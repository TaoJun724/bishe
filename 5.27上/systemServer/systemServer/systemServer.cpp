#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARINGS
#define UNREFERENCED_VALUE(P)          (P)

#include<queue>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<winsock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include <string.h>
#include"corrd.hpp"
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
#include"showCarStatusForm.h"
#include"showRoadStatusForm.h"
#include"showCarRoteForm.h"
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

Coord coord;
AMGraph<char, int> parkingA;
AMGraph<char, int> parkingB;
string license;//输入的车牌号
vector<int> minDistance;//选择最近车位(排序）
vector<int> minPark;//停靠排序
vector<int> minCar;//取车排序选择最近的小车
Road taskSpace;
string aparkstr;

int aFree = 0;
int aNum;
int cFree = 0;
int APARKIndex;
int aParkRet;
int bFree = 0;
int bNum;
int caraSize;
int aSpacesize;
int cSpacesize;
int aParkNum;
int bSpacesize;
int aParksize2;
int aParksize1;
int aElesize;
int aLineSize;
int bLineSize;
int bParksize;
int bElesize;
int carbSize;
int location = 0;//以此判断选择哪个停车场
int chooseRet = 0;//选择停车场结果索引/取车时判定车位
int minIndex = 0;//最近车位索引判断在那个车位区域
int task;//选择停车/取车任务
int workcar;//空闲小车的索引
int minspace = 999;//判断在那个车位区域 起中间判定作用
int min;//获取最近车位在图中的输入次序
int leavePosi;//代表小车离开时的车位
int leaveStat;//代表小车接到任务时所在位置的属性
int lineindex = 0;//代表行使中线路索引
int parkindex;//停靠索引
int pickIndex;//取车索引
int aParkindex;
int verNum; int startB; int* dist; int *path;
int verNumA; int startA; int* dist7; int *path7;
[STAThread]


//服务线程
DWORD WINAPI ServerThread(LPVOID lpParameter){

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
		}else if ((strcmp(revData, "查询小车状态") == 0))
		{
			showCarStatusForm showcarstatus;
			showcarstatus.find();
			showcarstatus.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "查询小车状态需求已处理\n", sizeof(sendData), 0);
		}else if ((strcmp(revData, "查询小车位置") == 0))
		{
			Application::EnableVisualStyles();
			Application::Run(gcnew showCarRoteForm());
			send(*ClientSocket, "查询小车位置需求已被处理\n", sizeof(sendData), 0);
		}

		///待完成///	
		 else if (strcmp(revData, "取车") == 0)
		 {
			 send(*ClientSocket, "取车功能待实现\n", sizeof(sendData), 0);
		 }
		 else if (strcmp(revData, "停车") == 0)
		 {
			 send(*ClientSocket, "停车功能待实现\n", sizeof(sendData), 0);
		 }else if ((strcmp(revData, "查询数据库") == 0)){
			 sql.QueryDatabase1();
			 send(*ClientSocket, "查询数据库需求已处理\n", sizeof(sendData), 0);
		 }
		 else if ((strcmp(revData, "展示停车场") == 0)){
			 m.show();
			 send(*ClientSocket, "展示停车场需求已处理\n", sizeof(sendData), 0);
		 }		
	    ////////
		else{
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
	coord.InitParkingAPoint(parkingA, aPoint);
	coord.InitParkingAEdge(parkingA, aPoint);
	coord.InitParkingBPoint(parkingB, bPoint);
	coord.InitParkingBEdge(parkingB, bPoint);
	coord.SpaceA(aSpace);//A停车场车位   
	coord.SpaceC(cSpace);//公共车位
	coord.SpaceB(bSpace);//B停车场车位
	coord.ParkA2(aPark2);//A停靠2 
	coord.ParkA1(aPark1);//A停靠1
	coord.EleA(aEle);//A充电
	coord.LineA(aLine);//A线路
	coord.CarA(carVectA);//A小车录入
	coord.LineB(bLine);//B线路
	coord.ParkB(bPark);//B停靠 
	coord.EleB(bEle);//B充电
	coord.CarB(carVectB);//B小车录入
	caraSize = carVectA.size();
	aSpacesize = aSpace.size();
	cSpacesize = cSpace.size();
	aParkNum = (aSpacesize + cSpacesize) / 2;
	bSpacesize = bSpace.size();
    aParksize2 = aPark2.size();
	aParksize1 = aPark1.size();
	aElesize = aEle.size();
	aLineSize = aLine.size();
	bLineSize = bLine.size();
	bParksize = bPark.size();
	bElesize = bEle.size();
	carbSize = carVectB.size();
	//////////修改B小车停靠位的状态////////
	for (int i = 0; i < bParksize; i++)
	{
		for (int j = 0; j < carbSize; j++)
		{
			if (strcmp(bPark[i].index0.c_str(), carVectB[j].position.c_str()) == 0)
			{
				bPark[i].status = true;
				carVectB[j].change(bPark[i].x, bPark[i].y, bPark[i].length, bPark[i].wide);
			}
		}
	}

	//////////修改A小车停靠位的状态////////
	for (int i = 0; i < aParksize1; i++)
	{
		for (int j = 0; j < caraSize; j++)
		{
			if (strcmp(aPark1[i].index0.c_str(), carVectA[j].position.c_str()) == 0)
			{
				aPark1[i].status = true;
				carVectA[j].change(aPark1[i].x, aPark1[i].y, aPark1[i].length, aPark1[i].wide);
			}
		}
	}

	for (int i = 0; i < aParksize2; i++)
	{
		for (int j = 0; j < caraSize; j++)
		{
			if (strcmp(aPark2[i].index0.c_str(), carVectA[j].position.c_str()) == 0)
			{
				aPark2[i].status = true;
				carVectA[j].change(aPark2[i].x, aPark2[i].y, aPark2[i].length, aPark2[i].wide);
			}
		}
	}
	///////////////////////////////
	/////////////////对于B停车场以出口为终点使用DIJKSTRA算法////////////////////////////
	verNum = parkingB.getVertexNumber(), startB = parkingB.strgetIndex0("R57"),
		dist = new int[verNum],
		path = new int[verNum];
	parkingB.dijkstra(startB, dist, path);

	for (int i = 0; i < bSpacesize; i++)
	{
		bSpace[i].distance_B = dist[parkingB.strgetIndex0(bSpace[i].index0.c_str())];
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		cSpace[i].distance_B = dist[parkingB.strgetIndex0(cSpace[i].index0.c_str())];
	}
	/////////////////////////////////////////////////////////////////////////////////////
	/////////////////对于A停车场以出口为终点使用DIJKSTRA算法////////////////////////////
	verNumA = parkingA.getVertexNumber(), startA = parkingA.strgetIndex0("R00"),
		dist7 = new int[verNumA],
		path7 = new int[verNumA];
	parkingA.dijkstra(startA, dist7, path7);

	for (int i = 0; i < aSpacesize; i++)
	{
		aSpace[i].distance_A = dist7[parkingA.strgetIndex0(aSpace[i].index0.c_str())];
	}

	for (int i = 0; i < cSpacesize; i++)
	{
		cSpace[i].distance_A = dist7[parkingA.strgetIndex0(cSpace[i].index0.c_str())];
	}
	/////////////////////////////////////////////////////////////////////////////////////

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

