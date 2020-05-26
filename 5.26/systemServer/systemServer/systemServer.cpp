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


//服务线程
DWORD WINAPI ServerThread(LPVOID lpParameter){
	string licensestr;
	//	m.initParking();
	mysql_query(&mysql, "set names gbk");
	sql.ConnectDatabase();
	sprintf(query, "SELECT licensePlate, userName, passwd from userInfo"); 
	mysql_query(&mysql, "set names gbk"); 
	//返回0 查询成功，返回1查询失败
	mysql_query(&mysql, query);      //执行SQL语句
	//获取结果集
	if (!(res = mysql_store_result(&mysql))){}
	//获取字段的信息
	char *str_field[32];  //定义一个字符串数组存储字段信息
	for (int i = 0; i<3; i++)   //在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
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
			cout << "接收到的消息是：" << revData << "            来自客户端:" << *ClientSocket << endl;
		}else{
			cout << "接收消息结束！" << endl;
			break;
		}
		//发送数据给客户端
		//	char sendData[1024];

	   if (strcmp(revData, "删除用户信息") == 0){
		Application::EnableVisualStyles();
		Application::Run(gcnew deletebaseForm());
		send(*ClientSocket, "删除用户信息需求已经处理\n", sizeof(sendData), 0);
     	}else if ((strcmp(revData, "插入用户信息") == 0)){
		   Application::EnableVisualStyles();
		   Application::Run(gcnew insertDataBaseForm());
		   send(*ClientSocket, "插入用户信息需求已处理\n", sizeof(sendData), 0);
	   }
		else if ((strcmp(revData, "修改用户信息") == 0)){
			Application::EnableVisualStyles();
			Application::Run(gcnew modiftyDataForm());
			send(*ClientSocket, "修改用户信息需求已处理\n", sizeof(sendData), 0);
		}else if ((strcmp(revData, "查询车位状态") == 0)){
			int free = 0; int busy = 0;
			free = m.findParkingSpaceStatusFree();
			busy = m.findParkingSpaceStatusBusy();
			showSpaceStatusForm showSpace;
			showSpace.find(free, busy);
			showSpace.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "查询车位状态需求已处理\n", sizeof(sendData), 0);
		}else if ((strcmp(revData, "查询便道状态") == 0))
		{
			int free = 0; int busy = 0;
			free = m.findRoadStatusFree();
			busy = m.findRoadStatusBusy();
			showRoadStatusForm showRoad;
			showRoad.find(free, busy);
			showRoad.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "查询便道状态需求已处理\n", sizeof(sendData), 0);
		}

		///待完成
		 else if ((strcmp(revData, "查询小车位置") == 0))
		 {
			 send(*ClientSocket, "查询小车位置待完成\n", sizeof(sendData), 0);
		 }
		 else if (strcmp(revData, "取车") == 0)
		 {
			 send(*ClientSocket, "取车功能待实现\n", sizeof(sendData), 0);
		 }
		 else if (strcmp(revData, "停车") == 0)
		 {
			 send(*ClientSocket, "停车功能待实现\n", sizeof(sendData), 0);
		 }		
		else if ((strcmp(revData, "查询小车状态") == 0))
		{
			int noWork = m.findAgvCarStatus();
			send(*ClientSocket, "查询小车状态需求已处理\n", sizeof(sendData), 0);
		}
	    //待完成
		else if ((strcmp(revData, "查询数据库") == 0)){
			sql.QueryDatabase1();
			send(*ClientSocket, "查询数据库需求已处理\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "展示停车场") == 0)){
			m.show();
			send(*ClientSocket, "展示停车场需求已处理\n", sizeof(sendData), 0);
		}else{
			send(*ClientSocket, "无效操作\n", sizeof(sendData), 0);
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
	ListenAddr.sin_addr.S_un.S_addr = INADDR_ANY;//表示填入本机ip
	ListenAddr.sin_port = htons(PORT);
	int n;
	n = bind(ListenSocket, (LPSOCKADDR)&ListenAddr, sizeof(ListenAddr));
	if (n == SOCKET_ERROR){
		cout << "端口绑定失败！" << endl;
		return -1;
	}
	else{
		cout << "端口绑定成功：" << PORT << endl;
	}
	int l = listen(ListenSocket, 20);
	cout << "服务端准备就绪，等待连接请求" << endl;

	while (1){
		//循环接收客户端连接请求并创建服务线程
		SOCKET *ClientSocket = new SOCKET;
		ClientSocket = (SOCKET*)malloc(sizeof(SOCKET));
		//接收客户端连接请求
		int SockAddrlen = sizeof(sockaddr);
		*ClientSocket = accept(ListenSocket, 0, 0);	
		cout << "一个客户端已连接到服务器，socket是：" << *ClientSocket << endl;

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

