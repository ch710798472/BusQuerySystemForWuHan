#if !defined(AFX_INFORMATION_H__D300264B_1356_45EE_976A_91B555842D30__INCLUDED_)
#define AFX_INFORMATION_H__D300264B_1356_45EE_976A_91B555842D30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// information.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// information dialog

class information : public CDialog
{
// Construction
public:
	information(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(information)
	enum { IDD = IDD_INFORMATION };
	CString	m_bus_line1;
	CString	m_bus_station1;
	CString	m_bus_stationid1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(information)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(information)
	afx_msg void OnAdd();
	afx_msg void OnEditBusLine();
	afx_msg void OnDel();
	afx_msg void OnChange();
	virtual void OnCancel();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFORMATION_H__D300264B_1356_45EE_976A_91B555842D30__INCLUDED_)
