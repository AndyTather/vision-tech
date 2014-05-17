// Saver.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"

#include "Saver.h"
#include "Saverdlg.h"
#include "VPropertySheet.h"
#include "monitor.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSaverApp

BEGIN_MESSAGE_MAP(CSaverApp, CWinApp)
	//{{AFX_MSG_MAP(CSaverApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

TCHAR szConfig[]=_T("Config");

/////////////////////////////////////////////////////////////////////////////
// CSaverApp construction

CSaverApp::CSaverApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_pSWnd = NULL;
	m_pDWnd = NULL;

	
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSaverApp object

CSaverApp theApp;

/*BOOL MatchOption(LPTSTR lpsz, LPTSTR lpszOption)
{
	if (lpsz == NULL)
		return FALSE;

	if (lpsz[0] == '-' || lpsz[0] == '/')
		lpsz++;
	if (lstrcmpi(lpsz, lpszOption) == 0)
		return TRUE;
	return FALSE;
}
*/
BOOL MatchOption(LPTSTR lpsz, TCHAR ch)
{
	if (lpsz == NULL)
		return FALSE;

    if (lpsz[0] == '-' || lpsz[0] == '/')
        lpsz++;

    if (lpsz[0] == ch)
        return TRUE;

    return FALSE;
}

