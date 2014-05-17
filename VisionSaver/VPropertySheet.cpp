// VPropertySheet.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "drawwnd.h"
#include "saverDlg.h"

#include "VPropertySheet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

#define WM_RESIZEPAGE WM_USER + 111

const int SHIFTRIGHT = 210;		// Max 250

/////////////////////////////////////////////////////////////////////////////
// CVisionPropertySheet

IMPLEMENT_DYNAMIC(CVisionPropertySheet, CPropertySheet)

CVisionPropertySheet::CVisionPropertySheet(CWnd* pWndParent, HBITMAP hbmWatermark)
	 : CPropertySheet(IDS_PROPSHT_CAPTION, pWndParent, 0, hbmWatermark)
{
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// Add all of the property pages here.  Note that
	// the order that they appear in here will be
	// the order they appear in on screen.  By default,
	// the first page of the set is the active one.
	// One way to make a different property page the 
	// active one is to call SetActivePage().

	AddPage(&m_Page1);
	AddPage(&m_Page2);
	AddPage(&m_Page3);
#ifndef NOVIDEO
	AddPage(&m_Page4);
#endif
	AddPage(&m_Page5);
	m_bNeedReset = FALSE;

}

CVisionPropertySheet::~CVisionPropertySheet()
{
	DeleteObject(hTransBitmap);
}


BEGIN_MESSAGE_MAP(CVisionPropertySheet, CPropertySheetEx)
	//{{AFX_MSG_MAP(CVisionPropertySheet)
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_RESIZEPAGE, OnResizePage)
	ON_COMMAND(ID_APPLY_NOW, OnApplyNow)
	ON_COMMAND(IDHELP, OnHelpNow)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CVisionPropertySheet message handlers

BOOL CVisionPropertySheet::OnInitDialog()
{
	BITMAP bmp;

	BOOL bResult = CPropertySheetEx::OnInitDialog();

	// Increase size of property sheet
	CRect rectWnd;
	GetWindowRect(rectWnd);
	SetWindowPos(NULL, 0, 0,
		rectWnd.Width() + SHIFTRIGHT,
		rectWnd.Height(),
		SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

	// Bitmap
	CRect rectImage( 15, 5, 15, 35);

	hTransBitmap = ::LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_MONITOR2),
		IMAGE_BITMAP, 0, 0,  LR_LOADTRANSPARENT | LR_LOADMAP3DCOLORS);
    // 
    // Get the size of the bitmap. 
    // 
    GetObject(hTransBitmap, sizeof(bmp), &bmp); 

	
	rectImage.right = rectImage.left + bmp.bmWidth;
	rectImage.bottom= rectImage.top + bmp.bmHeight;
	m_wndImage.Create(NULL, WS_CHILD|WS_VISIBLE | SS_BITMAP | SS_CENTERIMAGE | SS_REALSIZEIMAGE,
						rectImage, this, 301);
	m_wndImage.SetBitmap((HBITMAP) hTransBitmap);

	// add a preview window to the property sheet.
	CRect rectPreview( rectImage.left+16, rectImage.top+50,
						rectImage.left+169, rectImage.top+163 );
	m_wndPreview.Create(NULL, WS_VISIBLE|WS_CHILD|WS_BORDER|WS_CLIPCHILDREN, rectPreview, this, NULL);
	m_wndPreview.SetDemoMode(TRUE);

	// Resize the tab control
	CTabCtrl* pTab = GetTabControl();
	ASSERT(pTab);
	pTab->GetWindowRect(rectWnd);
	ScreenToClient(rectWnd);
	rectWnd.left += SHIFTRIGHT;
	rectWnd.right += SHIFTRIGHT;
	pTab->MoveWindow(rectWnd);

	// Resize property page
	CPropertyPage* pPage = GetActivePage();
	ASSERT(pPage);
	// Store page size in m_PageRect
	pPage->GetWindowRect(&m_PageRect);
	ScreenToClient(&m_PageRect);
	m_PageRect.right +=SHIFTRIGHT;
	m_PageRect.left += SHIFTRIGHT;
	pPage->MoveWindow(&m_PageRect);
	
	// Now the buttons below to be complete
	CWnd* pWnd = GetDlgItem(IDOK);
	pWnd->GetWindowRect(rectWnd);
	rectWnd.left += SHIFTRIGHT;
	rectWnd.right += SHIFTRIGHT;
	ScreenToClient(rectWnd);
	pWnd->MoveWindow(rectWnd);

	pWnd = GetDlgItem(IDCANCEL);
	pWnd->GetWindowRect(rectWnd);
	rectWnd.left += SHIFTRIGHT;
	rectWnd.right += SHIFTRIGHT;
	ScreenToClient(rectWnd);
	pWnd->MoveWindow(rectWnd);

	pWnd = GetDlgItem(ID_APPLY_NOW);
	pWnd->GetWindowRect(rectWnd);
	rectWnd.left += SHIFTRIGHT;
	rectWnd.right += SHIFTRIGHT;
	ScreenToClient(rectWnd);
	pWnd->MoveWindow(rectWnd);

	
	pWnd = GetDlgItem(IDHELP);
	pWnd->GetWindowRect(rectWnd);
	rectWnd.left += SHIFTRIGHT;
	rectWnd.right += SHIFTRIGHT;
	ScreenToClient(rectWnd);
	pWnd->MoveWindow(rectWnd);
	pWnd->SetWindowText("About...");
	
	// Add "About..." menu item to system menu.
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	if (!strAboutMenu.IsEmpty())
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE); // Set big icon
	SetIcon(m_hIcon, FALSE); // Set small icon
	
	CenterWindow();
	return bResult;
}



