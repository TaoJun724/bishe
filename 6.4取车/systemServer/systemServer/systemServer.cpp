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
#include"parkForm.h"
#include"sendForm.h"
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
vector<int> minDistance;//ѡ�������λ(����
vector<int> minPark;//ͣ������
vector<int> minCar;//ȡ������ѡ�������С��
Road taskSpace;
string aparkstr;


int aFree = 0;
int aNum = 0;
int cFree = 0;
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
int chooseRet = 0;//ѡ��ͣ�����������/ȡ��ʱ�ж���λ
int minIndex = 0;//�����λ�����ж����Ǹ���λ����
int task;//ѡ��ͣ��/ȡ������
int workcar;//����С��������
int minspace = 999;//�ж����Ǹ���λ���� ���м��ж�����
int leavePosi;//����С���뿪ʱ�ĳ�λ
int leaveStat;//����С���ӵ�����ʱ����λ�õ�����
int lineindex = 0;//������ʹ����·����
int parkindex;//ͣ������
int pickIndex;//ȡ������
int aParkindex;
int verNum; int startB; int* dist; int *path;
int verNumA; int startA; int* dist7; int *path7;

[STAThread]


void bParkProCar1()
{
	int work = 0;
	carVectB[work].status = true;//��״̬��Ϊʹ��
	carVectB[work].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
	carVectB[work].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
	//cout << "������С���±���" << carVectB[workcar].index << endl;
	//MessageBox::Show("����С�����±�Ϊ:" + carVectB[workcar].index);
	//ѡ������ĳ�λ
	while (1)
	{
		if (minDistance.size() == 0)
			break;
	};
	for (int i = 0; i < bSpacesize; i++)
	{
		if (bSpace[i].status == false)
			minDistance.push_back(bSpace[i].distance_B);
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if (cSpace[i].status == false)
			minDistance.push_back(cSpace[i].distance_B);
	}
	sort(minDistance.begin(), minDistance.end());
	//minspace = 999;
	//�ж������λ���ĸ�����
	for (int i = 0; i < bSpacesize; i++)
	{
		if ((minDistance[0] == bSpace[i].distance_B) && (bSpace[i].status == false))
		{
			//minspace = i;
			carVectB[work].carindex = i;
			bSpace[i].status = true;
			bSpace[i].license = license;
			carVectB[work].book(bSpace[i].x, bSpace[i].y);
			minIndex = 1;
			break;
		}
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if ((minDistance[0] == cSpace[i].distance_B) && (cSpace[i].status == false))
		{
			//minspace = i;
			carVectB[work].carindex = i;
			cSpace[i].status = true;
			cSpace[i].license = license;
			carVectB[work].book(cSpace[i].x, cSpace[i].y);
			minIndex = 2;
			break;
		}
	}

	minDistance.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��
	int minbp = 0;
	if (minIndex == 1)
		minbp = parkingB.strgetIndex0(bSpace[carVectB[work].carindex].index0.c_str());
	else if (minIndex == 2)
		minbp = parkingB.strgetIndex0(cSpace[carVectB[work].carindex].index0.c_str());
	//������ѡ��������λ
	//��ȡ���ڵ������λ��·��
	while (!carVectB[work].s1.empty())
		carVectB[work].s1.pop();
	carVectB[work].s1.push(parkingB.Print(minbp).index0);
	for (int j = path[minbp]; j != startB; j = path[j])
		carVectB[work].s1.push(parkingB.Print(j).index0);

	//��С����ǰλ��Ϊ�����㵽���ڵ����·��
	int leave = parkingB.strgetIndex0(carVectB[work].position.c_str());
	int *dist1 = new int[verNum];
	int *path1 = new int[verNum];
	parkingB.dijkstra(leave, dist1, path1);
	//��ȡС�������ڵ����·��
	while (!carVectB[work].s2.empty())
		carVectB[work].s2.pop();
	carVectB[work].s2.push(parkingB.Print(startB).index0);
	for (int j = path1[startB]; j != leave; j = path1[j])
		carVectB[work].s2.push(parkingB.Print(j).index0);

	cout << "С��" << carVectB[work].index << "��ʼ��ʹ" << endl;
	//��¼����С���뿪ʱ��λ��
	//1.С����ͣ�����ӵ�����
	for (int i = 0; i < bParksize; i++)
	{
		if (strcmp(bPark[i].index0.c_str(), carVectB[work].position.c_str()) == 0)
		{
			carVectB[work].ingChange(bPark[i].x, bPark[i].y, bPark[i].length, bPark[i].wide);
			bPark[i].status = false;
			leavePosi = i;
			leaveStat = 0;
		}
	}
	//2.С������·�нӵ�����
	for (int i = 0; i < bLineSize; i++)
	{
		if (strcmp(bLine[i].index0.c_str(), carVectB[work].position.c_str()) == 0)
		{
			carVectB[work].ingChange(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
			bLine[i].status = false;
			leavePosi = i;
			leaveStat = 1;
		}
	}
	//3.С���ӳ�����ӵ�����
	for (int i = 0; i < bElesize; i++)
	{
		if (strcmp(bEle[i].index0.c_str(), carVectB[work].position.c_str()) == 0)
		{
			carVectB[work].ingChange(bEle[i].x, bEle[i].y, bEle[i].length, bEle[i].wide);
			bEle[i].status = false;
			leavePosi = i;
			leaveStat = 2;
		}
	}

	//����С��ȥ���ڵĹ���
	carVectB[work].eleStatus = 1;
	carVectB[work].start = clock();
	while (carVectB[work].s2.size() != 0)
	{
		if (leaveStat == 0)
			carVectB[work].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
		if (leaveStat == 1)
			carVectB[work].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
		if (leaveStat == 2)
			carVectB[work].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);

		if (strcmp(carVectB[work].s2.top().c_str(), "R57") != 0)
		{
			for (int i = 0; i < bLineSize; i++)
			{
				if (strcmp(carVectB[work].s2.top().c_str(), bLine[i].index0.c_str()) == 0)
				{
					lineindex = i;
					if (bLine[i].status == false)
					{
						bLine[i].status = true;
						carVectB[work].position = carVectB[work].s2.top();
						////cout << carVectB[workcar].position << endl;
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						carVectB[work].position = carVectB[work].s2.top();
						////cout << carVectB[workcar].position << endl;											
						m.show();
					}
				}
			}
			carVectB[work].s2.pop();
			Sleep(2000);
			carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			bLine[lineindex].status = false;
		}
		else{
			if (leaveStat == 0)
				carVectB[work].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
			if (leaveStat == 1)
				carVectB[work].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
			if (leaveStat == 2)
				carVectB[work].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);
			Sleep(1000);
			carVectB[work].position = carVectB[work].s2.top();
			carVectB[work].s2.pop();
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	int tmp = carVectB[work].index;
	//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
	while (carVectB[work].s1.size() != 0)
	{
		if (strcmp(carVectB[work].s1.top().c_str(), parkingB.Print(minbp).index0.c_str()) != 0)
		{
			for (int i = 0; i < bLineSize; i++)
			{
				if (strcmp(carVectB[work].s1.top().c_str(), bLine[i].index0.c_str()) == 0)
				{
					carVectB[work].position = carVectB[work].s1.top();
					////cout << carVectB[workcar].position << endl;
					lineindex = i;
					if (bLine[i].status == false)
					{
						bLine[i].status = true;
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						m.show();
					}
				}
			}
			bLine[lineindex].status = false;
			carVectB[work].s1.pop();
			Sleep(2000);
			carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			cout << "С��" << carVectB[work].index << "��ʹ1��" << carVectB[work].s1.size() << endl;
		}
		else{
			Sleep(1000);
			carVectB[work].s1.pop();
			carVectB[work].change(parkingB.Print(minbp).x, parkingB.Print(minbp).y, parkingB.Print(minbp).length, parkingB.Print(minbp).wide);

			if (minIndex == 1)
				carVectB[work].occupy(bSpace[carVectB[work].carindex].x, bSpace[carVectB[work].carindex].y);
			if (minIndex == 2)
				carVectB[work].occupy(cSpace[carVectB[work].carindex].x, cSpace[carVectB[work].carindex].y);
			carVectB[work].carindex = 0;
			for (int i = 0; i < bLineSize; i++){
				if (strcmp(carVectB[work].position.c_str(), bLine[i].index0.c_str()) == 0)
				{
					carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
				}
			}
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			//cout << carVectB[workcar].eleNum << endl;
			if (carVectB[work].eleNum <= 25)
			{
				//������Ҫ��� �����Խ�����
				carVectB[work].eleFlag = 1;
				//ִ�г�����
				//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
				carVectB[work].eleStatus = 0;
				carVectB[work].start = clock();
			}
			else{
				carVectB[work].stop = 1;//��ʾ��Ҫͣ��
				carVectB[work].status = false;//��ʾ���Խ�����
				carVectB[work].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}


	//Bͣ��///////////////////////////////////////////////////////////////////////////////
	if (carVectB[work].stop == 1)
	{
		for (int b = 0; b < bElesize; b++)
		{
			if (strcmp(bEle[b].index0.c_str(), carVectB[work].position.c_str()) == 0)
			{
				carVectB[work].restoreEle(bEle[b].x, bEle[b].y, bEle[b].length, bEle[b].wide);
			}
		}
		for (int l = 0; l < bLineSize; l++){
			if (strcmp(carVectB[work].position.c_str(), bLine[l].index0.c_str()) == 0)
			{
				carVectB[work].restoreLine(bLine[l].x, bLine[l].y, bLine[l].length, bLine[l].wide);
			}
		}
		int park = parkingB.strgetIndex0(carVectB[work].position.c_str());
		int *dist2 = new int[verNum];
		int *path2 = new int[verNum];
		parkingB.dijkstra(park, dist2, path2);

		for (int j = 0; j < bParksize; j++)
		{
			bPark[j].distance_B = dist2[parkingB.strgetIndex0(bPark[j].index0.c_str())];
		}
		minPark.clear();
		for (int k = 0; k < bParksize; k++)
		{
			if (bPark[k].status == false)
			{
				minPark.push_back(bPark[k].distance_B);
			}
		}
		sort(minPark.begin(), minPark.end());
		//Ѱ������Ŀ���ͣ����
		for (int g = 0; g < bParksize; g++)
		{
			if (bPark[g].distance_B == minPark[0] && bPark[g].status == false)
			{
				parkindex = g;
				bPark[g].status = true;
				break;
			}

		}
		//�����ʱ����v
		minPark.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bPark[parkindex].index0.c_str());
		while (!carVectB[work].s3.empty())
			carVectB[work].s3.pop();
		carVectB[work].s3.push(bPark[parkindex].index0.c_str());
		for (int j = path2[minbp]; j != park; j = path2[j])
			carVectB[work].s3.push(parkingB.Print(j).index0.c_str());

		//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
		if (carVectB[work].stop == 0)
		{
			//˵�������㹻���Խ�������������е����ж�
			bPark[parkindex].status = false;
			while (!carVectB[work].s3.empty()){
				carVectB[work].s3.pop();
			}
			//break;
		}
		else{
			//����ִ��ͣ������
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//��s3���
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//ִ�г�����
				bPark[parkindex].status = false;
				carVectB[work].eleFlag = 1;
				carVectB[work].status = true;
				carVectB[work].start = clock();
				//break;
			}
		}

		carVectB[work].start = clock();
		carVectB[work].eleStatus = 1;
		///С��ȥ��ͣ������ִ��
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectB[work].s3.size() != 0)
		{
			//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
			if (carVectB[work].stop == 0)
			{
				bPark[parkindex].status = false;
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				break;
			}
			//��ȥͣ����;��ִ�е����ж�
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//��s3���
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//ִ�г�����
				bPark[parkindex].status = false;
				carVectB[work].eleFlag = 1;
				carVectB[work].status = true;
				carVectB[work].start = clock();
				break;
			}

			if (strcmp(carVectB[work].s3.top().c_str(), bPark[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < bLineSize; p++)
				{
					if (strcmp(carVectB[work].s3.top().c_str(), bLine[p].index0.c_str()) == 0)
					{
						carVectB[work].position = carVectB[work].s3.top().c_str();
						lineindex = p;
						if (bLine[p].status == false)
						{
							bLine[p].status = true;
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
					}
				}
				bLine[lineindex].status = false;
				carVectB[work].s3.pop();
				Sleep(2000);
				carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			}
			else{
				carVectB[work].position = carVectB[work].s3.top().c_str();
				carVectB[work].s3.pop();
				for (int b = 0; b < bParksize; b++)
				{
					if (strcmp(bPark[b].index0.c_str(), carVectB[work].position.c_str()) == 0)
					{

						carVectB[work].end = clock();
						carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
						if (carVectB[work].eleNum < 25)
						{
							//��s3���
							while (!carVectB[work].s3.empty())
								carVectB[work].s3.pop();
							//ִ�г�����
							bPark[parkindex].status = false;
							carVectB[work].status = true;
							carVectB[work].eleFlag = 1;
							carVectB[work].start = clock();
							break;
						}

						carVectB[work].change(bPark[b].x, bPark[b].y, bPark[b].length, bPark[b].wide);
						carVectB[work].start = clock();
						carVectB[work].eleStatus = 0;
						//m.show();
					}
				}

			}
		}
	}
	///////////B���////////////////////
	if (carVectB[work].eleFlag == 1)
	{
		//�жϴ���һ����ִ�г�����
		for (int o = 0; o < bParksize; o++)
		{
			if (strcmp(bPark[o].index0.c_str(), carVectB[work].position.c_str()) == 0)
			{
				carVectB[work].ingChange(bPark[o].x, bPark[o].y, bPark[o].length, bPark[o].wide);
				bPark[o].status = false;
				leavePosi = o;
				leaveStat = 0;
			}
		}
		//2.С������·�нӵ�
		for (int o = 0; o < bLineSize; o++)
		{
			if (strcmp(bLine[o].index0.c_str(), carVectB[work].position.c_str()) == 0)
			{
				carVectB[work].ingChange(bLine[o].x, bLine[o].y, bLine[o].length, bLine[o].wide);
				bLine[o].status = false;
				leavePosi = o;
				leaveStat = 1;
			}
		}
		int ele = parkingB.strgetIndex0(carVectB[work].position.c_str());
		int *dist6 = new int[verNum];
		int *path6 = new int[verNum];
		parkingB.dijkstra(ele, dist6, path6);

		for (int j = 0; j < bElesize; j++)
		{
			bEle[j].ele_Distance = dist6[parkingB.strgetIndex0(bEle[j].index0.c_str())];
		}
		for (int k = 0; k < bElesize; k++)
		{
			if (bEle[k].status == false)
			{
				minPark.push_back(bEle[k].ele_Distance);
			}
		}
		sort(minPark.begin(), minPark.end());
		//Ѱ������Ŀ��г���
		for (int g = 0; g < bElesize; g++)
		{
			if (bEle[g].ele_Distance == minPark[0] && bEle[g].status == false)
			{
				parkindex = g;
				bEle[g].status = true;
				break;
			}
		}
		//�����ʱ����v
		minPark.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bEle[parkindex].index0.c_str());
		while (!carVectB[work].s6.empty())
			carVectB[work].s6.pop();
		carVectB[work].s6.push(bEle[parkindex].index0.c_str());
		for (int j = path6[minbp]; j != ele; j = path6[j])
			carVectB[work].s6.push(parkingB.Print(j).index0.c_str());


		carVectB[work].start = clock();
		carVectB[work].eleStatus = 2;
		///С��ȥ���������ִ��
		while (carVectB[work].s6.size() != 0)
		{
			if (leaveStat == 0)
				carVectB[work].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
			if (leaveStat == 1)
				carVectB[work].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);

			if (strcmp(carVectB[work].s6.top().c_str(), bEle[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < bLineSize; p++)
				{
					if (strcmp(carVectB[work].s6.top().c_str(), bLine[p].index0.c_str()) == 0)
					{
						carVectB[work].position = carVectB[work].s6.top().c_str();
						lineindex = p;
						if (bLine[p].status == false)
						{
							bLine[p].status = true;
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
					}
				}
				bLine[lineindex].status = false;
				carVectB[work].s6.pop();
				Sleep(2000);
				carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			}
			else{
				carVectB[work].position = carVectB[work].s6.top().c_str();
				carVectB[work].s6.pop();
				carVectB[work].position = bEle[parkindex].index0;
				for (int b = 0; b < bElesize; b++)
				{
					if (strcmp(bEle[b].index0.c_str(), carVectB[work].position.c_str()) == 0)
					{
						carVectB[work].change(bEle[b].x, bEle[b].y, bEle[b].length, bEle[b].wide);
						carVectB[work].eleStatus = 2;
						m.show();
					}
				}
				carVectB[work].status = false;
				carVectB[work].stop = 1;
				carVectB[work].start = clock();
				carVectB[work].eleNum = 100;

			}
		}
	}
}

void bParkProCar2()
{
	int work = 1;
	carVectB[work].status = true;//��״̬��Ϊʹ��
	carVectB[work].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
	carVectB[work].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
	//cout << "������С���±���" << carVectB[workcar].index << endl;
	//MessageBox::Show("����С�����±�Ϊ:" + carVectB[workcar].index);
	//ѡ������ĳ�λ
	while (1)
	{
		if (minDistance.size() == 0)
			break;
	};
	for (int i = 0; i < bSpacesize; i++)
	{
		if (bSpace[i].status == false)
			minDistance.push_back(bSpace[i].distance_B);
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if (cSpace[i].status == false)
			minDistance.push_back(cSpace[i].distance_B);
	}
	sort(minDistance.begin(), minDistance.end());
	//minspace = 999;
	//�ж������λ���ĸ�����
	for (int i = 0; i < bSpacesize; i++)
	{
		if ((minDistance[0] == bSpace[i].distance_B) && (bSpace[i].status == false))
		{
			//minspace = i;
			carVectB[work].carindex = i;
			bSpace[i].status = true;
			bSpace[i].license = license;
			carVectB[work].book(bSpace[i].x, bSpace[i].y);
			minIndex = 1;
			break;
		}
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if ((minDistance[0] == cSpace[i].distance_B) && (cSpace[i].status == false))
		{
			//minspace = i;
			carVectB[work].carindex = i;
			cSpace[i].status = true;
			cSpace[i].license = license;
			carVectB[work].book(cSpace[i].x, cSpace[i].y);
			minIndex = 2;
			break;
		}
	}

	minDistance.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��
	int minbp = 0;
	if (minIndex == 1)
		minbp = parkingB.strgetIndex0(bSpace[carVectB[work].carindex].index0.c_str());
	else if (minIndex == 2)
		minbp = parkingB.strgetIndex0(cSpace[carVectB[work].carindex].index0.c_str());
	//������ѡ��������λ
	//��ȡ���ڵ������λ��·��
	while (!carVectB[work].s1.empty())
		carVectB[work].s1.pop();
	carVectB[work].s1.push(parkingB.Print(minbp).index0);
	for (int j = path[minbp]; j != startB; j = path[j])
		carVectB[work].s1.push(parkingB.Print(j).index0);

	//��С����ǰλ��Ϊ�����㵽���ڵ����·��
	int leave = parkingB.strgetIndex0(carVectB[work].position.c_str());
	int *dist1 = new int[verNum];
	int *path1 = new int[verNum];
	parkingB.dijkstra(leave, dist1, path1);
	//��ȡС�������ڵ����·��
	while (!carVectB[work].s2.empty())
		carVectB[work].s2.pop();
	carVectB[work].s2.push(parkingB.Print(startB).index0);
	for (int j = path1[startB]; j != leave; j = path1[j])
		carVectB[work].s2.push(parkingB.Print(j).index0);

	cout << "С��" << carVectB[work].index << "��ʼ��ʹ" << endl;
	//��¼����С���뿪ʱ��λ��
	//1.С����ͣ�����ӵ�����
	for (int i = 0; i < bParksize; i++)
	{
		if (strcmp(bPark[i].index0.c_str(), carVectB[work].position.c_str()) == 0)
		{
			carVectB[work].ingChange(bPark[i].x, bPark[i].y, bPark[i].length, bPark[i].wide);
			bPark[i].status = false;
			leavePosi = i;
			leaveStat = 0;
		}
	}
	//2.С������·�нӵ�����
	for (int i = 0; i < bLineSize; i++)
	{
		if (strcmp(bLine[i].index0.c_str(), carVectB[work].position.c_str()) == 0)
		{
			carVectB[work].ingChange(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
			bLine[i].status = false;
			leavePosi = i;
			leaveStat = 1;
		}
	}
	//3.С���ӳ�����ӵ�����
	for (int i = 0; i < bElesize; i++)
	{
		if (strcmp(bEle[i].index0.c_str(), carVectB[work].position.c_str()) == 0)
		{
			carVectB[work].ingChange(bEle[i].x, bEle[i].y, bEle[i].length, bEle[i].wide);
			bEle[i].status = false;
			leavePosi = i;
			leaveStat = 2;
		}
	}

	//����С��ȥ���ڵĹ���
	carVectB[work].eleStatus = 1;
	carVectB[work].start = clock();
	while (carVectB[work].s2.size() != 0)
	{
		if (leaveStat == 0)
			carVectB[work].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
		if (leaveStat == 1)
			carVectB[work].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
		if (leaveStat == 2)
			carVectB[work].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);

		if (strcmp(carVectB[work].s2.top().c_str(), "R57") != 0)
		{
			for (int i = 0; i < bLineSize; i++)
			{
				if (strcmp(carVectB[work].s2.top().c_str(), bLine[i].index0.c_str()) == 0)
				{
					lineindex = i;
					if (bLine[i].status == false)
					{
						bLine[i].status = true;
						carVectB[work].position = carVectB[work].s2.top();
						////cout << carVectB[workcar].position << endl;
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						carVectB[work].position = carVectB[work].s2.top();
						////cout << carVectB[workcar].position << endl;											
						m.show();
					}
				}
			}
			carVectB[work].s2.pop();
			Sleep(2000);
			carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			bLine[lineindex].status = false;
		}
		else{
			if (leaveStat == 0)
				carVectB[work].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
			if (leaveStat == 1)
				carVectB[work].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
			if (leaveStat == 2)
				carVectB[work].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);
			Sleep(1000);
			carVectB[work].position = carVectB[work].s2.top();
			carVectB[work].s2.pop();
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	int tmp = carVectB[work].index;
	//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
	while (carVectB[work].s1.size() != 0)
	{
		if (strcmp(carVectB[work].s1.top().c_str(), parkingB.Print(minbp).index0.c_str()) != 0)
		{
			for (int i = 0; i < bLineSize; i++)
			{
				if (strcmp(carVectB[work].s1.top().c_str(), bLine[i].index0.c_str()) == 0)
				{
					carVectB[work].position = carVectB[work].s1.top();
					////cout << carVectB[workcar].position << endl;
					lineindex = i;
					if (bLine[i].status == false)
					{
						bLine[i].status = true;
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						m.show();
					}
				}
			}
			bLine[lineindex].status = false;
			carVectB[work].s1.pop();
			Sleep(2000);
			carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			cout << "С��" << carVectB[work].index << "��ʹ1��" << carVectB[work].s1.size() << endl;
		}
		else{
			Sleep(1000);
			carVectB[work].s1.pop();
			carVectB[work].change(parkingB.Print(minbp).x, parkingB.Print(minbp).y, parkingB.Print(minbp).length, parkingB.Print(minbp).wide);

			if (minIndex == 1)
				carVectB[work].occupy(bSpace[carVectB[work].carindex].x, bSpace[carVectB[work].carindex].y);
			if (minIndex == 2)
				carVectB[work].occupy(cSpace[carVectB[work].carindex].x, cSpace[carVectB[work].carindex].y);
			carVectB[work].carindex = 0;
			for (int i = 0; i < bLineSize; i++){
				if (strcmp(carVectB[work].position.c_str(), bLine[i].index0.c_str()) == 0)
				{
					carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
				}
			}
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			//cout << carVectB[workcar].eleNum << endl;
			if (carVectB[work].eleNum <= 25)
			{
				//������Ҫ��� �����Խ�����
				carVectB[work].eleFlag = 1;
				//ִ�г�����
				//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
				carVectB[work].eleStatus = 0;
				carVectB[work].start = clock();
			}
			else{
				carVectB[work].stop = 1;//��ʾ��Ҫͣ��
				carVectB[work].status = false;//��ʾ���Խ�����
				carVectB[work].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}


	//Bͣ��///////////////////////////////////////////////////////////////////////////////
	if (carVectB[work].stop == 1)
	{
		for (int b = 0; b < bElesize; b++)
		{
			if (strcmp(bEle[b].index0.c_str(), carVectB[work].position.c_str()) == 0)
			{
				carVectB[work].restoreEle(bEle[b].x, bEle[b].y, bEle[b].length, bEle[b].wide);
			}
		}
		for (int l = 0; l < bLineSize; l++){
			if (strcmp(carVectB[work].position.c_str(), bLine[l].index0.c_str()) == 0)
			{
				carVectB[work].restoreLine(bLine[l].x, bLine[l].y, bLine[l].length, bLine[l].wide);
			}
		}
		int park = parkingB.strgetIndex0(carVectB[work].position.c_str());
		int *dist2 = new int[verNum];
		int *path2 = new int[verNum];
		parkingB.dijkstra(park, dist2, path2);

		for (int j = 0; j < bParksize; j++)
		{
			bPark[j].distance_B = dist2[parkingB.strgetIndex0(bPark[j].index0.c_str())];
		}
		minPark.clear();
		for (int k = 0; k < bParksize; k++)
		{
			if (bPark[k].status == false)
			{
				minPark.push_back(bPark[k].distance_B);
			}
		}
		sort(minPark.begin(), minPark.end());
		//Ѱ������Ŀ���ͣ����
		for (int g = 0; g < bParksize; g++)
		{
			if (bPark[g].distance_B == minPark[0] && bPark[g].status == false)
			{
				parkindex = g;
				bPark[g].status = true;
				break;
			}

		}
		//�����ʱ����v
		minPark.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bPark[parkindex].index0.c_str());
		while (!carVectB[work].s3.empty())
			carVectB[work].s3.pop();
		carVectB[work].s3.push(bPark[parkindex].index0.c_str());
		for (int j = path2[minbp]; j != park; j = path2[j])
			carVectB[work].s3.push(parkingB.Print(j).index0.c_str());

		//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
		if (carVectB[work].stop == 0)
		{
			//˵�������㹻���Խ�������������е����ж�
			bPark[parkindex].status = false;
			while (!carVectB[work].s3.empty()){
				carVectB[work].s3.pop();
			}
			//break;
		}
		else{
			//����ִ��ͣ������
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//��s3���
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//ִ�г�����
				bPark[parkindex].status = false;
				carVectB[work].eleFlag = 1;
				carVectB[work].status = true;
				carVectB[work].start = clock();
				//break;
			}
		}

		carVectB[work].start = clock();
		carVectB[work].eleStatus = 1;
		///С��ȥ��ͣ������ִ��
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectB[work].s3.size() != 0)
		{
			//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
			if (carVectB[work].stop == 0)
			{
				bPark[parkindex].status = false;
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				break;
			}
			//��ȥͣ����;��ִ�е����ж�
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//��s3���
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//ִ�г�����
				bPark[parkindex].status = false;
				carVectB[work].eleFlag = 1;
				carVectB[work].status = true;
				carVectB[work].start = clock();
				break;
			}

			if (strcmp(carVectB[work].s3.top().c_str(), bPark[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < bLineSize; p++)
				{
					if (strcmp(carVectB[work].s3.top().c_str(), bLine[p].index0.c_str()) == 0)
					{
						carVectB[work].position = carVectB[work].s3.top().c_str();
						lineindex = p;
						if (bLine[p].status == false)
						{
							bLine[p].status = true;
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
					}
				}
				bLine[lineindex].status = false;
				carVectB[work].s3.pop();
				Sleep(2000);
				carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			}
			else{
				carVectB[work].position = carVectB[work].s3.top().c_str();
				carVectB[work].s3.pop();
				for (int b = 0; b < bParksize; b++)
				{
					if (strcmp(bPark[b].index0.c_str(), carVectB[work].position.c_str()) == 0)
					{

						carVectB[work].end = clock();
						carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
						if (carVectB[work].eleNum < 25)
						{
							//��s3���
							while (!carVectB[work].s3.empty())
								carVectB[work].s3.pop();
							//ִ�г�����
							bPark[parkindex].status = false;
							carVectB[work].status = true;
							carVectB[work].eleFlag = 1;
							carVectB[work].start = clock();
							break;
						}

						carVectB[work].change(bPark[b].x, bPark[b].y, bPark[b].length, bPark[b].wide);
						carVectB[work].start = clock();
						carVectB[work].eleStatus = 0;
						//m.show();
					}
				}

			}
		}
	}
	///////////B���////////////////////
	if (carVectB[work].eleFlag == 1)
	{
		//�жϴ���һ����ִ�г�����
		for (int o = 0; o < bParksize; o++)
		{
			if (strcmp(bPark[o].index0.c_str(), carVectB[work].position.c_str()) == 0)
			{
				carVectB[work].ingChange(bPark[o].x, bPark[o].y, bPark[o].length, bPark[o].wide);
				bPark[o].status = false;
				leavePosi = o;
				leaveStat = 0;
			}
		}
		//2.С������·�нӵ�
		for (int o = 0; o < bLineSize; o++)
		{
			if (strcmp(bLine[o].index0.c_str(), carVectB[work].position.c_str()) == 0)
			{
				carVectB[work].ingChange(bLine[o].x, bLine[o].y, bLine[o].length, bLine[o].wide);
				bLine[o].status = false;
				leavePosi = o;
				leaveStat = 1;
			}
		}
		int ele = parkingB.strgetIndex0(carVectB[work].position.c_str());
		int *dist6 = new int[verNum];
		int *path6 = new int[verNum];
		parkingB.dijkstra(ele, dist6, path6);

		for (int j = 0; j < bElesize; j++)
		{
			bEle[j].ele_Distance = dist6[parkingB.strgetIndex0(bEle[j].index0.c_str())];
		}
		for (int k = 0; k < bElesize; k++)
		{
			if (bEle[k].status == false)
			{
				minPark.push_back(bEle[k].ele_Distance);
			}
		}
		sort(minPark.begin(), minPark.end());
		//Ѱ������Ŀ��г���
		for (int g = 0; g < bElesize; g++)
		{
			if (bEle[g].ele_Distance == minPark[0] && bEle[g].status == false)
			{
				parkindex = g;
				bEle[g].status = true;
				break;
			}
		}
		//�����ʱ����v
		minPark.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bEle[parkindex].index0.c_str());
		while (!carVectB[work].s6.empty())
			carVectB[work].s6.pop();
		carVectB[work].s6.push(bEle[parkindex].index0.c_str());
		for (int j = path6[minbp]; j != ele; j = path6[j])
			carVectB[work].s6.push(parkingB.Print(j).index0.c_str());


		carVectB[work].start = clock();
		carVectB[work].eleStatus = 2;
		///С��ȥ���������ִ��
		while (carVectB[work].s6.size() != 0)
		{
			if (leaveStat == 0)
				carVectB[work].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
			if (leaveStat == 1)
				carVectB[work].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);

			if (strcmp(carVectB[work].s6.top().c_str(), bEle[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < bLineSize; p++)
				{
					if (strcmp(carVectB[work].s6.top().c_str(), bLine[p].index0.c_str()) == 0)
					{
						carVectB[work].position = carVectB[work].s6.top().c_str();
						lineindex = p;
						if (bLine[p].status == false)
						{
							bLine[p].status = true;
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
					}
				}
				bLine[lineindex].status = false;
				carVectB[work].s6.pop();
				Sleep(2000);
				carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			}
			else{
				carVectB[work].position = carVectB[work].s6.top().c_str();
				carVectB[work].s6.pop();
				carVectB[work].position = bEle[parkindex].index0;
				for (int b = 0; b < bElesize; b++)
				{
					if (strcmp(bEle[b].index0.c_str(), carVectB[work].position.c_str()) == 0)
					{
						carVectB[work].change(bEle[b].x, bEle[b].y, bEle[b].length, bEle[b].wide);
						carVectB[work].eleStatus = 2;
						m.show();
					}
				}
				carVectB[work].status = false;
				carVectB[work].stop = 1;
				carVectB[work].start = clock();
				carVectB[work].eleNum = 100;

			}
		}
	}
}

void bParkProCar3()
{
	int work = 2;
	carVectB[work].status = true;//��״̬��Ϊʹ��
	carVectB[work].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
	carVectB[work].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
	//cout << "������С���±���" << carVectB[workcar].index << endl;
	//MessageBox::Show("����С�����±�Ϊ:" + carVectB[workcar].index);
	//ѡ������ĳ�λ
	while (1)
	{
		if (minDistance.size() == 0)
			break;
	};
	for (int i = 0; i < bSpacesize; i++)
	{
		if (bSpace[i].status == false)
			minDistance.push_back(bSpace[i].distance_B);
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if (cSpace[i].status == false)
			minDistance.push_back(cSpace[i].distance_B);
	}
	sort(minDistance.begin(), minDistance.end());
	//minspace = 999;
	//�ж������λ���ĸ�����
	for (int i = 0; i < bSpacesize; i++)
	{
		if ((minDistance[0] == bSpace[i].distance_B) && (bSpace[i].status == false))
		{
			//minspace = i;
			carVectB[work].carindex = i;
			bSpace[i].status = true;
			bSpace[i].license = license;
			carVectB[work].book(bSpace[i].x, bSpace[i].y);
			minIndex = 1;
			break;
		}
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if ((minDistance[0] == cSpace[i].distance_B) && (cSpace[i].status == false))
		{
			//minspace = i;
			carVectB[work].carindex = i;
			cSpace[i].status = true;
			cSpace[i].license = license;
			carVectB[work].book(cSpace[i].x, cSpace[i].y);
			minIndex = 2;
			break;
		}
	}

	minDistance.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��
	int minbp = 0;
	if (minIndex == 1)
		minbp = parkingB.strgetIndex0(bSpace[carVectB[work].carindex].index0.c_str());
	else if (minIndex == 2)
		minbp = parkingB.strgetIndex0(cSpace[carVectB[work].carindex].index0.c_str());
	//������ѡ��������λ
	//��ȡ���ڵ������λ��·��
	while (!carVectB[work].s1.empty())
		carVectB[work].s1.pop();
	carVectB[work].s1.push(parkingB.Print(minbp).index0);
	for (int j = path[minbp]; j != startB; j = path[j])
		carVectB[work].s1.push(parkingB.Print(j).index0);

	//��С����ǰλ��Ϊ�����㵽���ڵ����·��
	int leave = parkingB.strgetIndex0(carVectB[work].position.c_str());
	int *dist1 = new int[verNum];
	int *path1 = new int[verNum];
	parkingB.dijkstra(leave, dist1, path1);
	//��ȡС�������ڵ����·��
	while (!carVectB[work].s2.empty())
		carVectB[work].s2.pop();
	carVectB[work].s2.push(parkingB.Print(startB).index0);
	for (int j = path1[startB]; j != leave; j = path1[j])
		carVectB[work].s2.push(parkingB.Print(j).index0);

	cout << "С��" << carVectB[work].index << "��ʼ��ʹ" << endl;
	//��¼����С���뿪ʱ��λ��
	//1.С����ͣ�����ӵ�����
	for (int i = 0; i < bParksize; i++)
	{
		if (strcmp(bPark[i].index0.c_str(), carVectB[work].position.c_str()) == 0)
		{
			carVectB[work].ingChange(bPark[i].x, bPark[i].y, bPark[i].length, bPark[i].wide);
			bPark[i].status = false;
			leavePosi = i;
			leaveStat = 0;
		}
	}
	//2.С������·�нӵ�����
	for (int i = 0; i < bLineSize; i++)
	{
		if (strcmp(bLine[i].index0.c_str(), carVectB[work].position.c_str()) == 0)
		{
			carVectB[work].ingChange(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
			bLine[i].status = false;
			leavePosi = i;
			leaveStat = 1;
		}
	}
	//3.С���ӳ�����ӵ�����
	for (int i = 0; i < bElesize; i++)
	{
		if (strcmp(bEle[i].index0.c_str(), carVectB[work].position.c_str()) == 0)
		{
			carVectB[work].ingChange(bEle[i].x, bEle[i].y, bEle[i].length, bEle[i].wide);
			bEle[i].status = false;
			leavePosi = i;
			leaveStat = 2;
		}
	}

	//����С��ȥ���ڵĹ���
	carVectB[work].eleStatus = 1;
	carVectB[work].start = clock();
	while (carVectB[work].s2.size() != 0)
	{
		if (leaveStat == 0)
			carVectB[work].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
		if (leaveStat == 1)
			carVectB[work].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
		if (leaveStat == 2)
			carVectB[work].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);

		if (strcmp(carVectB[work].s2.top().c_str(), "R57") != 0)
		{
			for (int i = 0; i < bLineSize; i++)
			{
				if (strcmp(carVectB[work].s2.top().c_str(), bLine[i].index0.c_str()) == 0)
				{
					lineindex = i;
					if (bLine[i].status == false)
					{
						bLine[i].status = true;
						carVectB[work].position = carVectB[work].s2.top();
						////cout << carVectB[workcar].position << endl;
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						carVectB[work].position = carVectB[work].s2.top();
						////cout << carVectB[workcar].position << endl;											
						m.show();
					}
				}
			}
			carVectB[work].s2.pop();
			Sleep(2000);
			carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			bLine[lineindex].status = false;
		}
		else{
			if (leaveStat == 0)
				carVectB[work].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
			if (leaveStat == 1)
				carVectB[work].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
			if (leaveStat == 2)
				carVectB[work].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);
			Sleep(1000);
			carVectB[work].position = carVectB[work].s2.top();
			carVectB[work].s2.pop();
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	int tmp = carVectB[work].index;
	//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
	while (carVectB[work].s1.size() != 0)
	{
		if (strcmp(carVectB[work].s1.top().c_str(), parkingB.Print(minbp).index0.c_str()) != 0)
		{
			for (int i = 0; i < bLineSize; i++)
			{
				if (strcmp(carVectB[work].s1.top().c_str(), bLine[i].index0.c_str()) == 0)
				{
					carVectB[work].position = carVectB[work].s1.top();
					////cout << carVectB[workcar].position << endl;
					lineindex = i;
					if (bLine[i].status == false)
					{
						bLine[i].status = true;
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						m.show();
					}
				}
			}
			bLine[lineindex].status = false;
			carVectB[work].s1.pop();
			Sleep(2000);
			carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			cout << "С��" << carVectB[work].index << "��ʹ1��" << carVectB[work].s1.size() << endl;
		}
		else{
			Sleep(1000);
			carVectB[work].s1.pop();
			carVectB[work].change(parkingB.Print(minbp).x, parkingB.Print(minbp).y, parkingB.Print(minbp).length, parkingB.Print(minbp).wide);

			if (minIndex == 1)
				carVectB[work].occupy(bSpace[carVectB[work].carindex].x, bSpace[carVectB[work].carindex].y);
			if (minIndex == 2)
				carVectB[work].occupy(cSpace[carVectB[work].carindex].x, cSpace[carVectB[work].carindex].y);
			carVectB[work].carindex = 0;
			for (int i = 0; i < bLineSize; i++){
				if (strcmp(carVectB[work].position.c_str(), bLine[i].index0.c_str()) == 0)
				{
					carVectB[work].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
				}
			}
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			//cout << carVectB[workcar].eleNum << endl;
			if (carVectB[work].eleNum <= 25)
			{
				//������Ҫ��� �����Խ�����
				carVectB[work].eleFlag = 1;
				//ִ�г�����
				//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
				carVectB[work].eleStatus = 0;
				carVectB[work].start = clock();
			}
			else{
				carVectB[work].stop = 1;//��ʾ��Ҫͣ��
				carVectB[work].status = false;//��ʾ���Խ�����
				carVectB[work].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}


	//Bͣ��///////////////////////////////////////////////////////////////////////////////
	if (carVectB[work].stop == 1)
	{
		for (int b = 0; b < bElesize; b++)
		{
			if (strcmp(bEle[b].index0.c_str(), carVectB[work].position.c_str()) == 0)
			{
				carVectB[work].restoreEle(bEle[b].x, bEle[b].y, bEle[b].length, bEle[b].wide);
			}
		}
		for (int l = 0; l < bLineSize; l++){
			if (strcmp(carVectB[work].position.c_str(), bLine[l].index0.c_str()) == 0)
			{
				carVectB[work].restoreLine(bLine[l].x, bLine[l].y, bLine[l].length, bLine[l].wide);
			}
		}
		int park = parkingB.strgetIndex0(carVectB[work].position.c_str());
		int *dist2 = new int[verNum];
		int *path2 = new int[verNum];
		parkingB.dijkstra(park, dist2, path2);

		for (int j = 0; j < bParksize; j++)
		{
			bPark[j].distance_B = dist2[parkingB.strgetIndex0(bPark[j].index0.c_str())];
		}
		minPark.clear();
		for (int k = 0; k < bParksize; k++)
		{
			if (bPark[k].status == false)
			{
				minPark.push_back(bPark[k].distance_B);
			}
		}
		sort(minPark.begin(), minPark.end());
		//Ѱ������Ŀ���ͣ����
		for (int g = 0; g < bParksize; g++)
		{
			if (bPark[g].distance_B == minPark[0] && bPark[g].status == false)
			{
				parkindex = g;
				bPark[g].status = true;
				break;
			}

		}
		//�����ʱ����v
		minPark.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bPark[parkindex].index0.c_str());
		while (!carVectB[work].s3.empty())
			carVectB[work].s3.pop();
		carVectB[work].s3.push(bPark[parkindex].index0.c_str());
		for (int j = path2[minbp]; j != park; j = path2[j])
			carVectB[work].s3.push(parkingB.Print(j).index0.c_str());

		//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
		if (carVectB[work].stop == 0)
		{
			//˵�������㹻���Խ�������������е����ж�
			bPark[parkindex].status = false;
			while (!carVectB[work].s3.empty()){
				carVectB[work].s3.pop();
			}
			//break;
		}
		else{
			//����ִ��ͣ������
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//��s3���
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//ִ�г�����
				bPark[parkindex].status = false;
				carVectB[work].eleFlag = 1;
				carVectB[work].status = true;
				carVectB[work].start = clock();
				//break;
			}
		}

		carVectB[work].start = clock();
		carVectB[work].eleStatus = 1;
		///С��ȥ��ͣ������ִ��
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectB[work].s3.size() != 0)
		{
			//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
			if (carVectB[work].stop == 0)
			{
				bPark[parkindex].status = false;
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				break;
			}
			//��ȥͣ����;��ִ�е����ж�
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//��s3���
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//ִ�г�����
				bPark[parkindex].status = false;
				carVectB[work].eleFlag = 1;
				carVectB[work].status = true;
				carVectB[work].start = clock();
				break;
			}

			if (strcmp(carVectB[work].s3.top().c_str(), bPark[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < bLineSize; p++)
				{
					if (strcmp(carVectB[work].s3.top().c_str(), bLine[p].index0.c_str()) == 0)
					{
						carVectB[work].position = carVectB[work].s3.top().c_str();
						lineindex = p;
						if (bLine[p].status == false)
						{
							bLine[p].status = true;
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
					}
				}
				bLine[lineindex].status = false;
				carVectB[work].s3.pop();
				Sleep(2000);
				carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			}
			else{
				carVectB[work].position = carVectB[work].s3.top().c_str();
				carVectB[work].s3.pop();
				for (int b = 0; b < bParksize; b++)
				{
					if (strcmp(bPark[b].index0.c_str(), carVectB[work].position.c_str()) == 0)
					{

						carVectB[work].end = clock();
						carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
						if (carVectB[work].eleNum < 25)
						{
							//��s3���
							while (!carVectB[work].s3.empty())
								carVectB[work].s3.pop();
							//ִ�г�����
							bPark[parkindex].status = false;
							carVectB[work].status = true;
							carVectB[work].eleFlag = 1;
							carVectB[work].start = clock();
							break;
						}

						carVectB[work].change(bPark[b].x, bPark[b].y, bPark[b].length, bPark[b].wide);
						carVectB[work].start = clock();
						carVectB[work].eleStatus = 0;
						//m.show();
					}
				}

			}
		}
	}
	///////////B���////////////////////
	if (carVectB[work].eleFlag == 1)
	{
		//�жϴ���һ����ִ�г�����
		for (int o = 0; o < bParksize; o++)
		{
			if (strcmp(bPark[o].index0.c_str(), carVectB[work].position.c_str()) == 0)
			{
				carVectB[work].ingChange(bPark[o].x, bPark[o].y, bPark[o].length, bPark[o].wide);
				bPark[o].status = false;
				leavePosi = o;
				leaveStat = 0;
			}
		}
		//2.С������·�нӵ�
		for (int o = 0; o < bLineSize; o++)
		{
			if (strcmp(bLine[o].index0.c_str(), carVectB[work].position.c_str()) == 0)
			{
				carVectB[work].ingChange(bLine[o].x, bLine[o].y, bLine[o].length, bLine[o].wide);
				bLine[o].status = false;
				leavePosi = o;
				leaveStat = 1;
			}
		}
		int ele = parkingB.strgetIndex0(carVectB[work].position.c_str());
		int *dist6 = new int[verNum];
		int *path6 = new int[verNum];
		parkingB.dijkstra(ele, dist6, path6);

		for (int j = 0; j < bElesize; j++)
		{
			bEle[j].ele_Distance = dist6[parkingB.strgetIndex0(bEle[j].index0.c_str())];
		}
		for (int k = 0; k < bElesize; k++)
		{
			if (bEle[k].status == false)
			{
				minPark.push_back(bEle[k].ele_Distance);
			}
		}
		sort(minPark.begin(), minPark.end());
		//Ѱ������Ŀ��г���
		for (int g = 0; g < bElesize; g++)
		{
			if (bEle[g].ele_Distance == minPark[0] && bEle[g].status == false)
			{
				parkindex = g;
				bEle[g].status = true;
				break;
			}
		}
		//�����ʱ����v
		minPark.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bEle[parkindex].index0.c_str());
		while (!carVectB[work].s6.empty())
			carVectB[work].s6.pop();
		carVectB[work].s6.push(bEle[parkindex].index0.c_str());
		for (int j = path6[minbp]; j != ele; j = path6[j])
			carVectB[work].s6.push(parkingB.Print(j).index0.c_str());


		carVectB[work].start = clock();
		carVectB[work].eleStatus = 2;
		///С��ȥ���������ִ��
		while (carVectB[work].s6.size() != 0)
		{
			if (leaveStat == 0)
				carVectB[work].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
			if (leaveStat == 1)
				carVectB[work].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);

			if (strcmp(carVectB[work].s6.top().c_str(), bEle[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < bLineSize; p++)
				{
					if (strcmp(carVectB[work].s6.top().c_str(), bLine[p].index0.c_str()) == 0)
					{
						carVectB[work].position = carVectB[work].s6.top().c_str();
						lineindex = p;
						if (bLine[p].status == false)
						{
							bLine[p].status = true;
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectB[work].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
							m.show();
						}
					}
				}
				bLine[lineindex].status = false;
				carVectB[work].s6.pop();
				Sleep(2000);
				carVectB[work].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
			}
			else{
				carVectB[work].position = carVectB[work].s6.top().c_str();
				carVectB[work].s6.pop();
				carVectB[work].position = bEle[parkindex].index0;
				for (int b = 0; b < bElesize; b++)
				{
					if (strcmp(bEle[b].index0.c_str(), carVectB[work].position.c_str()) == 0)
					{
						carVectB[work].change(bEle[b].x, bEle[b].y, bEle[b].length, bEle[b].wide);
						carVectB[work].eleStatus = 2;
						m.show();
					}
				}
				carVectB[work].status = false;
				carVectB[work].stop = 1;
				carVectB[work].start = clock();
				carVectB[work].eleNum = 100;

			}
		}
	}
}

void aParkProCar4()
{
	int awork = 0;
	carVectA[awork].status = true;//��״̬��Ϊʹ��
	carVectA[awork].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
	carVectA[awork].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
	cout << "������С���±���" << carVectA[awork].index << endl;
	//MessageBox::Show("����С�����±�Ϊ:" + carVectA[workcar].index);
	vector<int> aminDist;
	//ѡ������ĳ�λ
	for (int i = 0; i < aSpacesize; i++)
	{
		if (aSpace[i].status == false)
			aminDist.push_back(aSpace[i].distance_A);
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if (cSpace[i].status == false)
			aminDist.push_back(cSpace[i].distance_A);
	}
	sort(aminDist.begin(), aminDist.end());
	//�ж������λ���ĸ�����
	for (int i = 0; i < aSpacesize; i++)
	{
		if ((aminDist[0] == aSpace[i].distance_A) && (aSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			aSpace[i].status = true;
			aSpace[i].license = license;
			carVectA[awork].book(aSpace[i].x, aSpace[i].y);
			minIndex = 1;
			break;
		}
	}

	for (int i = 0; i < cSpacesize; i++)
	{
		if ((aminDist[0] == cSpace[i].distance_A) && (cSpace[i].status == false))
		{
				carVectA[awork].carindex = i;
				cSpace[i].status = true;
				cSpace[i].license = license;
				carVectA[awork].book(cSpace[i].x, cSpace[i].y);
				minIndex = 2;
				break;
		}
	}
	aminDist.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��

	int minap;//��ȡ�����λ��ͼ�е��������
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//������ѡ��������λ
	//��ȡ���ڵ������λ��·��
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//��С����ǰλ��Ϊ�����㵽���ڵ����·��
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//��ȡС�������ڵ����·��
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//��¼����С���뿪ʱ��λ��
	//1.С����ͣ�����ӵ�����
	for (int i = 0; i < aParksize1; i++)
	{
		if (strcmp(aPark1[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark1[i].x, aPark1[i].y, aPark1[i].length, aPark1[i].wide);
			aPark1[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 1;
		}
	}
	for (int i = 0; i < aParksize2; i++)
	{
		if (strcmp(aPark2[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark2[i].x, aPark2[i].y, aPark2[i].length, aPark2[i].wide);
			aPark2[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 2;
		}
	}
	//2.С������·�нӵ�����
	for (int i = 0; i < aLineSize; i++)
	{
		if (strcmp(aLine[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
			aLine[i].status = false;
			leavePosi = i;
			leaveStat = 1;
		}
	}
	//3.С���ӳ�����ӵ�����
	for (int i = 0; i < aElesize; i++)
	{
		if (strcmp(aEle[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aEle[i].x, aEle[i].y, aEle[i].length, aEle[i].wide);
			aEle[i].status = false;
			leavePosi = i;
			leaveStat = 2;
		}
	}

	//����С��ȥ���ڵĹ���
	carVectA[awork].eleStatus = 1;
	carVectA[awork].start = clock();
	while (carVectA[awork].s2.size() != 0)
	{
		if (leaveStat == 0)
		{
			if (aParkindex == 1)
			{
				carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
			}
			if (aParkindex == 2)
			{
				carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
			}
		}

		if (leaveStat == 1)
			carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
		if (leaveStat == 2)
			carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);

		if (strcmp(carVectA[awork].s2.top().c_str(), "R00") != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s2.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;											
						m.show();
					}
				}
			}
			carVectA[awork].s2.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			aLine[lineindex].status = false;
		}
		else{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
			if (leaveStat == 2)
				carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);
			Sleep(1000);
			carVectA[awork].position = carVectA[awork].s2.top();
			carVectA[awork].s2.pop();
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
	while (carVectA[awork].s1.size() != 0)
	{
		if (strcmp(carVectA[awork].s1.top().c_str(), parkingA.Print(minap).index0.c_str()) != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s1.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectA[awork].position = carVectA[awork].s1.top();
					////cout << carVectB[workcar].position << endl;
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
				}
			}
			aLine[lineindex].status = false;
			carVectA[awork].s1.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
		}
		else{
			Sleep(1000);
			carVectA[awork].s1.pop();
			carVectA[awork].change(parkingA.Print(minap).x, parkingA.Print(minap).y, parkingA.Print(minap).length, parkingA.Print(minap).wide);

			if (minIndex == 1)
				carVectA[awork].occupy(aSpace[carVectA[awork].carindex].x, aSpace[carVectA[awork].carindex].y);
			if (minIndex == 2)
				carVectA[awork].occupy(cSpace[carVectA[awork].carindex].x, cSpace[carVectA[awork].carindex].y);
			for (int i = 0; i < aLineSize; i++){
				if (strcmp(carVectA[awork].position.c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectB[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
				}
			}
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			//cout << carVectB[workcar].eleNum << endl;
			if (carVectA[awork].eleNum <= 25)
			{
				//������Ҫ��� �����Խ�����
				carVectA[awork].eleFlag = 1;
				//ִ�г�����
				//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//��ʾ��Ҫͣ��
				carVectA[awork].status = false;//��ʾ���Խ�����
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "ͣ�����" << endl;
	//	MessageBox::Show("ͣ���������");
	/////////////////////////////////////////////////////2.A����ͣ������/////////////////////////////////////////////////////////////	
	    int APARKIndex = 0;
	    int aParkRet = 0;
		for (int v = 0; v < aSpacesize; v++)
		{
			if (aSpace[v].status == false)
				APARKIndex++;
		}
		for (int v = 0; v < cSpacesize; v++)
		{
			if (cSpace[v].status == false)
				APARKIndex++;
		}

		if (APARKIndex > aParkNum)
			aParkRet = 1;
		else
			aParkRet = 2;

		if (carVectA[awork].stop == 1)
		{
			for (int b = 0; b < aElesize; b++)
			{
				if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
				{
					carVectA[awork].restoreEle(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
				}
			}

			for (int p = 0; p < aLineSize; p++){
				if (strcmp(carVectA[awork].position.c_str(), aLine[p].index0.c_str()) == 0)
				{
					carVectA[awork].restoreLine(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
				}
			}
			int parkA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
			int *dist16 = new int[verNumA];
			int *path16 = new int[verNumA];
			parkingA.dijkstra(parkA, dist16, path16);

			for (int j = 0; j < aParksize1; j++)
			{
				aPark1[j].distance_A = dist16[parkingA.strgetIndex0(aPark1[j].index0.c_str())];
			}
			for (int j = 0; j < aParksize2; j++)
			{
				aPark2[j].distance_A = dist16[parkingA.strgetIndex0(aPark2[j].index0.c_str())];
			}
			
			vector<int> minParka;
			if (aParkRet == 1)
			{
				for (int k = 0; k < aParksize1; k++)
				{
					if (aPark1[k].status == false)
					{
						minParka.push_back(aPark1[k].distance_A);
					}
				}
			}

			if (aParkRet == 2)
			{
				for (int k = 0; k < aParksize2; k++)
				{
					if (aPark2[k].status == false)
					{
						minParka.push_back(aPark2[k].distance_A);
					}
				}
			}
			sort(minParka.begin(), minParka.end());
			//Ѱ������Ŀ���ͣ����
			if (aParkRet == 1)
			{
				for (int g = 0; g < aParksize1; g++)
				{
					if ((aPark1[g].distance_A == minParka[0]) && (aPark1[g].status == false))
					{
						parkindex = g;
						aPark1[g].status = true;
						break;
					}

				}
			}

			if (aParkRet == 2)
			{
				for (int g = 0; g < aParksize2; g++)
				{
					if ((aPark2[g].distance_A == minParka[0]) && (aPark2[g].status == false))
					{
						parkindex = g;
						aPark2[g].status = true;
						break;
					}

				}
			}


			//�����ʱ����v
			minParka.clear();
			//�����ͣ��λΪ�յ�滮ͣ��·��
			int minap = 0;
			if (aParkRet == 1)
			{
				minap = parkingA.strgetIndex0(aPark1[parkindex].index0.c_str());
				carVectA[awork].s3.push(aPark1[parkindex].index0.c_str());
				aparkstr.clear();
				aparkstr = aPark1[parkindex].index0;
			}

			if (aParkRet == 2)
			{
				minap = parkingA.strgetIndex0(aPark2[parkindex].index0.c_str());
				carVectA[awork].s3.push(aPark2[parkindex].index0.c_str());
				aparkstr.clear();
				aparkstr = aPark2[parkindex].index0;
			}
			for (int j = path16[minap]; j != parkA; j = path16[j])
				carVectA[awork].s3.push(parkingA.Print(j).index0.c_str());

			//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
			if (carVectA[awork].stop == 0)
			{
				//˵�������㹻���Խ�������������е����ж�
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//break;
			}
			else{
				//����ִ��ͣ������
				carVectA[awork].end = clock();
				carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
				if (carVectA[awork].eleNum < 25)
				{
					//��s3���
					while (!carVectA[awork].s3.empty())
						carVectA[awork].s3.pop();
					//ִ�г�����
					if (aParkRet == 1)
						aPark1[parkindex].status = false;
					if (aParkRet == 2)
						aPark2[parkindex].status = false;
					carVectA[awork].eleFlag = 1;
					carVectA[awork].status = true;
					carVectA[awork].start = clock();
					//break;
				}
			}

			carVectA[awork].start = clock();
			carVectA[awork].eleStatus = 1;
			///С��ȥ��ͣ������ִ��
			//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
			while (carVectA[awork].s3.size() != 0)
			{
				//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
				if (carVectA[awork].stop == 0)
				{
					if (aParkRet == 1)
						aPark1[parkindex].status = false;
					if (aParkRet == 2)
						aPark2[parkindex].status = false;
					while (!carVectA[awork].s3.empty())
						carVectA[awork].s3.pop();
					break;
				}
				//��ȥͣ����;��ִ�е����ж�
				carVectA[awork].end = clock();
				carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
				///	carVectA[i].eleNum = 100;
				if (carVectA[awork].eleNum < 25)
				{
					//��s3���
					while (!carVectA[awork].s3.empty())
						carVectA[awork].s3.pop();
					//ִ�г�����
					if (aParkRet == 1)
						aPark1[parkindex].status = false;
					if (aParkRet == 2)
						aPark2[parkindex].status = false;
					carVectA[awork].eleFlag = 1;
					carVectA[awork].status = true;
					carVectA[awork].start = clock();
					break;
				}

				if (strcmp(carVectA[awork].s3.top().c_str(), aparkstr.c_str()) != 0)
				{
					for (int p = 0; p < aLineSize; p++)
					{
						if (strcmp(carVectA[awork].s3.top().c_str(), aLine[p].index0.c_str()) == 0)
						{
							carVectA[awork].position = carVectA[awork].s3.top().c_str();
							lineindex = p;
							if (aLine[p].status == false)
							{
								aLine[p].status = true;
								carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
								aLine[lineindex].status = false;
								carVectA[awork].s3.pop();
								m.show();
							}
							else{
								Sleep(2000);							
								carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
								aLine[lineindex].status = false;
								carVectA[awork].s3.pop();
								m.show();
							}
						}
					}
					//Sleep(2000);
					carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
					//cout << carVectA[awork].index << "ͣ������" << carVectA[awork].s3.size() <<"��"<< endl;
				}
				else{
					carVectA[awork].position = carVectA[awork].s3.top().c_str();
					carVectA[awork].s3.pop();
					//cout << carVectA[awork].index << "ͣ�����һ��" << endl;
					if (aParkRet == 1){
						for (int b = 0; b < aParksize1; b++)
						{
							if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
							{
								carVectA[awork].end = clock();
								carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
								if (carVectA[awork].eleNum < 25)
								{
									//��s3���
									while (!carVectA[awork].s3.empty())
										carVectA[awork].s3.pop();
									if (aParkRet == 1)
										aPark1[parkindex].status = false;
									if (aParkRet == 2)
										aPark2[parkindex].status = false;
									//ִ�г�����
									carVectA[awork].status = true;
									carVectA[awork].eleFlag = 1;
									carVectA[awork].start = clock();
									break;
								}

								carVectA[awork].change(aPark1[b].x, aPark1[b].y, aPark1[b].length, aPark1[b].wide);
								carVectA[awork].start = clock();
								carVectA[awork].eleStatus = 0;
								m.show();
							}
						}
					}

					if (aParkRet == 2){
						for (int b = 0; b < aParksize2; b++)
						{
							if (strcmp(aPark2[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
							{
								carVectA[awork].end = clock();
								carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
								if (carVectA[awork].eleNum < 25)
								{
									//��s3���
									while (!carVectA[awork].s3.empty())
										carVectA[awork].s3.pop();
									//ִ�г�����
									if (aParkRet == 1)
										aPark1[parkindex].status = false;
									if (aParkRet == 2)
										aPark2[parkindex].status = false;
									carVectA[awork].status = true;
									carVectA[awork].eleFlag = 1;
									carVectA[awork].start = clock();
									break;
								}

								carVectA[awork].change(aPark2[b].x, aPark2[b].y, aPark2[b].length, aPark2[b].wide);
								carVectA[awork].start = clock();
								carVectA[awork].eleStatus = 0;
								m.show();
							}
						}
					}
				}
			}
		}
		/////////////A�ĳ�����////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (carVectA[awork].eleFlag == 1)
			{
				//�жϴ���һ����ִ�г�����
				//ͣ����
				for (int o = 0; o < aParksize1; o++)
				{
					if (strcmp(aPark1[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
					{
						carVectA[awork].ingChange(aPark1[o].x, aPark1[o].y, aPark1[o].length, aPark1[o].wide);
						aPark1[o].status = false;
						leavePosi = awork;
						leaveStat = 0;
						aParkindex = 1;
					}
				}
				for (int o = 0; o < aParksize2; o++)
				{
					if (strcmp(aPark2[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
					{
						carVectA[awork].ingChange(aPark2[o].x, aPark2[o].y, aPark2[o].length, aPark2[o].wide);
						aPark2[o].status = false;
						leavePosi = awork;
						leaveStat = 0;
						aParkindex = 2;
					}
				}
				//2.С������·�нӵ�
				for (int o = 0; o < aLineSize; o++)
				{
					if (strcmp(aLine[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
					{
						carVectA[awork].ingChange(aLine[o].x, aLine[o].y, aLine[o].length, aLine[o].wide);
						aLine[o].status = false;
						leavePosi = o;
						leaveStat = 1;
					}
				}


				int eleA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
				int *dist12 = new int[verNumA];
				int *path12 = new int[verNumA];
				parkingA.dijkstra(eleA, dist12, path12);

				for (int j = 0; j < aElesize; j++)
				{
					aEle[j].ele_Distance = dist12[parkingA.strgetIndex0(aEle[j].index0.c_str())];
				}
				vector<int> minElea;
				for (int k = 0; k < aElesize; k++)
				{
					if (aEle[k].status == false)
					{
						minElea.push_back(aEle[k].ele_Distance);
					}
				}
				sort(minElea.begin(), minElea.end());
				//Ѱ������Ŀ��г���
				for (int g = 0; g < aElesize; g++)
				{
					if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
					{
						parkindex = g;
						aEle[g].status = true;
						break;
					}
				}
				//�����ʱ����v
				minElea.clear();
				//�����ͣ��λΪ�յ�滮ͣ��·��
				int minap = 0;
				minap = parkingA.strgetIndex0(aEle[parkindex].index0.c_str());
				////cout << aEle[parkindex].index0 << endl;
				while (!carVectA[awork].s6.empty())
					carVectA[awork].s6.pop();
				carVectA[awork].s6.push(aEle[parkindex].index0.c_str());
				for (int j = path12[minap]; j != eleA; j = path12[j])
					carVectA[awork].s6.push(parkingA.Print(j).index0.c_str());


				carVectA[awork].start = clock();
				carVectA[awork].eleStatus = 2;
				///С��ȥ���������ִ��
				while (carVectA[awork].s6.size() != 0)
				{
					if (leaveStat == 0)
					{
						if (aParkindex == 1)
						{
							carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
						}
						if (aParkindex == 2)
						{
							carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
						}
					}

					if (leaveStat == 1)
						carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);

					if (strcmp(carVectA[awork].s6.top().c_str(), aEle[parkindex].index0.c_str()) != 0)
					{
						for (int p = 0; p < aLineSize; p++)
						{
							if (strcmp(carVectA[awork].s6.top().c_str(), aLine[p].index0.c_str()) == 0)
							{
								carVectA[awork].position = carVectA[awork].s6.top().c_str();
								lineindex = p;
								if (aLine[p].status == false)
								{
									aLine[p].status = true;
									carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
									m.show();
								}
								else{
									Sleep(2000);
									carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
									m.show();
								}
							}
						}
						aLine[lineindex].status = false;
						carVectA[awork].s6.pop();
						Sleep(2000);
						carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
					}
					else{
						carVectA[awork].position = carVectA[awork].s6.top().c_str();
						carVectA[awork].s6.pop();
						carVectA[awork].position = aEle[parkindex].index0;
						for (int b = 0; b < aElesize; b++)
						{
							if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
							{
								carVectA[awork].change(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
								carVectA[awork].eleStatus = 2;
								m.show();
							}
						}
						carVectA[awork].status = false;
						carVectA[awork].stop = 1;
						carVectA[awork].start = clock();
						carVectA[awork].eleNum = 100;

					}
				}
			}
		///////////������/////////////////////////////////////////////
	/////////////////////////////////////
}

void aParkProCar5()
{
	int awork = 1;
	carVectA[awork].status = true;//��״̬��Ϊʹ��
	carVectA[awork].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
	carVectA[awork].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
	cout << "������С���±���" << carVectA[awork].index << endl;
	//MessageBox::Show("����С�����±�Ϊ:" + carVectA[workcar].index);
	vector<int> aminDist;
	//ѡ������ĳ�λ
	for (int i = 0; i < aSpacesize; i++)
	{
		if (aSpace[i].status == false)
			aminDist.push_back(aSpace[i].distance_A);
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if (cSpace[i].status == false)
			aminDist.push_back(cSpace[i].distance_A);
	}
	sort(aminDist.begin(), aminDist.end());
	//�ж������λ���ĸ�����
	for (int i = 0; i < aSpacesize; i++)
	{
		if ((aminDist[0] == aSpace[i].distance_A) && (aSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			aSpace[i].status = true;
			aSpace[i].license = license;
			carVectA[awork].book(aSpace[i].x, aSpace[i].y);
			minIndex = 1;
			break;
		}
	}

	for (int i = 0; i < cSpacesize; i++)
	{
		if ((aminDist[0] == cSpace[i].distance_A) && (cSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			cSpace[i].status = true;
			cSpace[i].license = license;
			carVectA[awork].book(cSpace[i].x, cSpace[i].y);
			minIndex = 2;
			break;
		}
	}
	aminDist.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��

	int minap;//��ȡ�����λ��ͼ�е��������
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//������ѡ��������λ
	//��ȡ���ڵ������λ��·��
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//��С����ǰλ��Ϊ�����㵽���ڵ����·��
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//��ȡС�������ڵ����·��
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//��¼����С���뿪ʱ��λ��
	//1.С����ͣ�����ӵ�����
	for (int i = 0; i < aParksize1; i++)
	{
		if (strcmp(aPark1[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark1[i].x, aPark1[i].y, aPark1[i].length, aPark1[i].wide);
			aPark1[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 1;
		}
	}
	for (int i = 0; i < aParksize2; i++)
	{
		if (strcmp(aPark2[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark2[i].x, aPark2[i].y, aPark2[i].length, aPark2[i].wide);
			aPark2[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 2;
		}
	}
	//2.С������·�нӵ�����
	for (int i = 0; i < aLineSize; i++)
	{
		if (strcmp(aLine[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
			aLine[i].status = false;
			leavePosi = i;
			leaveStat = 1;
		}
	}
	//3.С���ӳ�����ӵ�����
	for (int i = 0; i < aElesize; i++)
	{
		if (strcmp(aEle[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aEle[i].x, aEle[i].y, aEle[i].length, aEle[i].wide);
			aEle[i].status = false;
			leavePosi = i;
			leaveStat = 2;
		}
	}

	//����С��ȥ���ڵĹ���
	carVectA[awork].eleStatus = 1;
	carVectA[awork].start = clock();
	while (carVectA[awork].s2.size() != 0)
	{
		if (leaveStat == 0)
		{
			if (aParkindex == 1)
			{
				carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
			}
			if (aParkindex == 2)
			{
				carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
			}
		}

		if (leaveStat == 1)
			carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
		if (leaveStat == 2)
			carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);

		if (strcmp(carVectA[awork].s2.top().c_str(), "R00") != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s2.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;											
						m.show();
					}
				}
			}
			carVectA[awork].s2.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			aLine[lineindex].status = false;
		}
		else{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
			if (leaveStat == 2)
				carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);
			Sleep(1000);
			carVectA[awork].position = carVectA[awork].s2.top();
			carVectA[awork].s2.pop();
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
	while (carVectA[awork].s1.size() != 0)
	{
		if (strcmp(carVectA[awork].s1.top().c_str(), parkingA.Print(minap).index0.c_str()) != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s1.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectA[awork].position = carVectA[awork].s1.top();
					////cout << carVectB[workcar].position << endl;
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
				}
			}
			aLine[lineindex].status = false;
			carVectA[awork].s1.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
		}
		else{
			Sleep(1000);
			carVectA[awork].s1.pop();
			carVectA[awork].change(parkingA.Print(minap).x, parkingA.Print(minap).y, parkingA.Print(minap).length, parkingA.Print(minap).wide);

			if (minIndex == 1)
				carVectA[awork].occupy(aSpace[carVectA[awork].carindex].x, aSpace[carVectA[awork].carindex].y);
			if (minIndex == 2)
				carVectA[awork].occupy(cSpace[carVectA[awork].carindex].x, cSpace[carVectA[awork].carindex].y);
			for (int i = 0; i < aLineSize; i++){
				if (strcmp(carVectA[awork].position.c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectB[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
				}
			}
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			//cout << carVectB[workcar].eleNum << endl;
			if (carVectA[awork].eleNum <= 25)
			{
				//������Ҫ��� �����Խ�����
				carVectA[awork].eleFlag = 1;
				//ִ�г�����
				//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//��ʾ��Ҫͣ��
				carVectA[awork].status = false;//��ʾ���Խ�����
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "ͣ�����" << endl;
	//	MessageBox::Show("ͣ���������");
	/////////////////////////////////////////////////////2.A����ͣ������/////////////////////////////////////////////////////////////	
	int APARKIndex = 0;
	int aParkRet = 0;
	for (int v = 0; v < aSpacesize; v++)
	{
		if (aSpace[v].status == false)
			APARKIndex++;
	}
	for (int v = 0; v < cSpacesize; v++)
	{
		if (cSpace[v].status == false)
			APARKIndex++;
	}

	if (APARKIndex > aParkNum)
		aParkRet = 1;
	else
		aParkRet = 2;

	if (carVectA[awork].stop == 1)
	{
		for (int b = 0; b < aElesize; b++)
		{
			if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].restoreEle(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
			}
		}

		for (int p = 0; p < aLineSize; p++){
			if (strcmp(carVectA[awork].position.c_str(), aLine[p].index0.c_str()) == 0)
			{
				carVectA[awork].restoreLine(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
			}
		}
		int parkA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
		int *dist16 = new int[verNumA];
		int *path16 = new int[verNumA];
		parkingA.dijkstra(parkA, dist16, path16);

		for (int j = 0; j < aParksize1; j++)
		{
			aPark1[j].distance_A = dist16[parkingA.strgetIndex0(aPark1[j].index0.c_str())];
		}
		for (int j = 0; j < aParksize2; j++)
		{
			aPark2[j].distance_A = dist16[parkingA.strgetIndex0(aPark2[j].index0.c_str())];
		}

		vector<int> minParka;
		if (aParkRet == 1)
		{
			for (int k = 0; k < aParksize1; k++)
			{
				if (aPark1[k].status == false)
				{
					minParka.push_back(aPark1[k].distance_A);
				}
			}
		}

		if (aParkRet == 2)
		{
			for (int k = 0; k < aParksize2; k++)
			{
				if (aPark2[k].status == false)
				{
					minParka.push_back(aPark2[k].distance_A);
				}
			}
		}
		sort(minParka.begin(), minParka.end());
		//Ѱ������Ŀ���ͣ����
		if (aParkRet == 1)
		{
			for (int g = 0; g < aParksize1; g++)
			{
				if ((aPark1[g].distance_A == minParka[0]) && (aPark1[g].status == false))
				{
					parkindex = g;
					aPark1[g].status = true;
					break;
				}

			}
		}

		if (aParkRet == 2)
		{
			for (int g = 0; g < aParksize2; g++)
			{
				if ((aPark2[g].distance_A == minParka[0]) && (aPark2[g].status == false))
				{
					parkindex = g;
					aPark2[g].status = true;
					break;
				}

			}
		}


		//�����ʱ����v
		minParka.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minap = 0;
		if (aParkRet == 1)
		{
			minap = parkingA.strgetIndex0(aPark1[parkindex].index0.c_str());
			carVectA[awork].s3.push(aPark1[parkindex].index0.c_str());
			aparkstr.clear();
			aparkstr = aPark1[parkindex].index0;
		}

		if (aParkRet == 2)
		{
			minap = parkingA.strgetIndex0(aPark2[parkindex].index0.c_str());
			carVectA[awork].s3.push(aPark2[parkindex].index0.c_str());
			aparkstr.clear();
			aparkstr = aPark2[parkindex].index0;
		}
		for (int j = path16[minap]; j != parkA; j = path16[j])
			carVectA[awork].s3.push(parkingA.Print(j).index0.c_str());

		//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
		if (carVectA[awork].stop == 0)
		{
			//˵�������㹻���Խ�������������е����ж�
			if (aParkRet == 1)
				aPark1[parkindex].status = false;
			if (aParkRet == 2)
				aPark2[parkindex].status = false;
			while (!carVectA[awork].s3.empty())
				carVectA[awork].s3.pop();
			//break;
		}
		else{
			//����ִ��ͣ������
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			if (carVectA[awork].eleNum < 25)
			{
				//��s3���
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//ִ�г�����
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				carVectA[awork].eleFlag = 1;
				carVectA[awork].status = true;
				carVectA[awork].start = clock();
				//break;
			}
		}

		carVectA[awork].start = clock();
		carVectA[awork].eleStatus = 1;
		///С��ȥ��ͣ������ִ��
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectA[awork].s3.size() != 0)
		{
			//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
			if (carVectA[awork].stop == 0)
			{
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				break;
			}
			//��ȥͣ����;��ִ�е����ж�
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			///	carVectA[i].eleNum = 100;
			if (carVectA[awork].eleNum < 25)
			{
				//��s3���
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//ִ�г�����
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				carVectA[awork].eleFlag = 1;
				carVectA[awork].status = true;
				carVectA[awork].start = clock();
				break;
			}

			if (strcmp(carVectA[awork].s3.top().c_str(), aparkstr.c_str()) != 0)
			{
				for (int p = 0; p < aLineSize; p++)
				{
					if (strcmp(carVectA[awork].s3.top().c_str(), aLine[p].index0.c_str()) == 0)
					{
						carVectA[awork].position = carVectA[awork].s3.top().c_str();
						lineindex = p;
						if (aLine[p].status == false)
						{
							aLine[p].status = true;
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							aLine[lineindex].status = false;
							carVectA[awork].s3.pop();
							m.show();
						}
						else{
							Sleep(2000);
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							aLine[lineindex].status = false;
							carVectA[awork].s3.pop();
							m.show();
						}
					}
				}
				//Sleep(2000);
				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
				//cout << carVectA[awork].index << "ͣ������" << carVectA[awork].s3.size() <<"��"<< endl;
			}
			else{
				carVectA[awork].position = carVectA[awork].s3.top().c_str();
				carVectA[awork].s3.pop();
				//cout << carVectA[awork].index << "ͣ�����һ��" << endl;
				if (aParkRet == 1){
					for (int b = 0; b < aParksize1; b++)
					{
						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//��s3���
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								//ִ�г�����
								carVectA[awork].status = true;
								carVectA[awork].eleFlag = 1;
								carVectA[awork].start = clock();
								break;
							}

							carVectA[awork].change(aPark1[b].x, aPark1[b].y, aPark1[b].length, aPark1[b].wide);
							carVectA[awork].start = clock();
							carVectA[awork].eleStatus = 0;
							m.show();
						}
					}
				}

				if (aParkRet == 2){
					for (int b = 0; b < aParksize2; b++)
					{
						if (strcmp(aPark2[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//��s3���
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								//ִ�г�����
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								carVectA[awork].status = true;
								carVectA[awork].eleFlag = 1;
								carVectA[awork].start = clock();
								break;
							}

							carVectA[awork].change(aPark2[b].x, aPark2[b].y, aPark2[b].length, aPark2[b].wide);
							carVectA[awork].start = clock();
							carVectA[awork].eleStatus = 0;
							m.show();
						}
					}
				}
			}
		}
	}
	/////////////A�ĳ�����////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (carVectA[awork].eleFlag == 1)
	{
		//�жϴ���һ����ִ�г�����
		//ͣ����
		for (int o = 0; o < aParksize1; o++)
		{
			if (strcmp(aPark1[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aPark1[o].x, aPark1[o].y, aPark1[o].length, aPark1[o].wide);
				aPark1[o].status = false;
				leavePosi = awork;
				leaveStat = 0;
				aParkindex = 1;
			}
		}
		for (int o = 0; o < aParksize2; o++)
		{
			if (strcmp(aPark2[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aPark2[o].x, aPark2[o].y, aPark2[o].length, aPark2[o].wide);
				aPark2[o].status = false;
				leavePosi = awork;
				leaveStat = 0;
				aParkindex = 2;
			}
		}
		//2.С������·�нӵ�
		for (int o = 0; o < aLineSize; o++)
		{
			if (strcmp(aLine[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aLine[o].x, aLine[o].y, aLine[o].length, aLine[o].wide);
				aLine[o].status = false;
				leavePosi = o;
				leaveStat = 1;
			}
		}


		int eleA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
		int *dist12 = new int[verNumA];
		int *path12 = new int[verNumA];
		parkingA.dijkstra(eleA, dist12, path12);

		for (int j = 0; j < aElesize; j++)
		{
			aEle[j].ele_Distance = dist12[parkingA.strgetIndex0(aEle[j].index0.c_str())];
		}
		vector<int> minElea;
		for (int k = 0; k < aElesize; k++)
		{
			if (aEle[k].status == false)
			{
				minElea.push_back(aEle[k].ele_Distance);
			}
		}
		sort(minElea.begin(), minElea.end());
		//Ѱ������Ŀ��г���
		for (int g = 0; g < aElesize; g++)
		{
			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
			{
				parkindex = g;
				aEle[g].status = true;
				break;
			}
		}
		//�����ʱ����v
		minElea.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minap = 0;
		minap = parkingA.strgetIndex0(aEle[parkindex].index0.c_str());
		////cout << aEle[parkindex].index0 << endl;
		while (!carVectA[awork].s6.empty())
			carVectA[awork].s6.pop();
		carVectA[awork].s6.push(aEle[parkindex].index0.c_str());
		for (int j = path12[minap]; j != eleA; j = path12[j])
			carVectA[awork].s6.push(parkingA.Print(j).index0.c_str());


		carVectA[awork].start = clock();
		carVectA[awork].eleStatus = 2;
		///С��ȥ���������ִ��
		while (carVectA[awork].s6.size() != 0)
		{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);

			if (strcmp(carVectA[awork].s6.top().c_str(), aEle[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < aLineSize; p++)
				{
					if (strcmp(carVectA[awork].s6.top().c_str(), aLine[p].index0.c_str()) == 0)
					{
						carVectA[awork].position = carVectA[awork].s6.top().c_str();
						lineindex = p;
						if (aLine[p].status == false)
						{
							aLine[p].status = true;
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							m.show();
						}
					}
				}
				aLine[lineindex].status = false;
				carVectA[awork].s6.pop();
				Sleep(2000);
				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			}
			else{
				carVectA[awork].position = carVectA[awork].s6.top().c_str();
				carVectA[awork].s6.pop();
				carVectA[awork].position = aEle[parkindex].index0;
				for (int b = 0; b < aElesize; b++)
				{
					if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
					{
						carVectA[awork].change(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
						carVectA[awork].eleStatus = 2;
						m.show();
					}
				}
				carVectA[awork].status = false;
				carVectA[awork].stop = 1;
				carVectA[awork].start = clock();
				carVectA[awork].eleNum = 100;

			}
		}
	}
	///////////������/////////////////////////////////////////////
	/////////////////////////////////////
}

void aParkProCar6()
{
	int awork = 2;
	carVectA[awork].status = true;//��״̬��Ϊʹ��
	carVectA[awork].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
	carVectA[awork].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
	cout << "������С���±���" << carVectA[awork].index << endl;
	//MessageBox::Show("����С�����±�Ϊ:" + carVectA[workcar].index);
	vector<int> aminDist;
	//ѡ������ĳ�λ
	for (int i = 0; i < aSpacesize; i++)
	{
		if (aSpace[i].status == false)
			aminDist.push_back(aSpace[i].distance_A);
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if (cSpace[i].status == false)
			aminDist.push_back(cSpace[i].distance_A);
	}
	sort(aminDist.begin(), aminDist.end());
	//�ж������λ���ĸ�����
	for (int i = 0; i < aSpacesize; i++)
	{
		if ((aminDist[0] == aSpace[i].distance_A) && (aSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			aSpace[i].status = true;
			aSpace[i].license = license;
			carVectA[awork].book(aSpace[i].x, aSpace[i].y);
			minIndex = 1;
			break;
		}
	}

	for (int i = 0; i < cSpacesize; i++)
	{
		if ((aminDist[0] == cSpace[i].distance_A) && (cSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			cSpace[i].status = true;
			cSpace[i].license = license;
			carVectA[awork].book(cSpace[i].x, cSpace[i].y);
			minIndex = 2;
			break;
		}
	}
	aminDist.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��

	int minap;//��ȡ�����λ��ͼ�е��������
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//������ѡ��������λ
	//��ȡ���ڵ������λ��·��
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//��С����ǰλ��Ϊ�����㵽���ڵ����·��
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//��ȡС�������ڵ����·��
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//��¼����С���뿪ʱ��λ��
	//1.С����ͣ�����ӵ�����
	for (int i = 0; i < aParksize1; i++)
	{
		if (strcmp(aPark1[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark1[i].x, aPark1[i].y, aPark1[i].length, aPark1[i].wide);
			aPark1[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 1;
		}
	}
	for (int i = 0; i < aParksize2; i++)
	{
		if (strcmp(aPark2[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark2[i].x, aPark2[i].y, aPark2[i].length, aPark2[i].wide);
			aPark2[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 2;
		}
	}
	//2.С������·�нӵ�����
	for (int i = 0; i < aLineSize; i++)
	{
		if (strcmp(aLine[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
			aLine[i].status = false;
			leavePosi = i;
			leaveStat = 1;
		}
	}
	//3.С���ӳ�����ӵ�����
	for (int i = 0; i < aElesize; i++)
	{
		if (strcmp(aEle[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aEle[i].x, aEle[i].y, aEle[i].length, aEle[i].wide);
			aEle[i].status = false;
			leavePosi = i;
			leaveStat = 2;
		}
	}

	//����С��ȥ���ڵĹ���
	carVectA[awork].eleStatus = 1;
	carVectA[awork].start = clock();
	while (carVectA[awork].s2.size() != 0)
	{
		if (leaveStat == 0)
		{
			if (aParkindex == 1)
			{
				carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
			}
			if (aParkindex == 2)
			{
				carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
			}
		}

		if (leaveStat == 1)
			carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
		if (leaveStat == 2)
			carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);

		if (strcmp(carVectA[awork].s2.top().c_str(), "R00") != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s2.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;											
						m.show();
					}
				}
			}
			carVectA[awork].s2.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			aLine[lineindex].status = false;
		}
		else{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
			if (leaveStat == 2)
				carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);
			Sleep(1000);
			carVectA[awork].position = carVectA[awork].s2.top();
			carVectA[awork].s2.pop();
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
	while (carVectA[awork].s1.size() != 0)
	{
		if (strcmp(carVectA[awork].s1.top().c_str(), parkingA.Print(minap).index0.c_str()) != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s1.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectA[awork].position = carVectA[awork].s1.top();
					////cout << carVectB[workcar].position << endl;
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
				}
			}
			aLine[lineindex].status = false;
			carVectA[awork].s1.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
		}
		else{
			Sleep(1000);
			carVectA[awork].s1.pop();
			carVectA[awork].change(parkingA.Print(minap).x, parkingA.Print(minap).y, parkingA.Print(minap).length, parkingA.Print(minap).wide);

			if (minIndex == 1)
				carVectA[awork].occupy(aSpace[carVectA[awork].carindex].x, aSpace[carVectA[awork].carindex].y);
			if (minIndex == 2)
				carVectA[awork].occupy(cSpace[carVectA[awork].carindex].x, cSpace[carVectA[awork].carindex].y);
			for (int i = 0; i < aLineSize; i++){
				if (strcmp(carVectA[awork].position.c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectB[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
				}
			}
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			//cout << carVectB[workcar].eleNum << endl;
			if (carVectA[awork].eleNum <= 25)
			{
				//������Ҫ��� �����Խ�����
				carVectA[awork].eleFlag = 1;
				//ִ�г�����
				//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//��ʾ��Ҫͣ��
				carVectA[awork].status = false;//��ʾ���Խ�����
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "ͣ�����" << endl;
	//	MessageBox::Show("ͣ���������");
	/////////////////////////////////////////////////////2.A����ͣ������/////////////////////////////////////////////////////////////	
	int APARKIndex = 0;
	int aParkRet = 0;
	for (int v = 0; v < aSpacesize; v++)
	{
		if (aSpace[v].status == false)
			APARKIndex++;
	}
	for (int v = 0; v < cSpacesize; v++)
	{
		if (cSpace[v].status == false)
			APARKIndex++;
	}

	if (APARKIndex > aParkNum)
		aParkRet = 1;
	else
		aParkRet = 2;

	if (carVectA[awork].stop == 1)
	{
		for (int b = 0; b < aElesize; b++)
		{
			if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].restoreEle(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
			}
		}

		for (int p = 0; p < aLineSize; p++){
			if (strcmp(carVectA[awork].position.c_str(), aLine[p].index0.c_str()) == 0)
			{
				carVectA[awork].restoreLine(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
			}
		}
		int parkA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
		int *dist16 = new int[verNumA];
		int *path16 = new int[verNumA];
		parkingA.dijkstra(parkA, dist16, path16);

		for (int j = 0; j < aParksize1; j++)
		{
			aPark1[j].distance_A = dist16[parkingA.strgetIndex0(aPark1[j].index0.c_str())];
		}
		for (int j = 0; j < aParksize2; j++)
		{
			aPark2[j].distance_A = dist16[parkingA.strgetIndex0(aPark2[j].index0.c_str())];
		}

		vector<int> minParka;
		if (aParkRet == 1)
		{
			for (int k = 0; k < aParksize1; k++)
			{
				if (aPark1[k].status == false)
				{
					minParka.push_back(aPark1[k].distance_A);
				}
			}
		}

		if (aParkRet == 2)
		{
			for (int k = 0; k < aParksize2; k++)
			{
				if (aPark2[k].status == false)
				{
					minParka.push_back(aPark2[k].distance_A);
				}
			}
		}
		sort(minParka.begin(), minParka.end());
		//Ѱ������Ŀ���ͣ����
		if (aParkRet == 1)
		{
			for (int g = 0; g < aParksize1; g++)
			{
				if ((aPark1[g].distance_A == minParka[0]) && (aPark1[g].status == false))
				{
					parkindex = g;
					aPark1[g].status = true;
					break;
				}

			}
		}

		if (aParkRet == 2)
		{
			for (int g = 0; g < aParksize2; g++)
			{
				if ((aPark2[g].distance_A == minParka[0]) && (aPark2[g].status == false))
				{
					parkindex = g;
					aPark2[g].status = true;
					break;
				}

			}
		}


		//�����ʱ����v
		minParka.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minap = 0;
		if (aParkRet == 1)
		{
			minap = parkingA.strgetIndex0(aPark1[parkindex].index0.c_str());
			carVectA[awork].s3.push(aPark1[parkindex].index0.c_str());
			aparkstr.clear();
			aparkstr = aPark1[parkindex].index0;
		}

		if (aParkRet == 2)
		{
			minap = parkingA.strgetIndex0(aPark2[parkindex].index0.c_str());
			carVectA[awork].s3.push(aPark2[parkindex].index0.c_str());
			aparkstr.clear();
			aparkstr = aPark2[parkindex].index0;
		}
		for (int j = path16[minap]; j != parkA; j = path16[j])
			carVectA[awork].s3.push(parkingA.Print(j).index0.c_str());

		//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
		if (carVectA[awork].stop == 0)
		{
			//˵�������㹻���Խ�������������е����ж�
			if (aParkRet == 1)
				aPark1[parkindex].status = false;
			if (aParkRet == 2)
				aPark2[parkindex].status = false;
			while (!carVectA[awork].s3.empty())
				carVectA[awork].s3.pop();
			//break;
		}
		else{
			//����ִ��ͣ������
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			if (carVectA[awork].eleNum < 25)
			{
				//��s3���
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//ִ�г�����
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				carVectA[awork].eleFlag = 1;
				carVectA[awork].status = true;
				carVectA[awork].start = clock();
				//break;
			}
		}

		carVectA[awork].start = clock();
		carVectA[awork].eleStatus = 1;
		///С��ȥ��ͣ������ִ��
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectA[awork].s3.size() != 0)
		{
			//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
			if (carVectA[awork].stop == 0)
			{
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				break;
			}
			//��ȥͣ����;��ִ�е����ж�
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			///	carVectA[i].eleNum = 100;
			if (carVectA[awork].eleNum < 25)
			{
				//��s3���
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//ִ�г�����
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				carVectA[awork].eleFlag = 1;
				carVectA[awork].status = true;
				carVectA[awork].start = clock();
				break;
			}

			if (strcmp(carVectA[awork].s3.top().c_str(), aparkstr.c_str()) != 0)
			{
				for (int p = 0; p < aLineSize; p++)
				{
					if (strcmp(carVectA[awork].s3.top().c_str(), aLine[p].index0.c_str()) == 0)
					{
						carVectA[awork].position = carVectA[awork].s3.top().c_str();
						lineindex = p;
						if (aLine[p].status == false)
						{
							aLine[p].status = true;
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							aLine[lineindex].status = false;
							carVectA[awork].s3.pop();
							m.show();
						}
						else{
							Sleep(2000);
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							aLine[lineindex].status = false;
							carVectA[awork].s3.pop();
							m.show();
						}
					}
				}
				//Sleep(2000);
				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
				//cout << carVectA[awork].index << "ͣ������" << carVectA[awork].s3.size() <<"��"<< endl;
			}
			else{
				carVectA[awork].position = carVectA[awork].s3.top().c_str();
				carVectA[awork].s3.pop();
				//cout << carVectA[awork].index << "ͣ�����һ��" << endl;
				if (aParkRet == 1){
					for (int b = 0; b < aParksize1; b++)
					{
						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//��s3���
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								//ִ�г�����
								carVectA[awork].status = true;
								carVectA[awork].eleFlag = 1;
								carVectA[awork].start = clock();
								break;
							}

							carVectA[awork].change(aPark1[b].x, aPark1[b].y, aPark1[b].length, aPark1[b].wide);
							carVectA[awork].start = clock();
							carVectA[awork].eleStatus = 0;
							m.show();
						}
					}
				}

				if (aParkRet == 2){
					for (int b = 0; b < aParksize2; b++)
					{
						if (strcmp(aPark2[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//��s3���
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								//ִ�г�����
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								carVectA[awork].status = true;
								carVectA[awork].eleFlag = 1;
								carVectA[awork].start = clock();
								break;
							}

							carVectA[awork].change(aPark2[b].x, aPark2[b].y, aPark2[b].length, aPark2[b].wide);
							carVectA[awork].start = clock();
							carVectA[awork].eleStatus = 0;
							m.show();
						}
					}
				}
			}
		}
	}
	/////////////A�ĳ�����////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (carVectA[awork].eleFlag == 1)
	{
		//�жϴ���һ����ִ�г�����
		//ͣ����
		for (int o = 0; o < aParksize1; o++)
		{
			if (strcmp(aPark1[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aPark1[o].x, aPark1[o].y, aPark1[o].length, aPark1[o].wide);
				aPark1[o].status = false;
				leavePosi = awork;
				leaveStat = 0;
				aParkindex = 1;
			}
		}
		for (int o = 0; o < aParksize2; o++)
		{
			if (strcmp(aPark2[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aPark2[o].x, aPark2[o].y, aPark2[o].length, aPark2[o].wide);
				aPark2[o].status = false;
				leavePosi = awork;
				leaveStat = 0;
				aParkindex = 2;
			}
		}
		//2.С������·�нӵ�
		for (int o = 0; o < aLineSize; o++)
		{
			if (strcmp(aLine[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aLine[o].x, aLine[o].y, aLine[o].length, aLine[o].wide);
				aLine[o].status = false;
				leavePosi = o;
				leaveStat = 1;
			}
		}


		int eleA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
		int *dist12 = new int[verNumA];
		int *path12 = new int[verNumA];
		parkingA.dijkstra(eleA, dist12, path12);

		for (int j = 0; j < aElesize; j++)
		{
			aEle[j].ele_Distance = dist12[parkingA.strgetIndex0(aEle[j].index0.c_str())];
		}
		vector<int> minElea;
		for (int k = 0; k < aElesize; k++)
		{
			if (aEle[k].status == false)
			{
				minElea.push_back(aEle[k].ele_Distance);
			}
		}
		sort(minElea.begin(), minElea.end());
		//Ѱ������Ŀ��г���
		for (int g = 0; g < aElesize; g++)
		{
			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
			{
				parkindex = g;
				aEle[g].status = true;
				break;
			}
		}
		//�����ʱ����v
		minElea.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minap = 0;
		minap = parkingA.strgetIndex0(aEle[parkindex].index0.c_str());
		////cout << aEle[parkindex].index0 << endl;
		while (!carVectA[awork].s6.empty())
			carVectA[awork].s6.pop();
		carVectA[awork].s6.push(aEle[parkindex].index0.c_str());
		for (int j = path12[minap]; j != eleA; j = path12[j])
			carVectA[awork].s6.push(parkingA.Print(j).index0.c_str());


		carVectA[awork].start = clock();
		carVectA[awork].eleStatus = 2;
		///С��ȥ���������ִ��
		while (carVectA[awork].s6.size() != 0)
		{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);

			if (strcmp(carVectA[awork].s6.top().c_str(), aEle[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < aLineSize; p++)
				{
					if (strcmp(carVectA[awork].s6.top().c_str(), aLine[p].index0.c_str()) == 0)
					{
						carVectA[awork].position = carVectA[awork].s6.top().c_str();
						lineindex = p;
						if (aLine[p].status == false)
						{
							aLine[p].status = true;
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							m.show();
						}
					}
				}
				aLine[lineindex].status = false;
				carVectA[awork].s6.pop();
				Sleep(2000);
				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			}
			else{
				carVectA[awork].position = carVectA[awork].s6.top().c_str();
				carVectA[awork].s6.pop();
				carVectA[awork].position = aEle[parkindex].index0;
				for (int b = 0; b < aElesize; b++)
				{
					if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
					{
						carVectA[awork].change(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
						carVectA[awork].eleStatus = 2;
						m.show();
					}
				}
				carVectA[awork].status = false;
				carVectA[awork].stop = 1;
				carVectA[awork].start = clock();
				carVectA[awork].eleNum = 100;

			}
		}
	}
	///////////������/////////////////////////////////////////////
	/////////////////////////////////////
}

void aParkProCar7()
{
	int awork = 3;
	carVectA[awork].status = true;//��״̬��Ϊʹ��
	carVectA[awork].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
	carVectA[awork].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
	cout << "������С���±���" << carVectA[awork].index << endl;
	//MessageBox::Show("����С�����±�Ϊ:" + carVectA[workcar].index);
	vector<int> aminDist;
	//ѡ������ĳ�λ
	for (int i = 0; i < aSpacesize; i++)
	{
		if (aSpace[i].status == false)
			aminDist.push_back(aSpace[i].distance_A);
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if (cSpace[i].status == false)
			aminDist.push_back(cSpace[i].distance_A);
	}
	sort(aminDist.begin(), aminDist.end());
	//�ж������λ���ĸ�����
	for (int i = 0; i < aSpacesize; i++)
	{
		if ((aminDist[0] == aSpace[i].distance_A) && (aSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			aSpace[i].status = true;
			aSpace[i].license = license;
			carVectA[awork].book(aSpace[i].x, aSpace[i].y);
			minIndex = 1;
			break;
		}
	}

	for (int i = 0; i < cSpacesize; i++)
	{
		if ((aminDist[0] == cSpace[i].distance_A) && (cSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			cSpace[i].status = true;
			cSpace[i].license = license;
			carVectA[awork].book(cSpace[i].x, cSpace[i].y);
			minIndex = 2;
			break;
		}
	}
	aminDist.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��

	int minap;//��ȡ�����λ��ͼ�е��������
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//������ѡ��������λ
	//��ȡ���ڵ������λ��·��
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//��С����ǰλ��Ϊ�����㵽���ڵ����·��
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//��ȡС�������ڵ����·��
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//��¼����С���뿪ʱ��λ��
	//1.С����ͣ�����ӵ�����
	for (int i = 0; i < aParksize1; i++)
	{
		if (strcmp(aPark1[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark1[i].x, aPark1[i].y, aPark1[i].length, aPark1[i].wide);
			aPark1[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 1;
		}
	}
	for (int i = 0; i < aParksize2; i++)
	{
		if (strcmp(aPark2[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark2[i].x, aPark2[i].y, aPark2[i].length, aPark2[i].wide);
			aPark2[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 2;
		}
	}
	//2.С������·�нӵ�����
	for (int i = 0; i < aLineSize; i++)
	{
		if (strcmp(aLine[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
			aLine[i].status = false;
			leavePosi = i;
			leaveStat = 1;
		}
	}
	//3.С���ӳ�����ӵ�����
	for (int i = 0; i < aElesize; i++)
	{
		if (strcmp(aEle[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aEle[i].x, aEle[i].y, aEle[i].length, aEle[i].wide);
			aEle[i].status = false;
			leavePosi = i;
			leaveStat = 2;
		}
	}

	//����С��ȥ���ڵĹ���
	carVectA[awork].eleStatus = 1;
	carVectA[awork].start = clock();
	while (carVectA[awork].s2.size() != 0)
	{
		if (leaveStat == 0)
		{
			if (aParkindex == 1)
			{
				carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
			}
			if (aParkindex == 2)
			{
				carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
			}
		}

		if (leaveStat == 1)
			carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
		if (leaveStat == 2)
			carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);

		if (strcmp(carVectA[awork].s2.top().c_str(), "R00") != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s2.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;											
						m.show();
					}
				}
			}
			carVectA[awork].s2.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			aLine[lineindex].status = false;
		}
		else{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
			if (leaveStat == 2)
				carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);
			Sleep(1000);
			carVectA[awork].position = carVectA[awork].s2.top();
			carVectA[awork].s2.pop();
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
	while (carVectA[awork].s1.size() != 0)
	{
		if (strcmp(carVectA[awork].s1.top().c_str(), parkingA.Print(minap).index0.c_str()) != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s1.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectA[awork].position = carVectA[awork].s1.top();
					////cout << carVectB[workcar].position << endl;
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
				}
			}
			aLine[lineindex].status = false;
			carVectA[awork].s1.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
		}
		else{
			Sleep(1000);
			carVectA[awork].s1.pop();
			carVectA[awork].change(parkingA.Print(minap).x, parkingA.Print(minap).y, parkingA.Print(minap).length, parkingA.Print(minap).wide);

			if (minIndex == 1)
				carVectA[awork].occupy(aSpace[carVectA[awork].carindex].x, aSpace[carVectA[awork].carindex].y);
			if (minIndex == 2)
				carVectA[awork].occupy(cSpace[carVectA[awork].carindex].x, cSpace[carVectA[awork].carindex].y);
			for (int i = 0; i < aLineSize; i++){
				if (strcmp(carVectA[awork].position.c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectB[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
				}
			}
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			//cout << carVectB[workcar].eleNum << endl;
			if (carVectA[awork].eleNum <= 25)
			{
				//������Ҫ��� �����Խ�����
				carVectA[awork].eleFlag = 1;
				//ִ�г�����
				//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//��ʾ��Ҫͣ��
				carVectA[awork].status = false;//��ʾ���Խ�����
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "ͣ�����" << endl;
	//	MessageBox::Show("ͣ���������");
	/////////////////////////////////////////////////////2.A����ͣ������/////////////////////////////////////////////////////////////	
	int APARKIndex = 0;
	int aParkRet = 0;
	for (int v = 0; v < aSpacesize; v++)
	{
		if (aSpace[v].status == false)
			APARKIndex++;
	}
	for (int v = 0; v < cSpacesize; v++)
	{
		if (cSpace[v].status == false)
			APARKIndex++;
	}

	if (APARKIndex > aParkNum)
		aParkRet = 1;
	else
		aParkRet = 2;

	if (carVectA[awork].stop == 1)
	{
		for (int b = 0; b < aElesize; b++)
		{
			if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].restoreEle(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
			}
		}

		for (int p = 0; p < aLineSize; p++){
			if (strcmp(carVectA[awork].position.c_str(), aLine[p].index0.c_str()) == 0)
			{
				carVectA[awork].restoreLine(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
			}
		}
		int parkA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
		int *dist16 = new int[verNumA];
		int *path16 = new int[verNumA];
		parkingA.dijkstra(parkA, dist16, path16);

		for (int j = 0; j < aParksize1; j++)
		{
			aPark1[j].distance_A = dist16[parkingA.strgetIndex0(aPark1[j].index0.c_str())];
		}
		for (int j = 0; j < aParksize2; j++)
		{
			aPark2[j].distance_A = dist16[parkingA.strgetIndex0(aPark2[j].index0.c_str())];
		}

		vector<int> minParka;
		if (aParkRet == 1)
		{
			for (int k = 0; k < aParksize1; k++)
			{
				if (aPark1[k].status == false)
				{
					minParka.push_back(aPark1[k].distance_A);
				}
			}
		}

		if (aParkRet == 2)
		{
			for (int k = 0; k < aParksize2; k++)
			{
				if (aPark2[k].status == false)
				{
					minParka.push_back(aPark2[k].distance_A);
				}
			}
		}
		sort(minParka.begin(), minParka.end());
		//Ѱ������Ŀ���ͣ����
		if (aParkRet == 1)
		{
			for (int g = 0; g < aParksize1; g++)
			{
				if ((aPark1[g].distance_A == minParka[0]) && (aPark1[g].status == false))
				{
					parkindex = g;
					aPark1[g].status = true;
					break;
				}

			}
		}

		if (aParkRet == 2)
		{
			for (int g = 0; g < aParksize2; g++)
			{
				if ((aPark2[g].distance_A == minParka[0]) && (aPark2[g].status == false))
				{
					parkindex = g;
					aPark2[g].status = true;
					break;
				}

			}
		}


		//�����ʱ����v
		minParka.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minap = 0;
		if (aParkRet == 1)
		{
			minap = parkingA.strgetIndex0(aPark1[parkindex].index0.c_str());
			carVectA[awork].s3.push(aPark1[parkindex].index0.c_str());
			aparkstr.clear();
			aparkstr = aPark1[parkindex].index0;
		}

		if (aParkRet == 2)
		{
			minap = parkingA.strgetIndex0(aPark2[parkindex].index0.c_str());
			carVectA[awork].s3.push(aPark2[parkindex].index0.c_str());
			aparkstr.clear();
			aparkstr = aPark2[parkindex].index0;
		}
		for (int j = path16[minap]; j != parkA; j = path16[j])
			carVectA[awork].s3.push(parkingA.Print(j).index0.c_str());

		//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
		if (carVectA[awork].stop == 0)
		{
			//˵�������㹻���Խ�������������е����ж�
			if (aParkRet == 1)
				aPark1[parkindex].status = false;
			if (aParkRet == 2)
				aPark2[parkindex].status = false;
			while (!carVectA[awork].s3.empty())
				carVectA[awork].s3.pop();
			//break;
		}
		else{
			//����ִ��ͣ������
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			if (carVectA[awork].eleNum < 25)
			{
				//��s3���
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//ִ�г�����
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				carVectA[awork].eleFlag = 1;
				carVectA[awork].status = true;
				carVectA[awork].start = clock();
				//break;
			}
		}

		carVectA[awork].start = clock();
		carVectA[awork].eleStatus = 1;
		///С��ȥ��ͣ������ִ��
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectA[awork].s3.size() != 0)
		{
			//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
			if (carVectA[awork].stop == 0)
			{
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				break;
			}
			//��ȥͣ����;��ִ�е����ж�
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			///	carVectA[i].eleNum = 100;
			if (carVectA[awork].eleNum < 25)
			{
				//��s3���
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//ִ�г�����
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				carVectA[awork].eleFlag = 1;
				carVectA[awork].status = true;
				carVectA[awork].start = clock();
				break;
			}

			if (strcmp(carVectA[awork].s3.top().c_str(), aparkstr.c_str()) != 0)
			{
				for (int p = 0; p < aLineSize; p++)
				{
					if (strcmp(carVectA[awork].s3.top().c_str(), aLine[p].index0.c_str()) == 0)
					{
						carVectA[awork].position = carVectA[awork].s3.top().c_str();
						lineindex = p;
						if (aLine[p].status == false)
						{
							aLine[p].status = true;
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							aLine[lineindex].status = false;
							carVectA[awork].s3.pop();
							m.show();
						}
						else{
							Sleep(2000);
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							aLine[lineindex].status = false;
							carVectA[awork].s3.pop();
							m.show();
						}
					}
				}
				//Sleep(2000);
				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
				//cout << carVectA[awork].index << "ͣ������" << carVectA[awork].s3.size() <<"��"<< endl;
			}
			else{
				carVectA[awork].position = carVectA[awork].s3.top().c_str();
				carVectA[awork].s3.pop();
				//cout << carVectA[awork].index << "ͣ�����һ��" << endl;
				if (aParkRet == 1){
					for (int b = 0; b < aParksize1; b++)
					{
						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//��s3���
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								//ִ�г�����
								carVectA[awork].status = true;
								carVectA[awork].eleFlag = 1;
								carVectA[awork].start = clock();
								break;
							}

							carVectA[awork].change(aPark1[b].x, aPark1[b].y, aPark1[b].length, aPark1[b].wide);
							carVectA[awork].start = clock();
							carVectA[awork].eleStatus = 0;
							m.show();
						}
					}
				}

				if (aParkRet == 2){
					for (int b = 0; b < aParksize2; b++)
					{
						if (strcmp(aPark2[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//��s3���
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								//ִ�г�����
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								carVectA[awork].status = true;
								carVectA[awork].eleFlag = 1;
								carVectA[awork].start = clock();
								break;
							}

							carVectA[awork].change(aPark2[b].x, aPark2[b].y, aPark2[b].length, aPark2[b].wide);
							carVectA[awork].start = clock();
							carVectA[awork].eleStatus = 0;
							m.show();
						}
					}
				}
			}
		}
	}
	/////////////A�ĳ�����////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (carVectA[awork].eleFlag == 1)
	{
		//�жϴ���һ����ִ�г�����
		//ͣ����
		for (int o = 0; o < aParksize1; o++)
		{
			if (strcmp(aPark1[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aPark1[o].x, aPark1[o].y, aPark1[o].length, aPark1[o].wide);
				aPark1[o].status = false;
				leavePosi = awork;
				leaveStat = 0;
				aParkindex = 1;
			}
		}
		for (int o = 0; o < aParksize2; o++)
		{
			if (strcmp(aPark2[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aPark2[o].x, aPark2[o].y, aPark2[o].length, aPark2[o].wide);
				aPark2[o].status = false;
				leavePosi = awork;
				leaveStat = 0;
				aParkindex = 2;
			}
		}
		//2.С������·�нӵ�
		for (int o = 0; o < aLineSize; o++)
		{
			if (strcmp(aLine[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aLine[o].x, aLine[o].y, aLine[o].length, aLine[o].wide);
				aLine[o].status = false;
				leavePosi = o;
				leaveStat = 1;
			}
		}


		int eleA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
		int *dist12 = new int[verNumA];
		int *path12 = new int[verNumA];
		parkingA.dijkstra(eleA, dist12, path12);

		for (int j = 0; j < aElesize; j++)
		{
			aEle[j].ele_Distance = dist12[parkingA.strgetIndex0(aEle[j].index0.c_str())];
		}
		vector<int> minElea;
		for (int k = 0; k < aElesize; k++)
		{
			if (aEle[k].status == false)
			{
				minElea.push_back(aEle[k].ele_Distance);
			}
		}
		sort(minElea.begin(), minElea.end());
		//Ѱ������Ŀ��г���
		for (int g = 0; g < aElesize; g++)
		{
			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
			{
				parkindex = g;
				aEle[g].status = true;
				break;
			}
		}
		//�����ʱ����v
		minElea.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minap = 0;
		minap = parkingA.strgetIndex0(aEle[parkindex].index0.c_str());
		////cout << aEle[parkindex].index0 << endl;
		while (!carVectA[awork].s6.empty())
			carVectA[awork].s6.pop();
		carVectA[awork].s6.push(aEle[parkindex].index0.c_str());
		for (int j = path12[minap]; j != eleA; j = path12[j])
			carVectA[awork].s6.push(parkingA.Print(j).index0.c_str());


		carVectA[awork].start = clock();
		carVectA[awork].eleStatus = 2;
		///С��ȥ���������ִ��
		while (carVectA[awork].s6.size() != 0)
		{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);

			if (strcmp(carVectA[awork].s6.top().c_str(), aEle[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < aLineSize; p++)
				{
					if (strcmp(carVectA[awork].s6.top().c_str(), aLine[p].index0.c_str()) == 0)
					{
						carVectA[awork].position = carVectA[awork].s6.top().c_str();
						lineindex = p;
						if (aLine[p].status == false)
						{
							aLine[p].status = true;
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							m.show();
						}
					}
				}
				aLine[lineindex].status = false;
				carVectA[awork].s6.pop();
				Sleep(2000);
				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			}
			else{
				carVectA[awork].position = carVectA[awork].s6.top().c_str();
				carVectA[awork].s6.pop();
				carVectA[awork].position = aEle[parkindex].index0;
				for (int b = 0; b < aElesize; b++)
				{
					if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
					{
						carVectA[awork].change(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
						carVectA[awork].eleStatus = 2;
						m.show();
					}
				}
				carVectA[awork].status = false;
				carVectA[awork].stop = 1;
				carVectA[awork].start = clock();
				carVectA[awork].eleNum = 100;

			}
		}
	}
	///////////������/////////////////////////////////////////////
	/////////////////////////////////////
}

void aParkProCar8()
{
	int awork = 4;
	carVectA[awork].status = true;//��״̬��Ϊʹ��
	carVectA[awork].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
	carVectA[awork].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
	cout << "������С���±���" << carVectA[awork].index << endl;
	//MessageBox::Show("����С�����±�Ϊ:" + carVectA[workcar].index);
	vector<int> aminDist;
	//ѡ������ĳ�λ
	for (int i = 0; i < aSpacesize; i++)
	{
		if (aSpace[i].status == false)
			aminDist.push_back(aSpace[i].distance_A);
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if (cSpace[i].status == false)
			aminDist.push_back(cSpace[i].distance_A);
	}
	sort(aminDist.begin(), aminDist.end());
	//�ж������λ���ĸ�����
	for (int i = 0; i < aSpacesize; i++)
	{
		if ((aminDist[0] == aSpace[i].distance_A) && (aSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			aSpace[i].status = true;
			aSpace[i].license = license;
			carVectA[awork].book(aSpace[i].x, aSpace[i].y);
			minIndex = 1;
			break;
		}
	}

	for (int i = 0; i < cSpacesize; i++)
	{
		if ((aminDist[0] == cSpace[i].distance_A) && (cSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			cSpace[i].status = true;
			cSpace[i].license = license;
			carVectA[awork].book(cSpace[i].x, cSpace[i].y);
			minIndex = 2;
			break;
		}
	}
	aminDist.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��

	int minap;//��ȡ�����λ��ͼ�е��������
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//������ѡ��������λ
	//��ȡ���ڵ������λ��·��
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//��С����ǰλ��Ϊ�����㵽���ڵ����·��
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//��ȡС�������ڵ����·��
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//��¼����С���뿪ʱ��λ��
	//1.С����ͣ�����ӵ�����
	for (int i = 0; i < aParksize1; i++)
	{
		if (strcmp(aPark1[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark1[i].x, aPark1[i].y, aPark1[i].length, aPark1[i].wide);
			aPark1[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 1;
		}
	}
	for (int i = 0; i < aParksize2; i++)
	{
		if (strcmp(aPark2[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark2[i].x, aPark2[i].y, aPark2[i].length, aPark2[i].wide);
			aPark2[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 2;
		}
	}
	//2.С������·�нӵ�����
	for (int i = 0; i < aLineSize; i++)
	{
		if (strcmp(aLine[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
			aLine[i].status = false;
			leavePosi = i;
			leaveStat = 1;
		}
	}
	//3.С���ӳ�����ӵ�����
	for (int i = 0; i < aElesize; i++)
	{
		if (strcmp(aEle[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aEle[i].x, aEle[i].y, aEle[i].length, aEle[i].wide);
			aEle[i].status = false;
			leavePosi = i;
			leaveStat = 2;
		}
	}

	//����С��ȥ���ڵĹ���
	carVectA[awork].eleStatus = 1;
	carVectA[awork].start = clock();
	while (carVectA[awork].s2.size() != 0)
	{
		if (leaveStat == 0)
		{
			if (aParkindex == 1)
			{
				carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
			}
			if (aParkindex == 2)
			{
				carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
			}
		}

		if (leaveStat == 1)
			carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
		if (leaveStat == 2)
			carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);

		if (strcmp(carVectA[awork].s2.top().c_str(), "R00") != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s2.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;											
						m.show();
					}
				}
			}
			carVectA[awork].s2.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			aLine[lineindex].status = false;
		}
		else{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
			if (leaveStat == 2)
				carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);
			Sleep(1000);
			carVectA[awork].position = carVectA[awork].s2.top();
			carVectA[awork].s2.pop();
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
	while (carVectA[awork].s1.size() != 0)
	{
		if (strcmp(carVectA[awork].s1.top().c_str(), parkingA.Print(minap).index0.c_str()) != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s1.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectA[awork].position = carVectA[awork].s1.top();
					////cout << carVectB[workcar].position << endl;
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
				}
			}
			aLine[lineindex].status = false;
			carVectA[awork].s1.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
		}
		else{
			Sleep(1000);
			carVectA[awork].s1.pop();
			carVectA[awork].change(parkingA.Print(minap).x, parkingA.Print(minap).y, parkingA.Print(minap).length, parkingA.Print(minap).wide);

			if (minIndex == 1)
				carVectA[awork].occupy(aSpace[carVectA[awork].carindex].x, aSpace[carVectA[awork].carindex].y);
			if (minIndex == 2)
				carVectA[awork].occupy(cSpace[carVectA[awork].carindex].x, cSpace[carVectA[awork].carindex].y);
			for (int i = 0; i < aLineSize; i++){
				if (strcmp(carVectA[awork].position.c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectB[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
				}
			}
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			//cout << carVectB[workcar].eleNum << endl;
			if (carVectA[awork].eleNum <= 25)
			{
				//������Ҫ��� �����Խ�����
				carVectA[awork].eleFlag = 1;
				//ִ�г�����
				//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//��ʾ��Ҫͣ��
				carVectA[awork].status = false;//��ʾ���Խ�����
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "ͣ�����" << endl;
	//	MessageBox::Show("ͣ���������");
	/////////////////////////////////////////////////////2.A����ͣ������/////////////////////////////////////////////////////////////	
	int APARKIndex = 0;
	int aParkRet = 0;
	for (int v = 0; v < aSpacesize; v++)
	{
		if (aSpace[v].status == false)
			APARKIndex++;
	}
	for (int v = 0; v < cSpacesize; v++)
	{
		if (cSpace[v].status == false)
			APARKIndex++;
	}

	if (APARKIndex > aParkNum)
		aParkRet = 1;
	else
		aParkRet = 2;

	if (carVectA[awork].stop == 1)
	{
		for (int b = 0; b < aElesize; b++)
		{
			if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].restoreEle(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
			}
		}

		for (int p = 0; p < aLineSize; p++){
			if (strcmp(carVectA[awork].position.c_str(), aLine[p].index0.c_str()) == 0)
			{
				carVectA[awork].restoreLine(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
			}
		}
		int parkA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
		int *dist16 = new int[verNumA];
		int *path16 = new int[verNumA];
		parkingA.dijkstra(parkA, dist16, path16);

		for (int j = 0; j < aParksize1; j++)
		{
			aPark1[j].distance_A = dist16[parkingA.strgetIndex0(aPark1[j].index0.c_str())];
		}
		for (int j = 0; j < aParksize2; j++)
		{
			aPark2[j].distance_A = dist16[parkingA.strgetIndex0(aPark2[j].index0.c_str())];
		}

		vector<int> minParka;
		if (aParkRet == 1)
		{
			for (int k = 0; k < aParksize1; k++)
			{
				if (aPark1[k].status == false)
				{
					minParka.push_back(aPark1[k].distance_A);
				}
			}
		}

		if (aParkRet == 2)
		{
			for (int k = 0; k < aParksize2; k++)
			{
				if (aPark2[k].status == false)
				{
					minParka.push_back(aPark2[k].distance_A);
				}
			}
		}
		sort(minParka.begin(), minParka.end());
		//Ѱ������Ŀ���ͣ����
		if (aParkRet == 1)
		{
			for (int g = 0; g < aParksize1; g++)
			{
				if ((aPark1[g].distance_A == minParka[0]) && (aPark1[g].status == false))
				{
					parkindex = g;
					aPark1[g].status = true;
					break;
				}

			}
		}

		if (aParkRet == 2)
		{
			for (int g = 0; g < aParksize2; g++)
			{
				if ((aPark2[g].distance_A == minParka[0]) && (aPark2[g].status == false))
				{
					parkindex = g;
					aPark2[g].status = true;
					break;
				}

			}
		}


		//�����ʱ����v
		minParka.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minap = 0;
		if (aParkRet == 1)
		{
			minap = parkingA.strgetIndex0(aPark1[parkindex].index0.c_str());
			carVectA[awork].s3.push(aPark1[parkindex].index0.c_str());
			aparkstr.clear();
			aparkstr = aPark1[parkindex].index0;
		}

		if (aParkRet == 2)
		{
			minap = parkingA.strgetIndex0(aPark2[parkindex].index0.c_str());
			carVectA[awork].s3.push(aPark2[parkindex].index0.c_str());
			aparkstr.clear();
			aparkstr = aPark2[parkindex].index0;
		}
		for (int j = path16[minap]; j != parkA; j = path16[j])
			carVectA[awork].s3.push(parkingA.Print(j).index0.c_str());

		//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
		if (carVectA[awork].stop == 0)
		{
			//˵�������㹻���Խ�������������е����ж�
			if (aParkRet == 1)
				aPark1[parkindex].status = false;
			if (aParkRet == 2)
				aPark2[parkindex].status = false;
			while (!carVectA[awork].s3.empty())
				carVectA[awork].s3.pop();
			//break;
		}
		else{
			//����ִ��ͣ������
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			if (carVectA[awork].eleNum < 25)
			{
				//��s3���
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//ִ�г�����
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				carVectA[awork].eleFlag = 1;
				carVectA[awork].status = true;
				carVectA[awork].start = clock();
				//break;
			}
		}

		carVectA[awork].start = clock();
		carVectA[awork].eleStatus = 1;
		///С��ȥ��ͣ������ִ��
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectA[awork].s3.size() != 0)
		{
			//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
			if (carVectA[awork].stop == 0)
			{
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				break;
			}
			//��ȥͣ����;��ִ�е����ж�
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			///	carVectA[i].eleNum = 100;
			if (carVectA[awork].eleNum < 25)
			{
				//��s3���
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//ִ�г�����
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				carVectA[awork].eleFlag = 1;
				carVectA[awork].status = true;
				carVectA[awork].start = clock();
				break;
			}

			if (strcmp(carVectA[awork].s3.top().c_str(), aparkstr.c_str()) != 0)
			{
				for (int p = 0; p < aLineSize; p++)
				{
					if (strcmp(carVectA[awork].s3.top().c_str(), aLine[p].index0.c_str()) == 0)
					{
						carVectA[awork].position = carVectA[awork].s3.top().c_str();
						lineindex = p;
						if (aLine[p].status == false)
						{
							aLine[p].status = true;
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							aLine[lineindex].status = false;
							carVectA[awork].s3.pop();
							m.show();
						}
						else{
							Sleep(2000);
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							aLine[lineindex].status = false;
							carVectA[awork].s3.pop();
							m.show();
						}
					}
				}
				//Sleep(2000);
				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
				//cout << carVectA[awork].index << "ͣ������" << carVectA[awork].s3.size() <<"��"<< endl;
			}
			else{
				carVectA[awork].position = carVectA[awork].s3.top().c_str();
				carVectA[awork].s3.pop();
				//cout << carVectA[awork].index << "ͣ�����һ��" << endl;
				if (aParkRet == 1){
					for (int b = 0; b < aParksize1; b++)
					{
						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//��s3���
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								//ִ�г�����
								carVectA[awork].status = true;
								carVectA[awork].eleFlag = 1;
								carVectA[awork].start = clock();
								break;
							}

							carVectA[awork].change(aPark1[b].x, aPark1[b].y, aPark1[b].length, aPark1[b].wide);
							carVectA[awork].start = clock();
							carVectA[awork].eleStatus = 0;
							m.show();
						}
					}
				}

				if (aParkRet == 2){
					for (int b = 0; b < aParksize2; b++)
					{
						if (strcmp(aPark2[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//��s3���
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								//ִ�г�����
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								carVectA[awork].status = true;
								carVectA[awork].eleFlag = 1;
								carVectA[awork].start = clock();
								break;
							}

							carVectA[awork].change(aPark2[b].x, aPark2[b].y, aPark2[b].length, aPark2[b].wide);
							carVectA[awork].start = clock();
							carVectA[awork].eleStatus = 0;
							m.show();
						}
					}
				}
			}
		}
	}
	/////////////A�ĳ�����////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (carVectA[awork].eleFlag == 1)
	{
		//�жϴ���һ����ִ�г�����
		//ͣ����
		for (int o = 0; o < aParksize1; o++)
		{
			if (strcmp(aPark1[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aPark1[o].x, aPark1[o].y, aPark1[o].length, aPark1[o].wide);
				aPark1[o].status = false;
				leavePosi = awork;
				leaveStat = 0;
				aParkindex = 1;
			}
		}
		for (int o = 0; o < aParksize2; o++)
		{
			if (strcmp(aPark2[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aPark2[o].x, aPark2[o].y, aPark2[o].length, aPark2[o].wide);
				aPark2[o].status = false;
				leavePosi = awork;
				leaveStat = 0;
				aParkindex = 2;
			}
		}
		//2.С������·�нӵ�
		for (int o = 0; o < aLineSize; o++)
		{
			if (strcmp(aLine[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aLine[o].x, aLine[o].y, aLine[o].length, aLine[o].wide);
				aLine[o].status = false;
				leavePosi = o;
				leaveStat = 1;
			}
		}


		int eleA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
		int *dist12 = new int[verNumA];
		int *path12 = new int[verNumA];
		parkingA.dijkstra(eleA, dist12, path12);

		for (int j = 0; j < aElesize; j++)
		{
			aEle[j].ele_Distance = dist12[parkingA.strgetIndex0(aEle[j].index0.c_str())];
		}
		vector<int> minElea;
		for (int k = 0; k < aElesize; k++)
		{
			if (aEle[k].status == false)
			{
				minElea.push_back(aEle[k].ele_Distance);
			}
		}
		sort(minElea.begin(), minElea.end());
		//Ѱ������Ŀ��г���
		for (int g = 0; g < aElesize; g++)
		{
			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
			{
				parkindex = g;
				aEle[g].status = true;
				break;
			}
		}
		//�����ʱ����v
		minElea.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minap = 0;
		minap = parkingA.strgetIndex0(aEle[parkindex].index0.c_str());
		////cout << aEle[parkindex].index0 << endl;
		while (!carVectA[awork].s6.empty())
			carVectA[awork].s6.pop();
		carVectA[awork].s6.push(aEle[parkindex].index0.c_str());
		for (int j = path12[minap]; j != eleA; j = path12[j])
			carVectA[awork].s6.push(parkingA.Print(j).index0.c_str());


		carVectA[awork].start = clock();
		carVectA[awork].eleStatus = 2;
		///С��ȥ���������ִ��
		while (carVectA[awork].s6.size() != 0)
		{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);

			if (strcmp(carVectA[awork].s6.top().c_str(), aEle[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < aLineSize; p++)
				{
					if (strcmp(carVectA[awork].s6.top().c_str(), aLine[p].index0.c_str()) == 0)
					{
						carVectA[awork].position = carVectA[awork].s6.top().c_str();
						lineindex = p;
						if (aLine[p].status == false)
						{
							aLine[p].status = true;
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							m.show();
						}
					}
				}
				aLine[lineindex].status = false;
				carVectA[awork].s6.pop();
				Sleep(2000);
				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			}
			else{
				carVectA[awork].position = carVectA[awork].s6.top().c_str();
				carVectA[awork].s6.pop();
				carVectA[awork].position = aEle[parkindex].index0;
				for (int b = 0; b < aElesize; b++)
				{
					if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
					{
						carVectA[awork].change(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
						carVectA[awork].eleStatus = 2;
						m.show();
					}
				}
				carVectA[awork].status = false;
				carVectA[awork].stop = 1;
				carVectA[awork].start = clock();
				carVectA[awork].eleNum = 100;

			}
		}
	}
	///////////������/////////////////////////////////////////////
	/////////////////////////////////////
}

void aParkProCar9()
{
	int awork = 5;
	carVectA[awork].status = true;//��״̬��Ϊʹ��
	carVectA[awork].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
	carVectA[awork].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
	cout << "������С���±���" << carVectA[awork].index << endl;
	//MessageBox::Show("����С�����±�Ϊ:" + carVectA[workcar].index);
	vector<int> aminDist;
	//ѡ������ĳ�λ
	for (int i = 0; i < aSpacesize; i++)
	{
		if (aSpace[i].status == false)
			aminDist.push_back(aSpace[i].distance_A);
	}
	for (int i = 0; i < cSpacesize; i++)
	{
		if (cSpace[i].status == false)
			aminDist.push_back(cSpace[i].distance_A);
	}
	sort(aminDist.begin(), aminDist.end());
	//�ж������λ���ĸ�����
	for (int i = 0; i < aSpacesize; i++)
	{
		if ((aminDist[0] == aSpace[i].distance_A) && (aSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			aSpace[i].status = true;
			aSpace[i].license = license;
			carVectA[awork].book(aSpace[i].x, aSpace[i].y);
			minIndex = 1;
			break;
		}
	}

	for (int i = 0; i < cSpacesize; i++)
	{
		if ((aminDist[0] == cSpace[i].distance_A) && (cSpace[i].status == false))
		{
			carVectA[awork].carindex = i;
			cSpace[i].status = true;
			cSpace[i].license = license;
			carVectA[awork].book(cSpace[i].x, cSpace[i].y);
			minIndex = 2;
			break;
		}
	}
	aminDist.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��

	int minap;//��ȡ�����λ��ͼ�е��������
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//������ѡ��������λ
	//��ȡ���ڵ������λ��·��
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//��С����ǰλ��Ϊ�����㵽���ڵ����·��
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//��ȡС�������ڵ����·��
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//��¼����С���뿪ʱ��λ��
	//1.С����ͣ�����ӵ�����
	for (int i = 0; i < aParksize1; i++)
	{
		if (strcmp(aPark1[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark1[i].x, aPark1[i].y, aPark1[i].length, aPark1[i].wide);
			aPark1[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 1;
		}
	}
	for (int i = 0; i < aParksize2; i++)
	{
		if (strcmp(aPark2[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aPark2[i].x, aPark2[i].y, aPark2[i].length, aPark2[i].wide);
			aPark2[i].status = false;
			leavePosi = i;
			leaveStat = 0;
			aParkindex = 2;
		}
	}
	//2.С������·�нӵ�����
	for (int i = 0; i < aLineSize; i++)
	{
		if (strcmp(aLine[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
			aLine[i].status = false;
			leavePosi = i;
			leaveStat = 1;
		}
	}
	//3.С���ӳ�����ӵ�����
	for (int i = 0; i < aElesize; i++)
	{
		if (strcmp(aEle[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
		{
			carVectA[awork].ingChange(aEle[i].x, aEle[i].y, aEle[i].length, aEle[i].wide);
			aEle[i].status = false;
			leavePosi = i;
			leaveStat = 2;
		}
	}

	//����С��ȥ���ڵĹ���
	carVectA[awork].eleStatus = 1;
	carVectA[awork].start = clock();
	while (carVectA[awork].s2.size() != 0)
	{
		if (leaveStat == 0)
		{
			if (aParkindex == 1)
			{
				carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
			}
			if (aParkindex == 2)
			{
				carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
			}
		}

		if (leaveStat == 1)
			carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
		if (leaveStat == 2)
			carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);

		if (strcmp(carVectA[awork].s2.top().c_str(), "R00") != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s2.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						carVectA[awork].position = carVectA[awork].s2.top();
						////cout << carVectB[workcar].position << endl;											
						m.show();
					}
				}
			}
			carVectA[awork].s2.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			aLine[lineindex].status = false;
		}
		else{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
			if (leaveStat == 2)
				carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);
			Sleep(1000);
			carVectA[awork].position = carVectA[awork].s2.top();
			carVectA[awork].s2.pop();
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
	while (carVectA[awork].s1.size() != 0)
	{
		if (strcmp(carVectA[awork].s1.top().c_str(), parkingA.Print(minap).index0.c_str()) != 0)
		{
			for (int i = 0; i < aLineSize; i++)
			{
				if (strcmp(carVectA[awork].s1.top().c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectA[awork].position = carVectA[awork].s1.top();
					////cout << carVectB[workcar].position << endl;
					lineindex = i;
					if (aLine[i].status == false)
					{
						aLine[i].status = true;
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
					else{
						Sleep(2000);
						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						m.show();
					}
				}
			}
			aLine[lineindex].status = false;
			carVectA[awork].s1.pop();
			Sleep(2000);
			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
		}
		else{
			Sleep(1000);
			carVectA[awork].s1.pop();
			carVectA[awork].change(parkingA.Print(minap).x, parkingA.Print(minap).y, parkingA.Print(minap).length, parkingA.Print(minap).wide);

			if (minIndex == 1)
				carVectA[awork].occupy(aSpace[carVectA[awork].carindex].x, aSpace[carVectA[awork].carindex].y);
			if (minIndex == 2)
				carVectA[awork].occupy(cSpace[carVectA[awork].carindex].x, cSpace[carVectA[awork].carindex].y);
			for (int i = 0; i < aLineSize; i++){
				if (strcmp(carVectA[awork].position.c_str(), aLine[i].index0.c_str()) == 0)
				{
					carVectB[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
				}
			}
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			//cout << carVectB[workcar].eleNum << endl;
			if (carVectA[awork].eleNum <= 25)
			{
				//������Ҫ��� �����Խ�����
				carVectA[awork].eleFlag = 1;
				//ִ�г�����
				//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//��ʾ��Ҫͣ��
				carVectA[awork].status = false;//��ʾ���Խ�����
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "ͣ�����" << endl;
	//	MessageBox::Show("ͣ���������");
	/////////////////////////////////////////////////////2.A����ͣ������/////////////////////////////////////////////////////////////	
	int APARKIndex = 0;
	int aParkRet = 0;
	for (int v = 0; v < aSpacesize; v++)
	{
		if (aSpace[v].status == false)
			APARKIndex++;
	}
	for (int v = 0; v < cSpacesize; v++)
	{
		if (cSpace[v].status == false)
			APARKIndex++;
	}

	if (APARKIndex > aParkNum)
		aParkRet = 1;
	else
		aParkRet = 2;

	if (carVectA[awork].stop == 1)
	{
		for (int b = 0; b < aElesize; b++)
		{
			if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].restoreEle(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
			}
		}

		for (int p = 0; p < aLineSize; p++){
			if (strcmp(carVectA[awork].position.c_str(), aLine[p].index0.c_str()) == 0)
			{
				carVectA[awork].restoreLine(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
			}
		}
		int parkA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
		int *dist16 = new int[verNumA];
		int *path16 = new int[verNumA];
		parkingA.dijkstra(parkA, dist16, path16);

		for (int j = 0; j < aParksize1; j++)
		{
			aPark1[j].distance_A = dist16[parkingA.strgetIndex0(aPark1[j].index0.c_str())];
		}
		for (int j = 0; j < aParksize2; j++)
		{
			aPark2[j].distance_A = dist16[parkingA.strgetIndex0(aPark2[j].index0.c_str())];
		}

		vector<int> minParka;
		if (aParkRet == 1)
		{
			for (int k = 0; k < aParksize1; k++)
			{
				if (aPark1[k].status == false)
				{
					minParka.push_back(aPark1[k].distance_A);
				}
			}
		}

		if (aParkRet == 2)
		{
			for (int k = 0; k < aParksize2; k++)
			{
				if (aPark2[k].status == false)
				{
					minParka.push_back(aPark2[k].distance_A);
				}
			}
		}
		sort(minParka.begin(), minParka.end());
		//Ѱ������Ŀ���ͣ����
		if (aParkRet == 1)
		{
			for (int g = 0; g < aParksize1; g++)
			{
				if ((aPark1[g].distance_A == minParka[0]) && (aPark1[g].status == false))
				{
					parkindex = g;
					aPark1[g].status = true;
					break;
				}

			}
		}

		if (aParkRet == 2)
		{
			for (int g = 0; g < aParksize2; g++)
			{
				if ((aPark2[g].distance_A == minParka[0]) && (aPark2[g].status == false))
				{
					parkindex = g;
					aPark2[g].status = true;
					break;
				}

			}
		}


		//�����ʱ����v
		minParka.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minap = 0;
		if (aParkRet == 1)
		{
			minap = parkingA.strgetIndex0(aPark1[parkindex].index0.c_str());
			carVectA[awork].s3.push(aPark1[parkindex].index0.c_str());
			aparkstr.clear();
			aparkstr = aPark1[parkindex].index0;
		}

		if (aParkRet == 2)
		{
			minap = parkingA.strgetIndex0(aPark2[parkindex].index0.c_str());
			carVectA[awork].s3.push(aPark2[parkindex].index0.c_str());
			aparkstr.clear();
			aparkstr = aPark2[parkindex].index0;
		}
		for (int j = path16[minap]; j != parkA; j = path16[j])
			carVectA[awork].s3.push(parkingA.Print(j).index0.c_str());

		//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
		if (carVectA[awork].stop == 0)
		{
			//˵�������㹻���Խ�������������е����ж�
			if (aParkRet == 1)
				aPark1[parkindex].status = false;
			if (aParkRet == 2)
				aPark2[parkindex].status = false;
			while (!carVectA[awork].s3.empty())
				carVectA[awork].s3.pop();
			//break;
		}
		else{
			//����ִ��ͣ������
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			if (carVectA[awork].eleNum < 25)
			{
				//��s3���
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//ִ�г�����
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				carVectA[awork].eleFlag = 1;
				carVectA[awork].status = true;
				carVectA[awork].start = clock();
				//break;
			}
		}

		carVectA[awork].start = clock();
		carVectA[awork].eleStatus = 1;
		///С��ȥ��ͣ������ִ��
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectA[awork].s3.size() != 0)
		{
			//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
			if (carVectA[awork].stop == 0)
			{
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				break;
			}
			//��ȥͣ����;��ִ�е����ж�
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			///	carVectA[i].eleNum = 100;
			if (carVectA[awork].eleNum < 25)
			{
				//��s3���
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//ִ�г�����
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				carVectA[awork].eleFlag = 1;
				carVectA[awork].status = true;
				carVectA[awork].start = clock();
				break;
			}

			if (strcmp(carVectA[awork].s3.top().c_str(), aparkstr.c_str()) != 0)
			{
				for (int p = 0; p < aLineSize; p++)
				{
					if (strcmp(carVectA[awork].s3.top().c_str(), aLine[p].index0.c_str()) == 0)
					{
						carVectA[awork].position = carVectA[awork].s3.top().c_str();
						lineindex = p;
						if (aLine[p].status == false)
						{
							aLine[p].status = true;
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							aLine[lineindex].status = false;
							carVectA[awork].s3.pop();
							m.show();
						}
						else{
							Sleep(2000);
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							aLine[lineindex].status = false;
							carVectA[awork].s3.pop();
							m.show();
						}
					}
				}
				//Sleep(2000);
				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
				//cout << carVectA[awork].index << "ͣ������" << carVectA[awork].s3.size() <<"��"<< endl;
			}
			else{
				carVectA[awork].position = carVectA[awork].s3.top().c_str();
				carVectA[awork].s3.pop();
				//cout << carVectA[awork].index << "ͣ�����һ��" << endl;
				if (aParkRet == 1){
					for (int b = 0; b < aParksize1; b++)
					{
						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//��s3���
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								//ִ�г�����
								carVectA[awork].status = true;
								carVectA[awork].eleFlag = 1;
								carVectA[awork].start = clock();
								break;
							}

							carVectA[awork].change(aPark1[b].x, aPark1[b].y, aPark1[b].length, aPark1[b].wide);
							carVectA[awork].start = clock();
							carVectA[awork].eleStatus = 0;
							m.show();
						}
					}
				}

				if (aParkRet == 2){
					for (int b = 0; b < aParksize2; b++)
					{
						if (strcmp(aPark2[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//��s3���
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								//ִ�г�����
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								carVectA[awork].status = true;
								carVectA[awork].eleFlag = 1;
								carVectA[awork].start = clock();
								break;
							}

							carVectA[awork].change(aPark2[b].x, aPark2[b].y, aPark2[b].length, aPark2[b].wide);
							carVectA[awork].start = clock();
							carVectA[awork].eleStatus = 0;
							m.show();
						}
					}
				}
			}
		}
	}
	/////////////A�ĳ�����////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (carVectA[awork].eleFlag == 1)
	{
		//�жϴ���һ����ִ�г�����
		//ͣ����
		for (int o = 0; o < aParksize1; o++)
		{
			if (strcmp(aPark1[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aPark1[o].x, aPark1[o].y, aPark1[o].length, aPark1[o].wide);
				aPark1[o].status = false;
				leavePosi = awork;
				leaveStat = 0;
				aParkindex = 1;
			}
		}
		for (int o = 0; o < aParksize2; o++)
		{
			if (strcmp(aPark2[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aPark2[o].x, aPark2[o].y, aPark2[o].length, aPark2[o].wide);
				aPark2[o].status = false;
				leavePosi = awork;
				leaveStat = 0;
				aParkindex = 2;
			}
		}
		//2.С������·�нӵ�
		for (int o = 0; o < aLineSize; o++)
		{
			if (strcmp(aLine[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
			{
				carVectA[awork].ingChange(aLine[o].x, aLine[o].y, aLine[o].length, aLine[o].wide);
				aLine[o].status = false;
				leavePosi = o;
				leaveStat = 1;
			}
		}


		int eleA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
		int *dist12 = new int[verNumA];
		int *path12 = new int[verNumA];
		parkingA.dijkstra(eleA, dist12, path12);

		for (int j = 0; j < aElesize; j++)
		{
			aEle[j].ele_Distance = dist12[parkingA.strgetIndex0(aEle[j].index0.c_str())];
		}
		vector<int> minElea;
		for (int k = 0; k < aElesize; k++)
		{
			if (aEle[k].status == false)
			{
				minElea.push_back(aEle[k].ele_Distance);
			}
		}
		sort(minElea.begin(), minElea.end());
		//Ѱ������Ŀ��г���
		for (int g = 0; g < aElesize; g++)
		{
			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
			{
				parkindex = g;
				aEle[g].status = true;
				break;
			}
		}
		//�����ʱ����v
		minElea.clear();
		//�����ͣ��λΪ�յ�滮ͣ��·��
		int minap = 0;
		minap = parkingA.strgetIndex0(aEle[parkindex].index0.c_str());
		////cout << aEle[parkindex].index0 << endl;
		while (!carVectA[awork].s6.empty())
			carVectA[awork].s6.pop();
		carVectA[awork].s6.push(aEle[parkindex].index0.c_str());
		for (int j = path12[minap]; j != eleA; j = path12[j])
			carVectA[awork].s6.push(parkingA.Print(j).index0.c_str());


		carVectA[awork].start = clock();
		carVectA[awork].eleStatus = 2;
		///С��ȥ���������ִ��
		while (carVectA[awork].s6.size() != 0)
		{
			if (leaveStat == 0)
			{
				if (aParkindex == 1)
				{
					carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
				}
				if (aParkindex == 2)
				{
					carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
				}
			}

			if (leaveStat == 1)
				carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);

			if (strcmp(carVectA[awork].s6.top().c_str(), aEle[parkindex].index0.c_str()) != 0)
			{
				for (int p = 0; p < aLineSize; p++)
				{
					if (strcmp(carVectA[awork].s6.top().c_str(), aLine[p].index0.c_str()) == 0)
					{
						carVectA[awork].position = carVectA[awork].s6.top().c_str();
						lineindex = p;
						if (aLine[p].status == false)
						{
							aLine[p].status = true;
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							m.show();
						}
						else{
							Sleep(2000);
							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							m.show();
						}
					}
				}
				aLine[lineindex].status = false;
				carVectA[awork].s6.pop();
				Sleep(2000);
				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
			}
			else{
				carVectA[awork].position = carVectA[awork].s6.top().c_str();
				carVectA[awork].s6.pop();
				carVectA[awork].position = aEle[parkindex].index0;
				for (int b = 0; b < aElesize; b++)
				{
					if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
					{
						carVectA[awork].change(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
						carVectA[awork].eleStatus = 2;
						m.show();
					}
				}
				carVectA[awork].status = false;
				carVectA[awork].stop = 1;
				carVectA[awork].start = clock();
				carVectA[awork].eleNum = 100;

			}
		}
	}
	///////////������/////////////////////////////////////////////
	/////////////////////////////////////
}

//void aParkProCar5()
//{
//	int awork = 1;
//	carVectA[awork].status = true;//��״̬��Ϊʹ��
//	carVectA[awork].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
//	carVectA[awork].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
//	cout << "������С���±���" << carVectA[awork].index << endl;
//	//MessageBox::Show("����С�����±�Ϊ:" + carVectA[workcar].index);
//	vector<int> aminDist;
//	//ѡ������ĳ�λ
//	for (int i = 0; i < aSpacesize; i++)
//	{
//		if (aSpace[i].status == false)
//			aminDist.push_back(aSpace[i].distance_A);
//	}
//	for (int i = 0; i < cSpacesize; i++)
//	{
//		if (cSpace[i].status == false)
//			aminDist.push_back(cSpace[i].distance_A);
//	}
//	sort(aminDist.begin(), aminDist.end());
//	//�ж������λ���ĸ�����
//	for (int i = 0; i < aSpacesize; i++)
//	{
//		if ((aminDist[0] == aSpace[i].distance_A) && (aSpace[i].status == false))
//		{
//			carVectA[awork].carindex = i;
//			aSpace[i].status = true;
//			aSpace[i].license = license;
//			carVectA[awork].book(aSpace[i].x, aSpace[i].y);
//			minIndex = 1;
//			break;
//		}
//	}
//
//	for (int i = 0; i < cSpacesize; i++)
//	{
//		if ((aminDist[0] == cSpace[i].distance_A) && (cSpace[i].status == false))
//		{
//			carVectA[awork].carindex = i;
//			cSpace[i].status = true;
//			cSpace[i].license = license;
//			carVectA[awork].book(cSpace[i].x, cSpace[i].y);
//			minIndex = 2;
//			break;
//		}
//	}
//	aminDist.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��
//
//	int minap;//��ȡ�����λ��ͼ�е��������
//	if (minIndex == 1){
//		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
//	}
//	else if (minIndex == 2){
//		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
//	}
//	//������ѡ��������λ
//	//��ȡ���ڵ������λ��·��
//	while (!carVectA[awork].s1.empty())
//		carVectA[awork].s1.pop();
//	carVectA[awork].s1.push(parkingA.Print(minap).index0);
//	for (int j = path7[minap]; j != startA; j = path7[j])
//		carVectA[awork].s1.push(parkingA.Print(j).index0);
//
//	//��С����ǰλ��Ϊ�����㵽���ڵ����·��
//	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
//	int *dist8 = new int[verNumA];
//	int *path8 = new int[verNumA];
//	parkingA.dijkstra(leaveA, dist8, path8);
//
//	//��ȡС�������ڵ����·��
//	while (!carVectA[awork].s2.empty())
//		carVectA[awork].s2.pop();
//	carVectA[awork].s2.push(parkingA.Print(startA).index0);
//	for (int j = path8[startA]; j != leaveA; j = path8[j])
//		carVectA[awork].s2.push(parkingA.Print(j).index0);
//
//
//	//��¼����С���뿪ʱ��λ��
//	//1.С����ͣ�����ӵ�����
//	for (int i = 0; i < aParksize1; i++)
//	{
//		if (strcmp(aPark1[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//		{
//			carVectA[awork].ingChange(aPark1[i].x, aPark1[i].y, aPark1[i].length, aPark1[i].wide);
//			aPark1[i].status = false;
//			leavePosi = i;
//			leaveStat = 0;
//			aParkindex = 1;
//		}
//	}
//	for (int i = 0; i < aParksize2; i++)
//	{
//		if (strcmp(aPark2[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//		{
//			carVectA[awork].ingChange(aPark2[i].x, aPark2[i].y, aPark2[i].length, aPark2[i].wide);
//			aPark2[i].status = false;
//			leavePosi = i;
//			leaveStat = 0;
//			aParkindex = 2;
//		}
//	}
//	//2.С������·�нӵ�����
//	for (int i = 0; i < aLineSize; i++)
//	{
//		if (strcmp(aLine[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//		{
//			carVectA[awork].ingChange(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
//			aLine[i].status = false;
//			leavePosi = i;
//			leaveStat = 1;
//		}
//	}
//	//3.С���ӳ�����ӵ�����
//	for (int i = 0; i < aElesize; i++)
//	{
//		if (strcmp(aEle[i].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//		{
//			carVectA[awork].ingChange(aEle[i].x, aEle[i].y, aEle[i].length, aEle[i].wide);
//			aEle[i].status = false;
//			leavePosi = i;
//			leaveStat = 2;
//		}
//	}
//
//	//����С��ȥ���ڵĹ���
//	carVectA[awork].eleStatus = 1;
//	carVectA[awork].start = clock();
//	while (carVectA[awork].s2.size() != 0)
//	{
//		if (leaveStat == 0)
//		{
//			if (aParkindex == 1)
//			{
//				carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
//			}
//			if (aParkindex == 2)
//			{
//				carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
//			}
//		}
//
//		if (leaveStat == 1)
//			carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
//		if (leaveStat == 2)
//			carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);
//
//		if (strcmp(carVectA[awork].s2.top().c_str(), "R00") != 0)
//		{
//			for (int i = 0; i < aLineSize; i++)
//			{
//				if (strcmp(carVectA[awork].s2.top().c_str(), aLine[i].index0.c_str()) == 0)
//				{
//					lineindex = i;
//					if (aLine[i].status == false)
//					{
//						aLine[i].status = true;
//						carVectA[awork].position = carVectA[awork].s2.top();
//						////cout << carVectB[workcar].position << endl;
//						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
//						//m.show();
//					}
//					else{
//						Sleep(2000);
//						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
//						carVectA[awork].position = carVectA[awork].s2.top();
//						////cout << carVectB[workcar].position << endl;											
//						//m.show();
//					}
//				}
//			}
//			carVectA[awork].s2.pop();
//			Sleep(2000);
//			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
//			aLine[lineindex].status = false;
//		}
//		else{
//			if (leaveStat == 0)
//			{
//				if (aParkindex == 1)
//				{
//					carVectA[awork].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
//				}
//				if (aParkindex == 2)
//				{
//					carVectA[awork].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
//				}
//			}
//
//			if (leaveStat == 1)
//				carVectA[awork].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
//			if (leaveStat == 2)
//				carVectA[awork].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);
//			Sleep(1000);
//			carVectA[awork].position = carVectA[awork].s2.top();
//			carVectA[awork].s2.pop();
//			////cout << carVectB[workcar].position << endl;
//			//m.show();
//		}
//	}
//	//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
//	while (carVectA[awork].s1.size() != 0)
//	{
//		if (strcmp(carVectA[awork].s1.top().c_str(), parkingA.Print(minap).index0.c_str()) != 0)
//		{
//			for (int i = 0; i < aLineSize; i++)
//			{
//				if (strcmp(carVectA[awork].s1.top().c_str(), aLine[i].index0.c_str()) == 0)
//				{
//					carVectA[awork].position = carVectA[awork].s1.top();
//					////cout << carVectB[workcar].position << endl;
//					lineindex = i;
//					if (aLine[i].status == false)
//					{
//						aLine[i].status = true;
//						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
//						//m.show();
//					}
//					else{
//						Sleep(2000);
//						carVectA[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
//						//m.show();
//					}
//				}
//			}
//			aLine[lineindex].status = false;
//			carVectA[awork].s1.pop();
//			Sleep(2000);
//			carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
//		}
//		else{
//			Sleep(1000);
//			carVectA[awork].s1.pop();
//			carVectA[awork].change(parkingA.Print(minap).x, parkingA.Print(minap).y, parkingA.Print(minap).length, parkingA.Print(minap).wide);
//
//			if (minIndex == 1)
//				carVectA[awork].occupy(aSpace[carVectA[awork].carindex].x, aSpace[carVectA[awork].carindex].y);
//			if (minIndex == 2)
//				carVectA[awork].occupy(cSpace[carVectA[awork].carindex].x, cSpace[carVectA[awork].carindex].y);
//			for (int i = 0; i < aLineSize; i++){
//				if (strcmp(carVectA[awork].position.c_str(), aLine[i].index0.c_str()) == 0)
//				{
//					carVectB[awork].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
//				}
//			}
//			carVectA[awork].end = clock();
//			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
//			//cout << carVectB[workcar].eleNum << endl;
//			if (carVectA[awork].eleNum <= 25)
//			{
//				//������Ҫ��� �����Խ�����
//				carVectA[awork].eleFlag = 1;
//				//ִ�г�����
//				//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
//				carVectA[awork].eleStatus = 0;
//				carVectA[awork].start = clock();
//			}
//			else{
//				carVectA[awork].stop = 1;//��ʾ��Ҫͣ��
//				carVectA[awork].status = false;//��ʾ���Խ�����
//				carVectA[awork].start = clock();
//			}
//			////cout << carVectB[workcar].position << endl;
//			/////m.show();
//		}
//	}
//	cout << carVectA[awork].index << "ͣ�����" << endl;
//	//	MessageBox::Show("ͣ���������");
//	/////////////////////////////////////////////////////2.A����ͣ������/////////////////////////////////////////////////////////////	
//	int APARKIndex = 0;
//	int aParkRet = 0;
//	for (int v = 0; v < aSpacesize; v++)
//	{
//		if (aSpace[v].status == false)
//			APARKIndex++;
//	}
//	for (int v = 0; v < cSpacesize; v++)
//	{
//		if (cSpace[v].status == false)
//			APARKIndex++;
//	}
//
//	if (APARKIndex > aParkNum)
//		aParkRet = 1;
//	else
//		aParkRet = 2;
//
//	if (carVectA[awork].stop == 1)
//	{
//		for (int b = 0; b < aElesize; b++)
//		{
//			if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//			{
//				carVectA[awork].restoreEle(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
//			}
//		}
//
//		for (int p = 0; p < aLineSize; p++){
//			if (strcmp(carVectA[awork].position.c_str(), aLine[p].index0.c_str()) == 0)
//			{
//				carVectA[awork].restoreLine(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
//			}
//		}
//		int parkA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
//		int *dist16 = new int[verNumA];
//		int *path16 = new int[verNumA];
//		parkingA.dijkstra(parkA, dist16, path16);
//
//		for (int j = 0; j < aParksize1; j++)
//		{
//			aPark1[j].distance_A = dist16[parkingA.strgetIndex0(aPark1[j].index0.c_str())];
//		}
//		for (int j = 0; j < aParksize2; j++)
//		{
//			aPark2[j].distance_A = dist16[parkingA.strgetIndex0(aPark2[j].index0.c_str())];
//		}
//
//		vector<int> minParka;
//		if (aParkRet == 1)
//		{
//			for (int k = 0; k < aParksize1; k++)
//			{
//				if (aPark1[k].status == false)
//				{
//					minParka.push_back(aPark1[k].distance_A);
//				}
//			}
//		}
//
//		if (aParkRet == 2)
//		{
//			for (int k = 0; k < aParksize2; k++)
//			{
//				if (aPark2[k].status == false)
//				{
//					minParka.push_back(aPark2[k].distance_A);
//				}
//			}
//		}
//		sort(minParka.begin(), minParka.end());
//		//Ѱ������Ŀ���ͣ����
//		if (aParkRet == 1)
//		{
//			for (int g = 0; g < aParksize1; g++)
//			{
//				if ((aPark1[g].distance_A == minParka[0]) && (aPark1[g].status == false))
//				{
//					parkindex = g;
//					aPark1[g].status = true;
//					break;
//				}
//
//			}
//		}
//
//		if (aParkRet == 2)
//		{
//			for (int g = 0; g < aParksize2; g++)
//			{
//				if ((aPark2[g].distance_A == minParka[0]) && (aPark2[g].status == false))
//				{
//					parkindex = g;
//					aPark2[g].status = true;
//					break;
//				}
//
//			}
//		}
//
//
//		//�����ʱ����v
//		minParka.clear();
//		//�����ͣ��λΪ�յ�滮ͣ��·��
//		int minap = 0;
//		if (aParkRet == 1)
//		{
//			minap = parkingA.strgetIndex0(aPark1[parkindex].index0.c_str());
//			carVectA[awork].s3.push(aPark1[parkindex].index0.c_str());
//			aparkstr.clear();
//			aparkstr = aPark1[parkindex].index0;
//		}
//
//		if (aParkRet == 2)
//		{
//			minap = parkingA.strgetIndex0(aPark2[parkindex].index0.c_str());
//			carVectA[awork].s3.push(aPark2[parkindex].index0.c_str());
//			aparkstr.clear();
//			aparkstr = aPark2[parkindex].index0;
//		}
//		for (int j = path16[minap]; j != parkA; j = path16[j])
//			carVectA[awork].s3.push(parkingA.Print(j).index0.c_str());
//
//		//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
//		if (carVectA[awork].stop == 0)
//		{
//			//˵�������㹻���Խ�������������е����ж�
//			if (aParkRet == 1)
//				aPark1[parkindex].status = false;
//			if (aParkRet == 2)
//				aPark2[parkindex].status = false;
//			while (!carVectA[awork].s3.empty())
//				carVectA[awork].s3.pop();
//			//break;
//		}
//		else{
//			//����ִ��ͣ������
//			carVectA[awork].end = clock();
//			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
//			if (carVectA[awork].eleNum < 25)
//			{
//				//��s3���
//				while (!carVectA[awork].s3.empty())
//					carVectA[awork].s3.pop();
//				//ִ�г�����
//				if (aParkRet == 1)
//					aPark1[parkindex].status = false;
//				if (aParkRet == 2)
//					aPark2[parkindex].status = false;
//				carVectA[awork].eleFlag = 1;
//				carVectA[awork].status = true;
//				carVectA[awork].start = clock();
//				//break;
//			}
//		}
//
//		carVectA[awork].start = clock();
//		carVectA[awork].eleStatus = 1;
//		///С��ȥ��ͣ������ִ��
//		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
//		while (carVectA[awork].s3.size() != 0)
//		{
//			//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
//			if (carVectA[awork].stop == 0)
//			{
//				if (aParkRet == 1)
//					aPark1[parkindex].status = false;
//				if (aParkRet == 2)
//					aPark2[parkindex].status = false;
//				while (!carVectA[awork].s3.empty())
//					carVectA[awork].s3.pop();
//				break;
//			}
//			//��ȥͣ����;��ִ�е����ж�
//			carVectA[awork].end = clock();
//			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
//			///	carVectA[i].eleNum = 100;
//			if (carVectA[awork].eleNum < 25)
//			{
//				//��s3���
//				while (!carVectA[awork].s3.empty())
//					carVectA[awork].s3.pop();
//				//ִ�г�����
//				if (aParkRet == 1)
//					aPark1[parkindex].status = false;
//				if (aParkRet == 2)
//					aPark2[parkindex].status = false;
//				carVectA[awork].eleFlag = 1;
//				carVectA[awork].status = true;
//				carVectA[awork].start = clock();
//				break;
//			}
//
//			if (strcmp(carVectA[awork].s3.top().c_str(), aparkstr.c_str()) != 0)
//			{
//				for (int p = 0; p < aLineSize; p++)
//				{
//					if (strcmp(carVectA[awork].s3.top().c_str(), aLine[p].index0.c_str()) == 0)
//					{
//						carVectA[awork].position = carVectA[awork].s3.top().c_str();
//						lineindex = p;
//						if (aLine[p].status == false)
//						{
//							aLine[p].status = true;
//							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
//							//m.show();
//						}
//						else{
//							Sleep(2000);
//							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
//							//m.show();
//						}
//					}
//				}
//				aLine[lineindex].status = false;
//				carVectA[awork].s3.pop();
//				Sleep(2000);
//				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
//			}
//			else{
//				carVectA[awork].position = carVectA[awork].s3.top().c_str();
//				carVectA[awork].s3.pop();
//				cout << carVectA[awork].index << "ͣ�����һ��" << endl;
//				if (aParkRet == 1){
//					for (int b = 0; b < aParksize1; b++)
//					{
//						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//						{
//							carVectA[awork].end = clock();
//							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
//							if (carVectA[awork].eleNum < 25)
//							{
//								//��s3���
//								while (!carVectA[awork].s3.empty())
//									carVectA[awork].s3.pop();
//								if (aParkRet == 1)
//									aPark1[parkindex].status = false;
//								if (aParkRet == 2)
//									aPark2[parkindex].status = false;
//								//ִ�г�����
//								carVectA[awork].status = true;
//								carVectA[awork].eleFlag = 1;
//								carVectA[awork].start = clock();
//								break;
//							}
//
//							carVectA[awork].change(aPark1[b].x, aPark1[b].y, aPark1[b].length, aPark1[b].wide);
//							carVectA[awork].start = clock();
//							carVectA[awork].eleStatus = 0;
//							//m.show();
//						}
//					}
//				}
//
//				if (aParkRet == 2){
//					for (int b = 0; b < aParksize2; b++)
//					{
//						if (strcmp(aPark2[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//						{
//							carVectA[awork].end = clock();
//							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
//							if (carVectA[awork].eleNum < 25)
//							{
//								//��s3���
//								while (!carVectA[awork].s3.empty())
//									carVectA[awork].s3.pop();
//								//ִ�г�����
//								if (aParkRet == 1)
//									aPark1[parkindex].status = false;
//								if (aParkRet == 2)
//									aPark2[parkindex].status = false;
//								carVectA[awork].status = true;
//								carVectA[awork].eleFlag = 1;
//								carVectA[awork].start = clock();
//								break;
//							}
//
//							carVectA[awork].change(aPark2[b].x, aPark2[b].y, aPark2[b].length, aPark2[b].wide);
//							carVectA[awork].start = clock();
//							carVectA[awork].eleStatus = 0;
//							//m.show();
//						}
//					}
//				}
//			}
//		}
//	}
//	/////////////A�ĳ�����////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	if (carVectA[awork].eleFlag == 1)
//	{
//		//�жϴ���һ����ִ�г�����
//		//ͣ����
//		for (int o = 0; o < aParksize1; o++)
//		{
//			if (strcmp(aPark1[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//			{
//				carVectA[awork].ingChange(aPark1[o].x, aPark1[o].y, aPark1[o].length, aPark1[o].wide);
//				aPark1[o].status = false;
//				leavePosi = awork;
//				leaveStat = 0;
//				aParkindex = 1;
//			}
//		}
//		for (int o = 0; o < aParksize2; o++)
//		{
//			if (strcmp(aPark2[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//			{
//				carVectA[awork].ingChange(aPark2[o].x, aPark2[o].y, aPark2[o].length, aPark2[o].wide);
//				aPark2[o].status = false;
//				leavePosi = awork;
//				leaveStat = 0;
//				aParkindex = 2;
//			}
//		}
//		//2.С������·�нӵ�
//		for (int o = 0; o < aLineSize; o++)
//		{
//			if (strcmp(aLine[o].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//			{
//				carVectA[awork].ingChange(aLine[o].x, aLine[o].y, aLine[o].length, aLine[o].wide);
//				aLine[o].status = false;
//				leavePosi = o;
//				leaveStat = 1;
//			}
//		}
//
//
//		int eleA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
//		int *dist12 = new int[verNumA];
//		int *path12 = new int[verNumA];
//		parkingA.dijkstra(eleA, dist12, path12);
//
//		for (int j = 0; j < aElesize; j++)
//		{
//			aEle[j].ele_Distance = dist12[parkingA.strgetIndex0(aEle[j].index0.c_str())];
//		}
//		vector<int> minElea;
//		for (int k = 0; k < aElesize; k++)
//		{
//			if (aEle[k].status == false)
//			{
//				minElea.push_back(aEle[k].ele_Distance);
//			}
//		}
//		sort(minElea.begin(), minElea.end());
//		//Ѱ������Ŀ��г���
//		for (int g = 0; g < aElesize; g++)
//		{
//			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
//			{
//				parkindex = g;
//				aEle[g].status = true;
//				break;
//			}
//		}
//		//�����ʱ����v
//		minElea.clear();
//		//�����ͣ��λΪ�յ�滮ͣ��·��
//		int minap = 0;
//		minap = parkingA.strgetIndex0(aEle[parkindex].index0.c_str());
//		////cout << aEle[parkindex].index0 << endl;
//		while (!carVectA[awork].s6.empty())
//			carVectA[awork].s6.pop();
//		carVectA[awork].s6.push(aEle[parkindex].index0.c_str());
//		for (int j = path12[minap]; j != eleA; j = path12[j])
//			carVectA[awork].s6.push(parkingA.Print(j).index0.c_str());
//
//
//		carVectA[awork].start = clock();
//		carVectA[awork].eleStatus = 2;
//		///С��ȥ���������ִ��
//		while (carVectA[awork].s6.size() != 0)
//		{
//			if (leaveStat == 0)
//			{
//				if (aParkindex == 1)
//				{
//					carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
//				}
//				if (aParkindex == 2)
//				{
//					carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
//				}
//			}
//
//			if (leaveStat == 1)
//				carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
//
//			if (strcmp(carVectA[awork].s6.top().c_str(), aEle[parkindex].index0.c_str()) != 0)
//			{
//				for (int p = 0; p < aLineSize; p++)
//				{
//					if (strcmp(carVectA[awork].s6.top().c_str(), aLine[p].index0.c_str()) == 0)
//					{
//						carVectA[awork].position = carVectA[awork].s6.top().c_str();
//						lineindex = p;
//						if (aLine[p].status == false)
//						{
//							aLine[p].status = true;
//							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
//							//m.show();
//						}
//						else{
//							Sleep(2000);
//							carVectA[awork].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
//							//m.show();
//						}
//					}
//				}
//				aLine[lineindex].status = false;
//				carVectA[awork].s6.pop();
//				Sleep(2000);
//				carVectA[awork].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
//			}
//			else{
//				carVectA[awork].position = carVectA[awork].s6.top().c_str();
//				carVectA[awork].s6.pop();
//				carVectA[awork].position = aEle[parkindex].index0;
//				for (int b = 0; b < aElesize; b++)
//				{
//					if (strcmp(aEle[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//					{
//						carVectA[awork].change(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
//						carVectA[awork].eleStatus = 2;
//						//m.show();
//					}
//				}
//				carVectA[awork].status = false;
//				carVectA[awork].stop = 1;
//				carVectA[awork].start = clock();
//				carVectA[awork].eleNum = 100;
//
//			}
//		}
//	}
//	///////////������/////////////////////////////////////////////
//	/////////////////////////////////////
//}


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
		}
		else{
			cout << "������Ϣ������" << endl;
			break;
		}
		//�������ݸ��ͻ���
		//	char sendData[1024];

		if (strcmp(revData, "ɾ���û���Ϣ") == 0){
			Application::EnableVisualStyles();
			Application::Run(gcnew deletebaseForm());
			send(*ClientSocket, "ɾ���û���Ϣ�����Ѿ�����\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "�����û���Ϣ") == 0)){
			Application::EnableVisualStyles();
			Application::Run(gcnew insertDataBaseForm());
			send(*ClientSocket, "�����û���Ϣ�����Ѵ���\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "�޸��û���Ϣ") == 0)){
			Application::EnableVisualStyles();
			Application::Run(gcnew modiftyDataForm());
			send(*ClientSocket, "�޸��û���Ϣ�����Ѵ���\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "��ѯ��λ״̬") == 0)){
			int free = 0; int busy = 0;
			free = m.findParkingSpaceStatusFree();
			busy = m.findParkingSpaceStatusBusy();
			showSpaceStatusForm showSpace;
			showSpace.find(free, busy);
			showSpace.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "��ѯ��λ״̬�����Ѵ���\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "��ѯ���״̬") == 0))
		{
			int free = 0; int busy = 0;
			arr[30][10] = 99;
			free = m.findRoadStatusFree();
			busy = m.findRoadStatusBusy();
			showRoadStatusForm showRoad;
			showRoad.find(free, busy);
			showRoad.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "��ѯ���״̬�����Ѵ���\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "��ѯС��״̬") == 0))
		{
			showCarStatusForm showcarstatus;
			showcarstatus.find();
			showcarstatus.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "��ѯС��״̬�����Ѵ���\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "��ѯС��λ��") == 0))
		{
			Application::EnableVisualStyles();
			Application::Run(gcnew showCarRoteForm());
			send(*ClientSocket, "��ѯС��λ�������ѱ�����\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "ͣ��") == 0)
		{
			send(*ClientSocket, "�û�ͣ����������ִ��\n", sizeof(sendData), 0);
			parkForm p;
			p.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			//��Aͣ������������
			for (int i = 0; i < aSpacesize; i++){
				if (aSpace[i].status == false)
					aFree++;
			}
			//��Bͣ������������
			for (int i = 0; i < bSpacesize; i++){
				if (bSpace[i].status == false)
					bFree++;
			}
			//�Թ��ó�λ��������
			for (int i = 0; i < cSpacesize; i++){
				if (cSpace[i].status == false)
					cFree++;
			}
			aNum = aFree + cFree; bNum = bFree + cFree;
			if (location <= 50){
				if (aNum != 0){
					MessageBox::Show("�����Aͣ��������ȥAͣ����ͣ��");
					chooseRet = 1;
				}
				else if (bNum != 0){
					MessageBox::Show("�����Bͣ��������ȥBͣ����ͣ��");
					chooseRet = 2;
				}
				else{
					MessageBox::Show("�Բ���ͣ�����Ѿ�û�п��೵λ");
					chooseRet = 0;
				}
			}
			else{
				if (bNum != 0){
					MessageBox::Show("�����Bͣ��������ȥBͣ����ͣ��");
					chooseRet = 2;
				}
				else if (aNum != 0){
					MessageBox::Show("�����Aͣ��������ȥAͣ����ͣ��");
					chooseRet = 1;
				}
				else{
					MessageBox::Show("�Բ���ͣ�����Ѿ�û�п��೵λ");
					chooseRet = 0;
				}
			}
			//��Aͣ����ͣ��
			if (chooseRet == 1){
				//ѡ����еĿ���С��
				for (int i = 0; i < caraSize; i++)
				{
					if (carVectA[i].status == false)
					{
						carVectA[i].eleNum = carVectA[i].calEle(carVectA[i].eleNum, carVectA[i].eleStatus, carVectA[i].start, carVectA[i].end);
						if (carVectA[i].eleNum >= 25)
						{
							workcar = i;
							break;
						}
					}
				}
				if (workcar == 0){
					aParkProCar4();
				}else if (workcar == 1){
					aParkProCar5();
				}else if (workcar == 2){
					aParkProCar6();
				}else if (workcar == 3){
					aParkProCar7();
				}else if (workcar == 4){
					aParkProCar8();
				}else if (workcar == 5){
					aParkProCar9();
				}
				
			}
			//Aͣ����ͣ�����

			//Bͣ����ʼ
			if (chooseRet == 2)
			{
				//ѡ����еĿ���С��
				for (int i = 0; i < carbSize; i++)
				{
					if (carVectB[i].status == false)
					{
						carVectB[i].eleNum = carVectB[i].calEle(carVectB[i].eleNum, carVectB[i].eleStatus, carVectB[i].start, carVectB[i].end);
						if (carVectB[i].eleNum >= 25)
						{
							workcar = i;
							cout << i << endl;
							cout << carVectB[i].index << endl;
							break;
						}
					}
				}
				if (workcar == 0){
					bParkProCar1();
				}
				else if (workcar == 1){
					bParkProCar2();
				}
				else if (workcar == 2){
					bParkProCar3();
				}
				//MessageBox::Show("ͣ���������");		
			}
			////////////////////////////
			//Bͣ������
			//ͣ������	
		}
		else if (strcmp(revData, "ȡ��") == 0)
		{
			send(*ClientSocket, "�û�ȡ����������ִ��\n", sizeof(sendData), 0);
			sendForm s;
			s.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			//Aȡ����ʼ/////////////////////////////////////
			if (location == 1)
			{
				MessageBox::Show("ϵͳ����Ϊ����Aͣ����ȡ��");
				//�ж��ĸ���λ��ȡ�ó��Ƶĳ�
				for (int i = 0; i < aSpacesize; i++)
				{
					if (strcmp(aSpace[i].license.c_str(), license.c_str()) == 0)
					{
						pickIndex = i;
						chooseRet = 0;
						taskSpace.index0 = aSpace[i].index0;
						break;
					}
				}
				for (int i = 0; i < cSpacesize; i++)
				{
					if (strcmp(cSpace[i].license.c_str(), license.c_str()) == 0)
					{
						pickIndex = i;
						chooseRet = 1;
						taskSpace.index0 = cSpace[i].index0;
						break;
					};
				}
				int min = 0;
				if (chooseRet == 0)
					min = parkingA.strgetIndex0(aSpace[pickIndex].index0.c_str());
				else if (chooseRet == 1)
					min = parkingA.strgetIndex0(cSpace[pickIndex].index0.c_str());

				//��ȡ����λλ��Ϊ��ʼ��ѡ������Ĺ�����λ 
				int retA = parkingA.strgetIndex0(taskSpace.index0.c_str());
				int *dist9 = new int[verNumA];
				int *path9 = new int[verNumA];
				parkingA.dijkstra(retA, dist9, path9);

				//ѡ����С��
				//�ڴ�δ���е����ж���Ϊ״̬Ϊfalse˵�������㹻
				for (int i = 0; i < caraSize; i++)
				{
					if (carVectA[i].status == false)
					{
						carVectA[i].distance = dist9[parkingA.strgetIndex0(carVectA[i].position.c_str())];
						minCar.push_back(carVectA[i].distance);
					}
				}

				sort(minCar.begin(), minCar.end());
				for (int i = 0; i < caraSize; i++)
				{
					if (carVectA[i].status == false)
					{
						if (carVectA[i].distance == minCar[0])
						{
							workcar = i;
							break;
						}
					}
				}

				//��¼����С���뿪ʱ��λ��
				//1.С����ͣ�����ӵ�����
				for (int i = 0; i < aParksize1; i++)
				{
					if (strcmp(aPark1[i].index0.c_str(), carVectA[workcar].position.c_str()) == 0)
					{
						carVectA[workcar].ingChange(aPark1[i].x, aPark1[i].y, aPark1[i].length, aPark1[i].wide);
						aPark1[i].status = false;
						leavePosi = i;
						leaveStat = 0;
						aParkindex = 1;
					}
				}
				for (int i = 0; i < aParksize2; i++)
				{
					if (strcmp(aPark2[i].index0.c_str(), carVectA[workcar].position.c_str()) == 0)
					{
						carVectA[workcar].ingChange(aPark2[i].x, aPark2[i].y, aPark2[i].length, aPark2[i].wide);
						aPark2[i].status = false;
						leavePosi = i;
						leaveStat = 0;
						aParkindex = 2;
					}
				}
				//2.С������·�нӵ�����
				for (int i = 0; i < aLineSize; i++)
				{
					if (strcmp(aLine[i].index0.c_str(), carVectA[workcar].position.c_str()) == 0)
					{
						carVectA[workcar].ingChange(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
						aLine[i].status = false;
						leavePosi = i;
						leaveStat = 1;
					}
				}
				//3.С���ӳ�����ӵ�����
				for (int i = 0; i < aElesize; i++)
				{
					if (strcmp(aEle[i].index0.c_str(), carVectA[workcar].position.c_str()) == 0)
					{
						carVectA[workcar].ingChange(aEle[i].x, aEle[i].y, aEle[i].length, aEle[i].wide);
						aEle[i].status = false;
						leavePosi = i;
						leaveStat = 2;
					}
				}
				carVectA[workcar].status = true;
				carVectA[workcar].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
				cout << "������С���±���" << carVectA[workcar].index << endl;


				while (!carVectA[workcar].s4.empty())
					carVectA[workcar].s4.pop();
				int pickA = parkingA.strgetIndex0(carVectA[workcar].position.c_str());
				int *dist10 = new int[verNumA];
				int *path10 = new int[verNumA];
				parkingA.dijkstra(pickA, dist10, path10);
				//��ȡС�������Ƴ�λ��·��
				//carVectB[workcar].s4.push(parkingB.Print(min).index0);
				for (int j = path10[min]; j != pickA; j = path10[j])
					carVectA[workcar].s4.push(parkingA.Print(j).index0);



				//����С��ȥ��λ��ִ��
				carVectA[workcar].eleStatus = 1;
				carVectA[workcar].start = clock();
				while (carVectA[workcar].s4.size() != 0)
				{
					if (leaveStat == 0)
					{
						if (aParkindex == 1)
						{
							carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
						}
						if (aParkindex == 2)
						{
							carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
						}
					}

					if (leaveStat == 1)
						carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
					if (leaveStat == 2)
						carVectA[workcar].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);

					if (strcmp(carVectA[workcar].s4.top().c_str(), parkingA.Print(min).index0.c_str()) != 0)
					{
						for (int i = 0; i < aLineSize; i++)
						{
							if (strcmp(carVectA[workcar].s4.top().c_str(), aLine[i].index0.c_str()) == 0)
							{
								lineindex = i;
								if (aLine[i].status == false)
								{
									aLine[i].status = true;
									carVectA[workcar].position = carVectA[workcar].s4.top();
									////cout << carVectB[workcar].position << endl;
									carVectA[workcar].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
									m.show();
								}
								else{
									Sleep(2000);
									carVectA[workcar].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
									carVectA[workcar].position = carVectA[workcar].s4.top();
									////cout << carVectB[workcar].position << endl;											
									m.show();
								}
							}
						}
						carVectA[workcar].s4.pop();
						Sleep(2000);
						carVectA[workcar].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
						aLine[lineindex].status = false;
					}
					else{
						if (leaveStat == 0)
						{
							if (aParkindex == 1)
							{
								carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
							}
							if (aParkindex == 2)
							{
								carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
							}
						}

						if (leaveStat == 1)
							carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
						if (leaveStat == 2)
							carVectA[workcar].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);

						Sleep(1000);
						carVectA[workcar].position = carVectA[workcar].s4.top();
						carVectA[workcar].s4.pop();
						/////////cout << carVectB[workcar].position << endl;
						m.show();
					}
				}
				//���С��ֱ�ӽ���ȡ���Ļ���Ҫ����Ĵ�������
				if (leaveStat == 0)
				{
					if (aParkindex == 1)
					{
						carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
					}
					if (aParkindex == 2)
					{
						carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
					}
				}

				if (leaveStat == 1)
					carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);
				if (leaveStat == 2)
					carVectA[workcar].restoreEle(aEle[leavePosi].x, aEle[leavePosi].y, aEle[leavePosi].length, aEle[leavePosi].wide);


				//����ȡ��
				if (chooseRet == 0){
					carVectA[workcar].restoreSpace(aSpace[pickIndex].x, aSpace[pickIndex].y, aSpace[pickIndex].length, aSpace[pickIndex].wide);
					aSpace[pickIndex].status = false;
					aSpace[pickIndex].license.clear();
				}
				else if (chooseRet == 1){
					carVectA[workcar].restoreSpace(cSpace[pickIndex].x, cSpace[pickIndex].y, cSpace[pickIndex].length, cSpace[pickIndex].wide);
					cSpace[pickIndex].status = false;
					cSpace[pickIndex].license.clear();
				}
				////m.show();

				/////ȡ�����ͳ�������
				int arriveA = parkingA.strgetIndex0(carVectA[workcar].position.c_str());
				int *dist11 = new int[verNumA];
				int *path11 = new int[verNumA];
				parkingA.dijkstra(arriveA, dist11, path11);
				//��ȡС�������ڵ����·��
				carVectA[workcar].s5.push("R00");
				min = parkingA.strgetIndex0("R00");
				for (int j = path11[min]; j != arriveA; j = path11[j])
					carVectA[workcar].s5.push(parkingA.Print(j).index0);

				while (carVectA[workcar].s5.size() != 0)
				{
					if (strcmp(carVectA[workcar].s5.top().c_str(), "R00") != 0)
					{
						for (int i = 0; i < aLineSize; i++)
						{
							if (strcmp(carVectA[workcar].s5.top().c_str(), aLine[i].index0.c_str()) == 0)
							{
								lineindex = i;
								if (aLine[i].status == false)
								{
									aLine[i].status = true;
									carVectA[workcar].position = carVectA[workcar].s5.top();
									////	cout << carVectB[workcar].position << endl;
									carVectA[workcar].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
									m.show();
								}
								else{
									Sleep(2000);
									carVectA[workcar].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
									carVectA[workcar].position = carVectA[workcar].s5.top();
									/////		cout << carVectB[workcar].position << endl;											
									m.show();
								}
							}
						}
						carVectA[workcar].s5.pop();
						Sleep(2000);
						carVectA[workcar].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
						aLine[lineindex].status = false;
					}
					else{
						Sleep(1000);
						carVectA[workcar].position = carVectA[workcar].s5.top();
						carVectA[workcar].s5.pop();
						////cout << carVectB[workcar].position << endl;

						for (int i = 0; i < aLineSize; i++){
							if (strcmp(carVectA[workcar].position.c_str(), aLine[i].index0.c_str()) == 0)
							{
								carVectB[workcar].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
							}
						}
						m.show();
						carVectA[workcar].end = clock();
						carVectA[workcar].eleNum = carVectA[workcar].calEle(carVectA[workcar].eleNum, carVectA[workcar].eleStatus, carVectA[workcar].start, carVectA[workcar].end);
						////cout << carVectB[workcar].eleNum << endl;
						if (carVectA[workcar].eleNum <= 25)
						{
							//������Ҫ��� �����Խ�����
							carVectA[workcar].eleFlag = 1;
							//ִ�г�����
							//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
							carVectA[workcar].eleStatus = 0;
							carVectA[workcar].start = clock();
							carVectA[workcar].status = true;

						}
						else{
							carVectA[workcar].stop = 1;//��ʾ��Ҫͣ��
							carVectA[workcar].status = false;//��ʾ���Խ�����
							carVectA[workcar].start = clock();
						}
						m.show();
					}
				}
				/////////////////////////////////////////////////////2.A����ͣ������/////////////////////////////////////////////////////////////	
				for (int i = 0; i < caraSize; i++)
				{
					int APARKIndex = 0;
					int aParkRet = 0;
					for (int v = 0; v < aSpacesize; v++)
					{
						if (aSpace[v].status == false)
							APARKIndex++;
					}
					for (int v = 0; v < cSpacesize; v++)
					{
						if (cSpace[v].status == false)
							APARKIndex++;
					}

					if (APARKIndex > aParkNum)
						aParkRet = 1;
					else
						aParkRet = 2;

					if (carVectA[i].stop == 1)
					{
						for (int b = 0; b < aElesize; b++)
						{
							if (strcmp(aEle[b].index0.c_str(), carVectA[i].position.c_str()) == 0)
							{
								carVectA[i].restoreEle(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
							}
						}

						for (int p = 0; p < aLineSize; p++){
							if (strcmp(carVectA[i].position.c_str(), aLine[p].index0.c_str()) == 0)
							{
								carVectA[i].restoreLine(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
							}
						}
						int parkA = parkingA.strgetIndex0(carVectA[i].position.c_str());
						int *dist16 = new int[verNumA];
						int *path16 = new int[verNumA];
						parkingA.dijkstra(parkA, dist16, path16);

						for (int j = 0; j < aParksize1; j++)
						{
							aPark1[j].distance_A = dist16[parkingA.strgetIndex0(aPark1[j].index0.c_str())];
							// cout << aPark1[j].distance_A << endl;
						}
						for (int j = 0; j < aParksize2; j++)
						{
							aPark2[j].distance_A = dist16[parkingA.strgetIndex0(aPark2[j].index0.c_str())];
							// cout << aPark2[j].distance_A << endl;
						}

						minPark.clear();
						if (aParkRet == 1)
						{
							for (int k = 0; k < aParksize1; k++)
							{
								if (aPark1[k].status == false)
								{
									minPark.push_back(aPark1[k].distance_A);
								}
							}
						}

						if (aParkRet == 2)
						{
							for (int k = 0; k < aParksize2; k++)
							{
								if (aPark2[k].status == false)
								{
									minPark.push_back(aPark2[k].distance_A);
								}
							}
						}
						cout << minPark.size() << endl;
						sort(minPark.begin(), minPark.end());
						cout << minPark.size() << endl;
						//Ѱ������Ŀ���ͣ����
						if (aParkRet == 1)
						{
							for (int g = 0; g < aParksize1; g++)
							{
								if ((aPark1[g].distance_A == minPark[0]) && (aPark1[g].status == false))
								{
									cout << "minpark0" << minPark[0] << endl;
									cout << aPark1[g].distance_A << endl;
									parkindex = g;
									aPark1[g].status = true;
									break;
								}

							}
						}

						if (aParkRet == 2)
						{
							for (int g = 0; g < aParksize2; g++)
							{
								if ((aPark2[g].distance_A == minPark[0]) && (aPark2[g].status == false))
								{
									parkindex = g;
									aPark2[g].status = true;
									break;
								}

							}
						}


						//�����ʱ����v
						minPark.clear();
						//�����ͣ��λΪ�յ�滮ͣ��·��
						if (aParkRet == 1)
						{
							min = parkingA.strgetIndex0(aPark1[parkindex].index0.c_str());
							carVectA[i].s3.push(aPark1[parkindex].index0.c_str());
							aparkstr.clear();
							aparkstr = aPark1[parkindex].index0;
						}

						if (aParkRet == 2)
						{
							min = parkingA.strgetIndex0(aPark2[parkindex].index0.c_str());
							carVectA[i].s3.push(aPark2[parkindex].index0.c_str());
							aparkstr.clear();
							aparkstr = aPark2[parkindex].index0;
						}
						for (int j = path16[min]; j != parkA; j = path16[j])
							carVectA[i].s3.push(parkingA.Print(j).index0.c_str());

						//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
						if (carVectA[i].stop == 0)
						{
							//˵�������㹻���Խ�������������е����ж�
							if (aParkRet == 1)
								aPark1[parkindex].status = false;
							if (aParkRet == 2)
								aPark2[parkindex].status = false;
							while (!carVectA[i].s3.empty())
								carVectA[i].s3.pop();
							break;
						}
						else{
							//����ִ��ͣ������
							carVectA[i].end = clock();
							carVectA[i].eleNum = carVectA[i].calEle(carVectA[i].eleNum, carVectA[i].eleStatus, carVectA[i].start, carVectA[i].end);
							if (carVectA[i].eleNum < 25)
							{
								//��s3���
								while (!carVectA[i].s3.empty())
									carVectA[i].s3.pop();
								//ִ�г�����
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								carVectA[i].eleFlag = 1;
								carVectA[i].status = true;
								carVectA[i].start = clock();
								break;
							}
						}

						carVectA[i].start = clock();
						carVectA[i].eleStatus = 1;
						///С��ȥ��ͣ������ִ��
						//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
						while (carVectA[i].s3.size() != 0)
						{
							//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
							if (carVectA[i].stop == 0)
							{
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								while (!carVectA[i].s3.empty())
									carVectA[i].s3.pop();
								break;
							}
							//��ȥͣ����;��ִ�е����ж�
							carVectA[i].end = clock();
							carVectA[i].eleNum = carVectA[i].calEle(carVectA[i].eleNum, carVectA[i].eleStatus, carVectA[i].start, carVectA[i].end);
							///	carVectA[i].eleNum = 100;
							if (carVectA[i].eleNum < 25)
							{
								//��s3���
								while (!carVectA[i].s3.empty())
									carVectA[i].s3.pop();
								//ִ�г�����
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								carVectA[i].eleFlag = 1;
								carVectA[i].status = true;
								carVectA[i].start = clock();
								break;
							}

							if (strcmp(carVectA[i].s3.top().c_str(), aparkstr.c_str()) != 0)
							{
								for (int p = 0; p < aLineSize; p++)
								{
									if (strcmp(carVectA[i].s3.top().c_str(), aLine[p].index0.c_str()) == 0)
									{
										carVectA[i].position = carVectA[i].s3.top().c_str();
										cout << "ͣ����λ" << "---" << carVectA[i].position << endl;
										lineindex = p;
										if (aLine[p].status == false)
										{
											aLine[p].status = true;
											carVectA[i].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
											m.show();
										}
										else{
											Sleep(2000);
											carVectA[i].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
											m.show();
										}
									}
								}
								aLine[lineindex].status = false;
								carVectA[i].s3.pop();
								Sleep(2000);
								carVectA[i].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
							}
							else{
								carVectA[i].position = carVectA[i].s3.top().c_str();
								carVectA[i].s3.pop();

								if (aParkRet == 1){
									for (int b = 0; b < aParksize1; b++)
									{
										if (strcmp(aPark1[b].index0.c_str(), carVectA[i].position.c_str()) == 0)
										{
											carVectA[i].end = clock();
											carVectA[i].eleNum = carVectA[i].calEle(carVectA[i].eleNum, carVectA[i].eleStatus, carVectA[i].start, carVectA[i].end);
											if (carVectA[i].eleNum < 25)
											{
												//��s3���
												while (!carVectA[i].s3.empty())
													carVectA[i].s3.pop();
												//ִ�г�����
												if (aParkRet == 1)
													aPark1[parkindex].status = false;
												if (aParkRet == 2)
													aPark2[parkindex].status = false;
												carVectA[i].status = true;
												carVectA[i].eleFlag = 1;
												carVectA[i].start = clock();
												break;
											}

											carVectA[i].change(aPark1[b].x, aPark1[b].y, aPark1[b].length, aPark1[b].wide);
											carVectA[i].start = clock();
											carVectA[i].eleStatus = 0;
											m.show();
										}
									}
								}



								if (aParkRet == 2){
									for (int b = 0; b < aParksize2; b++)
									{
										if (strcmp(aPark2[b].index0.c_str(), carVectA[i].position.c_str()) == 0)
										{
											carVectA[i].end = clock();
											carVectA[i].eleNum = carVectA[i].calEle(carVectA[i].eleNum, carVectA[i].eleStatus, carVectA[i].start, carVectA[i].end);
											if (carVectA[i].eleNum < 25)
											{
												//��s3���
												while (!carVectA[i].s3.empty())
													carVectA[i].s3.pop();
												//ִ�г�����
												if (aParkRet == 1)
													aPark1[parkindex].status = false;
												if (aParkRet == 2)
													aPark2[parkindex].status = false;
												carVectA[i].status = true;
												carVectA[i].eleFlag = 1;
												carVectA[i].start = clock();
												break;
											}

											carVectA[i].change(aPark2[b].x, aPark2[b].y, aPark2[b].length, aPark2[b].wide);
											carVectA[i].start = clock();
											carVectA[i].eleStatus = 0;
											m.show();
										}
									}
								}
							}
						}
					}
				}
				/////////////A�ĳ�����////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				for (int i = 0; i < caraSize; i++)
				{
					if (carVectA[i].eleFlag == 1)
					{
						//�жϴ���һ����ִ�г�����
						//ͣ����
						for (int o = 0; o < aParksize1; o++)
						{
							if (strcmp(aPark1[o].index0.c_str(), carVectA[i].position.c_str()) == 0)
							{
								carVectA[i].ingChange(aPark1[o].x, aPark1[o].y, aPark1[o].length, aPark1[o].wide);
								aPark1[o].status = false;
								leavePosi = i;
								leaveStat = 0;
								aParkindex = 1;
							}
						}
						for (int o = 0; o < aParksize2; o++)
						{
							if (strcmp(aPark2[o].index0.c_str(), carVectA[i].position.c_str()) == 0)
							{
								carVectA[i].ingChange(aPark2[o].x, aPark2[o].y, aPark2[o].length, aPark2[o].wide);
								aPark2[o].status = false;
								leavePosi = i;
								leaveStat = 0;
								aParkindex = 2;
							}
						}
						//2.С������·�нӵ�
						for (int o = 0; o < aLineSize; o++)
						{
							if (strcmp(aLine[o].index0.c_str(), carVectA[i].position.c_str()) == 0)
							{
								carVectA[i].ingChange(aLine[o].x, aLine[o].y, aLine[o].length, aLine[o].wide);
								aLine[o].status = false;
								leavePosi = o;
								leaveStat = 1;
							}
						}


						int eleA = parkingA.strgetIndex0(carVectA[i].position.c_str());
						int *dist12 = new int[verNumA];
						int *path12 = new int[verNumA];
						parkingA.dijkstra(eleA, dist12, path12);

						for (int j = 0; j < aElesize; j++)
						{
							aEle[j].ele_Distance = dist12[parkingA.strgetIndex0(aEle[j].index0.c_str())];
						}
						for (int k = 0; k < aElesize; k++)
						{
							if (aEle[k].status == false)
							{
								minPark.push_back(aEle[k].ele_Distance);
							}
						}
						sort(minPark.begin(), minPark.end());
						//Ѱ������Ŀ��г���
						for (int g = 0; g < aElesize; g++)
						{
							if (aEle[g].ele_Distance == minPark[0] && aEle[g].status == false)
							{
								parkindex = g;
								aEle[g].status = true;
								break;
							}
						}
						//�����ʱ����v
						minPark.clear();
						//�����ͣ��λΪ�յ�滮ͣ��·��
						min = parkingA.strgetIndex0(aEle[parkindex].index0.c_str());
						////cout << aEle[parkindex].index0 << endl;
						while (!carVectA[i].s6.empty())
							carVectA[i].s6.pop();
						carVectA[i].s6.push(aEle[parkindex].index0.c_str());
						for (int j = path12[min]; j != eleA; j = path12[j])
							carVectA[i].s6.push(parkingA.Print(j).index0.c_str());


						carVectA[i].start = clock();
						carVectA[i].eleStatus = 2;
						///С��ȥ���������ִ��
						while (carVectA[i].s6.size() != 0)
						{
							if (leaveStat == 0)
							{
								if (aParkindex == 1)
								{
									carVectA[workcar].restorePark(aPark1[leavePosi].x, aPark1[leavePosi].y, aPark1[leavePosi].length, aPark1[leavePosi].wide);
								}
								if (aParkindex == 2)
								{
									carVectA[workcar].restorePark(aPark2[leavePosi].x, aPark2[leavePosi].y, aPark2[leavePosi].length, aPark2[leavePosi].wide);
								}
							}

							if (leaveStat == 1)
								carVectA[workcar].restoreLine(aLine[leavePosi].x, aLine[leavePosi].y, aLine[leavePosi].length, aLine[leavePosi].wide);

							if (strcmp(carVectA[i].s6.top().c_str(), aEle[parkindex].index0.c_str()) != 0)
							{
								for (int p = 0; p < aLineSize; p++)
								{
									if (strcmp(carVectA[i].s6.top().c_str(), aLine[p].index0.c_str()) == 0)
									{
										carVectA[i].position = carVectA[i].s6.top().c_str();
										lineindex = p;
										if (aLine[p].status == false)
										{
											aLine[p].status = true;
											carVectA[i].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
											m.show();
										}
										else{
											Sleep(2000);
											carVectA[i].change(aLine[p].x, aLine[p].y, aLine[p].length, aLine[p].wide);
											m.show();
										}
									}
								}
								aLine[lineindex].status = false;
								carVectA[i].s6.pop();
								Sleep(2000);
								carVectA[i].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
							}
							else{
								carVectA[i].position = carVectA[i].s6.top().c_str();
								carVectA[i].s6.pop();
								carVectA[i].position = aEle[parkindex].index0;
								for (int b = 0; b < aElesize; b++)
								{
									if (strcmp(aEle[b].index0.c_str(), carVectA[i].position.c_str()) == 0)
									{
										carVectA[i].change(aEle[b].x, aEle[b].y, aEle[b].length, aEle[b].wide);
										carVectA[i].eleStatus = 2;
										m.show();
									}
								}
								carVectA[i].status = false;
								carVectA[i].stop = 1;
								carVectA[i].start = clock();
								carVectA[i].eleNum = 100;

							}
						}
					}
				}
				///////////������/////////////////////////////////////////////

			}
			//Bȡ����ʼ/////////////////////////////////////////
			if (location == 2)
			{
				MessageBox::Show("ϵͳ����Ϊ����Bͣ����ȡ��");
				//�ж��ĸ���λ��ȡ�ó��Ƶĳ�
				for (int i = 0; i < bSpacesize; i++)
				{
					if (strcmp(bSpace[i].license.c_str(), license.c_str()) == 0)
					{
						pickIndex = i;
						chooseRet = 0;
						taskSpace.index0 = bSpace[i].index0;
						break;
					}
				}
				for (int i = 0; i < cSpacesize; i++)
				{
					if (strcmp(cSpace[i].license.c_str(), license.c_str()) == 0)
					{
						pickIndex = i;
						chooseRet = 1;
						taskSpace.index0 = cSpace[i].index0;
						break;
					};
				}
				int min = 0;
				if (chooseRet == 0)
					min = parkingB.strgetIndex0(bSpace[pickIndex].index0.c_str());
				else if (chooseRet == 1)
					min = parkingB.strgetIndex0(cSpace[pickIndex].index0.c_str());

				//��ȡ����λλ��Ϊ��ʼ��ѡ������Ĺ�����λ 
				int ret = parkingB.strgetIndex0(taskSpace.index0.c_str());
				int *dist5 = new int[verNum];
				int *path5 = new int[verNum];
				parkingB.dijkstra(ret, dist5, path5);

				//ѡ����С��
				//�ڴ�δ���е����ж���Ϊ״̬Ϊfalse˵�������㹻
				for (int i = 0; i < carbSize; i++)
				{
					if (carVectB[i].status == false)
					{
						carVectB[i].distance = dist5[parkingB.strgetIndex0(carVectB[i].position.c_str())];
						minCar.push_back(carVectB[i].distance);
					}
				}

				sort(minCar.begin(), minCar.end());
				for (int i = 0; i < carbSize; i++)
				{
					if (carVectB[i].status == false)
					{
						if (carVectB[i].distance == minCar[0])
						{
							workcar = i;
							break;
						}
					}
				}
				//1.С����ͣ�����ӵ�����
				for (int i = 0; i < bParksize; i++)
				{
					if (strcmp(bPark[i].index0.c_str(), carVectB[workcar].position.c_str()) == 0)
					{
						carVectB[workcar].ingChange(bPark[i].x, bPark[i].y, bPark[i].length, bPark[i].wide);
						bPark[i].status = false;
						leavePosi = i;
						leaveStat = 0;
					}
				}
				//2.С������·�нӵ�����
				for (int i = 0; i < bLineSize; i++)
				{
					if (strcmp(bLine[i].index0.c_str(), carVectB[workcar].position.c_str()) == 0)
					{
						carVectB[workcar].ingChange(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
						bLine[i].status = false;
						leavePosi = i;
						leaveStat = 1;
					}
				}
				//3.С���ӳ�����ӵ�����
				for (int i = 0; i < bElesize; i++)
				{
					if (strcmp(bEle[i].index0.c_str(), carVectB[workcar].position.c_str()) == 0)
					{
						carVectB[workcar].ingChange(bEle[i].x, bEle[i].y, bEle[i].length, bEle[i].wide);
						bEle[i].status = false;
						leavePosi = i;
						leaveStat = 2;
					}
				}
				carVectB[workcar].status = true;
				carVectB[workcar].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
				cout << "������С���±���" << carVectB[workcar].index << endl;


				while (!carVectB[workcar].s4.empty())
					carVectB[workcar].s4.pop();
				int pick = parkingB.strgetIndex0(carVectB[workcar].position.c_str());
				int *dist3 = new int[verNum];
				int *path3 = new int[verNum];
				parkingB.dijkstra(pick, dist3, path3);
				//��ȡС�������Ƴ�λ��·��
				//carVectB[workcar].s4.push(parkingB.Print(min).index0);
				for (int j = path3[min]; j != pick; j = path3[j])
					carVectB[workcar].s4.push(parkingB.Print(j).index0);



				//����С��ȥ��λ��ִ��
				carVectB[workcar].eleStatus = 1;
				carVectB[workcar].start = clock();
				while (carVectB[workcar].s4.size() != 0)
				{
					if (leaveStat == 0)
						carVectB[workcar].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
					////cout << "1����������" << endl;
					if (leaveStat == 1)
						//cout << arr[bLine[leavePosi].x][bLine[leavePosi].y] << endl;
						carVectB[workcar].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
					//cout << arr[bLine[leavePosi].x][bLine[leavePosi].y] << endl;
					if (leaveStat == 2)
						carVectB[workcar].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);

					if (strcmp(carVectB[workcar].s4.top().c_str(), parkingB.Print(min).index0.c_str()) != 0)
					{
						for (int i = 0; i < bLineSize; i++)
						{
							if (strcmp(carVectB[workcar].s4.top().c_str(), bLine[i].index0.c_str()) == 0)
							{
								lineindex = i;
								if (bLine[i].status == false)
								{
									bLine[i].status = true;
									carVectB[workcar].position = carVectB[workcar].s4.top();
									////cout << carVectB[workcar].position << endl;
									carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
									m.show();
								}
								else{
									Sleep(2000);
									carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
									carVectB[workcar].position = carVectB[workcar].s4.top();
									////cout << carVectB[workcar].position << endl;											
									m.show();
								}
							}
						}
						carVectB[workcar].s4.pop();
						Sleep(2000);
						carVectB[workcar].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
						bLine[lineindex].status = false;
					}
					else{
						if (leaveStat == 0)
							carVectB[workcar].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
						if (leaveStat == 1)
							carVectB[workcar].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
						if (leaveStat == 2)
							carVectB[workcar].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);
						Sleep(1000);
						carVectB[workcar].position = carVectB[workcar].s4.top();
						carVectB[workcar].s4.pop();
						/////////cout << carVectB[workcar].position << endl;
						m.show();
					}
				}
				//���С��ֱ�ӽ���ȡ���Ļ���Ҫ����Ĵ�������
				if (leaveStat == 0)
					carVectB[workcar].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
				if (leaveStat == 1)
					carVectB[workcar].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
				if (leaveStat == 2)
					carVectB[workcar].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);


				//����ȡ��
				if (chooseRet == 0){
					carVectB[workcar].restoreSpace(bSpace[pickIndex].x, bSpace[pickIndex].y, bSpace[pickIndex].length, bSpace[pickIndex].wide);
					bSpace[pickIndex].status = false;
					bSpace[pickIndex].license.clear();
				}
				else if (chooseRet == 1){
					carVectB[workcar].restoreSpace(cSpace[pickIndex].x, cSpace[pickIndex].y, cSpace[pickIndex].length, cSpace[pickIndex].wide);
					cSpace[pickIndex].status = false;
					cSpace[pickIndex].license.clear();
				}
				////m.show();

				/////ȡ�����ͳ�������
				int arrive = parkingB.strgetIndex0(carVectB[workcar].position.c_str());
				int *dist4 = new int[verNum];
				int *path4 = new int[verNum];
				parkingB.dijkstra(arrive, dist4, path4);
				//��ȡС�������ڵ����·��
				carVectB[workcar].s5.push("R57");
				min = parkingB.strgetIndex0("R57");
				for (int j = path4[min]; j != arrive; j = path4[j])
					carVectB[workcar].s5.push(parkingB.Print(j).index0);

				while (carVectB[workcar].s5.size() != 0)
				{
					if (strcmp(carVectB[workcar].s5.top().c_str(), "R57") != 0)
					{
						for (int i = 0; i < bLineSize; i++)
						{
							if (strcmp(carVectB[workcar].s5.top().c_str(), bLine[i].index0.c_str()) == 0)
							{
								lineindex = i;
								if (bLine[i].status == false)
								{
									bLine[i].status = true;
									carVectB[workcar].position = carVectB[workcar].s5.top();
									////	cout << carVectB[workcar].position << endl;
									carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
									m.show();
								}
								else{
									Sleep(2000);
									carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
									carVectB[workcar].position = carVectB[workcar].s5.top();
									/////		cout << carVectB[workcar].position << endl;											
									m.show();
								}
							}
						}
						carVectB[workcar].s5.pop();
						Sleep(2000);
						carVectB[workcar].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
						bLine[lineindex].status = false;
					}
					else{
						Sleep(1000);
						carVectB[workcar].position = carVectB[workcar].s5.top();
						carVectB[workcar].s5.pop();
						for (int i = 0; i < bLineSize; i++){
							if (strcmp(carVectB[workcar].position.c_str(), bLine[i].index0.c_str()) == 0)
							{
								carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
							}
						}
						////cout << carVectB[workcar].position << endl;
						m.show();

						carVectB[workcar].end = clock();
						carVectB[workcar].eleNum = carVectB[workcar].calEle(carVectB[workcar].eleNum, carVectB[workcar].eleStatus, carVectB[workcar].start, carVectB[workcar].end);
						////cout << carVectB[workcar].eleNum << endl;
						if (carVectB[workcar].eleNum <= 25)
						{
							//������Ҫ��� �����Խ�����
							carVectB[workcar].eleFlag = 1;
							//ִ�г�����
							//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
							carVectB[workcar].eleStatus = 0;
							carVectB[workcar].start = clock();
							carVectB[workcar].status = true;

						}
						else{
							carVectB[workcar].stop = 1;//��ʾ��Ҫͣ��
							carVectB[workcar].status = false;//��ʾ���Խ�����
							carVectB[workcar].start = clock();
						}
						m.show();
						cout << "ȡ�����" << endl;
					}
				}

				//Bͣ��///////////////////////////////////////////////////////////////////////////////
				for (int i = 0; i < carbSize; i++)
				{
					if (carVectB[i].stop == 1)
					{
						for (int b = 0; b < bElesize; b++)
						{
							if (strcmp(bEle[b].index0.c_str(), carVectB[i].position.c_str()) == 0)
							{
								carVectB[i].restoreEle(bEle[b].x, bEle[b].y, bEle[b].length, bEle[b].wide);
							}
						}
						for (int l = 0; l < bLineSize; l++){
							if (strcmp(carVectB[i].position.c_str(), bLine[l].index0.c_str()) == 0)
							{
								carVectB[i].restoreLine(bLine[l].x, bLine[l].y, bLine[l].length, bLine[l].wide);
							}
						}
						int park = parkingB.strgetIndex0(carVectB[i].position.c_str());
						int *dist2 = new int[verNum];
						int *path2 = new int[verNum];
						parkingB.dijkstra(park, dist2, path2);

						for (int j = 0; j < bParksize; j++)
						{
							bPark[j].distance_B = dist2[parkingB.strgetIndex0(bPark[j].index0.c_str())];
						}
						for (int k = 0; k < bParksize; k++)
						{
							if (bPark[k].status == false)
							{
								minPark.push_back(bPark[k].distance_B);
							}
						}
						sort(minPark.begin(), minPark.end());
						//Ѱ������Ŀ���ͣ����
						for (int g = 0; g < bParksize; g++)
						{
							if (bPark[g].distance_B == minPark[0] && bPark[g].status == false)
							{
								parkindex = g;
								bPark[g].status = true;
								break;
							}

						}
						//�����ʱ����v
						minPark.clear();
						//�����ͣ��λΪ�յ�滮ͣ��·��
						min = parkingB.strgetIndex0(bPark[parkindex].index0.c_str());
						carVectB[i].s3.push(bPark[parkindex].index0.c_str());
						for (int j = path2[min]; j != park; j = path2[j])
							carVectB[i].s3.push(parkingB.Print(j).index0.c_str());

						//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
						if (carVectB[i].stop == 0)
						{
							//˵�������㹻���Խ�������������е����ж�
							bPark[parkindex].status = false;
							while (!carVectB[i].s3.empty())
								carVectB[i].s3.pop();
							break;
						}
						else{
							//����ִ��ͣ������
							carVectB[i].end = clock();
							carVectB[i].eleNum = carVectB[i].calEle(carVectB[i].eleNum, carVectB[i].eleStatus, carVectB[i].start, carVectB[i].end);
							if (carVectB[i].eleNum < 25)
							{
								//��s3���
								while (!carVectB[i].s3.empty())
									carVectB[i].s3.pop();
								//ִ�г�����
								bPark[parkindex].status = false;
								carVectB[i].eleFlag = 1;
								carVectB[i].status = true;
								carVectB[i].start = clock();
								break;
							}
						}

						carVectB[i].start = clock();
						carVectB[i].eleStatus = 1;
						///С��ȥ��ͣ������ִ��
						//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
						while (carVectB[i].s3.size() != 0)
						{
							//�����Ҫͣ��С����Ҫ�����ܽ����ͣ����λ�Ļؿ���״̬������
							if (carVectB[i].stop == 0)
							{
								bPark[parkindex].status = false;
								while (!carVectB[i].s3.empty())
									carVectB[i].s3.pop();
								break;
							}
							//��ȥͣ����;��ִ�е����ж�
							carVectB[i].end = clock();
							carVectB[i].eleNum = carVectB[i].calEle(carVectB[i].eleNum, carVectB[i].eleStatus, carVectB[i].start, carVectB[i].end);
							if (carVectB[i].eleNum < 25)
							{
								//��s3���
								while (!carVectB[i].s3.empty())
									carVectB[i].s3.pop();
								//ִ�г�����
								bPark[parkindex].status = false;
								carVectB[i].eleFlag = 1;
								carVectB[i].status = true;
								carVectB[i].start = clock();
								break;
							}

							if (strcmp(carVectB[i].s3.top().c_str(), bPark[parkindex].index0.c_str()) != 0)
							{
								for (int p = 0; p < bLineSize; p++)
								{
									if (strcmp(carVectB[i].s3.top().c_str(), bLine[p].index0.c_str()) == 0)
									{
										carVectB[i].position = carVectB[i].s3.top().c_str();
										cout << "ͣ����λ" << "---" << carVectB[i].position << endl;
										lineindex = p;
										if (bLine[p].status == false)
										{
											bLine[p].status = true;
											carVectB[i].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
											m.show();
										}
										else{
											Sleep(2000);
											carVectB[i].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
											m.show();
										}
									}
								}
								bLine[lineindex].status = false;
								carVectB[i].s3.pop();
								Sleep(2000);
								carVectB[i].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
							}
							else{
								carVectB[i].position = carVectB[i].s3.top().c_str();
								cout << "ͣ����λ" << "---" << carVectB[i].position << endl;
								carVectB[i].s3.pop();
								for (int b = 0; b < bParksize; b++)
								{
									if (strcmp(bPark[b].index0.c_str(), carVectB[i].position.c_str()) == 0)
									{

										carVectB[i].end = clock();
										carVectB[i].eleNum = carVectB[i].calEle(carVectB[i].eleNum, carVectB[i].eleStatus, carVectB[i].start, carVectB[i].end);
										if (carVectB[i].eleNum < 25)
										{
											//��s3���
											while (!carVectB[i].s3.empty())
												carVectB[i].s3.pop();
											//ִ�г�����
											bPark[parkindex].status = false;
											carVectB[i].status = true;
											carVectB[i].eleFlag = 1;
											carVectB[i].start = clock();
											break;
										}

										carVectB[i].change(bPark[b].x, bPark[b].y, bPark[b].length, bPark[b].wide);
										carVectB[i].start = clock();
										carVectB[i].eleStatus = 0;
										m.show();
									}
								}

							}
						}
					}
				}
				///////
				////B���////////////////////
				for (int i = 0; i < carbSize; i++)
				{
					if (carVectB[i].eleFlag == 1)
					{
						//�жϴ���һ����ִ�г�����
						for (int o = 0; o < bParksize; o++)
						{
							if (strcmp(bPark[o].index0.c_str(), carVectB[i].position.c_str()) == 0)
							{
								carVectB[i].ingChange(bPark[o].x, bPark[o].y, bPark[o].length, bPark[o].wide);
								bPark[o].status = false;
								leavePosi = o;
								leaveStat = 0;
							}
						}
						//2.С������·�нӵ�
						for (int o = 0; o < bLineSize; o++)
						{
							if (strcmp(bLine[o].index0.c_str(), carVectB[i].position.c_str()) == 0)
							{
								carVectB[i].ingChange(bLine[o].x, bLine[o].y, bLine[o].length, bLine[o].wide);
								bLine[o].status = false;
								leavePosi = o;
								leaveStat = 1;
							}
						}
						int ele = parkingB.strgetIndex0(carVectB[i].position.c_str());
						int *dist6 = new int[verNum];
						int *path6 = new int[verNum];
						parkingB.dijkstra(ele, dist6, path6);

						for (int j = 0; j < bElesize; j++)
						{
							bEle[j].ele_Distance = dist6[parkingB.strgetIndex0(bEle[j].index0.c_str())];
						}
						for (int k = 0; k < bElesize; k++)
						{
							if (bEle[k].status == false)
							{
								minPark.push_back(bEle[k].ele_Distance);
							}
						}
						sort(minPark.begin(), minPark.end());
						//Ѱ������Ŀ��г���
						for (int g = 0; g < bElesize; g++)
						{
							if (bEle[g].ele_Distance == minPark[0] && bEle[g].status == false)
							{
								parkindex = g;
								bEle[g].status = true;
								break;
							}
						}
						//�����ʱ����v
						minPark.clear();
						//�����ͣ��λΪ�յ�滮ͣ��·��
						min = parkingB.strgetIndex0(bEle[parkindex].index0.c_str());
						while (!carVectB[i].s6.empty())
							carVectB[i].s6.pop();
						carVectB[i].s6.push(bEle[parkindex].index0.c_str());
						for (int j = path6[min]; j != ele; j = path6[j])
							carVectB[i].s6.push(parkingB.Print(j).index0.c_str());


						carVectB[i].start = clock();
						carVectB[i].eleStatus = 2;
						///С��ȥ���������ִ��
						while (carVectB[i].s6.size() != 0)
						{
							if (leaveStat == 0)
								carVectB[i].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
							if (leaveStat == 1)
								carVectB[i].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);

							if (strcmp(carVectB[i].s6.top().c_str(), bEle[parkindex].index0.c_str()) != 0)
							{
								for (int p = 0; p < bLineSize; p++)
								{
									if (strcmp(carVectB[i].s6.top().c_str(), bLine[p].index0.c_str()) == 0)
									{
										carVectB[i].position = carVectB[i].s6.top().c_str();
										cout << "ͣ����λ" << "---" << carVectB[i].position << endl;
										lineindex = p;
										if (bLine[p].status == false)
										{
											bLine[p].status = true;
											carVectB[i].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
											m.show();
										}
										else{
											Sleep(2000);
											carVectB[i].change(bLine[p].x, bLine[p].y, bLine[p].length, bLine[p].wide);
											m.show();
										}
									}
								}
								bLine[lineindex].status = false;
								carVectB[i].s6.pop();
								Sleep(2000);
								carVectB[i].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
							}
							else{
								carVectB[i].position = carVectB[i].s6.top().c_str();
								carVectB[i].s6.pop();
								carVectB[i].position = bEle[parkindex].index0;
								cout << "����λ" << "---" << carVectB[i].position << endl;
								for (int b = 0; b < bElesize; b++)
								{
									if (strcmp(bEle[b].index0.c_str(), carVectB[i].position.c_str()) == 0)
									{
										carVectB[i].change(bEle[b].x, bEle[b].y, bEle[b].length, bEle[b].wide);
										carVectB[i].eleStatus = 2;
										m.show();
									}
								}
								carVectB[i].status = false;
								carVectB[i].stop = 1;
								carVectB[i].start = clock();
								carVectB[i].eleNum = 100;

							}
						}
						cout << "������" << endl;
						cout << "����λ" << "---" << carVectB[i].position << endl;
					}
				}
				////////////////////////////
			}

		}
		else if ((strcmp(revData, "��ѯ���ݿ�") == 0)){
			sql.QueryDatabase1();
			send(*ClientSocket, "��ѯ���ݿ������Ѵ���\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "չʾͣ����") == 0)){
			send(*ClientSocket, "չʾͣ���������Ѵ���\n", sizeof(sendData), 0);
			m.show();
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

