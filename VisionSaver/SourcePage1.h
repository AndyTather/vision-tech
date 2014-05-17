// SourcePage1.h : header file
//

#ifndef __SOURCEPAGE1_H__
#define __SOURCEPAGE1_H__

/////////////////////////////////////////////////////////////////////////////
// CSourcePage1 dialog

class CSourcePage1 : public CPropertyPageEx
{
	DECLARE_DYNCREATE(CSourcePage1)

// Construction
public:
	CSourcePage1();
	~CSourcePage1();

// Dialog Data
	//{{AFX_DATA(CSourcePage1)
	enum { IDD = IDD_MODEPAGE };
	CString	m_strDirectory;
	BOOL	m_bIncludeSubDirs;
	BOOL	m_bPseudoRandom;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSourcePage1)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	TCHAR m_szPath[MAX_PATH];

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSourcePage1)
	afx_msg void OnBrowseDir();
	virtual BOOL OnInitDialog();
	afx_msg void OnSubdirscheck();
	afx_msg void OnDefault();
	afx_msg void OnForce();
	afx_msg void OnPseudorandom();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CSlidePropertyPage dialog

class CSlidePropertyPage : public CPropertyPageEx
{
	DECLARE_DYNCREATE(CSlidePropertyPage)

// Construction
public:
	CSlidePropertyPage();
	~CSlidePropertyPage();

// Dialog Data
	//{{AFX_DATA(CSlidePropertyPage)
	enum { IDD = IDD_PROPPAGE2 };
	CSliderCtrl	m_slidectrl;
	int		m_slidetime;
	BOOL	m_bShowFilename;
	BOOL	m_bShowFPS;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSlidePropertyPage)
	public:
	virtual BOOL OnApply();
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSlidePropertyPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnReleasedcaptureSlidetime(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnShownamecheck();
	afx_msg void OnShowframerate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



#endif // __SOURCEPAGE1_H__
