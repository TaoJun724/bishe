#ifndef  __PARKING_MEMBER_HPP__
#define  __PARKING_MEMBER_HPP__

#include"Comm.hpp"
#include"parkingOperator.hpp"

class agvCar//AGVС����
{
public:
	void change1(int x, int y)//����λ״̬��ΪԤ��ʱ���и�ֵ
	{
		int i = x;
		int j = y;
		int length = 0;
		int index = 1;
		while (arr[i][j] == 1)
		{
			arr[i][j] = 6;
			j++;
		}
		length = j - y;
		if (length == 9)
		{
			j = y; i--;
			while (index < 4)
			{
				while (arr[i][j] == 1)
				{
					arr[i][j] = 6;
					j++;
				}
				j = y; i--;
				index++;
			}
		}
		if (length == 4)
		{
			j = y; i--;
			while (index < 9)
			{
				while (arr[i][j] == 1)
				{
					arr[i][j] = 6;
					j++;
				}
				j = y; i--;
				index++;
			}
		}
	}

	void change2(int x, int y)//����λ״̬��Ϊռ��ʱ���и�ֵ
	{
		int i = x;
		int j = y;
		int length = 0;
		int index = 1;
		while (arr[i][j] == 6)
		{
			arr[i][j] = 7;
			j++;
		}
		length = j - y;
		if (length == 9)
		{
			j = y; i--;
			while (index < 4)
			{
				while (arr[i][j] == 6)
				{
					arr[i][j] = 7;
					j++;
				}
				j = y; i--;
				index++;
			}
		}
		if (length == 4)
		{
			j = y; i--;
			while (index < 9)
			{
				while (arr[i][j] == 6)
				{
					arr[i][j] = 7;
					j++;
				}
				j = y; i--;
				index++;
			}
		}
	}

private:
	int index;//���
	int eleNum;//��������
};

class Manage//����Ա�� 
{
public:
	void initParking()//��ʼ��ͣ��������
	{
		build.model(arr);
	}
	void show()//չʾͣ��������
	{

		build.print(arr);
	}
	void findParkingSpaceStatus()//��ѯ��λ״̬
	{
		int x; int y;
		int index = 0;
		int free = 0;
		int busy = 0;

		FILE* fp1;
		fp1 = fopen("��λ.txt", "r");

		multimap<int, int> mfree1;
		multimap<int, int> mbusy1;
		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] == 1)
			{
				free++;
				mfree1.insert(make_pair(x, y));
			}				
		}
		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] != 1)
			{
				busy++;
				mbusy1.insert(make_pair(x, y));
			}
		}
		fclose(fp1);
		cout << "���г�λ��:" << free << "��" << endl;
		if (free > 0){
			cout << "���г�λ���½�����Ϊ:" << endl;
			for (auto& e : mfree1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		cout << "�ǿ��г�λ��:" << busy << "��" << endl;
		if (busy > 0){
			cout << "��ռ�ó�λ���½�����Ϊ:" << endl;
			for (auto& e : mbusy1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
		}		
	}
	void findRoadStatus()//��ѯ���״̬
	{
		int x; int y;
		int index = 0;
		int free = 0;
		int busy = 0;

		FILE* fp1;
		fp1 = fopen("���.txt", "r");

		multimap<int, int> mfree1;
		multimap<int, int> mbusy1;
		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] == 2)
			{
				free++;
				mfree1.insert(make_pair(x, y));
			}
		}

		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] != 2)
			{
				busy++;
				mbusy1.insert(make_pair(x, y));
			}
		}

		fclose(fp1);
		cout << "���б����:" << free << "��" << endl;
		if (free > 0){
			cout << "���б�����½�����Ϊ:" << endl;
			for (auto& e : mfree1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		cout << "�ǿ��б����:" << busy << "��" << endl;
		if (busy > 0){
			cout << "��ռ�ñ�����½�����Ϊ:" << endl;
			for (auto& e : mbusy1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
		}
	}
	int findAgvCarStatus()
	{
		int x; int y;
		int index = 0;
		int ele = 0;
		int rest = 0;

		FILE* fp1;
		fp1 = fopen("�����.txt", "r");

		multimap<int, int> ele_m;
		multimap<int, int> rest_m;
		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] == 3)
			{
				ele++;
				ele_m.insert(make_pair(x, y));
			}
		}
		fclose(fp1);
		cout << "С������Ϊ:" << AgvCarNum << endl;	
		if (ele > 0){
			cout << "���С����:" << ele << "��" << endl;
			cout << "���С����������Ϊ:" << endl;
			for (auto& e : ele_m)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		FILE* fp2;
		fp2 = fopen("С��ͣ����.txt", "r");
		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] == 4)
			{
				rest++;
				rest_m.insert(make_pair(x, y));
			}
		}
		fclose(fp2);
		
		if (rest > 0){
			cout << "������ͣ��С����:" << rest << "��" << endl;
			cout << "������ͣ��С����������Ϊ:" << endl;
			for (auto& e : rest_m)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		int ret = rest + ele;
		if (ret < AgvCarNum)
		{
			cout << "�����е�С����" << AgvCarNum - ret<< "��" << endl;
		}
		return ret;
	}
private:
	Build build;
};

#endif