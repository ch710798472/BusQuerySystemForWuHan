#if !defined(AFX_STATIONANDSTATION_H__13AEBF36_942E_4B7F_B771_DFB28720DD11__INCLUDED_)
#define AFX_STATIONANDSTATION_H__13AEBF36_942E_4B7F_B771_DFB28720DD11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StationandStation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// StationandStation dialog

class StationandStation : public CDialog
{
// Construction
public:
	StationandStation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(StationandStation)
	enum { IDD = IDD_STATIONANDSTATION };
	CEdit	m_edit2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(StationandStation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(StationandStation)
	afx_msg void OnStationandstation();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATIONANDSTATION_H__13AEBF36_942E_4B7F_B771_DFB28720DD11__INCLUDED_)
