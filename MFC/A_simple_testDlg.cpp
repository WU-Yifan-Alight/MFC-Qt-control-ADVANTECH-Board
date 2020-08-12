// A_simple_testDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "A_simple_test.h"
#include "A_simple_testDlg.h"
#include "afxdialogex.h"
#include "AdvMotApi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CA_simple_testDlg 对话框



CA_simple_testDlg::CA_simple_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_A_SIMPLE_TEST_DIALOG, pParent)
	, input_Speed(0)
	, input_positive_acc(0)
	, input_negative_acc(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CA_simple_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_show_status, text_show_status);
	DDX_Control(pDX, IDC_COMBO_available_device, chose_available_device);
	DDX_Control(pDX, IDC_BUTTON_open_device, button_open_device);
	DDX_Control(pDX, IDC_BUTTON_close_device, button_close_device);
	DDX_Control(pDX, IDC_BUTTON_servo_openclose, button_servo_openclose);
	DDX_Control(pDX, IDC_show_CPosition, show_CPosition);
	//  DDX_Control(pDX, IDC_show_CSpeed, show_CSpeed);
	DDX_Control(pDX, IDC_show_CSpeed, show_CSpeed);
	DDX_Control(pDX, IDC_show_CAxis_status, show_CAxis_status);
	DDX_Text(pDX, IDC_input_Speed, input_Speed);
	DDV_MinMaxFloat(pDX, input_Speed, 0, 1000);
	DDX_Text(pDX, IDC_input_positive_acc, input_positive_acc);
	DDV_MinMaxFloat(pDX, input_positive_acc, 0, 200);
	DDX_Text(pDX, IDC_input_negative_acc, input_negative_acc);
	DDV_MinMaxFloat(pDX, input_negative_acc, 0, 200);
	DDX_Control(pDX, IDC_BUTTON_positive_move, button_positive_move);
	DDX_Control(pDX, IDC_BUTTON_negative_move, button_negative_move);
	DDX_Control(pDX, IDC_BUTTON_stop, button_stop);
}

BEGIN_MESSAGE_MAP(CA_simple_testDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_open_device, &CA_simple_testDlg::OnBnClickedButtonopendevice)
	ON_BN_CLICKED(IDC_BUTTON_close_device, &CA_simple_testDlg::OnBnClickedButtonclosedevice)
	ON_BN_CLICKED(IDC_BUTTON_servo_openclose, &CA_simple_testDlg::OnBnClickedButtonservoopenclose)
	ON_CBN_SELCHANGE(IDC_COMBO_available_device, &CA_simple_testDlg::OnCbnSelchangeComboavailabledevice)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_positive_move, &CA_simple_testDlg::OnBnClickedButtonpositivemove)
	ON_BN_CLICKED(IDC_BUTTON_negative_move, &CA_simple_testDlg::OnBnClickedButtonnegativemove)
	ON_BN_CLICKED(IDC_BUTTON_stop, &CA_simple_testDlg::OnBnClickedButtonstop)
END_MESSAGE_MAP()


// CA_simple_testDlg 消息处理程序

