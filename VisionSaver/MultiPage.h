#pragma once


// CMultiPage dialog

class CMultiPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CMultiPage)

public:
	CMultiPage();
	virtual ~CMultiPage();

// Dialog Data
	enum { IDD = IDD_MULTIMON };

	int m_nMultiMode;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedMmprimary();
	afx_msg void OnBnClickedMmVd();
	afx_msg void OnBnClickedMmClone();
	afx_msg void OnBnClickedMmIndie();
	virtual void OnOK();
};
