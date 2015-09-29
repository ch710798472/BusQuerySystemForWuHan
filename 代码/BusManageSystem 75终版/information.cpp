// information.cpp : implementation file
//

#include "stdafx.h"
#include "BusManageSystem.h"
#include "information.h"
#include "change12.h"
#include "BusManageSystemDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "afxdao.h"

/////////////////////////////////////////////////////////////////////////////
// information dialog

information::information(CWnd* pParent /*=NULL*/)
	: CDialog(information::IDD, pParent)
{
	//{{AFX_DATA_INIT(information)
	m_bus_line1 = _T("");
	m_bus_station1 = _T("");
	m_bus_stationid1 = _T("");
	//}}AFX_DATA_INIT
}


void information::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(information)
	DDX_Text(pDX, IDC_EDIT1, m_bus_line1);
	DDX_Text(pDX, IDC_EDIT2, m_bus_station1);
	DDX_Text(pDX, IDC_EDIT3, m_bus_stationid1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(information, CDialog)
	//{{AFX_MSG_MAP(information)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_EN_CHANGE(IDC_EDIT1, OnEditBusLine)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// information message handlers

CDaoDatabase db3;
CDaoRecordset Record3(&db3);//记录集
void information::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString sql,a,b,c;
	CString s1,s2,s3;
	COleVariant var;
	CString path;
	path=".\\bus.mdb";
	db3.Open(path,0,0,NULL);
	//sql=L"insert into bus values(999,\'dsfd\',999)";
	//db.Execute(sql);
	GetDlgItemText(IDC_EDIT1,a);
	GetDlgItemText(IDC_EDIT2,b);
	GetDlgItemText(IDC_EDIT3,c);
	if(db3.IsOpen () == FALSE )
	{
	MessageBox("未连接数据库！");
	return ;
	}
	//sql.Format("insert into bus(db_bus_line,db_bus_station,db_bus_stationid) values('%s','%s','%s')",a,b,c);
	//sql="insert into bus(db_bus_line,db_bus_station,db_bus_stationid) values('"+a+"','"+b+"','"+c+"')";
	//db.Execute(sql);
	//打开记录集
	//暂时不支持重复插入相同数据
	if(a!=""&&b!=""&&c!="")
	{
	Record3.Open(-1L,"SELECT * FROM BUS",NULL);
	while(!Record3.IsEOF())	// 有没有到表结尾
		{
			Record3.GetFieldValue("db_bus_line",var);   //记录集中的字段数量
			s1 = (LPCSTR)var.pbstrVal;
			Record3.GetFieldValue("db_bus_station",var);   //记录集中的字段数量
			s2 = (LPCSTR)var.pbstrVal;
			Record3.GetFieldValue("db_bus_stationid",var);   //记录集中的字段数量
			s3 = (LPCSTR)var.pbstrVal;
			if(s1==a&&s2==b&&s3==c)
				break; 
			Record3.MoveNext();  //移动到下一条记录
		}
		 if(s1==a&&s2==b&&s3==c)
		 {
           MessageBox("您输入了重复数据!");
		 } 
		 else
		 {
	// 使用CDaoRecordset::AddNew函数表明要开始添加新记录
	Record3.AddNew () ;
	// 设置新记录
	Record3.SetFieldValue("db_bus_line",LPCTSTR(a));
	Record3.SetFieldValue("db_bus_station",LPCTSTR(b));
	Record3.SetFieldValue("db_bus_stationid",LPCTSTR(c));
	// 只有在执行CDaoRecordset::Update函数后才会写入到数据库
	Record3.Update () ;
	MessageBox("添加数据成功！！！");
		 }
	}else
	{
		MessageBox("请输入数据！！！");
	}
	// 关闭记录集
	Record3.Close () ;
	db3.Close();
}

