#if !defined(AFX_SEARCHLINE_H__069D385D_E207_40EC_9006_DB00182E02AE__INCLUDED_)
#define AFX_SEARCHLINE_H__069D385D_E207_40EC_9006_DB00182E02AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// searchline.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// searchline dialog

class searchline : public CDialog
{
// Construction
public:
	searchline(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(searchline)
	enum { IDD = IDD_SEARCHLINE };
	CEdit	m_edit2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(searchline)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(searchline)
	afx_msg void OnSearchline();
	afx_msg void OnChangeEdit1();
	virtual void OnCancel();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHLINE_H__069D385D_E207_40EC_9006_DB00182E02AE__INCLUDED_)
