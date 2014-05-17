// MultiPage.cpp : implementation file
//

#include "stdafx.h"
#include "Saver.h"
#include "MultiPage.h"
#include ".\multipage.h"


// CMultiPage dialog

IMPLEMENT_DYNAMIC(CMultiPage, CPropertyPage)
CMultiPage::CMultiPage()
	: CPropertyPage(CMultiPage::IDD)
{
	m_nMultiMode = AfxGetApp()->GetProfileInt(_T("Config"), _T("MultiMonMode"), 0);
}

CMultiPage::~CMultiPage()
{
}

void CMultiPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMultiPage, CPropertyPage)
	ON_BN_CLICKED(IDC_MM_PRIMARY, OnBnClickedMmprimary)
	ON_BN_CLICKED(IDC_MM_VD, OnBnClickedMmVd)
	ON_BN_CLICKED(IDC_MM_CLONE, OnBnClickedMmClone)
	ON_BN_CLICKED(IDC_MM_INDIE, OnBnClickedMmIndie)
END_MESSAGE_MAP()

BOOL CMultiPage::OnInitDialog() 
{
	CPropertyPageEx::OnInitDialog();

	UpdateData(FALSE);
	
	// Set Mode type 
	CheckRadioButton(IDC_MM_PRIMARY, IDC_MM_INDIE, IDC_MM_PRIMARY + m_nMultiMode);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// CMultiPage message handlers

void CMultiPage::OnBnClickedMmprimary()
{
	// TODO: Add your control notification handler code here
	m_nMultiMode = 0;
	CheckRadioButton(IDC_MM_PRIMARY, IDC_MM_INDIE, IDC_MM_PRIMARY + m_nMultiMode);
	SetModified(TRUE);	
}

void CMultiPage::OnBnClickedMmVd()
{
	// TODO: Add your control notification handler code here
	m_nMultiMode = 1;
	CheckRadioButton(IDC_MM_PRIMARY, IDC_MM_INDIE, IDC_MM_PRIMARY + m_nMultiMode);
	SetModified(TRUE);	
}

void CMultiPage::OnBnClickedMmClone()
{
	// TODO: Add your control notification handler code here
	m_nMultiMode = 2;
	CheckRadioButton(IDC_MM_PRIMARY, IDC_MM_INDIE, IDC_MM_PRIMARY + m_nMultiMode);
	SetModified(TRUE);	
}

void CMultiPage::OnBnClickedMmIndie()
{
	// TODO: Add your control notification handler code here
	m_nMultiMode = 3;
	CheckRadioButton(IDC_MM_PRIMARY, IDC_MM_INDIE, IDC_MM_PRIMARY + m_nMultiMode);
	SetModified(TRUE);	
}

void CMultiPage::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	AfxGetApp()->WriteProfileInt(_T("Config"), _T("MultiMonMode"), m_nMultiMode);

	CPropertyPage::OnOK();
}
