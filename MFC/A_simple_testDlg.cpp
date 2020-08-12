// A_simple_testDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "A_simple_test.h"
#include "A_simple_testDlg.h"
#include "afxdialogex.h"
#include "AdvMotApi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CA_simple_testDlg �Ի���



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


// CA_simple_testDlg ��Ϣ�������

BOOL CA_simple_testDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	U32		Result;
	ULONG	i = 0, deviceNumber = 0;
	
	//��ȡ�ѳɹ�������������Ϳ��Եõ����õ��豸�ź��豸�����б�
	//������ж���壬����Ĳ��˳��ı�ʱ���豸�б�list_avadevice��Ҳ��ı�
	Result = Acm_GetAvailableDevs(list_avadevice, 20, &deviceNumber);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("�볢���������������Ῠ���豸"), TEXT("δ�ҵ������豸"));
		return TRUE;
	}
	
	chose_available_device.Clear();
	for (i = 0; i<deviceNumber; i++)
	{
		chose_available_device.AddString(list_avadevice[i].szDeviceName);
	}
	chose_available_device.SetCurSel(0);

	show_CPosition.SetWindowTextA(TEXT("��δ���λ������")); //��ʼ�� ��ʾλ�� �ı�������е��ַ���ʾ
	show_CSpeed.SetWindowTextA(TEXT("��δ����ٶ�����"));    //��ʼ�� ��ʾ�ٶ� �ı�������е��ַ���ʾ

	input_Speed = 0;			    //��ʼ�� �����ٶ� �ı�������е���ֵ��ʾ
	input_positive_acc = 0;		    //��ʼ�� ����������ٶ� �ı�������е���ֵ��ʾ
	input_negative_acc = 0;		    //��ʼ�� ���÷�����ٶ� �ı�������е���ֵ��ʾ
	UpdateData(FALSE);            //�������ڵ������ϴ����ؼ�

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CA_simple_testDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CA_simple_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CA_simple_testDlg::OnBnClickedButtonopendevice()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	U32		Result;
	ULONG	retry = 0;
	bool	rescan = false;
	ULONG	AxisNumber=0;

	int devicenumber = chose_available_device.GetCurSel();//��ȡ�������е�ǰ�豸����

	m_dwDevNum = list_avadevice[devicenumber].dwDeviceNum;


	do
	{
		Result = Acm_DevOpen(m_dwDevNum, &devicehandle);
		if (Result != SUCCESS)
		{
			MessageBox(TEXT("�����³��Դ��豸"), TEXT("δ�ܳɹ����豸"));
			retry++;
			rescan = true;
			if (retry > 2)
				return;
			Sleep(1000);
		}
		m_Devhand[devicenumber] = devicehandle;
	} while (rescan == true);

	//�򿪴��豸��һ����
	Result = Acm_AxOpen(devicehandle, (USHORT)AxisNumber, &axishandle);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("�����³���"), TEXT("δ�ܳɹ����豸�ĵ�һ����"));
		return;
	}
	m_Axishand[devicenumber] = axishandle;

	CString devicename = list_avadevice[devicenumber].szDeviceName;
	text_show_status.SetWindowTextA(devicename + TEXT("�Ѵ�")); //��ʾ��ǰ�豸����״̬
	Deviceopenflag[devicenumber] = TRUE;
	//������ʱ��
	SetTimer(1, 200, NULL);

}


void CA_simple_testDlg::OnBnClickedButtonclosedevice()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	USHORT usAxisState[64];
	UINT AxisNum;
	int AxisCountnumber;
	int devicenumber = chose_available_device.GetCurSel();//��ȡ�������е�ǰ�豸����
	
		//��ȡ������ĵ�ǰ״̬
		
			if (Deviceopenflag[devicenumber] == TRUE)
			{
				Acm_AxGetState(m_Axishand[devicenumber], &usAxisState[devicenumber]);
				if (usAxisState[devicenumber] == STA_AX_ERROR_STOP)
				{
					//������״̬������ᴦ��ErrorStop״̬�����ô˺�����״̬������Ϊ����
					Acm_AxResetError(m_Axishand[devicenumber]);
				}
				//���������ֹͣ��
				Acm_AxStopDec(m_Axishand[devicenumber]);
				Pmotionflag[devicenumber] = FALSE;
				Nmotionflag[devicenumber] = FALSE;
				//�������ŷ��رա�
				Acm_AxSetSvOn(m_Axishand[devicenumber], 0);
				Servoflag[devicenumber] = FALSE;
				button_servo_openclose.SetWindowText("�����ŷ�");
				//�ر���
				Acm_AxClose(&m_Axishand[devicenumber]);
				//�ر��Ῠ�豸
				Acm_DevClose(&m_Devhand[devicenumber]);
				Deviceopenflag[devicenumber] = FALSE;
			}
	
	CString devicename = list_avadevice[devicenumber].szDeviceName;
	text_show_status.SetWindowTextA(devicename + TEXT("�ѹر�")); //��ʾ��ǰ�豸����״̬

	UpdateData(false);
}