void information::OnEditBusLine() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void information::OnDel() 
{
	// TODO: Add your control notification handler code here
	CString sql,a,b,c;
	CString path;
	path=".\\bus.mdb";
	db3.Open(path,0,0,NULL);
	COleVariant var;		// 字段类型
	GetDlgItemText(IDC_EDIT1,a);
	GetDlgItemText(IDC_EDIT2,b);
	GetDlgItemText(IDC_EDIT3,c);
	if(db3.IsOpen () == FALSE )
	{
	MessageBox("未连接数据库！");
	return ;
	}
	//打开记录集
	CString s1,s2,s3;
	int rep=0;
	if(a!=""&&b!=""&&c!="")
	{
	Record3.Open(-1L,"SELECT * FROM BUS",NULL);
	while(!Record3.IsEOF())	// 有没有到表结尾
	{
		Record3.GetFieldValue("db_bus_line",var);   //记录集中的字段数量
		s1 = (LPCSTR)var.pbstrVal;
		Record3.GetFieldValue("db_bus_station",var);   //记录集中的字段数量
		s2 = (LPCSTR)var.pbstrVal;
		Record3.GetFieldValue("db_bus_stationid",var);   //记录集中的字段数量
		s3 = (LPCSTR)var.pbstrVal;
		if(s1==a&&s2==b&&s3==c)
		{
			Record3.Delete();  //删除 
			rep++;
		}
		Record3.MoveNext();  //移动到下一条记录
	}
	// 关闭记录集
	Record3.Close () ;
	if(rep==0)
	{
		MessageBox("未找到要删除的数据！！！");
	}else{
		MessageBox("删除数据成功！！！");
	}
	}else if(a!=""&&b==""&c=="")
	{
	Record3.Open(-1L,"SELECT * FROM BUS",NULL);
	while(!Record3.IsEOF())	// 有没有到表结尾
	{
		Record3.GetFieldValue("db_bus_line",var);   //记录集中的字段数量
		s1 = (LPCSTR)var.pbstrVal;
		Record3.GetFieldValue("db_bus_station",var);   //记录集中的字段数量
		s2 = (LPCSTR)var.pbstrVal;
		Record3.GetFieldValue("db_bus_stationid",var);   //记录集中的字段数量
		s3 = (LPCSTR)var.pbstrVal;
		if(s1==a)
			Record3.Delete();  //删除 
		Record3.MoveNext();  //移动到下一条记录
	}
		Record3.Close();
		CDaoDatabase db10;
		CDaoRecordset Record10(&db10);//记录集
		CString path10;
		path10=".\\busline.mdb";
		db10.Open(path10,0,0,NULL);
		if(db10.IsOpen () == FALSE )
		{
		MessageBox("未连接数据库！");
		return ;
		}
		Record10.Open(-1L,"SELECT * FROM BUSLINE",NULL);
		while(!Record10.IsEOF())	// 有没有到表结尾
		{
		Record10.GetFieldValue("bus_num",var);   //记录集中的字段数量
		s1 = (LPCSTR)var.pbstrVal;
		if(s1==a)
			Record10.Delete();  //删除 
		Record10.MoveNext();  //移动到下一条记录
		}
	Record10.Close();
	db10.Close();
	MessageBox("删除线路成功！！！");
	}
	else
	{
		MessageBox("请输入数据！！！");
	}
	db3.Close();
}

void information::OnChange() 
{
	// TODO: Add your control notification handler code here
	CString sql,a,b,c;
	CString path;
	path=".\\bus.mdb";
	db3.Open(path,0,0,NULL);
	COleVariant var;		// 字段类型
	GetDlgItemText(IDC_EDIT1,a);
	GetDlgItemText(IDC_EDIT2,b);
	GetDlgItemText(IDC_EDIT3,c);
	if(db3.IsOpen () == FALSE )
	{
	MessageBox("未连接数据库！");
	return ;

	}

	//打开记录集
	CString s1,s2,s3;
	int fg=1;
	if(a!=""&&b!=""&&c!="")
	{
	Record3.Open(-1L,"SELECT * FROM BUS",NULL);
	 while(!Record3.IsEOF())	// 有没有到表结尾
	 {
		Record3.GetFieldValue("db_bus_line",var);   //记录集中的字段数量
		s1 = (LPCSTR)var.pbstrVal;
		Record3.GetFieldValue("db_bus_station",var);   //记录集中的字段数量
		s2 = (LPCSTR)var.pbstrVal;
		Record3.GetFieldValue("db_bus_stationid",var);   //记录集中的字段数量
		s3 = (LPCSTR)var.pbstrVal;
		if(s1==a&&s2==b&&s3==c)
		{
			//Record3.Delete();  //删除 
			del_a=a;
			del_b=b;
			del_c=c;
			fg=0;
		}
		Record3.MoveNext();  //移动到下一条记录
	 }
	// 关闭记录集
	Record3.Close () ;
	db3.Close();
	  if(!fg)
	  {
		change12 change;
		change.DoModal();
	  }else
	  {
		MessageBox("输入数据不存在！！！");
	  }
	}else
	{
		MessageBox("请输入数据！！！");
		Record3.Close () ;
	 db3.Close();
	}
}

void information::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void information::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect   rect;   
	GetClientRect(&rect);   
	CDC   dcMem;   
	dcMem.CreateCompatibleDC(&dc);   
	CBitmap   bmpBackground;   
	bmpBackground.LoadBitmap(IDB_BITMAP2);   //IDB_BITMAP是你自己的图对应的ID   ，由于我刚刚加入的位图资源 
	//被我命名成了IDB_Bg，因而我这句就是bmpBackground.LoadBitmap(IDB_Bg);  
	
	BITMAP   bitmap;   
	bmpBackground.GetBitmap(&bitmap);   
	CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
		bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH information::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
