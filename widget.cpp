#include <Windows.h>
#include "widget.h"
#include "ui_widget.h"
#include "AdvMotApi.h"
#pragma execution_character_set("utf-8")

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //在此插入初始化程序代码
    U32		Result;
    ULONG	i = 0, deviceNumber = 0;

    //获取已成功加载驱动程序就可以得到可用的设备号和设备名称列表
    //如果您有多个板，当板的插槽顺序改变时，设备列表（list_avadevice）也会改变
    Result = Acm_GetAvailableDevs(list_avadevice, 20, &deviceNumber);
    if (Result != SUCCESS)
    {
        QMessageBox::about(this,"未找到可用设备","请尝试连接您的虚拟轴卡和设备");
        return;
    }
    ui->comboBox_Chose_AvailableDevice->clear();
    for (i = 0; i<deviceNumber; i++)
    {
        const char *laChar = list_avadevice[i].szDeviceName;
        QString laQString(laChar);
        QStringList laQStringlist = laQString.split(";");
        ui->comboBox_Chose_AvailableDevice->addItems(laQStringlist);
    }
    ui->comboBox_Chose_AvailableDevice->setCurrentIndex(0);//初始化下拉框中的设备字符显示
    ui->lineEdit_Show_Position->setText("暂未获得位置数据");       //初始化 显示位置 单行文本编辑控件
    ui->lineEdit_Show_Speed->setText("暂未获得速度数据");          //初始化 显示速度 单行文本编辑控件
    ui->lineEdit_Set_Speed->setText("0");                //初始化 设置速度 单行文本编辑控件
    ui->lineEdit_Set_PositiveAcc->setText("0");          //初始化 设置正向加速度 单行文本编辑控件
    ui->lineEdit_Set_NegativeAcc->setText("0");          //初始化 设置反向加速度 单行文本编辑控件
    for (i = 0; i<sizeof(20); i++)
    {
        Deviceopenflag[i]=false;
        Servoflag[i]=false;
        Nmotionflag[i]=false;
        Pmotionflag[i]=false;
    }



    t = new QTimer;                                                 //初始化定时器
    connect(t,&QTimer::timeout,this,&Widget::updateData);           //连接定时器超时事件的信号与槽

}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateData()
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    U32 Result;
    F64 CurPos;
    F64 CurVel;
    U16 State;
    QString strTemp;
    QString stringPosition;
    QString stringSpeed;

    int number = ui->comboBox_Chose_AvailableDevice->currentIndex();//获取下拉框中当前设备索引
    if (Deviceopenflag[number] == TRUE)
    {
        //得到此设备轴一的当前理论位置
        Result = Acm_AxGetCmdPosition(m_Axishand[number], &CurPos);
        if (Result == SUCCESS)
        {
            stringPosition.setNum(CurPos);
            ui->lineEdit_Show_Position->setText(stringPosition);
        }
        //得到此设备轴一的当前理论速度
        Result = Acm_AxGetCmdVelocity(m_Axishand[number], &CurVel);
        if (Result == SUCCESS)
        {
            stringSpeed.setNum(CurVel);
            ui->lineEdit_Show_Speed->setText(stringSpeed);
        }
        // 得到此设备轴一的当前运动状态
        Result = Acm_AxGetState(m_Axishand[number], &State);
        if (Result == SUCCESS)
        {
            switch (State)
            {
            case 0:
                strTemp="被禁用，用户可打开并激活";
                break;
            case 1:
                strTemp="已准备就绪，等待新的命令";
                break;
            case 2:
                strTemp="暂停中";
                break;
            case 3:
                strTemp="出现错误终止";
                break;
            case 4:
                strTemp="返回初始点中";
                break;
            case 5:
                strTemp="正在点到点运动中";
                break;
            case 6:
                strTemp="正在持续运动";
                break;
            case 7:
                strTemp="正在执行插补运动";
                break;
            default:
                break;
            }
            ui->label_AixsStatus->setText(strTemp);
        }
    }

}



