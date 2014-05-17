	
// PandaZoom.h : Declaration of the CPandaZoom

#ifndef __PANDAZOOM_H_
#define __PANDAZOOM_H_

//--- Additional includes
#ifndef DTBase_h
#include <DTBase.h>
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPandaZoom
class ATL_NO_VTABLE CPandaZoom : 
	public CDXBaseNTo1,
	public CComCoClass<CPandaZoom, &CLSID_PandaZoom>,
	public IDispatchImpl<IDXTPandaZoom, &IID_IDXTPandaZoom, &LIBID_PDXTRANSLib>,
//	public CComPropertySupport<CPandaZoom>,
	public IObjectSafetyImpl2<CPandaZoom>,
	public IPersistStorageImpl<CPandaZoom>,
	public ISpecifyPropertyPagesImpl<CPandaZoom>,
	public IPersistPropertyBagImpl<CPandaZoom>
//	public IOleObjectDXImpl<CPandaZoom>
{
public:
	DECLARE_POLY_AGGREGATABLE(CPandaZoom)
	#if( _LICENSED_VERSION == 0 )
		DECLARE_REGISTER_DX_IMAGE_TRANS(IDR_PANDAZOOM)
	#else
		DECLARE_REGISTER_DX_IMAGE_AUTHOR_TRANS(IDR_PANDAZOOM)
	#endif



	CPandaZoom()
	{
		m_pUnkMarshaler = NULL;

	}

//DECLARE_REGISTER_DX_TRANSFORM(IDR_PANDAZOOM, CATID_DXImageTransform)
DECLARE_GET_CONTROLLING_UNKNOWN()


DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPandaZoom)
	COM_INTERFACE_ENTRY(IDXEffect)
	COM_INTERFACE_ENTRY(IDXTPandaZoom)
	COM_INTERFACE_ENTRY(IDispatch)
//	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
	COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafetyImpl2<CPandaZoom>)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IPersistPropertyBag)
	COM_INTERFACE_ENTRY_CHAIN(CDXBaseNTo1)
//	COM_INTERFACE_ENTRY_DXIMPL(IOleObject)
END_COM_MAP()

BEGIN_PROP_MAP( CPandaZoom )
//    PROP_ENTRY("Description", DISPID_MyProperty, CLSID_PandaZoomPP )
	PROP_ENTRY("Zoom Style", DISPID_DXZ_ZoomStyle, CLSID_PandaZoomPP)
    PROP_PAGE( CLSID_PandaZoomPP )
END_PROP_MAP()


	HRESULT FinalConstruct();

	void FinalRelease();

	IDXTransformFactory*    m_pTransFact;

	CComPtr<IUnknown> m_pUnkMarshaler;
    DXZOOMSTYLE m_eZoomStyle;
	BOOL        m_bCopyrightIsNotValid;
	BOOL        m_bRequiresSave;
	int			m_nNumInputs;
// IDXTPandaZoom
    //--- Base class overrides
    HRESULT WorkProc( const CDXTWorkInfoNTo1& WI, BOOL* pbContinue );
    HRESULT OnSetup( DWORD dwFlags );
	void ZoomOut(CDXDBnds bounds, CDXDBnds outbnd, IDXSurface* pInSurf);
	void ZoomIn(CDXDBnds bounds, CDXDBnds outbnd, IDXSurface* pInSurf);
public:
    //=== IDXEffect ======================================================
    DECLARE_IDXEFFECT_METHODS(DXTET_MORPH )   // 
    //=== IPersistPropertyBag ============================================
    // We don't persist unless we are the licensed version
#if( _LICENSED_VERSION == 0 )
    STDMETHOD( Save )( IPropertyBag* pPropBag, BOOL fClearDirty, BOOL fSaveAllProperties )
    {
        return E_FAIL;
    }
#endif
    STDMETHOD( get_ZoomStyle )( DXZOOMSTYLE *pVal );
    STDMETHOD( put_ZoomStyle )( DXZOOMSTYLE newVal );
    STDMETHOD( get_Copyright )( BSTR *pVal );
    STDMETHOD( put_Copyright )( BSTR newVal );


};

#endif //__PANDAZOOM_H_
