// drawwnd.cpp : implementation file
//
#define STRICT
//#define DIRECTDRAW_VERSION 0x0300

#include "stdafx.h"

#include "dxbounds.h"
//#include <DTBase.cpp>
//#include <DXBounds.h>
//#include <DXTGuid.c>
//#include <dxtmsftguid.h>
#include "dxtmsft.h"
#include <mmsystem.h>
#include "dxtGuid.c"
#import "..\PDXTrans\PDXTrans.tlb" no_namespace rename("IDXEffect", "myIDXEffect")


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

#pragma check_stack

#include <process.h>
#include <io.h>
#include "Saver.h"
#include "drawwnd.h"

// Define number of transforms and the Meta Creations Copyright info string
const int	MAX_STD_TRANSFORMS	=	39;	// i.e. 0-38
const int	SLIDE_TIMER=1;

const CString g_strNotice("Copyright MetaCreations Corp. 1998.  Unauthorized duplication of this string is illegal. ");

#define SAFE_RELEASE(ptr) if(ptr) { ptr->Release(); ptr = NULL; }

#define METACREATIONS_COPYRIGHT(subinterface) { subinterface* pCopyright = NULL; \
				hSubRes = pWipeTrans->QueryInterface( __uuidof(subinterface), (void **)&pCopyright ); \
				if( SUCCEEDED( hSubRes ) ) {\
					pCopyright->put_Copyright(_bstr_t(strNotice)); \
						SAFE_RELEASE(pCopyright);}}
				
// Define Constants for MultiThreaded bits
#define NEXT_SLIDE_EVENT 0
#define END_SLIDE_EVENT 1


LPCTSTR CDrawWnd::m_lpszClassName = NULL;
void SlideThreadProc( LPVOID pParam );
//HANDLE hEvent[2];
//DWORD dwThreadHandle;


/////////////////////////////////////////////////////////////////////////////
// CDrawWnd

CDrawWnd::CDrawWnd(/*BOOL bAutoDelete*/)
{
//	m_bAutoDelete = bAutoDelete;

	// NULL some items
	m_pTransFact = NULL;
	m_pSurfFact = NULL;
	m_pFinalOutSurf = NULL;
	m_pOutSurfA = NULL;
	m_pOutSurfB = NULL;
	m_pPrimaryDXSurf = NULL;

	m_lfFramesPerSecond = 0.0;
	//TCHAR szPath[MAX_PATH];
	//try
	//{
	//	// Just in case get the 'My Pictures Directory'
	//	if (FAILED( SHGetFolderPath(NULL, CSIDL_MYPICTURES, NULL, SHGFP_TYPE_CURRENT,	szPath)))
	//	{
	//		strcpy_s(szPath,"C:\\");
	//	}
	//}
	//catch(...)
	//{
	//}
	
	// User defined - settings
	// New slide show stuff
	//m_strDirectory = AfxGetApp()->GetProfileString(_T("Config"), _T("Directory"), szPath);
	m_nSlideDuration = AfxGetApp()->GetProfileInt(_T("Config"), _T("SlideTime"), 3);
	m_nWipeDuration = AfxGetApp()->GetProfileInt(_T("Config"), _T("WipeTime"), 1);

	m_nWipeFXMode = AfxGetApp()->GetProfileInt(_T("Config"), _T("WipeFXMode"), 1);
	m_bShowFilename = AfxGetApp()->GetProfileInt(_T("Config"), _T("ShowFilename"), FALSE);;
	m_bShowFPS = AfxGetApp()->GetProfileInt(_T("Config"), _T("ShowFPS"), FALSE);;
//	m_bIncludeSubDirs = AfxGetApp()->GetProfileInt(_T("Config"), _T("IncludeSubDirs"), TRUE);
//	m_bAllowVideo = AfxGetApp()->GetProfileInt(_T("Config"), _T("AllowVideo"), TRUE);
	m_bMuteVAudio = AfxGetApp()->GetProfileInt(_T("Config"), _T("MuteVAudio"), TRUE);
	m_bUseDefTime = AfxGetApp()->GetProfileInt(_T("Config"), _T("DefEffectTime"), TRUE);
//	m_bPseudoRandom = AfxGetApp()->GetProfileInt(_T("Config"), _T("PseudoRandom"), FALSE);
	m_nCycle = 1;
	// Sorry - Video Override
#ifdef NOVIDEO
	m_bAllowVideo = FALSE;
#endif


	//// quick check directory still exists
	//if (_access(m_strDirectory, 0) == -1)	// Not found
	//	m_strDirectory = szPath;


	//// Change Directory
	//m_strCurrentFileName = _T("");
 //	m_findimages.StartFindDirectory(m_strDirectory, m_bIncludeSubDirs);

	m_cxWndWidth = m_cyWndHeight = 0;

	m_bFirstSlide = TRUE;
	m_bCloseFlag = FALSE;
	m_bDemoMode = FALSE;

	m_bDitherOn = FALSE;

   /* Seed the random-number generator with current time so that
    * the numbers will be different every time we run.
    */

	m_bFirstBlank = TRUE;
	m_bVFullScreen = FALSE;

	m_bIsVideo = FALSE;
	m_bVideoInProgress = FALSE;
	
	m_nMonIdx = 0;
	
	pigb  = NULL;
	pimc  = NULL;
	pimex = NULL;
	pivw  = NULL;
	pWC = NULL;
	m_hGraphNotifyEvent = NULL;

	// Start an extra thread so we don't lockup the app when configuring

	m_hEvent[NEXT_SLIDE_EVENT] = CreateEvent(NULL, FALSE, FALSE, NULL /*_T("NextSlide")*/);
	m_hEvent[END_SLIDE_EVENT] = CreateEvent(NULL, FALSE, FALSE, _T("EndSlide"));
	m_dwThreadHandle = (HANDLE) _beginthread(SlideThreadProc, 0, this);

}


void SlideThreadProc( LPVOID pParam )
{
    CDrawWnd* pObject = (CDrawWnd*)pParam;
	bool bEndThread = false;

//	srand( (unsigned)time( NULL ) );
	srand(pObject->m_nMonIdx + (unsigned)time( NULL ));

    
	// Initialize the COM library
    CoInitialize( NULL );   
	try
	{
//    CoInitializeEx( NULL, COINIT_MULTITHREADED );    

	//	AfxOleInit();


	while (!bEndThread)
	{
		DWORD dwWait = ::WaitForMultipleObjects(2, &pObject->m_hEvent[0], FALSE, INFINITE);

		switch(dwWait)
		{
			default:
		case (WAIT_OBJECT_0):
				TRACE("SlideThreadProc(%d): Its the next slide in the Thread\n", pObject->m_nMonIdx);
				pObject->NextSlide();
				break;

		case (WAIT_OBJECT_0 + 1):
				TRACE("SlideThreadProc(%d): The End in the Thread\n", pObject->m_nMonIdx);
				bEndThread = true;
				break;
		}
	}
	}
	catch(...)
	{
	}
	  // do something with 'pObject'
	// Uninitialize the COM library
    CoUninitialize();		

	/* _endthread given to terminate */
    _endthread();

//    return ;   // thread completed successfully
}



CDrawWnd::~CDrawWnd()
{
	SetEvent( m_hEvent[END_SLIDE_EVENT]);

	// make sure we kill the extra work thread
	CloseHandle(m_hEvent[NEXT_SLIDE_EVENT]);
	CloseHandle(m_hEvent[END_SLIDE_EVENT]);
}


BEGIN_MESSAGE_MAP(CDrawWnd, CWnd)
	//{{AFX_MSG_MAP(CDrawWnd)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_WM_ACTIVATE()
	//}}AFX_MSG_MAP
	ON_WM_DEVMODECHANGE()
END_MESSAGE_MAP()

//	ON_MESSAGE(WM_GRAPHNOTIFY, OnGraphNotify)



void CDrawWnd::SetSpeed(int nSpeed)
{
	TRACE("Now setting Speed to %d\n", nSpeed);
	KillTimer(SLIDE_TIMER);
	VERIFY(SetTimer(SLIDE_TIMER, nSpeed*1000, NULL) != 0);
}



/////////////////////////////////////////////////////////////////////////////
// CDrawWnd message handlers

int CDrawWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CDXDBnds bnds;
	RECT rect;
	HRESULT hRes;
	
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// Reset Slides main vars
	m_bFirstSlide = TRUE;
	m_nSequence = 0;

	// Set the Sizes
	GetClientRect(&rect);
	m_cxWndWidth = rect.right - rect.left;
	m_cyWndHeight = rect.bottom - rect.top;
	bnds.SetXYSize(m_cxWndWidth, m_cyWndHeight);

	
	try
	{

		//Create the Transform Factory.IDXTransformFactory* pTransFact;
		hRes = CoCreateInstance( CLSID_DXTransformFactory, NULL,
					 CLSCTX_INPROC, IID_IDXTransformFactory,
					 (void **)&m_pTransFact );//Create the transform.
		if(FAILED(hRes))
		{
			::MessageBox(NULL, TEXT("Failed to CoCreate the Transform Factory!\n"
				"Please install DXMedia 6.0 from Microsoft"), TEXT("Vision Technician"), MB_OK);
			TRACE("Error %ld\n", GetLastError());
			return -1;
		}


		// Get the surface factory from the transform factory.
		m_pTransFact->QueryInterface(IID_IDXSurfaceFactory, (void**)&m_pSurfFact);
		m_pSurfFact->CreateSurface(
					 NULL, NULL, NULL, &bnds, 0, NULL,
					 IID_IDXSurface, (void**)&m_pFinalOutSurf);

		m_pSurfFact->CreateSurface(
					 NULL, NULL, &DDPF_PMARGB32, &bnds, 0, NULL,
					 IID_IDXSurface, (void**)&m_pOutSurfA);

		// Important Dither/Colour Palette Required section
		CDC* pDC = GetDC();
		int nColours = pDC->GetDeviceCaps(NUMCOLORS);
		m_pPal.CreateHalftonePalette(pDC);
		if (nColours == -1)
			m_bDitherOn = FALSE;
		else
			m_bDitherOn = TRUE;

/*
		RECT myrect;
        CDXDBnds mybnds;
		GetClientRect(&myrect );
        mybnds.SetXYSize( myrect.right, myrect.bottom );

		// Initialize the DDSURFACEDESC structure
		DDSURFACEDESC   ddsd;

		ZeroMemory( &ddsd, sizeof( ddsd ) );
		ddsd.dwSize = sizeof( ddsd );
		ddsd.dwFlags = DDSD_CAPS;
		ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

		// Pass in DDraw info to the call to IDXSurfaceFactory::CreateSurface so it
		// will know what type of underlying surface to create. Note that applications
		// that don't care what type of underlying Direct Draw surface to use would just 
		// pass NULL for the first 2 parameters. 
		// Applications that use this method for creating surfaces other than primary 
		// surfaces will have to specify dimensions either through the DDSURFACEDESC
		// parameter (param 2) or throught the DXBNDS parameter (param 4).
		hRes = m_pSurfFact->CreateSurface( NULL, &ddsd, NULL, NULL, 0,      
								NULL, IID_IDXSurface, (void **)&m_pPrimaryDXSurf );

*/

	}
	catch(...)
	{

	}
	InvalidateRect(NULL, TRUE);
#ifdef _DEBUG
//	MakeTitlePage();
	SetSpeed(1);
#else
	PostMessage(WM_TIMER, SLIDE_TIMER, 0);
#endif
	return 0;
}


BOOL CDrawWnd::Create(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
	CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// Register a class with no cursor
	if (m_lpszClassName == NULL)
	{
		m_lpszClassName = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW /*|CS_SAVEBITS|CS_DBLCLKS*/,
			::LoadCursor(AfxGetResourceHandle(),
			MAKEINTRESOURCE(IDC_NULLCURSOR)),
			(HBRUSH) ::GetStockObject(BLACK_BRUSH));
	}

	// TODO: Add your specialized code here and/or call the base class
	return CreateEx(dwExStyle, m_lpszClassName, _T(""), dwStyle,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		pParentWnd->GetSafeHwnd(), NULL, NULL );
}

void CDrawWnd::PostNcDestroy()
{
//	if (m_bAutoDelete)
//		delete this;
}




void CDrawWnd::OnDestroy() 
{
	TRACE("CDrawWnd::Destroy called\n");
//	AfxMessageBox("CDrawWnd::Destroy called");
	KillTimer(SLIDE_TIMER);
	m_bCloseFlag = TRUE;
	
	SetEvent(m_hEvent[END_SLIDE_EVENT]);


#ifndef NOVIDEO
	if (m_bVideoInProgress)
	#ifdef _VMR9ON
		StopMovieInWindow9();
	#else
		StopMovieInWindow();
	#endif
#endif	
	::WaitForSingleObject((HANDLE) m_dwThreadHandle, 500L);



	SAFE_RELEASE(m_pOutSurfA);
	SAFE_RELEASE(m_pOutSurfB);
	SAFE_RELEASE(m_pFinalOutSurf);

	SAFE_RELEASE(m_pPrimaryDXSurf);

    SAFE_RELEASE(m_pSurfFact);
	SAFE_RELEASE(m_pTransFact);


	CWnd::OnDestroy();
}


void CDrawWnd::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CWnd::OnTimer(nIDEvent);
	if (nIDEvent == SLIDE_TIMER)
	{
		// See if we can trigger the Thread instead !!!!
		SetEvent(m_hEvent[NEXT_SLIDE_EVENT]);
	}
	
}






