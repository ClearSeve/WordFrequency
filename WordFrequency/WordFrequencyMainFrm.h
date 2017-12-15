
// WordFrequencyMainFrm.h : CWordFrequencyMainFrame 类的接口
//

#pragma once
#include "WordFrequencyChildView.h"

class CWordFrequencyMainFrame : public CFrameWnd
{
	
public:
	CWordFrequencyMainFrame();
protected: 
	DECLARE_DYNAMIC(CWordFrequencyMainFrame)

// 特性
public:
    CSplitterWnd m_wndSplitterWnd;
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


// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


