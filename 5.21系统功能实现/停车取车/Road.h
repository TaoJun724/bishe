#ifndef ROAD_H
#define ROAD_H



class Road{
public:
	Road()
	{
		status = false;
	}
	string license;
	bool status;
	string index0;
public:
	int x;
	int y;
	int length;
	int wide;
	int distance_B;
	int distance_A;
	int ele_Distance;
};

#endif