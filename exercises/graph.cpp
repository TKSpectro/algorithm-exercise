#include <cstring>
#include <iostream>
using namespace std;

#define V 6

int G[V][V] = {
		{0,	3,	0,	6,	0,	3},
		{3, 0,  2,	5,  5,	1},
		{0,	2,	0,	1,  9,	6},
		{6,	5,  1,  0,  2,	4},
		{0,	5,  9,	2,	0,	1},
		{3,	1,  6,	4,  1,  0}};

void prim()
{
	int no_edge;  // number of edge

	// track already selected vertices
	bool selected[V];

	// set selected false initially
	for(int i = 0; i < V; i++)
	{
		selected[i] = false;
	}

	// set number of edge to 0
	no_edge = 0;

	// the number of egde in minimum spanning tree will be
	// always less than (V -1), where V is number of vertices in graph

	// choose 0th vertex and make it true
	selected[0] = true;

	int x;  //  row number
	int y;  //  col number

	// print for edge and weight
	cout << "Edge" << " : " << "Weight" << endl;
	while(no_edge < V - 1)
	{
		//For every vertex in the set S, find the all adjacent vertices
		// , calculate the distance from the vertex selected at step 1.
		// if the vertex is already in the set S, discard it otherwise
		//choose another vertex nearest to selected vertex  at step 1.

		int min = INT_MAX;
		x = 0;
		y = 0;

		for(int i = 0; i < V; i++)
		{
			if(selected[i])
			{
				for(int j = 0; j < V; j++)
				{
					if(!selected[j] && G[i][j])
					{  // not in selected and there is an edge
						if(min > G[i][j])
						{
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		cout << x << " - " << y << " :  " << G[x][y];
		cout << endl;
		selected[y] = true;
		no_edge++;
	}

	return;
}


/*
#include "graph.h"
#include <iostream>

using namespace std;

const int graphSize = 6;
const int inf = INT_MAX;

void printMST(int parent[], int graph[graphSize][graphSize])
{
	cout << "Edge \tWeight\n";
	for(int i = 1; i < graphSize; i++)
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX;

	for(int i = 0; i < graphSize; i++)
	{
		if(mstSet[i] == false && key[i] < min)
		{
			min = key[i];
			return i;
		}
	}
	puts("MinKey didnt work\n");
	return -1;
}

void prim()
{
	int graph[graphSize][graphSize] = {
		{0,	3,	0,	6,	0,	3},
		{3, 0,  2,	5,  5,	1},
		{0,	2,	0,	1,  9,	6},
		{6,	5,  1,  0,  2,	4},
		{0,	5,  9,	2,	0,	1},
		{3,	1,  6,	4,  1,  0}
	};

	int parent[graphSize];
	int key[graphSize];
	bool mstSet[graphSize];

	for(int i = 0; i < graphSize; i++)
	{
		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	// We just start at the first node
	key[0] = 0;
	parent[0] = -1;

	for(int i = 0; i < graphSize; i++)
	{
		int min = minKey(key, mstSet);

		mstSet[min] = true;

		for(int j = 0; j < graphSize; j++)
		{
			if(graph[min][j] > 0 && mstSet[j] == false && graph[min][j] < key[j])
			{
				parent[j] = min;
				key[j] = graph[min][j];
			}
		}
	}
	printMST(parent, graph);
}
*/