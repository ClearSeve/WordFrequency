
// WordFrequencyChildView.h : CWordFrequencyChildView ��Ľӿ�
//


#pragma once


// CWordFrequencyChildView ����

class CWordFrequencyChildView : public CWnd
{
// ����
public:
	CWordFrequencyChildView();

// ����
public:

// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CWordFrequencyChildView();

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

