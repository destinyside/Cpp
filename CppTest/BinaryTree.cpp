#include<iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	head = NULL;
	std::cout << "构造BinaryTree" << std::endl;
}

BinaryTree::~BinaryTree()
{
	deleteTree(head);
	std::cout << "析构BinaryTree" << std::endl;
}

void BinaryTree::Insert(BinaryTreeNode * node)
{
	if (head == NULL) {
		head = node;
		head->count = 1;
		head->left = NULL;
		head->right = NULL;
	}
	else {
		BinaryTreeNode* p = head;
		while (p) {
			if (p->val > node->val) {
				if (p->left == NULL) {
					p->left = node;
					p->left->count = 1;
					p->left->left = NULL;
					p->left->right = NULL;
				}
				else {
					p = p->left;
				}
			}
			else if (p->val < node->val) {
				if (p->right == NULL) {
					p->right = node;
					p->right->count = 1;
					p->right->left = NULL;
					p->right->right = NULL;
				}
				else {
					p = p->right;
				}
			}
			else {
				p->count++;
				break;
			}
		}
	}
}

void BinaryTree::pre()
{
	preTravel(head);
}

void BinaryTree::mid()
{
	midTravel(head);
}

void BinaryTree::post()
{
	postTravel(head);
}

void BinaryTree::preTravel(BinaryTreeNode* node) //前序遍历
{
	if (node != NULL) {
		std::cout << "前序遍历 ： " << node->val << " " << node->count << std::endl;
		preTravel(node->left);
		preTravel(node->right);
	}
}

void BinaryTree::midTravel(BinaryTreeNode* node) //中序遍历
{
	if (node != NULL) {
		midTravel(node->left);
		std::cout << "中序遍历 ： " << node->val << " " << node->count << std::endl;
		midTravel(node->right);
	}
}

void BinaryTree::postTravel(BinaryTreeNode* node) //后序遍历
{
	if (node != NULL) {
		postTravel(node->left);
		postTravel(node->right);
		std::cout << "后序遍历 ： " << node->val << " " << node->count << std::endl;
	}
}

void BinaryTree::deleteTree(BinaryTreeNode * node)
{
	if (node != NULL) {
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}
