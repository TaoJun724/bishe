#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARINGS
#define UNREFERENCED_VALUE(P)          (P)

#include<stdio.h>
#include<winsock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include <string.h>
#include"Comm.hpp"
#include "amgraph.h"
#include"parkingMember.hpp"
#include"parkingOperator.hpp"
#include"CMysqlOperator.hpp"
#include"insertDataBaseForm.h"
#include"functEndForm.h"
#include"deletebaseForm.h"
#include"startForm.h"
#include"modiftyDataForm.h"
#include "serverForm.h"
#include"showSpaceStatusForm.h"
#include"showRoadStatusForm.h"
#pragma comment(lib,"ws2_32.lib")

using namespace systemServer;
using namespace std;
using namespace itlab;

#define MaxClient 10
#define MaxBufSize 1024
#define BOUNDS_CHECK
const int PORT = 8000;
char sendData[MaxBufSize];

Manage m;
map<string, string> plsql;
[STAThread]


//�����߳�
DWORD WINAPI ServerThread(LPVOID lpParameter){
	string licensestr;
	//	m.initParking();
	mysql_query(&mysql, "set names gbk");
	sql.ConnectDatabase();
	sprintf(query, "SELECT licensePlate, userName, passwd from userInfo"); 
	mysql_query(&mysql, "set names gbk"); 
	//����0 ��ѯ�ɹ�������1��ѯʧ��
	mysql_query(&mysql, query);      //ִ��SQL���
	//��ȡ�����
	if (!(res = mysql_store_result(&mysql))){}
	//��ȡ�ֶε���Ϣ
	char *str_field[32];  //����һ���ַ�������洢�ֶ���Ϣ
	for (int i = 0; i<3; i++)   //����֪�ֶ�����������»�ȡ�ֶ���
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	//��ӡ��ȡ������
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
		plsql.insert(make_pair(column[0], column[2]));
	}

	SOCKET *ClientSocket = (SOCKET*)lpParameter;
	int receByt = 0;
	char revData[MaxBufSize];
	//char sendData[MaxBufSize];
	while (1){
		receByt = recv(*ClientSocket, revData, sizeof(revData), 0);
		if (receByt>0){
			cout << "���յ�����Ϣ�ǣ�" << revData << "            ���Կͻ���:" << *ClientSocket << endl;
		}else{
			cout << "������Ϣ������" << endl;
			break;
		}
		//�������ݸ��ͻ���
		//	char sendData[1024];

	   if (strcmp(revData, "ɾ���û���Ϣ") == 0){
		Application::EnableVisualStyles();
		Application::Run(gcnew deletebaseForm());
		send(*ClientSocket, "ɾ���û���Ϣ�����Ѿ�����\n", sizeof(sendData), 0);
     	}else if ((strcmp(revData, "�����û���Ϣ") == 0)){
		   Application::EnableVisualStyles();
		   Application::Run(gcnew insertDataBaseForm());
		   send(*ClientSocket, "�����û���Ϣ�����Ѵ���\n", sizeof(sendData), 0);
	   }
		else if ((strcmp(revData, "�޸��û���Ϣ") == 0)){
			Application::EnableVisualStyles();
			Application::Run(gcnew modiftyDataForm());
			send(*ClientSocket, "�޸��û���Ϣ�����Ѵ���\n", sizeof(sendData), 0);
		}else if ((strcmp(revData, "��ѯ��λ״̬") == 0)){
			int free = 0; int busy = 0;
			free = m.findParkingSpaceStatusFree();
			busy = m.findParkingSpaceStatusBusy();
			showSpaceStatusForm showSpace;
			showSpace.find(free, busy);
			showSpace.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "��ѯ��λ״̬�����Ѵ���\n", sizeof(sendData), 0);
		}else if ((strcmp(revData, "��ѯ���״̬") == 0))
		{
			int free = 0; int busy = 0;
			free = m.findRoadStatusFree();
			busy = m.findRoadStatusBusy();
			showRoadStatusForm showRoad;
			showRoad.find(free, busy);
			showRoad.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "��ѯ���״̬�����Ѵ���\n", sizeof(sendData), 0);
		}

		///�����
		 else if ((strcmp(revData, "��ѯС��λ��") == 0))
		 {
			 send(*ClientSocket, "��ѯС��λ�ô����\n", sizeof(sendData), 0);
		 }
		 else if (strcmp(revData, "ȡ��") == 0)
		 {
			 send(*ClientSocket, "ȡ�����ܴ�ʵ��\n", sizeof(sendData), 0);
		 }
		 else if (strcmp(revData, "ͣ��") == 0)
		 {
			 send(*ClientSocket, "ͣ�����ܴ�ʵ��\n", sizeof(sendData), 0);
		 }		
		else if ((strcmp(revData, "��ѯС��״̬") == 0))
		{
			int noWork = m.findAgvCarStatus();
			send(*ClientSocket, "��ѯС��״̬�����Ѵ���\n", sizeof(sendData), 0);
		}
	    //�����
		else if ((strcmp(revData, "��ѯ���ݿ�") == 0)){
			sql.QueryDatabase1();
			send(*ClientSocket, "��ѯ���ݿ������Ѵ���\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "չʾͣ����") == 0)){
			m.show();
			send(*ClientSocket, "չʾͣ���������Ѵ���\n", sizeof(sendData), 0);
		}else{
			send(*ClientSocket, "��Ч����\n", sizeof(sendData), 0);
		}
	}
	closesocket(*ClientSocket);
	free(ClientSocket);
	return 0;
}



int main(){
	Application::EnableVisualStyles();
	Application::Run(gcnew startForm());

	m.initParking();
	WSAData wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ListenAddr;
	ListenAddr.sin_family = AF_INET;
	ListenAddr.sin_addr.S_un.S_addr = INADDR_ANY;//��ʾ���뱾��ip
	ListenAddr.sin_port = htons(PORT);
	int n;
	n = bind(ListenSocket, (LPSOCKADDR)&ListenAddr, sizeof(ListenAddr));
	if (n == SOCKET_ERROR){
		cout << "�˿ڰ�ʧ�ܣ�" << endl;
		return -1;
	}
	else{
		cout << "�˿ڰ󶨳ɹ���" << PORT << endl;
	}
	int l = listen(ListenSocket, 20);
	cout << "�����׼���������ȴ���������" << endl;

	while (1){
		//ѭ�����տͻ����������󲢴��������߳�
		SOCKET *ClientSocket = new SOCKET;
		ClientSocket = (SOCKET*)malloc(sizeof(SOCKET));
		//���տͻ�����������
		int SockAddrlen = sizeof(sockaddr);
		*ClientSocket = accept(ListenSocket, 0, 0);	
		cout << "һ���ͻ��������ӵ���������socket�ǣ�" << *ClientSocket << endl;

		int  sockindex = *ClientSocket;
		serverForm serverform;
		serverform.change(sockindex);
		serverform.Show();
		Application::EnableVisualStyles();		
		Application::Run(gcnew startForm());

		CreateThread(NULL, 0, &ServerThread, ClientSocket, 0, NULL);
	}//while
	closesocket(ListenSocket);
	WSACleanup();
	system("pause");
	return(0);
}//main