BOOL CA_simple_testDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	U32		Result;
	ULONG	i = 0, deviceNumber = 0;
	
	//获取已成功加载驱动程序就可以得到可用的设备号和设备名称列表
	//如果您有多个板，当板的插槽顺序改变时，设备列表（list_avadevice）也会改变
	Result = Acm_GetAvailableDevs(list_avadevice, 20, &deviceNumber);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("请尝试连接您的虚拟轴卡和设备"), TEXT("未找到可用设备"));
		return TRUE;
	}
	
	chose_available_device.Clear();
	for (i = 0; i<deviceNumber; i++)
	{
		chose_available_device.AddString(list_avadevice[i].szDeviceName);
	}
	chose_available_device.SetCurSel(0);

	show_CPosition.SetWindowTextA(TEXT("暂未获得位置数据")); //初始化 显示位置 文本输入框中的字符显示
	show_CSpeed.SetWindowTextA(TEXT("暂未获得速度数据"));    //初始化 显示速度 文本输入框中的字符显示

	input_Speed = 0;			    //初始化 设置速度 文本输入框中的数值显示
	input_positive_acc = 0;		    //初始化 设置正向加速度 文本输入框中的数值显示
	input_negative_acc = 0;		    //初始化 设置反向加速度 文本输入框中的数值显示
	UpdateData(FALSE);            //将程序内的数据上传到控件

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CA_simple_testDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CA_simple_testDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CA_simple_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CA_simple_testDlg::OnBnClickedButtonopendevice()
{
	// TODO: 在此添加控件通知处理程序代码
	U32		Result;
	ULONG	retry = 0;
	bool	rescan = false;
	ULONG	AxisNumber=0;

	int devicenumber = chose_available_device.GetCurSel();//获取下拉框中当前设备索引

	m_dwDevNum = list_avadevice[devicenumber].dwDeviceNum;


	do
	{
		Result = Acm_DevOpen(m_dwDevNum, &devicehandle);
		if (Result != SUCCESS)
		{
			MessageBox(TEXT("请重新尝试打开设备"), TEXT("未能成功打开设备"));
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
		MessageBox(TEXT("请重新尝试"), TEXT("未能成功此设备的第一个轴"));
		return;
	}
	m_Axishand[devicenumber] = axishandle;

	CString devicename = list_avadevice[devicenumber].szDeviceName;
	text_show_status.SetWindowTextA(devicename + TEXT("已打开")); //显示当前设备连接状态
	Deviceopenflag[devicenumber] = TRUE;
	//开启定时器
	SetTimer(1, 200, NULL);

}


void CA_simple_testDlg::OnBnClickedButtonclosedevice()
{
	// TODO: 在此添加控件通知处理程序代码
	USHORT usAxisState[64];
	UINT AxisNum;
	int AxisCountnumber;
	int devicenumber = chose_available_device.GetCurSel();//获取下拉框中当前设备索引
	
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
				Pmotionflag[devicenumber] = FALSE;
				Nmotionflag[devicenumber] = FALSE;
				//命令轴伺服关闭。
				Acm_AxSetSvOn(m_Axishand[devicenumber], 0);
				Servoflag[devicenumber] = FALSE;
				button_servo_openclose.SetWindowText("开启伺服");
				//关闭轴
				Acm_AxClose(&m_Axishand[devicenumber]);
				//关闭轴卡设备
				Acm_DevClose(&m_Devhand[devicenumber]);
				Deviceopenflag[devicenumber] = FALSE;
			}
	
	CString devicename = list_avadevice[devicenumber].szDeviceName;
	text_show_status.SetWindowTextA(devicename + TEXT("已关闭")); //显示当前设备连接状态

	UpdateData(false);
}

void CA_simple_testDlg::OnClose()
{
	USHORT usAxisState[64];
	UINT number;
	int AxisCountnumber;

	AxisCountnumber = sizeof(m_Axishand);
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
			button_servo_openclose.SetWindowText("开启伺服");
			//关闭轴
			Acm_AxClose(&m_Axishand[number]);
			//关闭轴卡设备
			Acm_DevClose(&m_Devhand[number]);
			Deviceopenflag[number] = FALSE;
		}
	}
	
	text_show_status.SetWindowTextA(TEXT("关闭中")); //显示当前设备连接状态

	UpdateData(false);

	CDialog::OnClose();
}



