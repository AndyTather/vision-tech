// VideoPage.cpp : implementation file
//

#include "stdafx.h"
#include "saver.h"
#include "VideoPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoPage property page

IMPLEMENT_DYNCREATE(CVideoPage, CPropertyPageEx)

CVideoPage::CVideoPage() : CPropertyPageEx(CVideoPage::IDD)
{
	//{{AFX_DATA_INIT(CVideoPage)
	m_bAllowVideo = AfxGetApp()->GetProfileInt(_T("Config"), _T("AllowVideo"), TRUE);
	m_bMuteVAudio = AfxGetApp()->GetProfileInt(_T("Config"), _T("MuteVAudio"), TRUE);
	//}}AFX_DATA_INIT
}

CVideoPage::~CVideoPage()
{
}

void CVideoPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPageEx::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVideoPage)
	DDX_Check(pDX, IDC_ALLOWVIDEOCHECK, m_bAllowVideo);
	DDX_Check(pDX, IDC_MUTECHECK, m_bMuteVAudio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVideoPage, CPropertyPageEx)
	//{{AFX_MSG_MAP(CVideoPage)
	ON_BN_CLICKED(IDC_ALLOWVIDEOCHECK, OnAllowvideocheck)
	ON_BN_CLICKED(IDC_MUTECHECK, OnMutecheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoPage message handlers

void CVideoPage::OnAllowvideocheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SetModified(TRUE);		
}

void CVideoPage::OnMutecheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SetModified(TRUE);		
}


void CVideoPage::OnOK() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CPropertyPageEx::OnOK();
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("AllowVideo"), m_bAllowVideo);
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("MuteVAudio"), m_bMuteVAudio);

}