void Widget::on_pushButton_OpenDevice_clicked()
{
    // TODO: 在此添加控件通知处理程序代码
    U32		Result;
    ULONG	retry = 0;
    bool	rescan = false;
    ULONG	AxisNumber=0;

    int devicenumber = ui->comboBox_Chose_AvailableDevice->currentIndex();//获取下拉框中当前设备索引
    m_dwDevNum = list_avadevice[devicenumber].dwDeviceNum;

    do
    {
        Result = Acm_DevOpen(m_dwDevNum, &devicehandle);
        if (Result != SUCCESS)
        {
            QMessageBox::about(this,"未能成功打开设备","请重新尝试打开设备");
            retry++;
            rescan = true;
            if (retry > 2)
            return;
            Sleep(1000);
        }
        m_Devhand[devicenumber] = devicehandle;
    } while (rescan == true);
    //打开此设备的一号轴
    Result = Acm_AxOpen(devicehandle, (USHORT)AxisNumber, &axishandle);
    if (Result != SUCCESS)
    {
        QMessageBox::about(this,"未能打开一号轴","请重新尝试");
        return;
    }
    m_Axishand[devicenumber] = axishandle;
    const char *laCharShow = list_avadevice[devicenumber].szDeviceName;
    QString laQStringShow(laCharShow);

    Deviceopenflag[devicenumber] = TRUE;
    ui->label_DeviceStatus->setText(laQStringShow+"已打开");           //若连接到仿真器，则显示连接状态为已连接

    t->start(100);                                       //建立定时器，0.1秒触发一次

}

void Widget::on_pushButton_CloseDevice_clicked()
{

    // TODO: 在此添加控件通知处理程序代码
    USHORT usAxisState[64];
    int devicenumber = ui->comboBox_Chose_AvailableDevice->currentIndex();//获取下拉框中当前设备索引

    //获取所有轴的当前状态

    if (Deviceopenflag[devicenumber] == TRUE)
    {
        Acm_AxGetState(m_Axishand[devicenumber], &usAxisState[devicenumber]);
        if (usAxisState[devicenumber] == STA_AX_ERROR_STOP)
        {
            //重置轴状态。如果轴处于ErrorStop状态，调用此函数后状态将更改为就绪
            Acm_AxResetError(m_Axishand[devicenumber]);
        }
        //命令轴减速停止。
        Acm_AxStopDec(m_Axishand[devicenumber]);
        //命令轴伺服关闭。
        Acm_AxSetSvOn(m_Axishand[devicenumber], 0);
        ui->pushButton_OpenCloseServo->setText("开启伺服");
        //关闭轴
        Acm_AxClose(&m_Axishand[devicenumber]);
        //关闭轴卡设备
        Acm_DevClose(&m_Devhand[devicenumber]);
        Deviceopenflag[devicenumber] = FALSE;
    }

    const char *laCharShow = list_avadevice[devicenumber].szDeviceName;
    QString laQStringShow(laCharShow);

    Deviceopenflag[devicenumber] = TRUE;
    ui->label_DeviceStatus->setText(laQStringShow+"已关闭");           //若连接到仿真器，则显示连接状态为已连接
}

void Widget::closeEvent(QCloseEvent *event)
{
    switch( QMessageBox::information( this, tr("提示"), tr("请问您是否确认退出?"),tr("是"), tr("否"),nullptr, 1 ) )
    {
    case 0:
        event->accept();
        t->stop();
        USHORT usAxisState[64];
        int number;
        int AxisCountnumber;

        AxisCountnumber = ui->comboBox_Chose_AvailableDevice->count();
        //获取所有轴的当前状态
        for (number = 0; number < AxisCountnumber; number++)
        {
            if (Deviceopenflag[number] == TRUE)
            {
                Acm_AxGetState(m_Axishand[number], &usAxisState[number]);
                if (usAxisState[number] == STA_AX_ERROR_STOP)
                {
                    //重置轴状态。如果轴处于ErrorStop状态，调用此函数后状态将更改为就绪
                    Acm_AxResetError(m_Axishand[number]);
                }
                //命令轴减速停止。
                Acm_AxStopDec(m_Axishand[number]);
                Pmotionflag[number] = FALSE;
                Nmotionflag[number] = FALSE;

                //命令轴伺服关闭。
                Acm_AxSetSvOn(m_Axishand[number], 0);
                ui->pushButton_OpenCloseServo->setText("开启伺服");
                //关闭轴
                Acm_AxClose(&m_Axishand[number]);
                //关闭轴卡设备
                Acm_DevClose(&m_Devhand[number]);
                Deviceopenflag[number] = FALSE;
            }
        }
        ui->label_DeviceStatus->setText("关闭中"); //显示当前设备连接状态
        break;
    case 1:
    default:
        event->ignore();
        break;
    }
}


