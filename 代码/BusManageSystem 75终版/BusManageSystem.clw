; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=StationandStation
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BusManageSystem.h"

ClassCount=8
Class1=CBusManageSystemApp
Class2=CBusManageSystemDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_STATIONANDSTATION
Resource2=IDR_MAINFRAME
Resource3=IDD_BUSMANAGESYSTEM_DIALOG
Resource4=IDD_SEARCHSTATION
Resource5=IDD_INFORMATION
Resource6=IDD_SEARCHLINE
Class4=information
Class5=searchline
Class6=searchstation
Class7=StationandStation
Resource7=IDD_ABOUTBOX
Class8=change12
Resource8=IDD_CHANGE12

[CLS:CBusManageSystemApp]
Type=0
HeaderFile=BusManageSystem.h
ImplementationFile=BusManageSystem.cpp
Filter=N

[CLS:CBusManageSystemDlg]
Type=0
HeaderFile=BusManageSystemDlg.h
ImplementationFile=BusManageSystemDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_ABOUT

[CLS:CAboutDlg]
Type=0
HeaderFile=BusManageSystemDlg.h
ImplementationFile=BusManageSystemDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_BUSMANAGESYSTEM_DIALOG]
Type=1
Class=CBusManageSystemDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308353
Control2=IDC_INFORMATION,button,1342275584
Control3=IDC_SEARTHONLINE,button,1342275584
Control4=IDC_SEARCHONSTATION,button,1342275584
Control5=IDC_STATIONANDSTATION,button,1342275584
Control6=IDC_ABOUT,button,1342275584
Control7=IDCANCEL,button,1342275584

[DLG:IDD_INFORMATION]
Type=1
Class=information
ControlCount=13
Control1=IDC_STATIC,static,1342308353
Control2=IDCANCEL,button,1342275584
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT3,edit,1350631552
Control10=IDC_EDIT2,edit,1350631552
Control11=IDC_ADD,button,1342242816
Control12=IDC_DEL,button,1342242816
Control13=IDC_CHANGE,button,1342242816

[DLG:IDD_SEARCHLINE]
Type=1
Class=searchline
ControlCount=7
Control1=65535,static,1342308353
Control2=IDCANCEL,button,1342275584
Control3=65535,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_SEARCHLINE,button,1342275584
Control6=65535,static,1342308352
Control7=IDC_EDIT2,edit,1352728580

[DLG:IDD_SEARCHSTATION]
Type=1
Class=searchstation
ControlCount=7
Control1=65535,static,1342308353
Control2=IDCANCEL,button,1342275584
Control3=65535,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_SEEK,button,1342275584
Control6=65535,static,1342308352
Control7=IDC_EDIT2,edit,1352728580

[DLG:IDD_STATIONANDSTATION]
Type=1
Class=StationandStation
ControlCount=9
Control1=65535,static,1342308353
Control2=IDCANCEL,button,1342275584
Control3=65535,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIONANDSTATION,button,1342275584
Control6=65535,static,1342308352
Control7=IDC_EDIT2,edit,1352728580
Control8=65535,static,1342308352
Control9=IDC_EDIT3,edit,1350631552

[CLS:information]
Type=0
HeaderFile=information.h
ImplementationFile=information.cpp
BaseClass=CDialog
Filter=D
LastObject=information
VirtualFilter=dWC

[CLS:searchline]
Type=0
HeaderFile=searchline.h
ImplementationFile=searchline.cpp
BaseClass=CDialog
Filter=D
LastObject=searchline
VirtualFilter=dWC

[CLS:searchstation]
Type=0
HeaderFile=searchstation.h
ImplementationFile=searchstation.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT2
VirtualFilter=dWC

[CLS:StationandStation]
Type=0
HeaderFile=StationandStation.h
ImplementationFile=StationandStation.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=65535

[DLG:IDD_CHANGE12]
Type=1
Class=change12
ControlCount=9
Control1=IDC_STATIC,static,1342308353
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT3,edit,1350631552
Control7=IDC_EDIT2,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CHANGE,button,1342242816

[CLS:change12]
Type=0
HeaderFile=change12.h
ImplementationFile=change12.cpp
BaseClass=CDialog
Filter=D
LastObject=change12
VirtualFilter=dWC

