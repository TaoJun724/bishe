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
vector<agvCar> carVectB;//Bͣ����С��
vector<agvCar> carVectA;//Bͣ����С��


class Coord
{
public:
	//��ʼ��ͣ����Aͼ����
	void InitParkingAPoint(AMGraph<char, int>& parkingA,vector<Road>& v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A��ͼ����.txt", "r");
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

	//��ʼ��ͣ����Aͼ��·
	void InitParkingAEdge(AMGraph<char, int>& parkingA, vector<Road>& v)
	{
		char buf[1024];
		int size = v.size();
		int index1 = 0;
		int index2 = 0;
		FILE *fp;
		fp = fopen("A��ͼ·��.txt", "r");
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

	//��ʼ��ͣ����Bͼ����
	void InitParkingBPoint(AMGraph<char, int>& parkingB, vector<Road>& v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("B��ͼ����.txt", "r");
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

	//��ʼ��ͣ����Bͼ��·
	void InitParkingBEdge(AMGraph<char, int>& parkingB, vector<Road>& v)
	{
		char buf[1024];
		int size = v.size();
		int index1 = 0;
		int index2 = 0;
		FILE *fp;
		fp = fopen("B��ͼ·��.txt", "r");
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


	//��ʼ��Aͣ������ͣ����1
	void ParkA1(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("Aͣ��һ.txt", "r");
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
		fp1 = fopen("Aͣ������һ.txt", "r");
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
	//��ʼ��Aͣ������ͣ����2
	void ParkA2(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("Aͣ����.txt", "r");
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
		fp1 = fopen("Aͣ�������.txt", "r");
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
	//��ʼ��Aͣ�����ĳ����
	void EleA(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A���.txt", "r");
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
		fp1 = fopen("A���������.txt", "r");
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
	//��ʼ��Aͣ�����ı��
	void LineA(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A��·.txt", "r");
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
		fp1 = fopen("A��·����.txt", "r");
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
	//����AС��
	void CarA(vector<agvCar>& v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("AС������.txt", "r");
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

	//��ʼ��Aͣ������λ
	void SpaceA(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("A��ͼ��λ.txt", "r");
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
		fp1 = fopen("����A��λ.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}
	//��ʼ��������λ
	void SpaceC(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("������ͼ��λ.txt", "r");
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
		fp1 = fopen("���ܹ��ó�λ.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}
	//��ʼ��Bͣ������λ
	void SpaceB(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("B��ͼ��λ.txt", "r");
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
		fp1 = fopen("����B��λ.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}
	//��ʼ��Bͣ�����ı��
	void LineB(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("B��·.txt", "r");
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
		fp1 = fopen("B��·����.txt", "r");
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
	//��ʼ��Bͣ������ͣ����
	void ParkB(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("Bͣ��.txt", "r");
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
		fp1 = fopen("Bͣ������.txt", "r");
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
	//��ʼ��Bͣ�����ĳ����
	void EleB(vector<Road> &v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("B���.txt", "r");
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
		fp1 = fopen("B�������.txt", "r");
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
	//����BС��
	void CarB(vector<agvCar>& v)
	{
		char buf[1024];
		FILE *fp;
		fp = fopen("BС������.txt", "r");
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
