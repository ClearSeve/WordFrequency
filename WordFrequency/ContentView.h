#pragma once


// CContentView ��ͼ

class CContentView : public CEditView
{
	DECLARE_DYNCREATE(CContentView)

protected:
	CContentView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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