void Widget::on_pushButton_OpenCloseServo_clicked()
{
    // TODO: 在此添加控件通知处理程序代码
    U32 Result;
    int devicenumber = ui->comboBox_Chose_AvailableDevice->currentIndex();//获取下拉框中当前设备索引
    const char *laCharShow = list_avadevice[devicenumber].szDeviceName;
    QString laQStringShow(laCharShow);

    //检查servoOn标志符，以确定是打开还是关闭伺服。
    if(Deviceopenflag[devicenumber]==TRUE)
    {
        if (Servoflag[devicenumber] == false) //检查servoOn标志符，以确定是打开还是关闭伺服。
        {   //打开伺服
            Result = Acm_AxSetSvOn(m_Axishand[devicenumber], 1);
            if (Result != SUCCESS)
            {
                QMessageBox::about(this,"未能打开伺服","请查看设备连接");
                return;
            }
            Servoflag[devicenumber] = true;
            ui->pushButton_OpenCloseServo->setText("关闭伺服");
            ui->label_DeviceStatus->setText(laQStringShow+"已打开 伺服已开启");	}
        else
        {   //关闭伺服
            Result = Acm_AxSetSvOn(m_Axishand[devicenumber], 0);
            if (Result != SUCCESS)
            {
                QMessageBox::about(this,"未能关闭伺服","请查看设备连接");
                return;
            }
            Servoflag[devicenumber] = false;
            ui->pushButton_OpenCloseServo->setText("开启伺服");
            ui->label_DeviceStatus->setText(laQStringShow+"已打开 伺服已关闭");		}
    }
    else
    {
        QMessageBox::about(this,"未能打开伺服","请查看设备连接");
        return;
    }

}

void Widget::on_comboBox_Chose_AvailableDevice_currentIndexChanged(const QString &arg1)
{
    int devicenumber = ui->comboBox_Chose_AvailableDevice->currentIndex();//获取下拉框中当前设备索引
    const char *laCharShow = list_avadevice[devicenumber].szDeviceName;
    QString laQStringShow(laCharShow);

    if (Deviceopenflag[devicenumber] == TRUE)
    {
        if (Servoflag[devicenumber] == TRUE)
        {
            ui->label_DeviceStatus->setText(laQStringShow+"已打开 伺服已开启");
            ui->pushButton_OpenCloseServo->setText("关闭伺服");
        }
        else
        {
            ui->label_DeviceStatus->setText(laQStringShow+"已打开 伺服已关闭");
            ui->pushButton_OpenCloseServo->setText("开启伺服");
        }
    }
    else
    {
        ui->label_DeviceStatus->setText(laQStringShow+"已关闭"); //显示当前设备连接状态
        ui->pushButton_OpenCloseServo->setText("开启伺服");
    }
}

void Widget::SetParameters( )
{
    U32 Result;
    double AxVelLow;
    double AxVelHigh;
    double AxAcc;
    double AxDec;

    int number = ui->comboBox_Chose_AvailableDevice->currentIndex();//获取下拉框中当前设备索引

    AxVelLow = 0;
    //设置初始速度
    Result = Acm_SetF64Property(m_Axishand[number], PAR_AxVelLow, AxVelLow);
    if (Result != SUCCESS)
    {
        QMessageBox::about(this,"未能设置初始速度","请查看设备连接");
        return;
    }
    double input_Speed=ui->lineEdit_Set_Speed->text().toDouble();
    AxVelHigh = input_Speed;
    // 设置最高速度
    Result = Acm_SetF64Property(m_Axishand[number], PAR_AxVelHigh, AxVelHigh);
    if (Result != SUCCESS)
    {
        QMessageBox::about(this,"未能设置速度","请查看设备连接");
        return;
    }
    double input_positive_acc=ui->lineEdit_Set_PositiveAcc->text().toDouble();
    AxAcc = input_positive_acc;
    // 设置正向加速度
    Result = Acm_SetF64Property(m_Axishand[number], PAR_AxAcc, AxAcc);
    if (Result != SUCCESS)
    {
        QMessageBox::about(this,"未能设置正向加速度","请查看设备连接");
        return;
    }
    double input_negative_acc=ui->lineEdit_Set_NegativeAcc->text().toDouble();
    AxDec = input_negative_acc;
    //设置反向加速度
    Result = Acm_SetF64Property(m_Axishand[number], PAR_AxDec, AxDec);
    if (Result != SUCCESS)
    {
        QMessageBox::about(this,"未能设置反向加速度","请查看设备连接");
        return;
    }
}

