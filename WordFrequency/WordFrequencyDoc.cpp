// WordFrequencyDoc.cpp : 实现文件
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


// CWordFrequencyDoc 诊断

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
// CWordFrequencyDoc 序列化

void CWordFrequencyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
	}
	else
	{
		// TODO:  在此添加加载代码
	}
}
#endif


// CWordFrequencyDoc 命令



BOOL CWordFrequencyDoc::SaveModified()
{
	// TODO:  在此添加专用代码和/或调用基类

	return TRUE; // CDocument::SaveModified();
}