BOOL CALLBACK CSaverApp::AddMonitorsCallBack( HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData )
{
	CSaverApp* pSaverApp = (CSaverApp*) dwData;

	CMonitor* pMon = (CMonitor*) new CMonitor();
	pMon->m_hMonitor = hMonitor;
	pMon->m_rect.SetRect(lprcMonitor->left, lprcMonitor->top, lprcMonitor->right, lprcMonitor->bottom);

	pSaverApp->m_monitorlist.Add(pMon);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSaverApp initialization

BOOL CSaverApp::InitInstance()
{
    // Initialize the COM library
    CoInitialize( NULL);

	// New feature - monitor check
	int vscr = ::GetSystemMetrics(SM_CMONITORS);
	::EnumDisplayMonitors( NULL, NULL, (MONITORENUMPROC) AddMonitorsCallBack, (LPARAM) this );
	
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
#ifdef _AFXDLL
//	Enable3dControls();         // Call this when using MFC in a shared DLL
#else
//	Enable3dControlsStatic();   // Call this when linking to MFC statically
#endif

	SetRegistryKey(_T("Pandasoft Computer Systems"));

	//First free the string allocated by MFC at CWinApp startup.
	//The string is allocated before InitInstance is called.
	free((void*)m_pszProfileName);
	//Change the name of the .INI file.
	//The CWinApp destructor will free the memory.
	m_pszProfileName=_tcsdup(_T("VTSCR"));

	if (MatchOption(__argv[1], _T('s')))
	{
		CRect rect;

		int nMultiMode = AfxGetApp()->GetProfileInt(_T("Config"), _T("MultiMonMode"), 0);
		// Single mon
		if (nMultiMode == 0)
		{
			rect.left = 0;
			rect.top = 0;
			rect.right = ::GetSystemMetrics(SM_CXSCREEN);
			rect.bottom = ::GetSystemMetrics(SM_CYSCREEN);
			m_pSWnd = new CSaverWnd();
			m_pSWnd->Create(rect,0);
			m_pMainWnd = m_pSWnd;
		}
		else if (nMultiMode == 1)
		{
			// Virtual Multi mon
			rect.left = ::GetSystemMetrics(SM_XVIRTUALSCREEN);
			rect.top = ::GetSystemMetrics(SM_YVIRTUALSCREEN);
			rect.right = ::GetSystemMetrics(SM_CXVIRTUALSCREEN);
			rect.bottom = ::GetSystemMetrics(SM_CYVIRTUALSCREEN);
			m_pSWnd = new CSaverWnd();
			m_pSWnd->Create(rect,0);
			m_pMainWnd = m_pSWnd;
		}
		else if (nMultiMode == 2)
		{
			// Seperate Instance for each
			for ( int i = 0; i < m_monitorlist.GetSize(); i++ )			
			{
				CMonitor* pMon = (CMonitor*) m_monitorlist.GetAt(i);

				pMon->m_pSWnd = new CSaverWnd();
				pMon->m_pSWnd->Create(pMon->m_rect,0);

				if (i==0)
				{
					m_pMainWnd = pMon->m_pSWnd;
				}
			}
	
		}
		else
		{
			// Seperate Instance for each screen and possible random list of media
			for ( int i = 0; i < m_monitorlist.GetSize(); i++ )			
			{
				CMonitor* pMon = (CMonitor*) m_monitorlist.GetAt(i);

				pMon->m_pSWnd = new CSaverWnd();
				pMon->m_pSWnd->Create(pMon->m_rect,i);

				if (i==0)
				{
					m_pMainWnd = pMon->m_pSWnd;
				}
			}
		}

		return TRUE;
	}
	else if (MatchOption(__argv[1], _T('p')))
	{
		CRect rect;
		CWnd* pParent = CWnd::FromHandle((HWND)atol(__argv[2]));
		ASSERT(pParent != NULL);
		pParent->GetClientRect(&rect);
		m_pDWnd = new CDrawWnd();
		if(m_pDWnd->Create(WS_EX_TOPMOST, WS_VISIBLE|WS_CHILD, rect, pParent, NULL))
		{
			m_pDWnd->SetDemoMode(TRUE);
			m_pMainWnd = m_pDWnd;
			return TRUE;
		}
	}
	else if (MatchOption(__argv[1], _T('c')))
	{
		DoConfig(CWnd::GetForegroundWindow());
	}
	else
	{
		DoConfig(NULL);
	}
	return FALSE;
}


void CSaverApp::DoConfig(CWnd* pParent)
{
	CVisionPropertySheet propSheet(pParent);

	// Set Main Dlg Item
	m_pMainWnd = &propSheet;
	propSheet.DoModal();

}


int CSaverApp::ExitInstance() 
{
	try
	{

//		for ( int i = 0; i < m_monitorlist.GetSize(); i++ )
		for ( INT_PTR i = m_monitorlist.GetSize()-1; i >= 0; i-- )
		{
			CMonitor* pMon = (CMonitor*) m_monitorlist.GetAt(i);
			if (pMon->m_pSWnd)
#ifdef _VMR9ON
				pMon->m_pSWnd->StopMovieInWindow9();
#else
				pMon->m_pSWnd->StopMovieInWindow();
#endif

			delete m_monitorlist.GetAt( i );
		}

		if (m_pSWnd)
			delete m_pSWnd;
		if (m_pDWnd)
			delete m_pDWnd;
	}
	catch(...)
	{
	}
	// Uninitialize the COM library
    CoUninitialize();	
	return CWinApp::ExitInstance();
}

/*int CSaverApp::Run()
{   // Overridden to check for Graph events as well as messages

	if (m_pMainWnd == NULL && AfxOleGetUserCtrl())
	{
		// Not launched /Embedding or /Automation, but has no main window!
		TRACE0("Warning: m_pMainWnd is NULL in CPlayerApp::Run - quitting application.\n");
		AfxPostQuitMessage(0);
	}

	CDrawWnd* pWnd = (CDrawWnd*) m_pMainWnd; 

    BOOL bIdle = TRUE;
    LONG lIdleCount = 0;
    HANDLE  ahObjects[1];               // handles that need to be waited on
    const int cObjects = 1;             // no of objects that we are waiting on

    // message loop lasts until we get a WM_QUIT message
    // upon which we shall return from the function
    while (TRUE) {

        // If we don't have an event handle then process idle
        // routines until a message arrives or until the idle routines
        // stop (when we block until a message arrives). The graph event
        // handle can only be created in response to a message
        if( (ahObjects[ 0 ] = pWnd->GetGraphEventHandle()) == NULL ){
    		while (    bIdle
    		        && !::PeekMessage(&m_msgCur, NULL, NULL, NULL, PM_NOREMOVE))
    		{
    			// call OnIdle while in bIdle state
    			if (!OnIdle(lIdleCount++)){
    				bIdle = FALSE;
                    WaitMessage();
                }
    		}
        } else {
            // wait for any message sent or posted to this queue
            // or for a graph notification. If there is no message or event
            // and we are idling then we process the idle time routines
            DWORD result;

            result = MsgWaitForMultipleObjects( cObjects
                                              , ahObjects
                                              , FALSE
                                              , (bIdle ? 0 : INFINITE)
                                              , QS_ALLINPUT
                                              );
            if( result != (WAIT_OBJECT_0 + cObjects) ){
                // not a message...

                if( result == WAIT_OBJECT_0 )
                    pWnd->OnGraphNotify();

                else if( result == WAIT_TIMEOUT )
                    if(!OnIdle(lIdleCount++))
                        bIdle = FALSE;

                continue;
            }
        }


        // When here, we either have a message or no event handle
        // has been created yet.

        // read all of the messages in this next loop
        // removing each message as we read it
		do
		{
			// pump message, but quit on WM_QUIT
			if (!PumpMessage())
				return ExitInstance();

			// reset "no idle" state after pumping "normal" message
			if (IsIdleMessage(&m_msgCur))
			{
				bIdle = TRUE;
				lIdleCount = 0;
			}

		} while (::PeekMessage(&m_msgCur, NULL, NULL, NULL, PM_NOREMOVE));

    } // end of the always while-loop


}


*/