#include "BinaryTreeNode.h"
#pragma once

#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void Insert(BinaryTreeNode* node);
	void pre();
	void mid();
	void post();
private:
	BinaryTreeNode* head;
	void preTravel(BinaryTreeNode* node);
	void midTravel(BinaryTreeNode* node);
	void postTravel(BinaryTreeNode* node);
	void deleteTree(BinaryTreeNode* node);
};

#endif // !BINARYTREE_H
