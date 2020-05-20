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

int main()
{
////////////////////����Ա��/////////////////////////
	Manage m;
	m.initParking();
///	int q;
///	cin >> q;
	cout << "չʾͣ����" << endl;
///	m.show();
/////////////////////////////////////////////////////

/////////////////////ͼ�Ĺ���///////////////////////
	Coord coord;
	AMGraph<char, int> parkingA;
	AMGraph<char, int> parkingB;
	coord.InitParkingAPoint(parkingA,aPoint);
	coord.InitParkingAEdge(parkingA, aPoint);
	coord.InitParkingBPoint(parkingB, bPoint);
	coord.InitParkingBEdge(parkingB, bPoint);
////////////////////////////////////////////////////

////////////////////ȫ��ʹ��////////////////////////
	coord.SpaceA(aSpace);//Aͣ������λ   
	int aSpacesize = aSpace.size();
	int aFree = 0;
	int aNum;

	coord.SpaceC(cSpace);//������λ
	int cSpacesize = cSpace.size();
	int cFree = 0;

	int aParkNum = (aSpacesize + cSpacesize) / 2;
	int APARKIndex;
	int aParkRet;

	coord.SpaceB(bSpace);//Bͣ������λ
	int bSpacesize = bSpace.size();
	int bFree = 0;
	int bNum;

	coord.ParkA2(aPark2);//Aͣ��2 
	int aParksize2 = aPark2.size();
	coord.ParkA1(aPark1);//Aͣ��1
	int aParksize1 = aPark1.size();
	coord.EleA(aEle);//A���
	int aElesize = aEle.size();
	coord.LineA(aLine);//A��·
	int aLineSize = aLine.size();
	coord.CarA(carVectA);//BС��¼��
	int caraSize = carVectA.size();

	coord.LineB(bLine);//B��·
	int bLineSize = bLine.size();
	coord.ParkB(bPark);//Bͣ�� 
	int bParksize = bPark.size();
	coord.EleB(bEle);//B���
	int bElesize = bEle.size();
	coord.CarB(carVectB);//BС��¼��
	int carbSize = carVectB.size();
	int location = 0;//�Դ��ж�ѡ���ĸ�ͣ����
	int chooseRet = 0;//ѡ��ͣ�����������/ȡ��ʱ�ж���λ
	string license;//����ĳ��ƺ�
	vector<int> minDistance;//ѡ�������λ(����
	int minIndex = 0;//�����λ�����ж����Ǹ���λ����
	int task;//ѡ��ͣ��/ȡ������
	int workcar;//����С��������
	int minspace = 999;//�ж����Ǹ���λ���� ���м��ж�����
	int min;//��ȡ�����λ��ͼ�е��������
	int leavePosi;//����С���뿪ʱ�ĳ�λ
	int leaveStat;//����С���ӵ�����ʱ����λ�õ�����
	int lineindex = 0;//������ʹ����·����
	vector<int> minPark;//ͣ������
	vector<int> minCar;//ȡ������ѡ�������С��
	int parkindex;//ͣ������
	int pickIndex;//ȡ������
	Road taskSpace;
	//int elePark;
	int aParkindex;
	string aparkstr;
/////////////////����Bͣ�����Գ���Ϊ�յ�ʹ��DIJKSTRA�㷨////////////////////////////

	int verNum = parkingB.getVertexNumber(), startB = parkingB.strgetIndex0("R57"),
		*dist = new int[verNum],
		*path = new int[verNum];
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

	int verNumA = parkingA.getVertexNumber(), startA = parkingA.strgetIndex0("R00"),
		*dist7 = new int[verNumA],
		*path7 = new int[verNumA];
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
//////////////////�ж�ͣ�����Ƿ����ͣ��///////////
	cout << "��������ĵص�" << endl;
	cin >> location;
	//��Aͣ������������
	for (int i = 0; i < aSpacesize; i++)
	{
		if (aSpace[i].status == false)
			aFree++;
	}
	//��Bͣ������������
	for (int i = 0; i < bSpacesize; i++)
	{
		if (bSpace[i].status == false)
			bFree++;
	}
	//�Թ��ó�λ��������
	for (int i = 0; i < cSpacesize; i++)
	{
		if (cSpace[i].status == false)
			cFree++;
	}
	aNum = aFree + cFree;
	bNum = bFree + cFree;
	////cout << aNum << " " << bNum << " "<<aFree<<" "<<bFree<<" "<<cFree<<endl;
	if (location <= 50)
	{
		if (aNum != 0)
		{
			cout << "��ȥAͣ����ͣ��" << endl;
			chooseRet = 1;
		}else if (bNum != 0)
		{
			cout << "��ȥBͣ����ͣ��" << endl;
			chooseRet = 2;
		}else{
			cout << "ͣ����û�п��೵λ" << endl;
			chooseRet = 0;
		}
	}else{
		if (bNum != 0)
		{
			cout << "��ȥBͣ����ͣ��" << endl;
			chooseRet = 2;
		}else if (aNum != 0)
		{
			cout << "��ȥAͣ����ͣ��" << endl;
			chooseRet = 1;
		}else{
			cout << "ͣ����û�п��೵λ" << endl;
			chooseRet = 0;
		}
	}
//////////////////////////////////////////////////


///////////////Aͣ��ȡ������//////////////////////
	if (chooseRet == 1)//��Aͣ�������в���
	{
		cout << "��ѡ��ͣ��/ȡ������" << endl;
		cin >> task;
		if (task == 1){
			cout << "ͣ������" << endl;
			cout << "��������ĳ��ƺ�" << endl;
			cin >> license;


			//ѡ����еĿ���С��
			for (int i = 0; i < caraSize; i++)
			{
				if (carVectA[i].status == false)
				{
					carVectA[i].eleNum = carVectA[i].calEle(carVectA[i].eleNum, carVectA[i].eleStatus, carVectA[i].start, carVectA[i].end);
					//cout << carVectB[i].eleNum << "->" << carVectB[i].start << "->" << carVectB[i].end << "->" << carVectB[i].eleStatus << endl;
					if (carVectA[i].eleNum >= 25)
					{
						workcar = i;
						break;
					}
				}
			}
			carVectA[workcar].status = true;//��״̬��Ϊʹ��
			carVectA[workcar].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
			carVectA[workcar].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
			cout << "������С���±���" << carVectA[workcar].index << endl;

			//ѡ������ĳ�λ
			for (int i = 0; i < aSpacesize; i++)
			{
				if (aSpace[i].status == false)
					minDistance.push_back(aSpace[i].distance_A);
			}
			for (int i = 0; i < cSpacesize; i++)
			{
				if (cSpace[i].status == false)
					minDistance.push_back(cSpace[i].distance_A);
			}
			sort(minDistance.begin(), minDistance.end());
			//cout << minDistance[0] << endl;
			minspace = 999;
			//�ж������λ���ĸ�����
			for (int i = 0; i < aSpacesize; i++)
			{
				if (minDistance[0] == aSpace[i].distance_A)
				{
					minspace = i;
					aSpace[i].status = true;
					aSpace[i].license = license;
					carVectA[workcar].book(aSpace[i].x, aSpace[i].y);
					//cout << "�����λ" << aSpace[minspace].index0 << "--"<< endl;
					minIndex = 1;
					break;
				}
			}
			if (minspace == 999)
			{
				for (int i = 0; i < cSpacesize; i++)
				{
					if (minDistance[0] == cSpace[i].distance_A)
					{
						minspace = i;
						cSpace[i].status = true;
						cSpace[i].license = license;
						carVectA[workcar].book(cSpace[i].x, cSpace[i].y);
						minIndex = 2;
						break;
					}
				}
			}
			minDistance.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��
			if (minIndex == 1){
				min = parkingA.strgetIndex0(aSpace[minspace].index0.c_str());
				//cout << aSpace[minspace].index0 << endl;
			}
			else if (minIndex == 2)
				min = parkingA.strgetIndex0(cSpace[minspace].index0.c_str());
			//������ѡ��������λ

			//��ȡ���ڵ������λ��·��
			while (!carVectA[workcar].s1.empty())
				carVectA[workcar].s1.pop();
			carVectA[workcar].s1.push(parkingA.Print(min).index0);
			for (int j = path7[min]; j != startA; j = path7[j])
				carVectA[workcar].s1.push(parkingA.Print(j).index0);

			//��С����ǰλ��Ϊ�����㵽���ڵ����·��
			int leaveA = parkingA.strgetIndex0(carVectA[workcar].position.c_str());
			int *dist8 = new int[verNumA];
			int *path8 = new int[verNumA];
			parkingA.dijkstra(leaveA, dist8, path8);


			//��ȡС�������ڵ����·��
			while (!carVectA[workcar].s2.empty())
				carVectA[workcar].s2.pop();
			carVectA[workcar].s2.push(parkingA.Print(startA).index0);
			for (int j = path8[startA]; j != leaveA; j = path8[j])
				carVectA[workcar].s2.push(parkingA.Print(j).index0);


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

			//����С��ȥ���ڵĹ���
			carVectA[workcar].eleStatus = 1;
			carVectA[workcar].start = clock();
			while (carVectA[workcar].s2.size() != 0)
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

				if (strcmp(carVectA[workcar].s2.top().c_str(), "R00") != 0)
				{
					for (int i = 0; i < aLineSize; i++)
					{
						if (strcmp(carVectA[workcar].s2.top().c_str(), aLine[i].index0.c_str()) == 0)
						{
							lineindex = i;
							if (aLine[i].status == false)
							{
								aLine[i].status = true;
								carVectA[workcar].position = carVectA[workcar].s2.top();
								////cout << carVectB[workcar].position << endl;
								carVectA[workcar].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
								////m.show();
							}
							else{
								Sleep(2000);
								carVectA[workcar].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
								carVectA[workcar].position = carVectA[workcar].s2.top();
								////cout << carVectB[workcar].position << endl;											
								////m.show();
							}
						}
					}
					carVectA[workcar].s2.pop();
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
					carVectA[workcar].position = carVectA[workcar].s2.top();
					carVectA[workcar].s2.pop();
					////cout << carVectB[workcar].position << endl;
					////m.show();
				}
			}
			//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
			while (carVectA[workcar].s1.size() != 0)
			{
				if (strcmp(carVectA[workcar].s1.top().c_str(), parkingA.Print(min).index0.c_str()) != 0)
				{
					for (int i = 0; i < aLineSize; i++)
					{
						if (strcmp(carVectA[workcar].s1.top().c_str(), aLine[i].index0.c_str()) == 0)
						{
							carVectA[workcar].position = carVectA[workcar].s1.top();
							////cout << carVectB[workcar].position << endl;
							lineindex = i;
							if (aLine[i].status == false)
							{
								aLine[i].status = true;
								carVectA[workcar].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
								////m.show();
							}
							else{
								Sleep(2000);
								carVectA[workcar].change(aLine[i].x, aLine[i].y, aLine[i].length, aLine[i].wide);
								////m.show();
							}
						}
					}
					aLine[lineindex].status = false;
					carVectA[workcar].s1.pop();
					Sleep(2000);
					carVectA[workcar].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
				}
				else{
					Sleep(1000);
					carVectA[workcar].s1.pop();
					carVectA[workcar].change(parkingA.Print(min).x, parkingA.Print(min).y, parkingA.Print(min).length, parkingA.Print(min).wide);

					if (minIndex == 1)
						carVectA[workcar].occupy(aSpace[minspace].x, aSpace[minspace].y);
					if (minIndex == 2)
						carVectA[workcar].occupy(cSpace[minspace].x, cSpace[minspace].y);

					carVectA[workcar].end = clock();
					carVectA[workcar].eleNum = carVectA[workcar].calEle(carVectA[workcar].eleNum, carVectA[workcar].eleStatus, carVectA[workcar].start, carVectA[workcar].end);
					//cout << carVectB[workcar].eleNum << endl;
					if (carVectA[workcar].eleNum <= 25)
					{
						//������Ҫ��� �����Խ�����
						carVectA[workcar].eleFlag = 1;
						//ִ�г�����
						//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
						carVectA[workcar].eleStatus = 0;
						carVectA[workcar].start = clock();
					}
					else{
						carVectA[workcar].stop = 1;//��ʾ��Ҫͣ��
						carVectA[workcar].status = false;//��ʾ���Խ�����
						carVectA[workcar].start = clock();
					}
					////cout << carVectB[workcar].position << endl;
					/////m.show();
				}
			}
			cout << "ͣ���������" << endl;
			m.show();

		}
		else{
			cout << "ȡ������" << endl;
			cout << "�����복�ƺ�" << endl;
			cin >> license;

			//aSpace[3].license = "2";
			//carVectA[0].change(aSpace[3].x, aSpace[3].y, aSpace[3].length, aSpace[3].wide);
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
					cout << carVectA[workcar].position << endl;
					cout << "ȡ�����" << endl;
				}
			}
		}
	}
