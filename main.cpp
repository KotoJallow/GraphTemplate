#include "graph.h"
#include <cstdlib>
#include <ctime>
#define SIZE 5

int main(){
	srand(time(NULL));
	Graph g;
	// for (int i = 0; i < SIZE; ++i)
	// {
	// 	for (int j = 0; j < SIZE; ++j)
	// 	{
	// 		g.insert(i,rand()%SIZE);
	// 	}
	// }
	g.insert(25,90);g.insert(25,78);g.insert(25,80);g.insert(25,20);
	//g.insert(25,10);g.insert(25,90);g.insert(25,90);g.insert(25,90);
	//g.insert(25,90);g.insert(25,70);g.insert(25,80);g.insert(25,20);

	g.insert(38,67);g.insert(38,97);g.insert(38,37);
	g.insert(8,67);g.insert(8,97);g.insert(8,37);
	g.insert(50);g.insert(50,89);
	g.display();
	return 0;
}