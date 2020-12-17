#pragma once

#ifndef LAB_9_MCELL_H
#define LAB_9_MCELL_H

class MCell
{
public:
	bool right();
	bool down();
private:
	bool m_down = false;
	bool m_right = false;
	friend class Maze;
};

#endif LAB_9_MCELL_H
