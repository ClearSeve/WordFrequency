
// WordFrequencyMainFrm.h : CWordFrequencyMainFrame ��Ľӿ�
//

#pragma once
#include "WordFrequencyChildView.h"

class CWordFrequencyMainFrame : public CFrameWnd
{
	
public:
	CWordFrequencyMainFrame();
protected: 
	DECLARE_DYNAMIC(CWordFrequencyMainFrame)

// ����
public:
    CSplitterWnd m_wndSplitterWnd;
// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// ʵ��
public:
	virtual ~CWordFrequencyMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


