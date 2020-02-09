#include<iostream>
using namespace std;

class AVLNode {
public:
	int data;
	int height;
	AVLNode* lchild;
	AVLNode* rchild;
	AVLNode(int d) :data(d), height(0), lchild(NULL), rchild(NULL) {}
};

class AVLTree {
public:
	AVLNode* root;

	AVLTree() {
	}

	AVLNode* LLRotate(AVLNode* &p) {
		//LLÐÍ²»Æ½ºâ£¬
		//Ê¹pµÄ×óº¢×ÓÎªÐÂµÄ¸ù½áµã£¬
		//p×óº¢×ÓµÄÓÒº¢×Ó³ÉÎªpµÄ×óº¢×Ó
		//p³ÉÎªp×óº¢×ÓµÄÓÒº¢×Ó£¬   

		AVLNode* lc = p->lchild;
		p->lchild = lc->rchild;
		lc->rchild = p;

		p->height = Max(getHeight(p->lchild), getHeight(p->rchild)) + 1;
		lc->height = Max(getHeight(lc->lchild), p->height) + 1;
		return lc;

	}
	AVLNode* RRRotate(AVLNode* &p) {
		//RRÐÍ²»Æ½ºâ
		//ÓëLLÏà·´
		//

		AVLNode* rc = p->rchild;
		p->rchild = rc->lchild;
		rc->lchild = p;

		p->height = Max(getHeight(p->lchild), getHeight(p->rchild)) + 1;
		rc->height = Max(getHeight(rc->rchild), p->height) + 1;
		return rc;
	}
	AVLNode* LRRotate(AVLNode* &p) {
		//LRÐÍ²»Æ½ºâ
		//p×óº¢×ÓÎªRRÐÍ²»Æ½ºâ

		p->lchild = RRRotate(p->lchild);
		p = LLRotate(p);
		return p;
	}
	AVLNode* RLRotate(AVLNode* &p) {
		//RLÐÍ²»Æ½ºâ
		//pÓÒº¢×ÓÎªLLÐÍ²»Æ½ºâ

		p->rchild = LLRotate(p->rchild);
		p = RRRotate(p);
		return p;
	}
	int getHeight(AVLNode* &p) {
		return (p == NULL) ? -1 : p->height;
	}

	int Max(int a, int b) {
		return a > b ? a : b;
	}
	AVLNode* insertNode(int e, AVLNode* &t) {
		if (!t) {
			t = new AVLNode(e);
		}
		else {
			if (e == t->data) {
			}
			if (e < t->data) {
				t->lchild = insertNode(e, t->lchild);
				if (getHeight(t->lchild) - getHeight(t->rchild) == 2) {
					if (e < t->lchild->data) {
						t = LLRotate(t);
					}
					else {
						t = LRRotate(t);
					}
				}
			}
			else {
				t->rchild = insertNode(e, t->rchild);
				if (getHeight(t->rchild) - getHeight(t->lchild) == 2) {
					if (e > t->rchild->data) {
						t = RRRotate(t);
					}
					else {
						t = RLRotate(t);
					}
				}
			}
		}
		t->height = Max(getHeight(t->lchild), getHeight(t->rchild)) + 1;
		return t;
	}

	void deleteNode(int key, bool lower, AVLNode* &t) {

	}
	void printTree(AVLNode* t) {
		if (t != NULL) {
			cout << t->data << " " << endl;
			if (t->lchild != NULL) {
				cout << " left child : " << t->lchild->data << endl;
			}
			if (t->rchild != NULL) {
				cout << "right child : " << t->rchild->data << endl;
			}
			printTree(t->lchild);
			printTree(t->rchild);
		}
	}
};

int main() {
	AVLTree* head = new AVLTree();
	int num = -1;
	while (true) {
		cin >> num;
		if (num == 0) {
			break;
		}
		head->root = head->insertNode(num, head->root);
	}
	head->printTree(head->root);
	delete head;
	system("pause");
}
