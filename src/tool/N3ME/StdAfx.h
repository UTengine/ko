// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

// stl 쓸려고...
#pragma warning(disable : 4786)

#pragma once

#define VC_EXTRALEAN // Exclude rarely-used stuff from Windows headers

#include <afxwin.h>   // MFC core and standard components
#include <afxext.h>   // MFC extensions
#include <afxdisp.h>  // MFC Automation classes
#include <afxdtctl.h> // MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h> // MFC support for Windows Common Controls
#endif              // _AFX_NO_AFXCMN_SUPPORT

#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>

#include "N3Base/My_3DStruct.h"

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