void CDrawWnd::NextSlide()
{
    HRESULT     hRes;
    WCHAR       szWFileName[MAX_PATH*2];
	int			nSequence;
	BOOL		bDirection = FALSE;
	CString strCurrentFileName;

	IDXSurface*		pLoadInSurf	= NULL;
	IDXSurface*		pTempSurf	= NULL;
	
	// Important so not to fill the system with WM_TIMERS
	KillTimer(SLIDE_TIMER);

NEXT:	
	if (!m_seqEngine.Next(m_bIsVideo))
		goto FAILED;
	
	strCurrentFileName = m_seqEngine.GetCurrentFileName();

//	TRACE("**************** Next Slide SCRN SAVE %ld **0x%8X**%s\n", m_nMonIdx, GetCurrentThreadId(),m_strCurrentFileName);
	//Create a temp DXSurface with an image loaded on it.
    size_t size = mbstowcs( szWFileName, strCurrentFileName, MAX_PATH*2 );

	// At this point we need to test whether its a picture or Multimedia File
	// So how do we do this ??
	// If its a video file then stop timer and set no time to wait for picture

	if (m_bIsVideo)
	{
		MakeBlankSlide();	// Makes an A Surface
		SAFE_RELEASE(m_pOutSurfB);  // Releases B Surface
#ifdef _VMR9ON
		PlayMovieInWindow9 ( (LPCSTR) strCurrentFileName);
#else
		PlayMovieInWindow ( (LPCSTR) strCurrentFileName);
#endif
		return;
	}

		HRESULT hr = m_pSurfFact->LoadImage(szWFileName, NULL, NULL,
							 &DDPF_PMARGB32,
							 IID_IDXSurface,
							 (void**)&pLoadInSurf );
		if (SUCCEEDED( hr))
		{
			// Very important - Scale Loaded surface image to the size set by m_cxWndWidth etc
			ScaleSlide(pLoadInSurf);  // Creates a B surface - scaled from LoadSurf
			// Loose temp load surface
			SAFE_RELEASE(pLoadInSurf);
		}
		else
		{
			TRACE("LoadImage Failed %s, hr=%d\n", strCurrentFileName,  hr);
			goto NEXT;
		}
		


/*		if ((m_bShowFilename || m_bShowFPS) && !m_bDemoMode)
		{
			RECT rc;
			IDXDCLock*  pIDCLock = NULL;
			hRes = m_pOutSurfB->LockSurfaceDC(NULL, INFINITE, DXLOCKF_READWRITE, &pIDCLock);
			if (SUCCEEDED(hRes))
			{
				HDC hdc = pIDCLock->GetDC();
				CDC dc;
				dc.Attach(hdc);
				dc.SetBkMode(TRANSPARENT);
				if (m_bShowFilename)
				{

					dc.SetTextColor(RGB(0,0,0));
					rc.left = 0;
					rc.right = m_cxWndWidth;
					rc.top = 0;
					rc.bottom = m_cyWndHeight;
					dc.DrawText(m_strCurrentFileName, &rc, DT_CENTER | DT_NOCLIP );
					dc.SetTextColor(RGB(255,255,255));
					rc.left+=2;
					rc.top+=1;
					dc.DrawText(m_strCurrentFileName, &rc, DT_CENTER | DT_NOCLIP );
					TRACE("Written Text to: %s\n",m_strCurrentFileName);
				}
				if (m_bShowFPS)
				{
					char strFPS[255];
					sprintf(strFPS, "FPS: %2.2f", m_lfFramesPerSecond);
					dc.SetTextColor(RGB(0,0,0));
					rc.left = 0;
					rc.right = m_cxWndWidth;
					rc.top = m_cyWndHeight - 25;
					rc.bottom = m_cyWndHeight;
					dc.DrawText(strFPS, &rc, DT_NOCLIP );
					dc.SetTextColor(RGB(255,255,255));
					rc.left+=2;
					rc.top+=1;
					dc.DrawText(strFPS, &rc, DT_NOCLIP );								
				
				}
				dc.Detach();
				SAFE_RELEASE(pIDCLock);	
			}
		}
*/		
/*		if (m_bShowFPS && !m_bDemoMode)
		{
			RECT rc;
			IDXDCLock*  pIDCLock = NULL;
			hRes = m_pOutSurfB->LockSurfaceDC(NULL, INFINITE, DXLOCKF_READWRITE, &pIDCLock);
			if (SUCCEEDED(hRes))
			{
				char strFPS[20];
				
				sprintf(strFPS, "FPS: %2.2f", m_nFramesPerSecond);
				HDC hdc = pIDCLock->GetDC();
				CDC dc;
				dc.Attach(hdc);
				dc.SetBkMode(TRANSPARENT);
				dc.SetTextColor(RGB(0,0,0));
				rc.left = 0;
				rc.right = m_cxWndWidth;
				rc.top = m_cyWndHeight - 25;
				rc.bottom = m_cyWndHeight;
				dc.DrawText(strFPS, &rc, DT_NOCLIP );
				dc.SetTextColor(RGB(255,255,255));
				rc.left+=2;
				rc.top+=1;
				dc.DrawText(strFPS, &rc, DT_NOCLIP );
				dc.Detach();
				SAFE_RELEASE(pIDCLock);	
			}
		}
*/		
	// Set sequence and motion direction
	if (m_nWipeFXMode == 1)
	{
		nSequence = m_nSequence % MAX_STD_TRANSFORMS;
		bDirection = (m_nSequence / (MAX_STD_TRANSFORMS) ) % 2;
	}
	else if (m_nWipeFXMode == 2)
	{
		int nRand = rand();
		nSequence = nRand % MAX_STD_TRANSFORMS;
		bDirection = (nRand / (MAX_STD_TRANSFORMS) ) % 2;
	}


	// When no effects required do something different
	if (m_nWipeFXMode == 0)
		// Make a first copy
		hRes = PlayNoWipe();
	else
		if (!m_bFirstSlide)
		{
			IDXTransform*	pWipeTrans = NULL;
			// Setup the transform and get back the wipe interface
			hRes = SetupTransform(nSequence, &pWipeTrans);
			if( SUCCEEDED( hRes ) )
			{
				if (!bDirection)
					hRes = PlayWipeForward(pWipeTrans);
				else
					hRes = PlayWipeBackwards(pWipeTrans);
			}
			else
			{
				hRes = PlayNoWipe();
				// Lets either swap surfaces B to A
				pTempSurf = m_pOutSurfA;
				m_pOutSurfA = m_pOutSurfB;
				m_pOutSurfB = pTempSurf;
			}
			SAFE_RELEASE(pWipeTrans);
		}
		else
		{
			// Make a first copy
			hRes = PlayNoWipe();
		
			// Lets either swap surfaces B to A
			pTempSurf = m_pOutSurfA;
			m_pOutSurfA = m_pOutSurfB;
			m_pOutSurfB = pTempSurf;
		}


	// Set so we can start fading etc....
	m_bFirstSlide = FALSE;

	// Sequence 
	m_nSequence++;


FAILED:
	SAFE_RELEASE(m_pOutSurfB);

	SetSpeed(m_nSlideDuration);
}



void CDrawWnd::MakeBlankSlide()
{
	HRESULT			hRes;
	CDXDBnds		bnds;
	bnds.SetXYSize(m_cxWndWidth, m_cyWndHeight);

	try
	{
		SAFE_RELEASE(m_pOutSurfA);

		// Create Surface A
		hRes = m_pSurfFact->CreateSurface(
					 NULL, NULL, &DDPF_PMARGB32, &bnds, 0, NULL,
					 IID_IDXSurface, (void**)&m_pOutSurfA);
		hRes = m_pSurfFact->BitBlt(m_pFinalOutSurf, NULL, m_pOutSurfA, NULL, m_bDitherOn ? DXBOF_DITHER:0);

	}
	catch(...)
	{

	}

}


void CDrawWnd::ScaleSlide(IDXSurface* pLoadInSurf)
{
    IDXTScale*		pScale      = NULL;
    IDXTransform*	pScaleTransform = NULL;
	HRESULT			hRes;
	CDXDBnds		bnds;
    CDXDBnds		sbnds;
	CDXDVec			place;	
	SIZE			size;

	//Create the output DXSurface for the transform.
	//Give it a size.
	bnds.SetXYSize(m_cxWndWidth, m_cyWndHeight);

	try
	{

		// Create Surface B
		hRes = m_pSurfFact->CreateSurface(
					 NULL, NULL, &DDPF_PMARGB32, &bnds, 0, NULL,
					 IID_IDXSurface, (void**)&m_pOutSurfB);
		

		// Create and set-up the scale transform which will resize our image to fit
		// the entire window.  Use this instead of StretchBlt() to preserve
		// image quality as alpha is ignored with StretchBlt().
		hRes = m_pTransFact->CreateTransform(NULL, 0, NULL, 0, NULL, NULL, CLSID_DXTScale,
							IID_IDXTransform, (void**)&pScaleTransform);
		if(FAILED(hRes))
		{
			::MessageBox(NULL, TEXT("Failed to create the Scale transform!\n"
				"Please register dxtrans.dll."), TEXT("Vision Technician"), MB_OK);
			goto SCALEFAILED;
		}


		pScaleTransform->Setup(
							(IUnknown**)&pLoadInSurf,     // Source (from LoadImage)
							1,
							(IUnknown**)&m_pOutSurfB,    // Dest (from CreateSurface)
							1, 
							0);

		// Scaled-Image B
		// Get the IDXTScale interface because IDXTScale::ScaleFitToSize() 
		// is what we need to call.
		pScaleTransform->QueryInterface(IID_IDXTScale, (void**)&pScale);
		pScaleTransform->SetQuality(1.0f);

		size.cx = m_cxWndWidth;
		size.cy = m_cyWndHeight;
		pScale->ScaleFitToSize(NULL, size, TRUE);

		// Try to position it correctly in the center
		pScaleTransform->MapBoundsIn2Out(NULL, 0, 0, &sbnds);
		place[DXB_X] = (m_cxWndWidth - sbnds.Width()) / 2;
		place[DXB_Y] = (m_cyWndHeight - sbnds.Height()) / 2;

		// Scale the output surface to the window size.
		pScaleTransform->Execute(NULL, NULL, &place);
	}
	catch(...)
	{

	}
	// Loose PreScale-Image A
SCALEFAILED:
    SAFE_RELEASE(pScale);
    SAFE_RELEASE(pScaleTransform);
}


