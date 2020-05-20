#ifndef  __PARKING_MEMBER_HPP__
#define  __PARKING_MEMBER_HPP__

#include"Comm.hpp"
#include"parkingOperator.hpp"
#include<stack>
#include<ctime>
class agvCar//AGVС����
{
public:
	//���캯��
	agvCar()
	{
		eleNum = 100;
		stop = 0;
		status = false;
		start = clock();
		end = clock();
		distance = 0;
		eleStatus = 0;
		eleFlag = 0;
	}
public:
	//����λ״̬��ΪԤ��ʱ���и�ֵ
	void book(int x, int y)
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
	//����λ״̬��Ϊռ��ʱ���и�ֵ
	void occupy(int x, int y)
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
	//��ռ�õı��/ͣ����/����/��λ���и�ֵ
	void change(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//���оֲ��ĸ�ֵ
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 8;
			}
		}
	}
	//�ָ����ֵ
	void restoreLine(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//���оֲ��ĸ�ֵ
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 2;
			}
		}
	}
	//�ָ����ֵ
	void restoreEle(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//���оֲ��ĸ�ֵ
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 3;
			}
		}
	}
	//��ʾС�������뿪ͣ����
	void ingChange(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//���оֲ��ĸ�ֵ
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 6;
			}
		}
	}
	//�ָ�ͣ��ֵ
	void restorePark(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//���оֲ��ĸ�ֵ
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 4;
			}
		}
	}
	//�ָ�С��ֵ
	void restoreSpace(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//���оֲ��ĸ�ֵ
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 1;
			}
		}
	}

public:
	int index;//���
	int stop;//�Ƿ���Ҫͣ��������
    string position;//С������λ��
	int distance;//ȡ��ʱ���ڳ�λ�ľ���
	bool status;//С����״̬
	stack<string> s1;//��ȡͣ��ʱ���ڵ���λ��·��
	stack<string> s2;//��ȡͣ��ʱͣ���㵽���ڵ�·��
	stack<string> s3;//��ȡͣ��ʱ��·��
	stack<string> s4;//��ȡȡ��ʱȥ��λ��·��
	stack<string> s5;//��ȡȡ��ʱ��λ�����ڵ�·��
	stack<string> s6;//��ȡ���ʱ·��

public:
	double calEle(double& eleNum,int eleStatus,clock_t& start,clock_t& end)
	{
		end = clock();
		double ret = (end - start) / CLOCKS_PER_SEC;
		double tmp;
		if (eleStatus == 0)
		{
			tmp = ret * 0.5;
			eleNum -= tmp;
		}		
		if (eleStatus == 1)
		{
			tmp = ret * 1;
			eleNum -= tmp;
		}
			
		if (eleStatus == 2)
			eleNum = eleNum;
		return eleNum;
	}
	//��������
	double eleNum;
	//��ʱ��ʼ��
	clock_t start;
	//��ʱ��ֹ��
	clock_t end;
	//С�����ĵ�ı�־��
	//�������0���ʾ֮ǰΪͣ��
	//�������1���ʾΪ�˶���
	//�������2���ʾΪ���
	int eleStatus;
	//������� 0 ��ʾ����Ҫ 1��ʾ��Ҫ
	int eleFlag;
	//����ʱ��ĺĵ���(����Ϊ��λ��
	float free = 0.5;
	//����ʱ��ĺĵ���
	float busy = 1;
	//���ʱ������
	float charge = 5;

};


//����Ա�� 
class Manage
{
public:
	//��ʼ��ͣ��������
	void initParking()
	{
		build.model(arr);
	}
	//չʾͣ��������
	void show()
	{
		build.print(arr);
	}
	//��ѯ��λ״̬
	void findParkingSpaceStatus()
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
	//��ѯ���״̬
	void findRoadStatus()
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
	//��ѯС��״̬
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
			cout << "�����е�С����" << AgvCarNum - ret << "��" << endl;
		}
		return ret;
	}
private:
	Build build;
};

#endif