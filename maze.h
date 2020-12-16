#include "MCell.h"
#pragma once

#ifndef LAB_7_MAZE_H
#define LAB_7_MAZE_H

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
	int m_height;//height и width нужны дл€ того, чтобы вызвать printMaze(),hasConnection(),makeConnection(), конструктор cell() в соответствии с “«(количество и смысл переменных, передаваемых в метод)
	int m_width;//height и width нужны дл€ того, чтобы вызвать printMaze(),hasConnection(),makeConnection(), конструктор cell() в соответствии с “«(количество и смысл переменных, передаваемых в метод)
};

#endif LAB_7_MAZE_H
#pragma once