void CA_simple_testDlg::OnClose()
{
	USHORT usAxisState[64];
	UINT number;
	int AxisCountnumber;

	AxisCountnumber = sizeof(m_Axishand);
	//��ȡ������ĵ�ǰ״̬
	for (number = 0; number < AxisCountnumber; number++)
	{
		if (Deviceopenflag[number] == TRUE)
		{
			Acm_AxGetState(m_Axishand[number], &usAxisState[number]);
			if (usAxisState[number] == STA_AX_ERROR_STOP)
			{
				//������״̬������ᴦ��ErrorStop״̬�����ô˺�����״̬������Ϊ����
				Acm_AxResetError(m_Axishand[number]);
			}
			//���������ֹͣ��
			Acm_AxStopDec(m_Axishand[number]);
			Pmotionflag[number] = FALSE;
			Nmotionflag[number] = FALSE;
			//�������ŷ��رա�
			Acm_AxSetSvOn(m_Axishand[number], 0);
			button_servo_openclose.SetWindowText("�����ŷ�");
			//�ر���
			Acm_AxClose(&m_Axishand[number]);
			//�ر��Ῠ�豸
			Acm_DevClose(&m_Devhand[number]);
			Deviceopenflag[number] = FALSE;
		}
	}
	
	text_show_status.SetWindowTextA(TEXT("�ر���")); //��ʾ��ǰ�豸����״̬

	UpdateData(false);

	CDialog::OnClose();
}



void CA_simple_testDlg::OnBnClickedButtonservoopenclose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	U32 Result;
	int devicenumber = chose_available_device.GetCurSel();//��ȡ�������е�ǰ�豸����
	CString devicename = list_avadevice[devicenumber].szDeviceName;
	
	if(Deviceopenflag[devicenumber]==TRUE)
	{
		//���servoOn��־������ȷ���Ǵ򿪻��ǹر��ŷ���
		if (Servoflag[devicenumber] == false)
		{
			//���ŷ�
			Result = Acm_AxSetSvOn(m_Axishand[devicenumber], 1);
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("��鿴�豸����"), TEXT("δ�ܴ��ŷ�"));
				return;
			}
			Servoflag[devicenumber] = true;
			button_servo_openclose.SetWindowText("�ر��ŷ�");

			text_show_status.SetWindowTextA(devicename + TEXT("�Ѵ� �ŷ��ѿ���")); //��ʾ��ǰ�豸����״̬
		}
		else
		{
			//�ر��ŷ�
			Result = Acm_AxSetSvOn(m_Axishand[devicenumber], 0);
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("��鿴�豸����"), TEXT("δ�ܹر��ŷ�"));
				return;
			}
			Servoflag[devicenumber] = false;
			button_servo_openclose.SetWindowText("�����ŷ�");
			text_show_status.SetWindowTextA(devicename + TEXT("�Ѵ� �ŷ��ѹر�")); //��ʾ��ǰ�豸����״̬
		}
	}
	else
	{
		MessageBox(TEXT("��鿴�豸����"), TEXT("δ�ܴ��ŷ�"));
		return;
	}
	

}


void CA_simple_testDlg::OnCbnSelchangeComboavailabledevice()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int devicenumber = chose_available_device.GetCurSel();//��ȡ�������е�ǰ�豸����
	CString devicename = list_avadevice[devicenumber].szDeviceName;

	if (Deviceopenflag[devicenumber] == TRUE)
	{
		if (Servoflag[devicenumber] == TRUE)
		{
			text_show_status.SetWindowTextA(devicename + TEXT("�Ѵ� �ŷ��ѿ���")); //��ʾ��ǰ�豸����״̬
			button_servo_openclose.SetWindowText("�ر��ŷ�");
		}
		else
		{
			text_show_status.SetWindowTextA(devicename + TEXT("�Ѵ� �ŷ��ѹر�")); //��ʾ��ǰ�豸����״̬
			button_servo_openclose.SetWindowText("�����ŷ�");
		}
	}
	else
	{
		text_show_status.SetWindowTextA(devicename + TEXT("�ѹر�")); //��ʾ��ǰ�豸����״̬
		button_servo_openclose.SetWindowText("�����ŷ�");
	}
}


