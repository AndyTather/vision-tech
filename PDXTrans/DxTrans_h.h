

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Apr 25 14:54:52 2010
 */
/* Compiler settings for DxTrans.Idl:
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

#ifndef __DxTrans_h_h__
#define __DxTrans_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDXBaseObject_FWD_DEFINED__
#define __IDXBaseObject_FWD_DEFINED__
typedef interface IDXBaseObject IDXBaseObject;
#endif 	/* __IDXBaseObject_FWD_DEFINED__ */


#ifndef __IDXTransformFactory_FWD_DEFINED__
#define __IDXTransformFactory_FWD_DEFINED__
typedef interface IDXTransformFactory IDXTransformFactory;
#endif 	/* __IDXTransformFactory_FWD_DEFINED__ */


#ifndef __IDXTransform_FWD_DEFINED__
#define __IDXTransform_FWD_DEFINED__
typedef interface IDXTransform IDXTransform;
#endif 	/* __IDXTransform_FWD_DEFINED__ */


#ifndef __IDXSurfacePick_FWD_DEFINED__
#define __IDXSurfacePick_FWD_DEFINED__
typedef interface IDXSurfacePick IDXSurfacePick;
#endif 	/* __IDXSurfacePick_FWD_DEFINED__ */


#ifndef __IDXTBindHost_FWD_DEFINED__
#define __IDXTBindHost_FWD_DEFINED__
typedef interface IDXTBindHost IDXTBindHost;
#endif 	/* __IDXTBindHost_FWD_DEFINED__ */


#ifndef __IDXTaskManager_FWD_DEFINED__
#define __IDXTaskManager_FWD_DEFINED__
typedef interface IDXTaskManager IDXTaskManager;
#endif 	/* __IDXTaskManager_FWD_DEFINED__ */


#ifndef __IDXSurfaceFactory_FWD_DEFINED__
#define __IDXSurfaceFactory_FWD_DEFINED__
typedef interface IDXSurfaceFactory IDXSurfaceFactory;
#endif 	/* __IDXSurfaceFactory_FWD_DEFINED__ */


#ifndef __IDXSurfaceModifier_FWD_DEFINED__
#define __IDXSurfaceModifier_FWD_DEFINED__
typedef interface IDXSurfaceModifier IDXSurfaceModifier;
#endif 	/* __IDXSurfaceModifier_FWD_DEFINED__ */


#ifndef __IDXSurface_FWD_DEFINED__
#define __IDXSurface_FWD_DEFINED__
typedef interface IDXSurface IDXSurface;
#endif 	/* __IDXSurface_FWD_DEFINED__ */


#ifndef __IDXSurfaceInit_FWD_DEFINED__
#define __IDXSurfaceInit_FWD_DEFINED__
typedef interface IDXSurfaceInit IDXSurfaceInit;
#endif 	/* __IDXSurfaceInit_FWD_DEFINED__ */


#ifndef __IDXARGBSurfaceInit_FWD_DEFINED__
#define __IDXARGBSurfaceInit_FWD_DEFINED__
typedef interface IDXARGBSurfaceInit IDXARGBSurfaceInit;
#endif 	/* __IDXARGBSurfaceInit_FWD_DEFINED__ */


#ifndef __IDXARGBReadPtr_FWD_DEFINED__
#define __IDXARGBReadPtr_FWD_DEFINED__
typedef interface IDXARGBReadPtr IDXARGBReadPtr;
#endif 	/* __IDXARGBReadPtr_FWD_DEFINED__ */


#ifndef __IDXARGBReadWritePtr_FWD_DEFINED__
#define __IDXARGBReadWritePtr_FWD_DEFINED__
typedef interface IDXARGBReadWritePtr IDXARGBReadWritePtr;
#endif 	/* __IDXARGBReadWritePtr_FWD_DEFINED__ */


#ifndef __IDXDCLock_FWD_DEFINED__
#define __IDXDCLock_FWD_DEFINED__
typedef interface IDXDCLock IDXDCLock;
#endif 	/* __IDXDCLock_FWD_DEFINED__ */


#ifndef __IDXTScaleOutput_FWD_DEFINED__
#define __IDXTScaleOutput_FWD_DEFINED__
typedef interface IDXTScaleOutput IDXTScaleOutput;
#endif 	/* __IDXTScaleOutput_FWD_DEFINED__ */


#ifndef __IDXGradient_FWD_DEFINED__
#define __IDXGradient_FWD_DEFINED__
typedef interface IDXGradient IDXGradient;
#endif 	/* __IDXGradient_FWD_DEFINED__ */


#ifndef __IDXGradient2_FWD_DEFINED__
#define __IDXGradient2_FWD_DEFINED__
typedef interface IDXGradient2 IDXGradient2;
#endif 	/* __IDXGradient2_FWD_DEFINED__ */


#ifndef __IDXTScale_FWD_DEFINED__
#define __IDXTScale_FWD_DEFINED__
typedef interface IDXTScale IDXTScale;
#endif 	/* __IDXTScale_FWD_DEFINED__ */


#ifndef __IDXTLabel_FWD_DEFINED__
#define __IDXTLabel_FWD_DEFINED__
typedef interface IDXTLabel IDXTLabel;
#endif 	/* __IDXTLabel_FWD_DEFINED__ */


#ifndef __IDXRasterizer_FWD_DEFINED__
#define __IDXRasterizer_FWD_DEFINED__
typedef interface IDXRasterizer IDXRasterizer;
#endif 	/* __IDXRasterizer_FWD_DEFINED__ */


#ifndef __IDXEffect_FWD_DEFINED__
#define __IDXEffect_FWD_DEFINED__
typedef interface IDXEffect IDXEffect;
#endif 	/* __IDXEffect_FWD_DEFINED__ */


#ifndef __IDXLookupTable_FWD_DEFINED__
#define __IDXLookupTable_FWD_DEFINED__
typedef interface IDXLookupTable IDXLookupTable;
#endif 	/* __IDXLookupTable_FWD_DEFINED__ */


#ifndef __IDX2DDebug_FWD_DEFINED__
#define __IDX2DDebug_FWD_DEFINED__
typedef interface IDX2DDebug IDX2DDebug;
#endif 	/* __IDX2DDebug_FWD_DEFINED__ */


#ifndef __IDX2D_FWD_DEFINED__
#define __IDX2D_FWD_DEFINED__
typedef interface IDX2D IDX2D;
#endif 	/* __IDX2D_FWD_DEFINED__ */


#ifndef __IDXRawSurface_FWD_DEFINED__
#define __IDXRawSurface_FWD_DEFINED__
typedef interface IDXRawSurface IDXRawSurface;
#endif 	/* __IDXRawSurface_FWD_DEFINED__ */


#ifndef __DXTransformFactory_FWD_DEFINED__
#define __DXTransformFactory_FWD_DEFINED__

#ifdef __cplusplus
typedef class DXTransformFactory DXTransformFactory;
#else
typedef struct DXTransformFactory DXTransformFactory;
#endif /* __cplusplus */

#endif 	/* __DXTransformFactory_FWD_DEFINED__ */


#ifndef __DXTaskManager_FWD_DEFINED__
#define __DXTaskManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class DXTaskManager DXTaskManager;
#else
typedef struct DXTaskManager DXTaskManager;
#endif /* __cplusplus */

#endif 	/* __DXTaskManager_FWD_DEFINED__ */


#ifndef __DXTScale_FWD_DEFINED__
#define __DXTScale_FWD_DEFINED__

#ifdef __cplusplus
typedef class DXTScale DXTScale;
#else
typedef struct DXTScale DXTScale;
#endif /* __cplusplus */

#endif 	/* __DXTScale_FWD_DEFINED__ */


#ifndef __DXTLabel_FWD_DEFINED__
#define __DXTLabel_FWD_DEFINED__

#ifdef __cplusplus
typedef class DXTLabel DXTLabel;
#else
typedef struct DXTLabel DXTLabel;
#endif /* __cplusplus */

#endif 	/* __DXTLabel_FWD_DEFINED__ */


#ifndef __DX2D_FWD_DEFINED__
#define __DX2D_FWD_DEFINED__

#ifdef __cplusplus
typedef class DX2D DX2D;
#else
typedef struct DX2D DX2D;
#endif /* __cplusplus */

#endif 	/* __DX2D_FWD_DEFINED__ */


#ifndef __DXSurface_FWD_DEFINED__
#define __DXSurface_FWD_DEFINED__

#ifdef __cplusplus
typedef class DXSurface DXSurface;
#else
typedef struct DXSurface DXSurface;
#endif /* __cplusplus */

#endif 	/* __DXSurface_FWD_DEFINED__ */


#ifndef __DXSurfaceModifier_FWD_DEFINED__
#define __DXSurfaceModifier_FWD_DEFINED__

#ifdef __cplusplus
typedef class DXSurfaceModifier DXSurfaceModifier;
#else
typedef struct DXSurfaceModifier DXSurfaceModifier;
#endif /* __cplusplus */

#endif 	/* __DXSurfaceModifier_FWD_DEFINED__ */


#ifndef __DXRasterizer_FWD_DEFINED__
#define __DXRasterizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class DXRasterizer DXRasterizer;
#else
typedef struct DXRasterizer DXRasterizer;
#endif /* __cplusplus */

#endif 	/* __DXRasterizer_FWD_DEFINED__ */


#ifndef __DXGradient_FWD_DEFINED__
#define __DXGradient_FWD_DEFINED__

#ifdef __cplusplus
typedef class DXGradient DXGradient;
#else
typedef struct DXGradient DXGradient;
#endif /* __cplusplus */

#endif 	/* __DXGradient_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "comcat.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_DxTrans_0000_0000 */
/* [local] */ 

#include <servprov.h>
#include <ddraw.h>
#include <d3d.h>
#include <d3drm.h>
#include <urlmon.h>
#if 0
// Bogus definition used to make MIDL compiler happy
typedef void DDSURFACEDESC;

typedef void D3DRMBOX;

typedef void D3DVECTOR;

typedef void D3DRMMATRIX4D;

typedef void *LPSECURITY_ATTRIBUTES;

#endif
#ifdef _DXTRANSIMPL
    #define _DXTRANS_IMPL_EXT _declspec(dllexport)
#else
    #define _DXTRANS_IMPL_EXT _declspec(dllimport)
#endif


















//
//   All GUIDs for DXTransforms are declared in DXTGUID.CPP in the SDK include directory
//
EXTERN_C const GUID DDPF_RGB1;
EXTERN_C const GUID DDPF_RGB2;
EXTERN_C const GUID DDPF_RGB4;
EXTERN_C const GUID DDPF_RGB8;
EXTERN_C const GUID DDPF_RGB332;
EXTERN_C const GUID DDPF_ARGB4444;
EXTERN_C const GUID DDPF_RGB565;
EXTERN_C const GUID DDPF_BGR565;
EXTERN_C const GUID DDPF_RGB555;
EXTERN_C const GUID DDPF_ARGB1555;
EXTERN_C const GUID DDPF_RGB24;
EXTERN_C const GUID DDPF_BGR24;
EXTERN_C const GUID DDPF_RGB32;
EXTERN_C const GUID DDPF_BGR32;
EXTERN_C const GUID DDPF_ABGR32;
EXTERN_C const GUID DDPF_ARGB32;
EXTERN_C const GUID DDPF_PMARGB32;
EXTERN_C const GUID DDPF_A1;
EXTERN_C const GUID DDPF_A2;
EXTERN_C const GUID DDPF_A4;
EXTERN_C const GUID DDPF_A8;
EXTERN_C const GUID DDPF_Z8;
EXTERN_C const GUID DDPF_Z16;
EXTERN_C const GUID DDPF_Z24;
EXTERN_C const GUID DDPF_Z32;
//
//   Component categories
//
EXTERN_C const GUID CATID_DXImageTransform;
EXTERN_C const GUID CATID_DX3DTransform;
EXTERN_C const GUID CATID_DXAuthoringTransform;
EXTERN_C const GUID CATID_DXSurface;
//
//   Service IDs
//
EXTERN_C const GUID SID_SDirectDraw;
EXTERN_C const GUID SID_SDirect3DRM;
#define SID_SDXTaskManager CLSID_DXTaskManager
#define SID_SDXSurfaceFactory IID_IDXSurfaceFactory


extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0000_v0_0_s_ifspec;

#ifndef __IDXBaseObject_INTERFACE_DEFINED__
#define __IDXBaseObject_INTERFACE_DEFINED__