HRESULT CDrawWnd::SetupTransform(int nTransform, IDXTransform**	ppWipeTrans)
{
    CLSID	ourTransCLSID;
	_bstr_t bstrTransform;

	HRESULT		hRes;
	HRESULT		hSubRes;
	IDXTransform* pWipeTrans = NULL;

	// Using given transform number - use ProgID to convert into CLSID's
	switch(nTransform)
	{
		default:
		case 0:
			bstrTransform = L"DXImageTransform.Microsoft.Fade";
			break;
		case 1:
			bstrTransform = L"DXImageTransform.Microsoft.Wipe";
			break;
		case 2:
			bstrTransform = L"DXImageTransform.Microsoft.Pixelate";
			break;
		case 3:
			bstrTransform = L"DXImageTransform.Microsoft.CrBarn";
			break;
		case 4:
			bstrTransform = L"DXImageTransform.Microsoft.CrBlinds";
			break;
		case 5:
			bstrTransform = L"DXImageTransform.Microsoft.CrInset";
			break;
		case 6:
			bstrTransform = L"DXImageTransform.Microsoft.CrRadialWipe";
			break;
		case 7:
			bstrTransform = L"DXImageTransform.Microsoft.CrSlide";
			break;
		case 8:
			bstrTransform = L"DXImageTransform.Microsoft.CrStretch";
			break;
		case 9:
			bstrTransform = L"DXImageTransform.Microsoft.CrSpiral";
			break;
		case 10:
			bstrTransform = L"DXImageTransform.Microsoft.CrWheel";
			break;
		case 11:
			bstrTransform = L"DXImageTransform.Microsoft.CrZigzag";
			break;
		case 12:
			bstrTransform = L"DXImageTransform.Microsoft.CrIris";
			break;
//		case 13:
//			bstrTransform = L"DXImageTransform.MetaCreations.BurnFilm";
//			break;
		case 14:
			bstrTransform = L"DXImageTransform.MetaCreations.CenterCurls";
			break;
		case 15:
			bstrTransform = L"DXImageTransform.MetaCreations.ColorFade";
			break;
		case 16:
			bstrTransform = L"DXImageTransform.MetaCreations.Curls";
			break;
		case 17:
			bstrTransform = L"DXImageTransform.MetaCreations.Curtains";
			break;
		case 18:
			bstrTransform = L"DXImageTransform.MetaCreations.FadeWhite";
			break;
		case 19:
			bstrTransform = L"DXImageTransform.MetaCreations.FlowMotion";
			break;
		case 20:
			bstrTransform = L"DXImageTransform.MetaCreations.GlassBlock";
			break;
		case 21:
			bstrTransform = L"DXImageTransform.MetaCreations.Grid";
			break; 
		case 22:
			bstrTransform = L"DXImageTransform.MetaCreations.Jaws";
			break; 
		case 23:
			bstrTransform = L"DXImageTransform.MetaCreations.Lens";
			break; 
		case 24:
			bstrTransform = L"DXImageTransform.MetaCreations.LightWipe";
			break; 
		case 25:
			bstrTransform = L"DXImageTransform.MetaCreations.Liquid";
			break; 
		case 26:
			bstrTransform = L"DXImageTransform.MetaCreations.PageCurl";
			break; 
		case 27:
			bstrTransform = L"DXImageTransform.MetaCreations.PeelABCD";
			break;
		case 28:
			bstrTransform = L"DXImageTransform.MetaCreations.Ripple";
			break; 
		case 29:
			bstrTransform = L"DXImageTransform.MetaCreations.RollDown";
			break; 
		case 30:
			bstrTransform = L"DXImageTransform.MetaCreations.Threshold";
			break; 
		case 31:
			bstrTransform = L"DXImageTransform.MetaCreations.Twister";
			break; 
		case 32:
			bstrTransform = L"DXImageTransform.MetaCreations.Vacuum";
			break; 
		case 33:
			bstrTransform = L"DXImageTransform.MetaCreations.Water";
			break; 
		case 34:
			bstrTransform = L"DXImageTransform.MetaCreations.Wormhole";
			break; 	
		// Pandasoft only
		case 35:
			bstrTransform = L"DXImageTransform.Pandasoft.PandaZoom";
			break; 	
		// IE 5.5 only
		case 36:
			bstrTransform = L"DXImageTransform.Microsoft.CheckerBoard";
			break; 	
		case 37:
			bstrTransform = L"DXImageTransform.Microsoft.RandomBars";
			break; 	
		case 38:
			bstrTransform = L"DXImageTransform.Microsoft.RandomDissolve";
			break; 	

	}
	
	// Translate the ProgID into a CLSID that we can use
	if (FAILED(hRes = CLSIDFromProgID( bstrTransform, &ourTransCLSID)))
		return hRes;
	
try
{

	// We have selected transform - now get its interface
	hRes = m_pTransFact->CreateTransform( NULL, 0, NULL, 0, NULL, NULL, ourTransCLSID,
											IID_IDXTransform, (void **) ppWipeTrans );
	if( SUCCEEDED( hRes ) )
	{
		pWipeTrans = *ppWipeTrans;
      
		DWORD dwFlags;
        pWipeTrans->GetMiscFlags(&dwFlags);		
		
		// Set Dither output just instead we have 256 or less - yuk !!!
		if (m_bDitherOn)
			dwFlags &= DXTMF_DITHER_OUTPUT;
		else
			dwFlags &= (~DXTMF_DITHER_OUTPUT);

 
        dwFlags &= (~DXTMF_BLEND_WITH_OUTPUT);
        pWipeTrans->SetMiscFlags(dwFlags);

	
	}

	// Use string handling instead of GUID's for copyright string
	LPOLESTR lpszGUID;
	StringFromCLSID(ourTransCLSID, &lpszGUID);
	CString strNotice = g_strNotice + lpszGUID;
	// Important clean up
	CoTaskMemFree(lpszGUID);

	// Depending on which transform is selected - query for Custom Interface
	// for those extra special effects
	switch(nTransform)
	{
		case 1:
			{
				IDXTWipe* pWipe = NULL;
				hSubRes = pWipeTrans->QueryInterface( IID_IDXTWipe, (void **)&pWipe );
				if( SUCCEEDED( hSubRes ) )
				{
					switch(m_nSequence % 2)
					{
						case 0:
							pWipe->put_WipeStyle( DXWD_VERTICAL);
							break;
						case 1:
							pWipe->put_WipeStyle( DXWD_HORIZONTAL);
							break;
					}
				}
				SAFE_RELEASE(pWipe);
			}
			break;

		case 6:
			{
				ICrRadialWipe* pRadialWipe = NULL;
				hSubRes = pWipeTrans->QueryInterface( __uuidof(ICrRadialWipe), (void **)&pRadialWipe );
				if( SUCCEEDED( hSubRes ) )
				{
					switch(m_nSequence % 3)
					{
						case 0:
							pRadialWipe->put_wipeStyle( L"CLOCK" );
							break;
						case 1:
							pRadialWipe->put_wipeStyle( L"WEDGE" );
							break;
						case 2:
							pRadialWipe->put_wipeStyle( L"RADIAL" );
							break;
					}
					SAFE_RELEASE(pRadialWipe);
				}
			}
			break;

		case 7:
			{
				ICrSlide* pSlide = NULL;
				hSubRes = pWipeTrans->QueryInterface( __uuidof(ICrSlide), (void **)&pSlide );
				if( SUCCEEDED( hSubRes ) )
				{
					switch(m_nSequence % 3)
					{
						case 0:
							pSlide->put_slideStyle( L"HIDE" );
							break;
						case 1:
							pSlide->put_slideStyle( L"PUSH" );
							break;
						case 2:
							pSlide->put_slideStyle( L"SWAP" );
							break;
					}
					SAFE_RELEASE(pSlide);
				}
			}
			break;

		case 8:
			{
				ICrStretch* pStretch = NULL;
				hSubRes = pWipeTrans->QueryInterface( __uuidof(ICrStretch), (void **)&pStretch );
				if( SUCCEEDED( hSubRes ) )
				{
					switch(m_nSequence % 3)
					{
						case 0:
							pStretch->put_stretchStyle( L"SPIN" );
							break;
						case 1:
							pStretch->put_stretchStyle( L"PUSH" );
							break;
						case 2:
							pStretch->put_stretchStyle( L"HIDE" );
							break;
					}
					SAFE_RELEASE(pStretch);
				}
			}
			break;

		case 12:
			{
				ICrIris* pIris = NULL;
				hSubRes = pWipeTrans->QueryInterface( __uuidof(ICrIris), (void **)&pIris );
				if( SUCCEEDED( hSubRes ) )
				{
					switch(m_nSequence % 6)
					{
						case 0:
							pIris->put_irisStyle( L"DIAMOND" );
							break;
						case 1:
							pIris->put_irisStyle( L"CIRCLE" );
							break;
						case 2:
							pIris->put_irisStyle( L"CROSS" );
							break;
						case 3:
							pIris->put_irisStyle( L"STAR" );
							break;
						case 4:
							pIris->put_irisStyle( L"PLUS" );
							break;
						case 5:
							pIris->put_irisStyle( L"SQUARE" );
							break;
					}
					SAFE_RELEASE(pIris);
				}
			}
			break;

//		case 13:
//			METACREATIONS_COPYRIGHT(IDXTMetaBurnFilm);
//			break;
		case 14:
			METACREATIONS_COPYRIGHT(IDXTMetaCenterPeel);
			break;
		case 15:
			METACREATIONS_COPYRIGHT(IDXTMetaColorFade);
			break;
		case 16:
			METACREATIONS_COPYRIGHT(IDXTMetaPeelSmall);
			break;
		case 17:
			METACREATIONS_COPYRIGHT(IDXTMetaPeelSplit);
			break;
		case 18:
			METACREATIONS_COPYRIGHT(IDXTMetaWhiteOut);
			break;
		case 19:
			METACREATIONS_COPYRIGHT(IDXTMetaFlowMotion);
			break;
		case 20:
			METACREATIONS_COPYRIGHT(IDXTMetaGriddler2);
			break;
		case 21:
			METACREATIONS_COPYRIGHT(IDXTMetaGriddler);
			break;
		case 22:
			METACREATIONS_COPYRIGHT(IDXTMetaJaws);
			break;
		case 23:
			METACREATIONS_COPYRIGHT(IDXTMetaRadialScaleWipe);
			break;
		case 24:
			METACREATIONS_COPYRIGHT(IDXTMetaLightWipe);
			break;
		case 25:
			METACREATIONS_COPYRIGHT(IDXTMetaLiquid);
			break;
		case 26:
			METACREATIONS_COPYRIGHT(IDXTMetaPageTurn);
			break;
		case 27:
			METACREATIONS_COPYRIGHT(IDXTMetaPeelPiece);
			break;
		case 28:
			METACREATIONS_COPYRIGHT(IDXTMetaRipple);
			break;
		case 29:
			METACREATIONS_COPYRIGHT(IDXTMetaRoll);
			break;
		case 30:
			METACREATIONS_COPYRIGHT(IDXTMetaThreshold);
			break;
		case 31:
			METACREATIONS_COPYRIGHT(IDXTMetaTwister);
			break;
		case 32:
			METACREATIONS_COPYRIGHT(IDXTMetaVacuum);
			break;
		case 33:
			METACREATIONS_COPYRIGHT(IDXTMetaWater);
			break;
		case 34:
			METACREATIONS_COPYRIGHT(IDXTMetaWormHole);
			break;
		case 35:
			{
				IDXTPandaZoom* pZoom = NULL;
				hSubRes = pWipeTrans->QueryInterface( __uuidof(IDXTPandaZoom), (void **)&pZoom );
				if( SUCCEEDED( hSubRes ) )
				{
					switch(m_nSequence % 2)
					{
						case 0:
							pZoom->put_ZoomStyle( DXZS_IN );
							break;
						case 1:
							pZoom->put_ZoomStyle( DXZS_OUT );
							break;
					}
				}
				SAFE_RELEASE(pZoom);
			}
			break;

	}
}
catch(...)
{
	TRACE("CDrawWnd::TransFormation=%d FAILED\n", nTransform);

}


	TRACE("Trans=%s in sequence=%d \n", (LPCSTR) bstrTransform, m_nSequence);
	return hRes;
}



