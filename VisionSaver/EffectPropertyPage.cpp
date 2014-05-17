// EffectPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "saver.h"
#include "EffectPropertyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEffectPropertyPage property page

IMPLEMENT_DYNCREATE(CEffectPropertyPage, CPropertyPageEx)

CEffectPropertyPage::CEffectPropertyPage() : CPropertyPageEx(CEffectPropertyPage::IDD)
{
	//{{AFX_DATA_INIT(CEffectPropertyPage)
	m_nWipeTime = AfxGetApp()->GetProfileInt(_T("Config"), _T("WipeTime"), 1);
	m_bUseDefTime = AfxGetApp()->GetProfileInt(_T("Config"), _T("DefEffectTime"), TRUE);
	//}}AFX_DATA_INIT
	m_nWipeFXMode = AfxGetApp()->GetProfileInt(_T("Config"), _T("WipeFXMode"), 1);

}

CEffectPropertyPage::~CEffectPropertyPage()
{
}

void CEffectPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPageEx::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEffectPropertyPage)
	DDX_Control(pDX, IDC_WIPE_TIME, m_ctrlWipeTime);
	DDX_Slider(pDX, IDC_WIPE_TIME, m_nWipeTime);
	DDX_Check(pDX, IDC_EFFECTTIMEDEF, m_bUseDefTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEffectPropertyPage, CPropertyPageEx)
	//{{AFX_MSG_MAP(CEffectPropertyPage)
	ON_BN_CLICKED(IDC_WIPE_NONE, OnWipeNone)
	ON_BN_CLICKED(IDC_WIPE_RANDOM, OnWipeRandom)
	ON_BN_CLICKED(IDC_WIPE_SEQ, OnWipeSeq)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_WIPE_TIME, OnReleasedcaptureWipeTime)
	ON_BN_CLICKED(IDC_EFFECTTIMEDEF, OnEffecttimedef)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEffectPropertyPage message handlers

BOOL CEffectPropertyPage::OnInitDialog() 
{
	CPropertyPageEx::OnInitDialog();

	UpdateData(FALSE);
	
	// TODO: Add extra initialization here
	m_ctrlWipeTime.SetRange(1,5,TRUE);
	m_ctrlWipeTime.SetTic(m_nWipeTime);
	// Set Mode type 
	CheckRadioButton(IDC_WIPE_NONE, IDC_WIPE_RANDOM, IDC_WIPE_NONE + m_nWipeFXMode);
	
	if (m_bUseDefTime)
		m_ctrlWipeTime.EnableWindow(FALSE);
	else
		m_ctrlWipeTime.EnableWindow(TRUE);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEffectPropertyPage::OnOK() 
{
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("WipeFXMode"), m_nWipeFXMode);
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("WipeTime"), m_nWipeTime);
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("DefEffectTime"), m_bUseDefTime);
	
	CPropertyPageEx::OnOK();
}


BOOL CEffectPropertyPage::OnApply() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CPropertyPageEx::OnApply();
}

void CEffectPropertyPage::OnWipeNone() 
{
	// TODO: Add your control notification handler code here
	m_nWipeFXMode = 0;
	CheckRadioButton(IDC_WIPE_NONE, IDC_WIPE_RANDOM, IDC_WIPE_NONE + m_nWipeFXMode);
	SetModified(TRUE);	
}


void CEffectPropertyPage::OnWipeSeq() 
{
	// TODO: Add your control notification handler code here
	m_nWipeFXMode = 1;
	CheckRadioButton(IDC_WIPE_NONE, IDC_WIPE_RANDOM, IDC_WIPE_NONE + m_nWipeFXMode);
	SetModified(TRUE);	
}

void CEffectPropertyPage::OnWipeRandom() 
{
	// TODO: Add your control notification handler code here
	m_nWipeFXMode = 2;
	CheckRadioButton(IDC_WIPE_NONE, IDC_WIPE_RANDOM, IDC_WIPE_NONE + m_nWipeFXMode);
	SetModified(TRUE);	
}

void CEffectPropertyPage::OnReleasedcaptureWipeTime(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	SetModified(TRUE);	
	*pResult = 0;
}

void CEffectPropertyPage::OnEffecttimedef() 
{
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	SetModified(TRUE);	
	// TODO: Add your control notification handler code here
	if (m_bUseDefTime)
		m_ctrlWipeTime.EnableWindow(FALSE);
	else
		m_ctrlWipeTime.EnableWindow(TRUE);

}