/* interface IDXBaseObject */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXBaseObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17B59B2B-9CC8-11d1-9053-00C04FD9189D")
    IDXBaseObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetGenerationId( 
            /* [out] */ ULONG *pID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IncrementGenerationId( 
            /* [in] */ BOOL bRefresh) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectSize( 
            /* [out] */ ULONG *pcbSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXBaseObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXBaseObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXBaseObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXBaseObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetGenerationId )( 
            IDXBaseObject * This,
            /* [out] */ ULONG *pID);
        
        HRESULT ( STDMETHODCALLTYPE *IncrementGenerationId )( 
            IDXBaseObject * This,
            /* [in] */ BOOL bRefresh);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectSize )( 
            IDXBaseObject * This,
            /* [out] */ ULONG *pcbSize);
        
        END_INTERFACE
    } IDXBaseObjectVtbl;

    interface IDXBaseObject
    {
        CONST_VTBL struct IDXBaseObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXBaseObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXBaseObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXBaseObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXBaseObject_GetGenerationId(This,pID)	\
    ( (This)->lpVtbl -> GetGenerationId(This,pID) ) 

#define IDXBaseObject_IncrementGenerationId(This,bRefresh)	\
    ( (This)->lpVtbl -> IncrementGenerationId(This,bRefresh) ) 

#define IDXBaseObject_GetObjectSize(This,pcbSize)	\
    ( (This)->lpVtbl -> GetObjectSize(This,pcbSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXBaseObject_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0001 */
/* [local] */ 

typedef 
enum DXFILTERTYPE
    {	DXFILTER_NEAREST	= 0,
	DXFILTER_BILINEAR	= ( DXFILTER_NEAREST + 1 ) ,
	DXFILTER_CUBIC	= ( DXFILTER_BILINEAR + 1 ) ,
	DXFILTER_BSPLINE	= ( DXFILTER_CUBIC + 1 ) ,
	DXFILTER_NUM_FILTERS	= ( DXFILTER_BSPLINE + 1 ) 
    } 	DXFILTERTYPE;

typedef 
enum DX2DXFORMOPS
    {	DX2DXO_IDENTITY	= 0,
	DX2DXO_TRANSLATE	= ( DX2DXO_IDENTITY + 1 ) ,
	DX2DXO_SCALE	= ( DX2DXO_TRANSLATE + 1 ) ,
	DX2DXO_SCALE_AND_TRANS	= ( DX2DXO_SCALE + 1 ) ,
	DX2DXO_GENERAL	= ( DX2DXO_SCALE_AND_TRANS + 1 ) ,
	DX2DXO_GENERAL_AND_TRANS	= ( DX2DXO_GENERAL + 1 ) 
    } 	DX2DXFORMOPS;

typedef struct DX2DXFORM
    {
    FLOAT eM11;
    FLOAT eM12;
    FLOAT eM21;
    FLOAT eM22;
    FLOAT eDx;
    FLOAT eDy;
    DX2DXFORMOPS eOp;
    } 	DX2DXFORM;

typedef struct DX2DXFORM *PDX2DXFORM;

typedef 
enum DXBNDID
    {	DXB_X	= 0,
	DXB_Y	= 1,
	DXB_Z	= 2,
	DXB_T	= 3
    } 	DXBNDID;

typedef 
enum DXBNDTYPE
    {	DXBT_DISCRETE	= 0,
	DXBT_DISCRETE64	= ( DXBT_DISCRETE + 1 ) ,
	DXBT_CONTINUOUS	= ( DXBT_DISCRETE64 + 1 ) ,
	DXBT_CONTINUOUS64	= ( DXBT_CONTINUOUS + 1 ) 
    } 	DXBNDTYPE;

typedef struct DXDBND
    {
    long Min;
    long Max;
    } 	DXDBND;

typedef DXDBND DXDBNDS[ 4 ];

typedef struct DXDBND64
    {
    LONGLONG Min;
    LONGLONG Max;
    } 	DXDBND64;

typedef DXDBND64 DXDBNDS64[ 4 ];

typedef struct DXCBND
    {
    float Min;
    float Max;
    } 	DXCBND;

typedef DXCBND DXCBNDS[ 4 ];

typedef struct DXCBND64
    {
    double Min;
    double Max;
    } 	DXCBND64;

typedef DXCBND64 DXCBNDS64[ 4 ];

typedef struct DXBNDS
    {
    DXBNDTYPE eType;
    /* [switch_type] */ union __MIDL___MIDL_itf_DxTrans_0000_0001_0001
        {
        DXDBND D[ 4 ];
        DXDBND64 LD[ 4 ];
        DXCBND C[ 4 ];
        DXCBND64 LC[ 4 ];
        } 	u;
    } 	DXBNDS;

typedef long DXDVEC[ 4 ];

typedef LONGLONG DXDVEC64[ 4 ];

typedef float DXCVEC[ 4 ];

typedef double DXCVEC64[ 4 ];

typedef struct DXVEC
    {
    DXBNDTYPE eType;
    /* [switch_type] */ union __MIDL___MIDL_itf_DxTrans_0000_0001_0002
        {
        long D[ 4 ];
        LONGLONG LD[ 4 ];
        float C[ 4 ];
        double LC[ 4 ];
        } 	u;
    } 	DXVEC;



extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0001_v0_0_s_ifspec;

#ifndef __IDXTransformFactory_INTERFACE_DEFINED__
#define __IDXTransformFactory_INTERFACE_DEFINED__

/* interface IDXTransformFactory */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXTransformFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A950B2B-A971-11d1-81C8-0000F87557DB")
    IDXTransformFactory : public IServiceProvider
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetService( 
            /* [in] */ REFGUID guidService,
            /* [in] */ IUnknown *pUnkService,
            /* [in] */ BOOL bWeakReference) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTransform( 
            /* [size_is][in] */ IUnknown **punkInputs,
            /* [in] */ ULONG ulNumInputs,
            /* [size_is][in] */ IUnknown **punkOutputs,
            /* [in] */ ULONG ulNumOutputs,
            /* [in] */ IPropertyBag *pInitProps,
            /* [in] */ IErrorLog *pErrLog,
            /* [in] */ REFCLSID TransCLSID,
            /* [in] */ REFIID TransIID,
            /* [iid_is][out] */ void **ppTransform) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitializeTransform( 
            /* [in] */ IDXTransform *pTransform,
            /* [size_is][in] */ IUnknown **punkInputs,
            /* [in] */ ULONG ulNumInputs,
            /* [size_is][in] */ IUnknown **punkOutputs,
            /* [in] */ ULONG ulNumOutputs,
            /* [in] */ IPropertyBag *pInitProps,
            /* [in] */ IErrorLog *pErrLog) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXTransformFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXTransformFactory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXTransformFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXTransformFactory * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *QueryService )( 
            IDXTransformFactory * This,
            /* [annotation][in] */ 
            __in  REFGUID guidService,
            /* [annotation][in] */ 
            __in  REFIID riid,
            /* [annotation][out] */ 
            __deref_out  void **ppvObject);
        
        HRESULT ( STDMETHODCALLTYPE *SetService )( 
            IDXTransformFactory * This,
            /* [in] */ REFGUID guidService,
            /* [in] */ IUnknown *pUnkService,
            /* [in] */ BOOL bWeakReference);
        
        HRESULT ( STDMETHODCALLTYPE *CreateTransform )( 
            IDXTransformFactory * This,
            /* [size_is][in] */ IUnknown **punkInputs,
            /* [in] */ ULONG ulNumInputs,
            /* [size_is][in] */ IUnknown **punkOutputs,
            /* [in] */ ULONG ulNumOutputs,
            /* [in] */ IPropertyBag *pInitProps,
            /* [in] */ IErrorLog *pErrLog,
            /* [in] */ REFCLSID TransCLSID,
            /* [in] */ REFIID TransIID,
            /* [iid_is][out] */ void **ppTransform);
        
        HRESULT ( STDMETHODCALLTYPE *InitializeTransform )( 
            IDXTransformFactory * This,
            /* [in] */ IDXTransform *pTransform,
            /* [size_is][in] */ IUnknown **punkInputs,
            /* [in] */ ULONG ulNumInputs,
            /* [size_is][in] */ IUnknown **punkOutputs,
            /* [in] */ ULONG ulNumOutputs,
            /* [in] */ IPropertyBag *pInitProps,
            /* [in] */ IErrorLog *pErrLog);
        
        END_INTERFACE
    } IDXTransformFactoryVtbl;

    interface IDXTransformFactory
    {
        CONST_VTBL struct IDXTransformFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXTransformFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXTransformFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXTransformFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXTransformFactory_QueryService(This,guidService,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryService(This,guidService,riid,ppvObject) ) 


#define IDXTransformFactory_SetService(This,guidService,pUnkService,bWeakReference)	\
    ( (This)->lpVtbl -> SetService(This,guidService,pUnkService,bWeakReference) ) 

#define IDXTransformFactory_CreateTransform(This,punkInputs,ulNumInputs,punkOutputs,ulNumOutputs,pInitProps,pErrLog,TransCLSID,TransIID,ppTransform)	\
    ( (This)->lpVtbl -> CreateTransform(This,punkInputs,ulNumInputs,punkOutputs,ulNumOutputs,pInitProps,pErrLog,TransCLSID,TransIID,ppTransform) ) 

#define IDXTransformFactory_InitializeTransform(This,pTransform,punkInputs,ulNumInputs,punkOutputs,ulNumOutputs,pInitProps,pErrLog)	\
    ( (This)->lpVtbl -> InitializeTransform(This,pTransform,punkInputs,ulNumInputs,punkOutputs,ulNumOutputs,pInitProps,pErrLog) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXTransformFactory_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0002 */
/* [local] */ 

typedef 
enum DXTMISCFLAGS
    {	DXTMF_BLEND_WITH_OUTPUT	= ( 1L << 0 ) ,
	DXTMF_DITHER_OUTPUT	= ( 1L << 1 ) ,
	DXTMF_OPTION_MASK	= 0xffff,
	DXTMF_VALID_OPTIONS	= ( DXTMF_BLEND_WITH_OUTPUT | DXTMF_DITHER_OUTPUT ) ,
	DXTMF_BLEND_SUPPORTED	= ( 1L << 16 ) ,
	DXTMF_DITHER_SUPPORTED	= ( 1L << 17 ) ,
	DXTMF_INPLACE_OPERATION	= ( 1L << 24 ) ,
	DXTMF_BOUNDS_SUPPORTED	= ( 1L << 25 ) ,
	DXTMF_PLACEMENT_SUPPORTED	= ( 1L << 26 ) ,
	DXTMF_QUALITY_SUPPORTED	= ( 1L << 27 ) ,
	DXTMF_OPAQUE_RESULT	= ( 1L << 28 ) 
    } 	DXTMISCFLAGS;

typedef 
enum DXINOUTINFOFLAGS
    {	DXINOUTF_OPTIONAL	= ( 1L << 0 ) 
    } 	DXINOUTINFOFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0002_v0_0_s_ifspec;

#ifndef __IDXTransform_INTERFACE_DEFINED__
#define __IDXTransform_INTERFACE_DEFINED__

/* interface IDXTransform */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXTransform;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("30A5FB78-E11F-11d1-9064-00C04FD9189D")
    IDXTransform : public IDXBaseObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Setup( 
            /* [size_is][in] */ IUnknown *const *punkInputs,
            /* [in] */ ULONG ulNumInputs,
            /* [size_is][in] */ IUnknown *const *punkOutputs,
            /* [in] */ ULONG ulNumOutputs,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ const GUID *pRequestID,
            /* [in] */ const DXBNDS *pClipBnds,
            /* [in] */ const DXVEC *pPlacement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MapBoundsIn2Out( 
            /* [in] */ const DXBNDS *pInBounds,
            /* [in] */ ULONG ulNumInBnds,
            /* [in] */ ULONG ulOutIndex,
            /* [out] */ DXBNDS *pOutBounds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MapBoundsOut2In( 
            /* [in] */ ULONG ulOutIndex,
            /* [in] */ const DXBNDS *pOutBounds,
            /* [in] */ ULONG ulInIndex,
            /* [out] */ DXBNDS *pInBounds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMiscFlags( 
            /* [in] */ DWORD dwMiscFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMiscFlags( 
            /* [out] */ DWORD *pdwMiscFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInOutInfo( 
            /* [in] */ BOOL bIsOutput,
            /* [in] */ ULONG ulIndex,
            /* [out] */ DWORD *pdwFlags,
            /* [size_is][out] */ GUID *pIDs,
            /* [out][in] */ ULONG *pcIDs,
            /* [out] */ IUnknown **ppUnkCurrentObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetQuality( 
            /* [in] */ float fQuality) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetQuality( 
            /* [out] */ float *fQuality) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXTransformVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXTransform * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXTransform * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXTransform * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetGenerationId )( 
            IDXTransform * This,
            /* [out] */ ULONG *pID);
        
        HRESULT ( STDMETHODCALLTYPE *IncrementGenerationId )( 
            IDXTransform * This,
            /* [in] */ BOOL bRefresh);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectSize )( 
            IDXTransform * This,
            /* [out] */ ULONG *pcbSize);
        
        HRESULT ( STDMETHODCALLTYPE *Setup )( 
            IDXTransform * This,
            /* [size_is][in] */ IUnknown *const *punkInputs,
            /* [in] */ ULONG ulNumInputs,
            /* [size_is][in] */ IUnknown *const *punkOutputs,
            /* [in] */ ULONG ulNumOutputs,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IDXTransform * This,
            /* [in] */ const GUID *pRequestID,
            /* [in] */ const DXBNDS *pClipBnds,
            /* [in] */ const DXVEC *pPlacement);
        
        HRESULT ( STDMETHODCALLTYPE *MapBoundsIn2Out )( 
            IDXTransform * This,
            /* [in] */ const DXBNDS *pInBounds,
            /* [in] */ ULONG ulNumInBnds,
            /* [in] */ ULONG ulOutIndex,
            /* [out] */ DXBNDS *pOutBounds);
        
        HRESULT ( STDMETHODCALLTYPE *MapBoundsOut2In )( 
            IDXTransform * This,
            /* [in] */ ULONG ulOutIndex,
            /* [in] */ const DXBNDS *pOutBounds,
            /* [in] */ ULONG ulInIndex,
            /* [out] */ DXBNDS *pInBounds);
        
        HRESULT ( STDMETHODCALLTYPE *SetMiscFlags )( 
            IDXTransform * This,
            /* [in] */ DWORD dwMiscFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetMiscFlags )( 
            IDXTransform * This,
            /* [out] */ DWORD *pdwMiscFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetInOutInfo )( 
            IDXTransform * This,
            /* [in] */ BOOL bIsOutput,
            /* [in] */ ULONG ulIndex,
            /* [out] */ DWORD *pdwFlags,
            /* [size_is][out] */ GUID *pIDs,
            /* [out][in] */ ULONG *pcIDs,
            /* [out] */ IUnknown **ppUnkCurrentObject);
        
        HRESULT ( STDMETHODCALLTYPE *SetQuality )( 
            IDXTransform * This,
            /* [in] */ float fQuality);
        
        HRESULT ( STDMETHODCALLTYPE *GetQuality )( 
            IDXTransform * This,
            /* [out] */ float *fQuality);
        
        END_INTERFACE
    } IDXTransformVtbl;

    interface IDXTransform
    {
        CONST_VTBL struct IDXTransformVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXTransform_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXTransform_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXTransform_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXTransform_GetGenerationId(This,pID)	\
    ( (This)->lpVtbl -> GetGenerationId(This,pID) ) 

#define IDXTransform_IncrementGenerationId(This,bRefresh)	\
    ( (This)->lpVtbl -> IncrementGenerationId(This,bRefresh) ) 

#define IDXTransform_GetObjectSize(This,pcbSize)	\
    ( (This)->lpVtbl -> GetObjectSize(This,pcbSize) ) 


#define IDXTransform_Setup(This,punkInputs,ulNumInputs,punkOutputs,ulNumOutputs,dwFlags)	\
    ( (This)->lpVtbl -> Setup(This,punkInputs,ulNumInputs,punkOutputs,ulNumOutputs,dwFlags) ) 

#define IDXTransform_Execute(This,pRequestID,pClipBnds,pPlacement)	\
    ( (This)->lpVtbl -> Execute(This,pRequestID,pClipBnds,pPlacement) ) 

#define IDXTransform_MapBoundsIn2Out(This,pInBounds,ulNumInBnds,ulOutIndex,pOutBounds)	\
    ( (This)->lpVtbl -> MapBoundsIn2Out(This,pInBounds,ulNumInBnds,ulOutIndex,pOutBounds) ) 

#define IDXTransform_MapBoundsOut2In(This,ulOutIndex,pOutBounds,ulInIndex,pInBounds)	\
    ( (This)->lpVtbl -> MapBoundsOut2In(This,ulOutIndex,pOutBounds,ulInIndex,pInBounds) ) 

#define IDXTransform_SetMiscFlags(This,dwMiscFlags)	\
    ( (This)->lpVtbl -> SetMiscFlags(This,dwMiscFlags) ) 

#define IDXTransform_GetMiscFlags(This,pdwMiscFlags)	\
    ( (This)->lpVtbl -> GetMiscFlags(This,pdwMiscFlags) ) 

#define IDXTransform_GetInOutInfo(This,bIsOutput,ulIndex,pdwFlags,pIDs,pcIDs,ppUnkCurrentObject)	\
    ( (This)->lpVtbl -> GetInOutInfo(This,bIsOutput,ulIndex,pdwFlags,pIDs,pcIDs,ppUnkCurrentObject) ) 

#define IDXTransform_SetQuality(This,fQuality)	\
    ( (This)->lpVtbl -> SetQuality(This,fQuality) ) 

#define IDXTransform_GetQuality(This,fQuality)	\
    ( (This)->lpVtbl -> GetQuality(This,fQuality) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXTransform_INTERFACE_DEFINED__ */


#ifndef __IDXSurfacePick_INTERFACE_DEFINED__
#define __IDXSurfacePick_INTERFACE_DEFINED__

/* interface IDXSurfacePick */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXSurfacePick;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("30A5FB79-E11F-11d1-9064-00C04FD9189D")
    IDXSurfacePick : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PointPick( 
            /* [in] */ const DXVEC *pPoint,
            /* [out] */ ULONG *pulInputSurfaceIndex,
            /* [out] */ DXVEC *pInputPoint) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXSurfacePickVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXSurfacePick * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXSurfacePick * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXSurfacePick * This);
        
        HRESULT ( STDMETHODCALLTYPE *PointPick )( 
            IDXSurfacePick * This,
            /* [in] */ const DXVEC *pPoint,
            /* [out] */ ULONG *pulInputSurfaceIndex,
            /* [out] */ DXVEC *pInputPoint);
        
        END_INTERFACE
    } IDXSurfacePickVtbl;

    interface IDXSurfacePick
    {
        CONST_VTBL struct IDXSurfacePickVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXSurfacePick_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXSurfacePick_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXSurfacePick_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXSurfacePick_PointPick(This,pPoint,pulInputSurfaceIndex,pInputPoint)	\
    ( (This)->lpVtbl -> PointPick(This,pPoint,pulInputSurfaceIndex,pInputPoint) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXSurfacePick_INTERFACE_DEFINED__ */


#ifndef __IDXTBindHost_INTERFACE_DEFINED__
#define __IDXTBindHost_INTERFACE_DEFINED__

/* interface IDXTBindHost */
/* [object][local][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXTBindHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D26BCE55-E9DC-11d1-9066-00C04FD9189D")
    IDXTBindHost : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetBindHost( 
            /* [in] */ IBindHost *pBindHost) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXTBindHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXTBindHost * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXTBindHost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXTBindHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetBindHost )( 
            IDXTBindHost * This,
            /* [in] */ IBindHost *pBindHost);
        
        END_INTERFACE
    } IDXTBindHostVtbl;

    interface IDXTBindHost
    {
        CONST_VTBL struct IDXTBindHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXTBindHost_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXTBindHost_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXTBindHost_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXTBindHost_SetBindHost(This,pBindHost)	\
    ( (This)->lpVtbl -> SetBindHost(This,pBindHost) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXTBindHost_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0005 */
/* [local] */ 

typedef void __stdcall __stdcall DXTASKPROC( 
    void *pTaskData,
    BOOL *pbContinueProcessing);

typedef DXTASKPROC *PFNDXTASKPROC;

typedef void __stdcall __stdcall DXAPCPROC( 
    DWORD dwData);

typedef DXAPCPROC *PFNDXAPCPROC;

#ifdef __cplusplus
typedef struct DXTMTASKINFO
{
    PFNDXTASKPROC pfnTaskProc;       // Pointer to function to execute
    PVOID         pTaskData;         // Pointer to argument data
    PFNDXAPCPROC  pfnCompletionAPC;  // Pointer to completion APC proc
    DWORD         dwCompletionData;  // Pointer to APC proc data
    const GUID*   pRequestID;        // Used to identify groups of tasks
} DXTMTASKINFO;
#else
typedef struct DXTMTASKINFO
    {
    PVOID pfnTaskProc;
    PVOID pTaskData;
    PVOID pfnCompletionAPC;
    DWORD dwCompletionData;
    const GUID *pRequestID;
    } 	DXTMTASKINFO;

#endif


extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0005_v0_0_s_ifspec;

#ifndef __IDXTaskManager_INTERFACE_DEFINED__
#define __IDXTaskManager_INTERFACE_DEFINED__

/* interface IDXTaskManager */
/* [object][unique][helpstring][uuid][local] */ 


EXTERN_C const IID IID_IDXTaskManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("254DBBC1-F922-11d0-883A-3C8B00C10000")
    IDXTaskManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryNumProcessors( 
            /* [out] */ ULONG *pulNumProc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetThreadPoolSize( 
            /* [in] */ ULONG ulNumThreads) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetThreadPoolSize( 
            /* [out] */ ULONG *pulNumThreads) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConcurrencyLimit( 
            /* [in] */ ULONG ulNumThreads) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConcurrencyLimit( 
            /* [out] */ ULONG *pulNumThreads) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScheduleTasks( 
            /* [in] */ DXTMTASKINFO TaskInfo[  ],
            /* [in] */ HANDLE Events[  ],
            /* [out] */ DWORD TaskIDs[  ],
            /* [in] */ ULONG ulNumTasks,
            /* [in] */ ULONG ulWaitPeriod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateTasks( 
            /* [in] */ DWORD TaskIDs[  ],
            /* [in] */ ULONG ulCount,
            /* [in] */ ULONG ulTimeOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateRequest( 
            /* [in] */ REFIID RequestID,
            /* [in] */ ULONG ulTimeOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXTaskManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXTaskManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXTaskManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXTaskManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryNumProcessors )( 
            IDXTaskManager * This,
            /* [out] */ ULONG *pulNumProc);
        
        HRESULT ( STDMETHODCALLTYPE *SetThreadPoolSize )( 
            IDXTaskManager * This,
            /* [in] */ ULONG ulNumThreads);
        
        HRESULT ( STDMETHODCALLTYPE *GetThreadPoolSize )( 
            IDXTaskManager * This,
            /* [out] */ ULONG *pulNumThreads);
        
        HRESULT ( STDMETHODCALLTYPE *SetConcurrencyLimit )( 
            IDXTaskManager * This,
            /* [in] */ ULONG ulNumThreads);
        
        HRESULT ( STDMETHODCALLTYPE *GetConcurrencyLimit )( 
            IDXTaskManager * This,
            /* [out] */ ULONG *pulNumThreads);
        
        HRESULT ( STDMETHODCALLTYPE *ScheduleTasks )( 
            IDXTaskManager * This,
            /* [in] */ DXTMTASKINFO TaskInfo[  ],
            /* [in] */ HANDLE Events[  ],
            /* [out] */ DWORD TaskIDs[  ],
            /* [in] */ ULONG ulNumTasks,
            /* [in] */ ULONG ulWaitPeriod);
        
        HRESULT ( STDMETHODCALLTYPE *TerminateTasks )( 
            IDXTaskManager * This,
            /* [in] */ DWORD TaskIDs[  ],
            /* [in] */ ULONG ulCount,
            /* [in] */ ULONG ulTimeOut);
        
        HRESULT ( STDMETHODCALLTYPE *TerminateRequest )( 
            IDXTaskManager * This,
            /* [in] */ REFIID RequestID,
            /* [in] */ ULONG ulTimeOut);
        
        END_INTERFACE
    } IDXTaskManagerVtbl;

    interface IDXTaskManager
    {
        CONST_VTBL struct IDXTaskManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXTaskManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXTaskManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXTaskManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXTaskManager_QueryNumProcessors(This,pulNumProc)	\
    ( (This)->lpVtbl -> QueryNumProcessors(This,pulNumProc) ) 

#define IDXTaskManager_SetThreadPoolSize(This,ulNumThreads)	\
    ( (This)->lpVtbl -> SetThreadPoolSize(This,ulNumThreads) ) 

#define IDXTaskManager_GetThreadPoolSize(This,pulNumThreads)	\
    ( (This)->lpVtbl -> GetThreadPoolSize(This,pulNumThreads) ) 

#define IDXTaskManager_SetConcurrencyLimit(This,ulNumThreads)	\
    ( (This)->lpVtbl -> SetConcurrencyLimit(This,ulNumThreads) ) 

#define IDXTaskManager_GetConcurrencyLimit(This,pulNumThreads)	\
    ( (This)->lpVtbl -> GetConcurrencyLimit(This,pulNumThreads) ) 

#define IDXTaskManager_ScheduleTasks(This,TaskInfo,Events,TaskIDs,ulNumTasks,ulWaitPeriod)	\
    ( (This)->lpVtbl -> ScheduleTasks(This,TaskInfo,Events,TaskIDs,ulNumTasks,ulWaitPeriod) ) 

#define IDXTaskManager_TerminateTasks(This,TaskIDs,ulCount,ulTimeOut)	\
    ( (This)->lpVtbl -> TerminateTasks(This,TaskIDs,ulCount,ulTimeOut) ) 

#define IDXTaskManager_TerminateRequest(This,RequestID,ulTimeOut)	\
    ( (This)->lpVtbl -> TerminateRequest(This,RequestID,ulTimeOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXTaskManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0006 */
/* [local] */ 

#ifdef __cplusplus
/////////////////////////////////////////////////////

class DXBASESAMPLE;
class DXSAMPLE;
class DXPMSAMPLE;

/////////////////////////////////////////////////////

class DXBASESAMPLE
{
public:
    BYTE Blue;
    BYTE Green;
    BYTE Red;
    BYTE Alpha;
    DXBASESAMPLE() {}
    DXBASESAMPLE(const BYTE alpha, const BYTE red, const BYTE green, const BYTE blue) :
        Alpha(alpha),
        Red(red),
        Green(green),
        Blue(blue) {}
    DXBASESAMPLE(const DWORD val) { *this = (*(DXBASESAMPLE *)&val); }
    operator DWORD () const {return *((DWORD *)this); }
    DWORD operator=(const DWORD val) { return *this = *((DXBASESAMPLE *)&val); }
}; // DXBASESAMPLE

/////////////////////////////////////////////////////

class DXSAMPLE : public DXBASESAMPLE
{
public:
    DXSAMPLE() {}
    DXSAMPLE(const BYTE alpha, const BYTE red, const BYTE green, const BYTE blue) :
         DXBASESAMPLE(alpha, red, green, blue) {}
    DXSAMPLE(const DWORD val) { *this = (*(DXSAMPLE *)&val); }
    operator DWORD () const {return *((DWORD *)this); }
    DWORD operator=(const DWORD val) { return *this = *((DXSAMPLE *)&val); }
    operator DXPMSAMPLE() const;
}; // DXSAMPLE

/////////////////////////////////////////////////////

class DXPMSAMPLE : public DXBASESAMPLE
{
public:
    DXPMSAMPLE() {}
    DXPMSAMPLE(const BYTE alpha, const BYTE red, const BYTE green, const BYTE blue) :
         DXBASESAMPLE(alpha, red, green, blue) {}
    DXPMSAMPLE(const DWORD val) { *this = (*(DXPMSAMPLE *)&val); }
    operator DWORD () const {return *((DWORD *)this); }
    DWORD operator=(const DWORD val) { return *this = *((DXPMSAMPLE *)&val); }
    operator DXSAMPLE() const;
}; // DXPMSAMPLE

//
// The following cast operators are to prevent a direct assignment of a DXSAMPLE to a DXPMSAMPLE
//
inline DXSAMPLE::operator DXPMSAMPLE() const { return *((DXPMSAMPLE *)this); }
inline DXPMSAMPLE::operator DXSAMPLE() const { return *((DXSAMPLE *)this); }
#else // !__cplusplus
typedef struct DXBASESAMPLE
    {
    BYTE Blue;
    BYTE Green;
    BYTE Red;
    BYTE Alpha;
    } 	DXBASESAMPLE;

typedef struct DXSAMPLE
    {
    BYTE Blue;
    BYTE Green;
    BYTE Red;
    BYTE Alpha;
    } 	DXSAMPLE;

typedef struct DXPMSAMPLE
    {
    BYTE Blue;
    BYTE Green;
    BYTE Red;
    BYTE Alpha;
    } 	DXPMSAMPLE;

#endif // !__cplusplus
typedef 
enum DXRUNTYPE
    {	DXRUNTYPE_CLEAR	= 0,
	DXRUNTYPE_OPAQUE	= 1,
	DXRUNTYPE_TRANS	= 2,
	DXRUNTYPE_UNKNOWN	= 3
    } 	DXRUNTYPE;

#define	DX_MAX_RUN_INFO_COUNT	( 128 )

// Ignore the definition used by MIDL for TLB generation
#if 0
typedef struct DXRUNINFO
    {
    ULONG Bitfields;
    } 	DXRUNINFO;

#endif // 0
typedef struct DXRUNINFO
{
    ULONG   Type  : 2;   // Type
    ULONG   Count : 30;  // Number of samples in run
} DXRUNINFO;
typedef 
enum DXSFCREATE
    {	DXSF_FORMAT_IS_CLSID	= ( 1L << 0 ) ,
	DXSF_NO_LAZY_DDRAW_LOCK	= ( 1L << 1 ) 
    } 	DXSFCREATE;

typedef 
enum DXBLTOPTIONS
    {	DXBOF_DO_OVER	= ( 1L << 0 ) ,
	DXBOF_DITHER	= ( 1L << 1 ) 
    } 	DXBLTOPTIONS;



extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0006_v0_0_s_ifspec;

#ifndef __IDXSurfaceFactory_INTERFACE_DEFINED__
#define __IDXSurfaceFactory_INTERFACE_DEFINED__

/* interface IDXSurfaceFactory */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXSurfaceFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("144946F5-C4D4-11d1-81D1-0000F87557DB")
    IDXSurfaceFactory : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateSurface( 
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ const DXBNDS *pBounds,
            /* [in] */ DWORD dwFlags,
            /* [in] */ IUnknown *punkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDXSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateFromDDSurface( 
            /* [in] */ IUnknown *pDDrawSurface,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ DWORD dwFlags,
            /* [in] */ IUnknown *punkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDXSurface) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE LoadImage( 
            /* [in] */ const LPWSTR pszFileName,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDXSurface) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE LoadImageFromStream( 
            /* [in] */ IStream *pStream,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDXSurface) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CopySurfaceToNewFormat( 
            /* [in] */ IDXSurface *pSrc,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pDestFormatID,
            /* [out] */ IDXSurface **ppNewSurface) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateD3DRMTexture( 
            /* [in] */ IDXSurface *pSrc,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ IUnknown *pD3DRM3,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppTexture3) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BitBlt( 
            /* [in] */ IDXSurface *pDest,
            /* [in] */ const DXVEC *pPlacement,
            /* [in] */ IDXSurface *pSrc,
            /* [in] */ const DXBNDS *pClipBounds,
            /* [in] */ DWORD dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXSurfaceFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXSurfaceFactory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXSurfaceFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXSurfaceFactory * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CreateSurface )( 
            IDXSurfaceFactory * This,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ const DXBNDS *pBounds,
            /* [in] */ DWORD dwFlags,
            /* [in] */ IUnknown *punkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDXSurface);
        
        HRESULT ( STDMETHODCALLTYPE *CreateFromDDSurface )( 
            IDXSurfaceFactory * This,
            /* [in] */ IUnknown *pDDrawSurface,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ DWORD dwFlags,
            /* [in] */ IUnknown *punkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDXSurface);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *LoadImage )( 
            IDXSurfaceFactory * This,
            /* [in] */ const LPWSTR pszFileName,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDXSurface);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *LoadImageFromStream )( 
            IDXSurfaceFactory * This,
            /* [in] */ IStream *pStream,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDXSurface);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopySurfaceToNewFormat )( 
            IDXSurfaceFactory * This,
            /* [in] */ IDXSurface *pSrc,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pDestFormatID,
            /* [out] */ IDXSurface **ppNewSurface);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CreateD3DRMTexture )( 
            IDXSurfaceFactory * This,
            /* [in] */ IDXSurface *pSrc,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ IUnknown *pD3DRM3,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppTexture3);
        
        HRESULT ( STDMETHODCALLTYPE *BitBlt )( 
            IDXSurfaceFactory * This,
            /* [in] */ IDXSurface *pDest,
            /* [in] */ const DXVEC *pPlacement,
            /* [in] */ IDXSurface *pSrc,
            /* [in] */ const DXBNDS *pClipBounds,
            /* [in] */ DWORD dwFlags);
        
        END_INTERFACE
    } IDXSurfaceFactoryVtbl;

    interface IDXSurfaceFactory
    {
        CONST_VTBL struct IDXSurfaceFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXSurfaceFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXSurfaceFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXSurfaceFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXSurfaceFactory_CreateSurface(This,pDirectDraw,pDDSurfaceDesc,pFormatID,pBounds,dwFlags,punkOuter,riid,ppDXSurface)	\
    ( (This)->lpVtbl -> CreateSurface(This,pDirectDraw,pDDSurfaceDesc,pFormatID,pBounds,dwFlags,punkOuter,riid,ppDXSurface) ) 

#define IDXSurfaceFactory_CreateFromDDSurface(This,pDDrawSurface,pFormatID,dwFlags,punkOuter,riid,ppDXSurface)	\
    ( (This)->lpVtbl -> CreateFromDDSurface(This,pDDrawSurface,pFormatID,dwFlags,punkOuter,riid,ppDXSurface) ) 

#define IDXSurfaceFactory_LoadImage(This,pszFileName,pDirectDraw,pDDSurfaceDesc,pFormatID,riid,ppDXSurface)	\
    ( (This)->lpVtbl -> LoadImage(This,pszFileName,pDirectDraw,pDDSurfaceDesc,pFormatID,riid,ppDXSurface) ) 

#define IDXSurfaceFactory_LoadImageFromStream(This,pStream,pDirectDraw,pDDSurfaceDesc,pFormatID,riid,ppDXSurface)	\
    ( (This)->lpVtbl -> LoadImageFromStream(This,pStream,pDirectDraw,pDDSurfaceDesc,pFormatID,riid,ppDXSurface) ) 

#define IDXSurfaceFactory_CopySurfaceToNewFormat(This,pSrc,pDirectDraw,pDDSurfaceDesc,pDestFormatID,ppNewSurface)	\
    ( (This)->lpVtbl -> CopySurfaceToNewFormat(This,pSrc,pDirectDraw,pDDSurfaceDesc,pDestFormatID,ppNewSurface) ) 

#define IDXSurfaceFactory_CreateD3DRMTexture(This,pSrc,pDirectDraw,pD3DRM3,riid,ppTexture3)	\
    ( (This)->lpVtbl -> CreateD3DRMTexture(This,pSrc,pDirectDraw,pD3DRM3,riid,ppTexture3) ) 

#define IDXSurfaceFactory_BitBlt(This,pDest,pPlacement,pSrc,pClipBounds,dwFlags)	\
    ( (This)->lpVtbl -> BitBlt(This,pDest,pPlacement,pSrc,pClipBounds,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXSurfaceFactory_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0007 */
/* [local] */ 

typedef 
enum DXSURFMODCOMPOP
    {	DXSURFMOD_COMP_OVER	= 0,
	DXSURFMOD_COMP_ALPHA_MASK	= 1,
	DXSURFMOD_COMP_MAX_VALID	= 1
    } 	DXSURFMODCOMPOP;



extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0007_v0_0_s_ifspec;

#ifndef __IDXSurfaceModifier_INTERFACE_DEFINED__
#define __IDXSurfaceModifier_INTERFACE_DEFINED__

/* interface IDXSurfaceModifier */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXSurfaceModifier;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9EA3B637-C37D-11d1-905E-00C04FD9189D")
    IDXSurfaceModifier : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFillColor( 
            /* [in] */ DXSAMPLE Color) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFillColor( 
            /* [out] */ DXSAMPLE *pColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBounds( 
            /* [in] */ const DXBNDS *pBounds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBackground( 
            /* [in] */ IDXSurface *pSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBackground( 
            /* [out] */ IDXSurface **ppSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositeOperation( 
            /* [in] */ DXSURFMODCOMPOP CompOp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositeOperation( 
            /* [out] */ DXSURFMODCOMPOP *pCompOp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetForeground( 
            /* [in] */ IDXSurface *pSurface,
            /* [in] */ BOOL bTile,
            /* [in] */ const POINT *pOrigin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetForeground( 
            /* [out] */ IDXSurface **ppSurface,
            /* [out] */ BOOL *pbTile,
            /* [out] */ POINT *pOrigin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOpacity( 
            /* [in] */ float Opacity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOpacity( 
            /* [out] */ float *pOpacity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLookup( 
            /* [in] */ IDXLookupTable *pLookupTable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLookup( 
            /* [out] */ IDXLookupTable **ppLookupTable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXSurfaceModifierVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXSurfaceModifier * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXSurfaceModifier * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXSurfaceModifier * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFillColor )( 
            IDXSurfaceModifier * This,
            /* [in] */ DXSAMPLE Color);
        
        HRESULT ( STDMETHODCALLTYPE *GetFillColor )( 
            IDXSurfaceModifier * This,
            /* [out] */ DXSAMPLE *pColor);
        
        HRESULT ( STDMETHODCALLTYPE *SetBounds )( 
            IDXSurfaceModifier * This,
            /* [in] */ const DXBNDS *pBounds);
        
        HRESULT ( STDMETHODCALLTYPE *SetBackground )( 
            IDXSurfaceModifier * This,
            /* [in] */ IDXSurface *pSurface);
        
        HRESULT ( STDMETHODCALLTYPE *GetBackground )( 
            IDXSurfaceModifier * This,
            /* [out] */ IDXSurface **ppSurface);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositeOperation )( 
            IDXSurfaceModifier * This,
            /* [in] */ DXSURFMODCOMPOP CompOp);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositeOperation )( 
            IDXSurfaceModifier * This,
            /* [out] */ DXSURFMODCOMPOP *pCompOp);
        
        HRESULT ( STDMETHODCALLTYPE *SetForeground )( 
            IDXSurfaceModifier * This,
            /* [in] */ IDXSurface *pSurface,
            /* [in] */ BOOL bTile,
            /* [in] */ const POINT *pOrigin);
        
        HRESULT ( STDMETHODCALLTYPE *GetForeground )( 
            IDXSurfaceModifier * This,
            /* [out] */ IDXSurface **ppSurface,
            /* [out] */ BOOL *pbTile,
            /* [out] */ POINT *pOrigin);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpacity )( 
            IDXSurfaceModifier * This,
            /* [in] */ float Opacity);
        
        HRESULT ( STDMETHODCALLTYPE *GetOpacity )( 
            IDXSurfaceModifier * This,
            /* [out] */ float *pOpacity);
        
        HRESULT ( STDMETHODCALLTYPE *SetLookup )( 
            IDXSurfaceModifier * This,
            /* [in] */ IDXLookupTable *pLookupTable);
        
        HRESULT ( STDMETHODCALLTYPE *GetLookup )( 
            IDXSurfaceModifier * This,
            /* [out] */ IDXLookupTable **ppLookupTable);
        
        END_INTERFACE
    } IDXSurfaceModifierVtbl;

    interface IDXSurfaceModifier
    {
        CONST_VTBL struct IDXSurfaceModifierVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXSurfaceModifier_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXSurfaceModifier_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXSurfaceModifier_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXSurfaceModifier_SetFillColor(This,Color)	\
    ( (This)->lpVtbl -> SetFillColor(This,Color) ) 

#define IDXSurfaceModifier_GetFillColor(This,pColor)	\
    ( (This)->lpVtbl -> GetFillColor(This,pColor) ) 

#define IDXSurfaceModifier_SetBounds(This,pBounds)	\
    ( (This)->lpVtbl -> SetBounds(This,pBounds) ) 

#define IDXSurfaceModifier_SetBackground(This,pSurface)	\
    ( (This)->lpVtbl -> SetBackground(This,pSurface) ) 

#define IDXSurfaceModifier_GetBackground(This,ppSurface)	\
    ( (This)->lpVtbl -> GetBackground(This,ppSurface) ) 

#define IDXSurfaceModifier_SetCompositeOperation(This,CompOp)	\
    ( (This)->lpVtbl -> SetCompositeOperation(This,CompOp) ) 

#define IDXSurfaceModifier_GetCompositeOperation(This,pCompOp)	\
    ( (This)->lpVtbl -> GetCompositeOperation(This,pCompOp) ) 

#define IDXSurfaceModifier_SetForeground(This,pSurface,bTile,pOrigin)	\
    ( (This)->lpVtbl -> SetForeground(This,pSurface,bTile,pOrigin) ) 

#define IDXSurfaceModifier_GetForeground(This,ppSurface,pbTile,pOrigin)	\
    ( (This)->lpVtbl -> GetForeground(This,ppSurface,pbTile,pOrigin) ) 

#define IDXSurfaceModifier_SetOpacity(This,Opacity)	\
    ( (This)->lpVtbl -> SetOpacity(This,Opacity) ) 

#define IDXSurfaceModifier_GetOpacity(This,pOpacity)	\
    ( (This)->lpVtbl -> GetOpacity(This,pOpacity) ) 

#define IDXSurfaceModifier_SetLookup(This,pLookupTable)	\
    ( (This)->lpVtbl -> SetLookup(This,pLookupTable) ) 

#define IDXSurfaceModifier_GetLookup(This,ppLookupTable)	\
    ( (This)->lpVtbl -> GetLookup(This,ppLookupTable) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXSurfaceModifier_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0008 */
/* [local] */ 

typedef 
enum DXSAMPLEFORMATENUM
    {	DXPF_FLAGSMASK	= 0xffff0000,
	DXPF_NONPREMULT	= 0x10000,
	DXPF_TRANSPARENCY	= 0x20000,
	DXPF_TRANSLUCENCY	= 0x40000,
	DXPF_2BITERROR	= 0x200000,
	DXPF_3BITERROR	= 0x300000,
	DXPF_4BITERROR	= 0x400000,
	DXPF_5BITERROR	= 0x500000,
	DXPF_ERRORMASK	= 0x700000,
	DXPF_NONSTANDARD	= 0,
	DXPF_PMARGB32	= ( ( 1 | DXPF_TRANSPARENCY )  | DXPF_TRANSLUCENCY ) ,
	DXPF_ARGB32	= ( ( ( 2 | DXPF_NONPREMULT )  | DXPF_TRANSPARENCY )  | DXPF_TRANSLUCENCY ) ,
	DXPF_ARGB4444	= ( ( ( ( 3 | DXPF_NONPREMULT )  | DXPF_TRANSPARENCY )  | DXPF_TRANSLUCENCY )  | DXPF_4BITERROR ) ,
	DXPF_A8	= ( ( 4 | DXPF_TRANSPARENCY )  | DXPF_TRANSLUCENCY ) ,
	DXPF_RGB32	= 5,
	DXPF_RGB24	= 6,
	DXPF_RGB565	= ( 7 | DXPF_3BITERROR ) ,
	DXPF_RGB555	= ( 8 | DXPF_3BITERROR ) ,
	DXPF_RGB8	= ( 9 | DXPF_5BITERROR ) ,
	DXPF_ARGB1555	= ( ( 10 | DXPF_TRANSPARENCY )  | DXPF_3BITERROR ) ,
	DXPF_RGB32_CK	= ( DXPF_RGB32 | DXPF_TRANSPARENCY ) ,
	DXPF_RGB24_CK	= ( DXPF_RGB24 | DXPF_TRANSPARENCY ) ,
	DXPF_RGB555_CK	= ( DXPF_RGB555 | DXPF_TRANSPARENCY ) ,
	DXPF_RGB565_CK	= ( DXPF_RGB565 | DXPF_TRANSPARENCY ) ,
	DXPF_RGB8_CK	= ( DXPF_RGB8 | DXPF_TRANSPARENCY ) 
    } 	DXSAMPLEFORMATENUM;

typedef 
enum DXLOCKSURF
    {	DXLOCKF_READ	= 0,
	DXLOCKF_READWRITE	= ( 1 << 0 ) ,
	DXLOCKF_EXISTINGINFOONLY	= ( 1 << 1 ) ,
	DXLOCKF_WANTRUNINFO	= ( 1 << 2 ) ,
	DXLOCKF_NONPREMULT	= ( 1 << 16 ) ,
	DXLOCKF_VALIDFLAGS	= ( ( ( DXLOCKF_READWRITE | DXLOCKF_EXISTINGINFOONLY )  | DXLOCKF_WANTRUNINFO )  | DXLOCKF_NONPREMULT ) 
    } 	DXLOCKSURF;

typedef 
enum DXSURFSTATUS
    {	DXSURF_TRANSIENT	= ( 1 << 0 ) ,
	DXSURF_READONLY	= ( 1 << 1 ) ,
	DXSURF_VALIDFLAGS	= ( DXSURF_TRANSIENT | DXSURF_READONLY ) 
    } 	DXSURFSTATUS;



extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0008_v0_0_s_ifspec;

#ifndef __IDXSurface_INTERFACE_DEFINED__
#define __IDXSurface_INTERFACE_DEFINED__

/* interface IDXSurface */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B39FD73F-E139-11d1-9065-00C04FD9189D")
    IDXSurface : public IDXBaseObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPixelFormat( 
            /* [out] */ GUID *pFormatID,
            /* [out] */ DXSAMPLEFORMATENUM *pSampleFormatEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBounds( 
            /* [out] */ DXBNDS *pBounds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatusFlags( 
            /* [out] */ DWORD *pdwStatusFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStatusFlags( 
            /* [in] */ DWORD dwStatusFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockSurface( 
            /* [in] */ const DXBNDS *pBounds,
            /* [in] */ ULONG ulTimeOut,
            /* [in] */ DWORD dwFlags,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppPointer,
            /* [out] */ ULONG *pulGenerationId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDirectDrawSurface( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColorKey( 
            DXSAMPLE *pColorKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColorKey( 
            DXSAMPLE ColorKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockSurfaceDC( 
            /* [in] */ const DXBNDS *pBounds,
            /* [in] */ ULONG ulTimeOut,
            /* [in] */ DWORD dwFlags,
            /* [out] */ IDXDCLock **ppDCLock) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAppData( 
            DWORD dwAppData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAppData( 
            DWORD *pdwAppData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetGenerationId )( 
            IDXSurface * This,
            /* [out] */ ULONG *pID);
        
        HRESULT ( STDMETHODCALLTYPE *IncrementGenerationId )( 
            IDXSurface * This,
            /* [in] */ BOOL bRefresh);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectSize )( 
            IDXSurface * This,
            /* [out] */ ULONG *pcbSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPixelFormat )( 
            IDXSurface * This,
            /* [out] */ GUID *pFormatID,
            /* [out] */ DXSAMPLEFORMATENUM *pSampleFormatEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetBounds )( 
            IDXSurface * This,
            /* [out] */ DXBNDS *pBounds);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatusFlags )( 
            IDXSurface * This,
            /* [out] */ DWORD *pdwStatusFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetStatusFlags )( 
            IDXSurface * This,
            /* [in] */ DWORD dwStatusFlags);
        
        HRESULT ( STDMETHODCALLTYPE *LockSurface )( 
            IDXSurface * This,
            /* [in] */ const DXBNDS *pBounds,
            /* [in] */ ULONG ulTimeOut,
            /* [in] */ DWORD dwFlags,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppPointer,
            /* [out] */ ULONG *pulGenerationId);
        
        HRESULT ( STDMETHODCALLTYPE *GetDirectDrawSurface )( 
            IDXSurface * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppSurface);
        
        HRESULT ( STDMETHODCALLTYPE *GetColorKey )( 
            IDXSurface * This,
            DXSAMPLE *pColorKey);
        
        HRESULT ( STDMETHODCALLTYPE *SetColorKey )( 
            IDXSurface * This,
            DXSAMPLE ColorKey);
        
        HRESULT ( STDMETHODCALLTYPE *LockSurfaceDC )( 
            IDXSurface * This,
            /* [in] */ const DXBNDS *pBounds,
            /* [in] */ ULONG ulTimeOut,
            /* [in] */ DWORD dwFlags,
            /* [out] */ IDXDCLock **ppDCLock);
        
        HRESULT ( STDMETHODCALLTYPE *SetAppData )( 
            IDXSurface * This,
            DWORD dwAppData);
        
        HRESULT ( STDMETHODCALLTYPE *GetAppData )( 
            IDXSurface * This,
            DWORD *pdwAppData);
        
        END_INTERFACE
    } IDXSurfaceVtbl;

    interface IDXSurface
    {
        CONST_VTBL struct IDXSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXSurface_GetGenerationId(This,pID)	\
    ( (This)->lpVtbl -> GetGenerationId(This,pID) ) 

#define IDXSurface_IncrementGenerationId(This,bRefresh)	\
    ( (This)->lpVtbl -> IncrementGenerationId(This,bRefresh) ) 

#define IDXSurface_GetObjectSize(This,pcbSize)	\
    ( (This)->lpVtbl -> GetObjectSize(This,pcbSize) ) 


#define IDXSurface_GetPixelFormat(This,pFormatID,pSampleFormatEnum)	\
    ( (This)->lpVtbl -> GetPixelFormat(This,pFormatID,pSampleFormatEnum) ) 

#define IDXSurface_GetBounds(This,pBounds)	\
    ( (This)->lpVtbl -> GetBounds(This,pBounds) ) 

#define IDXSurface_GetStatusFlags(This,pdwStatusFlags)	\
    ( (This)->lpVtbl -> GetStatusFlags(This,pdwStatusFlags) ) 

#define IDXSurface_SetStatusFlags(This,dwStatusFlags)	\
    ( (This)->lpVtbl -> SetStatusFlags(This,dwStatusFlags) ) 

#define IDXSurface_LockSurface(This,pBounds,ulTimeOut,dwFlags,riid,ppPointer,pulGenerationId)	\
    ( (This)->lpVtbl -> LockSurface(This,pBounds,ulTimeOut,dwFlags,riid,ppPointer,pulGenerationId) ) 

#define IDXSurface_GetDirectDrawSurface(This,riid,ppSurface)	\
    ( (This)->lpVtbl -> GetDirectDrawSurface(This,riid,ppSurface) ) 

#define IDXSurface_GetColorKey(This,pColorKey)	\
    ( (This)->lpVtbl -> GetColorKey(This,pColorKey) ) 

#define IDXSurface_SetColorKey(This,ColorKey)	\
    ( (This)->lpVtbl -> SetColorKey(This,ColorKey) ) 

#define IDXSurface_LockSurfaceDC(This,pBounds,ulTimeOut,dwFlags,ppDCLock)	\
    ( (This)->lpVtbl -> LockSurfaceDC(This,pBounds,ulTimeOut,dwFlags,ppDCLock) ) 

#define IDXSurface_SetAppData(This,dwAppData)	\
    ( (This)->lpVtbl -> SetAppData(This,dwAppData) ) 

#define IDXSurface_GetAppData(This,pdwAppData)	\
    ( (This)->lpVtbl -> GetAppData(This,pdwAppData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXSurface_INTERFACE_DEFINED__ */


#ifndef __IDXSurfaceInit_INTERFACE_DEFINED__
#define __IDXSurfaceInit_INTERFACE_DEFINED__

/* interface IDXSurfaceInit */
/* [object][local][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXSurfaceInit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9EA3B639-C37D-11d1-905E-00C04FD9189D")
    IDXSurfaceInit : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitSurface( 
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ const DXBNDS *pBounds,
            /* [in] */ DWORD dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXSurfaceInitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXSurfaceInit * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXSurfaceInit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXSurfaceInit * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitSurface )( 
            IDXSurfaceInit * This,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ const DXBNDS *pBounds,
            /* [in] */ DWORD dwFlags);
        
        END_INTERFACE
    } IDXSurfaceInitVtbl;

    interface IDXSurfaceInit
    {
        CONST_VTBL struct IDXSurfaceInitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXSurfaceInit_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXSurfaceInit_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXSurfaceInit_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXSurfaceInit_InitSurface(This,pDirectDraw,pDDSurfaceDesc,pFormatID,pBounds,dwFlags)	\
    ( (This)->lpVtbl -> InitSurface(This,pDirectDraw,pDDSurfaceDesc,pFormatID,pBounds,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXSurfaceInit_INTERFACE_DEFINED__ */


#ifndef __IDXARGBSurfaceInit_INTERFACE_DEFINED__
#define __IDXARGBSurfaceInit_INTERFACE_DEFINED__

/* interface IDXARGBSurfaceInit */
/* [object][local][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXARGBSurfaceInit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9EA3B63A-C37D-11d1-905E-00C04FD9189D")
    IDXARGBSurfaceInit : public IDXSurfaceInit
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitFromDDSurface( 
            /* [in] */ IUnknown *pDDrawSurface,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitFromRawSurface( 
            /* [in] */ IDXRawSurface *pRawSurface) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXARGBSurfaceInitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXARGBSurfaceInit * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXARGBSurfaceInit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXARGBSurfaceInit * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitSurface )( 
            IDXARGBSurfaceInit * This,
            /* [in] */ IUnknown *pDirectDraw,
            /* [in] */ const DDSURFACEDESC *pDDSurfaceDesc,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ const DXBNDS *pBounds,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromDDSurface )( 
            IDXARGBSurfaceInit * This,
            /* [in] */ IUnknown *pDDrawSurface,
            /* [in] */ const GUID *pFormatID,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromRawSurface )( 
            IDXARGBSurfaceInit * This,
            /* [in] */ IDXRawSurface *pRawSurface);
        
        END_INTERFACE
    } IDXARGBSurfaceInitVtbl;

    interface IDXARGBSurfaceInit
    {
        CONST_VTBL struct IDXARGBSurfaceInitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXARGBSurfaceInit_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXARGBSurfaceInit_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXARGBSurfaceInit_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXARGBSurfaceInit_InitSurface(This,pDirectDraw,pDDSurfaceDesc,pFormatID,pBounds,dwFlags)	\
    ( (This)->lpVtbl -> InitSurface(This,pDirectDraw,pDDSurfaceDesc,pFormatID,pBounds,dwFlags) ) 


#define IDXARGBSurfaceInit_InitFromDDSurface(This,pDDrawSurface,pFormatID,dwFlags)	\
    ( (This)->lpVtbl -> InitFromDDSurface(This,pDDrawSurface,pFormatID,dwFlags) ) 

#define IDXARGBSurfaceInit_InitFromRawSurface(This,pRawSurface)	\
    ( (This)->lpVtbl -> InitFromRawSurface(This,pRawSurface) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXARGBSurfaceInit_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0011 */
/* [local] */ 

typedef struct tagDXNATIVETYPEINFO
    {
    BYTE *pCurrentData;
    BYTE *pFirstByte;
    long lPitch;
    DWORD dwColorKey;
    } 	DXNATIVETYPEINFO;

typedef struct tagDXPACKEDRECTDESC
    {
    DXBASESAMPLE *pSamples;
    BOOL bPremult;
    RECT rect;
    long lRowPadding;
    } 	DXPACKEDRECTDESC;

typedef struct tagDXOVERSAMPLEDESC
    {
    POINT p;
    DXPMSAMPLE Color;
    } 	DXOVERSAMPLEDESC;



extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0011_v0_0_s_ifspec;

#ifndef __IDXARGBReadPtr_INTERFACE_DEFINED__
#define __IDXARGBReadPtr_INTERFACE_DEFINED__

/* interface IDXARGBReadPtr */
/* [object][local][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXARGBReadPtr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EAAAC2D6-C290-11d1-905D-00C04FD9189D")
    IDXARGBReadPtr : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSurface( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppSurface) = 0;
        
        virtual DXSAMPLEFORMATENUM STDMETHODCALLTYPE GetNativeType( 
            /* [out] */ DXNATIVETYPEINFO *pInfo) = 0;
        
        virtual void STDMETHODCALLTYPE Move( 
            /* [in] */ long cSamples) = 0;
        
        virtual void STDMETHODCALLTYPE MoveToRow( 
            /* [in] */ ULONG y) = 0;
        
        virtual void STDMETHODCALLTYPE MoveToXY( 
            /* [in] */ ULONG x,
            /* [in] */ ULONG y) = 0;
        
        virtual ULONG STDMETHODCALLTYPE MoveAndGetRunInfo( 
            /* [in] */ ULONG Row,
            /* [out] */ const DXRUNINFO **ppInfo) = 0;
        
        virtual DXSAMPLE *STDMETHODCALLTYPE Unpack( 
            /* [in] */ DXSAMPLE *pSamples,
            /* [in] */ ULONG cSamples,
            /* [in] */ BOOL bMove) = 0;
        
        virtual DXPMSAMPLE *STDMETHODCALLTYPE UnpackPremult( 
            /* [in] */ DXPMSAMPLE *pSamples,
            /* [in] */ ULONG cSamples,
            /* [in] */ BOOL bMove) = 0;
        
        virtual void STDMETHODCALLTYPE UnpackRect( 
            /* [in] */ const DXPACKEDRECTDESC *pRectDesc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXARGBReadPtrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXARGBReadPtr * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXARGBReadPtr * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXARGBReadPtr * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSurface )( 
            IDXARGBReadPtr * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppSurface);
        
        DXSAMPLEFORMATENUM ( STDMETHODCALLTYPE *GetNativeType )( 
            IDXARGBReadPtr * This,
            /* [out] */ DXNATIVETYPEINFO *pInfo);
        
        void ( STDMETHODCALLTYPE *Move )( 
            IDXARGBReadPtr * This,
            /* [in] */ long cSamples);
        
        void ( STDMETHODCALLTYPE *MoveToRow )( 
            IDXARGBReadPtr * This,
            /* [in] */ ULONG y);
        
        void ( STDMETHODCALLTYPE *MoveToXY )( 
            IDXARGBReadPtr * This,
            /* [in] */ ULONG x,
            /* [in] */ ULONG y);
        
        ULONG ( STDMETHODCALLTYPE *MoveAndGetRunInfo )( 
            IDXARGBReadPtr * This,
            /* [in] */ ULONG Row,
            /* [out] */ const DXRUNINFO **ppInfo);
        
        DXSAMPLE *( STDMETHODCALLTYPE *Unpack )( 
            IDXARGBReadPtr * This,
            /* [in] */ DXSAMPLE *pSamples,
            /* [in] */ ULONG cSamples,
            /* [in] */ BOOL bMove);
        
        DXPMSAMPLE *( STDMETHODCALLTYPE *UnpackPremult )( 
            IDXARGBReadPtr * This,
            /* [in] */ DXPMSAMPLE *pSamples,
            /* [in] */ ULONG cSamples,
            /* [in] */ BOOL bMove);
        
        void ( STDMETHODCALLTYPE *UnpackRect )( 
            IDXARGBReadPtr * This,
            /* [in] */ const DXPACKEDRECTDESC *pRectDesc);
        
        END_INTERFACE
    } IDXARGBReadPtrVtbl;

    interface IDXARGBReadPtr
    {
        CONST_VTBL struct IDXARGBReadPtrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXARGBReadPtr_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXARGBReadPtr_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXARGBReadPtr_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXARGBReadPtr_GetSurface(This,riid,ppSurface)	\
    ( (This)->lpVtbl -> GetSurface(This,riid,ppSurface) ) 

#define IDXARGBReadPtr_GetNativeType(This,pInfo)	\
    ( (This)->lpVtbl -> GetNativeType(This,pInfo) ) 

#define IDXARGBReadPtr_Move(This,cSamples)	\
    ( (This)->lpVtbl -> Move(This,cSamples) ) 

#define IDXARGBReadPtr_MoveToRow(This,y)	\
    ( (This)->lpVtbl -> MoveToRow(This,y) ) 

#define IDXARGBReadPtr_MoveToXY(This,x,y)	\
    ( (This)->lpVtbl -> MoveToXY(This,x,y) ) 

#define IDXARGBReadPtr_MoveAndGetRunInfo(This,Row,ppInfo)	\
    ( (This)->lpVtbl -> MoveAndGetRunInfo(This,Row,ppInfo) ) 

#define IDXARGBReadPtr_Unpack(This,pSamples,cSamples,bMove)	\
    ( (This)->lpVtbl -> Unpack(This,pSamples,cSamples,bMove) ) 

#define IDXARGBReadPtr_UnpackPremult(This,pSamples,cSamples,bMove)	\
    ( (This)->lpVtbl -> UnpackPremult(This,pSamples,cSamples,bMove) ) 

#define IDXARGBReadPtr_UnpackRect(This,pRectDesc)	\
    ( (This)->lpVtbl -> UnpackRect(This,pRectDesc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXARGBReadPtr_INTERFACE_DEFINED__ */


#ifndef __IDXARGBReadWritePtr_INTERFACE_DEFINED__
#define __IDXARGBReadWritePtr_INTERFACE_DEFINED__

/* interface IDXARGBReadWritePtr */
/* [object][local][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXARGBReadWritePtr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EAAAC2D7-C290-11d1-905D-00C04FD9189D")
    IDXARGBReadWritePtr : public IDXARGBReadPtr
    {
    public:
        virtual void STDMETHODCALLTYPE PackAndMove( 
            /* [in] */ const DXSAMPLE *pSamples,
            /* [in] */ ULONG cSamples) = 0;
        
        virtual void STDMETHODCALLTYPE PackPremultAndMove( 
            /* [in] */ const DXPMSAMPLE *pSamples,
            /* [in] */ ULONG cSamples) = 0;
        
        virtual void STDMETHODCALLTYPE PackRect( 
            /* [in] */ const DXPACKEDRECTDESC *pRectDesc) = 0;
        
        virtual void STDMETHODCALLTYPE CopyAndMoveBoth( 
            /* [in] */ DXBASESAMPLE *pScratchBuffer,
            /* [in] */ IDXARGBReadPtr *pSrc,
            /* [in] */ ULONG cSamples,
            /* [in] */ BOOL bIsOpaque) = 0;
        
        virtual void STDMETHODCALLTYPE CopyRect( 
            /* [in] */ DXBASESAMPLE *pScratchBuffer,
            /* [in] */ const RECT *pDestRect,
            /* [in] */ IDXARGBReadPtr *pSrc,
            /* [in] */ const POINT *pSrcOrigin,
            /* [in] */ BOOL bIsOpaque) = 0;
        
        virtual void STDMETHODCALLTYPE FillAndMove( 
            /* [in] */ DXBASESAMPLE *pScratchBuffer,
            /* [in] */ DXPMSAMPLE SampVal,
            /* [in] */ ULONG cSamples,
            /* [in] */ BOOL bDoOver) = 0;
        
        virtual void STDMETHODCALLTYPE FillRect( 
            /* [in] */ const RECT *pRect,
            /* [in] */ DXPMSAMPLE SampVal,
            /* [in] */ BOOL bDoOver) = 0;
        
        virtual void STDMETHODCALLTYPE OverSample( 
            /* [in] */ const DXOVERSAMPLEDESC *pOverDesc) = 0;
        
        virtual void STDMETHODCALLTYPE OverArrayAndMove( 
            /* [in] */ DXBASESAMPLE *pScratchBuffer,
            /* [in] */ const DXPMSAMPLE *pSrc,
            /* [in] */ ULONG cSamples) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXARGBReadWritePtrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXARGBReadWritePtr * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXARGBReadWritePtr * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSurface )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppSurface);
        
        DXSAMPLEFORMATENUM ( STDMETHODCALLTYPE *GetNativeType )( 
            IDXARGBReadWritePtr * This,
            /* [out] */ DXNATIVETYPEINFO *pInfo);
        
        void ( STDMETHODCALLTYPE *Move )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ long cSamples);
        
        void ( STDMETHODCALLTYPE *MoveToRow )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ ULONG y);
        
        void ( STDMETHODCALLTYPE *MoveToXY )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ ULONG x,
            /* [in] */ ULONG y);
        
        ULONG ( STDMETHODCALLTYPE *MoveAndGetRunInfo )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ ULONG Row,
            /* [out] */ const DXRUNINFO **ppInfo);
        
        DXSAMPLE *( STDMETHODCALLTYPE *Unpack )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ DXSAMPLE *pSamples,
            /* [in] */ ULONG cSamples,
            /* [in] */ BOOL bMove);
        
        DXPMSAMPLE *( STDMETHODCALLTYPE *UnpackPremult )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ DXPMSAMPLE *pSamples,
            /* [in] */ ULONG cSamples,
            /* [in] */ BOOL bMove);
        
        void ( STDMETHODCALLTYPE *UnpackRect )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ const DXPACKEDRECTDESC *pRectDesc);
        
        void ( STDMETHODCALLTYPE *PackAndMove )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ const DXSAMPLE *pSamples,
            /* [in] */ ULONG cSamples);
        
        void ( STDMETHODCALLTYPE *PackPremultAndMove )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ const DXPMSAMPLE *pSamples,
            /* [in] */ ULONG cSamples);
        
        void ( STDMETHODCALLTYPE *PackRect )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ const DXPACKEDRECTDESC *pRectDesc);
        
        void ( STDMETHODCALLTYPE *CopyAndMoveBoth )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ DXBASESAMPLE *pScratchBuffer,
            /* [in] */ IDXARGBReadPtr *pSrc,
            /* [in] */ ULONG cSamples,
            /* [in] */ BOOL bIsOpaque);
        
        void ( STDMETHODCALLTYPE *CopyRect )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ DXBASESAMPLE *pScratchBuffer,
            /* [in] */ const RECT *pDestRect,
            /* [in] */ IDXARGBReadPtr *pSrc,
            /* [in] */ const POINT *pSrcOrigin,
            /* [in] */ BOOL bIsOpaque);
        
        void ( STDMETHODCALLTYPE *FillAndMove )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ DXBASESAMPLE *pScratchBuffer,
            /* [in] */ DXPMSAMPLE SampVal,
            /* [in] */ ULONG cSamples,
            /* [in] */ BOOL bDoOver);
        
        void ( STDMETHODCALLTYPE *FillRect )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ const RECT *pRect,
            /* [in] */ DXPMSAMPLE SampVal,
            /* [in] */ BOOL bDoOver);
        
        void ( STDMETHODCALLTYPE *OverSample )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ const DXOVERSAMPLEDESC *pOverDesc);
        
        void ( STDMETHODCALLTYPE *OverArrayAndMove )( 
            IDXARGBReadWritePtr * This,
            /* [in] */ DXBASESAMPLE *pScratchBuffer,
            /* [in] */ const DXPMSAMPLE *pSrc,
            /* [in] */ ULONG cSamples);
        
        END_INTERFACE
    } IDXARGBReadWritePtrVtbl;

    interface IDXARGBReadWritePtr
    {
        CONST_VTBL struct IDXARGBReadWritePtrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXARGBReadWritePtr_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXARGBReadWritePtr_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXARGBReadWritePtr_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXARGBReadWritePtr_GetSurface(This,riid,ppSurface)	\
    ( (This)->lpVtbl -> GetSurface(This,riid,ppSurface) ) 

#define IDXARGBReadWritePtr_GetNativeType(This,pInfo)	\
    ( (This)->lpVtbl -> GetNativeType(This,pInfo) ) 

#define IDXARGBReadWritePtr_Move(This,cSamples)	\
    ( (This)->lpVtbl -> Move(This,cSamples) ) 

#define IDXARGBReadWritePtr_MoveToRow(This,y)	\
    ( (This)->lpVtbl -> MoveToRow(This,y) ) 

#define IDXARGBReadWritePtr_MoveToXY(This,x,y)	\
    ( (This)->lpVtbl -> MoveToXY(This,x,y) ) 

#define IDXARGBReadWritePtr_MoveAndGetRunInfo(This,Row,ppInfo)	\
    ( (This)->lpVtbl -> MoveAndGetRunInfo(This,Row,ppInfo) ) 

#define IDXARGBReadWritePtr_Unpack(This,pSamples,cSamples,bMove)	\
    ( (This)->lpVtbl -> Unpack(This,pSamples,cSamples,bMove) ) 

#define IDXARGBReadWritePtr_UnpackPremult(This,pSamples,cSamples,bMove)	\
    ( (This)->lpVtbl -> UnpackPremult(This,pSamples,cSamples,bMove) ) 

#define IDXARGBReadWritePtr_UnpackRect(This,pRectDesc)	\
    ( (This)->lpVtbl -> UnpackRect(This,pRectDesc) ) 


#define IDXARGBReadWritePtr_PackAndMove(This,pSamples,cSamples)	\
    ( (This)->lpVtbl -> PackAndMove(This,pSamples,cSamples) ) 

#define IDXARGBReadWritePtr_PackPremultAndMove(This,pSamples,cSamples)	\
    ( (This)->lpVtbl -> PackPremultAndMove(This,pSamples,cSamples) ) 

#define IDXARGBReadWritePtr_PackRect(This,pRectDesc)	\
    ( (This)->lpVtbl -> PackRect(This,pRectDesc) ) 

#define IDXARGBReadWritePtr_CopyAndMoveBoth(This,pScratchBuffer,pSrc,cSamples,bIsOpaque)	\
    ( (This)->lpVtbl -> CopyAndMoveBoth(This,pScratchBuffer,pSrc,cSamples,bIsOpaque) ) 

#define IDXARGBReadWritePtr_CopyRect(This,pScratchBuffer,pDestRect,pSrc,pSrcOrigin,bIsOpaque)	\
    ( (This)->lpVtbl -> CopyRect(This,pScratchBuffer,pDestRect,pSrc,pSrcOrigin,bIsOpaque) ) 

#define IDXARGBReadWritePtr_FillAndMove(This,pScratchBuffer,SampVal,cSamples,bDoOver)	\
    ( (This)->lpVtbl -> FillAndMove(This,pScratchBuffer,SampVal,cSamples,bDoOver) ) 

#define IDXARGBReadWritePtr_FillRect(This,pRect,SampVal,bDoOver)	\
    ( (This)->lpVtbl -> FillRect(This,pRect,SampVal,bDoOver) ) 

#define IDXARGBReadWritePtr_OverSample(This,pOverDesc)	\
    ( (This)->lpVtbl -> OverSample(This,pOverDesc) ) 

#define IDXARGBReadWritePtr_OverArrayAndMove(This,pScratchBuffer,pSrc,cSamples)	\
    ( (This)->lpVtbl -> OverArrayAndMove(This,pScratchBuffer,pSrc,cSamples) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXARGBReadWritePtr_INTERFACE_DEFINED__ */


#ifndef __IDXDCLock_INTERFACE_DEFINED__
#define __IDXDCLock_INTERFACE_DEFINED__

/* interface IDXDCLock */
/* [object][local][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXDCLock;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0F619456-CF39-11d1-905E-00C04FD9189D")
    IDXDCLock : public IUnknown
    {
    public:
        virtual HDC STDMETHODCALLTYPE GetDC( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXDCLockVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXDCLock * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXDCLock * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXDCLock * This);
        
        HDC ( STDMETHODCALLTYPE *GetDC )( 
            IDXDCLock * This);
        
        END_INTERFACE
    } IDXDCLockVtbl;

    interface IDXDCLock
    {
        CONST_VTBL struct IDXDCLockVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXDCLock_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXDCLock_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXDCLock_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXDCLock_GetDC(This)	\
    ( (This)->lpVtbl -> GetDC(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXDCLock_INTERFACE_DEFINED__ */


#ifndef __IDXTScaleOutput_INTERFACE_DEFINED__
#define __IDXTScaleOutput_INTERFACE_DEFINED__

/* interface IDXTScaleOutput */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXTScaleOutput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B2024B50-EE77-11d1-9066-00C04FD9189D")
    IDXTScaleOutput : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetOutputSize( 
            /* [in] */ const SIZE OutSize,
            /* [in] */ BOOL bMaintainAspect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXTScaleOutputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXTScaleOutput * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXTScaleOutput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXTScaleOutput * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutputSize )( 
            IDXTScaleOutput * This,
            /* [in] */ const SIZE OutSize,
            /* [in] */ BOOL bMaintainAspect);
        
        END_INTERFACE
    } IDXTScaleOutputVtbl;

    interface IDXTScaleOutput
    {
        CONST_VTBL struct IDXTScaleOutputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXTScaleOutput_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXTScaleOutput_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXTScaleOutput_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXTScaleOutput_SetOutputSize(This,OutSize,bMaintainAspect)	\
    ( (This)->lpVtbl -> SetOutputSize(This,OutSize,bMaintainAspect) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXTScaleOutput_INTERFACE_DEFINED__ */


#ifndef __IDXGradient_INTERFACE_DEFINED__
#define __IDXGradient_INTERFACE_DEFINED__

/* interface IDXGradient */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXGradient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B2024B51-EE77-11d1-9066-00C04FD9189D")
    IDXGradient : public IDXTScaleOutput
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetGradient( 
            DXSAMPLE StartColor,
            DXSAMPLE EndColor,
            BOOL bHorizontal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputSize( 
            /* [out] */ SIZE *pOutSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGradientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGradient * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGradient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGradient * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutputSize )( 
            IDXGradient * This,
            /* [in] */ const SIZE OutSize,
            /* [in] */ BOOL bMaintainAspect);
        
        HRESULT ( STDMETHODCALLTYPE *SetGradient )( 
            IDXGradient * This,
            DXSAMPLE StartColor,
            DXSAMPLE EndColor,
            BOOL bHorizontal);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputSize )( 
            IDXGradient * This,
            /* [out] */ SIZE *pOutSize);
        
        END_INTERFACE
    } IDXGradientVtbl;

    interface IDXGradient
    {
        CONST_VTBL struct IDXGradientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGradient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGradient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGradient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGradient_SetOutputSize(This,OutSize,bMaintainAspect)	\
    ( (This)->lpVtbl -> SetOutputSize(This,OutSize,bMaintainAspect) ) 


#define IDXGradient_SetGradient(This,StartColor,EndColor,bHorizontal)	\
    ( (This)->lpVtbl -> SetGradient(This,StartColor,EndColor,bHorizontal) ) 

#define IDXGradient_GetOutputSize(This,pOutSize)	\
    ( (This)->lpVtbl -> GetOutputSize(This,pOutSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGradient_INTERFACE_DEFINED__ */


#ifndef __IDXGradient2_INTERFACE_DEFINED__
#define __IDXGradient2_INTERFACE_DEFINED__

/* interface IDXGradient2 */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXGradient2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d0ef2a80-61dc-11d2-b2eb-00a0c936b212")
    IDXGradient2 : public IDXGradient
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetRadialGradient( 
            /* [size_is][in] */ double *rgdblOffsets,
            /* [size_is][in] */ double *rgdblColors,
            /* [in] */ ULONG ulCount,
            /* [in] */ double dblOpacity,
            /* [in] */ DX2DXFORM *pXform,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLinearGradient( 
            /* [size_is][in] */ double *rgdblOffsets,
            /* [size_is][in] */ double *rgdblColors,
            /* [in] */ ULONG ulCount,
            /* [in] */ double dblOpacity,
            /* [in] */ DX2DXFORM *pXform,
            /* [in] */ DWORD dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXGradient2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGradient2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGradient2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGradient2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutputSize )( 
            IDXGradient2 * This,
            /* [in] */ const SIZE OutSize,
            /* [in] */ BOOL bMaintainAspect);
        
        HRESULT ( STDMETHODCALLTYPE *SetGradient )( 
            IDXGradient2 * This,
            DXSAMPLE StartColor,
            DXSAMPLE EndColor,
            BOOL bHorizontal);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputSize )( 
            IDXGradient2 * This,
            /* [out] */ SIZE *pOutSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetRadialGradient )( 
            IDXGradient2 * This,
            /* [size_is][in] */ double *rgdblOffsets,
            /* [size_is][in] */ double *rgdblColors,
            /* [in] */ ULONG ulCount,
            /* [in] */ double dblOpacity,
            /* [in] */ DX2DXFORM *pXform,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetLinearGradient )( 
            IDXGradient2 * This,
            /* [size_is][in] */ double *rgdblOffsets,
            /* [size_is][in] */ double *rgdblColors,
            /* [in] */ ULONG ulCount,
            /* [in] */ double dblOpacity,
            /* [in] */ DX2DXFORM *pXform,
            /* [in] */ DWORD dwFlags);
        
        END_INTERFACE
    } IDXGradient2Vtbl;

    interface IDXGradient2
    {
        CONST_VTBL struct IDXGradient2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGradient2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGradient2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGradient2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGradient2_SetOutputSize(This,OutSize,bMaintainAspect)	\
    ( (This)->lpVtbl -> SetOutputSize(This,OutSize,bMaintainAspect) ) 


#define IDXGradient2_SetGradient(This,StartColor,EndColor,bHorizontal)	\
    ( (This)->lpVtbl -> SetGradient(This,StartColor,EndColor,bHorizontal) ) 

#define IDXGradient2_GetOutputSize(This,pOutSize)	\
    ( (This)->lpVtbl -> GetOutputSize(This,pOutSize) ) 


#define IDXGradient2_SetRadialGradient(This,rgdblOffsets,rgdblColors,ulCount,dblOpacity,pXform,dwFlags)	\
    ( (This)->lpVtbl -> SetRadialGradient(This,rgdblOffsets,rgdblColors,ulCount,dblOpacity,pXform,dwFlags) ) 

#define IDXGradient2_SetLinearGradient(This,rgdblOffsets,rgdblColors,ulCount,dblOpacity,pXform,dwFlags)	\
    ( (This)->lpVtbl -> SetLinearGradient(This,rgdblOffsets,rgdblColors,ulCount,dblOpacity,pXform,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGradient2_INTERFACE_DEFINED__ */


#ifndef __IDXTScale_INTERFACE_DEFINED__
#define __IDXTScale_INTERFACE_DEFINED__

/* interface IDXTScale */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXTScale;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B39FD742-E139-11d1-9065-00C04FD9189D")
    IDXTScale : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetScales( 
            /* [in] */ float Scales[ 2 ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScales( 
            /* [out] */ float Scales[ 2 ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScaleFitToSize( 
            /* [out][in] */ DXBNDS *pClipBounds,
            /* [in] */ SIZE FitToSize,
            /* [in] */ BOOL bMaintainAspect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXTScaleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXTScale * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXTScale * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXTScale * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetScales )( 
            IDXTScale * This,
            /* [in] */ float Scales[ 2 ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetScales )( 
            IDXTScale * This,
            /* [out] */ float Scales[ 2 ]);
        
        HRESULT ( STDMETHODCALLTYPE *ScaleFitToSize )( 
            IDXTScale * This,
            /* [out][in] */ DXBNDS *pClipBounds,
            /* [in] */ SIZE FitToSize,
            /* [in] */ BOOL bMaintainAspect);
        
        END_INTERFACE
    } IDXTScaleVtbl;

    interface IDXTScale
    {
        CONST_VTBL struct IDXTScaleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXTScale_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXTScale_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXTScale_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXTScale_SetScales(This,Scales)	\
    ( (This)->lpVtbl -> SetScales(This,Scales) ) 

#define IDXTScale_GetScales(This,Scales)	\
    ( (This)->lpVtbl -> GetScales(This,Scales) ) 

#define IDXTScale_ScaleFitToSize(This,pClipBounds,FitToSize,bMaintainAspect)	\
    ( (This)->lpVtbl -> ScaleFitToSize(This,pClipBounds,FitToSize,bMaintainAspect) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXTScale_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0018 */
/* [local] */ 

typedef 
enum DXLOGFONTENUM
    {	DXLF_HEIGHT	= 1,
	DXLF_WIDTH	= 2,
	DXLF_ESC	= 4,
	DXLF_ORIENTATION	= 8,
	DXLF_WEIGHT	= 16,
	DXLF_ITALIC	= 32,
	DXLF_UNDERLINE	= 64,
	DXLF_STRIKEOUT	= 128,
	DXLF_CHARSET	= 256,
	DXLF_OUTPREC	= 512,
	DXLF_CLIPPREC	= 1024,
	DXLF_QUALITY	= 2048,
	DXLF_PITCHANDFAM	= 4096,
	DXLF_FACENAME	= 8192,
	DXLF_ALL	= 0x3fff
    } 	DXLOGFONTENUM;

#ifndef _WINGDI_
typedef struct tagLOGFONTA
    {
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[ 32 ];
    } 	LOGFONTA;

typedef struct tagLOGFONTW
    {
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[ 32 ];
    } 	LOGFONTW;

typedef LOGFONTA LOGFONT;

#endif


extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0018_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0018_v0_0_s_ifspec;

#ifndef __IDXTLabel_INTERFACE_DEFINED__
#define __IDXTLabel_INTERFACE_DEFINED__

/* interface IDXTLabel */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXTLabel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C0C17F0E-AE41-11d1-9A3B-0000F8756A10")
    IDXTLabel : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFontHandle( 
            /* [in] */ HFONT hFont) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontHandle( 
            /* [out] */ HFONT *phFont) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTextString( 
            /* [in] */ LPCWSTR pString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTextString( 
            /* [out] */ LPWSTR *ppString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFillColor( 
            /* [out] */ DXSAMPLE *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFillColor( 
            /* [in] */ DXSAMPLE newVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBackgroundColor( 
            /* [out] */ DXSAMPLE *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBackgroundColor( 
            /* [in] */ DXSAMPLE newVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTexturePosition( 
            /* [out] */ long *px,
            /* [out] */ long *py) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTexturePosition( 
            /* [in] */ long x,
            /* [in] */ long y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMatrix( 
            /* [out] */ PDX2DXFORM pXform) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMatrix( 
            /* [in] */ const PDX2DXFORM pXform) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLogfont( 
            /* [in] */ const LOGFONT *plf,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLogfont( 
            /* [out] */ LOGFONT *plf,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExecuteWithRasterizer( 
            /* [in] */ IDXRasterizer *pRasterizer,
            /* [in] */ const DXBNDS *pClipBnds,
            /* [in] */ const DXVEC *pPlacement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBaselineOffset( 
            /* [out] */ long *px,
            /* [out] */ long *py,
            /* [out] */ long *pdx,
            /* [out] */ long *pdy) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXTLabelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXTLabel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXTLabel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXTLabel * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFontHandle )( 
            IDXTLabel * This,
            /* [in] */ HFONT hFont);
        
        HRESULT ( STDMETHODCALLTYPE *GetFontHandle )( 
            IDXTLabel * This,
            /* [out] */ HFONT *phFont);
        
        HRESULT ( STDMETHODCALLTYPE *SetTextString )( 
            IDXTLabel * This,
            /* [in] */ LPCWSTR pString);
        
        HRESULT ( STDMETHODCALLTYPE *GetTextString )( 
            IDXTLabel * This,
            /* [out] */ LPWSTR *ppString);
        
        HRESULT ( STDMETHODCALLTYPE *GetFillColor )( 
            IDXTLabel * This,
            /* [out] */ DXSAMPLE *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetFillColor )( 
            IDXTLabel * This,
            /* [in] */ DXSAMPLE newVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetBackgroundColor )( 
            IDXTLabel * This,
            /* [out] */ DXSAMPLE *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetBackgroundColor )( 
            IDXTLabel * This,
            /* [in] */ DXSAMPLE newVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTexturePosition )( 
            IDXTLabel * This,
            /* [out] */ long *px,
            /* [out] */ long *py);
        
        HRESULT ( STDMETHODCALLTYPE *SetTexturePosition )( 
            IDXTLabel * This,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE *GetMatrix )( 
            IDXTLabel * This,
            /* [out] */ PDX2DXFORM pXform);
        
        HRESULT ( STDMETHODCALLTYPE *SetMatrix )( 
            IDXTLabel * This,
            /* [in] */ const PDX2DXFORM pXform);
        
        HRESULT ( STDMETHODCALLTYPE *SetLogfont )( 
            IDXTLabel * This,
            /* [in] */ const LOGFONT *plf,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetLogfont )( 
            IDXTLabel * This,
            /* [out] */ LOGFONT *plf,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *ExecuteWithRasterizer )( 
            IDXTLabel * This,
            /* [in] */ IDXRasterizer *pRasterizer,
            /* [in] */ const DXBNDS *pClipBnds,
            /* [in] */ const DXVEC *pPlacement);
        
        HRESULT ( STDMETHODCALLTYPE *GetBaselineOffset )( 
            IDXTLabel * This,
            /* [out] */ long *px,
            /* [out] */ long *py,
            /* [out] */ long *pdx,
            /* [out] */ long *pdy);
        
        END_INTERFACE
    } IDXTLabelVtbl;

    interface IDXTLabel
    {
        CONST_VTBL struct IDXTLabelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXTLabel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXTLabel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXTLabel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXTLabel_SetFontHandle(This,hFont)	\
    ( (This)->lpVtbl -> SetFontHandle(This,hFont) ) 

#define IDXTLabel_GetFontHandle(This,phFont)	\
    ( (This)->lpVtbl -> GetFontHandle(This,phFont) ) 

#define IDXTLabel_SetTextString(This,pString)	\
    ( (This)->lpVtbl -> SetTextString(This,pString) ) 

#define IDXTLabel_GetTextString(This,ppString)	\
    ( (This)->lpVtbl -> GetTextString(This,ppString) ) 

#define IDXTLabel_GetFillColor(This,pVal)	\
    ( (This)->lpVtbl -> GetFillColor(This,pVal) ) 

#define IDXTLabel_SetFillColor(This,newVal)	\
    ( (This)->lpVtbl -> SetFillColor(This,newVal) ) 

#define IDXTLabel_GetBackgroundColor(This,pVal)	\
    ( (This)->lpVtbl -> GetBackgroundColor(This,pVal) ) 

#define IDXTLabel_SetBackgroundColor(This,newVal)	\
    ( (This)->lpVtbl -> SetBackgroundColor(This,newVal) ) 

#define IDXTLabel_GetTexturePosition(This,px,py)	\
    ( (This)->lpVtbl -> GetTexturePosition(This,px,py) ) 

#define IDXTLabel_SetTexturePosition(This,x,y)	\
    ( (This)->lpVtbl -> SetTexturePosition(This,x,y) ) 

#define IDXTLabel_GetMatrix(This,pXform)	\
    ( (This)->lpVtbl -> GetMatrix(This,pXform) ) 

#define IDXTLabel_SetMatrix(This,pXform)	\
    ( (This)->lpVtbl -> SetMatrix(This,pXform) ) 

#define IDXTLabel_SetLogfont(This,plf,dwFlags)	\
    ( (This)->lpVtbl -> SetLogfont(This,plf,dwFlags) ) 

#define IDXTLabel_GetLogfont(This,plf,dwFlags)	\
    ( (This)->lpVtbl -> GetLogfont(This,plf,dwFlags) ) 

#define IDXTLabel_ExecuteWithRasterizer(This,pRasterizer,pClipBnds,pPlacement)	\
    ( (This)->lpVtbl -> ExecuteWithRasterizer(This,pRasterizer,pClipBnds,pPlacement) ) 

#define IDXTLabel_GetBaselineOffset(This,px,py,pdx,pdy)	\
    ( (This)->lpVtbl -> GetBaselineOffset(This,px,py,pdx,pdy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXTLabel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0019 */
/* [local] */ 

typedef 
enum DXRASTERFILL
    {	DXRASTER_PEN	= 0,
	DXRASTER_BRUSH	= 1,
	DXRASTER_BACKGROUND	= 2
    } 	DXRASTERFILL;

typedef struct DXRASTERSCANINFO
    {
    ULONG ulIndex;
    ULONG Row;
    const BYTE *pWeights;
    const DXRUNINFO *pRunInfo;
    ULONG cRunInfo;
    } 	DXRASTERSCANINFO;

typedef struct DXRASTERPOINTINFO
    {
    DXOVERSAMPLEDESC Pixel;
    ULONG ulIndex;
    BYTE Weight;
    } 	DXRASTERPOINTINFO;

typedef struct DXRASTERRECTINFO
    {
    ULONG ulIndex;
    RECT Rect;
    BYTE Weight;
    } 	DXRASTERRECTINFO;



extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0019_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0019_v0_0_s_ifspec;

#ifndef __IDXRasterizer_INTERFACE_DEFINED__
#define __IDXRasterizer_INTERFACE_DEFINED__

/* interface IDXRasterizer */
/* [object][local][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXRasterizer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9EA3B635-C37D-11d1-905E-00C04FD9189D")
    IDXRasterizer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSurface( 
            /* [in] */ IDXSurface *pDXSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurface( 
            /* [out] */ IDXSurface **ppDXSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFill( 
            /* [in] */ ULONG ulIndex,
            /* [in] */ IDXSurface *pSurface,
            /* [in] */ const POINT *ppt,
            /* [in] */ DXSAMPLE FillColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFill( 
            /* [in] */ ULONG ulIndex,
            /* [out] */ IDXSurface **ppSurface,
            /* [out] */ POINT *ppt,
            /* [out] */ DXSAMPLE *pFillColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginRendering( 
            /* [in] */ ULONG ulTimeOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndRendering( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RenderScan( 
            /* [in] */ const DXRASTERSCANINFO *pScanInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPixel( 
            /* [in] */ DXRASTERPOINTINFO *pPointInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FillRect( 
            /* [in] */ const DXRASTERRECTINFO *pRectInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBounds( 
            /* [out] */ DXBNDS *pBounds) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXRasterizerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXRasterizer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXRasterizer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXRasterizer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSurface )( 
            IDXRasterizer * This,
            /* [in] */ IDXSurface *pDXSurface);
        
        HRESULT ( STDMETHODCALLTYPE *GetSurface )( 
            IDXRasterizer * This,
            /* [out] */ IDXSurface **ppDXSurface);
        
        HRESULT ( STDMETHODCALLTYPE *SetFill )( 
            IDXRasterizer * This,
            /* [in] */ ULONG ulIndex,
            /* [in] */ IDXSurface *pSurface,
            /* [in] */ const POINT *ppt,
            /* [in] */ DXSAMPLE FillColor);
        
        HRESULT ( STDMETHODCALLTYPE *GetFill )( 
            IDXRasterizer * This,
            /* [in] */ ULONG ulIndex,
            /* [out] */ IDXSurface **ppSurface,
            /* [out] */ POINT *ppt,
            /* [out] */ DXSAMPLE *pFillColor);
        
        HRESULT ( STDMETHODCALLTYPE *BeginRendering )( 
            IDXRasterizer * This,
            /* [in] */ ULONG ulTimeOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndRendering )( 
            IDXRasterizer * This);
        
        HRESULT ( STDMETHODCALLTYPE *RenderScan )( 
            IDXRasterizer * This,
            /* [in] */ const DXRASTERSCANINFO *pScanInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SetPixel )( 
            IDXRasterizer * This,
            /* [in] */ DXRASTERPOINTINFO *pPointInfo);
        
        HRESULT ( STDMETHODCALLTYPE *FillRect )( 
            IDXRasterizer * This,
            /* [in] */ const DXRASTERRECTINFO *pRectInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetBounds )( 
            IDXRasterizer * This,
            /* [out] */ DXBNDS *pBounds);
        
        END_INTERFACE
    } IDXRasterizerVtbl;

    interface IDXRasterizer
    {
        CONST_VTBL struct IDXRasterizerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXRasterizer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXRasterizer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXRasterizer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXRasterizer_SetSurface(This,pDXSurface)	\
    ( (This)->lpVtbl -> SetSurface(This,pDXSurface) ) 

#define IDXRasterizer_GetSurface(This,ppDXSurface)	\
    ( (This)->lpVtbl -> GetSurface(This,ppDXSurface) ) 

#define IDXRasterizer_SetFill(This,ulIndex,pSurface,ppt,FillColor)	\
    ( (This)->lpVtbl -> SetFill(This,ulIndex,pSurface,ppt,FillColor) ) 

#define IDXRasterizer_GetFill(This,ulIndex,ppSurface,ppt,pFillColor)	\
    ( (This)->lpVtbl -> GetFill(This,ulIndex,ppSurface,ppt,pFillColor) ) 

#define IDXRasterizer_BeginRendering(This,ulTimeOut)	\
    ( (This)->lpVtbl -> BeginRendering(This,ulTimeOut) ) 

#define IDXRasterizer_EndRendering(This)	\
    ( (This)->lpVtbl -> EndRendering(This) ) 

#define IDXRasterizer_RenderScan(This,pScanInfo)	\
    ( (This)->lpVtbl -> RenderScan(This,pScanInfo) ) 

#define IDXRasterizer_SetPixel(This,pPointInfo)	\
    ( (This)->lpVtbl -> SetPixel(This,pPointInfo) ) 

#define IDXRasterizer_FillRect(This,pRectInfo)	\
    ( (This)->lpVtbl -> FillRect(This,pRectInfo) ) 

#define IDXRasterizer_GetBounds(This,pBounds)	\
    ( (This)->lpVtbl -> GetBounds(This,pBounds) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXRasterizer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0020 */
/* [local] */ 

typedef 
enum DISPIDDXEFFECT
    {	DISPID_DXECAPABILITIES	= 10000,
	DISPID_DXEPROGRESS	= ( DISPID_DXECAPABILITIES + 1 ) ,
	DISPID_DXESTEP	= ( DISPID_DXEPROGRESS + 1 ) ,
	DISPID_DXEDURATION	= ( DISPID_DXESTEP + 1 ) ,
	DISPID_DXE_NEXT_ID	= ( DISPID_DXEDURATION + 1 ) 
    } 	DISPIDDXBOUNDEDEFFECT;

typedef 
enum DXEFFECTTYPE
    {	DXTET_PERIODIC	= ( 1 << 0 ) ,
	DXTET_MORPH	= ( 1 << 1 ) 
    } 	DXEFFECTTYPE;



extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0020_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0020_v0_0_s_ifspec;

#ifndef __IDXEffect_INTERFACE_DEFINED__
#define __IDXEffect_INTERFACE_DEFINED__

/* interface IDXEffect */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDXEffect;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E31FB81B-1335-11d1-8189-0000F87557DB")
    IDXEffect : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Capabilities( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Progress( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Progress( 
            /* [in] */ float newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StepResolution( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Duration( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Duration( 
            /* [in] */ float newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXEffectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXEffect * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXEffect * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXEffect * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDXEffect * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDXEffect * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDXEffect * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDXEffect * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Capabilities )( 
            IDXEffect * This,
            /* [retval][out] */ long *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Progress )( 
            IDXEffect * This,
            /* [retval][out] */ float *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Progress )( 
            IDXEffect * This,
            /* [in] */ float newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StepResolution )( 
            IDXEffect * This,
            /* [retval][out] */ float *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Duration )( 
            IDXEffect * This,
            /* [retval][out] */ float *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Duration )( 
            IDXEffect * This,
            /* [in] */ float newVal);
        
        END_INTERFACE
    } IDXEffectVtbl;

    interface IDXEffect
    {
        CONST_VTBL struct IDXEffectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXEffect_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXEffect_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXEffect_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXEffect_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDXEffect_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDXEffect_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDXEffect_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDXEffect_get_Capabilities(This,pVal)	\
    ( (This)->lpVtbl -> get_Capabilities(This,pVal) ) 

#define IDXEffect_get_Progress(This,pVal)	\
    ( (This)->lpVtbl -> get_Progress(This,pVal) ) 

#define IDXEffect_put_Progress(This,newVal)	\
    ( (This)->lpVtbl -> put_Progress(This,newVal) ) 

#define IDXEffect_get_StepResolution(This,pVal)	\
    ( (This)->lpVtbl -> get_StepResolution(This,pVal) ) 

#define IDXEffect_get_Duration(This,pVal)	\
    ( (This)->lpVtbl -> get_Duration(This,pVal) ) 

#define IDXEffect_put_Duration(This,newVal)	\
    ( (This)->lpVtbl -> put_Duration(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXEffect_INTERFACE_DEFINED__ */


#ifndef __IDXLookupTable_INTERFACE_DEFINED__
#define __IDXLookupTable_INTERFACE_DEFINED__

/* interface IDXLookupTable */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXLookupTable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01BAFC7F-9E63-11d1-9053-00C04FD9189D")
    IDXLookupTable : public IDXBaseObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTables( 
            /* [out] */ BYTE RedLUT[ 256 ],
            /* [out] */ BYTE GreenLUT[ 256 ],
            /* [out] */ BYTE BlueLUT[ 256 ],
            /* [out] */ BYTE AlphaLUT[ 256 ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsChannelIdentity( 
            /* [out] */ DXBASESAMPLE *pSampleBools) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIndexValues( 
            /* [in] */ ULONG Index,
            /* [out] */ DXBASESAMPLE *pSample) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ApplyTables( 
            /* [out][in] */ DXSAMPLE *pSamples,
            /* [in] */ ULONG cSamples) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXLookupTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXLookupTable * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXLookupTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXLookupTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetGenerationId )( 
            IDXLookupTable * This,
            /* [out] */ ULONG *pID);
        
        HRESULT ( STDMETHODCALLTYPE *IncrementGenerationId )( 
            IDXLookupTable * This,
            /* [in] */ BOOL bRefresh);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectSize )( 
            IDXLookupTable * This,
            /* [out] */ ULONG *pcbSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetTables )( 
            IDXLookupTable * This,
            /* [out] */ BYTE RedLUT[ 256 ],
            /* [out] */ BYTE GreenLUT[ 256 ],
            /* [out] */ BYTE BlueLUT[ 256 ],
            /* [out] */ BYTE AlphaLUT[ 256 ]);
        
        HRESULT ( STDMETHODCALLTYPE *IsChannelIdentity )( 
            IDXLookupTable * This,
            /* [out] */ DXBASESAMPLE *pSampleBools);
        
        HRESULT ( STDMETHODCALLTYPE *GetIndexValues )( 
            IDXLookupTable * This,
            /* [in] */ ULONG Index,
            /* [out] */ DXBASESAMPLE *pSample);
        
        HRESULT ( STDMETHODCALLTYPE *ApplyTables )( 
            IDXLookupTable * This,
            /* [out][in] */ DXSAMPLE *pSamples,
            /* [in] */ ULONG cSamples);
        
        END_INTERFACE
    } IDXLookupTableVtbl;

    interface IDXLookupTable
    {
        CONST_VTBL struct IDXLookupTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXLookupTable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXLookupTable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXLookupTable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXLookupTable_GetGenerationId(This,pID)	\
    ( (This)->lpVtbl -> GetGenerationId(This,pID) ) 

#define IDXLookupTable_IncrementGenerationId(This,bRefresh)	\
    ( (This)->lpVtbl -> IncrementGenerationId(This,bRefresh) ) 

#define IDXLookupTable_GetObjectSize(This,pcbSize)	\
    ( (This)->lpVtbl -> GetObjectSize(This,pcbSize) ) 


#define IDXLookupTable_GetTables(This,RedLUT,GreenLUT,BlueLUT,AlphaLUT)	\
    ( (This)->lpVtbl -> GetTables(This,RedLUT,GreenLUT,BlueLUT,AlphaLUT) ) 

#define IDXLookupTable_IsChannelIdentity(This,pSampleBools)	\
    ( (This)->lpVtbl -> IsChannelIdentity(This,pSampleBools) ) 

#define IDXLookupTable_GetIndexValues(This,Index,pSample)	\
    ( (This)->lpVtbl -> GetIndexValues(This,Index,pSample) ) 

#define IDXLookupTable_ApplyTables(This,pSamples,cSamples)	\
    ( (This)->lpVtbl -> ApplyTables(This,pSamples,cSamples) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXLookupTable_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0022 */
/* [local] */ 

typedef 
enum DX2DPOLYDRAW
    {	DX2D_WINDING_FILL	= ( 1L << 0 ) ,
	DX2D_NO_FLATTEN	= ( 1L << 1 ) ,
	DX2D_DO_GRID_FIT	= ( 1L << 2 ) ,
	DX2D_IS_RECT	= ( 1L << 3 ) ,
	DX2D_STROKE	= ( 1L << 4 ) ,
	DX2D_FILL	= ( 1L << 5 ) ,
	DX2D_UNUSED	= 0xffffffc0
    } 	DX2DPOLYDRAW;

typedef struct DXFPOINT
    {
    FLOAT x;
    FLOAT y;
    } 	DXFPOINT;

typedef 
enum DX2DPEN
    {	DX2D_PEN_DEFAULT	= 0,
	DX2D_PEN_WIDTH_IN_DISPLAY_COORDS	= ( 1L << 0 ) ,
	DX2D_PEN_UNUSED	= 0xfffffffe
    } 	DX2DPEN;

typedef struct DXPEN
    {
    DXSAMPLE Color;
    float Width;
    DWORD Style;
    IDXSurface *pTexture;
    DXFPOINT TexturePos;
    DWORD dwFlags;
    } 	DXPEN;

typedef struct DXBRUSH
    {
    DXSAMPLE Color;
    IDXSurface *pTexture;
    DXFPOINT TexturePos;
    } 	DXBRUSH;

typedef 
enum DX2DGRADIENT
    {	DX2DGRAD_DEFAULT	= 0,
	DX2DGRAD_CLIPGRADIENT	= 1,
	DX2DGRAD_UNUSED	= 0xfffffffe
    } 	DX2DGRADIENT;



extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0022_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0022_v0_0_s_ifspec;

#ifndef __IDX2DDebug_INTERFACE_DEFINED__
#define __IDX2DDebug_INTERFACE_DEFINED__

/* interface IDX2DDebug */
/* [object][unique][helpstring][uuid][local] */ 


EXTERN_C const IID IID_IDX2DDebug;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("03BB2457-A279-11d1-81C6-0000F87557DB")
    IDX2DDebug : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetDC( 
            HDC hDC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDC( 
            HDC *phDC) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDX2DDebugVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDX2DDebug * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDX2DDebug * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDX2DDebug * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDC )( 
            IDX2DDebug * This,
            HDC hDC);
        
        HRESULT ( STDMETHODCALLTYPE *GetDC )( 
            IDX2DDebug * This,
            HDC *phDC);
        
        END_INTERFACE
    } IDX2DDebugVtbl;

    interface IDX2DDebug
    {
        CONST_VTBL struct IDX2DDebugVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDX2DDebug_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDX2DDebug_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDX2DDebug_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDX2DDebug_SetDC(This,hDC)	\
    ( (This)->lpVtbl -> SetDC(This,hDC) ) 

#define IDX2DDebug_GetDC(This,phDC)	\
    ( (This)->lpVtbl -> GetDC(This,phDC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDX2DDebug_INTERFACE_DEFINED__ */


#ifndef __IDX2D_INTERFACE_DEFINED__
#define __IDX2D_INTERFACE_DEFINED__

/* interface IDX2D */
/* [object][unique][helpstring][uuid][local] */ 


EXTERN_C const IID IID_IDX2D;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9EFD02A9-A996-11d1-81C9-0000F87557DB")
    IDX2D : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetTransformFactory( 
            IDXTransformFactory *pTransFact) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransformFactory( 
            IDXTransformFactory **ppTransFact) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSurface( 
            IUnknown *pSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurface( 
            REFIID riid,
            void **ppSurface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetClipRect( 
            RECT *pClipRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClipRect( 
            RECT *pClipRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWorldTransform( 
            const DX2DXFORM *pXform) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWorldTransform( 
            DX2DXFORM *pXform) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPen( 
            const DXPEN *pPen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPen( 
            DXPEN *pPen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBrush( 
            const DXBRUSH *pBrush) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBrush( 
            DXBRUSH *pBrush) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBackgroundBrush( 
            const DXBRUSH *pBrush) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBackgroundBrush( 
            DXBRUSH *pBrush) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFont( 
            HFONT hFont) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFont( 
            HFONT *phFont) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Blt( 
            IUnknown *punkSrc,
            const RECT *pSrcRect,
            const POINT *pDest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AAPolyDraw( 
            const DXFPOINT *pPos,
            const BYTE *pTypes,
            ULONG ulCount,
            ULONG SubSampRes,
            DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AAText( 
            DXFPOINT Pos,
            LPWSTR pString,
            ULONG ulCount,
            DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRadialGradientBrush( 
            /* [size_is][in] */ double *rgdblOffsets,
            /* [size_is][in] */ double *rgdblColors,
            /* [in] */ ULONG ulCount,
            /* [in] */ double dblOpacity,
            /* [in] */ DX2DXFORM *pXform,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLinearGradientBrush( 
            /* [size_is][in] */ double *rgdblOffsets,
            /* [size_is][in] */ double *rgdblColors,
            /* [in] */ ULONG ulCount,
            /* [in] */ double dblOpacity,
            /* [in] */ DX2DXFORM *pXform,
            /* [in] */ DWORD dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDX2DVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDX2D * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDX2D * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDX2D * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetTransformFactory )( 
            IDX2D * This,
            IDXTransformFactory *pTransFact);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransformFactory )( 
            IDX2D * This,
            IDXTransformFactory **ppTransFact);
        
        HRESULT ( STDMETHODCALLTYPE *SetSurface )( 
            IDX2D * This,
            IUnknown *pSurface);
        
        HRESULT ( STDMETHODCALLTYPE *GetSurface )( 
            IDX2D * This,
            REFIID riid,
            void **ppSurface);
        
        HRESULT ( STDMETHODCALLTYPE *SetClipRect )( 
            IDX2D * This,
            RECT *pClipRect);
        
        HRESULT ( STDMETHODCALLTYPE *GetClipRect )( 
            IDX2D * This,
            RECT *pClipRect);
        
        HRESULT ( STDMETHODCALLTYPE *SetWorldTransform )( 
            IDX2D * This,
            const DX2DXFORM *pXform);
        
        HRESULT ( STDMETHODCALLTYPE *GetWorldTransform )( 
            IDX2D * This,
            DX2DXFORM *pXform);
        
        HRESULT ( STDMETHODCALLTYPE *SetPen )( 
            IDX2D * This,
            const DXPEN *pPen);
        
        HRESULT ( STDMETHODCALLTYPE *GetPen )( 
            IDX2D * This,
            DXPEN *pPen);
        
        HRESULT ( STDMETHODCALLTYPE *SetBrush )( 
            IDX2D * This,
            const DXBRUSH *pBrush);
        
        HRESULT ( STDMETHODCALLTYPE *GetBrush )( 
            IDX2D * This,
            DXBRUSH *pBrush);
        
        HRESULT ( STDMETHODCALLTYPE *SetBackgroundBrush )( 
            IDX2D * This,
            const DXBRUSH *pBrush);
        
        HRESULT ( STDMETHODCALLTYPE *GetBackgroundBrush )( 
            IDX2D * This,
            DXBRUSH *pBrush);
        
        HRESULT ( STDMETHODCALLTYPE *SetFont )( 
            IDX2D * This,
            HFONT hFont);
        
        HRESULT ( STDMETHODCALLTYPE *GetFont )( 
            IDX2D * This,
            HFONT *phFont);
        
        HRESULT ( STDMETHODCALLTYPE *Blt )( 
            IDX2D * This,
            IUnknown *punkSrc,
            const RECT *pSrcRect,
            const POINT *pDest);
        
        HRESULT ( STDMETHODCALLTYPE *AAPolyDraw )( 
            IDX2D * This,
            const DXFPOINT *pPos,
            const BYTE *pTypes,
            ULONG ulCount,
            ULONG SubSampRes,
            DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *AAText )( 
            IDX2D * This,
            DXFPOINT Pos,
            LPWSTR pString,
            ULONG ulCount,
            DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetRadialGradientBrush )( 
            IDX2D * This,
            /* [size_is][in] */ double *rgdblOffsets,
            /* [size_is][in] */ double *rgdblColors,
            /* [in] */ ULONG ulCount,
            /* [in] */ double dblOpacity,
            /* [in] */ DX2DXFORM *pXform,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetLinearGradientBrush )( 
            IDX2D * This,
            /* [size_is][in] */ double *rgdblOffsets,
            /* [size_is][in] */ double *rgdblColors,
            /* [in] */ ULONG ulCount,
            /* [in] */ double dblOpacity,
            /* [in] */ DX2DXFORM *pXform,
            /* [in] */ DWORD dwFlags);
        
        END_INTERFACE
    } IDX2DVtbl;

    interface IDX2D
    {
        CONST_VTBL struct IDX2DVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDX2D_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDX2D_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDX2D_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDX2D_SetTransformFactory(This,pTransFact)	\
    ( (This)->lpVtbl -> SetTransformFactory(This,pTransFact) ) 

#define IDX2D_GetTransformFactory(This,ppTransFact)	\
    ( (This)->lpVtbl -> GetTransformFactory(This,ppTransFact) ) 

#define IDX2D_SetSurface(This,pSurface)	\
    ( (This)->lpVtbl -> SetSurface(This,pSurface) ) 

#define IDX2D_GetSurface(This,riid,ppSurface)	\
    ( (This)->lpVtbl -> GetSurface(This,riid,ppSurface) ) 

#define IDX2D_SetClipRect(This,pClipRect)	\
    ( (This)->lpVtbl -> SetClipRect(This,pClipRect) ) 

#define IDX2D_GetClipRect(This,pClipRect)	\
    ( (This)->lpVtbl -> GetClipRect(This,pClipRect) ) 

#define IDX2D_SetWorldTransform(This,pXform)	\
    ( (This)->lpVtbl -> SetWorldTransform(This,pXform) ) 

#define IDX2D_GetWorldTransform(This,pXform)	\
    ( (This)->lpVtbl -> GetWorldTransform(This,pXform) ) 

#define IDX2D_SetPen(This,pPen)	\
    ( (This)->lpVtbl -> SetPen(This,pPen) ) 

#define IDX2D_GetPen(This,pPen)	\
    ( (This)->lpVtbl -> GetPen(This,pPen) ) 

#define IDX2D_SetBrush(This,pBrush)	\
    ( (This)->lpVtbl -> SetBrush(This,pBrush) ) 

#define IDX2D_GetBrush(This,pBrush)	\
    ( (This)->lpVtbl -> GetBrush(This,pBrush) ) 

#define IDX2D_SetBackgroundBrush(This,pBrush)	\
    ( (This)->lpVtbl -> SetBackgroundBrush(This,pBrush) ) 

#define IDX2D_GetBackgroundBrush(This,pBrush)	\
    ( (This)->lpVtbl -> GetBackgroundBrush(This,pBrush) ) 

#define IDX2D_SetFont(This,hFont)	\
    ( (This)->lpVtbl -> SetFont(This,hFont) ) 

#define IDX2D_GetFont(This,phFont)	\
    ( (This)->lpVtbl -> GetFont(This,phFont) ) 

#define IDX2D_Blt(This,punkSrc,pSrcRect,pDest)	\
    ( (This)->lpVtbl -> Blt(This,punkSrc,pSrcRect,pDest) ) 

#define IDX2D_AAPolyDraw(This,pPos,pTypes,ulCount,SubSampRes,dwFlags)	\
    ( (This)->lpVtbl -> AAPolyDraw(This,pPos,pTypes,ulCount,SubSampRes,dwFlags) ) 

#define IDX2D_AAText(This,Pos,pString,ulCount,dwFlags)	\
    ( (This)->lpVtbl -> AAText(This,Pos,pString,ulCount,dwFlags) ) 

#define IDX2D_SetRadialGradientBrush(This,rgdblOffsets,rgdblColors,ulCount,dblOpacity,pXform,dwFlags)	\
    ( (This)->lpVtbl -> SetRadialGradientBrush(This,rgdblOffsets,rgdblColors,ulCount,dblOpacity,pXform,dwFlags) ) 

#define IDX2D_SetLinearGradientBrush(This,rgdblOffsets,rgdblColors,ulCount,dblOpacity,pXform,dwFlags)	\
    ( (This)->lpVtbl -> SetLinearGradientBrush(This,rgdblOffsets,rgdblColors,ulCount,dblOpacity,pXform,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDX2D_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DxTrans_0000_0024 */
/* [local] */ 

typedef struct DXRAWSURFACEINFO
    {
    BYTE *pFirstByte;
    long lPitch;
    ULONG Width;
    ULONG Height;
    const GUID *pPixelFormat;
    HDC hdc;
    DWORD dwColorKey;
    DXBASESAMPLE *pPalette;
    } 	DXRAWSURFACEINFO;



extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0024_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DxTrans_0000_0024_v0_0_s_ifspec;

#ifndef __IDXRawSurface_INTERFACE_DEFINED__
#define __IDXRawSurface_INTERFACE_DEFINED__

/* interface IDXRawSurface */
/* [object][local][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDXRawSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("09756C8A-D96A-11d1-9062-00C04FD9189D")
    IDXRawSurface : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSurfaceInfo( 
            DXRAWSURFACEINFO *pSurfaceInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDXRawSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXRawSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXRawSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXRawSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSurfaceInfo )( 
            IDXRawSurface * This,
            DXRAWSURFACEINFO *pSurfaceInfo);
        
        END_INTERFACE
    } IDXRawSurfaceVtbl;

    interface IDXRawSurface
    {
        CONST_VTBL struct IDXRawSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXRawSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXRawSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXRawSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXRawSurface_GetSurfaceInfo(This,pSurfaceInfo)	\
    ( (This)->lpVtbl -> GetSurfaceInfo(This,pSurfaceInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXRawSurface_INTERFACE_DEFINED__ */



#ifndef __DXTRANSLib_LIBRARY_DEFINED__
#define __DXTRANSLib_LIBRARY_DEFINED__

/* library DXTRANSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_DXTRANSLib;

EXTERN_C const CLSID CLSID_DXTransformFactory;

#ifdef __cplusplus

class DECLSPEC_UUID("D1FE6762-FC48-11D0-883A-3C8B00C10000")
DXTransformFactory;
#endif

EXTERN_C const CLSID CLSID_DXTaskManager;

#ifdef __cplusplus

class DECLSPEC_UUID("4CB26C03-FF93-11d0-817E-0000F87557DB")
DXTaskManager;
#endif

EXTERN_C const CLSID CLSID_DXTScale;

#ifdef __cplusplus

class DECLSPEC_UUID("555278E2-05DB-11D1-883A-3C8B00C10000")
DXTScale;
#endif

EXTERN_C const CLSID CLSID_DXTLabel;

#ifdef __cplusplus

class DECLSPEC_UUID("54702535-2606-11D1-999C-0000F8756A10")
DXTLabel;
#endif

EXTERN_C const CLSID CLSID_DX2D;

#ifdef __cplusplus

class DECLSPEC_UUID("473AA80B-4577-11D1-81A8-0000F87557DB")
DX2D;
#endif

EXTERN_C const CLSID CLSID_DXSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("0E890F83-5F79-11D1-9043-00C04FD9189D")
DXSurface;
#endif

EXTERN_C const CLSID CLSID_DXSurfaceModifier;

#ifdef __cplusplus

class DECLSPEC_UUID("3E669F1D-9C23-11d1-9053-00C04FD9189D")
DXSurfaceModifier;
#endif

EXTERN_C const CLSID CLSID_DXRasterizer;

#ifdef __cplusplus

class DECLSPEC_UUID("8652CE55-9E80-11D1-9053-00C04FD9189D")
DXRasterizer;
#endif

EXTERN_C const CLSID CLSID_DXGradient;

#ifdef __cplusplus

class DECLSPEC_UUID("C6365470-F667-11d1-9067-00C04FD9189D")
DXGradient;
#endif
#endif /* __DXTRANSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HFONT_UserSize(     unsigned long *, unsigned long            , HFONT * ); 
unsigned char * __RPC_USER  HFONT_UserMarshal(  unsigned long *, unsigned char *, HFONT * ); 
unsigned char * __RPC_USER  HFONT_UserUnmarshal(unsigned long *, unsigned char *, HFONT * ); 
void                      __RPC_USER  HFONT_UserFree(     unsigned long *, HFONT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


