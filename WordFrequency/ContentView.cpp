// ContentView.cpp : 实现文件
//

#include "stdafx.h"
#include "WordFrequency.h"
#include "ContentView.h"
#include "WordFrequencyDoc.h"

// CContentView

IMPLEMENT_DYNCREATE(CContentView, CEditView)

CContentView::CContentView()
{

}

CContentView::~CContentView()
{
}

BEGIN_MESSAGE_MAP(CContentView, CEditView)
    ON_WM_CREATE()
END_MESSAGE_MAP()


// CContentView 诊断

#ifdef _DEBUG
void CContentView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CContentView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG


// CContentView 消息处理程序
