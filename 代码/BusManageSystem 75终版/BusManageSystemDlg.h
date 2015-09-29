// BusManageSystemDlg.h : header file
//

#if !defined(AFX_BUSMANAGESYSTEMDLG_H__09368410_50B8_4F3B_8D13_5533D1FC8A83__INCLUDED_)
#define AFX_BUSMANAGESYSTEMDLG_H__09368410_50B8_4F3B_8D13_5533D1FC8A83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBusManageSystemDlg dialog

class CBusManageSystemDlg : public CDialog
{
// Construction
public:
	CBusManageSystemDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBusManageSystemDlg)
	enum { IDD = IDD_BUSMANAGESYSTEM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBusManageSystemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBusManageSystemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInformation();
	afx_msg void OnSearthonline();
	afx_msg void OnSearchonstation();
	afx_msg void OnStationandstation();
	afx_msg void OnAbout();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUSMANAGESYSTEMDLG_H__09368410_50B8_4F3B_8D13_5533D1FC8A83__INCLUDED_)
