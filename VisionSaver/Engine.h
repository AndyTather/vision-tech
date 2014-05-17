#pragma once

#include "FindImages.h"

class Engine
{
public:	
	CString m_strDirectory;
	
	BOOL	m_bPseudoRandom;
	BOOL	m_bAllowVideo;
	BOOL	m_bIsVideo;
	BOOL	m_bIncludeSubDirs;

protected:
	CFindImages m_findimages;
	CString m_strCurrentFileName;
public:
	Engine(void);
	~Engine(void);

	bool Next(BOOL&  bIsVideo);

	void SetDirectory(CString strDirectory);
	void SetPsuedoRandom(BOOL bPseudoRandom);
	void SetIncludeSubDirs(BOOL bIncludeSubDirs);
	void SetAllowVideo(BOOL bAllow);

	CString GetCurrentFileName() { return m_strCurrentFileName; };
};

