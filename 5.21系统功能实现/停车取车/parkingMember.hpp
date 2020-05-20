#ifndef  __PARKING_MEMBER_HPP__
#define  __PARKING_MEMBER_HPP__

#include"Comm.hpp"
#include"parkingOperator.hpp"
#include<stack>
#include<ctime>
class agvCar//AGV小车类
{
public:
	//构造函数
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
	//当车位状态变为预定时进行改值
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
	//当车位状态变为占用时进行改值
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
	//对占用的便道/停靠点/充电点/车位进行改值
	void change(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//进行局部的赋值
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 8;
			}
		}
	}
	//恢复便道值
	void restoreLine(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//进行局部的赋值
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 2;
			}
		}
	}
	//恢复充电值
	void restoreEle(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//进行局部的赋值
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 3;
			}
		}
	}
	//表示小车正在离开停靠点
	void ingChange(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//进行局部的赋值
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 6;
			}
		}
	}
	//恢复停靠值
	void restorePark(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//进行局部的赋值
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 4;
			}
		}
	}
	//恢复小车值
	void restoreSpace(int x, int y, int length, int wide)
	{
		for (int i = x - wide + 1; i <= x; i++)//进行局部的赋值
		{
			for (int j = y; j <= y + length - 1; j++)
			{
				arr[i][j] = 1;
			}
		}
	}

public:
	int index;//编号
	int stop;//是否需要停靠的索引
    string position;//小车所在位置
	int distance;//取车时对于车位的距离
	bool status;//小车的状态
	stack<string> s1;//存取停车时出口到车位的路径
	stack<string> s2;//存取停车时停靠点到出口的路径
	stack<string> s3;//存取停靠时的路径
	stack<string> s4;//存取取车时去车位的路径
	stack<string> s5;//存取取车时车位到出口的路径
	stack<string> s6;//存取充电时路径

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
	//电量总数
	double eleNum;
	//计时起始点
	clock_t start;
	//计时终止点
	clock_t end;
	//小车消耗电的标志点
	//如果等于0则表示之前为停靠
	//如果等于1则表示为运动中
	//如果等于2则表示为充电
	int eleStatus;
	//充电索引 0 表示不需要 1表示需要
	int eleFlag;
	//空闲时间的耗电量(以秒为单位）
	float free = 0.5;
	//工作时间的耗电量
	float busy = 1;
	//充电时的速率
	float charge = 5;

};


//管理员类 
class Manage
{
public:
	//初始化停车场环境
	void initParking()
	{
		build.model(arr);
	}
	//展示停车场环境
	void show()
	{
		build.print(arr);
	}
	//查询车位状态
	void findParkingSpaceStatus()
	{
		int x; int y;
		int index = 0;
		int free = 0;
		int busy = 0;

		FILE* fp1;
		fp1 = fopen("车位.txt", "r");

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
		cout << "空闲车位有:" << free << "个" << endl;
		if (free > 0){
			cout << "空闲车位左下角坐标为:" << endl;
			for (auto& e : mfree1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		cout << "非空闲车位有:" << busy << "个" << endl;
		if (busy > 0){
			cout << "已占用车位左下角坐标为:" << endl;
			for (auto& e : mbusy1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
		}
	}
	//查询便道状态
	void findRoadStatus()
	{
		int x; int y;
		int index = 0;
		int free = 0;
		int busy = 0;

		FILE* fp1;
		fp1 = fopen("便道.txt", "r");

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
		cout << "空闲便道有:" << free << "个" << endl;
		if (free > 0){
			cout << "空闲便道左下角坐标为:" << endl;
			for (auto& e : mfree1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		cout << "非空闲便道有:" << busy << "个" << endl;
		if (busy > 0){
			cout << "已占用便道左下角坐标为:" << endl;
			for (auto& e : mbusy1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
		}
	}
	//查询小车状态
	int findAgvCarStatus()
	{
		int x; int y;
		int index = 0;
		int ele = 0;
		int rest = 0;

		FILE* fp1;
		fp1 = fopen("充电区.txt", "r");

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
		cout << "小车总数为:" << AgvCarNum << endl;
		if (ele > 0){
			cout << "充电小车有:" << ele << "个" << endl;
			cout << "充电小车左下坐标为:" << endl;
			for (auto& e : ele_m)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		FILE* fp2;
		fp2 = fopen("小车停靠区.txt", "r");
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
			cout << "无任务停靠小车有:" << rest << "个" << endl;
			cout << "无任务停靠小车左下坐标为:" << endl;
			for (auto& e : rest_m)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		int ret = rest + ele;
		if (ret < AgvCarNum)
		{
			cout << "工作中的小车有" << AgvCarNum - ret << "个" << endl;
		}
		return ret;
	}
private:
	Build build;
};

#endif