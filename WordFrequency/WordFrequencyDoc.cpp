// WordFrequencyDoc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WordFrequency.h"
#include "WordFrequencyDoc.h"


// CWordFrequencyDoc

IMPLEMENT_DYNCREATE(CWordFrequencyDoc, CDocument)

CWordFrequencyDoc::CWordFrequencyDoc()
{
}

BOOL CWordFrequencyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;


	return TRUE;
}

CWordFrequencyDoc::~CWordFrequencyDoc()
{
}


BEGIN_MESSAGE_MAP(CWordFrequencyDoc, CDocument)
END_MESSAGE_MAP()


// CWordFrequencyDoc ���

#ifdef _DEBUG
void CWordFrequencyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CWordFrequencyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CWordFrequencyDoc ���л�

void CWordFrequencyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}
}
#endif


// CWordFrequencyDoc ����
