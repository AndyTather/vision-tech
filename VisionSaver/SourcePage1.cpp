// SourcePage1.cpp : implementation file
//

#include "stdafx.h"
#include "saver.h"
#include "resource.h"
#include "SourcePage1.h"
#include <shlobj.h>
#include "VPropertySheet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CSourcePage1, CPropertyPageEx)
IMPLEMENT_DYNCREATE(CSlidePropertyPage, CPropertyPageEx)


/////////////////////////////////////////////////////////////////////////////
// CSourcePage1 property page

CSourcePage1::CSourcePage1() : CPropertyPageEx(CSourcePage1::IDD)
{
	// Just in case get the 'My Pictures Directory'
	if (FAILED( SHGetFolderPath(NULL, CSIDL_MYPICTURES, NULL, SHGFP_TYPE_CURRENT, m_szPath)))
	{
		strcpy_s(m_szPath,"C:\\");
	}

	//{{AFX_DATA_INIT(CSourcePage1)
	m_strDirectory = AfxGetApp()->GetProfileString(_T("Config"), _T("Directory"), m_szPath);
	m_bIncludeSubDirs = AfxGetApp()->GetProfileInt(_T("Config"), _T("IncludeSubDirs"), TRUE);
	m_bPseudoRandom = AfxGetApp()->GetProfileInt(_T("Config"), _T("PseudoRandom"), FALSE);
	//}}AFX_DATA_INIT
}

CSourcePage1::~CSourcePage1()
{
}

void CSourcePage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPageEx::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSourcePage1)
	DDX_Text(pDX, IDC_DIRECTORY, m_strDirectory);
	DDX_Check(pDX, IDC_SUBDIRSCHECK, m_bIncludeSubDirs);
	DDX_Check(pDX, IDC_PSEUDORANDOM, m_bPseudoRandom);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSourcePage1, CPropertyPageEx)
	//{{AFX_MSG_MAP(CSourcePage1)
	ON_BN_CLICKED(IDC_BROWSE_DIR, OnBrowseDir)
	ON_BN_CLICKED(IDC_SUBDIRSCHECK, OnSubdirscheck)
	ON_BN_CLICKED(IDC_DEFAULT, OnDefault)
	ON_BN_CLICKED(IDC_FORCE, OnForce)
	ON_BN_CLICKED(IDC_PSEUDORANDOM, OnPseudorandom)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



int CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lp, LPARAM pData)
{
	TCHAR szDir[MAX_PATH];

	switch(uMsg)
	{
		case BFFM_INITIALIZED:
			{
				if (GetCurrentDirectory(sizeof(szDir)/sizeof(TCHAR), szDir))
					SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM) szDir);
			}
			break;

		case BFFM_SELCHANGED:
			{
				if (SHGetPathFromIDList((LPITEMIDLIST) lp, szDir))
					SendMessage(hwnd, BFFM_SETSTATUSTEXT, 0, (LPARAM) szDir);
			}
			break;

		default:
			break;
	}

	return 0;
}


void CSourcePage1::OnBrowseDir() 
{
	BROWSEINFO bi;
	TCHAR szDir[MAX_PATH];
	LPITEMIDLIST pidl;
	LPMALLOC pMalloc;

	if (SUCCEEDED(SHGetMalloc(&pMalloc)))
	{
		ZeroMemory(&bi, sizeof(bi));
		bi.hwndOwner = this->GetSafeHwnd(); // NULL;
		bi.pszDisplayName = 0;
		bi.pidlRoot = 0;
		bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT;
		bi.lpfn = BrowseCallbackProc;

		pidl = SHBrowseForFolder(&bi);
		if (pidl)
		{
			if (SHGetPathFromIDList(pidl, szDir))
				m_strDirectory = szDir;
			SetModified(TRUE);	
			pMalloc->Free(pidl);
			pMalloc->Release();
		}
	}
	UpdateData(FALSE);		
}

BOOL CSourcePage1::OnInitDialog() 
{
	CPropertyPageEx::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSourcePage1::OnOK() 
{
	CPropertyPageEx::OnOK();
	AfxGetApp()->WriteProfileString(_T("Config"), _T("Directory"), m_strDirectory);
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("IncludeSubDirs"), m_bIncludeSubDirs);
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("PseudoRandom"), m_bPseudoRandom);
}

void CSourcePage1::OnSubdirscheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	SetModified(TRUE);	
}

void CSourcePage1::OnPseudorandom() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	SetModified(TRUE);	
	
}

void CSourcePage1::OnDefault() 
{
	m_strDirectory = m_szPath;
	UpdateData(FALSE);
	SetModified(TRUE);		
}

void CSourcePage1::OnForce() 
{
	// TODO: Add your control notification handler code here
	CVisionPropertySheet* pVPS = (CVisionPropertySheet*) GetParent();
	pVPS->m_wndPreview.ForceNextSlide();
}


/////////////////////////////////////////////////////////////////////////////
// CSlidePropertyPage property page

CSlidePropertyPage::CSlidePropertyPage() : CPropertyPageEx(CSlidePropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CSlidePropertyPage)
	m_slidetime = AfxGetApp()->GetProfileInt(_T("Config"), _T("SlideTime"), 3);
	m_bShowFilename = AfxGetApp()->GetProfileInt(_T("Config"), _T("ShowFilename"), FALSE);
	m_bShowFPS = AfxGetApp()->GetProfileInt(_T("Config"), _T("ShowFPS"), FALSE);
	//}}AFX_DATA_INIT
}

CSlidePropertyPage::~CSlidePropertyPage()
{
}

void CSlidePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPageEx::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSlidePropertyPage)
	DDX_Control(pDX, IDC_SLIDETIME, m_slidectrl);
	DDX_Slider(pDX, IDC_SLIDETIME, m_slidetime);
	DDX_Check(pDX, IDC_SHOWNAMECHECK, m_bShowFilename);
	DDX_Check(pDX, IDC_SHOWFRAMERATE, m_bShowFPS);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSlidePropertyPage, CPropertyPageEx)
	//{{AFX_MSG_MAP(CSlidePropertyPage)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDETIME, OnReleasedcaptureSlidetime)
	ON_BN_CLICKED(IDC_SHOWNAMECHECK, OnShownamecheck)
	ON_BN_CLICKED(IDC_SHOWFRAMERATE, OnShowframerate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



BOOL CSlidePropertyPage::OnInitDialog() 
{
	CPropertyPageEx::OnInitDialog();

	UpdateData(FALSE);
	
	// TODO: Add extra initialization here
	m_slidectrl.SetRange(0,15,TRUE);
	m_slidectrl.SetTic(m_slidetime);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CSlidePropertyPage::OnApply() 
{
	// TODO: Add your specialized code here and/or call the base class
	return CPropertyPageEx::OnApply();
}

void CSlidePropertyPage::OnOK() 
{
	// TODO: Add your specialized code here and/or call the base class
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("SlideTime"), m_slidetime);
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("ShowFilename"), m_bShowFilename);
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("ShowFPS"), m_bShowFPS);
	
	CPropertyPageEx::OnOK();
}

void CSlidePropertyPage::OnReleasedcaptureSlidetime(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	SetModified(TRUE);
	*pResult = 0;
}

void CSlidePropertyPage::OnShownamecheck() 
{
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	SetModified(TRUE);
}










void CSlidePropertyPage::OnShowframerate() 
{
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	SetModified(TRUE);	
}