HRESULT CDrawWnd::PlayWipeForward( IDXTransform* pWipeTrans)
{
	HRESULT hRes;
	IDXEffect*		pEffect = NULL;

	IUnknown* In[2];
	IUnknown* Out[1];
	In[0] = m_pOutSurfA;
	In[1] = m_pOutSurfB;
	Out[0]= m_pFinalOutSurf;

	try
	{
		hRes = pWipeTrans->Setup( In, 2, Out, 1, 0 );
		//
		// Get the Effect interface.  We'll use this to set
		// execution properties for the effect (ie PercentComplete, Duration)
		//
		if (SUCCEEDED(hRes))
		{
			hRes = pWipeTrans->QueryInterface( IID_IDXEffect, (void **)&pEffect );
			float Duration, PercentComplete = 0.0f;
			DWORD msStartTime = timeGetTime();
			ULONG ulFrames = 0;

			// This duration can be set via the property page for
			// the effect.  It defaults to .50
			if (!m_bUseDefTime)
				pEffect->put_Duration( (float) m_nWipeDuration );
			pEffect->get_Duration( &Duration );
			TRACE("Duration: %f\n", Duration);
			do
			{
				// Set percent complete
				pEffect->put_Progress( PercentComplete );

				// Execute the transform
				hRes = pWipeTrans->Execute( NULL, NULL, NULL );
				
				// Next
				float fFramesPerSecond = (float)( (timeGetTime() - msStartTime) / 1000.0f );
				PercentComplete = (fFramesPerSecond / Duration);
				++ulFrames;
				m_lfFramesPerSecond += (ulFrames / fFramesPerSecond);
				//Ave
				m_lfFramesPerSecond /= 2;
				
				// Invalidate the area in question and force update
				InvalidateRect(NULL, FALSE);
				UpdateWindow();
				


			}
			while( PercentComplete <= 1.0f && !m_bCloseFlag);

#ifdef _DEBUG			
			double fTime = (double)(timeGetTime()-msStartTime) / 1000.;
	        TRACE( "Frames/Sec = %2f \n", (double)ulFrames / fTime );
#endif
			// Float division never gets to exactly 0
			pEffect->put_Progress( 1.0f );
			// Execute the transform
			hRes = pWipeTrans->Execute( NULL, NULL, NULL );

			// Invalidate the area in question and force update
			InvalidateRect(NULL, FALSE);
			UpdateWindow();
			SAFE_RELEASE(pEffect);
		}
	}
	catch(...)
	{

	}

	// Lets either swap surfaces B to A or something
	IDXSurface*	pTempSurf = m_pOutSurfA;
	m_pOutSurfA = m_pOutSurfB;
	m_pOutSurfB = pTempSurf;
	return hRes;
}


HRESULT CDrawWnd::PlayWipeBackwards( IDXTransform* pWipeTrans)
{
	HRESULT hRes;
	IDXEffect*		pEffect = NULL;

	IUnknown* In[2];
	IUnknown* Out[1];
	In[0] = m_pOutSurfB;
	In[1] = m_pOutSurfA;
	Out[0]= m_pFinalOutSurf;

	try
	{
		hRes = pWipeTrans->Setup( In, 2, Out, 1, 0 );
		//
		// Get the Effect interface.  We'll use this to set
		// execution properties for the effect (ie PercentComplete, Duration)
		//
		if (SUCCEEDED(hRes))
		{
			hRes = pWipeTrans->QueryInterface( IID_IDXEffect, (void **)&pEffect );
			float Duration;
			float PercentComplete = 1.0f;
			DWORD msStartTime = timeGetTime();
			ULONG ulFrames = 0;

			// This duration can be set via the property page for
			// the effect.  It defaults to .50
			if (!m_bUseDefTime)
				pEffect->put_Duration( (float) m_nWipeDuration );
			pEffect->get_Duration( &Duration );
			TRACE("Duration: %f\n", Duration);
			do
			{
				// Set percent complete
				pEffect->put_Progress( PercentComplete );

				// Execute the transform
				hRes = pWipeTrans->Execute( NULL, NULL, NULL );

				// Next
				float fFramesPerSecond = (float)( (timeGetTime() - msStartTime) / 1000.0f );
				PercentComplete = (float) 1.0f - (fFramesPerSecond / Duration);
				++ulFrames;
				m_lfFramesPerSecond += (ulFrames / fFramesPerSecond);
				//Ave
				m_lfFramesPerSecond /= 2;

				// Invalidate the area in question and force update
				InvalidateRect(NULL, FALSE);
				UpdateWindow();


			}
			while( PercentComplete >= 0.0f &&!m_bCloseFlag);

			// Float division never gets to exactly 0
			pEffect->put_Progress( 0.0f );
			// Execute the transform
			hRes = pWipeTrans->Execute( NULL, NULL, NULL );

			// Invalidate the area in question and force update
			InvalidateRect(NULL, FALSE);
			UpdateWindow();
			SAFE_RELEASE(pEffect);
		}
	}
	catch(...)
	{

	}

	// Lets either swap surfaces A to B or something
	IDXSurface*	pTempSurf = m_pOutSurfB;
	m_pOutSurfB = m_pOutSurfA;
	m_pOutSurfA = pTempSurf;
	return hRes;
}