///////////////Bͣ��ȡ������//////////////////////
		if (chooseRet == 2)//��Bͣ�������в���
		{
			cout << "��ѡ��ͣ��/ȡ������" << endl;
			cin >> task;
			if (task == 1){
				cout << "ͣ������" << endl;
				cout << "��������ĳ��ƺ�" << endl;
				cin >> license;


				//ѡ����еĿ���С��
				for (int i = 0; i < carbSize; i++)
				{
					if (carVectB[i].status == false)
					{
						carVectB[i].eleNum = carVectB[i].calEle(carVectB[i].eleNum, carVectB[i].eleStatus, carVectB[i].start, carVectB[i].end);
						//cout << carVectB[i].eleNum << "->" << carVectB[i].start << "->" << carVectB[i].end << "->" << carVectB[i].eleStatus << endl;
						if (carVectB[i].eleNum >= 25)
						{
							workcar = i;
							break;
						}
					}
				}
				carVectB[workcar].status = true;//��״̬��Ϊʹ��
				carVectB[workcar].stop = 0;//�����ͣ����·��Ҳ��������ȥ���й���
				carVectB[workcar].eleFlag = 0;//��������ڳ��Ľ�����־��Ϊ��
				cout << "������С���±���" << carVectB[workcar].index << endl;

				//ѡ������ĳ�λ
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
				minspace = 999;
				//�ж������λ���ĸ�����
				for (int i = 0; i < bSpacesize; i++)
				{
					if (minDistance[0] == bSpace[i].distance_B)
					{
						minspace = i;
						bSpace[i].status = true;
						bSpace[i].license = license;
						carVectB[workcar].book(bSpace[i].x, bSpace[i].y);
						minIndex = 1;
						break;
					}
				}
				if (minspace == 999)
				{
					for (int i = 0; i < cSpacesize; i++)
					{
						if (minDistance[0] == cSpace[i].distance_B)
						{
							minspace = i;
							cSpace[i].status = true;
							cSpace[i].license = license;
							//	cout << "�����λ" << spaceC[minspace].index << "--" << spaceC[minspace].x << "--" << spaceC[minspace].y << endl;
							carVectB[workcar].book(cSpace[i].x, cSpace[i].y);
							minIndex = 2;
							break;
						}
					}
				}
				minDistance.clear();//����ʹ����ʱ������գ��Ա���һ��ʹ��
				if (minIndex == 1)
					min = parkingB.strgetIndex0(bSpace[minspace].index0.c_str());
				else if (minIndex == 2)
					min = parkingB.strgetIndex0(cSpace[minspace].index0.c_str());
				//������ѡ��������λ

				//��ȡ���ڵ������λ��·��
				while (!carVectB[workcar].s1.empty())
					carVectB[workcar].s1.pop();
				carVectB[workcar].s1.push(parkingB.Print(min).index0);
				for (int j = path[min]; j != startB; j = path[j])
					carVectB[workcar].s1.push(parkingB.Print(j).index0);

				//��С����ǰλ��Ϊ�����㵽���ڵ����·��
				int leave = parkingB.strgetIndex0(carVectB[workcar].position.c_str());
				int *dist1 = new int[verNum];
				int *path1 = new int[verNum];
				parkingB.dijkstra(leave, dist1, path1);
				//��ȡС�������ڵ����·��
				while (!carVectB[workcar].s2.empty())
					carVectB[workcar].s2.pop();
				carVectB[workcar].s2.push(parkingB.Print(startB).index0);
				for (int j = path1[startB]; j != leave; j = path1[j])
					carVectB[workcar].s2.push(parkingB.Print(j).index0);
				//��¼����С���뿪ʱ��λ��
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

				//����С��ȥ���ڵĹ���
				carVectB[workcar].eleStatus = 1;
				carVectB[workcar].start = clock();
				while (carVectB[workcar].s2.size() != 0)
				{
					if (leaveStat == 0)
						carVectB[workcar].restorePark(bPark[leavePosi].x, bPark[leavePosi].y, bPark[leavePosi].length, bPark[leavePosi].wide);
					if (leaveStat == 1)
						carVectB[workcar].restoreLine(bLine[leavePosi].x, bLine[leavePosi].y, bLine[leavePosi].length, bLine[leavePosi].wide);
					if (leaveStat == 2)
						carVectB[workcar].restoreEle(bEle[leavePosi].x, bEle[leavePosi].y, bEle[leavePosi].length, bEle[leavePosi].wide);

					if (strcmp(carVectB[workcar].s2.top().c_str(), "R57") != 0)
					{
						for (int i = 0; i < bLineSize; i++)
						{
							if (strcmp(carVectB[workcar].s2.top().c_str(), bLine[i].index0.c_str()) == 0)
							{
								lineindex = i;
								if (bLine[i].status == false)
								{
									bLine[i].status = true;
									carVectB[workcar].position = carVectB[workcar].s2.top();
									////cout << carVectB[workcar].position << endl;
									carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
									m.show();
								}
								else{
									Sleep(2000);
									carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
									carVectB[workcar].position = carVectB[workcar].s2.top();
									////cout << carVectB[workcar].position << endl;											
									m.show();
								}
							}
						}
						carVectB[workcar].s2.pop();
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
						carVectB[workcar].position = carVectB[workcar].s2.top();
						carVectB[workcar].s2.pop();
						////cout << carVectB[workcar].position << endl;
						////m.show();
					}
				}
				//С���Ѿ����յ���Ҫͣ�ĳ������������λ��·��
				while (carVectB[workcar].s1.size() != 0)
				{
					if (strcmp(carVectB[workcar].s1.top().c_str(), parkingB.Print(min).index0.c_str()) != 0)
					{
						for (int i = 0; i < bLineSize; i++)
						{
							if (strcmp(carVectB[workcar].s1.top().c_str(), bLine[i].index0.c_str()) == 0)
							{
								carVectB[workcar].position = carVectB[workcar].s1.top();
								////cout << carVectB[workcar].position << endl;
								lineindex = i;
								if (bLine[i].status == false)
								{
									bLine[i].status = true;
									carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
									m.show();
								}
								else{
									Sleep(2000);
									carVectB[workcar].change(bLine[i].x, bLine[i].y, bLine[i].length, bLine[i].wide);
									m.show();
								}
							}
						}
						bLine[lineindex].status = false;
						carVectB[workcar].s1.pop();
						Sleep(2000);
						carVectB[workcar].restoreLine(bLine[lineindex].x, bLine[lineindex].y, bLine[lineindex].length, bLine[lineindex].wide);
					}
					else{
						Sleep(1000);
						carVectB[workcar].s1.pop();
						carVectB[workcar].change(parkingB.Print(min).x, parkingB.Print(min).y, parkingB.Print(min).length, parkingB.Print(min).wide);

						if (minIndex == 1)
							carVectB[workcar].occupy(bSpace[minspace].x, bSpace[minspace].y);
						if (minIndex == 2)
							carVectB[workcar].occupy(cSpace[minspace].x, cSpace[minspace].y);

						carVectB[workcar].end = clock();
						carVectB[workcar].eleNum = carVectB[workcar].calEle(carVectB[workcar].eleNum, carVectB[workcar].eleStatus, carVectB[workcar].start, carVectB[workcar].end);
						//cout << carVectB[workcar].eleNum << endl;
						if (carVectB[workcar].eleNum <= 25)
						{
							//������Ҫ��� �����Խ�����
							carVectB[workcar].eleFlag = 1;
							//ִ�г�����
							//״̬��Ϊͣ����Ѱ�ҵ����������ִ��
							carVectB[workcar].eleStatus = 0;
							carVectB[workcar].start = clock();
						}
						else{
							carVectB[workcar].stop = 1;//��ʾ��Ҫͣ��
							carVectB[workcar].status = false;//��ʾ���Խ�����
							carVectB[workcar].start = clock();
						}
						////cout << carVectB[workcar].position << endl;
						m.show();
					}
				}
				cout << "ͣ���������" << endl;
				m.show();
			}
			else{
				cout << "ȡ������" << endl;
				cout << "�����복�ƺ�" << endl;
				cin >> license;

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


			}
		}
