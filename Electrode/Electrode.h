
// Electrode.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CElectrodeApp: 
// �йش����ʵ�֣������ Electrode.cpp
//

class CElectrodeApp : public CWinApp
{
public:
	CElectrodeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CElectrodeApp theApp;