HRESULT CDrawWnd::PlayNoWipe()
{
	HRESULT hRes;
	try
	{
		// Make a first copy
		hRes = m_pSurfFact->BitBlt(m_pFinalOutSurf, NULL, m_pOutSurfB, NULL, m_bDitherOn ? DXBOF_DITHER:0);
		// Invalidate the area in question and force update
		InvalidateRect(NULL, FALSE);
		UpdateWindow();
	}
	catch(...)
	{

	}
	return hRes;
}


BOOL CDrawWnd::OnEraseBkgnd(CDC* pDC) 
{
	if (m_bFirstBlank)
	{
		// TODO: Add your message handler code here and/or call default
		CRect rect;
		GetClientRect(&rect);
		pDC->FillSolidRect(rect, RGB(0,0,0));
		m_bFirstBlank = FALSE;
	}
	return TRUE;
}


void CDrawWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	dc.SelectPalette( &m_pPal, FALSE);
	dc.RealizePalette ();

	if (!m_bVideoInProgress && !m_bIsVideo)
	{
		try
		{
			// Lock the output surface and draw it to the DC, using GDI's BitBlt.
			if (m_pFinalOutSurf)
			{
				IDXDCLock*  pIDCLock = NULL;
				// Woz READ
				m_pFinalOutSurf->LockSurfaceDC(NULL, INFINITE, DXLOCKF_READWRITE, &pIDCLock);
				HDC hdc = pIDCLock->GetDC();
				::BitBlt(
					dc,                // handle to destination device context
					0,                  // x-coordinate of upper-left corner of dest. rect.
					0,                  // y-coordinate of upper-left corner of dest. rect.
					m_cxWndWidth,        // width of destination rectangle
					m_cyWndHeight,       // height of destination rectangle
					hdc,  // handle to source device context
					0,                  // x-coordinate of upper-left corner of source rectangle
					0,                  // y-coordinate of upper-left corner of source rectangle  
					SRCCOPY);           // raster operation code

				if ((m_bShowFilename || m_bShowFPS) && !m_bDemoMode)
				{
					RECT rc;
//					CDC dc;
//					dc.Attach(hdc);
					dc.SetBkMode(TRANSPARENT);
					if (m_bShowFilename)
					{

						dc.SetTextColor(RGB(0,0,0));
						rc.left = 0;
						rc.right = m_cxWndWidth;
						rc.top = 0;
						rc.bottom = m_cyWndHeight;
						dc.DrawText(m_seqEngine.GetCurrentFileName(), &rc, DT_CENTER | DT_NOCLIP );
						dc.SetTextColor(RGB(255,255,255));
						rc.left+=2;
						rc.top+=1;
						dc.DrawText(m_seqEngine.GetCurrentFileName(), &rc, DT_CENTER | DT_NOCLIP );
//							TRACE("Written Text to: %s\n",m_strCurrentFileName);
					}
					if (m_bShowFPS)
					{
						char strFPS[255];
						sprintf_s(strFPS, sizeof(strFPS), "FPS: %2.2f", m_lfFramesPerSecond);
						dc.SetTextColor(RGB(0,0,0));
						rc.left = 0;
						rc.right = m_cxWndWidth;
//						rc.top = 0;
						rc.top = m_cyWndHeight - 25;
						rc.bottom = m_cyWndHeight;
						dc.DrawText(strFPS, &rc, DT_NOCLIP );
						dc.SetTextColor(RGB(255,255,255));
						rc.left+=2;
						rc.top+=1;
						dc.DrawText(strFPS, &rc, DT_NOCLIP );								
					
					}
//					dc.Detach();
				}
				SAFE_RELEASE(pIDCLock);	

			}
			else
			{
				RECT rect;
				GetClientRect(&rect);
				dc.FillSolidRect(&rect, RGB(0,0,0));
				TRACE("Do a Blank\n");
			}

		}
		catch(...)
		{
			// Don't Care !!!
		}
	}
	else
	{
#ifdef _VMR9ON
		try
		{
			if (pWC)
				pWC->RepaintVideo(this->GetSafeHwnd(), dc.GetSafeHdc());	
		}
		catch(...)
		{
		}
#endif

	}


	// Do not call CWnd::OnPaint() for painting messages
}



void CDrawWnd::OnClose() 
{
	KillTimer(SLIDE_TIMER);
	m_bCloseFlag = TRUE;
	if (m_bVideoInProgress)
#ifdef _VMR9ON
		StopMovieInWindow9();
#else
		StopMovieInWindow();
#endif	
	// Call Parent and set any animation to end now
	CWnd::OnClose();

}

void CDrawWnd::SetSlideDuration(int nSlideDuration)
{
	m_nSlideDuration = nSlideDuration;
	if (!m_bVideoInProgress)
		SetSpeed(m_nSlideDuration);
}

void CDrawWnd::SetWipeDuration(int nWipeDuration)
{
	m_nWipeDuration = nWipeDuration;
}

void CDrawWnd::SetDirectory(CString strDirectory)
{
	this->m_seqEngine.SetDirectory(strDirectory);
}


void CDrawWnd::SetWipeFXMode(int bFXMode)
{
	m_nWipeFXMode = bFXMode;
}


void CDrawWnd::SetIncludeSubDirs(BOOL bIncludeSubDirs)
{
	this->m_seqEngine.SetIncludeSubDirs( bIncludeSubDirs);
}


void CDrawWnd::SetAllowVideo(BOOL bAllow)
{
	this->m_seqEngine.SetAllowVideo(bAllow);
}


void CDrawWnd::SetDefEffectTime(BOOL bUseDefTime)
{
	m_bUseDefTime = bUseDefTime;
};


void CDrawWnd::SetMuteVAudio(BOOL bMute)
{
	m_bMuteVAudio = bMute;

	if (m_bVideoInProgress && piba)
		if (this->m_bMuteVAudio)
			piba->put_Volume(-10000L);  // Mute
		else
			piba->put_Volume(0);	// Full Volume
}


void CDrawWnd::MakeTitlePage()
{
/*	IDXSurface*		pTempSurf	= NULL;
	CDXDBnds		bnds;
	HRESULT hRes;
	BITMAP bmp;
	CBitmap bmpLogo;

	bmpLogo.LoadBitmap(IDB_PANDALOGO);
	bmpLogo.GetBitmap(&bmp);

	//Create the output DXSurface for the transform.
	//Give it a size.
	bnds.SetXYSize(80,600 ); // bmp.bmWidth, bmp.bmHeight

	// Create Surface 
	hRes = m_pSurfFact->CreateSurface(
                 NULL, NULL, &DDPF_PMARGB32, &bnds, 0, NULL,
                 IID_IDXSurface, (void**)&pTempSurf);

	IDXDCLock*  pIDCLock = NULL;
	hRes = pTempSurf->LockSurfaceDC(NULL, INFINITE, DXLOCKF_READWRITE, &pIDCLock);
	HDC hdc = pIDCLock->GetDC();
	CDC dc;
	dc.Attach(hdc);
	
	CDC newDC;
	newDC.CreateCompatibleDC(&dc);
	CBitmap* poldbmp = newDC.SelectObject(&bmpLogo);
	dc.SetMapMode(MM_TEXT);
	dc.BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &newDC, 0, 0, SRCCOPY);
	dc.TextOut(0,0, "Hello");
	newDC.SelectObject(poldbmp);
	dc.Detach();
	SAFE_RELEASE(pIDCLock);	

	// Very important - Scale B surface image to the size set by m_cxWndWidth etc
//	ScaleSlide(pTempSurf);
//	hRes = m_pSurfFact->BitBlt(m_pOutSurfB, NULL, pTempSurf, NULL, NULL);
    IDXTScale*		pScale      = NULL;
    IDXTransform*	pScaleTransform = NULL;
//	CDXDBnds		bnds;
//    CDXDBnds		sbnds;
//	CDXDVec			place;	
	SIZE			size;

    // Create and set-up the scale transform which will resize our image to fit
    // the entire window.  Use this instead of StretchBlt() to preserve
    // image quality as alpha is ignored with StretchBlt().
    hRes = m_pTransFact->CreateTransform(NULL, 0, NULL, 0, NULL, NULL, CLSID_DXTScale,
                        IID_IDXTransform, (void**)&pScaleTransform);
    if(FAILED(hRes))
    {
        ::MessageBox(NULL, TEXT("Failed to create the Scale transform!\n"
            "Please register dxtrans.dll."), TEXT("Vision Technician"), MB_OK);
        goto SCALEFAILED;
    }


	hRes = pScaleTransform->Setup(
						(IUnknown**)&pTempSurf,     // Source (from LoadImage)
						1,
						(IUnknown**)&m_pFinalOutSurf,    // Dest (from CreateSurface)
						1, 
						0);

	// Scaled-Image B
    // Get the IDXTScale interface because IDXTScale::ScaleFitToSize() 
    // is what we need to call.
    pScaleTransform->QueryInterface(IID_IDXTScale, (void**)&pScale);
	pScaleTransform->SetQuality(1.0);

	size.cx = m_cxWndWidth;
	size.cy = m_cyWndHeight;
    hRes = pScale->ScaleFitToSize(NULL, size, TRUE);

    // Scale the output surface to the window size.
    hRes = pScaleTransform->Execute(NULL, NULL, NULL);

	// Loose PreScale-Image A
SCALEFAILED:
    SAFE_RELEASE(pScale);
    SAFE_RELEASE(pScaleTransform);





	// Make a first copy
//	hRes = m_pSurfFact->BitBlt(m_pFinalOutSurf, NULL, pTempSurf, NULL, NULL);
//	hRes = m_pSurfFact->BitBlt(m_pFinalOutSurf, NULL, m_pOutSurfB, NULL, NULL);

	// Loose temp load surface
    SAFE_RELEASE(pTempSurf);
*/
}

