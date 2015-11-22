#include "Map_Dijkstra.h"


Map_Dijkstra::Map_Dijkstra(int len)
{
	//初始化邻接矩阵
	//暂时不弄成参数形式
	int	map1[7][7] = {
		{ 0, 3, 3, noDway, noDway, noDway, noDway },
		{ noDway, 0, noDway, 2, 4, noDway, noDway },
		{ noDway, noDway, 0, noDway, 2, 1, noDway },
		{ noDway, noDway, noDway, 0, noDway, noDway, 2 },
		{ noDway, noDway, noDway, noDway, 0, noDway, 1 },
		{ noDway, noDway, noDway, noDway, 1, 0, noDway },
		{ noDway, noDway, noDway, noDway, noDway, noDway, 0 }


	};
	for (int j = 0; j < len;j++){
		for (int k = 0; k < len;k++){
			map[j][k] = map1[j][k];

		
		}
	
	}




	this->len = len;
	arrU = new (point_Dijkstra* [len]);
	for (int i = 0; i < len;i++){
		
		arrU[i] = new point_Dijkstra();
		continue;
	}
	
}


Map_Dijkstra::~Map_Dijkstra()
{
}
void Map_Dijkstra::findMinRoad(int start, int end, int *length, int * road,int *road_len){

	//init
	(*arrU[start]).isIn = true;
	(*arrU[start]).from = 0;
	(*arrU[start]).distance = 0;
	for (int _i = 0; _i < len;_i++)
	{
		int min = -1;
		int minj = 0;
		for (int j = 0; j < len; j++){
			if ((*arrU[j]).isIn){				
				for (int i = 0; i < this->len; i++){
					if (map[j][i] != noDway && (!(*arrU[i]).isIn)){
						//找到邻接点
						if ((*arrU[i]).distance == -1 || (*arrU[i]).distance>(*arrU[j]).distance + map[j][i]){
							(*arrU[i]).from = j;
							(*arrU[i]).distance = (*arrU[j]).distance + map[j][i];	
						}
						if (min == -1 || min > (*arrU[i]).distance){
							min = (*arrU[i]).distance;
							minj = i;
						}
					}
				}
			}	
		}
		(*arrU[minj]).isIn = true;			
	}

	//算法完成

	//输出


	*length = (*arrU[end]).distance;
	int temp = end;
	*road_len = 0;
	
	while ((*arrU[temp]).from!=start)
	{
		road[*road_len] = (*arrU[temp]).from;
		temp = (*arrU[temp]).from;
		(*road_len)++;
	}
	
	road[*road_len] = start;
	(*road_len)++;
	return;

	
}


