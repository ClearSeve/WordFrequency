
// WordFrequency.h : WordFrequency Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CWordFrequencyApp:
// �йش����ʵ�֣������ WordFrequency.cpp
//

class CWordFrequencyApp : public CWinApp
{
public:
	CWordFrequencyApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWordFrequencyApp theApp;
