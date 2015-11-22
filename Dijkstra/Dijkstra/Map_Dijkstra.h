#pragma once
#include "point_Dijkstra.h"
class Map_Dijkstra
{
public:
	

	Map_Dijkstra(int len);
	~Map_Dijkstra();
	void findMinRoad(int start,int end,int *length,int * road,int *road_len);

private:
	static const int noDway = -1;

	

	int len;
	point_Dijkstra** arrU;

	int map[7][7] ;



};

