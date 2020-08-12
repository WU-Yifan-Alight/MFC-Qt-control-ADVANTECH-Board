
// A_simple_testDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "AdvMotApi.h"


// CA_simple_testDlg �Ի���
class CA_simple_testDlg : public CDialogEx
{
// ����
public:
	CA_simple_testDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_A_SIMPLE_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
private:
	CStatic text_show_status;
	CComboBox chose_available_device;
	CButton button_open_device;
	CButton button_close_device;
	CButton button_servo_openclose;
public:
	DEVLIST	list_avadevice[20];
	afx_msg void OnBnClickedButtonopendevice();
	DWORD	m_dwDevNum;
	HAND    devicehandle;
	HAND    axishandle;
	HAND	m_Devhand[20];
	HAND	m_Axishand[20];
	BOOL	Deviceopenflag[20];
	afx_msg void OnClose();
		
	afx_msg void OnBnClickedButtonclosedevice();
	afx_msg void OnBnClickedButtonservoopenclose();

	BOOL	Servoflag[20];
	afx_msg void OnCbnSelchangeComboavailabledevice();
	BOOL	Pmotionflag[20];
	BOOL	Nmotionflag[20];
private:
	CEdit show_CPosition;
	CEdit show_CSpeed;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	
private:
	CStatic show_CAxis_status;
	float input_Speed;
	float input_positive_acc;
	float input_negative_acc;
	CButton button_positive_move;
	CButton button_negative_move;
	CButton button_stop;
	void SetParameters();
public:
	afx_msg void OnBnClickedButtonpositivemove();
	afx_msg void OnBnClickedButtonnegativemove();
	afx_msg void OnBnClickedButtonstop();
	DECLARE_MESSAGE_MAP()
};
