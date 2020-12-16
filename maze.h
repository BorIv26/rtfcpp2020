#include "MCell.h"
#pragma once

#ifndef LAB_8_MAZE_H
#define LAB_8_MAZE_H

class Maze
{
public:
	Maze(int n, int m);
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
	int height();
	int width();
	~Maze();
private:
	MCell* m_field;
	int m_height;//height and width are needed in order to execute printMaze(),hasConnection(),makeConnection(),cell() constructor, in accordance with the requirements for the task(the number and meaning of variables passed in the method)
	int m_width;//height and width are needed in order to execute printMaze(),hasConnection(),makeConnection(),cell() constructor, in accordance with the requirements for the task(the number and meaning of variables passed in the method)
};

#endif LAB_8_MAZE_H