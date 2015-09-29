// searchstation.cpp : implementation file
//

#include "stdafx.h"
#include "BusManageSystem.h"
#include "searchstation.h"
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// searchstation dialog


searchstation::searchstation(CWnd* pParent /*=NULL*/)
	: CDialog(searchstation::IDD, pParent)
{
	//{{AFX_DATA_INIT(searchstation)
	//}}AFX_DATA_INIT
}


void searchstation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(searchstation)
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(searchstation, CDialog)
	//{{AFX_MSG_MAP(searchstation)
	ON_BN_CLICKED(IDC_SEEK, OnSeek)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// searchstation message handlers
CDaoDatabase db5;
CDaoRecordset Record5(&db5);//记录集
void searchstation::OnSeek() 
{
	// TODO: Add your control notification handler code here
	CString a,s1,s2,str,str1,temp;
	CString path;
    int biaozhiwei=1;       //标志位
	int flg=0;
	path=".\\bus.mdb";
	db5.Open(path,0,0,NULL);
	COleVariant var;                       //字段类型
	GetDlgItemText(IDC_EDIT1,a);
	if(db5.IsOpen () == FALSE )
	{
	MessageBox("未连接数据库！");
	return ;
	}

	if(a!="")
	{
		flg=0;
	   str1.Format("该站点名称是：%s \r\n经过的路线有：\r\n",a);
	    
	   Record5.Open(-1L,"SELECT * FROM BUS",NULL);
	   while(!Record5.IsEOF())	// 有没有到表结尾
	   {
		Record5.GetFieldValue("db_bus_line",var);   //记录集中的字段数量
		s1 = (LPCSTR)var.pbstrVal;
		Record5.GetFieldValue("db_bus_station",var);   //记录集中的字段数量
		s2 = (LPCSTR)var.pbstrVal;
		 if(s2==a)
		 {
			temp.Format("%s \r\n",s1);
			str+=temp;
			flg=1;
		 }
		Record5.MoveNext();  //移动到下一条记录
	
	   }
	 str1+=str;
	 Record5.Close();
	  if (flg==1)
	  {
	  m_edit2.SetSel(0,-1);
	  m_edit2.ReplaceSel(str1,1);//在编辑框输出线路	  
	  }
	  else if(flg==0)
	  {	
		  CString s="未找到您查找的站点! 您要查找的站点是不是：\r\n",look="",look2="";
		  CString sn="未找到与输入站点相匹配的信息!";
		  CString bustation[250];
		//  int i=0;
		  //添加模糊搜索的代码TODO
          Record5.Open(-1L,"SELECT * FROM BUS",NULL);
		 
		  
		  while(!Record5.IsEOF())	// 有没有到表结尾
		  {
			  Record5.GetFieldValue("db_bus_line",var);   //记录集中的字段数量
		      s1 = (LPCSTR)var.pbstrVal;
			  Record5.GetFieldValue("db_bus_station",var);   //记录集中的字段数量
	        	s2 = (LPCSTR)var.pbstrVal;
			  char* s3= s2.GetBuffer(s2.GetLength()+1); 
		//	  char *s4=a.GetBuffer(a.GetLength()+1); 
			  
					if(strstr(s3,a)!=NULL)
					{
						biaozhiwei=0;
						look.Format("%s:%s \r\n",s1,s2);
					//	bustation[i]=look;
					//	i++;
						look2+=look;
					}
				Record5.MoveNext();  //移动到下一条记录
		  }
	//	  for (int j=0;j<i-1;j++)
	//	  {
      //     s+=bustation[i];
	//	  }
		  s+=look2;
           Record5.Close () ;
		  if (biaozhiwei==0)
		   {
			   m_edit2.SetSel(0,-1);
		       m_edit2.ReplaceSel(s,1);
		   }
		   else{
		   m_edit2.SetSel(0,-1);
		   m_edit2.ReplaceSel(sn,1);
		   }

	  }
	}else if(a=="")
	{
	MessageBox("请输入数据！！！");
	Record5.Close () ;
	}
	 db5.Close();
}

void searchstation::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect   rect;   
           GetClientRect(&rect);   
           CDC   dcMem;   
           dcMem.CreateCompatibleDC(&dc);   
           CBitmap   bmpBackground;   
           bmpBackground.LoadBitmap(IDB_BITMAP5);   
                  
           BITMAP   bitmap;   
           bmpBackground.GetBitmap(&bitmap);   
           CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
           dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH searchstation::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
if (pWnd->GetDlgCtrlID()==IDC_EDIT2)
{
	pDC->SetTextColor(RGB(255,0,0));
}


	if(nCtlColor == CTLCOLOR_STATIC)
    {
         pDC->SetBkMode(TRANSPARENT);   
        return   (HBRUSH)::GetStockObject(NULL_BRUSH);   
    }
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
