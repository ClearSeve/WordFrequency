
// WordFrequencyMainFrm.h : CWordFrequencyMainFrame 类的接口
//

#pragma once
#include "WordFrequencyChildView.h"


typedef struct _OPERATETHREADDATA
{
	CWnd* pwndEditView;
	CListCtrl* pwndListCtrl;
	CMenu* pMenu;
	BOOL* pbMenuItemClick;
	CString strText;
}OPERATETHREADDATA, *LPOPERATETHREADDATA;

class CWordFrequencyMainFrame : public CFrameWnd
{
	
public:
	CWordFrequencyMainFrame();
protected: 
	DECLARE_DYNAMIC(CWordFrequencyMainFrame)

// 特性
public:
    CSplitterWnd m_wndSplitterWnd;
	BOOL m_bMenuItemClick;
// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// 实现
public:
	virtual ~CWordFrequencyMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
private:
	UINT m_wndViewWdith;
	BOOL m_bOnlyInit;
// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle = WS_OVERLAPPEDWINDOW, const RECT& rect = rectDefault, CWnd* pParentWnd = NULL, LPCTSTR lpszMenuName = NULL, DWORD dwExStyle = 0, CCreateContext* pContext = NULL);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBegin();
	afx_msg void OnUpdateBegin(CCmdUI *pCmdUI);
};


