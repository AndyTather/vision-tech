#if !defined(AFX_EFFECTPROPERTYPAGE_H__DBEFDBBA_C764_11D2_B015_000000000000__INCLUDED_)
#define AFX_EFFECTPROPERTYPAGE_H__DBEFDBBA_C764_11D2_B015_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EffectPropertyPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEffectPropertyPage dialog

class CEffectPropertyPage : public CPropertyPageEx
{
	DECLARE_DYNCREATE(CEffectPropertyPage)

// Construction
public:
	CEffectPropertyPage();
	~CEffectPropertyPage();

// Dialog Data
	//{{AFX_DATA(CEffectPropertyPage)
	enum { IDD = IDD_WIPEPAGE };
	CSliderCtrl	m_ctrlWipeTime;
	int		m_nWipeTime;
	BOOL	m_bUseDefTime;
	//}}AFX_DATA

	int	m_nWipeFXMode;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CEffectPropertyPage)
	public:
	virtual void OnOK();
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CEffectPropertyPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnWipeNone();
	afx_msg void OnWipeRandom();
	afx_msg void OnWipeSeq();
	afx_msg void OnReleasedcaptureWipeTime(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEffecttimedef();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EFFECTPROPERTYPAGE_H__DBEFDBBA_C764_11D2_B015_000000000000__INCLUDED_)
