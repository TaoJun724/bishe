#ifndef ROAD_H
#define ROAD_H



class Road{
public:
	Road()
	{
		status = false;
	}
	char* index;
	string license;
	bool status;
	string index0;
public:
	int x;
	int y;
	int length;
	int wide;
	int distance;
	int distance_A;
};

#endif