#include "maze.h"
#include <iostream>

int main()
{
	int height = 5;
	int width = 5;
	Maze* maze = new Maze(height, width);
	for (int i = 0; i < maze->height() - 1; i++)
	{
		bool connected = maze->makeConnection(i, i, i, i + 1);
		connected = maze->makeConnection(i, i + 1, i + 1, i + 1);
	}
	maze->makeConnection(height - 1, width - 1, height - 1, width);
	maze->printMaze();
}