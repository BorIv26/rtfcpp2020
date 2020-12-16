#include "ìaze.h"
#include <iostream>

int main()
{
	int height = 5;
	int width = 5;
	Maze* maze = new Maze(height, width);	
	bool connected = maze->makeConnection(0, 0, 0, 1);
	connected = maze->makeConnection(0, 1, 1, 1);
	connected = maze->makeConnection(1, 1, 1, 2);
	connected = maze->makeConnection(1, 2, 2, 2);
	connected = maze->makeConnection(2, 2, 2, 3);
	connected = maze->makeConnection(2, 3, 3, 3);
	connected = maze->makeConnection(3, 3, 3, 4);
	connected = maze->makeConnection(3, 4, 4, 4);
	connected = maze->makeConnection(4, 4, 4, 5);
	for (int i = 0; i < maze->height() - 1; i++)
	{
		bool c = maze->makeConnection(i, i, i, i + 1);
		c = maze->makeConnection(i, i + 1, i + 1, i + 1);
	}
	maze->printMaze();
}