void CA_simple_testDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	U32 Result;
	F64 CurPos;
	F64 CurVel;
	U16 State;
	CString strTemp;
	U32 Status;
	UpdateData(true);

	int number = chose_available_device.GetCurSel();//��ȡ�������е�ǰ�豸����
	
	if (Deviceopenflag[number] == TRUE)
	{
		//�õ����豸��һ�ĵ�ǰ����λ��
		Result = Acm_AxGetCmdPosition(m_Axishand[number], &CurPos);
		if (Result == SUCCESS)
		{
			strTemp.Format("%.0f", CurPos);
			show_CPosition.SetWindowText(strTemp);
		}
		//�õ����豸��һ�ĵ�ǰ�����ٶ�
		Result = Acm_AxGetCmdVelocity(m_Axishand[number], &CurVel);
		if (Result == SUCCESS)
		{
			strTemp.Format("%.0f", CurVel);
			show_CSpeed.SetWindowText(strTemp);
		}
		
		// �õ����豸��һ�ĵ�ǰ�˶�״̬
		Result = Acm_AxGetState(m_Axishand[number], &State);
		if (Result == SUCCESS)
		{
			switch (State)
			{
			case 0:
				strTemp.Format("�����ã��û��ɴ򿪲�����");
				break;
			case 1:
				strTemp.Format("��׼���������ȴ��µ�����");
				break;
			case 2:
				strTemp.Format("��ͣ��");
				break;
			case 3:
				strTemp.Format("���ִ�����ֹ");
				break;
			case 4:
				strTemp.Format("���س�ʼ����");
				break;
			case 5:
				strTemp.Format("���ڵ㵽���˶���");
				break;
			case 6:
				strTemp.Format("���ڳ����˶�");
				break;
			case 7:
				strTemp.Format("����ִ�в岹�˶�");
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

	int number = chose_available_device.GetCurSel();//��ȡ�������е�ǰ�豸����

	AxVelLow = 0;
	//���ó�ʼ�ٶ�
	Result = Acm_SetF64Property(m_Axishand[number], PAR_AxVelLow, AxVelLow);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("��鿴�豸����"), TEXT("δ�����ó�ʼ�ٶ�"));
		return;
	}
	AxVelHigh = input_Speed;
	// ��������ٶ�
	Result = Acm_SetF64Property(m_Axishand[number], PAR_AxVelHigh, AxVelHigh);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("��鿴�豸����"), TEXT("δ�������ٶ�"));
		return;
	}
	AxAcc = input_positive_acc;
	// ����������ٶ�
	Result = Acm_SetF64Property(m_Axishand[number], PAR_AxAcc, AxAcc);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("��鿴�豸����"), TEXT("δ������������ٶ�"));
		return;
	}
	AxDec = input_negative_acc;
	//���÷�����ٶ�
	Result = Acm_SetF64Property(m_Axishand[number], PAR_AxDec, AxDec);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("��鿴�豸����"), TEXT("δ�����÷�����ٶ�"));
		return;
	}
	
	UpdateData(FALSE);
	
}

void CA_simple_testDlg::OnBnClickedButtonpositivemove()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	U32 Result;
	CString strString;
	int number = chose_available_device.GetCurSel();//��ȡ�������е�ǰ�豸����
	if (Pmotionflag[number] == FALSE)
	{
		if (Nmotionflag[number] == TRUE)//�������ڷ����˶�
		{
			Result = Acm_AxStopDec(m_Axishand[number]);//�Ƚ���ͣ���������˶�
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("��鿴�豸����"), TEXT("δ��ִ���˶�ָ��"));
				return;
			}
			Nmotionflag[number] = FALSE;
			Sleep(1000);
			SetParameters();
			//0��������1��������
			Result = Acm_AxMoveVel(m_Axishand[number], 0);
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("��鿴�豸����"), TEXT("δ��ִ���˶�ָ��"));
				return;
			}
			Pmotionflag[number] = TRUE;
		}
		else
		{
			SetParameters();
			//0��������1��������
			Result = Acm_AxMoveVel(m_Axishand[number], 0);
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("��鿴�豸����"), TEXT("δ��ִ���˶�ָ��"));
				return;
			}
			Pmotionflag[number] = TRUE;
		}
	}
}


void CA_simple_testDlg::OnBnClickedButtonnegativemove()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	U32 Result;
	CString strString;
	int number = chose_available_device.GetCurSel();//��ȡ�������е�ǰ�豸����
	if (Nmotionflag[number] == FALSE)
	{
		if (Pmotionflag[number] == TRUE)//�������������˶�
		{
			Result = Acm_AxStopDec(m_Axishand[number]);//�Ƚ���ͣ���ٷ����˶�
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("��鿴�豸����"), TEXT("δ��ִ���˶�ָ��"));
				return;
			}
			Pmotionflag[number] = FALSE;
			Sleep(1000);
			SetParameters();
			//0��������1��������
			Result = Acm_AxMoveVel(m_Axishand[number], 1);
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("��鿴�豸����"), TEXT("δ��ִ���˶�ָ��"));
				return;
			}
			Nmotionflag[number] = TRUE;
		}
		else
		{
			SetParameters();
			//0��������1��������
			Result = Acm_AxMoveVel(m_Axishand[number], 1);
			if (Result != SUCCESS)
			{
				MessageBox(TEXT("��鿴�豸����"), TEXT("δ��ִ���˶�ָ��"));
				return;
			}
			Nmotionflag[number] = TRUE;
		}
	}	
}


void CA_simple_testDlg::OnBnClickedButtonstop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	U32 Result;
	CString strString;
	int number = chose_available_device.GetCurSel();//��ȡ�������е�ǰ�豸����
	//ʹ�������ֹͣ		
	Result = Acm_AxStopDec(m_Axishand[number]);
	if (Result != SUCCESS)
	{
		MessageBox(TEXT("��鿴�豸����"), TEXT("δ��ִ���˶�ָ��"));
		return;
	}
	Pmotionflag[number] = FALSE;
	Nmotionflag[number] = FALSE;
	return;
}
