#define _CRT_SECURE_NO_DEPRECATE
#include<WINSOCK2.H> //socketͷ�ļ� 
#include<STDIO.H>  
#include<iostream>  
#include<cstring>  
#include<map>
#include <string>
#include<WS2tcpip.h>
using namespace std;
#pragma comment(lib, "ws2_32.lib")//����socket 
using namespace std;
const int PORT = 8000;
#define MaxBufSize 1024
#define _CRT_SECURE_NO_WARINGS

#include"adminForm.h"
#include"userForm.h"
#include"clientForm.h"
using namespace systemClient;


int main(){
	mysql_query(&mysql, "set names gbk");
	sql.ConnectDatabase();
	//sql.QueryDatabase1();
	sprintf(query, "SELECT licensePlate, userName, passwd from userInfo");
	mysql_query(&mysql, "set names gbk"); 
	mysql_query(&mysql, query);     
	if (!(res = mysql_store_result(&mysql))){}
	char *str_field[32];  
	for (int i = 0; i<3; i++)   
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	while (column = mysql_fetch_row(res))   
	{
		plsql.insert(make_pair(column[0], column[2]));
	}
	//cout << plsql.size() << endl;
	Application::EnableVisualStyles();
	Application::Run(gcnew clientForm());
	//sql.QueryDatabase1();
	cout << "��¼�ɹ�����ѡ����" << endl;


	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET SocketClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN  ClientAddr;

	ClientAddr.sin_family = AF_INET;
	ClientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ClientAddr.sin_port = htons(PORT);
	int n = 0;
	n = connect(SocketClient, (struct sockaddr*)&ClientAddr, sizeof(ClientAddr));
	if (n == SOCKET_ERROR){
		cout << "����ʧ��" << endl;
		return -1;
	}
		//cout << "�Ѿ����ӵ��������������������������Ϣ�ˣ�" << endl;
	char info[1024], SendBuff[MaxBufSize], RecvBuff[MaxBufSize];
	while (1){
		char* mess;
	
		if (show == 1)
		{
			//�û�����
			Application::EnableVisualStyles();
			Application::Run(gcnew userForm());		
		}
		if (show == 2)
		{
			//����Ա����
			Application::EnableVisualStyles();
			Application::Run(gcnew adminForm());
		}
		if (index == 1){
			mess = "ȡ��";
		}if (index == 2){
			mess = "ͣ��";
		}if (index == 3){
			mess = "��ѯ���ݿ�";
		}if (index == 4){
			mess = "��ѯС��״̬";
		}if (index == 5){
			mess = "ɾ���û���Ϣ";
		}if (index == 6){
			mess = "��ѯ��λ״̬";
		}if (index == 7){
			mess = "��ѯ���״̬";
		}if (index == 8){
			mess = "չʾͣ����";
		}if (index == 9){
			mess = "��ѯС��λ��";
		}if (index == 10){
			mess = "�����û���Ϣ";
		}if (index == 11){
			mess = "�޸��û���Ϣ";
		}
		
	
		strcpy(SendBuff, mess);
		
		memset(info, 0, sizeof(info));
		int k = 0;
		n = send(SocketClient, SendBuff, sizeof(SendBuff), 0);
		memset(SendBuff, 0, sizeof(SendBuff));
		if (k<0){
			cout << "����ʧ��" << endl;
		}
		Sleep(500);
		int n = 0;
		n = recv(SocketClient, RecvBuff, sizeof(RecvBuff), 0);
		if (n>0){
			cout << RecvBuff << endl;
		}
		memset(RecvBuff, 0, sizeof(RecvBuff));
	}
	closesocket(SocketClient);
	WSACleanup();
	return 0;
}


