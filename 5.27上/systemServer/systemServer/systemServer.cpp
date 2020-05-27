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
string license;//����ĳ��ƺ�
vector<int> minDistance;//ѡ�������λ(����
vector<int> minPark;//ͣ������
vector<int> minCar;//ȡ������ѡ�������С��
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
int location = 0;//�Դ��ж�ѡ���ĸ�ͣ����
int chooseRet = 0;//ѡ��ͣ�����������/ȡ��ʱ�ж���λ
int minIndex = 0;//�����λ�����ж����Ǹ���λ����
int task;//ѡ��ͣ��/ȡ������
int workcar;//����С��������
int minspace = 999;//�ж����Ǹ���λ���� ���м��ж�����
int min;//��ȡ�����λ��ͼ�е��������
int leavePosi;//����С���뿪ʱ�ĳ�λ
int leaveStat;//����С���ӵ�����ʱ����λ�õ�����
int lineindex = 0;//������ʹ����·����
int parkindex;//ͣ������
int pickIndex;//ȡ������
int aParkindex;
int verNum; int startB; int* dist; int *path;
int verNumA; int startA; int* dist7; int *path7;
[STAThread]


//�����߳�
DWORD WINAPI ServerThread(LPVOID lpParameter){

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
		}else if ((strcmp(revData, "��ѯС��״̬") == 0))
		{
			showCarStatusForm showcarstatus;
			showcarstatus.find();
			showcarstatus.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "��ѯС��״̬�����Ѵ���\n", sizeof(sendData), 0);
		}else if ((strcmp(revData, "��ѯС��λ��") == 0))
		{
			Application::EnableVisualStyles();
			Application::Run(gcnew showCarRoteForm());
			send(*ClientSocket, "��ѯС��λ�������ѱ�����\n", sizeof(sendData), 0);
		}

		///�����///	
		 else if (strcmp(revData, "ȡ��") == 0)
		 {
			 send(*ClientSocket, "ȡ�����ܴ�ʵ��\n", sizeof(sendData), 0);
		 }
		 else if (strcmp(revData, "ͣ��") == 0)
		 {
			 send(*ClientSocket, "ͣ�����ܴ�ʵ��\n", sizeof(sendData), 0);
		 }else if ((strcmp(revData, "��ѯ���ݿ�") == 0)){
			 sql.QueryDatabase1();
			 send(*ClientSocket, "��ѯ���ݿ������Ѵ���\n", sizeof(sendData), 0);
		 }
		 else if ((strcmp(revData, "չʾͣ����") == 0)){
			 m.show();
			 send(*ClientSocket, "չʾͣ���������Ѵ���\n", sizeof(sendData), 0);
		 }		
	    ////////
		else{
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
	coord.InitParkingAPoint(parkingA, aPoint);
	coord.InitParkingAEdge(parkingA, aPoint);
	coord.InitParkingBPoint(parkingB, bPoint);
	coord.InitParkingBEdge(parkingB, bPoint);
	coord.SpaceA(aSpace);//Aͣ������λ   
	coord.SpaceC(cSpace);//������λ
	coord.SpaceB(bSpace);//Bͣ������λ
	coord.ParkA2(aPark2);//Aͣ��2 
	coord.ParkA1(aPark1);//Aͣ��1
	coord.EleA(aEle);//A���
	coord.LineA(aLine);//A��·
	coord.CarA(carVectA);//AС��¼��
	coord.LineB(bLine);//B��·
	coord.ParkB(bPark);//Bͣ�� 
	coord.EleB(bEle);//B���
	coord.CarB(carVectB);//BС��¼��
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
	//////////�޸�BС��ͣ��λ��״̬////////
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

	//////////�޸�AС��ͣ��λ��״̬////////
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
	/////////////////����Bͣ�����Գ���Ϊ�յ�ʹ��DIJKSTRA�㷨////////////////////////////
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
	/////////////////����Aͣ�����Գ���Ϊ�յ�ʹ��DIJKSTRA�㷨////////////////////////////
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

