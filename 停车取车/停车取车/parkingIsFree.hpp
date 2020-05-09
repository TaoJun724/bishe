#ifndef PARKING_IS_FREE_HPP
#define PARKING_IS_FREE_HPP


#include"Comm.hpp"

class IsFree
{
public:
	
	int IsFreeA()
	{
		for (int i = 0; i <= 70; i++)
		{
			if (spaceVect[i].status == false)
				indexA++;
		}
		return indexA;
	}

	int IsFreeB()
	{
		for (int i = 37; i <= 53; i++)
		{
			if (spaceVect[i].status == false)
				indexC++;
		}
		for (int i = 71; i <= 84; i++)
		{
			if (spaceVect[i].status == false)
				indexB++;
		}
		return indexC + indexB;
	}

	void freeInt()
	{
		indexA = 0; indexB = 0; indexC = 0;
	}

    int indexA = 0;
	int indexC = 0;
	int indexB = 0;
};

#endif