#if !defined(AFX_VIDEOPAGE_H__F268D566_8C44_4E0D_938F_09841C2C7B51__INCLUDED_)
#define AFX_VIDEOPAGE_H__F268D566_8C44_4E0D_938F_09841C2C7B51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVideoPage dialog

class CVideoPage : public CPropertyPageEx
{
	DECLARE_DYNCREATE(CVideoPage)

// Construction
public:
	CVideoPage();
	~CVideoPage();

// Dialog Data
	//{{AFX_DATA(CVideoPage)
	enum { IDD = IDD_VIDEOPAGE };
	BOOL	m_bAllowVideo;
	BOOL	m_bMuteVAudio;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CVideoPage)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CVideoPage)
	afx_msg void OnAllowvideocheck();
	afx_msg void OnMutecheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOPAGE_H__F268D566_8C44_4E0D_938F_09841C2C7B51__INCLUDED_)