void CDrawWnd::SetDemoMode(BOOL bDemo)
{
	m_bDemoMode = bDemo;
}

void CDrawWnd::SetShowName(BOOL bShow)
{
	m_bShowFilename = bShow;
}

void CDrawWnd::SetShowFPS(BOOL bShowFPS)
{
	m_bShowFPS = bShowFPS;
}

void CDrawWnd::SetPsuedoRandom(BOOL bPseudoRandom)
{
	this->m_seqEngine.SetPsuedoRandom( bPseudoRandom );
}

//#define VFW_S_VIDEO_NOT_RENDERED 0x00040257


// PlayMovieInWindow //
void CDrawWnd::PlayMovieInWindow (LPCSTR szFile)
{ 
	HRESULT hr = S_OK;
    WCHAR wFile[MAX_PATH];
    
	MultiByteToWideChar( CP_ACP, 0, szFile, -1, wFile, MAX_PATH );
		
	SAFE_RELEASE(pigb);
      hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&pigb);
      if (SUCCEEDED(hr))
      { // Graphbuilder instance

        // QueryInterface for some basic interfaces
        pigb->QueryInterface(IID_IMediaControl, (void **)&pimc);
        pigb->QueryInterface(IID_IMediaEventEx, (void **)&pimex);
        pigb->QueryInterface(IID_IVideoWindow, (void **)&pivw);
        pigb->QueryInterface(IID_IBasicAudio, (void **)&piba);


        // Have the graph construct its the appropriate graph automatically
        hr = pigb->RenderFile(wFile, NULL);
		// Check hr for errors - especially no codec - no point
		if (hr == VFW_S_VIDEO_NOT_RENDERED)
		{
			TRACE("Codec not found for %s  Error: %ld\n", szFile, hr);
	        SAFE_RELEASE(piba);
			SAFE_RELEASE(pivw);
            SAFE_RELEASE(pimex);
            SAFE_RELEASE(pimc);
            SAFE_RELEASE(pigb);

			// Next File - NOW !!
			PostMessage(WM_TIMER, SLIDE_TIMER, 0);
			return;
		}


		// New bit
//	    hr = pimex->GetEventHandle((OAEVENT*) &m_hGraphNotifyEvent);



        pivw->put_Owner((OAHWND) this->GetSafeHwnd() );
        pivw->put_WindowStyle(WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN);

        // Have the graph signal event via window callbacks for performance
   //     pimex->SetNotifyWindow((OAHWND) this->GetSafeHwnd(), WM_GRAPHNOTIFY, 0L);

		pivw->put_MessageDrain((OAHWND) this->GetSafeHwnd() );
		pivw->HideCursor(OATRUE);

		// handle the audio settings
		if (this->m_bMuteVAudio)
			piba->put_Volume(-10000L);  // Mute

		GetClientRect(&grc);
        pivw->SetWindowPosition(grc.left, grc.top, grc.right, grc.bottom);

        // Run the graph if RenderFile succeeded
        if (SUCCEEDED(hr))
		{
			hr = pimc->Pause();
			pivw->put_Visible(OATRUE);
			m_bVideoInProgress = TRUE;
			hr = pimc->Run();
			//pimc->Release();
		}

		if (SUCCEEDED(hr)) {
			long evCode;
			hr = pimex->WaitForCompletion(INFINITE, &evCode);
			TRACE("Wait for a Completion has signaled\n");
//			if (evCode == 0  || EC_COMPLETE == evCode || EC_ERRORABORT == evCode)
//			{ // Finished
				
				TRACE("****VIDEO NOW SIGNALLED FINISHED*****\n");
				if (pivw)
				{ // Relinquish ownership (IMPORTANT!) after hiding

					pivw->put_Visible(OAFALSE);
					pivw->put_Owner(NULL);
					SAFE_RELEASE(pivw);

				} // Relinquish ownership (IMPORTANT!) after hiding
				pimex->SetNotifyWindow((OAHWND) NULL, 0, 0L);
				SAFE_RELEASE(piba);
				SAFE_RELEASE(pimc);
				SAFE_RELEASE(pimex);
				SAFE_RELEASE(pigb);
				m_bVideoInProgress = FALSE;
				// Lets go to the next bit - NOW !!
				PostMessage(WM_TIMER, SLIDE_TIMER, 0);
				//SetSpeed(m_nSlideDuration);


//			} // Finished
		}



      } // Graphbuilder instance

} // PlayMovieInWindow //

void CDrawWnd::StopMovieInWindow()
{
	HRESULT hr(S_OK);
	TRACE("StopMovieInWindow(%ld)\n", m_nMonIdx);
//	AfxMessageBox("CDrawWnd::StopMovieInWindow()");

	try
	{	
		if (pimc)
		{
//			hr = pimc->StopWhenReady();
			hr = pimc->Stop();
/*				if (pivw)
				{ // Relinquish ownership (IMPORTANT!) after hiding

					pivw->put_Visible(OAFALSE);
					pivw->put_Owner(NULL);
					SAFE_RELEASE(pivw);

				} // Relinquish ownership (IMPORTANT!) after hiding
				pimex->SetNotifyWindow((OAHWND) NULL, 0, 0L);
				SAFE_RELEASE(piba);
				SAFE_RELEASE(pimc);
				SAFE_RELEASE(pimex);
				SAFE_RELEASE(pigb);
				m_bVideoInProgress = FALSE;
			*/
		}
		m_hGraphNotifyEvent = NULL;

	}
	catch(...)
	{

	}

}


void CDrawWnd::OnGraphNotify()
{
    long lEventCode;
	LONG_PTR lParam1, lParam2;

    ASSERT( m_hGraphNotifyEvent != NULL );

	if( SUCCEEDED(pimex->GetEvent(&lEventCode, &lParam1, &lParam2, 0)))
	{

            HRESULT hrTmp = pimex->FreeEventParams(lEventCode, lParam1, lParam2);
            ASSERT(SUCCEEDED(hrTmp));

            // if this is a normal stop, then we do a rewind as
            // we would if the user pressed stop. For an abort,
            // we don't touch this.
 /*           if (lEventCode == EC_COMPLETE) {
                OnMediaStop();
            } else if ((lEventCode == EC_ERRORABORT) ||
                       (lEventCode == EC_USERABORT)) {

                // put the graph into stop mode but don't mess with it.
                OnAbortStop();
            }*/
			if (EC_COMPLETE == lEventCode || EC_ERRORABORT == lEventCode)
			{ 
				// Finished
				if (pivw)
				{ // Relinquish ownership (IMPORTANT!) after hiding

					pivw->put_Visible(OAFALSE);
					pivw->put_Owner(NULL);
					SAFE_RELEASE(pivw);

				} // Relinquish ownership (IMPORTANT!) after hiding


				SAFE_RELEASE(piba);
				SAFE_RELEASE(pimc);
				SAFE_RELEASE(pimex);
				SAFE_RELEASE(pigb);
				m_bVideoInProgress = FALSE;
			}
			// Lets go to the next bit - NOW !!
			PostMessage(WM_TIMER, SLIDE_TIMER, 0);

    }
}


