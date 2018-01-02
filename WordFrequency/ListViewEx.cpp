// ListViewEx.cpp : 实现文件
//

#include "stdafx.h"
#include "WordFrequency.h"
#include "ListViewEx.h"


// CListViewEx

IMPLEMENT_DYNCREATE(CListViewEx, CListView)

CListViewEx::CListViewEx()
{

}

CListViewEx::~CListViewEx()
{
}

BEGIN_MESSAGE_MAP(CListViewEx, CListView)
END_MESSAGE_MAP()


// CListViewEx 诊断

#ifdef _DEBUG
void CListViewEx::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CListViewEx::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CListViewEx 消息处理程序


BOOL CListViewEx::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= LVS_REPORT;;

	

	return CListView::PreCreateWindow(cs);
}

