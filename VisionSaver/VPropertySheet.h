// VPropertySheet.h : header file
//
// This class defines custom modal property sheet 
// CVisionPropertySheet.
 // CVisionPropertySheet has been customized to include
// a preview window.
 
#ifndef __VPROPERTYSHEET_H__
#define __VPROPERTYSHEET_H__

#include "SourcePage1.h"
#include "VideoPage.h"
#include "EffectPropertyPage.h"
#include "MultiPage.h"
/////////////////////////////////////////////////////////////////////////////
// CVisionPropertySheet

class CVisionPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CVisionPropertySheet)

// Construction
public:
	CVisionPropertySheet(CWnd* pWndParent = NULL, HBITMAP hbmWatermark = NULL);

// Attributes
public:
	CSourcePage1 m_Page1;
	CSlidePropertyPage m_Page2;
	CEffectPropertyPage m_Page3;
	CVideoPage m_Page4;
	CMultiPage m_Page5;

	CDrawWnd m_wndPreview;
	CStatic	 m_wndImage;

	HICON m_hIcon;

	HANDLE hTransBitmap;
// Operations
public:
	BOOL	m_bNeedReset;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisionPropertySheet)
	protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVisionPropertySheet();
	virtual BOOL OnInitDialog();

// Generated message map functions
protected:
	RECT m_PageRect;
	//{{AFX_MSG(CVisionPropertySheet)
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	afx_msg LRESULT OnResizePage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnApplyNow();
	afx_msg void OnHelpNow();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif	// __VPROPERTYSHEET_H__
