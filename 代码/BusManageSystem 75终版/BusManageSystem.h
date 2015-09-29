// BusManageSystem.h : main header file for the BUSMANAGESYSTEM application
//

#if !defined(AFX_BUSMANAGESYSTEM_H__AEAC23CE_52A5_480E_BB03_4F6D8C2F0C37__INCLUDED_)
#define AFX_BUSMANAGESYSTEM_H__AEAC23CE_52A5_480E_BB03_4F6D8C2F0C37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBusManageSystemApp:
// See BusManageSystem.cpp for the implementation of this class
//

class CBusManageSystemApp : public CWinApp
{
public:
	CBusManageSystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBusManageSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBusManageSystemApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUSMANAGESYSTEM_H__AEAC23CE_52A5_480E_BB03_4F6D8C2F0C37__INCLUDED_)
