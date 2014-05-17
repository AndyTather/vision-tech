// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

#define _CRT_SECURE_NO_DEPRECATE

#define STRICT
//#define VC_EXTRALEAN
//#define _AFX_NO_OCC_SUPPORT

#include <afxwin.h>      // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC OLE automation classes

#include <afxole.h>
#include <comdef.h>

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows 95 Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


#include <objbase.h>
#include "dxtrans.h"
#include <dshow.h>
#include <D3d9.h>
//#include <vmr9.h>
#include "pvmr9.h"


// Movie Support
#include <strmif.h>
#include <control.h>
//#include <evcode.h>
#include <uuids.h>
#include <afxdlgs.h>
#include <afx.h>
#define EC_COMPLETE                         0x01
// ( HRESULT, void ) : defaulted (special)
// Signals the completed playback of a stream within the graph.  This message
// is sent by renderers when they receive end-of-stream.  The default handling
// of this message results in a _SINGLE_ EC_COMPLETE being sent to the
// application when ALL of the individual renderers have signaled EC_COMPLETE
// to the filter graph.  If the default handing is canceled, the application
// will see all of the individual EC_COMPLETEs.


#define EC_USERABORT                        0x02
// ( void, void ) : application
// In some sense, the user has requested that playback be terminated.
// This message is typically sent by renderers that render into a
// window if the user closes the window into which it was rendering.
// It is up to the application to decide if playback should actually
// be stopped.


#define EC_ERRORABORT                       0x03