void CA_simple_testDlg::OnBnClickedButtonservoopenclose()
{
	// TODO: 在此添加控件通知处理程序代码
	U32 Result;
	int devicenumber = chose_available_device.GetCurSel();//获取下拉框中当前设备索引
	CString devicename = list_avadevice[devicenumber].szDeviceName;
	
	if(Deviceopenflag[devicenumber]==TRUE)
	{
		//检查servoOn标志符，以确定是打开还是关闭伺服。
		if (Servoflag[devicenumber] == false)
		{
			//打开伺服
			Result = Acm_AxSetSvOn(m_Axishand[devicenumber], 1);
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("请查看设备连接"), TEXT("未能打开伺服"));
				return;
			}
			Servoflag[devicenumber] = true;
			button_servo_openclose.SetWindowText("关闭伺服");

			text_show_status.SetWindowTextA(devicename + TEXT("已打开 伺服已开启")); //显示当前设备连接状态
		}
		else
		{
			//关闭伺服
			Result = Acm_AxSetSvOn(m_Axishand[devicenumber], 0);
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("请查看设备连接"), TEXT("未能关闭伺服"));
				return;
			}
			Servoflag[devicenumber] = false;
			button_servo_openclose.SetWindowText("开启伺服");
			text_show_status.SetWindowTextA(devicename + TEXT("已打开 伺服已关闭")); //显示当前设备连接状态
		}
	}
	else
	{
		MessageBox(TEXT("请查看设备连接"), TEXT("未能打开伺服"));
		return;
	}
	

}


void CA_simple_testDlg::OnCbnSelchangeComboavailabledevice()
{
	// TODO: 在此添加控件通知处理程序代码
	int devicenumber = chose_available_device.GetCurSel();//获取下拉框中当前设备索引
	CString devicename = list_avadevice[devicenumber].szDeviceName;

	if (Deviceopenflag[devicenumber] == TRUE)
	{
		if (Servoflag[devicenumber] == TRUE)
		{
			text_show_status.SetWindowTextA(devicename + TEXT("已打开 伺服已开启")); //显示当前设备连接状态
			button_servo_openclose.SetWindowText("关闭伺服");
		}
		else
		{
			text_show_status.SetWindowTextA(devicename + TEXT("已打开 伺服已关闭")); //显示当前设备连接状态
			button_servo_openclose.SetWindowText("开启伺服");
		}
	}
	else
	{
		text_show_status.SetWindowTextA(devicename + TEXT("已关闭")); //显示当前设备连接状态
		button_servo_openclose.SetWindowText("开启伺服");
	}
}


void CA_simple_testDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	U32 Result;
	F64 CurPos;
	F64 CurVel;
	U16 State;
	CString strTemp;
	U32 Status;
	UpdateData(true);

	int number = chose_available_device.GetCurSel();//获取下拉框中当前设备索引
	
	if (Deviceopenflag[number] == TRUE)
	{
		//得到此设备轴一的当前理论位置
		Result = Acm_AxGetCmdPosition(m_Axishand[number], &CurPos);
		if (Result == SUCCESS)
		{
			strTemp.Format("%.0f", CurPos);
			show_CPosition.SetWindowText(strTemp);
		}
		//得到此设备轴一的当前理论速度
		Result = Acm_AxGetCmdVelocity(m_Axishand[number], &CurVel);
		if (Result == SUCCESS)
		{
			strTemp.Format("%.0f", CurVel);
			show_CSpeed.SetWindowText(strTemp);
		}
		
		// 得到此设备轴一的当前运动状态
		Result = Acm_AxGetState(m_Axishand[number], &State);
		if (Result == SUCCESS)
		{
			switch (State)
			{
			case 0:
				strTemp.Format("被禁用，用户可打开并激活");
				break;
			case 1:
				strTemp.Format("已准备就绪，等待新的命令");
				break;
			case 2:
				strTemp.Format("暂停中");
				break;
			case 3:
				strTemp.Format("出现错误终止");
				break;
			case 4:
				strTemp.Format("返回初始点中");
				break;
			case 5:
				strTemp.Format("正在点到点运动中");
				break;
			case 6:
				strTemp.Format("正在持续运动");
				break;
			case 7:
				strTemp.Format("正在执行插补运动");
				break;
			default:
				break;
			}
			show_CAxis_status.SetWindowText(strTemp);
		}
	}
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}

