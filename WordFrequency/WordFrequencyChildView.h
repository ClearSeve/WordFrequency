
// WordFrequencyChildView.h : CWordFrequencyChildView 类的接口
//


#pragma once


// CWordFrequencyChildView 窗口

class CWordFrequencyChildView : public CWnd
{
// 构造
public:
	CWordFrequencyChildView();

// 特性
public:

// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CWordFrequencyChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

