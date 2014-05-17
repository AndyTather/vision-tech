// FindImages.h: interface for the CFindImages class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FINDIMAGES_H__B0750076_CF1A_11D2_B01E_000000000000__INCLUDED_)
#define AFX_FINDIMAGES_H__B0750076_CF1A_11D2_B01E_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const int MAX_LEVELS = 20;

class CFindImages  
{
public:
	long GetCycle();
	CFindImages();
	virtual ~CFindImages();

	BOOL GetNextImageFile(CString& strFullFileName, BOOL bAllowVideo, BOOL& bVideo);
	BOOL StartFindDirectory(CString strDirectory, BOOL bSubDirs);
protected:
	CFileFind	m_FindFile[MAX_LEVELS];	
	CString		m_strCurrentDir[MAX_LEVELS];
	BOOL		m_bNotLastOne[MAX_LEVELS];

	BOOL	m_bFoundInit;
	BOOL	m_bIncludeSubDirs;

	int		m_nLevel;

	long	m_nNumCount;
	long	m_nLastCycle;
};

#endif // !defined(AFX_FINDIMAGES_H__B0750076_CF1A_11D2_B01E_000000000000__INCLUDED_)
