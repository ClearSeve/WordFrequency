#pragma once


// CListViewEx ��ͼ

class CListViewEx : public CListView
{
	DECLARE_DYNCREATE(CListViewEx)

protected:
	CListViewEx();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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


