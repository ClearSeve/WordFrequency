#pragma once

// CWordFrequencyDoc �ĵ�

class CWordFrequencyDoc : public CDocument
{
	DECLARE_DYNCREATE(CWordFrequencyDoc)

public:
	CWordFrequencyDoc();
	virtual ~CWordFrequencyDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // Ϊ�ĵ� I/O ��д
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
public:
    CString m_strContent;

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()

	virtual BOOL SaveModified();
};
