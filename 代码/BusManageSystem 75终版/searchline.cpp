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
CDaoRecordset Record4(&db4);//��¼��
void searchline::OnSearchline() 
{
	// TODO: Add your control notification handler code here
	CString sql,a;
	CString path;
	path=".\\bus.mdb";
	db4.Open(path,0,0,NULL);
	int count_bus_line=0;//��¼line����station����
	COleVariant var;		// �ֶ�����
	int totol_line[200];//��������������е���·
	memset(totol_line,2,200);
	CString s1,s2,s3,temp,str,count,count1,tmp;
	int sum=0;//line����վ����������ں�count_bus_line�Ƚ�
	char bus[50][100];//��¼·�߲�ѯ���վ����Ϣ
	int bus_id[50];//վ��ID
	GetDlgItemText(IDC_EDIT1,a);
	if(db4.IsOpen () == FALSE )
	{
	MessageBox("δ�������ݿ⣡");
	return ;
	}
	Record4.Open(-1L,"SELECT * FROM BUS",NULL);
	while(!Record4.IsEOF())	// ��û�е����β
	{
		Record4.GetFieldValue("db_bus_line",var);   //��¼���е��ֶ�����
		s2 = (LPCSTR)var.pbstrVal;
		if(strcmp(s2,a)==0)//�Ƚ���ͬ�Ĺ�����·
		{
		count_bus_line++;
		}
		Record4.MoveNext();  //�ƶ�����һ����¼
	}
	Record4.Close () ;
	//�򿪼�¼��
	count.Format("%d",count_bus_line);
	if(a!=""&&a!="all")
	{
		str+=a;
		str+="·: ";
	Record4.Open(-1L,"SELECT * FROM BUS",NULL);
	while(!Record4.IsEOF())	// ��û�е����β
	{
		Record4.GetFieldValue("db_bus_station",var);   //��¼���е��ֶ�����
		s1 = (LPCSTR)var.pbstrVal;
		Record4.GetFieldValue("db_bus_line",var);   //��¼���е��ֶ�����
		s2 = (LPCSTR)var.pbstrVal;
		Record4.GetFieldValue("db_bus_stationid",var);   //��¼���е��ֶ�����
		s3 = (LPCSTR)var.pbstrVal;
		if(strcmp(s2,a)==0)//�Ƚ���ͬ�Ĺ�����·
		{
			sum++;
			if(sum==count_bus_line)
				temp.Format("%s  ",LPCSTR(s1));
			else
				temp.Format("%s-->",LPCSTR(s1));
			tmp+=temp;//���ÿ��վ�㵽�ַ���
			//memcpy(bus_id[sum],s3,s3.GetLength());
			//memcpy(bus[sum],s1,s1.GetLength());
			bus_id[sum]=atoi(s3);
			strcpy(bus[bus_id[sum]],s1);//����ID�����㷨
			//*bus[bus_id[sum]]=*s1;
		}
		Record4.MoveNext();  //�ƶ�����һ����¼
	}
		//str+=count;
		int k;//�����·�㷨
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
		count1.Format("\r\n�ܹ�����%dվ",sum);
		str+=count1;
		if(sum==0)
		{
			MessageBox("û���ҵ����·�ߣ�����");
		}
		//str+='\n';
		//m_edit2.SetSel(0,-1);
		//m_edit2.ReplaceSel(tmp,1);//�ڱ༭�������·
		m_edit2.SetSel(0,-1);
		m_edit2.ReplaceSel(str,1);//�ڱ༭�������·
		// �رռ�¼��
		Record4.Close () ;
		db4.Close();
	}else if(a!=""&&a=="all"){
		//db.Close();
		int bbb=0,l;
		CDaoDatabase db1;
		CDaoRecordset Record1(&db1);//��¼��
		CString path1;
		path1=".\\busline.mdb";
		db1.Open(path1,0,0,NULL);
		if(db1.IsOpen () == FALSE )
		{
		MessageBox("δ�������ݿ⣡");
		return ;
		}
		CString line,sline,tmp;
		Record1.Open(-1L,"SELECT * FROM BUSLINE",NULL);
		while(!Record1.IsEOF())	// ��û�е����β
		{
		Record1.GetFieldValue("bus_num",var);   //��¼���е��ֶ�����
		line = (LPCSTR)var.pbstrVal;
		totol_line[bbb]=atoi(line);
		bbb++;
		//tmp.Format("%s ·\r\n",line);
		//sline+=tmp;
		//sline+="\r\n";
		Record1.MoveNext();
		}//�ƶ�����һ����¼
		qsort(totol_line,bbb,sizeof(totol_line[0]),cmp1);
		CString tp;//��ʱ��
		for(l=0;l<bbb;l++)
		{
			if(totol_line[l]!=2)
			{
			tp.Format("%d\r\n",totol_line[l]);
			sline+=tp;
			}
		}
		m_edit2.SetSel(0,-1);
		m_edit2.ReplaceSel(sline,1);//�ڱ༭�����all��·
		Record1.Close () ;
		db1.Close();
	}else
	{
		MessageBox("���������ݣ�����");
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
           bmpBackground.LoadBitmap(IDB_BITMAP5);   //IDB_BITMAP�����Լ���ͼ��Ӧ��ID   �������Ҹոռ����λͼ��Դ 
                                                                             //������������IDB_Bg�������������bmpBackground.LoadBitmap(IDB_Bg);  
                  
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
