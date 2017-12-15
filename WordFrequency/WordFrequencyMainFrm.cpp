
// WordFrequencyMainFrm.cpp : CWordFrequencyMainFrame 类的实现
//

#include "stdafx.h"
#include "WordFrequency.h"
#include "WordFrequencyMainFrm.h"
#include "ContentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWordFrequencyMainFrame

IMPLEMENT_DYNAMIC(CWordFrequencyMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CWordFrequencyMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// CWordFrequencyMainFrame 构造/析构

CWordFrequencyMainFrame::CWordFrequencyMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CWordFrequencyMainFrame::~CWordFrequencyMainFrame()
{
}

int CWordFrequencyMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;


	return 0;
}

BOOL CWordFrequencyMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CWordFrequencyMainFrame 诊断

#ifdef _DEBUG
void CWordFrequencyMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CWordFrequencyMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CWordFrequencyMainFrame 消息处理程序

void CWordFrequencyMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{

}

BOOL CWordFrequencyMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 否则，执行默认处理
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}



BOOL CWordFrequencyMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
    m_wndSplitterWnd.CreateStatic(this, 1, 2);
    
    m_wndSplitterWnd.CreateView(0, 0, RUNTIME_CLASS(CContentView), CSize(200, 0), pContext);
    m_wndSplitterWnd.CreateView(0, 1, RUNTIME_CLASS(CContentView), CSize(200, 0), pContext);
    
    return TRUE;
    //return CFrameWnd::OnCreateClient(lpcs, pContext);
}
