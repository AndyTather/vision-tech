// FindImages.cpp: implementation of the CFindImages class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FindImages.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFindImages::CFindImages()
{
	m_bFoundInit = FALSE;
	m_bIncludeSubDirs = FALSE;
	m_nLevel = 0;
	m_nNumCount = 0;
	m_nLastCycle = 69;  // Wahey
	ZeroMemory(m_bNotLastOne, sizeof(BOOL) * MAX_LEVELS);
}


CFindImages::~CFindImages()
{

}


BOOL CFindImages::StartFindDirectory(CString strDirectory, BOOL bSubDirs)
{
	m_bIncludeSubDirs = bSubDirs;

	// Change Directory
	int nHello = ::SetCurrentDirectory(strDirectory);
	m_nLevel = 0;
	m_strCurrentDir[m_nLevel] = strDirectory;
	m_bFoundInit = FALSE;
	m_nNumCount = 0;
    return m_FindFile[m_nLevel].FindFile( "*.*" );
}


BOOL CFindImages::GetNextImageFile(CString& strFullFileName, BOOL bAllowVideo, BOOL& bVideo)
{
	BOOL bFound = FALSE;
	bVideo = FALSE;

	// This would be where our next slide is found
	while (!bFound)
	{
		m_bNotLastOne[m_nLevel] = m_FindFile[m_nLevel].FindNextFile();
		// If we are a directory lets go down it !!
		if (m_bIncludeSubDirs && 
				!m_FindFile[m_nLevel].IsDots() &&
					m_FindFile[m_nLevel].IsDirectory())
		{
			if  (m_nLevel+1 < MAX_LEVELS)
			{
				m_nLevel++;
				// Change to this directory
				m_strCurrentDir[m_nLevel] = m_FindFile[m_nLevel-1].GetFilePath(); 
				::SetCurrentDirectory(m_strCurrentDir[m_nLevel]);
				
				// Now say we are in a sub directory
				TRACE("CFindImages: Now on Level %d, Searching Folder...%s\n", m_nLevel, m_strCurrentDir[m_nLevel] );
				m_bNotLastOne[m_nLevel] = m_FindFile[m_nLevel].FindFile( "*.*" );
			}
		}
		else if (!m_FindFile[m_nLevel].IsDots() && !m_FindFile[m_nLevel].IsDirectory())
		{
			CString strName = m_FindFile[m_nLevel].GetFileName();
			strName.MakeLower();

			// Not a directory so check the filename for our kind of extension
			if (strstr(strName, ".jpg") ||
				 strstr(strName, ".gif") ||
				  strstr(strName, ".png") ||
				   strstr(strName, ".bmp") )
			{
				strFullFileName = m_FindFile[m_nLevel].GetFilePath();
//				TRACE("CFindImages: Showing Slide %d Name = %s\n", m_nNumCount, m_FindFile[m_nLevel].GetFilePath());					
				bFound = TRUE;
				m_bFoundInit = TRUE;
				bVideo = FALSE;
				m_nNumCount++;
			}
			// Look for video as well
			else if (bAllowVideo && (strstr(strName, ".avi") ||
									strstr(strName, ".mpg") ||
									strstr(strName, ".mpe") ||
									strstr(strName, ".asf") ||
									strstr(strName, ".mov") ||
									strstr(strName, ".mpeg") ||
									 strstr(strName, ".wmv") ||
									 strstr(strName, ".ts") ||
									 strstr(strName, ".vob") ||
									 strstr(strName, ".m2t")  ||
									 strstr(strName, ".m2ts")   ))
			{
				strFullFileName = m_FindFile[m_nLevel].GetFilePath();
				TRACE("CFindImages: Showing Video Name = %s\n", m_FindFile[m_nLevel].GetFilePath());					
				bFound = TRUE;
				m_bFoundInit = TRUE;
				bVideo = TRUE;
				m_nNumCount++;
			}


			
		}
		// Get next file		
		while(!m_bNotLastOne[m_nLevel])
		{
			// be kind and free resources
			m_FindFile[m_nLevel].Close();

			// Only if we are in a sub folder
			if (m_nLevel > 0)
			{
				m_strCurrentDir[m_nLevel].Empty();
				--m_nLevel;
				::SetCurrentDirectory(m_strCurrentDir[m_nLevel]);
				TRACE("Back up to level %d, Searching Folder %s\n", m_nLevel, m_strCurrentDir[m_nLevel] );
			}

			// Now if we are at the root and it was the last one restart it.
			if (m_nLevel == 0 && !m_bNotLastOne[m_nLevel])
			{
				m_nLastCycle = m_nNumCount;
				m_nNumCount = 0;

				TRACE("Lets Start again- Set cycle to %d\n", m_nLastCycle);

				m_bNotLastOne[m_nLevel] = m_FindFile[m_nLevel].FindFile( "*.*" );
				// We can't find any !!!
				if (!m_bFoundInit)
					return FALSE;
			}
		}

	}
	return bFound;
}



long CFindImages::GetCycle()
{
	return m_nLastCycle;
}
