// StationandStation.cpp : implementation file
//

#include "stdafx.h"
#include "BusManageSystem.h"
#include "StationandStation.h"
#include "string.h"
#include "stdlib.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// StationandStation dialog


StationandStation::StationandStation(CWnd* pParent /*=NULL*/)
	: CDialog(StationandStation::IDD, pParent)
{
	//{{AFX_DATA_INIT(StationandStation)
	//}}AFX_DATA_INIT
}


void StationandStation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(StationandStation)
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(StationandStation, CDialog)
	//{{AFX_MSG_MAP(StationandStation)
	ON_BN_CLICKED(IDC_STATIONANDSTATION, OnStationandstation)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// StationandStation message handlers
int cmp ( const void *a , const void *b )  
{  
return *(int *)a - *(int *)b;  
} 
CDaoDatabase db6;
CDaoRecordset Record6(&db6);//��¼��
void StationandStation::OnStationandstation() 
{
	// TODO: Add your control notification handler code here
	CString a,b,str;
	CString path;
	path=".\\bus.mdb";
	db6.Open(path,0,0,NULL);
	COleVariant var;		// �ֶ�����
	CString bus[50][30];//��¼·�߲�ѯ���վ����Ϣ
	CString bus_line1[50][50],bus_line2[50][50];//��¼���蹫������ѯ��ʼ�յ�ֿ��������ߵ�վ����Ϣ,������u,v
	char bus_station[50][30];//��¼վ����
	int bus_id1[50],bus_id2[50];//վ̨ID
	int zhi=0;//��¼�Ƿ�ֱ��1ֱ��0��תһ��
	CString line1[50],line2[50];//��¼����������ߵĳ���
	CString id1[50],id2[50];//վ��ID
	int minstation[50];//������վ������¼���������վ�����·��
	int k;
	for(k=0;k<50;k++)
	{
		minstation[k]=100;
	}
	int i=0,j=0;
	GetDlgItemText(IDC_EDIT1,a);
	GetDlgItemText(IDC_EDIT3,b);
	if(db6.IsOpen () == FALSE )
	{
	MessageBox("δ�������ݿ⣡");
	return ;
	}
	//�򿪼�¼��
	CString s1,s2,s3;
	int line1_count=0;
	int line2_count=0;//��ʼ���������·����
	CString line_common[50];//����
	int line_common_count=0;
	CString id_common1[50],id_common2[50];
	if(a!=""&&b!="")
	{//////////////ֱ���㷨��ʼ///////////////////////
		Record6.Open(-1L,"SELECT * FROM BUS",NULL);//��¼��ѯ��ʼ����յ����·�Լ�վ��ID�����Ƿ���ֱ����ж�
	    while(!Record6.IsEOF())	// ��û�е����β
	{
		Record6.GetFieldValue("db_bus_line",var);   //��¼���е��ֶ�����
		s1 = (LPCSTR)var.pbstrVal;
		Record6.GetFieldValue("db_bus_station",var);   //��¼���е��ֶ�����
		s2 = (LPCSTR)var.pbstrVal;
		Record6.GetFieldValue("db_bus_stationid",var);   //��¼���е��ֶ�����
		s3 = (LPCSTR)var.pbstrVal;
		if(s2==a)
		{
			line1_count++;
			line1[line1_count]=s1;
			id1[line1_count]=s3;//�������Щ���ߵ���Щ��ID
		}
		if(s2==b)
		{
			line2_count++;
			line2[line2_count]=s1;
			id2[line2_count]=s3;//�յ�����Щ���ߵ���Щ��ID
		}
		Record6.MoveNext();  //�ƶ�����һ����¼
	}
		for(i=1;i<=line1_count;i++)//�ж��Ƿ�ֱ��
			for(j=1;j<=line2_count;j++)
				if(line1[i]==line2[j]&&atoi(id2[j])>=atoi(id1[i]))//or id2>id1?
				{
					zhi=1;
					line_common_count++;
					line_common[line_common_count]=line1[i];
					id_common1[line_common_count]=id1[i];
					id_common2[line_common_count]=id2[j];
					minstation[line_common_count]=atoi(id2[j])-atoi(id1[i]);
				}
	Record6.Close () ;
	CString ttt;//��ʱ��
	CString ttt1,ttt2;//��ʱ��
	int sss=0;
	if(zhi==1)
	{
	ttt1.Format(" ֱ�ﳵ�ι���%d�Σ�",line_common_count);
	str+=ttt1;
	for(i=1;i<=line_common_count;i++)
	{
	ttt1.Format(" \r\n%s·��",line_common[i]);
	str+=ttt1;
	Record6.Open(-1L,"SELECT * FROM BUS",NULL);
	while(!Record6.IsEOF())	// ��û�е����β
	{
		Record6.GetFieldValue("db_bus_line",var);   //��¼���е��ֶ�����
		s1 = (LPCSTR)var.pbstrVal;
		Record6.GetFieldValue("db_bus_station",var);   //��¼���е��ֶ�����
		s2 = (LPCSTR)var.pbstrVal;
		Record6.GetFieldValue("db_bus_stationid",var);   //��¼���е��ֶ�����
		s3 = (LPCSTR)var.pbstrVal;
		if(s1==line_common[i]&&atoi(s3)>=atoi(id_common1[i])&&atoi(s3)<=atoi(id_common2[i]))//�ҳ�·��
		{
			if(s3==id_common2[i])
			{
				ttt1.Format(" %s",s2);
				str+=ttt1;
			}
			else
			{
				ttt1.Format(" %s -->",s2);
				str+=ttt1;
			}
		}
		Record6.MoveNext();  //�ƶ�����һ����¼
	}
			ttt2.Format("\r\n������%dվ",(atoi(id_common2[i])-atoi(id_common1[i])));
			str+=ttt2;
		Record6.Close () ;
	}
	
	qsort(minstation,line_common_count,sizeof(minstation[1]),cmp);//���·��
	if(minstation[0]==100)
	{
	}else
	{
	ttt2.Format("  \r\n  ****��������վ��Ϊ%dվ****",minstation[0]);
	str+=ttt2;
	}
	}
	else//else zhi==0
	{
	ttt2.Format("  \r\n  ****û��ֱ�ﳵ��****");
	str+=ttt2;
	////////////////////////��תһ���㷨��ʼ/////////////////////////////////////
	int p1=1,p2=1,q1=1,q2=1,station1_count[50],station2_count[50];//����
	CString bus_line1id[50][50],bus_line2id[50][50];//U,V������վ��ID
	while((p1<=line1_count)||(p2<=line2_count))
	{
		Record6.Open(-1L,"SELECT * FROM BUS",NULL);
	while(!Record6.IsEOF())	// ��û�е����β
	{
		Record6.GetFieldValue("db_bus_line",var);   //��¼���е��ֶ�����
		s1 = (LPCSTR)var.pbstrVal;
		Record6.GetFieldValue("db_bus_station",var);   //��¼���е��ֶ�����
		s2 = (LPCSTR)var.pbstrVal;
		Record6.GetFieldValue("db_bus_stationid",var);   //��¼���е��ֶ�����
		s3 = (LPCSTR)var.pbstrVal;
		if(zhi==0)//��תһ�ε��������U,V
		{
			if(s1==line1[p1]&&p1<=line1_count)
			{
				bus_line1[p1][q1]=s2;
				bus_line1id[p1][q1]=s3;
				q1++;
			}
			if(s1==line2[p2]&&p2<=line2_count)
			{
				bus_line2[p2][q2]=s2;
				bus_line2id[p2][q2]=s3;
				q2++;
			}
		}
		Record6.MoveNext();  //�ƶ�����һ����¼
	}
	station1_count[p1]=q1-1;
	station2_count[p2]=q2-1;//��¼ÿ���ߵ�վ̨����
	q1=1;//��Ҫ���¼���
	q2=1;//��Ҫ���¼���
	p1++;
	p2++;
		Record6.Close();//�������°Ѽ�¼����ָ��ָ���һ����¼
	}
//		CString ww;//���Խ������
// 		for(int op=1;op<=line2_count;op++)
// 		{
// 			ww.Format("%d ",station2_count[op]);
// 			str+=ww;
// 		}
		
		int station_commonp1[500],station_commonq1[500],station_commonp2[500],station_commonq2[500];//�����������е�λ��
		int ssss=0,ssss_count;//��¼�������
		CString bus_zhuan[500];//�����תվ��
		bus_zhuan[0].Format("��תվ");
//		int bb,gg=0;//һ������һ������Ƿ񽻵��ظ�
		int pl=1;//�Ż���ⷽ����־��
		for(p1=1;p1<=line1_count;p1++)
		{
			for(q1=1;q1<=station1_count[p1];q1++)
			{
				pl=1;
				for(p2=1;p2<=line2_count;p2++)
				{
					for(q2=1;q2<=station2_count[p2];q2++)
					{
						if(strcmp(bus_line1[p1][q1],bus_line2[p2][q2])==0&&bus_line1id[p1][q1]>=id1[p1]&&bus_line2id[p2][q2]<=id2[p2])//�󽻼�
						{
							ssss++;
							bus_zhuan[ssss]=bus_line1[p1][q1];
							station_commonp1[ssss]=p1;
							station_commonq1[ssss]=q1;
							station_commonp2[ssss]=p2;
							station_commonq2[ssss]=q2;
							pl=0;
						}
						if(pl==0)
							break;
					}//end for q2
					if(pl==0)
						break;
				}//end for p2
	
			}//end for q1
		
		}//end for p1
		ssss_count=ssss;
  		CString ww;//���Խ������
		for(p1=1;p1<=ssss_count;p1++)
		{
		ww.Format("%s",bus_zhuan[p1]);
		str+=ww;
		}
		ww.Format("%d",ssss_count);
		str+=ww;
		/*CString gongjiao1[50][50],gongjiao2[50][50];
		int gongjiaoid1[50],gongjiaoid2[50];
		int yy=1;
		while(yy<=ssss_count)
		{
		Record6.Open(-1L,"SELECT * FROM BUS",NULL);
	    while(!Record6.IsEOF())	// ��û�е����β
		{
		Record6.GetFieldValue("db_bus_line",var);   
		s1 = (LPCSTR)var.pbstrVal;
		Record6.GetFieldValue("db_bus_station",var);   
		s2 = (LPCSTR)var.pbstrVal;
		Record6.GetFieldValue("db_bus_stationid",var);  
		s3 = (LPCSTR)var.pbstrVal;
		if(s1==line1[station_commonp1[yy]]&&s3>=id1[station_commonp1[yy]])
		{
			gongjiao1[yy][atoi(s3)]=s2;
			gongjiaoid1[yy]=atoi(s3);
		}
		if(s1==line2[station_commonp2[yy]]&&s3<=id2[station_commonp2[yy]])
		{
			gongjiao2[yy][atoi(s3)]=s2;
			gongjiaoid2[yy]=atoi(s3);
		}
		yy++;
		Record6.MoveNext();  //�ƶ�����һ����¼
		}
		db6.Close();
		}
		for(p1=1;p1<yy;p1++)
			for(p2=1;p2<(atoi(id2[station_commonp1[p1]])-gongjiaoid2[p1]+atoi(id1[station_commonp1[p1]])-gongjiaoid1[p1]);p2++)
				str+=gongjiao1[p1][q1];
		for(p1=1;p1<yy;p1++)
			for(p2=1;p2<id2[station_commonp2[p1]];p2++)
				str+=gongjiao2[p1][q1];*/
	}//end of else zhi==0
		m_edit2.SetSel(0,-1);
		m_edit2.ReplaceSel(str,1);//�ڱ༭�������·
	}else//else for a,b==""
	{
		MessageBox("���������ݣ�����");
	}
	db6.Close();
}

void StationandStation::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect   rect;   
           GetClientRect(&rect);   
           CDC   dcMem;   
           dcMem.CreateCompatibleDC(&dc);   
           CBitmap   bmpBackground;   
           bmpBackground.LoadBitmap(IDB_BITMAP6);   //IDB_BITMAP�����Լ���ͼ��Ӧ��ID   �������Ҹոռ����λͼ��Դ 
                                                                             //������������IDB_Bg�������������bmpBackground.LoadBitmap(IDB_Bg);  
                  
           BITMAP   bitmap;   
           bmpBackground.GetBitmap(&bitmap);   
           CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
           dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH StationandStation::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
