#if !defined(AFX_SEARCHSTATION_H__2844DC3F_6D32_4910_9976_F175EC462F32__INCLUDED_)
#define AFX_SEARCHSTATION_H__2844DC3F_6D32_4910_9976_F175EC462F32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// searchstation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// searchstation dialog

class searchstation : public CDialog
{
// Construction
public:
	searchstation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(searchstation)
	enum { IDD = IDD_SEARCHSTATION };
	CEdit	m_edit2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(searchstation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(searchstation)
	afx_msg void OnSeek();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHSTATION_H__2844DC3F_6D32_4910_9976_F175EC462F32__INCLUDED_)