void CA_simple_testDlg::SetParameters()
{
	U32 Result;
	double AxVelLow;
	double AxVelHigh;
	double AxAcc;
	double AxDec;
	double AxJerk;
	CString strString;

	int number = chose_available_device.GetCurSel();//获取下拉框中当前设备索引

	AxVelLow = 0;
	//设置初始速度
	Result = Acm_SetF64Property(m_Axishand[number], PAR_AxVelLow, AxVelLow);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("请查看设备连接"), TEXT("未能设置初始速度"));
		return;
	}
	AxVelHigh = input_Speed;
	// 设置最高速度
	Result = Acm_SetF64Property(m_Axishand[number], PAR_AxVelHigh, AxVelHigh);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("请查看设备连接"), TEXT("未能设置速度"));
		return;
	}
	AxAcc = input_positive_acc;
	// 设置正向加速度
	Result = Acm_SetF64Property(m_Axishand[number], PAR_AxAcc, AxAcc);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("请查看设备连接"), TEXT("未能设置正向加速度"));
		return;
	}
	AxDec = input_negative_acc;
	//设置反向加速度
	Result = Acm_SetF64Property(m_Axishand[number], PAR_AxDec, AxDec);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("请查看设备连接"), TEXT("未能设置反向加速度"));
		return;
	}
	
	UpdateData(FALSE);
	
}

void CA_simple_testDlg::OnBnClickedButtonpositivemove()
{
	// TODO: 在此添加控件通知处理程序代码
	U32 Result;
	CString strString;
	int number = chose_available_device.GetCurSel();//获取下拉框中当前设备索引
	if (Pmotionflag[number] == FALSE)
	{
		if (Nmotionflag[number] == TRUE)//若轴正在反向运动
		{
			Result = Acm_AxStopDec(m_Axishand[number]);//先将轴停下再正向运动
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("请查看设备连接"), TEXT("未能执行运动指令"));
				return;
			}
			Nmotionflag[number] = FALSE;
			Sleep(1000);
			SetParameters();
			//0代表正向，1代表逆向
			Result = Acm_AxMoveVel(m_Axishand[number], 0);
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("请查看设备连接"), TEXT("未能执行运动指令"));
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
				MessageBox(TEXT("请查看设备连接"), TEXT("未能执行运动指令"));
				return;
			}
			Pmotionflag[number] = TRUE;
		}
	}
}


void CA_simple_testDlg::OnBnClickedButtonnegativemove()
{
	// TODO: 在此添加控件通知处理程序代码
	U32 Result;
	CString strString;
	int number = chose_available_device.GetCurSel();//获取下拉框中当前设备索引
	if (Nmotionflag[number] == FALSE)
	{
		if (Pmotionflag[number] == TRUE)//若轴正在正向运动
		{
			Result = Acm_AxStopDec(m_Axishand[number]);//先将轴停下再反向运动
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("请查看设备连接"), TEXT("未能执行运动指令"));
				return;
			}
			Pmotionflag[number] = FALSE;
			Sleep(1000);
			SetParameters();
			//0代表正向，1代表逆向
			Result = Acm_AxMoveVel(m_Axishand[number], 1);
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("请查看设备连接"), TEXT("未能执行运动指令"));
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
				MessageBox(TEXT("请查看设备连接"), TEXT("未能执行运动指令"));
				return;
			}
			Nmotionflag[number] = TRUE;
		}
	}	
}


void CA_simple_testDlg::OnBnClickedButtonstop()
{
	// TODO: 在此添加控件通知处理程序代码
	U32 Result;
	CString strString;
	int number = chose_available_device.GetCurSel();//获取下拉框中当前设备索引
	//使此轴减速停止		
	Result = Acm_AxStopDec(m_Axishand[number]);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("请查看设备连接"), TEXT("未能执行运动指令"));
		return;
	}
	Pmotionflag[number] = FALSE;
	Nmotionflag[number] = FALSE;
	return;
}
