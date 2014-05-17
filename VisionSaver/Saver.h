// Saver.h : main header file for the SAVER application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "drawwnd.h"
#include "saverwnd.h"
/////////////////////////////////////////////////////////////////////////////
// CSaverApp:
// See Saver.cpp for the implementation of this class
//

class CSaverApp : public CWinApp
{
public:
	CSaverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaverApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
//	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
	void DoConfig(CWnd* pParent);
	CSaverWnd*	m_pSWnd;
	CDrawWnd*	m_pDWnd;
	static BOOL CALLBACK AddMonitorsCallBack( HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData );

	CObArray	m_monitorlist;

	//{{AFX_MSG(CSaverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
