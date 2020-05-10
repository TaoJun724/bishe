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
//  管理员类
	Manage m;
	m.initParking();

	cout << arr[110][95] << endl;
	int o;
	cin >> o;
	m.show();
//
	
//  图的构建
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


	//B停车场属性
	coord.LineB(bLine);
	coord.ParkB(bPark);
	//B停车场停靠点

//	cout << bLine.size() << endl;
//	cout << bLine[14].index1 << endl;
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


	
//

//判断停车场是否有车位
	IsFree isFree;
	int A = isFree.IsFreeA();
	int B = isFree.IsFreeB();
	isFree.freeInt();

	int x;
	cout << "请输入你所在地点" << endl;
	cin >> x;
	int choose;
	if (x <= 50)
	{
		if (A != 0)
		{
			cout << "请去A停车场停车" << endl;
			choose = 1;
		}		
		else if (B != 0)
		{
			cout << "请去B停车场停车" << endl;
			choose = 2;
		}			
		else
		{
			cout << "停车场没有空余车位" << endl;
			choose = 0;
		}
	}
	else{
		if (B != 0)
		{
			cout << "请去B停车场停车" << endl;
			choose = 2;
		}		
		else if (A != 0)
		{
			cout << "请去A停车场停车" << endl;
			choose = 1;
		}		
		else
		{
			cout << "停车场没有空余车位" << endl;
			choose = 0;
		}		
	}

	//	cout << choose << endl;



////////////////////////////////////////////////////
	
////////////////////////////////////////////////////////////////////////////////
	agvCar car1;
	car1.index = 1; car1.eleNum = 100; car1.position = "T12"; car1.status = false; car1.stop = 0; 
	for (int i = 0; i < bPark.size(); i++)
	{
		if (strcmp(bPark[i].index0.c_str(), car1.position) == 0)
		{
			bPark[i].status = true;
		}
	}

	agvCar car2;
	car2.index = 2; car2.eleNum = 100; car2.position = "T13"; car2.status = false; car2.stop = 0;

	vector<agvCar> carVectB;
	carVectB.push_back(car1); carVectB.push_back(car2);
