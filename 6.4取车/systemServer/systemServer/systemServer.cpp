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
vector<int> minDistance;//选择最近车位(排序）
vector<int> minPark;//停靠排序
vector<int> minCar;//取车排序选择最近的小车
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
int chooseRet = 0;//选择停车场结果索引/取车时判定车位
int minIndex = 0;//最近车位索引判断在那个车位区域
int task;//选择停车/取车任务
int workcar;//空闲小车的索引
int minspace = 999;//判断在那个车位区域 起中间判定作用
int leavePosi;//代表小车离开时的车位
int leaveStat;//代表小车接到任务时所在位置的属性
int lineindex = 0;//代表行使中线路索引
int parkindex;//停靠索引
int pickIndex;//取车索引
int aParkindex;
int verNum; int startB; int* dist; int *path;
int verNumA; int startA; int* dist7; int *path7;

[STAThread]


void bParkProCar1()
{
	int work = 0;
	carVectB[work].status = true;//将状态改为使用
	carVectB[work].stop = 0;//如果在停靠的路上也将其利用去进行工作
	carVectB[work].eleFlag = 0;//如果是正在充电的将充电标志改为否
	//cout << "工作的小车下标是" << carVectB[workcar].index << endl;
	//MessageBox::Show("工作小车的下标为:" + carVectB[workcar].index);
	//选择最近的车位
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
	//判断最近车位在哪个区域
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

	minDistance.clear();//在其使用完时进行清空，以便下一次使用
	int minbp = 0;
	if (minIndex == 1)
		minbp = parkingB.strgetIndex0(bSpace[carVectB[work].carindex].index0.c_str());
	else if (minIndex == 2)
		minbp = parkingB.strgetIndex0(cSpace[carVectB[work].carindex].index0.c_str());
	//到此已选择出最近车位
	//存取出口到最近车位的路线
	while (!carVectB[work].s1.empty())
		carVectB[work].s1.pop();
	carVectB[work].s1.push(parkingB.Print(minbp).index0);
	for (int j = path[minbp]; j != startB; j = path[j])
		carVectB[work].s1.push(parkingB.Print(j).index0);

	//以小车当前位置为起点计算到出口的最近路线
	int leave = parkingB.strgetIndex0(carVectB[work].position.c_str());
	int *dist1 = new int[verNum];
	int *path1 = new int[verNum];
	parkingB.dijkstra(leave, dist1, path1);
	//存取小车到出口的最近路线
	while (!carVectB[work].s2.empty())
		carVectB[work].s2.pop();
	carVectB[work].s2.push(parkingB.Print(startB).index0);
	for (int j = path1[startB]; j != leave; j = path1[j])
		carVectB[work].s2.push(parkingB.Print(j).index0);

	cout << "小车" << carVectB[work].index << "开始行使" << endl;
	//记录任务小车离开时的位置
	//1.小车从停靠区接到任务
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
	//2.小车从线路中接到任务
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
	//3.小车从充电区接到任务
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

	//任务小车去出口的过程
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
	//小车已经接收到需要停的车辆赶往最近车位的路上
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
			cout << "小车" << carVectB[work].index << "行使1的" << carVectB[work].s1.size() << endl;
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
				//表明需要充电 不可以接任务
				carVectB[work].eleFlag = 1;
				//执行充电策略
				//状态改为停靠，寻找到充电区进行执行
				carVectB[work].eleStatus = 0;
				carVectB[work].start = clock();
			}
			else{
				carVectB[work].stop = 1;//表示需要停靠
				carVectB[work].status = false;//表示可以接任务
				carVectB[work].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}


	//B停靠///////////////////////////////////////////////////////////////////////////////
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
		//寻找最近的空闲停车点
		for (int g = 0; g < bParksize; g++)
		{
			if (bPark[g].distance_B == minPark[0] && bPark[g].status == false)
			{
				parkindex = g;
				bPark[g].status = true;
				break;
			}

		}
		//清空临时排序v
		minPark.clear();
		//以最近停靠位为终点规划停靠路线
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bPark[parkindex].index0.c_str());
		while (!carVectB[work].s3.empty())
			carVectB[work].s3.pop();
		carVectB[work].s3.push(bPark[parkindex].index0.c_str());
		for (int j = path2[minbp]; j != park; j = path2[j])
			carVectB[work].s3.push(parkingB.Print(j).index0.c_str());

		//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
		if (carVectB[work].stop == 0)
		{
			//说明电量足够可以接受任务，无需进行电量判断
			bPark[parkindex].status = false;
			while (!carVectB[work].s3.empty()){
				carVectB[work].s3.pop();
			}
			//break;
		}
		else{
			//继续执行停靠策略
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//将s3清空
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//执行充电策略
				bPark[parkindex].status = false;
				carVectB[work].eleFlag = 1;
				carVectB[work].status = true;
				carVectB[work].start = clock();
				//break;
			}
		}

		carVectB[work].start = clock();
		carVectB[work].eleStatus = 1;
		///小车去往停靠区的执行
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectB[work].s3.size() != 0)
		{
			//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
			if (carVectB[work].stop == 0)
			{
				bPark[parkindex].status = false;
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				break;
			}
			//在去停靠的途中执行电量判断
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//将s3清空
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//执行充电策略
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
							//将s3清空
							while (!carVectB[work].s3.empty())
								carVectB[work].s3.pop();
							//执行充电策略
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
	///////////B充电////////////////////
	if (carVectB[work].eleFlag == 1)
	{
		//判断从那一部分执行充电策略
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
		//2.小车从线路中接到
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
		//寻找最近的空闲充电点
		for (int g = 0; g < bElesize; g++)
		{
			if (bEle[g].ele_Distance == minPark[0] && bEle[g].status == false)
			{
				parkindex = g;
				bEle[g].status = true;
				break;
			}
		}
		//清空临时排序v
		minPark.clear();
		//以最近停靠位为终点规划停靠路线
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bEle[parkindex].index0.c_str());
		while (!carVectB[work].s6.empty())
			carVectB[work].s6.pop();
		carVectB[work].s6.push(bEle[parkindex].index0.c_str());
		for (int j = path6[minbp]; j != ele; j = path6[j])
			carVectB[work].s6.push(parkingB.Print(j).index0.c_str());


		carVectB[work].start = clock();
		carVectB[work].eleStatus = 2;
		///小车去往充电区的执行
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
	carVectB[work].status = true;//将状态改为使用
	carVectB[work].stop = 0;//如果在停靠的路上也将其利用去进行工作
	carVectB[work].eleFlag = 0;//如果是正在充电的将充电标志改为否
	//cout << "工作的小车下标是" << carVectB[workcar].index << endl;
	//MessageBox::Show("工作小车的下标为:" + carVectB[workcar].index);
	//选择最近的车位
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
	//判断最近车位在哪个区域
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

	minDistance.clear();//在其使用完时进行清空，以便下一次使用
	int minbp = 0;
	if (minIndex == 1)
		minbp = parkingB.strgetIndex0(bSpace[carVectB[work].carindex].index0.c_str());
	else if (minIndex == 2)
		minbp = parkingB.strgetIndex0(cSpace[carVectB[work].carindex].index0.c_str());
	//到此已选择出最近车位
	//存取出口到最近车位的路线
	while (!carVectB[work].s1.empty())
		carVectB[work].s1.pop();
	carVectB[work].s1.push(parkingB.Print(minbp).index0);
	for (int j = path[minbp]; j != startB; j = path[j])
		carVectB[work].s1.push(parkingB.Print(j).index0);

	//以小车当前位置为起点计算到出口的最近路线
	int leave = parkingB.strgetIndex0(carVectB[work].position.c_str());
	int *dist1 = new int[verNum];
	int *path1 = new int[verNum];
	parkingB.dijkstra(leave, dist1, path1);
	//存取小车到出口的最近路线
	while (!carVectB[work].s2.empty())
		carVectB[work].s2.pop();
	carVectB[work].s2.push(parkingB.Print(startB).index0);
	for (int j = path1[startB]; j != leave; j = path1[j])
		carVectB[work].s2.push(parkingB.Print(j).index0);

	cout << "小车" << carVectB[work].index << "开始行使" << endl;
	//记录任务小车离开时的位置
	//1.小车从停靠区接到任务
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
	//2.小车从线路中接到任务
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
	//3.小车从充电区接到任务
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

	//任务小车去出口的过程
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
	//小车已经接收到需要停的车辆赶往最近车位的路上
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
			cout << "小车" << carVectB[work].index << "行使1的" << carVectB[work].s1.size() << endl;
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
				//表明需要充电 不可以接任务
				carVectB[work].eleFlag = 1;
				//执行充电策略
				//状态改为停靠，寻找到充电区进行执行
				carVectB[work].eleStatus = 0;
				carVectB[work].start = clock();
			}
			else{
				carVectB[work].stop = 1;//表示需要停靠
				carVectB[work].status = false;//表示可以接任务
				carVectB[work].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}


	//B停靠///////////////////////////////////////////////////////////////////////////////
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
		//寻找最近的空闲停车点
		for (int g = 0; g < bParksize; g++)
		{
			if (bPark[g].distance_B == minPark[0] && bPark[g].status == false)
			{
				parkindex = g;
				bPark[g].status = true;
				break;
			}

		}
		//清空临时排序v
		minPark.clear();
		//以最近停靠位为终点规划停靠路线
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bPark[parkindex].index0.c_str());
		while (!carVectB[work].s3.empty())
			carVectB[work].s3.pop();
		carVectB[work].s3.push(bPark[parkindex].index0.c_str());
		for (int j = path2[minbp]; j != park; j = path2[j])
			carVectB[work].s3.push(parkingB.Print(j).index0.c_str());

		//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
		if (carVectB[work].stop == 0)
		{
			//说明电量足够可以接受任务，无需进行电量判断
			bPark[parkindex].status = false;
			while (!carVectB[work].s3.empty()){
				carVectB[work].s3.pop();
			}
			//break;
		}
		else{
			//继续执行停靠策略
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//将s3清空
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//执行充电策略
				bPark[parkindex].status = false;
				carVectB[work].eleFlag = 1;
				carVectB[work].status = true;
				carVectB[work].start = clock();
				//break;
			}
		}

		carVectB[work].start = clock();
		carVectB[work].eleStatus = 1;
		///小车去往停靠区的执行
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectB[work].s3.size() != 0)
		{
			//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
			if (carVectB[work].stop == 0)
			{
				bPark[parkindex].status = false;
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				break;
			}
			//在去停靠的途中执行电量判断
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//将s3清空
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//执行充电策略
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
							//将s3清空
							while (!carVectB[work].s3.empty())
								carVectB[work].s3.pop();
							//执行充电策略
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
	///////////B充电////////////////////
	if (carVectB[work].eleFlag == 1)
	{
		//判断从那一部分执行充电策略
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
		//2.小车从线路中接到
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
		//寻找最近的空闲充电点
		for (int g = 0; g < bElesize; g++)
		{
			if (bEle[g].ele_Distance == minPark[0] && bEle[g].status == false)
			{
				parkindex = g;
				bEle[g].status = true;
				break;
			}
		}
		//清空临时排序v
		minPark.clear();
		//以最近停靠位为终点规划停靠路线
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bEle[parkindex].index0.c_str());
		while (!carVectB[work].s6.empty())
			carVectB[work].s6.pop();
		carVectB[work].s6.push(bEle[parkindex].index0.c_str());
		for (int j = path6[minbp]; j != ele; j = path6[j])
			carVectB[work].s6.push(parkingB.Print(j).index0.c_str());


		carVectB[work].start = clock();
		carVectB[work].eleStatus = 2;
		///小车去往充电区的执行
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
	carVectB[work].status = true;//将状态改为使用
	carVectB[work].stop = 0;//如果在停靠的路上也将其利用去进行工作
	carVectB[work].eleFlag = 0;//如果是正在充电的将充电标志改为否
	//cout << "工作的小车下标是" << carVectB[workcar].index << endl;
	//MessageBox::Show("工作小车的下标为:" + carVectB[workcar].index);
	//选择最近的车位
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
	//判断最近车位在哪个区域
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

	minDistance.clear();//在其使用完时进行清空，以便下一次使用
	int minbp = 0;
	if (minIndex == 1)
		minbp = parkingB.strgetIndex0(bSpace[carVectB[work].carindex].index0.c_str());
	else if (minIndex == 2)
		minbp = parkingB.strgetIndex0(cSpace[carVectB[work].carindex].index0.c_str());
	//到此已选择出最近车位
	//存取出口到最近车位的路线
	while (!carVectB[work].s1.empty())
		carVectB[work].s1.pop();
	carVectB[work].s1.push(parkingB.Print(minbp).index0);
	for (int j = path[minbp]; j != startB; j = path[j])
		carVectB[work].s1.push(parkingB.Print(j).index0);

	//以小车当前位置为起点计算到出口的最近路线
	int leave = parkingB.strgetIndex0(carVectB[work].position.c_str());
	int *dist1 = new int[verNum];
	int *path1 = new int[verNum];
	parkingB.dijkstra(leave, dist1, path1);
	//存取小车到出口的最近路线
	while (!carVectB[work].s2.empty())
		carVectB[work].s2.pop();
	carVectB[work].s2.push(parkingB.Print(startB).index0);
	for (int j = path1[startB]; j != leave; j = path1[j])
		carVectB[work].s2.push(parkingB.Print(j).index0);

	cout << "小车" << carVectB[work].index << "开始行使" << endl;
	//记录任务小车离开时的位置
	//1.小车从停靠区接到任务
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
	//2.小车从线路中接到任务
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
	//3.小车从充电区接到任务
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

	//任务小车去出口的过程
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
	//小车已经接收到需要停的车辆赶往最近车位的路上
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
			cout << "小车" << carVectB[work].index << "行使1的" << carVectB[work].s1.size() << endl;
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
				//表明需要充电 不可以接任务
				carVectB[work].eleFlag = 1;
				//执行充电策略
				//状态改为停靠，寻找到充电区进行执行
				carVectB[work].eleStatus = 0;
				carVectB[work].start = clock();
			}
			else{
				carVectB[work].stop = 1;//表示需要停靠
				carVectB[work].status = false;//表示可以接任务
				carVectB[work].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}


	//B停靠///////////////////////////////////////////////////////////////////////////////
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
		//寻找最近的空闲停车点
		for (int g = 0; g < bParksize; g++)
		{
			if (bPark[g].distance_B == minPark[0] && bPark[g].status == false)
			{
				parkindex = g;
				bPark[g].status = true;
				break;
			}

		}
		//清空临时排序v
		minPark.clear();
		//以最近停靠位为终点规划停靠路线
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bPark[parkindex].index0.c_str());
		while (!carVectB[work].s3.empty())
			carVectB[work].s3.pop();
		carVectB[work].s3.push(bPark[parkindex].index0.c_str());
		for (int j = path2[minbp]; j != park; j = path2[j])
			carVectB[work].s3.push(parkingB.Print(j).index0.c_str());

		//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
		if (carVectB[work].stop == 0)
		{
			//说明电量足够可以接受任务，无需进行电量判断
			bPark[parkindex].status = false;
			while (!carVectB[work].s3.empty()){
				carVectB[work].s3.pop();
			}
			//break;
		}
		else{
			//继续执行停靠策略
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//将s3清空
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//执行充电策略
				bPark[parkindex].status = false;
				carVectB[work].eleFlag = 1;
				carVectB[work].status = true;
				carVectB[work].start = clock();
				//break;
			}
		}

		carVectB[work].start = clock();
		carVectB[work].eleStatus = 1;
		///小车去往停靠区的执行
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectB[work].s3.size() != 0)
		{
			//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
			if (carVectB[work].stop == 0)
			{
				bPark[parkindex].status = false;
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				break;
			}
			//在去停靠的途中执行电量判断
			carVectB[work].end = clock();
			carVectB[work].eleNum = carVectB[work].calEle(carVectB[work].eleNum, carVectB[work].eleStatus, carVectB[work].start, carVectB[work].end);
			if (carVectB[work].eleNum < 25)
			{
				//将s3清空
				while (!carVectB[work].s3.empty())
					carVectB[work].s3.pop();
				//执行充电策略
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
							//将s3清空
							while (!carVectB[work].s3.empty())
								carVectB[work].s3.pop();
							//执行充电策略
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
	///////////B充电////////////////////
	if (carVectB[work].eleFlag == 1)
	{
		//判断从那一部分执行充电策略
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
		//2.小车从线路中接到
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
		//寻找最近的空闲充电点
		for (int g = 0; g < bElesize; g++)
		{
			if (bEle[g].ele_Distance == minPark[0] && bEle[g].status == false)
			{
				parkindex = g;
				bEle[g].status = true;
				break;
			}
		}
		//清空临时排序v
		minPark.clear();
		//以最近停靠位为终点规划停靠路线
		int minbp = 0;
		minbp = parkingB.strgetIndex0(bEle[parkindex].index0.c_str());
		while (!carVectB[work].s6.empty())
			carVectB[work].s6.pop();
		carVectB[work].s6.push(bEle[parkindex].index0.c_str());
		for (int j = path6[minbp]; j != ele; j = path6[j])
			carVectB[work].s6.push(parkingB.Print(j).index0.c_str());


		carVectB[work].start = clock();
		carVectB[work].eleStatus = 2;
		///小车去往充电区的执行
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
	carVectA[awork].status = true;//将状态改为使用
	carVectA[awork].stop = 0;//如果在停靠的路上也将其利用去进行工作
	carVectA[awork].eleFlag = 0;//如果是正在充电的将充电标志改为否
	cout << "工作的小车下标是" << carVectA[awork].index << endl;
	//MessageBox::Show("工作小车的下标为:" + carVectA[workcar].index);
	vector<int> aminDist;
	//选择最近的车位
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
	//判断最近车位在哪个区域
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
	aminDist.clear();//在其使用完时进行清空，以便下一次使用

	int minap;//获取最近车位在图中的输入次序
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//到此已选择出最近车位
	//存取出口到最近车位的路线
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//以小车当前位置为起点计算到出口的最近路线
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//存取小车到出口的最近路线
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//记录任务小车离开时的位置
	//1.小车从停靠区接到任务
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
	//2.小车从线路中接到任务
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
	//3.小车从充电区接到任务
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

	//任务小车去出口的过程
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
	//小车已经接收到需要停的车辆赶往最近车位的路上
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
				//表明需要充电 不可以接任务
				carVectA[awork].eleFlag = 1;
				//执行充电策略
				//状态改为停靠，寻找到充电区进行执行
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//表示需要停靠
				carVectA[awork].status = false;//表示可以接任务
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "停车完成" << endl;
	//	MessageBox::Show("停车任务完成");
	/////////////////////////////////////////////////////2.A区域停靠策略/////////////////////////////////////////////////////////////	
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
			//寻找最近的空闲停车点
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


			//清空临时排序v
			minParka.clear();
			//以最近停靠位为终点规划停靠路线
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

			//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
			if (carVectA[awork].stop == 0)
			{
				//说明电量足够可以接受任务，无需进行电量判断
				if (aParkRet == 1)
					aPark1[parkindex].status = false;
				if (aParkRet == 2)
					aPark2[parkindex].status = false;
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//break;
			}
			else{
				//继续执行停靠策略
				carVectA[awork].end = clock();
				carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
				if (carVectA[awork].eleNum < 25)
				{
					//将s3清空
					while (!carVectA[awork].s3.empty())
						carVectA[awork].s3.pop();
					//执行充电策略
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
			///小车去往停靠区的执行
			//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
			while (carVectA[awork].s3.size() != 0)
			{
				//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
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
				//在去停靠的途中执行电量判断
				carVectA[awork].end = clock();
				carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
				///	carVectA[i].eleNum = 100;
				if (carVectA[awork].eleNum < 25)
				{
					//将s3清空
					while (!carVectA[awork].s3.empty())
						carVectA[awork].s3.pop();
					//执行充电策略
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
					//cout << carVectA[awork].index << "停靠还有" << carVectA[awork].s3.size() <<"步"<< endl;
				}
				else{
					carVectA[awork].position = carVectA[awork].s3.top().c_str();
					carVectA[awork].s3.pop();
					//cout << carVectA[awork].index << "停靠最后一步" << endl;
					if (aParkRet == 1){
						for (int b = 0; b < aParksize1; b++)
						{
							if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
							{
								carVectA[awork].end = clock();
								carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
								if (carVectA[awork].eleNum < 25)
								{
									//将s3清空
									while (!carVectA[awork].s3.empty())
										carVectA[awork].s3.pop();
									if (aParkRet == 1)
										aPark1[parkindex].status = false;
									if (aParkRet == 2)
										aPark2[parkindex].status = false;
									//执行充电策略
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
									//将s3清空
									while (!carVectA[awork].s3.empty())
										carVectA[awork].s3.pop();
									//执行充电策略
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
		/////////////A的充电策略////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (carVectA[awork].eleFlag == 1)
			{
				//判断从那一部分执行充电策略
				//停靠区
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
				//2.小车从线路中接到
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
				//寻找最近的空闲充电点
				for (int g = 0; g < aElesize; g++)
				{
					if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
					{
						parkindex = g;
						aEle[g].status = true;
						break;
					}
				}
				//清空临时排序v
				minElea.clear();
				//以最近停靠位为终点规划停靠路线
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
				///小车去往充电区的执行
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
		///////////充电完毕/////////////////////////////////////////////
	/////////////////////////////////////
}

void aParkProCar5()
{
	int awork = 1;
	carVectA[awork].status = true;//将状态改为使用
	carVectA[awork].stop = 0;//如果在停靠的路上也将其利用去进行工作
	carVectA[awork].eleFlag = 0;//如果是正在充电的将充电标志改为否
	cout << "工作的小车下标是" << carVectA[awork].index << endl;
	//MessageBox::Show("工作小车的下标为:" + carVectA[workcar].index);
	vector<int> aminDist;
	//选择最近的车位
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
	//判断最近车位在哪个区域
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
	aminDist.clear();//在其使用完时进行清空，以便下一次使用

	int minap;//获取最近车位在图中的输入次序
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//到此已选择出最近车位
	//存取出口到最近车位的路线
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//以小车当前位置为起点计算到出口的最近路线
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//存取小车到出口的最近路线
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//记录任务小车离开时的位置
	//1.小车从停靠区接到任务
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
	//2.小车从线路中接到任务
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
	//3.小车从充电区接到任务
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

	//任务小车去出口的过程
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
	//小车已经接收到需要停的车辆赶往最近车位的路上
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
				//表明需要充电 不可以接任务
				carVectA[awork].eleFlag = 1;
				//执行充电策略
				//状态改为停靠，寻找到充电区进行执行
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//表示需要停靠
				carVectA[awork].status = false;//表示可以接任务
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "停车完成" << endl;
	//	MessageBox::Show("停车任务完成");
	/////////////////////////////////////////////////////2.A区域停靠策略/////////////////////////////////////////////////////////////	
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
		//寻找最近的空闲停车点
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


		//清空临时排序v
		minParka.clear();
		//以最近停靠位为终点规划停靠路线
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

		//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
		if (carVectA[awork].stop == 0)
		{
			//说明电量足够可以接受任务，无需进行电量判断
			if (aParkRet == 1)
				aPark1[parkindex].status = false;
			if (aParkRet == 2)
				aPark2[parkindex].status = false;
			while (!carVectA[awork].s3.empty())
				carVectA[awork].s3.pop();
			//break;
		}
		else{
			//继续执行停靠策略
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			if (carVectA[awork].eleNum < 25)
			{
				//将s3清空
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//执行充电策略
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
		///小车去往停靠区的执行
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectA[awork].s3.size() != 0)
		{
			//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
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
			//在去停靠的途中执行电量判断
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			///	carVectA[i].eleNum = 100;
			if (carVectA[awork].eleNum < 25)
			{
				//将s3清空
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//执行充电策略
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
				//cout << carVectA[awork].index << "停靠还有" << carVectA[awork].s3.size() <<"步"<< endl;
			}
			else{
				carVectA[awork].position = carVectA[awork].s3.top().c_str();
				carVectA[awork].s3.pop();
				//cout << carVectA[awork].index << "停靠最后一步" << endl;
				if (aParkRet == 1){
					for (int b = 0; b < aParksize1; b++)
					{
						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//将s3清空
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								//执行充电策略
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
								//将s3清空
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								//执行充电策略
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
	/////////////A的充电策略////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (carVectA[awork].eleFlag == 1)
	{
		//判断从那一部分执行充电策略
		//停靠区
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
		//2.小车从线路中接到
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
		//寻找最近的空闲充电点
		for (int g = 0; g < aElesize; g++)
		{
			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
			{
				parkindex = g;
				aEle[g].status = true;
				break;
			}
		}
		//清空临时排序v
		minElea.clear();
		//以最近停靠位为终点规划停靠路线
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
		///小车去往充电区的执行
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
	///////////充电完毕/////////////////////////////////////////////
	/////////////////////////////////////
}

void aParkProCar6()
{
	int awork = 2;
	carVectA[awork].status = true;//将状态改为使用
	carVectA[awork].stop = 0;//如果在停靠的路上也将其利用去进行工作
	carVectA[awork].eleFlag = 0;//如果是正在充电的将充电标志改为否
	cout << "工作的小车下标是" << carVectA[awork].index << endl;
	//MessageBox::Show("工作小车的下标为:" + carVectA[workcar].index);
	vector<int> aminDist;
	//选择最近的车位
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
	//判断最近车位在哪个区域
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
	aminDist.clear();//在其使用完时进行清空，以便下一次使用

	int minap;//获取最近车位在图中的输入次序
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//到此已选择出最近车位
	//存取出口到最近车位的路线
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//以小车当前位置为起点计算到出口的最近路线
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//存取小车到出口的最近路线
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//记录任务小车离开时的位置
	//1.小车从停靠区接到任务
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
	//2.小车从线路中接到任务
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
	//3.小车从充电区接到任务
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

	//任务小车去出口的过程
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
	//小车已经接收到需要停的车辆赶往最近车位的路上
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
				//表明需要充电 不可以接任务
				carVectA[awork].eleFlag = 1;
				//执行充电策略
				//状态改为停靠，寻找到充电区进行执行
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//表示需要停靠
				carVectA[awork].status = false;//表示可以接任务
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "停车完成" << endl;
	//	MessageBox::Show("停车任务完成");
	/////////////////////////////////////////////////////2.A区域停靠策略/////////////////////////////////////////////////////////////	
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
		//寻找最近的空闲停车点
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


		//清空临时排序v
		minParka.clear();
		//以最近停靠位为终点规划停靠路线
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

		//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
		if (carVectA[awork].stop == 0)
		{
			//说明电量足够可以接受任务，无需进行电量判断
			if (aParkRet == 1)
				aPark1[parkindex].status = false;
			if (aParkRet == 2)
				aPark2[parkindex].status = false;
			while (!carVectA[awork].s3.empty())
				carVectA[awork].s3.pop();
			//break;
		}
		else{
			//继续执行停靠策略
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			if (carVectA[awork].eleNum < 25)
			{
				//将s3清空
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//执行充电策略
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
		///小车去往停靠区的执行
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectA[awork].s3.size() != 0)
		{
			//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
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
			//在去停靠的途中执行电量判断
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			///	carVectA[i].eleNum = 100;
			if (carVectA[awork].eleNum < 25)
			{
				//将s3清空
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//执行充电策略
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
				//cout << carVectA[awork].index << "停靠还有" << carVectA[awork].s3.size() <<"步"<< endl;
			}
			else{
				carVectA[awork].position = carVectA[awork].s3.top().c_str();
				carVectA[awork].s3.pop();
				//cout << carVectA[awork].index << "停靠最后一步" << endl;
				if (aParkRet == 1){
					for (int b = 0; b < aParksize1; b++)
					{
						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//将s3清空
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								//执行充电策略
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
								//将s3清空
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								//执行充电策略
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
	/////////////A的充电策略////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (carVectA[awork].eleFlag == 1)
	{
		//判断从那一部分执行充电策略
		//停靠区
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
		//2.小车从线路中接到
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
		//寻找最近的空闲充电点
		for (int g = 0; g < aElesize; g++)
		{
			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
			{
				parkindex = g;
				aEle[g].status = true;
				break;
			}
		}
		//清空临时排序v
		minElea.clear();
		//以最近停靠位为终点规划停靠路线
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
		///小车去往充电区的执行
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
	///////////充电完毕/////////////////////////////////////////////
	/////////////////////////////////////
}

void aParkProCar7()
{
	int awork = 3;
	carVectA[awork].status = true;//将状态改为使用
	carVectA[awork].stop = 0;//如果在停靠的路上也将其利用去进行工作
	carVectA[awork].eleFlag = 0;//如果是正在充电的将充电标志改为否
	cout << "工作的小车下标是" << carVectA[awork].index << endl;
	//MessageBox::Show("工作小车的下标为:" + carVectA[workcar].index);
	vector<int> aminDist;
	//选择最近的车位
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
	//判断最近车位在哪个区域
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
	aminDist.clear();//在其使用完时进行清空，以便下一次使用

	int minap;//获取最近车位在图中的输入次序
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//到此已选择出最近车位
	//存取出口到最近车位的路线
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//以小车当前位置为起点计算到出口的最近路线
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//存取小车到出口的最近路线
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//记录任务小车离开时的位置
	//1.小车从停靠区接到任务
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
	//2.小车从线路中接到任务
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
	//3.小车从充电区接到任务
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

	//任务小车去出口的过程
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
	//小车已经接收到需要停的车辆赶往最近车位的路上
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
				//表明需要充电 不可以接任务
				carVectA[awork].eleFlag = 1;
				//执行充电策略
				//状态改为停靠，寻找到充电区进行执行
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//表示需要停靠
				carVectA[awork].status = false;//表示可以接任务
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "停车完成" << endl;
	//	MessageBox::Show("停车任务完成");
	/////////////////////////////////////////////////////2.A区域停靠策略/////////////////////////////////////////////////////////////	
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
		//寻找最近的空闲停车点
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


		//清空临时排序v
		minParka.clear();
		//以最近停靠位为终点规划停靠路线
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

		//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
		if (carVectA[awork].stop == 0)
		{
			//说明电量足够可以接受任务，无需进行电量判断
			if (aParkRet == 1)
				aPark1[parkindex].status = false;
			if (aParkRet == 2)
				aPark2[parkindex].status = false;
			while (!carVectA[awork].s3.empty())
				carVectA[awork].s3.pop();
			//break;
		}
		else{
			//继续执行停靠策略
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			if (carVectA[awork].eleNum < 25)
			{
				//将s3清空
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//执行充电策略
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
		///小车去往停靠区的执行
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectA[awork].s3.size() != 0)
		{
			//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
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
			//在去停靠的途中执行电量判断
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			///	carVectA[i].eleNum = 100;
			if (carVectA[awork].eleNum < 25)
			{
				//将s3清空
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//执行充电策略
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
				//cout << carVectA[awork].index << "停靠还有" << carVectA[awork].s3.size() <<"步"<< endl;
			}
			else{
				carVectA[awork].position = carVectA[awork].s3.top().c_str();
				carVectA[awork].s3.pop();
				//cout << carVectA[awork].index << "停靠最后一步" << endl;
				if (aParkRet == 1){
					for (int b = 0; b < aParksize1; b++)
					{
						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//将s3清空
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								//执行充电策略
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
								//将s3清空
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								//执行充电策略
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
	/////////////A的充电策略////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (carVectA[awork].eleFlag == 1)
	{
		//判断从那一部分执行充电策略
		//停靠区
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
		//2.小车从线路中接到
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
		//寻找最近的空闲充电点
		for (int g = 0; g < aElesize; g++)
		{
			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
			{
				parkindex = g;
				aEle[g].status = true;
				break;
			}
		}
		//清空临时排序v
		minElea.clear();
		//以最近停靠位为终点规划停靠路线
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
		///小车去往充电区的执行
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
	///////////充电完毕/////////////////////////////////////////////
	/////////////////////////////////////
}

void aParkProCar8()
{
	int awork = 4;
	carVectA[awork].status = true;//将状态改为使用
	carVectA[awork].stop = 0;//如果在停靠的路上也将其利用去进行工作
	carVectA[awork].eleFlag = 0;//如果是正在充电的将充电标志改为否
	cout << "工作的小车下标是" << carVectA[awork].index << endl;
	//MessageBox::Show("工作小车的下标为:" + carVectA[workcar].index);
	vector<int> aminDist;
	//选择最近的车位
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
	//判断最近车位在哪个区域
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
	aminDist.clear();//在其使用完时进行清空，以便下一次使用

	int minap;//获取最近车位在图中的输入次序
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//到此已选择出最近车位
	//存取出口到最近车位的路线
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//以小车当前位置为起点计算到出口的最近路线
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//存取小车到出口的最近路线
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//记录任务小车离开时的位置
	//1.小车从停靠区接到任务
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
	//2.小车从线路中接到任务
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
	//3.小车从充电区接到任务
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

	//任务小车去出口的过程
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
	//小车已经接收到需要停的车辆赶往最近车位的路上
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
				//表明需要充电 不可以接任务
				carVectA[awork].eleFlag = 1;
				//执行充电策略
				//状态改为停靠，寻找到充电区进行执行
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//表示需要停靠
				carVectA[awork].status = false;//表示可以接任务
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "停车完成" << endl;
	//	MessageBox::Show("停车任务完成");
	/////////////////////////////////////////////////////2.A区域停靠策略/////////////////////////////////////////////////////////////	
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
		//寻找最近的空闲停车点
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


		//清空临时排序v
		minParka.clear();
		//以最近停靠位为终点规划停靠路线
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

		//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
		if (carVectA[awork].stop == 0)
		{
			//说明电量足够可以接受任务，无需进行电量判断
			if (aParkRet == 1)
				aPark1[parkindex].status = false;
			if (aParkRet == 2)
				aPark2[parkindex].status = false;
			while (!carVectA[awork].s3.empty())
				carVectA[awork].s3.pop();
			//break;
		}
		else{
			//继续执行停靠策略
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			if (carVectA[awork].eleNum < 25)
			{
				//将s3清空
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//执行充电策略
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
		///小车去往停靠区的执行
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectA[awork].s3.size() != 0)
		{
			//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
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
			//在去停靠的途中执行电量判断
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			///	carVectA[i].eleNum = 100;
			if (carVectA[awork].eleNum < 25)
			{
				//将s3清空
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//执行充电策略
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
				//cout << carVectA[awork].index << "停靠还有" << carVectA[awork].s3.size() <<"步"<< endl;
			}
			else{
				carVectA[awork].position = carVectA[awork].s3.top().c_str();
				carVectA[awork].s3.pop();
				//cout << carVectA[awork].index << "停靠最后一步" << endl;
				if (aParkRet == 1){
					for (int b = 0; b < aParksize1; b++)
					{
						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//将s3清空
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								//执行充电策略
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
								//将s3清空
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								//执行充电策略
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
	/////////////A的充电策略////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (carVectA[awork].eleFlag == 1)
	{
		//判断从那一部分执行充电策略
		//停靠区
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
		//2.小车从线路中接到
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
		//寻找最近的空闲充电点
		for (int g = 0; g < aElesize; g++)
		{
			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
			{
				parkindex = g;
				aEle[g].status = true;
				break;
			}
		}
		//清空临时排序v
		minElea.clear();
		//以最近停靠位为终点规划停靠路线
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
		///小车去往充电区的执行
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
	///////////充电完毕/////////////////////////////////////////////
	/////////////////////////////////////
}

void aParkProCar9()
{
	int awork = 5;
	carVectA[awork].status = true;//将状态改为使用
	carVectA[awork].stop = 0;//如果在停靠的路上也将其利用去进行工作
	carVectA[awork].eleFlag = 0;//如果是正在充电的将充电标志改为否
	cout << "工作的小车下标是" << carVectA[awork].index << endl;
	//MessageBox::Show("工作小车的下标为:" + carVectA[workcar].index);
	vector<int> aminDist;
	//选择最近的车位
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
	//判断最近车位在哪个区域
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
	aminDist.clear();//在其使用完时进行清空，以便下一次使用

	int minap;//获取最近车位在图中的输入次序
	if (minIndex == 1){
		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
	}
	else if (minIndex == 2){
		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
	}
	//到此已选择出最近车位
	//存取出口到最近车位的路线
	while (!carVectA[awork].s1.empty())
		carVectA[awork].s1.pop();
	carVectA[awork].s1.push(parkingA.Print(minap).index0);
	for (int j = path7[minap]; j != startA; j = path7[j])
		carVectA[awork].s1.push(parkingA.Print(j).index0);

	//以小车当前位置为起点计算到出口的最近路线
	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
	int *dist8 = new int[verNumA];
	int *path8 = new int[verNumA];
	parkingA.dijkstra(leaveA, dist8, path8);

	//存取小车到出口的最近路线
	while (!carVectA[awork].s2.empty())
		carVectA[awork].s2.pop();
	carVectA[awork].s2.push(parkingA.Print(startA).index0);
	for (int j = path8[startA]; j != leaveA; j = path8[j])
		carVectA[awork].s2.push(parkingA.Print(j).index0);


	//记录任务小车离开时的位置
	//1.小车从停靠区接到任务
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
	//2.小车从线路中接到任务
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
	//3.小车从充电区接到任务
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

	//任务小车去出口的过程
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
	//小车已经接收到需要停的车辆赶往最近车位的路上
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
				//表明需要充电 不可以接任务
				carVectA[awork].eleFlag = 1;
				//执行充电策略
				//状态改为停靠，寻找到充电区进行执行
				carVectA[awork].eleStatus = 0;
				carVectA[awork].start = clock();
			}
			else{
				carVectA[awork].stop = 1;//表示需要停靠
				carVectA[awork].status = false;//表示可以接任务
				carVectA[awork].start = clock();
			}
			////cout << carVectB[workcar].position << endl;
			m.show();
		}
	}
	//cout << carVectA[awork].index << "停车完成" << endl;
	//	MessageBox::Show("停车任务完成");
	/////////////////////////////////////////////////////2.A区域停靠策略/////////////////////////////////////////////////////////////	
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
		//寻找最近的空闲停车点
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


		//清空临时排序v
		minParka.clear();
		//以最近停靠位为终点规划停靠路线
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

		//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
		if (carVectA[awork].stop == 0)
		{
			//说明电量足够可以接受任务，无需进行电量判断
			if (aParkRet == 1)
				aPark1[parkindex].status = false;
			if (aParkRet == 2)
				aPark2[parkindex].status = false;
			while (!carVectA[awork].s3.empty())
				carVectA[awork].s3.pop();
			//break;
		}
		else{
			//继续执行停靠策略
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			if (carVectA[awork].eleNum < 25)
			{
				//将s3清空
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//执行充电策略
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
		///小车去往停靠区的执行
		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
		while (carVectA[awork].s3.size() != 0)
		{
			//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
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
			//在去停靠的途中执行电量判断
			carVectA[awork].end = clock();
			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
			///	carVectA[i].eleNum = 100;
			if (carVectA[awork].eleNum < 25)
			{
				//将s3清空
				while (!carVectA[awork].s3.empty())
					carVectA[awork].s3.pop();
				//执行充电策略
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
				//cout << carVectA[awork].index << "停靠还有" << carVectA[awork].s3.size() <<"步"<< endl;
			}
			else{
				carVectA[awork].position = carVectA[awork].s3.top().c_str();
				carVectA[awork].s3.pop();
				//cout << carVectA[awork].index << "停靠最后一步" << endl;
				if (aParkRet == 1){
					for (int b = 0; b < aParksize1; b++)
					{
						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
						{
							carVectA[awork].end = clock();
							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
							if (carVectA[awork].eleNum < 25)
							{
								//将s3清空
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								if (aParkRet == 1)
									aPark1[parkindex].status = false;
								if (aParkRet == 2)
									aPark2[parkindex].status = false;
								//执行充电策略
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
								//将s3清空
								while (!carVectA[awork].s3.empty())
									carVectA[awork].s3.pop();
								//执行充电策略
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
	/////////////A的充电策略////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (carVectA[awork].eleFlag == 1)
	{
		//判断从那一部分执行充电策略
		//停靠区
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
		//2.小车从线路中接到
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
		//寻找最近的空闲充电点
		for (int g = 0; g < aElesize; g++)
		{
			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
			{
				parkindex = g;
				aEle[g].status = true;
				break;
			}
		}
		//清空临时排序v
		minElea.clear();
		//以最近停靠位为终点规划停靠路线
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
		///小车去往充电区的执行
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
	///////////充电完毕/////////////////////////////////////////////
	/////////////////////////////////////
}

//void aParkProCar5()
//{
//	int awork = 1;
//	carVectA[awork].status = true;//将状态改为使用
//	carVectA[awork].stop = 0;//如果在停靠的路上也将其利用去进行工作
//	carVectA[awork].eleFlag = 0;//如果是正在充电的将充电标志改为否
//	cout << "工作的小车下标是" << carVectA[awork].index << endl;
//	//MessageBox::Show("工作小车的下标为:" + carVectA[workcar].index);
//	vector<int> aminDist;
//	//选择最近的车位
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
//	//判断最近车位在哪个区域
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
//	aminDist.clear();//在其使用完时进行清空，以便下一次使用
//
//	int minap;//获取最近车位在图中的输入次序
//	if (minIndex == 1){
//		minap = parkingA.strgetIndex0(aSpace[carVectA[awork].carindex].index0.c_str());
//	}
//	else if (minIndex == 2){
//		minap = parkingA.strgetIndex0(cSpace[carVectA[awork].carindex].index0.c_str());
//	}
//	//到此已选择出最近车位
//	//存取出口到最近车位的路线
//	while (!carVectA[awork].s1.empty())
//		carVectA[awork].s1.pop();
//	carVectA[awork].s1.push(parkingA.Print(minap).index0);
//	for (int j = path7[minap]; j != startA; j = path7[j])
//		carVectA[awork].s1.push(parkingA.Print(j).index0);
//
//	//以小车当前位置为起点计算到出口的最近路线
//	int leaveA = parkingA.strgetIndex0(carVectA[awork].position.c_str());
//	int *dist8 = new int[verNumA];
//	int *path8 = new int[verNumA];
//	parkingA.dijkstra(leaveA, dist8, path8);
//
//	//存取小车到出口的最近路线
//	while (!carVectA[awork].s2.empty())
//		carVectA[awork].s2.pop();
//	carVectA[awork].s2.push(parkingA.Print(startA).index0);
//	for (int j = path8[startA]; j != leaveA; j = path8[j])
//		carVectA[awork].s2.push(parkingA.Print(j).index0);
//
//
//	//记录任务小车离开时的位置
//	//1.小车从停靠区接到任务
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
//	//2.小车从线路中接到任务
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
//	//3.小车从充电区接到任务
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
//	//任务小车去出口的过程
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
//	//小车已经接收到需要停的车辆赶往最近车位的路上
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
//				//表明需要充电 不可以接任务
//				carVectA[awork].eleFlag = 1;
//				//执行充电策略
//				//状态改为停靠，寻找到充电区进行执行
//				carVectA[awork].eleStatus = 0;
//				carVectA[awork].start = clock();
//			}
//			else{
//				carVectA[awork].stop = 1;//表示需要停靠
//				carVectA[awork].status = false;//表示可以接任务
//				carVectA[awork].start = clock();
//			}
//			////cout << carVectB[workcar].position << endl;
//			/////m.show();
//		}
//	}
//	cout << carVectA[awork].index << "停车完成" << endl;
//	//	MessageBox::Show("停车任务完成");
//	/////////////////////////////////////////////////////2.A区域停靠策略/////////////////////////////////////////////////////////////	
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
//		//寻找最近的空闲停车点
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
//		//清空临时排序v
//		minParka.clear();
//		//以最近停靠位为终点规划停靠路线
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
//		//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
//		if (carVectA[awork].stop == 0)
//		{
//			//说明电量足够可以接受任务，无需进行电量判断
//			if (aParkRet == 1)
//				aPark1[parkindex].status = false;
//			if (aParkRet == 2)
//				aPark2[parkindex].status = false;
//			while (!carVectA[awork].s3.empty())
//				carVectA[awork].s3.pop();
//			//break;
//		}
//		else{
//			//继续执行停靠策略
//			carVectA[awork].end = clock();
//			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
//			if (carVectA[awork].eleNum < 25)
//			{
//				//将s3清空
//				while (!carVectA[awork].s3.empty())
//					carVectA[awork].s3.pop();
//				//执行充电策略
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
//		///小车去往停靠区的执行
//		//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
//		while (carVectA[awork].s3.size() != 0)
//		{
//			//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
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
//			//在去停靠的途中执行电量判断
//			carVectA[awork].end = clock();
//			carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
//			///	carVectA[i].eleNum = 100;
//			if (carVectA[awork].eleNum < 25)
//			{
//				//将s3清空
//				while (!carVectA[awork].s3.empty())
//					carVectA[awork].s3.pop();
//				//执行充电策略
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
//				cout << carVectA[awork].index << "停靠最后一步" << endl;
//				if (aParkRet == 1){
//					for (int b = 0; b < aParksize1; b++)
//					{
//						if (strcmp(aPark1[b].index0.c_str(), carVectA[awork].position.c_str()) == 0)
//						{
//							carVectA[awork].end = clock();
//							carVectA[awork].eleNum = carVectA[awork].calEle(carVectA[awork].eleNum, carVectA[awork].eleStatus, carVectA[awork].start, carVectA[awork].end);
//							if (carVectA[awork].eleNum < 25)
//							{
//								//将s3清空
//								while (!carVectA[awork].s3.empty())
//									carVectA[awork].s3.pop();
//								if (aParkRet == 1)
//									aPark1[parkindex].status = false;
//								if (aParkRet == 2)
//									aPark2[parkindex].status = false;
//								//执行充电策略
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
//								//将s3清空
//								while (!carVectA[awork].s3.empty())
//									carVectA[awork].s3.pop();
//								//执行充电策略
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
//	/////////////A的充电策略////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	if (carVectA[awork].eleFlag == 1)
//	{
//		//判断从那一部分执行充电策略
//		//停靠区
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
//		//2.小车从线路中接到
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
//		//寻找最近的空闲充电点
//		for (int g = 0; g < aElesize; g++)
//		{
//			if (aEle[g].ele_Distance == minElea[0] && aEle[g].status == false)
//			{
//				parkindex = g;
//				aEle[g].status = true;
//				break;
//			}
//		}
//		//清空临时排序v
//		minElea.clear();
//		//以最近停靠位为终点规划停靠路线
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
//		///小车去往充电区的执行
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
//	///////////充电完毕/////////////////////////////////////////////
//	/////////////////////////////////////
//}


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
		}
		else{
			cout << "接收消息结束！" << endl;
			break;
		}
		//发送数据给客户端
		//	char sendData[1024];

		if (strcmp(revData, "删除用户信息") == 0){
			Application::EnableVisualStyles();
			Application::Run(gcnew deletebaseForm());
			send(*ClientSocket, "删除用户信息需求已经处理\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "插入用户信息") == 0)){
			Application::EnableVisualStyles();
			Application::Run(gcnew insertDataBaseForm());
			send(*ClientSocket, "插入用户信息需求已处理\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "修改用户信息") == 0)){
			Application::EnableVisualStyles();
			Application::Run(gcnew modiftyDataForm());
			send(*ClientSocket, "修改用户信息需求已处理\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "查询车位状态") == 0)){
			int free = 0; int busy = 0;
			free = m.findParkingSpaceStatusFree();
			busy = m.findParkingSpaceStatusBusy();
			showSpaceStatusForm showSpace;
			showSpace.find(free, busy);
			showSpace.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "查询车位状态需求已处理\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "查询便道状态") == 0))
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
			send(*ClientSocket, "查询便道状态需求已处理\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "查询小车状态") == 0))
		{
			showCarStatusForm showcarstatus;
			showcarstatus.find();
			showcarstatus.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			send(*ClientSocket, "查询小车状态需求已处理\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "查询小车位置") == 0))
		{
			Application::EnableVisualStyles();
			Application::Run(gcnew showCarRoteForm());
			send(*ClientSocket, "查询小车位置需求已被处理\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "停车") == 0)
		{
			send(*ClientSocket, "用户停车需求正在执行\n", sizeof(sendData), 0);
			parkForm p;
			p.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			//对A停车场进行评估
			for (int i = 0; i < aSpacesize; i++){
				if (aSpace[i].status == false)
					aFree++;
			}
			//对B停车场进行评估
			for (int i = 0; i < bSpacesize; i++){
				if (bSpace[i].status == false)
					bFree++;
			}
			//对共用车位进行评估
			for (int i = 0; i < cSpacesize; i++){
				if (cSpace[i].status == false)
					cFree++;
			}
			aNum = aFree + cFree; bNum = bFree + cFree;
			if (location <= 50){
				if (aNum != 0){
					MessageBox::Show("你距离A停车场近请去A停车场停车");
					chooseRet = 1;
				}
				else if (bNum != 0){
					MessageBox::Show("你距离B停车场近请去B停车场停车");
					chooseRet = 2;
				}
				else{
					MessageBox::Show("对不起，停车场已经没有空余车位");
					chooseRet = 0;
				}
			}
			else{
				if (bNum != 0){
					MessageBox::Show("你距离B停车场近请去B停车场停车");
					chooseRet = 2;
				}
				else if (aNum != 0){
					MessageBox::Show("你距离A停车场近请去A停车场停车");
					chooseRet = 1;
				}
				else{
					MessageBox::Show("对不起，停车场已经没有空余车位");
					chooseRet = 0;
				}
			}
			//在A停车场停车
			if (chooseRet == 1){
				//选择空闲的空闲小车
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
			//A停车场停车完毕

			//B停车开始
			if (chooseRet == 2)
			{
				//选择空闲的空闲小车
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
				//MessageBox::Show("停车任务完成");		
			}
			////////////////////////////
			//B停车结束
			//停车结束	
		}
		else if (strcmp(revData, "取车") == 0)
		{
			send(*ClientSocket, "用户取车需求正在执行\n", sizeof(sendData), 0);
			sendForm s;
			s.Show();
			Application::EnableVisualStyles();
			Application::Run(gcnew functEndForm());
			//A取车开始/////////////////////////////////////
			if (location == 1)
			{
				MessageBox::Show("系统正在为您在A停车区取车");
				//判断哪个车位存取该车牌的车
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

				//以取车车位位置为起始点选择最近的工作车位 
				int retA = parkingA.strgetIndex0(taskSpace.index0.c_str());
				int *dist9 = new int[verNumA];
				int *path9 = new int[verNumA];
				parkingA.dijkstra(retA, dist9, path9);

				//选择工作小车
				//在此未进行电量判断因为状态为false说明电量足够
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

				//记录任务小车离开时的位置
				//1.小车从停靠区接到任务
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
				//2.小车从线路中接到任务
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
				//3.小车从充电区接到任务
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
				carVectA[workcar].stop = 0;//如果在停靠的路上也将其利用去进行工作
				cout << "工作的小车下标是" << carVectA[workcar].index << endl;


				while (!carVectA[workcar].s4.empty())
					carVectA[workcar].s4.pop();
				int pickA = parkingA.strgetIndex0(carVectA[workcar].position.c_str());
				int *dist10 = new int[verNumA];
				int *path10 = new int[verNumA];
				parkingA.dijkstra(pickA, dist10, path10);
				//存取小车到车牌车位的路线
				//carVectB[workcar].s4.push(parkingB.Print(min).index0);
				for (int j = path10[min]; j != pickA; j = path10[j])
					carVectA[workcar].s4.push(parkingA.Print(j).index0);



				//任务小车去车位的执行
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
				//如果小车直接进行取车的话需要特殊的处理如下
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


				//进行取车
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

				/////取车后送车到出口
				int arriveA = parkingA.strgetIndex0(carVectA[workcar].position.c_str());
				int *dist11 = new int[verNumA];
				int *path11 = new int[verNumA];
				parkingA.dijkstra(arriveA, dist11, path11);
				//存取小车到出口的最近路线
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
							//表明需要充电 不可以接任务
							carVectA[workcar].eleFlag = 1;
							//执行充电策略
							//状态改为停靠，寻找到充电区进行执行
							carVectA[workcar].eleStatus = 0;
							carVectA[workcar].start = clock();
							carVectA[workcar].status = true;

						}
						else{
							carVectA[workcar].stop = 1;//表示需要停靠
							carVectA[workcar].status = false;//表示可以接任务
							carVectA[workcar].start = clock();
						}
						m.show();
					}
				}
				/////////////////////////////////////////////////////2.A区域停靠策略/////////////////////////////////////////////////////////////	
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
						//寻找最近的空闲停车点
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


						//清空临时排序v
						minPark.clear();
						//以最近停靠位为终点规划停靠路线
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

						//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
						if (carVectA[i].stop == 0)
						{
							//说明电量足够可以接受任务，无需进行电量判断
							if (aParkRet == 1)
								aPark1[parkindex].status = false;
							if (aParkRet == 2)
								aPark2[parkindex].status = false;
							while (!carVectA[i].s3.empty())
								carVectA[i].s3.pop();
							break;
						}
						else{
							//继续执行停靠策略
							carVectA[i].end = clock();
							carVectA[i].eleNum = carVectA[i].calEle(carVectA[i].eleNum, carVectA[i].eleStatus, carVectA[i].start, carVectA[i].end);
							if (carVectA[i].eleNum < 25)
							{
								//将s3清空
								while (!carVectA[i].s3.empty())
									carVectA[i].s3.pop();
								//执行充电策略
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
						///小车去往停靠区的执行
						//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
						while (carVectA[i].s3.size() != 0)
						{
							//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
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
							//在去停靠的途中执行电量判断
							carVectA[i].end = clock();
							carVectA[i].eleNum = carVectA[i].calEle(carVectA[i].eleNum, carVectA[i].eleStatus, carVectA[i].start, carVectA[i].end);
							///	carVectA[i].eleNum = 100;
							if (carVectA[i].eleNum < 25)
							{
								//将s3清空
								while (!carVectA[i].s3.empty())
									carVectA[i].s3.pop();
								//执行充电策略
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
										cout << "停靠点位" << "---" << carVectA[i].position << endl;
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
												//将s3清空
												while (!carVectA[i].s3.empty())
													carVectA[i].s3.pop();
												//执行充电策略
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
												//将s3清空
												while (!carVectA[i].s3.empty())
													carVectA[i].s3.pop();
												//执行充电策略
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
				/////////////A的充电策略////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				for (int i = 0; i < caraSize; i++)
				{
					if (carVectA[i].eleFlag == 1)
					{
						//判断从那一部分执行充电策略
						//停靠区
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
						//2.小车从线路中接到
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
						//寻找最近的空闲充电点
						for (int g = 0; g < aElesize; g++)
						{
							if (aEle[g].ele_Distance == minPark[0] && aEle[g].status == false)
							{
								parkindex = g;
								aEle[g].status = true;
								break;
							}
						}
						//清空临时排序v
						minPark.clear();
						//以最近停靠位为终点规划停靠路线
						min = parkingA.strgetIndex0(aEle[parkindex].index0.c_str());
						////cout << aEle[parkindex].index0 << endl;
						while (!carVectA[i].s6.empty())
							carVectA[i].s6.pop();
						carVectA[i].s6.push(aEle[parkindex].index0.c_str());
						for (int j = path12[min]; j != eleA; j = path12[j])
							carVectA[i].s6.push(parkingA.Print(j).index0.c_str());


						carVectA[i].start = clock();
						carVectA[i].eleStatus = 2;
						///小车去往充电区的执行
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
				///////////充电完毕/////////////////////////////////////////////

			}
			//B取车开始/////////////////////////////////////////
			if (location == 2)
			{
				MessageBox::Show("系统正在为您在B停车区取车");
				//判断哪个车位存取该车牌的车
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

				//以取车车位位置为起始点选择最近的工作车位 
				int ret = parkingB.strgetIndex0(taskSpace.index0.c_str());
				int *dist5 = new int[verNum];
				int *path5 = new int[verNum];
				parkingB.dijkstra(ret, dist5, path5);

				//选择工作小车
				//在此未进行电量判断因为状态为false说明电量足够
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
				//1.小车从停靠区接到任务
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
				//2.小车从线路中接到任务
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
				//3.小车从充电区接到任务
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
				carVectB[workcar].stop = 0;//如果在停靠的路上也将其利用去进行工作
				cout << "工作的小车下标是" << carVectB[workcar].index << endl;


				while (!carVectB[workcar].s4.empty())
					carVectB[workcar].s4.pop();
				int pick = parkingB.strgetIndex0(carVectB[workcar].position.c_str());
				int *dist3 = new int[verNum];
				int *path3 = new int[verNum];
				parkingB.dijkstra(pick, dist3, path3);
				//存取小车到车牌车位的路线
				//carVectB[workcar].s4.push(parkingB.Print(min).index0);
				for (int j = path3[min]; j != pick; j = path3[j])
					carVectB[workcar].s4.push(parkingB.Print(j).index0);



				//任务小车去车位的执行
				carVectB[workcar].eleStatus = 1;
				carVectB[workcar].start = clock();
				while (carVectB[workcar].s4.size() != 0)
				{
					if (leaveStat == 0)
						carVectB[workcar].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
					////cout << "1哈哈哈哈哈" << endl;
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
				//如果小车直接进行取车的话需要特殊的处理如下
				if (leaveStat == 0)
					carVectB[workcar].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
				if (leaveStat == 1)
					carVectB[workcar].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
				if (leaveStat == 2)
					carVectB[workcar].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);


				//进行取车
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

				/////取车后送车到出口
				int arrive = parkingB.strgetIndex0(carVectB[workcar].position.c_str());
				int *dist4 = new int[verNum];
				int *path4 = new int[verNum];
				parkingB.dijkstra(arrive, dist4, path4);
				//存取小车到出口的最近路线
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
							//表明需要充电 不可以接任务
							carVectB[workcar].eleFlag = 1;
							//执行充电策略
							//状态改为停靠，寻找到充电区进行执行
							carVectB[workcar].eleStatus = 0;
							carVectB[workcar].start = clock();
							carVectB[workcar].status = true;

						}
						else{
							carVectB[workcar].stop = 1;//表示需要停靠
							carVectB[workcar].status = false;//表示可以接任务
							carVectB[workcar].start = clock();
						}
						m.show();
						cout << "取车完成" << endl;
					}
				}

				//B停靠///////////////////////////////////////////////////////////////////////////////
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
						//寻找最近的空闲停车点
						for (int g = 0; g < bParksize; g++)
						{
							if (bPark[g].distance_B == minPark[0] && bPark[g].status == false)
							{
								parkindex = g;
								bPark[g].status = true;
								break;
							}

						}
						//清空临时排序v
						minPark.clear();
						//以最近停靠位为终点规划停靠路线
						min = parkingB.strgetIndex0(bPark[parkindex].index0.c_str());
						carVectB[i].s3.push(bPark[parkindex].index0.c_str());
						for (int j = path2[min]; j != park; j = path2[j])
							carVectB[i].s3.push(parkingB.Print(j).index0.c_str());

						//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
						if (carVectB[i].stop == 0)
						{
							//说明电量足够可以接受任务，无需进行电量判断
							bPark[parkindex].status = false;
							while (!carVectB[i].s3.empty())
								carVectB[i].s3.pop();
							break;
						}
						else{
							//继续执行停靠策略
							carVectB[i].end = clock();
							carVectB[i].eleNum = carVectB[i].calEle(carVectB[i].eleNum, carVectB[i].eleStatus, carVectB[i].start, carVectB[i].end);
							if (carVectB[i].eleNum < 25)
							{
								//将s3清空
								while (!carVectB[i].s3.empty())
									carVectB[i].s3.pop();
								//执行充电策略
								bPark[parkindex].status = false;
								carVectB[i].eleFlag = 1;
								carVectB[i].status = true;
								carVectB[i].start = clock();
								break;
							}
						}

						carVectB[i].start = clock();
						carVectB[i].eleStatus = 1;
						///小车去往停靠区的执行
						//while (carVectB[workcar].s3.size() != 0 && (parkstop == false))
						while (carVectB[i].s3.size() != 0)
						{
							//如果需要停靠小车又要工作能将最近停靠车位改回空闲状态并跳出
							if (carVectB[i].stop == 0)
							{
								bPark[parkindex].status = false;
								while (!carVectB[i].s3.empty())
									carVectB[i].s3.pop();
								break;
							}
							//在去停靠的途中执行电量判断
							carVectB[i].end = clock();
							carVectB[i].eleNum = carVectB[i].calEle(carVectB[i].eleNum, carVectB[i].eleStatus, carVectB[i].start, carVectB[i].end);
							if (carVectB[i].eleNum < 25)
							{
								//将s3清空
								while (!carVectB[i].s3.empty())
									carVectB[i].s3.pop();
								//执行充电策略
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
										cout << "停靠点位" << "---" << carVectB[i].position << endl;
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
								cout << "停靠点位" << "---" << carVectB[i].position << endl;
								carVectB[i].s3.pop();
								for (int b = 0; b < bParksize; b++)
								{
									if (strcmp(bPark[b].index0.c_str(), carVectB[i].position.c_str()) == 0)
									{

										carVectB[i].end = clock();
										carVectB[i].eleNum = carVectB[i].calEle(carVectB[i].eleNum, carVectB[i].eleStatus, carVectB[i].start, carVectB[i].end);
										if (carVectB[i].eleNum < 25)
										{
											//将s3清空
											while (!carVectB[i].s3.empty())
												carVectB[i].s3.pop();
											//执行充电策略
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
				////B充电////////////////////
				for (int i = 0; i < carbSize; i++)
				{
					if (carVectB[i].eleFlag == 1)
					{
						//判断从那一部分执行充电策略
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
						//2.小车从线路中接到
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
						//寻找最近的空闲充电点
						for (int g = 0; g < bElesize; g++)
						{
							if (bEle[g].ele_Distance == minPark[0] && bEle[g].status == false)
							{
								parkindex = g;
								bEle[g].status = true;
								break;
							}
						}
						//清空临时排序v
						minPark.clear();
						//以最近停靠位为终点规划停靠路线
						min = parkingB.strgetIndex0(bEle[parkindex].index0.c_str());
						while (!carVectB[i].s6.empty())
							carVectB[i].s6.pop();
						carVectB[i].s6.push(bEle[parkindex].index0.c_str());
						for (int j = path6[min]; j != ele; j = path6[j])
							carVectB[i].s6.push(parkingB.Print(j).index0.c_str());


						carVectB[i].start = clock();
						carVectB[i].eleStatus = 2;
						///小车去往充电区的执行
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
										cout << "停靠点位" << "---" << carVectB[i].position << endl;
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
								cout << "充电点位" << "---" << carVectB[i].position << endl;
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
						cout << "充电结束" << endl;
						cout << "充电点位" << "---" << carVectB[i].position << endl;
					}
				}
				////////////////////////////
			}

		}
		else if ((strcmp(revData, "查询数据库") == 0)){
			sql.QueryDatabase1();
			send(*ClientSocket, "查询数据库需求已处理\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "展示停车场") == 0)){
			send(*ClientSocket, "展示停车场需求已处理\n", sizeof(sendData), 0);
			m.show();
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

