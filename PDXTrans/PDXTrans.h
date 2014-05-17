

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Apr 25 14:54:53 2010
 */
/* Compiler settings for PDXTrans.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __PDXTrans_h__
#define __PDXTrans_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDXTPandaZoom_FWD_DEFINED__
#define __IDXTPandaZoom_FWD_DEFINED__
typedef interface IDXTPandaZoom IDXTPandaZoom;
#endif 	/* __IDXTPandaZoom_FWD_DEFINED__ */


#ifndef __PandaZoom_FWD_DEFINED__
#define __PandaZoom_FWD_DEFINED__

#ifdef __cplusplus
typedef class PandaZoom PandaZoom;
#else
typedef struct PandaZoom PandaZoom;
#endif /* __cplusplus */

#endif 	/* __PandaZoom_FWD_DEFINED__ */


#ifndef __PandaZoomPP_FWD_DEFINED__
#define __PandaZoomPP_FWD_DEFINED__

#ifdef __cplusplus
typedef class PandaZoomPP PandaZoomPP;
#else
typedef struct PandaZoomPP PandaZoomPP;
#endif /* __cplusplus */

#endif 	/* __PandaZoomPP_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "Dxtrans.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_PDXTrans_0000_0000 */
/* [local] */ 

typedef 
enum DXZOOMSTYLE
    {	DXZS_IN	= 0,
	DXZS_OUT	= ( DXZS_IN + 1 ) 
    } 	DXZOOMSTYLE;

typedef 
enum DXPANDAZOOMDISPID
    {	DISPID_DXZ_ZoomStyle	= DISPID_DXE_NEXT_ID,
	DISPID_DXZ_Copyright	= ( DISPID_DXZ_ZoomStyle + 1 ) 
    } 	DXPANDAZOOMDISPID;



extern RPC_IF_HANDLE __MIDL_itf_PDXTrans_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_PDXTrans_0000_0000_v0_0_s_ifspec;

#ifndef __IDXTPandaZoom_INTERFACE_DEFINED__
#define __IDXTPandaZoom_INTERFACE_DEFINED__

/* interface IDXTPandaZoom */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDXTPandaZoom;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A8C11F74-5007-4CE5-9A5E-84E2ABA9C860")
    IDXTPandaZoom : public IDXEffect
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ZoomStyle( 
            /* [retval][out] */ DXZOOMSTYLE *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ZoomStyle( 
            /* [in] */ DXZOOMSTYLE newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Copyright( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Copyright( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXTPandaZoomVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXTPandaZoom * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXTPandaZoom * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXTPandaZoom * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDXTPandaZoom * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDXTPandaZoom * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDXTPandaZoom * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDXTPandaZoom * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Capabilities )( 
            IDXTPandaZoom * This,
            /* [retval][out] */ long *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Progress )( 
            IDXTPandaZoom * This,
            /* [retval][out] */ float *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Progress )( 
            IDXTPandaZoom * This,
            /* [in] */ float newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StepResolution )( 
            IDXTPandaZoom * This,
            /* [retval][out] */ float *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Duration )( 
            IDXTPandaZoom * This,
            /* [retval][out] */ float *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Duration )( 
            IDXTPandaZoom * This,
            /* [in] */ float newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ZoomStyle )( 
            IDXTPandaZoom * This,
            /* [retval][out] */ DXZOOMSTYLE *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ZoomStyle )( 
            IDXTPandaZoom * This,
            /* [in] */ DXZOOMSTYLE newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            IDXTPandaZoom * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Copyright )( 
            IDXTPandaZoom * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IDXTPandaZoomVtbl;

    interface IDXTPandaZoom
    {
        CONST_VTBL struct IDXTPandaZoomVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXTPandaZoom_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXTPandaZoom_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXTPandaZoom_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXTPandaZoom_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDXTPandaZoom_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDXTPandaZoom_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDXTPandaZoom_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDXTPandaZoom_get_Capabilities(This,pVal)	\
    ( (This)->lpVtbl -> get_Capabilities(This,pVal) ) 

#define IDXTPandaZoom_get_Progress(This,pVal)	\
    ( (This)->lpVtbl -> get_Progress(This,pVal) ) 

#define IDXTPandaZoom_put_Progress(This,newVal)	\
    ( (This)->lpVtbl -> put_Progress(This,newVal) ) 

#define IDXTPandaZoom_get_StepResolution(This,pVal)	\
    ( (This)->lpVtbl -> get_StepResolution(This,pVal) ) 

#define IDXTPandaZoom_get_Duration(This,pVal)	\
    ( (This)->lpVtbl -> get_Duration(This,pVal) ) 

#define IDXTPandaZoom_put_Duration(This,newVal)	\
    ( (This)->lpVtbl -> put_Duration(This,newVal) ) 


#define IDXTPandaZoom_get_ZoomStyle(This,pVal)	\
    ( (This)->lpVtbl -> get_ZoomStyle(This,pVal) ) 

#define IDXTPandaZoom_put_ZoomStyle(This,newVal)	\
    ( (This)->lpVtbl -> put_ZoomStyle(This,newVal) ) 

#define IDXTPandaZoom_get_Copyright(This,pVal)	\
    ( (This)->lpVtbl -> get_Copyright(This,pVal) ) 

#define IDXTPandaZoom_put_Copyright(This,newVal)	\
    ( (This)->lpVtbl -> put_Copyright(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXTPandaZoom_INTERFACE_DEFINED__ */



#ifndef __PDXTRANSLib_LIBRARY_DEFINED__
#define __PDXTRANSLib_LIBRARY_DEFINED__

/* library PDXTRANSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_PDXTRANSLib;

EXTERN_C const CLSID CLSID_PandaZoom;

#ifdef __cplusplus

class DECLSPEC_UUID("0977FFA2-3591-41E6-A6B4-6C8171032649")
PandaZoom;
#endif

EXTERN_C const CLSID CLSID_PandaZoomPP;

#ifdef __cplusplus

class DECLSPEC_UUID("7AFECA03-E284-4ED7-AD05-BB763BBB1393")
PandaZoomPP;
#endif
#endif /* __PDXTRANSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


