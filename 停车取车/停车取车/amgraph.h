#ifndef AMGRAPH_H
#define AMGRAPH_H

#define INITSIZE 150
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "matrixallocate.h"
#include"Road.h"

using namespace std;


namespace itlab
{

	/**
	* adjacency matrix based graph
	*/
	template<typename Object, typename Weight>
	class AMGraph
	{

	public:

		static const Weight MAXWEIGHT = Weight(32767);
		static const Weight MINWEIGHT = Weight(-32768);

		explicit AMGraph(int n = INITSIZE);
		~AMGraph();

		int getVertexNumber() const;
		int getEdgeNumber() const;

		Object getData(int i) const;
		//int getIndex(const Road &x) const;
		int strgetIndex(char* str) const;
		int getIndex(const Road &x) const;
		Weight getWeight(int row, int col) const;
		Weight getWeight(const Road &x1, const Road &x2) const;

		int getNextDst(const Road &x) const;
		int getNextDst(const Road &x1, const Road &x2) const;

		//void insertVertex(const Object &x);
		void insertVertex(const Road &x);
		void removeVertex(const Road &x);
		void insertEdge(const Road &x1, const Road &x2, Weight c);
		void removeEdge(const Road &x1, const Road &x2);

		void dijkstra(int start, Weight *dist, int *path);
		void floyd(Weight **dist, int **path);
		int GetIndex(const Road &x);
		Road Print(int i);
	private:

		int curSize;
		int maxSize;
		int edgeNum;
		Road *vertexArray;
		Weight **edgeMatrix;

	};


#include "amgraph-impl.h"

}
// namespace itlab


#endif
// AMGRAPH_H