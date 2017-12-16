// WordNumber.cpp : 实现文件
//

#include "stdafx.h"
#include "WordFrequency.h"
#include "WordNumber.h"


// CWordNumber

IMPLEMENT_DYNCREATE(CWordNumber, CFormView)

CWordNumber::CWordNumber()
	: CFormView(IDD_FORMVIEW)
{

}

CWordNumber::~CWordNumber()
{
}

void CWordNumber::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWordNumber, CFormView)
    ON_WM_SIZE()
    ON_WM_UPDATEUISTATE()
END_MESSAGE_MAP()


// CWordNumber 诊断

#ifdef _DEBUG
void CWordNumber::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CWordNumber::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CWordNumber 消息处理程序


void CWordNumber::OnSize(UINT nType, int cx, int cy)
{
    CFormView::OnSize(nType, cx, cy);

    if (IsWindowVisible())
    {
        GetDlgItem(IDC_BUTTON)->SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOMOVE);
    }

    
}


void CWordNumber::OnUpdateUIState(UINT /*nAction*/, UINT /*nUIElement*/)
{
    CRect ClientRect;
    GetClientRect(ClientRect);

    GetDlgItem(IDC_BUTTON)->SetWindowPos(NULL, 0, 0, ClientRect.Width(), ClientRect.Height(), SWP_NOMOVE);
}