//LRESULT CDrawWnd::OnGraphNotify()
/*void Test()
{
	HRESULT hr;
	LONG      evCode;
	LONG      evParam1;
	LONG      evParam2;

	while (SUCCEEDED(pimex->GetEvent(&evCode, &evParam1, &evParam2, 0)))
    { // Spin through the events

        hr = pimex->FreeEventParams(evCode, evParam1, evParam2);
		ASSERT(SUCCEEDED(hr));
		TRACE("Notify Code=%d\n", evCode);

        if (EC_COMPLETE == evCode || EC_ERRORABORT == evCode
        { // Finished
			
			TRACE("****VIDEO NOW SIGNALLED FINISHED*****\n");
			if (pivw)
			{ // Relinquish ownership (IMPORTANT!) after hiding

				pivw->put_Visible(OAFALSE);
				pivw->put_Owner(NULL);
				SAFE_RELEASE(pivw);

			} // Relinquish ownership (IMPORTANT!) after hiding
//			pimex->SetNotifyWindow((OAHWND) NULL, 0, 0L);
	        SAFE_RELEASE(piba);
            SAFE_RELEASE(pimc);
            SAFE_RELEASE(pimex);
            SAFE_RELEASE(pigb);
			m_bVideoInProgress = FALSE;
			// Lets go to the next bit - NOW !!
			PostMessage(WM_TIMER, SLIDE_TIMER, 0);
			//SetSpeed(m_nSlideDuration);
            break;

        } // Finished
      
      } // Spin through the events


	return 0L;
}
*/

void CDrawWnd::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CWnd::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	
}

void CDrawWnd::ForceNextSlide()
{
	TRACE("ForceNextSlide Called");
	
//	KillTimer(SLIDE_TIMER);
	if (m_bVideoInProgress)
#ifdef _VMR9ON
		StopMovieInWindow9();
#else
		StopMovieInWindow();
#endif
//	else
//	{

		// Lets go to the next bit - NOW !!
		PostMessage(WM_TIMER, SLIDE_TIMER, 0);
//	}
}

void CDrawWnd::PlayMovieInWindow9(LPCSTR szFile)
{ 
	HRESULT hr = S_OK;
    WCHAR wFile[MAX_PATH];
    
	MultiByteToWideChar( CP_ACP, 0, szFile, -1, wFile, MAX_PATH );
	SAFE_RELEASE(pigb);


	try
	{
		hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&pigb);
		if (SUCCEEDED(hr))
		{
			// Graphbuilder instance
			hr = CoCreateInstance(CLSID_VideoMixingRenderer9, NULL, CLSCTX_INPROC, IID_IBaseFilter, (void**)&pVmr);
			if (SUCCEEDED(hr))
			{
				// add the VMR9 filter to the Graph Manager
				pigb->AddFilter(pVmr, L"VMR9"); 

				// get a pointer to the IVMRFilterConfig9 interface
				IVMRFilterConfig9 *pConfig;
				hr = pVmr->QueryInterface(IID_IVMRFilterConfig9, (void**)&pConfig);
				if (SUCCEEDED(hr))
				{
					// make sure VMR9 is in windowless mode
					hr = pConfig->SetRenderingMode(VMRMode_Windowless);
//					CString test;
//					test.Format("Render VFW_E_WRONG_STATE failed 0x%X",hr);
//					AfxMessageBox((const char*) test);

					pConfig->Release();
				}
				else
					AfxMessageBox("Failed to Query FilterConfig");


				// get a pointer to the IVMRWindowlessControl9 interface 
				hr = pVmr->QueryInterface(IID_IVMRWindowlessControl9, (void**)&pWC);
				if (SUCCEEDED(hr))
				{
					hr = pWC->SetVideoClippingWindow( this->GetSafeHwnd() );
					if (SUCCEEDED(hr))
					{

						// Find the native video size
						long lWidth, lHeight;
						hr = pWC->GetNativeVideoSize(&lWidth, &lHeight, NULL, NULL);
						if (SUCCEEDED(hr))
						{
							RECT rcSrc, rcDest;

							SetRect(&rcSrc, 0,0,lWidth, lHeight);

							// Get Window client area
							GetClientRect(&rcDest);
							SetRect(&rcDest, 0 ,0, rcDest.right, rcDest.bottom);
							hr = pWC->SetVideoPosition(&rcSrc, &rcDest);
							hr = pWC->SetAspectRatioMode(VMR9ARMode_LetterBox);
						}
					}
				}
			}
			else
				AfxMessageBox("Failed to VMR9");


			// QueryInterface for some basic interfaces
			pigb->QueryInterface(IID_IMediaControl, (void **)&pimc);
			pigb->QueryInterface(IID_IBasicAudio, (void **)&piba);
			pigb->QueryInterface(IID_IMediaEventEx, (void **)&pimex);

			// Have the graph construct its the appropriate graph automatically
			try
			{
				hr = pigb->RenderFile(wFile, NULL);
			}
			catch(...)
			{
			
			}
			// Check hr for errors - especially no codec - no point
			if (hr == VFW_S_VIDEO_NOT_RENDERED)
			{
				m_bVideoInProgress = FALSE;
				TRACE("Codec not found for %s  Error: %ld\n", szFile, hr);
				SAFE_RELEASE(piba);
				SAFE_RELEASE(pimex);
				SAFE_RELEASE(pWC);
				SAFE_RELEASE(pimc);
				SAFE_RELEASE(pVmr);
				SAFE_RELEASE(pigb);

				// Next File - NOW !!
				PostMessage(WM_TIMER, SLIDE_TIMER, 0);
				return;
			}

			// handle the audio settings
			if (this->m_bMuteVAudio)
				piba->put_Volume(-10000L);  // Mute

	        // Run the graph if RenderFile succeeded
//			hr = pimc->Pause();
			m_bVideoInProgress = TRUE;
			hr = pimc->Run();


			long evCode;
			hr = pimex->WaitForCompletion(INFINITE, &evCode);
			TRACE("Wait for a Completion has signaled\n");
			m_bVideoInProgress = FALSE;
			
			TRACE("****VIDEO NOW SIGNALLED FINISHED*****\n");
			SAFE_RELEASE(piba);
			SAFE_RELEASE(pimc);
			SAFE_RELEASE(pWC);
			SAFE_RELEASE(pimex);
			SAFE_RELEASE(pVmr);
			SAFE_RELEASE(pigb);
			// Lets go to the next bit - NOW !!
			PostMessage(WM_TIMER, SLIDE_TIMER, 0);


		}
		else
			AfxMessageBox("Failed to make graph");

	}
	catch(...)
	{
		m_bVideoInProgress = FALSE;
		SAFE_RELEASE(piba);
		SAFE_RELEASE(pimc);
		SAFE_RELEASE(pWC);
		SAFE_RELEASE(pimex);
		SAFE_RELEASE(pVmr);
		SAFE_RELEASE(pigb);	
		PostMessage(WM_TIMER, SLIDE_TIMER, 0);
	}

}

void CDrawWnd::StopMovieInWindow9()
{
	HRESULT hr(S_OK);
	TRACE("StopMovieInWindow9(%ld)\n", m_nMonIdx);

	try
	{	
		if (pimc)
		{
//			hr = pimc->StopWhenReady();
			hr = pimc->Stop();
		}
	}
	catch(...)
	{

	}
}

void CDrawWnd::OnGraphNotify9()
{

}

void CDrawWnd::OnDevModeChange(LPTSTR lpDeviceName)
{
	CWnd::OnDevModeChange(lpDeviceName);

	// TODO: Add your message handler code here
}
