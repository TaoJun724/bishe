#ifndef MATRIXALLOCATE_H
#define MATRIXALLOCATE_H

namespace itlab
{
	template<typename Type>
	inline void makeMatrix(Type **&m, int rows, int cols)
	{
		m = new Type*[rows];
		for (int i = 0; i<rows; ++i)
			m[i] = new Type[cols];
	}

	template<typename Type>
	inline void deleteMatrix(Type **&m, int rows)
	{
		for (int i = 0; i<rows; ++i)
			delete[]m[i];

		delete[]m;
		m = 0;
	}

}

#endif
// MATRIXALLOCATE_H