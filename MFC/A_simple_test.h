
// A_simple_test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CA_simple_testApp: 
// �йش����ʵ�֣������ A_simple_test.cpp
//

class CA_simple_testApp : public CWinApp
{
public:
	CA_simple_testApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CA_simple_testApp theApp;