//////////////////////////////////////////////////////////////////////////////
	string license;
	vector<int> ss;//排序寻找最近的车位
	int spaceBsize = spaceB.size();
	int spaceAsize = spaceA.size();
	int spaceCsize = spaceC.size();
	int indexmin = 0;
	int task;
	if (choose == 2)
	{
		cout << "请选择停车/取车任务" << endl;
		cin >> task;
		if (task == 1){
			cout << "停车任务" << endl;			
			cout << "请输入你的车牌号" << endl;
			cin >> license;

			//////选择工作小车///////
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
			cout << "工作的小车下标是" << carVectB[workcar].index <<endl;
			/////////////////////////


			//	cout << "停车场B内操作" << endl;
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
					//	cout << "最近车位" << spaceC[minspace].index << "--" << spaceC[minspace].x << "--" << spaceC[minspace].y << endl;
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
			
			
			int leave = parkingB.strgetIndex0(carVectB[workcar].position);
			int *dist1 = new int[verNum];
			int *path1 = new int[verNum];
			parkingB.dijkstra(leave, dist1, path1);

			carVectB[workcar].s2.push(parkingB.Print(startB).index);
			for (int j = path1[startB]; j != leave; j = path1[j])
				carVectB[workcar].s2.push(parkingB.Print(j).index);
			//carVectB[workcar].s2.push(parkingB.Print(leave).index);
			
			////停车任务去取车的路径上
			////将停靠点改为变动状态

			int leavecar;
			for (int i = 0; i < bPark.size(); i++)
			{
				if (strcmp(bPark[i].index0.c_str(), carVectB[workcar].position) == 0)
				{
			//		cout << bPark[i].x << " " << bPark[i].y << "" << bPark[i].length << endl;
				   carVectB[workcar].restore1(bPark[i].x, bPark[i].y, bPark[i].length, bPark[i].wide);
				   bPark[i].status = false;
				   leavecar = i;
				}
			}
			


		//	carVectB[workcar].restore1()
			int linesize = bLine.size();
			int lineindex = 0;
			while (carVectB[workcar].s2.size() != 0)
			{
				carVectB[workcar].restore2(bPark[leavecar].x, bPark[leavecar].y, bPark[leavecar].length, bPark[leavecar].wide);
			  if(strcmp(carVectB[workcar].s2.top(), "R57") != 0)
			 {
				  for (int i = 0; i < linesize; i++)
				  {
					 // char* = bLine[i].index1.c_str;
					  if (strcmp(carVectB[workcar].s2.top(), bLine[i].index0.c_str()) == 0)
					  {
						  lineindex = i;
						  carVectB[workcar].position = carVectB[workcar].s2.top();
						  if (bLine[i].status == false)
						  {
							  bLine[i].status = true;
							  carVectB[workcar].position = carVectB[workcar].s2.top();
							  carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
							  bLine[i].status = false;
					//		  m.show();
						  }		
						  else{
							  Sleep(1000);
							  carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
					//		  m.show();
						  }
					  }
				  }
				  carVectB[workcar].s2.pop();
				  Sleep(1000);
				  carVectB[workcar].restore(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
				  bLine[lineindex].status = false;
		//		  m.show();
			  }
			  else{
				  Sleep(1000);
				  carVectB[workcar].position = carVectB[workcar].s2.top();
				  carVectB[workcar].s2.pop();
			  }
			}

			//停车任务去车位的路径上
		    // cout << carVectB[workcar].s1.top() << endl; 
			cout << parkingB.Print(min).index << endl;
			while (carVectB[workcar].s1.size() != 0)
			{
				if (strcmp(carVectB[workcar].s1.top(), parkingB.Print(min).index) != 0)
				{
					for (int i = 0; i < linesize; i++)
					{
						if (strcmp(carVectB[workcar].s1.top(), bLine[i].index0.c_str()) == 0)
						{
							carVectB[workcar].position = carVectB[workcar].s1.top();
							lineindex = i;
							if (bLine[i].status == false)
							{
								bLine[i].status = true;
								carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
								bLine[i].status = false;
					//		    m.show();
							}
							else{
								Sleep(5000);
								carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
					//		    m.show();
							}
						}
					}
					carVectB[workcar].s1.pop();
					Sleep(5000);
					carVectB[workcar].restore(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
				//    m.show();
				}
				else{
					Sleep(1000);
					carVectB[workcar].s1.pop();
					carVectB[workcar].change(parkingB.Print(min).x, parkingB.Print(min).y, parkingB.Print(min).length, parkingB.Print(min).wide);
					

					if (indexmin == 1)
						carVectB[workcar].change2(spaceB[minspace].x, spaceB[minspace].y);
					if (indexmin == 2)
						carVectB[workcar].change2(spaceC[minspace].x, spaceC[minspace].y);
				//	m.show();
				}
			}
			cout << "停车任务完成" << endl;	






/////////////////////////////////////////////////////////停靠策略//////////////////////////////////////////////////////////
			carVectB[workcar].stop = 1;
			vector<int> tmp;
			int parkindex;
			int carBsize = carVectB.size();
			int pbsize = bPark.size();
			//cout << carVectB[workcar].position << endl;
			for (int i = 0; i < carBsize; i++)
			{
				if (carVectB[i].stop == 1)
				{
					int park = parkingB.strgetIndex0(carVectB[i].position);
					int *dist2 = new int[verNum];
					int *path2 = new int[verNum];
					parkingB.dijkstra(park, dist2, path2);

					for (int i = 0; i < pbsize; i++)
					{					
						bPark[i].distance = dist2[parkingB.strgetIndex0(bPark[i].index0.c_str())];
					//	cout << bPark[i].distance << endl;
					}
					for (int i = 0; i < pbsize; i++)
					{
						if (bPark[i].status == false)
						{
							tmp.push_back(bPark[i].distance);
						}
					}					
					sort(tmp.begin(), tmp.end());
					//寻找最近的空闲停车点
					for (int i = 0; i < pbsize; i++)
					{
						if (bPark[i].distance == tmp[0] && bPark[i].status == false)
						{
							parkindex = i;
							bPark[i].status = true;
						}				
						break;
					}
				
					
					min = parkingB.strgetIndex0(bPark[parkindex].index0.c_str());
					////cout << "min:" << min << endl;
					carVectB[workcar].s3.push(bPark[parkindex].index0.c_str());
					for (int j = path2[min]; j != park; j = path2[j])
						carVectB[workcar].s3.push(parkingB.Print(j).index);


					///小车去往停靠区的执行
					bool parkstop = false;
					while (carVectB[workcar].s3.size() != 0 &&  (parkstop == false))
					{
						////cout << carVectB[workcar].s3.size() << endl;
						////cout << carVectB[workcar].s3.top().c_str() << endl;
						////cout << bPark[parkindex].index0.c_str() << endl;
						if (strcmp(carVectB[workcar].s3.top().c_str(), bPark[parkindex].index0.c_str()) != 0)
						{
							for (int i = 0; i < linesize; i++)
							{
								if (strcmp(carVectB[workcar].s3.top().c_str(), bLine[i].index0.c_str()) == 0)
								{
									carVectB[workcar].position = carVectB[workcar].s3.top().c_str();
									lineindex = i;
									if (bLine[i].status == false)
									{
										bLine[i].status = true;
										carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
										bLine[i].status = false;
									    m.show();
									}
									else{
										Sleep(5000);
										carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
										    m.show();
									}
								}
							}
							carVectB[workcar].s3.pop();
							Sleep(5000);
							carVectB[workcar].restore(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
							   m.show();
						}
						else{
							carVectB[workcar].position = carVectB[workcar].s3.top().c_str();
							Sleep(1000);
						//	carVectB[workcar].s3.pop();
						//	carVectB[workcar].change(parkingB.Print(min).x, parkingB.Print(min).y, parkingB.Print(min).length, parkingB.Print(min).wide);
							carVectB[workcar].status = false;
							cout << "停靠点位" << "---" << carVectB[workcar].position << endl;
							for (int i = 0; i < bPark.size(); i++)
							{
								if (strcmp(bPark[i].index0.c_str(), carVectB[workcar].position) == 0)
								{
									bPark[i].status = true;
									carVectB[workcar].change(bPark[i].x, bPark[i].y, bPark[i].length, bPark[i].wide);
									m.show();
								}
									
							}
							parkstop = true;
						}
					}		
					cout << "停靠点位" << "---" << carVectB[workcar].position << endl;
					carVectB[workcar].position0.push(carVectB[workcar].s3.top());
					carVectB[workcar].s3.pop();
					carVectB[workcar].position = carVectB[workcar].position0.top().c_str();
					cout << "停靠点位" << "---" << carVectB[workcar].position << endl;
					cout << "停靠完成" << endl;
					m.show();
					/////////////////////////////////////////////////////////停靠策略//////////////////////////////////////////////////////////

				}
			}
		}
		else
		{
			cout << "取车任务" << endl;
		}
	}
////////////////////////////////////////////////////////

	system("pause");
}

