
// WordFrequencyChildView.cpp : CWordFrequencyChildView ���ʵ��
//

#include "stdafx.h"
#include "WordFrequency.h"
#include "WordFrequencyChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWordFrequencyChildView

CWordFrequencyChildView::CWordFrequencyChildView()
{
}

CWordFrequencyChildView::~CWordFrequencyChildView()
{
}


BEGIN_MESSAGE_MAP(CWordFrequencyChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CWordFrequencyChildView ��Ϣ�������

BOOL CWordFrequencyChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CWordFrequencyChildView::OnPaint() 
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������
	
	// TODO: �ڴ˴������Ϣ����������
	
	// ��ҪΪ������Ϣ������ CWnd::OnPaint()
}

