// searchline.cpp : implementation file
//

#include "stdafx.h"
#include "BusManageSystem.h"
#include "searchline.h"
#include "string.h"
#include "stdlib.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// searchline dialog


searchline::searchline(CWnd* pParent /*=NULL*/)
	: CDialog(searchline::IDD, pParent)
{
	//{{AFX_DATA_INIT(searchline)
	//}}AFX_DATA_INIT
}


void searchline::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(searchline)
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(searchline, CDialog)
	//{{AFX_MSG_MAP(searchline)
	ON_BN_CLICKED(IDC_SEARCHLINE, OnSearchline)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// searchline message handlers
int cmp1 ( const void *a , const void *b )  
{  
return *(int *)a - *(int *)b;  
}
CDaoDatabase db4;
CDaoRecordset Record4(&db4);//记录集
void searchline::OnSearchline() 
{
	// TODO: Add your control notification handler code here
	CString sql,a;
	CString path;
	path=".\\bus.mdb";
	db4.Open(path,0,0,NULL);
	int count_bus_line=0;//记录line里面station条数
	COleVariant var;		// 字段类型
	int totol_line[200];//用于排序输出所有的线路
	memset(totol_line,2,200);
	CString s1,s2,s3,temp,str,count,count1,tmp;
	int sum=0;//line里面站点个数，用于和count_bus_line比较
	char bus[50][100];//记录路线查询结果站点信息
	int bus_id[50];//站点ID
	GetDlgItemText(IDC_EDIT1,a);
	if(db4.IsOpen () == FALSE )
	{
	MessageBox("未连接数据库！");
	return ;
	}
	Record4.Open(-1L,"SELECT * FROM BUS",NULL);
	while(!Record4.IsEOF())	// 有没有到表结尾
	{
		Record4.GetFieldValue("db_bus_line",var);   //记录集中的字段数量
		s2 = (LPCSTR)var.pbstrVal;
		if(strcmp(s2,a)==0)//比较相同的公交线路
		{
		count_bus_line++;
		}
		Record4.MoveNext();  //移动到下一条记录
	}
	Record4.Close () ;
	//打开记录集
	count.Format("%d",count_bus_line);
	if(a!=""&&a!="all")
	{
		str+=a;
		str+="路: ";
	Record4.Open(-1L,"SELECT * FROM BUS",NULL);
	while(!Record4.IsEOF())	// 有没有到表结尾
	{
		Record4.GetFieldValue("db_bus_station",var);   //记录集中的字段数量
		s1 = (LPCSTR)var.pbstrVal;
		Record4.GetFieldValue("db_bus_line",var);   //记录集中的字段数量
		s2 = (LPCSTR)var.pbstrVal;
		Record4.GetFieldValue("db_bus_stationid",var);   //记录集中的字段数量
		s3 = (LPCSTR)var.pbstrVal;
		if(strcmp(s2,a)==0)//比较相同的公交线路
		{
			sum++;
			if(sum==count_bus_line)
				temp.Format("%s  ",LPCSTR(s1));
			else
				temp.Format("%s-->",LPCSTR(s1));
			tmp+=temp;//添加每个站点到字符串
			//memcpy(bus_id[sum],s3,s3.GetLength());
			//memcpy(bus[sum],s1,s1.GetLength());
			bus_id[sum]=atoi(s3);
			strcpy(bus[bus_id[sum]],s1);//基于ID排序算法
			//*bus[bus_id[sum]]=*s1;
		}
		Record4.MoveNext();  //移动到下一条记录
	}
		//str+=count;
		int k;//输出线路算法
		for(k=1;k<=sum;k++)
		{
			
			if(k!=sum)
			{
				str+=bus[k];
				temp.Format(" --> ");
				str+=temp;
			}else
			{
				str+=bus[k];
			}
		}
		count1.Format("\r\n总共经过%d站",sum);
		str+=count1;
		if(sum==0)
		{
			MessageBox("没有找到相关路线！！！");
		}
		//str+='\n';
		//m_edit2.SetSel(0,-1);
		//m_edit2.ReplaceSel(tmp,1);//在编辑框输出线路
		m_edit2.SetSel(0,-1);
		m_edit2.ReplaceSel(str,1);//在编辑框输出线路
		// 关闭记录集
		Record4.Close () ;
		db4.Close();
	}else if(a!=""&&a=="all"){
		//db.Close();
		int bbb=0,l;
		CDaoDatabase db1;
		CDaoRecordset Record1(&db1);//记录集
		CString path1;
		path1=".\\busline.mdb";
		db1.Open(path1,0,0,NULL);
		if(db1.IsOpen () == FALSE )
		{
		MessageBox("未连接数据库！");
		return ;
		}
		CString line,sline,tmp;
		Record1.Open(-1L,"SELECT * FROM BUSLINE",NULL);
		while(!Record1.IsEOF())	// 有没有到表结尾
		{
		Record1.GetFieldValue("bus_num",var);   //记录集中的字段数量
		line = (LPCSTR)var.pbstrVal;
		totol_line[bbb]=atoi(line);
		bbb++;
		//tmp.Format("%s 路\r\n",line);
		//sline+=tmp;
		//sline+="\r\n";
		Record1.MoveNext();
		}//移动到下一条记录
		qsort(totol_line,bbb,sizeof(totol_line[0]),cmp1);
		CString tp;//临时用
		for(l=0;l<bbb;l++)
		{
			if(totol_line[l]!=2)
			{
			tp.Format("%d\r\n",totol_line[l]);
			sline+=tp;
			}
		}
		m_edit2.SetSel(0,-1);
		m_edit2.ReplaceSel(sline,1);//在编辑框输出all线路
		Record1.Close () ;
		db1.Close();
	}else
	{
		MessageBox("请输入数据！！！");
	}
}

void searchline::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void searchline::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
	OnOK();
}

void searchline::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect   rect;   
           GetClientRect(&rect);   
           CDC   dcMem;   
           dcMem.CreateCompatibleDC(&dc);   
           CBitmap   bmpBackground;   
           bmpBackground.LoadBitmap(IDB_BITMAP5);   //IDB_BITMAP是你自己的图对应的ID   ，由于我刚刚加入的位图资源 
                                                                             //被我命名成了IDB_Bg，因而我这句就是bmpBackground.LoadBitmap(IDB_Bg);  
                  
           BITMAP   bitmap;   
           bmpBackground.GetBitmap(&bitmap);   
           CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
           dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH searchline::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
