// drawwnd.h : header file
//
#ifndef __DRAWWND_H__
#define __DRAWWND_H__
/////////////////////////////////////////////////////////////////////////////
// CDrawWnd window
#include "FindImages.h"
#include "Engine.h"

#define WM_GRAPHNOTIFY  WM_USER + 13
#define OATRUE (-1)
#define OAFALSE (0)

//#define NOVIDEO 1
#define _VMR9ON

class CDrawWnd : public CWnd
{
// Construction
public:
	CDrawWnd(/*BOOL bAutoDelete = FALSE*/);

// Attributes
public:
	Engine	m_seqEngine;

//	CString m_strCurrentFileName;
//	CString m_strDirectory;
	int		m_nMonIdx;   // monitor index
	HANDLE  m_hEvent[2];
	HANDLE	m_dwThreadHandle;
protected:
//	CFindImages m_findimages;
	BOOL	m_bDitherOn;
	int		m_nWipeFXMode;
	int		m_nSlideDuration;
	int		m_nWipeDuration;
//	BOOL	m_bIncludeSubDirs;
//	BOOL	m_bAllowVideo;
	BOOL	m_bMuteVAudio;
	BOOL	m_bUseDefTime;
//	BOOL	m_bPseudoRandom;
	int		m_nCycle;
	static LPCTSTR m_lpszClassName;
	CPalette m_pPal;

	void SetSpeed(int nSpeed);

	void ScaleSlide(IDXSurface*	pLoadInSurf);
	void MakeBlankSlide();
	HRESULT SetupTransform(int nTransform, IDXTransform** pWipeTrans);
	HRESULT	PlayWipeForward(IDXTransform* pWipeTrans);
	HRESULT	PlayWipeBackwards(IDXTransform* pWipeTrans);
	HRESULT	PlayNoWipe();

	/////////////////////////////////////////////////
	// Movie Stuff
	RECT      grc;

	// Collection of interfaces
	IGraphBuilder *pigb  ;
	IMediaControl *pimc  ;
	IMediaEventEx *pimex ;
	IVideoWindow  *pivw  ;
	IBasicAudio	  *piba	 ;

	IBaseFilter *pVmr; 
	IVMRWindowlessControl9 *pWC;


// Event handles
protected:
    HANDLE m_hGraphNotifyEvent;
public:
    HANDLE GetGraphEventHandle( ) { return m_hGraphNotifyEvent; };
	
	BOOL m_bIsVideo;
	BOOL m_bVideoInProgress;


	BOOL m_bVFullScreen;
	void PlayMovieInWindow (LPCSTR szFile);
	void StopMovieInWindow();
	
	void PlayMovieInWindow9(LPCSTR szFile);
	void StopMovieInWindow9();
	void OnGraphNotify9();
	/////////////////////////////////////////////////

// Operations
public:
	void NextSlide();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawWnd)
	public:
	virtual BOOL Create(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	void ForceNextSlide();
	void SetShowName(BOOL bShow);
	void SetShowFPS(BOOL bShowFPS);
	void SetDemoMode(BOOL bDemo);
	void MakeTitlePage();
	void SetDirectory(CString strDirectory);
	void SetSlideDuration(int nSlideDuration);
	void SetWipeFXMode(int bFxMode);
	void SetWipeDuration(int nWipeDuration);
	void SetIncludeSubDirs(BOOL bIncludeSubDirs);
	void SetAllowVideo(BOOL bAllow);
	void SetMuteVAudio(BOOL bMute);
	void SetDefEffectTime(BOOL bUseDefTime);
	void SetPsuedoRandom(BOOL bPseudoRandom);
	virtual ~CDrawWnd();

protected:
//	BOOL m_bAutoDelete;
	BOOL m_bDemoMode;
	BOOL m_bShowFilename;
	BOOL m_bShowFPS;
	IDXTransformFactory*    m_pTransFact;
	IDXSurfaceFactory*		m_pSurfFact;
	IDXSurface*				m_pOutSurfA;
	IDXSurface*				m_pOutSurfB;
	IDXSurface*				m_pFinalOutSurf;

	IDXSurface*		m_pPrimaryDXSurf;

	BOOL	m_bCloseFlag;
	CRgn	m_rgnLast;

	int		m_cxWndWidth;
	int		m_cyWndHeight;
	DWORD	m_nSequence;
	BOOL	m_bFirstBlank;

	BOOL m_bFirstSlide;

	double m_lfFramesPerSecond;

	// Generated message map functions
protected:
	//{{AFX_MSG(CDrawWnd)
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg LRESULT OnGraphNotify();
	void OnGraphNotify();
public:
	afx_msg void OnDevModeChange(LPTSTR lpDeviceName);
};

/////////////////////////////////////////////////////////////////////////////

#endif // DRAWWND
