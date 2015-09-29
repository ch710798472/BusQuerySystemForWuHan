// change12.cpp : implementation file
//

#include "stdafx.h"
#include "BusManageSystem.h"
#include "change12.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// change12 dialog


change12::change12(CWnd* pParent /*=NULL*/)
	: CDialog(change12::IDD, pParent)
{
	//{{AFX_DATA_INIT(change12)
	m_bus_line12 = _T("");
	m_bus_station12 = _T("");
	m_bus_stationid12 = _T("");
	//}}AFX_DATA_INIT
}


void change12::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(change12)
	DDX_Text(pDX, IDC_EDIT1, m_bus_line12);
	DDX_Text(pDX, IDC_EDIT2, m_bus_station12);
	DDX_Text(pDX, IDC_EDIT3, m_bus_stationid12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(change12, CDialog)
	//{{AFX_MSG_MAP(change12)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// change12 message handlers
CDaoDatabase db2;
CDaoRecordset Record2(&db2);
void change12::OnChange() 
{
	// TODO: Add your control notification handler code here
	CString sql,a,b,c;
	CString path;
	path=".\\bus.mdb";
	db2.Open(path,0,0,NULL);
	GetDlgItemText(IDC_EDIT1,a);
	GetDlgItemText(IDC_EDIT2,b);
	GetDlgItemText(IDC_EDIT3,c);
	if(db2.IsOpen () == FALSE )
	{
	MessageBox("δ�������ݿ⣡");
	return ;
	}
	if(a!=""&&b!=""&&c!="")
	{
	Record2.Open(-1L,"SELECT * FROM BUS",NULL);
	// ʹ��CDaoRecordset::AddNew��������Ҫ��ʼ����¼�¼
	Record2.AddNew () ;
	// �����¼�¼
	Record2.SetFieldValue("db_bus_line",LPCTSTR(a));
	Record2.SetFieldValue("db_bus_station",LPCTSTR(b));
	Record2.SetFieldValue("db_bus_stationid",LPCTSTR(c));
	// ֻ����ִ��CDaoRecordset::Update������Ż�д�뵽���ݿ�
	Record2.Update () ;
	}else
	{
		MessageBox("���������ݣ�����");
	}
	// �رռ�¼��
	MessageBox("�޸����ݳɹ�������");
	Record2.Close () ;
	db2.Close();
}


HBRUSH change12::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void change12::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect   rect;   
           GetClientRect(&rect);   
           CDC   dcMem;   
           dcMem.CreateCompatibleDC(&dc);   
           CBitmap   bmpBackground;   
           bmpBackground.LoadBitmap(IDB_BITMAP5);   //IDB_BITMAP�����Լ���ͼ��Ӧ��ID   �������Ҹոռ����λͼ��Դ 
                                                                             //������������IDB_Bg�������������bmpBackground.LoadBitmap(IDB_Bg);  
                  
           BITMAP   bitmap;   
           bmpBackground.GetBitmap(&bitmap);   
           CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
           dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}
