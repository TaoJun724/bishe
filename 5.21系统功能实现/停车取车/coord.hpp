#ifndef COORD_HPP
#define COORD_HPP

#include"Comm.hpp"
#include<vector>
#include"Road.h"
#include"amgraph.h"
#define BOUNDS_CHECK
using namespace itlab;

vector<Road> aPoint;
vector<Road> bPoint;
vector<Road> aEle;
vector<Road> aLine;
vector<Road> aSpace;
vector<Road> cSpace;
vector<Road> bSpace;
vector<Road> bPark;
vector<Road> aPark2;
vector<Road> aPark1;
vector<Road> bLine;
vector<Road> bEle;
vector<agvCar> carVectB;//B停车场小车
vector<agvCar> carVectA;//B停车场小车


class Coord
{
public:
	//初始化停车场A图顶点
	void InitParkingAPoint(AMGraph<char, int>& parkingA,vector<Road>& v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A区图顶点.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			//cout << ret.index0 << endl;
			if (strcmp(ret.index0.c_str(), "out") != 0)
				v.push_back(ret);
			//cout << v.size() << endl;
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
			parkingA.insertVertex(ret);
		}
		fclose(fp);
	}

	//初始化停车场A图线路
	void InitParkingAEdge(AMGraph<char, int>& parkingA, vector<Road>& v)
	{
		char buf[1024];
		int size = v.size();
		int index1 = 0;
		int index2 = 0;
		FILE *fp;
		fp = fopen("A区图路线.txt", "r");
		while (1)
		{
			Road ret0, ret1;
			int value;
			fgets(buf, 1024, fp);
			ret0.index0 += buf[0];
			ret0.index0 += buf[1];
			ret0.index0 += buf[2];
		
			ret1.index0 += buf[4];
			ret1.index0 += buf[5];
			ret1.index0 += buf[6];

			value = buf[8] - 48;

			if (strcmp(ret0.index0.c_str(), "out") == 0)
				break;
		//	cout << ret0.index0 << endl;
		//  cout << ret1.index0 << endl;
		//	cout << value<< endl;
			for (int i = 0; i < size; i++)
			{
				if (strcmp(v[i].index0.c_str(), ret0.index0.c_str()) == 0)
					index1 = i;
				if (strcmp(v[i].index0.c_str(), ret1.index0.c_str()) == 0)
					index2 = i;
			}
			parkingA.insertEdge(v[index1], v[index2], 1);
		}
		fclose(fp);
		
	}

	//初始化停车场B图顶点
	void InitParkingBPoint(AMGraph<char, int>& parkingB, vector<Road>& v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("B区图顶点.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			//cout << ret.index0 << endl;
			if (strcmp(ret.index0.c_str(), "out") != 0)
				v.push_back(ret);
			//cout << v.size() << endl;
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
			parkingB.insertVertex(ret);
		}
		fclose(fp);
	}

	//初始化停车场B图线路
	void InitParkingBEdge(AMGraph<char, int>& parkingB, vector<Road>& v)
	{
		char buf[1024];
		int size = v.size();
		int index1 = 0;
		int index2 = 0;
		FILE *fp;
		fp = fopen("B区图路线.txt", "r");
		while (1)
		{
			Road ret0, ret1;
			int value;
			fgets(buf, 1024, fp);
			ret0.index0 += buf[0];
			ret0.index0 += buf[1];
			ret0.index0 += buf[2];

			ret1.index0 += buf[4];
			ret1.index0 += buf[5];
			ret1.index0 += buf[6];

			value = buf[8] - 48;

			if (strcmp(ret0.index0.c_str(), "out") == 0)
				break;
			//	cout << ret0.index0 << endl;
			//  cout << ret1.index0 << endl;
			//	cout << value<< endl;
			for (int i = 0; i < size; i++)
			{
				if (strcmp(v[i].index0.c_str(), ret0.index0.c_str()) == 0)
					index1 = i;
				if (strcmp(v[i].index0.c_str(), ret1.index0.c_str()) == 0)
					index2 = i;
			}
			parkingB.insertEdge(v[index1], v[index2], 1);
		}
		fclose(fp);
	}


	//初始化A停车场的停靠区1
	void ParkA1(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A停靠一.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
			v.push_back(ret);
		}
		fclose(fp);

		int size = 0;
		int i = 0;
		FILE* fp1;
		fp1 = fopen("A停靠坐标一.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);

	}
	//初始化A停车场的停靠区2
	void ParkA2(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A停靠二.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
			v.push_back(ret);
		}
		fclose(fp);

		int size = 0;
		int i = 0;
		FILE* fp1;
		fp1 = fopen("A停靠坐标二.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);

	}
	//初始化A停车场的充电区
	void EleA(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A充电.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
			v.push_back(ret);
		}
		fclose(fp);

		int size = 0;
		int i = 0;
		FILE* fp1;
		fp1 = fopen("A充电区坐标.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);

	}
	//初始化A停车场的便道
	void LineA(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A线路.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
			v.push_back(ret);
		}
		fclose(fp);

		int size = 0;
		int i = 0;
		FILE* fp1;
		fp1 = fopen("A线路坐标.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);

	}
	//构建A小车
	void CarA(vector<agvCar>& v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A小车构建.txt", "r");
		while (1)
		{
			agvCar ret;
			fgets(buf, 1024, fp);
			ret.position += buf[0];
			ret.position += buf[1];
			ret.position += buf[2];
			ret.index = buf[4] - 48;
			if (strcmp(ret.position.c_str(), "out") != 0)
				v.push_back(ret);
			if (strcmp(ret.position.c_str(), "out") == 0)
				break;
		}
		fclose(fp);
	}

	//初始化A停车场车位
	void SpaceA(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A区图车位.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			if (strcmp(ret.index0.c_str(), "out") != 0)
				v.push_back(ret);
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
		}
		fclose(fp);

	
		int i = 0;
		int size = 0;
		FILE* fp1;
		fp1 = fopen("功能A车位.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}
	//初始化公共车位
	void SpaceC(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("共用区图车位.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			if (strcmp(ret.index0.c_str(), "out") != 0)
				v.push_back(ret);
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
		}
		fclose(fp);

		int i = 0;
		int size = 0;
		FILE* fp1;
		fp1 = fopen("功能共用车位.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}
	//初始化B停车场车位
	void SpaceB(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("B区图车位.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			if (strcmp(ret.index0.c_str(), "out") != 0)
				v.push_back(ret);
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
		}
		fclose(fp);

		int i = 0;
		int size = 0;
		FILE* fp1;
		fp1 = fopen("功能B车位.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}
	//初始化B停车场的便道
	void LineB(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("B线路.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
			v.push_back(ret);
		}
		fclose(fp);

		int size = 0;
		int i = 0;
		FILE* fp1;
		fp1 = fopen("B线路坐标.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);

	}
	//初始化B停车场的停靠区
	void ParkB(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("B停靠.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
			v.push_back(ret);
		}
		fclose(fp);

		int size = 0;
		int i = 0;
		FILE* fp1;
		fp1 = fopen("B停靠坐标.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);

	}
	//初始化B停车场的充电区
	void EleB(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("B充电.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index0 += buf[0];
			ret.index0 += buf[1];
			ret.index0 += buf[2];
			if (strcmp(ret.index0.c_str(), "out") == 0)
				break;
			v.push_back(ret);
		}
		fclose(fp);

		int size = 0;
		int i = 0;
		FILE* fp1;
		fp1 = fopen("B充电坐标.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);

	}
	//构建B小车
	void CarB(vector<agvCar>& v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("B小车构建.txt", "r");
		while (1)
		{
			agvCar ret;
			fgets(buf, 1024, fp);
			ret.position += buf[0];
			ret.position += buf[1];
			ret.position += buf[2];
			ret.index = buf[4] - 48;
			if (strcmp(ret.position.c_str(), "out") != 0)
				v.push_back(ret);
			if (strcmp(ret.position.c_str(), "out") == 0)
				break;
		}
		fclose(fp);
	}
};


#endif
