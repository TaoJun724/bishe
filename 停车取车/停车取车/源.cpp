#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARINGS
#include<stdio.h>
#include<queue>
#include<winsock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include<string>
#include <string.h>
#include<algorithm>
#include"Comm.hpp"
#include "amgraph.h"
#include"parkingMember.hpp"
#include"parkingOperator.hpp"
using namespace std;
using namespace itlab;
#pragma comment(lib,"ws2_32.lib")
#define BOUNDS_CHECK
const int PORT = 8000;
#include"coord.hpp"
#include"parkingIsFree.hpp"

int main()
{
//  ����Ա��
	Manage m;
	m.initParking();
//	m.show();
//
	
//  ͼ�Ĺ���
	Coord coord;
	AMGraph<char, int> parkingA;
	AMGraph<char, int> parkingB;
	coord.InitParkingAPoint(parkingA);
	coord.InitParkingAEdge(parkingA);
	coord.InitParkingBPoint(parkingB);
	coord.InitParkingBEdge(parkingB);



	coord.Line(lineVect);
	coord.Ele(eleVect);
	coord.Berth(berVect);

	coord.LineB(bLine);
////////////////////////////////

	int verNum = parkingB.getVertexNumber(), startB = parkingB.getIndex(R57),
		*dist = new int[verNum],
		*path = new int[verNum];
	parkingB.dijkstra(startB, dist, path);

	int c71 = dist[parkingB.strgetIndex("C71")]; C71.distance = c71;
	int c72 = dist[parkingB.strgetIndex("C72")]; C72.distance = c72;
	int c73 = dist[parkingB.strgetIndex("C73")]; C73.distance = c73;
	int c74 = dist[parkingB.strgetIndex("C74")]; C74.distance = c74;
	int c75 = dist[parkingB.strgetIndex("C75")]; C75.distance = c75;
	int c76 = dist[parkingB.strgetIndex("C76")]; C76.distance = c76;
	int c77 = dist[parkingB.strgetIndex("C77")]; C77.distance = c77;
	int c78 = dist[parkingB.strgetIndex("C78")]; C78.distance = c78;
	int c79 = dist[parkingB.strgetIndex("C79")]; C79.distance = c79;
	int c80 = dist[parkingB.strgetIndex("C80")]; C80.distance = c80;
	int c81 = dist[parkingB.strgetIndex("C81")]; C81.distance = c81;
	int c82 = dist[parkingB.strgetIndex("C82")]; C82.distance = c82;
	int c83 = dist[parkingB.strgetIndex("C83")]; C83.distance = c83;
	int c84 = dist[parkingB.strgetIndex("C84")]; C84.distance = c84;

	int c37 = dist[parkingB.strgetIndex("C37")]; C37.distance = c37;
	int c38 = dist[parkingB.strgetIndex("C38")]; C38.distance = c38;
	int c39 = dist[parkingB.strgetIndex("C39")]; C39.distance = c39;
	int c40 = dist[parkingB.strgetIndex("C40")]; C40.distance = c40;
	int c41 = dist[parkingB.strgetIndex("C41")]; C41.distance = c41;
	int c42 = dist[parkingB.strgetIndex("C42")]; C42.distance = c42;
	int c43 = dist[parkingB.strgetIndex("C43")]; C43.distance = c43;
	int c44 = dist[parkingB.strgetIndex("C44")]; C44.distance = c44;
	int c45 = dist[parkingB.strgetIndex("C45")]; C45.distance = c45;
	int c46 = dist[parkingB.strgetIndex("C46")]; C46.distance = c46;
	int c47 = dist[parkingB.strgetIndex("C47")]; C47.distance = c47;
	int c48 = dist[parkingB.strgetIndex("C48")]; C48.distance = c48;
	int c49 = dist[parkingB.strgetIndex("C49")]; C49.distance = c49;
	int c50 = dist[parkingB.strgetIndex("C50")]; C50.distance = c50;
	int c51 = dist[parkingB.strgetIndex("C51")]; C51.distance = c51;
	int c52 = dist[parkingB.strgetIndex("C52")]; C52.distance = c52;
////////////////////////////////
	coord.Space(spaceVect);
	coord.SpaceA(spaceA);
	coord.SpaceB(spaceB);
	coord.SpaceC(spaceC);

	//for (int i = 0; i < spaceA.size(); i++)
	//{
	//	cout << spaceA[i].index << "--" << spaceA[i].x << "--" << spaceA[i].y << "--" << spaceA[i].length << "--" << spaceA[i].wide << endl;
	//}

	/*for (int i = 0; i < spaceC.size(); i++)
	{
		cout << spaceC[i].index << "--" << spaceC[i].x << "--" << spaceC[i].y << "--" << spaceC[i].length << "--" << spaceC[i].wide << endl;
	}
    */

	
//

//�ж�ͣ�����Ƿ��г�λ
	IsFree isFree;
	int A = isFree.IsFreeA();
	int B = isFree.IsFreeB();
	isFree.freeInt();

	int x;
	cout << "�����������ڵص�" << endl;
	cin >> x;
	int choose;
	if (x <= 50)
	{
		if (A != 0)
		{
			cout << "��ȥAͣ����ͣ��" << endl;
			choose = 1;
		}		
		else if (B != 0)
		{
			cout << "��ȥBͣ����ͣ��" << endl;
			choose = 2;
		}			
		else
		{
			cout << "ͣ����û�п��೵λ" << endl;
			choose = 0;
		}
	}
	else{
		if (B != 0)
		{
			cout << "��ȥBͣ����ͣ��" << endl;
			choose = 2;
		}		
		else if (A != 0)
		{
			cout << "��ȥAͣ����ͣ��" << endl;
			choose = 1;
		}		
		else
		{
			cout << "ͣ����û�п��೵λ" << endl;
			choose = 0;
		}		
	}

	//	cout << choose << endl;



////////////////////////////////////////////////////
	
////////////////////////////////////////////////////////////////////////////////
	agvCar car1;
	car1.index = 1; car1.eleNum = 100; car1.position = "T12"; car1.status = false;
	agvCar car2;
	car2.index = 2; car2.eleNum = 100; car2.position = "T13"; car2.status = false;

	vector<agvCar> carVectB;
	carVectB.push_back(car1); carVectB.push_back(car2);
//////////////////////////////////////////////////////////////////////////////
	string license;
	vector<int> ss;//����Ѱ������ĳ�λ
	int spaceBsize = spaceB.size();
	int spaceAsize = spaceA.size();
	int spaceCsize = spaceC.size();
	int indexmin = 0;
	int task;
	if (choose == 2)
	{
		cout << "��ѡ��ͣ��/ȡ������" << endl;
		cin >> task;
		if (task == 1){
			cout << "ͣ������" << endl;			
			cout << "��������ĳ��ƺ�" << endl;
			cin >> license;

			//////ѡ����С��///////
			int carsize = carVectB.size();
			int workcar;
			for (int i = 0; i < carsize; i++)
			{
				if (carVectB[i].status == false)
				{
					workcar = i;
					break;
				}
			}
			carVectB[workcar].status = true;
			cout << "������С���±���" << carVectB[workcar].index <<endl;
			/////////////////////////


			//	cout << "ͣ����B�ڲ���" << endl;
			for (int i = 0; i < spaceBsize; i++)
			{
				if (spaceB[i].status == false)
					ss.push_back(spaceB[i].distance);
			}
			for (int i = 0; i < spaceCsize; i++)
			{
				if (spaceC[i].status == false)
					ss.push_back(spaceC[i].distance);
			}
			sort(ss.begin(), ss.end());
			int minspace = 999;
			for (int i = 0; i < spaceBsize; i++)
			{
				if (ss[0] == spaceB[i].distance)
				{
					//cout << "i=" << i << endl;
					minspace = i;
					spaceB[i].status = true;
					spaceB[i].license = license;
					carVectB[workcar].change1(spaceB[i].x, spaceB[i].y);
					indexmin = 1;
					break;
				}
			}
			if (minspace == 999)
			{
				for (int i = 0; i < spaceCsize; i++)
				{
					if (ss[0] == spaceC[i].distance)
					{
						minspace = i;
						spaceC[i].status = true;
						spaceC[i].license = license;
					//	cout << "�����λ" << spaceC[minspace].index << "--" << spaceC[minspace].x << "--" << spaceC[minspace].y << endl;
						carVectB[workcar].change1(spaceC[i].x, spaceC[i].y);			
						indexmin = 2;
						break;
					}
				}
			}
			int min;
			if (indexmin == 1)
				min = parkingB.strgetIndex(spaceB[minspace].index);
			else if (indexmin == 2)
				min = parkingB.strgetIndex(spaceC[minspace].index);

			carVectB[workcar].s1.push(parkingB.Print(min).index);
			for (int j = path[min]; j != startB; j = path[j])
				carVectB[workcar].s1.push(parkingB.Print(j).index);
			//carVectB[workcar].s1.push(parkingB.Print(startB).index);
			//	cout << carVectB[workcar].s.top() << endl;
			//	carVectB[workcar].s.pop();


			int leave = parkingB.strgetIndex(carVectB[workcar].position);
			int *dist1 = new int[verNum];
			int *path1 = new int[verNum];
			parkingB.dijkstra(leave, dist1, path1);

			carVectB[workcar].s2.push(parkingB.Print(startB).index);
			for (int j = path1[startB]; j != leave; j = path1[j])
				carVectB[workcar].s2.push(parkingB.Print(j).index);
			//carVectB[workcar].s2.push(parkingB.Print(leave).index);
	   
			////ͣ������ȥȡ����·����
			int linesize = bLine.size();
			int lineindex = 0;
			while (carVectB[workcar].s2.size() != 0)
			{
			  if(strcmp(carVectB[workcar].s2.top(), "R57") != 0)
			 {
				  for (int i = 0; i < linesize; i++)
				  {
					 // char* = bLine[i].index1.c_str;
					  if (strcmp(carVectB[workcar].s2.top(), bLine[i].index1.c_str()) == 0)
					  {
						  lineindex = i;
						  if (bLine[i].status == false)
						  {
							  bLine[i].status = true;
							  carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
							  m.show();
						  }		
						  else{
							  Sleep(1000);
							  carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
							  m.show();
						  }
					  }
				  }
				  carVectB[workcar].s2.pop();
				  Sleep(1000);
				  carVectB[workcar].restore(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
				  bLine[lineindex].status = false;
				  m.show();
			  }
			  else{
				  Sleep(1000);
				  carVectB[workcar].s2.pop();
			  }
			}

			//ͣ������ȥ��λ��·����
		    // cout << carVectB[workcar].s1.top() << endl; 
			cout << parkingB.Print(min).index << endl;
			while (carVectB[workcar].s1.size() != 0)
			{
				if (strcmp(carVectB[workcar].s1.top(), parkingB.Print(min).index) != 0)
				{
					for (int i = 0; i < linesize; i++)
					{
						if (strcmp(carVectB[workcar].s1.top(), bLine[i].index1.c_str()) == 0)
						{
							lineindex = i;
							if (bLine[i].status == false)
							{
								bLine[i].status = true;
								carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
							    m.show();
							}
							else{
								Sleep(5000);
								carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
							    m.show();
							}
						}
					}
					carVectB[workcar].s1.pop();
					Sleep(5000);
					carVectB[workcar].restore(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
				    m.show();
				}
				else{
					Sleep(1000);
					carVectB[workcar].s1.pop();
					carVectB[workcar].change(parkingB.Print(min).x, parkingB.Print(min).y, parkingB.Print(min).length, parkingB.Print(min).wide);
					

					if (indexmin == 1)
						carVectB[workcar].change2(spaceB[minspace].x, spaceB[minspace].y);
					if (indexmin == 2)
						carVectB[workcar].change2(spaceC[minspace].x, spaceC[minspace].y);
					//cout << parkingB.Print(min).index << endl;
					//cout << parkingB.Print(min).x<<"--"<<parkingB.Print(min).y<< endl;
					m.show();
				}
			}
			m.show();
			cout << "ͣ�����" << endl;	


		}
		else
		{
			cout << "ȡ������" << endl;
		}
	}
////////////////////////////////////////////////////////

	system("pause");
}

