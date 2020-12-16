#include <iostream>
#include "maze.h"
using namespace std;

Maze::Maze(int n, int m)
{
	this->m_field = new MCell[n * m];
	this->m_width = n;//meaning of width and height is explained in maze.h
	this->m_height = m;//meaning of width and height is explained in maze.h
}

int Maze::width()
{
	return this->m_width;
}

int Maze::height()
{
	return this->m_height;
}

const MCell& Maze::cell(int i, int j) const
{
	if (i < 0 && j < 0)
		return *(new MCell());
	return this->m_field[i * this->m_width + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	MCell c;
	if (((abs(i1 - i2) + abs(j1 - j2)) != 1) || i1 < 0 || j1 < 0 || i2 < 0 || j2 < 0) return false;

	if (i1 != i2)
	{
		if (i1 > i2)
			c = this->cell(i2, j2);
		else
			c = this->cell(i1, j1);
		return c.m_down;
	}
	else
	{
		if (j1 > j2)
			c = this->cell(i2, j2);
		else
			c = this->cell(i1, j1);
		return c.m_right;
	}
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	MCell* c;
	if (abs(i1 - i2) + abs(j1 - j2) != 1)
		return false;
	if (i1 != i2)
	{
		if (i1 > i2)
			c = &this->m_field[i2 * this->m_width + j2];
		else
			c = &this->m_field[i1 * this->m_width + j1];
		c->m_down = true;
	}
	else
	{
		if (j1 > j2)
			c = &this->m_field[i2 * this->m_width + j2];
		else
			c = &this->m_field[i1 * this->m_width + j1];
		c->m_right = true;
	}
	return this->hasConnection(i1, j1, i2, j2);
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	MCell c;
	if (abs(i1 - i2) + abs(j1 - j2) != 1)
		return false;
	if (i1 != i2)
	{
		if (i1 > i2)
			c = this->cell(i2, j2);
		else
			c = this->cell(i1, j1);
		c.m_down = false;
	}
	else
	{
		if (j1 > j2)
			c = this->cell(i2, j2);
		else
			c = this->cell(i1, j1);
		c.m_right = false;
	}
	return true;
}

void Maze::printMaze()
{
	for (int i = 0; i < this->height(); i++)
	{
		for (int j = 0; j < this->width(); j++)
		{
			char symbol = (char)248;
			bool down = this->hasConnection(i, j, i + 1, j);
			bool right = this->hasConnection(i, j, i, j + 1);
			bool left = this->hasConnection(i, j, i, j - 1);
			bool up = this->hasConnection(i, j, i - 1, j);
			if (up && down)
				symbol = (char)179;
			if (up && right)
				symbol = (char)192;
			if (up && left)
				symbol = (char)217;
			if (down && left)
				symbol = (char)191;
			if (right && left)
				symbol = (char)196;
			if (right && down)
				symbol = (char)218;
			if (up && down && left)
				symbol = (char)180;
			if (up && right && left)
				symbol = (char)193;
			if (up && right && down)
				symbol = (char)195;
			if (right && down && left)
				symbol = (char)194;
			if (up && right && down && left)
				symbol = (char)197;
			cout << symbol;
		}
		cout << endl;
	}
}

Maze::~Maze()
{
	delete this->m_field;
}