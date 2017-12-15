#pragma once


// CContentView 视图

class CContentView : public CEditView
{
	DECLARE_DYNCREATE(CContentView)

protected:
	CContentView();           // 动态创建所使用的受保护的构造函数
	virtual ~CContentView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


