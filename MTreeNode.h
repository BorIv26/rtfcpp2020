#pragma once

#ifndef LAB_9_MTREENODE_H
#define LAB_9_MTREENODE_H

class MTreeNode
{
public:
	int m_i;
	int m_j;
	MTreeNode* m_parent;
	MTreeNode* m_children[3];//0-no child, 1-child for the right, 2- child below
	int m_distance;
	int i() const;
	int j() const;
	const MTreeNode* parent() const;
	const MTreeNode* child(int i) const;
	int distance() const;
	int childCount() const;
	bool addChild(int i, int j);
	MTreeNode* hasChild(int i, int j);
	static MTreeNode* beginTree(int i, int j);
private:
	MTreeNode(MTreeNode* parent);
};

#endif LAB_9_MTREENODE_H