// BusManageSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BusManageSystem.h"
#include "BusManageSystemDlg.h"
#include "information.h"
#include "searchline.h"
#include "searchstation.h"
#include "StationandStation.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBusManageSystemDlg dialog

CBusManageSystemDlg::CBusManageSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBusManageSystemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBusManageSystemDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBusManageSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBusManageSystemDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBusManageSystemDlg, CDialog)
	//{{AFX_MSG_MAP(CBusManageSystemDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFORMATION, OnInformation)
	ON_BN_CLICKED(IDC_SEARTHONLINE, OnSearthonline)
	ON_BN_CLICKED(IDC_SEARCHONSTATION, OnSearchonstation)
	ON_BN_CLICKED(IDC_STATIONANDSTATION, OnStationandstation)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBusManageSystemDlg message handlers
//extern CDaoDatabase db;
BOOL CBusManageSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	/*CString path;
	path=".\\bus.mdb";
	db.Open(path,0,0,NULL);*/
	//sql=L"insert into bus values(999,\'dsfd\',999)";
	//db.Execute(sql);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBusManageSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBusManageSystemDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialog::OnPaint();//Ҫ��ֹ�������   
		CPaintDC   dc(this);   
		CRect   rect;   
		GetClientRect(&rect);   
		CDC   dcMem;   
		dcMem.CreateCompatibleDC(&dc);   
		CBitmap   bmpBackground;   
		bmpBackground.LoadBitmap(IDB_BITMAP1);    
		
		BITMAP   bitmap;   
		bmpBackground.GetBitmap(&bitmap);   
		CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBusManageSystemDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBusManageSystemDlg::OnInformation() 
{
	// TODO: Add your control notification handler code here
	information dlg;
	dlg. DoModal();
}

void CBusManageSystemDlg::OnSearthonline() 
{
	// TODO: Add your control notification handler code here
	searchline dlg;
    dlg.DoModal();
}

void CBusManageSystemDlg::OnSearchonstation() 
{
	// TODO: Add your control notification handler code here
	searchstation dlg;
	dlg.DoModal();
}

void CBusManageSystemDlg::OnStationandstation() 
{
	// TODO: Add your control notification handler code here
	StationandStation dlg;
	dlg.DoModal();
}

void CBusManageSystemDlg::OnAbout() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg about;
	about.DoModal();
}

HBRUSH CBusManageSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor == CTLCOLOR_STATIC)
    {
         pDC->SetBkMode(TRANSPARENT);   
        return   (HBRUSH)::GetStockObject(NULL_BRUSH);   
    }
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
