
// WordFrequencyMainFrm.cpp : CWordFrequencyMainFrame 类的实现
//

#include "stdafx.h"
#include "WordFrequency.h"
#include "WordFrequencyMainFrm.h"
#include "ContentView.h"
#include "ListViewEx.h"

#include <map>
#include <vector>
#include <algorithm>
using namespace std;

TCHAR SYMBOL[] = { TEXT('\''), TEXT('-'), TEXT('’') };
int g_nSymbolSize = sizeof(SYMBOL) / sizeof(SYMBOL[0]);

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWordFrequencyMainFrame

IMPLEMENT_DYNAMIC(CWordFrequencyMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CWordFrequencyMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_BEGIN, &CWordFrequencyMainFrame::OnBegin)
	ON_UPDATE_COMMAND_UI(ID_BEGIN, &CWordFrequencyMainFrame::OnUpdateBegin)
END_MESSAGE_MAP()

// CWordFrequencyMainFrame 构造/析构

CWordFrequencyMainFrame::CWordFrequencyMainFrame() :m_wndViewWdith(), m_bOnlyInit(), m_bMenuItemClick(TRUE)
{
	// TODO: 在此添加成员初始化代码
}

CWordFrequencyMainFrame::~CWordFrequencyMainFrame()
{
}
 // ListCtrl 排序函数
int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	return lParam1 < lParam2;
}

int CWordFrequencyMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	static_cast<CListViewEx*>(m_wndSplitterWnd.GetPane(0, 1))->GetListCtrl().InsertColumn(0, _T("单词"), LVCFMT_LEFT, 100);
	static_cast<CListViewEx*>(m_wndSplitterWnd.GetPane(0, 1))->GetListCtrl().InsertColumn(1, _T("词频"), LVCFMT_LEFT, 100);



	
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
    
	m_wndSplitterWnd.CreateView(0, 0, RUNTIME_CLASS(CContentView), CSize(m_wndViewWdith, 0), pContext);
	m_wndSplitterWnd.CreateView(0, 1, RUNTIME_CLASS(CListViewEx), CSize(0, 0), pContext);
    
	
    return TRUE;
    //return CFrameWnd::OnCreateClient(lpcs, pContext);
}


BOOL CWordFrequencyMainFrame::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, LPCTSTR lpszMenuName, DWORD dwExStyle, CCreateContext* pContext)
{
	
	m_wndViewWdith = rect.left - rect.right;

	return CFrameWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, lpszMenuName, dwExStyle, pContext);
}


void CWordFrequencyMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);
	if (IsWindowVisible() && m_bOnlyInit == FALSE)
	{
		m_bOnlyInit = TRUE;
		// 调整切分大小
		m_wndSplitterWnd.SetColumnInfo(0, cx*0.7, 0); 
		m_wndSplitterWnd.RecalcLayout();


	}
	
}

DWORD WINAPI OperateThreadProc(_In_ LPVOID lpParameter)
{
	LPOPERATETHREADDATA pOperateThreadData = (LPOPERATETHREADDATA)lpParameter;

	map<CString, DWORD> wordmap;

	pOperateThreadData->pwndEditView->EnableWindow(FALSE);
	*pOperateThreadData->pbMenuItemClick = FALSE;

	// 末尾添加空格
	pOperateThreadData->strText += _T(" ");

	// 清空ListItem
	pOperateThreadData->pwndListCtrl->DeleteAllItems();

	// 调整文章为小写
	pOperateThreadData->strText.MakeLower();

	// 过滤单词中的符号
	for (int i = 0; i < pOperateThreadData->strText.GetLength(); ++i)
	{
		if (!(pOperateThreadData->strText[i] >= L'a' && pOperateThreadData->strText[i] <= L'z'))
		{ // 不是字母

			BOOL bReplace = TRUE;
			TCHAR ch = pOperateThreadData->strText[i];
			// 遍历排查过滤器
			for (int nSymbol = 0; nSymbol<g_nSymbolSize; ++nSymbol)
			{
				if(SYMBOL[nSymbol] == pOperateThreadData->strText[i])
				{
					bReplace = FALSE;
					break;
				}
			}
			// 替换
			if (bReplace == TRUE)
			{
				pOperateThreadData->strText.SetAt(i, TEXT(' '));
			}
		}
	}
	while (1)
	{
		int nFindSpace = pOperateThreadData->strText.Find(TEXT(' '));
		if (nFindSpace == -1)
			break;
		
		CString strWork = pOperateThreadData->strText.Left(nFindSpace);
		pOperateThreadData->strText = pOperateThreadData->strText.Right(pOperateThreadData->strText.GetLength() - (nFindSpace + 1));
		if (strWork.GetLength()>0)
		{
			
			map<CString, DWORD>::iterator p = wordmap.find(strWork);
			if ( p != wordmap.end())
			{ // 找到
				wordmap[strWork]++;
			}
			else
			{ // 未找到
				wordmap.insert(pair<CString, DWORD>(strWork, 1));
			}
		}
		
	}

	//// 迭代器的遍历
	map<CString, DWORD>::iterator pBegin = wordmap.begin();
	while (pBegin != wordmap.end())
	{
		int nItem = pOperateThreadData->pwndListCtrl->InsertItem(pOperateThreadData->pwndListCtrl->GetItemCount(), pBegin->first);
		CString strText;
		strText.Format(_TEXT("%d"), pBegin->second);
		pOperateThreadData->pwndListCtrl->SetItemText(nItem, 1, strText);
		// 设置data
		pOperateThreadData->pwndListCtrl->SetItemData(nItem, pBegin->second);
		pBegin++;
	}
	
	// 设置排序
	pOperateThreadData->pwndListCtrl->SortItems(CompareFunc, 0);


	// 开始排序
	pOperateThreadData->pwndListCtrl->Arrange(LVA_DEFAULT);


	*pOperateThreadData->pbMenuItemClick = TRUE;
	pOperateThreadData->pwndEditView->EnableWindow(TRUE);
	delete pOperateThreadData;
	return 0;
}

void CWordFrequencyMainFrame::OnBegin()
{
	// 判断是否未输入内容
	if (m_wndSplitterWnd.GetPane(0, 0)->GetWindowTextLength() == 0)
		return;

	LPOPERATETHREADDATA pOperateThreadData = new OPERATETHREADDATA;
	pOperateThreadData->pwndEditView = m_wndSplitterWnd.GetPane(0, 0);
	pOperateThreadData->pwndListCtrl = &static_cast<CListViewEx*>(m_wndSplitterWnd.GetPane(0, 1))->GetListCtrl();
	pOperateThreadData->pMenu = GetMenu()->GetSubMenu(0);
	pOperateThreadData->pbMenuItemClick = &m_bMenuItemClick;
	m_wndSplitterWnd.GetPane(0, 0)->GetWindowText(pOperateThreadData->strText);

	


	CreateThread(NULL, 0, OperateThreadProc, pOperateThreadData, 0, NULL);
}



void CWordFrequencyMainFrame::OnUpdateBegin(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(m_bMenuItemClick);
}


BOOL CWordFrequencyMainFrame::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_F1)
	{
		// 打开主页
		ShellExecute(NULL, _T("OPEN"), _T("http://www.clearseve.com/Software/243.html"), NULL, NULL, SW_SHOWNORMAL);
		return TRUE;
	}

	return CFrameWnd::PreTranslateMessage(pMsg);
}
