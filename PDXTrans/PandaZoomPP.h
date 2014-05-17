	
// PandaZoomPP.h : Declaration of the CPandaZoomPP

#ifndef __PANDAZOOMPP_H_
#define __PANDAZOOMPP_H_

#include "resource.h"       // main symbols

EXTERN_C const CLSID CLSID_PandaZoomPP;

/////////////////////////////////////////////////////////////////////////////
// CPandaZoomPP
class ATL_NO_VTABLE CPandaZoomPP :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CPandaZoomPP, &CLSID_PandaZoomPP>,
	public IPropertyPageImpl<CPandaZoomPP>,
	public CDialogImpl<CPandaZoomPP>
{
public:
	CPandaZoomPP() 
	{
		m_pUnkMarshaler = NULL;
		m_dwTitleID = IDS_TITLEPandaZoomPP;
		m_dwHelpFileID = IDS_HELPFILEPandaZoomPP;
		m_dwDocStringID = IDS_DOCSTRINGPandaZoomPP;
	}

	enum {IDD = IDD_PANDAZOOMPP};

DECLARE_GET_CONTROLLING_UNKNOWN()
DECLARE_REGISTRY_RESOURCEID(IDR_PANDAZOOMPP)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPandaZoomPP) 
	COM_INTERFACE_ENTRY(IPropertyPage)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

BEGIN_MSG_MAP(CPandaZoomPP)
	CHAIN_MSG_MAP(IPropertyPageImpl<CPandaZoomPP>)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_HANDLER(IDC_ZOOM_STYLE, CBN_CLOSEUP, OnCloseupZoom_style)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}

	CComPtr<IUnknown> m_pUnkMarshaler;

	STDMETHOD(Apply)(void)
	{
		ATLTRACE(_T("CPandaZoomPP::Apply\n"));
		for (UINT i = 0; i < m_nObjects; i++)
		{
			CComQIPtr<IDXTPandaZoom, &IID_IDXTPandaZoom> cpZoom(m_ppUnk[i]);
			DXZOOMSTYLE ZoomStyle;
	        ZoomStyle = (DXZOOMSTYLE) 	SendDlgItemMessage( IDC_ZOOM_STYLE, CB_GETCURSEL, 0, 0L );
		    cpZoom->put_ZoomStyle( ZoomStyle );
		}
		m_bDirty = FALSE;
		return S_OK;
	}
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		CComQIPtr<IDXTPandaZoom, &IID_IDXTPandaZoom> cpZoom(m_ppUnk[0]);
	    
		//--- Init the combo box
		DXZOOMSTYLE ZoomStyle;
		cpZoom->get_ZoomStyle( &ZoomStyle );

		SendDlgItemMessage( IDC_ZOOM_STYLE, CB_ADDSTRING, 0, (LPARAM) (LPCSTR) "Zoom In" );
		SendDlgItemMessage( IDC_ZOOM_STYLE, CB_ADDSTRING, 0, (LPARAM) (LPCSTR) "Zoom Out" );
	
		SendDlgItemMessage( IDC_ZOOM_STYLE, CB_SETCURSEL, ZoomStyle,  0L );
	
		
		
		return 0;
	}

	LRESULT OnCloseupZoom_style(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		// TODO : Add Code for control notification handler.
		SetDirty(TRUE);
		return 0;
	}
};

#endif //__PANDAZOOMPP_H_
