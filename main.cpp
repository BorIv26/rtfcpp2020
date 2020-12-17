#include "MTreeNode.h"
#include "maze.h"
#include <iostream>
using namespace std;

int main()
{
	int size = 5;
	int** nodesWeight;
	nodesWeight = new int* [size];
	for (int i = 0; i < size; i++)
	{
		nodesWeight[i] = new int[size];
	}
	nodesWeight[0][0] = 0;
	MTreeNode* beginNode = MTreeNode::beginTree(0, 0);
	Maze* maze = new Maze(size, size);
	MTreeNode* nextNode = beginNode;
	MTreeNode* nodeToCopy = nextNode;
	bool ableToAddChild;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++) 
		{
			ableToAddChild = nextNode->addChild(j, i);
			nextNode = nextNode->hasChild(j, i);
		}
		nextNode = nodeToCopy;
		if (i < size - 1) 
		{
			ableToAddChild = nextNode->addChild(i, i + 1);
			nextNode = nextNode->hasChild(i, i + 1);
			ableToAddChild = nextNode->addChild(i + 1, i + 1);
			nodeToCopy = nextNode->hasChild(i + 1, i + 1);
		}
		for (int j = i + 2; j < size; j++) 
		{
			ableToAddChild = nextNode->addChild(i, j);
			nextNode = nextNode->hasChild(i, j);
		}
		nextNode = nodeToCopy;
	}	
	nextNode = beginNode;
	for (int counter = 0; counter < size; counter++)
	{
		int i = nextNode->i()+1;
		int j = nextNode->j();
		nodeToCopy = nextNode;		
		MTreeNode* child = nodeToCopy->hasChild(i, j);
		while (child != nullptr)
		{
			ableToAddChild = maze->makeConnection(i - 1, j, i, j);
			i++;
			nodeToCopy = child;			
			child = nodeToCopy->hasChild(i, j);
		}
		i = counter + 1;
		nodeToCopy = nextNode;
		child = nodeToCopy->hasChild(counter, i);
		if (counter < size - 1)
		{
			nextNode = child->hasChild(counter + 1, counter + 1);
			ableToAddChild = maze->makeConnection(counter, i, i, i);
		}
		while (child != nullptr)
		{
			ableToAddChild = maze->makeConnection(j, i - 1, j, i);
			i++;
			nodeToCopy = child;			
			child = nodeToCopy->hasChild(counter, i);
		}
	}
	maze->printMaze();	
	nextNode = beginNode;
	nodeToCopy = nextNode;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			nextNode = nextNode->hasChild(j, i);
			nodesWeight[j][i] = nextNode->distance();
		}
		nextNode = nodeToCopy;
		if (i != size - 1)
		{
			nextNode = nextNode->hasChild(i, i + 1);
			nodesWeight[i][i + 1] = nextNode->distance();
			nodeToCopy = nextNode->hasChild(i + 1, i + 1);
			nodesWeight[i + 1][i + 1] = nodeToCopy->distance();
		}
		for (int j = i + 2; j < size; j++)
		{
			nextNode = nextNode->hasChild(i, j);
			nodesWeight[i][j] = nextNode->distance();
		}
		nextNode = nodeToCopy;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << nodesWeight[i][j] << " ";
		}
		cout << endl;
	}
}
