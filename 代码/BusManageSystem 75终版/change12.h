#if !defined(AFX_CHANGE12_H__0C116307_1989_4909_BAF1_FBE29CB5C533__INCLUDED_)
#define AFX_CHANGE12_H__0C116307_1989_4909_BAF1_FBE29CB5C533__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// change12.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// change12 dialog

class change12 : public CDialog
{
// Construction
public:
	change12(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(change12)
	enum { IDD = IDD_CHANGE12 };
	CString	m_bus_line12;
	CString	m_bus_station12;
	CString	m_bus_stationid12;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(change12)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(change12)
	afx_msg void OnChange();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGE12_H__0C116307_1989_4909_BAF1_FBE29CB5C533__INCLUDED_)
