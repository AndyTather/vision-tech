#include "stdafx.h"
#include "Engine.h"
#include <io.h>

Engine::Engine(void)
{
	m_bPseudoRandom = AfxGetApp()->GetProfileInt(_T("Config"), _T("PseudoRandom"), FALSE);
	m_bAllowVideo = AfxGetApp()->GetProfileInt(_T("Config"), _T("AllowVideo"), TRUE);
	m_bIncludeSubDirs = AfxGetApp()->GetProfileInt(_T("Config"), _T("IncludeSubDirs"), TRUE);

	TCHAR szPath[MAX_PATH];
	try
	{
		// Just in case get the 'My Pictures Directory'
		if (FAILED( SHGetFolderPath(NULL, CSIDL_MYPICTURES, NULL, SHGFP_TYPE_CURRENT,	szPath)))
		{
			strcpy_s(szPath,"C:\\");
		}
	}
	catch(...)
	{
	}
	m_strDirectory = AfxGetApp()->GetProfileString(_T("Config"), _T("Directory"), szPath);
	
		// quick check directory still exists
	if (_access(m_strDirectory, 0) == -1)	// Not found
		m_strDirectory = szPath;

	// Change Directory
	m_strCurrentFileName = _T("");
 	m_findimages.StartFindDirectory(m_strDirectory, m_bIncludeSubDirs);
}


Engine::~Engine(void)
{
}


bool Engine::Next(BOOL&  bIsVideo)
{
	int nTries = 1;
	int images = m_findimages.GetCycle();
	if (m_bPseudoRandom && images>0)
		nTries = rand() % images;
	
	TRACE("****(%d) Tries %ld Cycle=%ld\n", 0,nTries, images);

	for (int nTry = 0; nTry < nTries; nTry++)
//NEXT:	
	if (!m_findimages.GetNextImageFile(m_strCurrentFileName, m_bAllowVideo,  bIsVideo))
		goto FAILED;
	

	return true;
FAILED:
	return false;
}


void Engine::SetDirectory(CString strDirectory)
{
	m_strCurrentFileName = "";
	// Only reset if we have a change
	if (m_strDirectory != strDirectory)
	{
		m_strDirectory = strDirectory;
		m_findimages.StartFindDirectory(m_strDirectory, m_bIncludeSubDirs);
	}
}

void Engine::SetPsuedoRandom(BOOL bPseudoRandom)
{
	m_bPseudoRandom = bPseudoRandom;
}

void Engine::SetIncludeSubDirs(BOOL bIncludeSubDirs)
{
	m_bIncludeSubDirs = bIncludeSubDirs;
}

void Engine::SetAllowVideo(BOOL bAllow)
{
	m_bAllowVideo = bAllow;
}