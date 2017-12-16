#pragma once



// CWordNumber 窗体视图

class CWordNumber : public CFormView
{
	DECLARE_DYNCREATE(CWordNumber)

protected:
	CWordNumber();           // 动态创建所使用的受保护的构造函数
	virtual ~CWordNumber();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnUpdateUIState(UINT /*nAction*/, UINT /*nUIElement*/);
};


