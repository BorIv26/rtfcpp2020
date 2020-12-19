#include "MTreeNode.h"
#include "maze.h"
#include <iostream>
using namespace std;

int main()
{
	int height = 5;
	int width = 5;
	Maze* maze = new Maze(height, width);
	for (int counter = 0; counter < height; counter++)
	{
		int i = counter;
		int j = counter;
		maze->makeConnection(i, j + 1, i + 1, j + 1);
		while (i <height-1)
		{
			maze->makeConnection(i, j, i+1, j);			
			i++;
		}
		j = counter;
		i = counter;
		while (j < width-1 )
		{
			maze->makeConnection(i, j, i, j+1);
			j++;
		}
	}
	int** nodesWeight;
	nodesWeight = new int* [height];
	for (int i = 0; i < height; i++)
	{
		nodesWeight[i] = new int[height];
	}
	nodesWeight[0][0] = 0;
	MTreeNode* beginNode = MTreeNode::beginTree(0, 0);
	MTreeNode* nextNode = beginNode;
	MTreeNode* nodeToCopy = nextNode;
	bool ableToAddChild;
	for (int i = 0; i < height; i++)
	{
		for (int j = i + 1; j < width; j++)
		{
			ableToAddChild = nextNode->addChild(j, i);
			nextNode = nextNode->hasChild(j, i);
		}
		nextNode = nodeToCopy;
		if (i < height - 1)
		{
			ableToAddChild = nextNode->addChild(i, i + 1);
			nextNode = nextNode->hasChild(i, i + 1);
			ableToAddChild = nextNode->addChild(i + 1, i + 1);
			nodeToCopy = nextNode->hasChild(i + 1, i + 1);
		}
		for (int j = i + 2; j < width; j++)
		{
			ableToAddChild = nextNode->addChild(i, j);
			nextNode = nextNode->hasChild(i, j);
		}
		nextNode = nodeToCopy;
	}	
	nextNode = beginNode;
	maze->printMaze();	
	nextNode = beginNode;
	nodeToCopy = nextNode;
	for (int i = 0; i < height; i++)
	{
		for (int j = i + 1; j < width; j++)
		{
			nextNode = nextNode->hasChild(j, i);
			nodesWeight[j][i] = nextNode->distance();
		}
		nextNode = nodeToCopy;
		if (i != height - 1)
		{
			nextNode = nextNode->hasChild(i, i + 1);
			nodesWeight[i][i + 1] = nextNode->distance();
			nodeToCopy = nextNode->hasChild(i + 1, i + 1);
			nodesWeight[i + 1][i + 1] = nodeToCopy->distance();
		}
		for (int j = i + 2; j < width; j++)
		{
			nextNode = nextNode->hasChild(i, j);
			nodesWeight[i][j] = nextNode->distance();
		}
		nextNode = nodeToCopy;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << nodesWeight[i][j] << " ";
		}
		cout << endl;
	}
}