////////////////////////////////////////////////ͣ������/////////////////////////////////////////
//////1.B����////////////////////////////////
	for (int i = 0; i < carbSize; i++)
	{
		if (carVectB[i].stop == 1)
		{
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
			}else{
				//����ִ��ͣ������
				carVectB[i].end = clock();
				carVectB[i].eleNum = carVectB[i].calEle(carVectB[i].eleNum, carVectB[i].eleStatus, carVectB[i].start, carVectB[i].end);
				if (carVectB[i].eleNum < 25)
				{
					//��s3���
					while (!carVectB[i].s3.empty())
						carVectB[i].s3.pop();
					//ִ�г�����
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
			while (carVectB[i].s3.size() != 0 )
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
			cout << "ͣ������" << endl;
			cout << "ͣ����λ" << "---" << carVectB[workcar].position << endl;
		}
	}
///////////////2.A����ͣ������////////////////////////
	
	////carVectA[0].stop = 1;
	for (int i = 0; i < caraSize; i++)
	{
		APARKIndex = 0;
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
			int parkA = parkingA.strgetIndex0(carVectA[i].position.c_str());
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

			sort(minPark.begin(), minPark.end());
			//Ѱ������Ŀ���ͣ����
			if (aParkRet == 1)
			{
				for (int g = 0; g < aParksize1; g++)
				{
					if (aPark1[g].distance_A == minPark[0] && aPark1[g].status == false)
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
					if (aPark2[g].distance_A == minPark[0] && aPark2[g].status == false)
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
					cout << "��������" << endl;
					cout << "ͣ����λ" << "---" << carVectA[i].position << endl;
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
			cout << "ͣ������" << endl;
			cout << "ͣ����λ" << "---" << carVectA[workcar].position << endl;
		}
	}


////////////////B������////////////////////
	////carVectB[0].eleFlag = 1;
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

/////////////////////////////////////////////

////////////////A������////////////////////
	////carVectA[0].eleFlag = 1;
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
					carVectA[i].s6.pop();
					Sleep(2000);
					carVectA[i].restoreLine(aLine[lineindex].x, aLine[lineindex].y, aLine[lineindex].length, aLine[lineindex].wide);
				}
				else{
					carVectA[i].position = carVectA[i].s6.top().c_str();
					carVectA[i].s6.pop();
					carVectA[i].position = aEle[parkindex].index0;
					cout << "����λ" << "---" << carVectA[i].position << endl;
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
			cout << "������" << endl;
			cout << "����λ" << "---" << carVectA[i].position << endl;
		}
	}
	system("pause");
}