void Widget::on_pushButton_PositiveMove_clicked()
{
    // TODO: 在此添加控件通知处理程序代码
    U32 Result;

    int number;
    number = ui->comboBox_Chose_AvailableDevice->currentIndex();//获取下拉框中当前设备索引

    if (Pmotionflag[number] == FALSE)
    {
        if (Nmotionflag[number] == TRUE)//若轴正在反向运动
        {
            Result = Acm_AxStopDec(m_Axishand[number]);//先将轴停下再正向运动
            if (Result != SUCCESS)
            {
                QMessageBox::about(this,"未能执行运动指令","请查看设备连接");
                return;
            }
            Nmotionflag[number] = FALSE;
            Sleep(1000);
            SetParameters();
            //0代表正向，1代表逆向
            Result = Acm_AxMoveVel(m_Axishand[number], 0);
            if (Result != SUCCESS)
            {
                QMessageBox::about(this,"未能执行运动指令","请查看设备连接");
                return;
            }
            Pmotionflag[number] = TRUE;
        }
        else
        {
            SetParameters();
            //0代表正向，1代表逆向
            Result = Acm_AxMoveVel(m_Axishand[number], 0);
            if (Result != SUCCESS)
            {
                QMessageBox::about(this,"未能执行运动指令","请查看设备连接");
                return;
            }
            Pmotionflag[number] = TRUE;
        }
    }

}

void Widget::on_pushButton_NegativeMove_clicked()
{
    // TODO: 在此添加控件通知处理程序代码
    U32 Result;
    int number;
    number = ui->comboBox_Chose_AvailableDevice->currentIndex();//获取下拉框中当前设备索引

    if (Nmotionflag[number] == FALSE)
    {
        if (Pmotionflag[number] == TRUE)//若轴正在正向运动
        {
            Result = Acm_AxStopDec(m_Axishand[number]);//先将轴停下再反向运动
            if (Result != SUCCESS)
            {
                QMessageBox::about(this,"未能执行运动指令","请查看设备连接");
                return;
            }
            Pmotionflag[number] = FALSE;
            Sleep(1000);
            SetParameters();
            //0代表正向，1代表逆向
            Result = Acm_AxMoveVel(m_Axishand[number], 1);
            if (Result != SUCCESS)
            {
                QMessageBox::about(this,"未能执行运动指令","请查看设备连接");
                return;
            }
            Nmotionflag[number] = TRUE;
        }
        else
        {
            SetParameters();
            //0代表正向，1代表逆向
            Result = Acm_AxMoveVel(m_Axishand[number], 1);
            if (Result != SUCCESS)
            {
                QMessageBox::about(this,"未能执行运动指令","请查看设备连接");
                return;
            }
            Nmotionflag[number] = TRUE;
        }
    }
}

void Widget::on_pushButton_Stop_clicked()
{

    // TODO: 在此添加控件通知处理程序代码
    U32 Result;
    int number;
    number = ui->comboBox_Chose_AvailableDevice->currentIndex();//获取下拉框中当前设备索引

    //使此轴减速停止
    Result = Acm_AxStopDec(m_Axishand[number]);
    if (Result != SUCCESS)
    {
        QMessageBox::about(this,"未能执行运动指令","请查看设备连接");
        return;
    }
    Pmotionflag[number] = FALSE;
    Nmotionflag[number] = FALSE;
    return;

}
