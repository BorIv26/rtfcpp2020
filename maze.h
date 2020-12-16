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
	int m_height;//height � width ����� ��� ����, ����� ������� printMaze(),hasConnection(),makeConnection(), ����������� cell() � ������������ � ��(���������� � ����� ����������, ������������ � �����)
	int m_width;//height � width ����� ��� ����, ����� ������� printMaze(),hasConnection(),makeConnection(), ����������� cell() � ������������ � ��(���������� � ����� ����������, ������������ � �����)
};

#endif LAB_7_MAZE_H
#pragma once