void CVisionPropertySheet::OnSysCommand(UINT nID, LPARAM lParam) 
{
	// TODO: Add your message handler code here and/or call default
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CPropertySheetEx::OnSysCommand(nID, lParam);
	}
}


LRESULT CVisionPropertySheet::OnResizePage(WPARAM, LPARAM )
{
	// Resize the page using m_PageRect which was set in OnInit Dialog
	CPropertyPage* pPage = GetActivePage();
	ASSERT(pPage);
	pPage->MoveWindow(&m_PageRect);
	return 0;
}


BOOL CVisionPropertySheet::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	NMHDR* pnmh = (LPNMHDR) lParam;

	// the sheet resizes the page whenever it is activated
	// so we need to resize it to what we want
	if (TCN_SELCHANGE == pnmh->code)
		// user defined message needs to be posted because page must 
		// be resized after TCN_SELCHANGE has been processed
		PostMessage(WM_RESIZEPAGE);

	return CPropertySheetEx::OnNotify(wParam, lParam, pResult);
}


void CVisionPropertySheet::OnApplyNow()
{
	// the sheet resizes the page whenever the Apply button is clicked
	PostMessage(WM_RESIZEPAGE);

	// Change current settings
	m_wndPreview.SetDirectory(m_Page1.m_strDirectory);
	m_wndPreview.SetIncludeSubDirs(m_Page1.m_bIncludeSubDirs);
	m_wndPreview.SetPsuedoRandom(m_Page1.m_bPseudoRandom);

	m_wndPreview.SetSlideDuration(m_Page2.m_slidetime);
	m_wndPreview.SetShowName(m_Page2.m_bShowFilename);
	m_wndPreview.SetShowName(m_Page2.m_bShowFPS);

	m_wndPreview.SetWipeFXMode(m_Page3.m_nWipeFXMode);
	m_wndPreview.SetWipeDuration(m_Page3.m_nWipeTime);
	m_wndPreview.SetDefEffectTime(m_Page3.m_bUseDefTime);

	m_wndPreview.SetAllowVideo(m_Page4.m_bAllowVideo);
	m_wndPreview.SetMuteVAudio(m_Page4.m_bMuteVAudio);

	// Reset the Pages modified flag
	int nPageCount = GetPageCount();
	for (int nPage = 0; nPage < nPageCount; nPage++)
	{
		CPropertyPage* pPage = GetPage(nPage);
		pPage->SetModified(FALSE);
	}
}

void CVisionPropertySheet::OnHelpNow()
{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
}
