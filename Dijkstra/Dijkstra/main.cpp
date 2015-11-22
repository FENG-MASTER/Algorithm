#include <iostream>
#include "Map_Dijkstra.h"
using namespace std;
int main(){
	int len=0;
	int road_len = 0;
	int road[7];
	Map_Dijkstra* mapD = new Map_Dijkstra(7);
	mapD->findMinRoad(0,6,&len,road,&road_len);
	
	cout << "len:"<<len<<"road"<<endl;
	for (int i = 0; i < road_len;i++){
		cout << road[i]<<endl;
	}
	system("pause");
	return 0;

}