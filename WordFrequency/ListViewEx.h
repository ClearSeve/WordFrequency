#pragma once


// CListViewEx 视图

class CListViewEx : public CListView
{
	DECLARE_DYNCREATE(CListViewEx)

protected:
	CListViewEx();           // 动态创建所使用的受保护的构造函数
	virtual ~CListViewEx();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


