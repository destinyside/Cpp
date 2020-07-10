#include<iostream>
using namespace std;

enum Color{Red,Black};

class RBTreeNode {
	public:
		Color color;
		int data;
		RBTreeNode* parent;
		RBTreeNode* left;
		RBTreeNode* right;
		RBTreeNode(int value):color(Red),data(value),parent(NULL),left(NULL),right(NULL){}
};

class RBTree {

	/*
	 * 	每个节点要么是红的，要么是黑的。
	 * 	根节点是黑的。
	 * 	每个叶节点（叶节点即指树尾端NIL指针或NULL节点）是黑的。
	 * 	如果一个节点是红的，那么它的两个儿子都是黑的。
	 * 	对于任一节点而言，其到叶节点树尾端NIL指针的每一条路径都包含相同数目的黑节点。
	 * 	*/


	public:
		RBTreeNode* head;
		RBTree() {

		}
		RBTreeNode* getParent(RBTreeNode* node) {
			return node->parent;
		}

		RBTreeNode* getUncle(RBTreeNode* node) {
			if (node->parent == getGrandParent(node)->left) {
				return getGrandParent(node)->right;
			}
			else {
				return getGrandParent(node)->left;
			}
		}

		RBTreeNode* getGrandParent(RBTreeNode* node) {
			return node->parent->parent;
		}

		void leftRotate(RBTreeNode* &node) {
			if (node != NULL) {
				RBTreeNode* rc = node->right;
				RBTreeNode* parent = node->parent;

				node->right = rc->left;
				if (rc->left != NULL) {
					rc->left->parent = node;
				}

				rc->left = node;
				node->parent = rc;

				if (parent == NULL) {
					head = rc;
					parent = head;
				}
				else if (node == parent->left) {
					parent->left = rc;
					rc->parent = parent;
				}
				else {
					parent->right = rc;
					rc->parent = parent;
				}
			}
		}

		void rightRotate(RBTreeNode* &node) {
			if (node != NULL) {
				RBTreeNode* lc = node->left;
				RBTreeNode* parent = node->parent;

				node->left = lc->right;
				if (lc->right != NULL) {
					lc->right->parent = node;
				}

				lc->right = node;
				node->parent = lc;

				if (parent == NULL) {
					head = lc;
					parent = head;
				}
				else if (node == parent->left) {
					parent->left = lc;
					lc->parent = parent;
				}
				else {
					parent->right = lc;
					lc->parent = parent;
				}
			}
		}

		void insertNode(RBTreeNode* &root, int value) {
			RBTreeNode* node = new RBTreeNode(value);
			if (root == NULL) {
				root = node;
				head = root;
			}
			else {
				RBTreeNode* tmp = root;
				while (tmp) {
					if (node->data > tmp->data) {
						if (tmp->right == NULL) {
							tmp->right = node;
							node->parent = tmp;
							break;
						}
						else {
							tmp = tmp->right;
						}
					}
					else if (node->data == tmp->data) {
						//insertCase(tmp);
					}
					else {
						if (tmp->left == NULL) {
							tmp->left = node;
							node->parent = tmp;
							break;
						}
						else {
							tmp = tmp->left;
						}
					}
				}
			}
			insertCase(node);
			root = head;
			root->color = Black;
		}

		void insertCase(RBTreeNode* &node){
			//自底向上修改颜色

			while ((node != NULL) && (node->parent != NULL) && (node->parent->color == Red)) {
				//cout << node->data << " ";
				if (node->parent == getGrandParent(node)->left) {
					if (getUncle(node) != NULL&&getUncle(node)->color == Red) {
						//红父红叔，设置父叔为黑色，设置祖父为红色
						//
						node->parent->color = Black;
						getUncle(node)->color = Black;
						getGrandParent(node)->color = Red;
						node = getGrandParent(node);
					}
					else {//红父黑叔

						if (node == node->parent->right) {
							//node节点为右子节点
							//
							node = node->parent;
							leftRotate(node);
						}
						node->parent->color = Black;
						getGrandParent(node)->color = Red;
						rightRotate(node->parent->parent);
					}
				}
				else {
					//对称
					if (getUncle(node) != NULL&&getUncle(node)->color == Red) {
						//红父红叔，设置父叔为黑色，设置祖父为红色
						node->parent->color = Black;
						getUncle(node)->color = Black;
						getGrandParent(node)->color = Red;
						node = getGrandParent(node);
					}
					else {//红父黑叔

						if (node == node->parent->left) {
							//node节点为左子节点
							//
							node = node->parent;
							rightRotate(node);
						}
						node->parent->color = Black;
						getGrandParent(node)->color = Red;
						leftRotate(node->parent->parent);
					}
				}
			}
		}

		RBTreeNode* midAfter(RBTreeNode* node) {
                    return NULL;
		}

		void deleteNode(RBTreeNode* root, int key) {

		}

		void deleteCase(RBTreeNode* &node) {

		}

		void deleteAll(RBTreeNode* node) {
			if (node != NULL) {
				deleteAll(node->left);
				deleteAll(node->right);
				delete node;
			}
		}

		void printTree(RBTreeNode* node) {
			if (node != NULL) {
				cout << node->data << " ";
				cout << node->color << endl;
				if (node->left != NULL) {
					cout << " left child : " << node->left->data << endl;
				}
				if (node->right != NULL) {
					cout << "right child : " << node->right->data << endl;
				}
				printTree(node->left);
				printTree(node->right);
			}
		}

		void prePrint(RBTreeNode* node) {
			if (node != NULL) {
				cout << node->data << " ";
				prePrint(node->left);
				prePrint(node->right);
			}
		}

		void midPrint(RBTreeNode* node) {
			if (node != NULL) {
				midPrint(node->left);
				cout << node->data << " ";
				midPrint(node->right);
			}
		}

		void postPrint(RBTreeNode* node) {
			if (node != NULL) {
				postPrint(node->left);
				postPrint(node->right);
				cout << node->data << " ";
			}
		}
};
int main() {
	/*
	 * == 原始数据: 10 40 30 60 90 70 20 50 80 
	 * == 前序遍历: 30 10 20 60 40 50 80 70 90 
	 * == 中序遍历: 10 20 30 40 50 60 70 80 90 
	 * == 后序遍历: 20 10 50 40 70 90 80 60 30 
	 * == 最小值: 10
	 * == 最大值: 90
	 * == 树的详细信息: 
	 * 30(B) is root
	 * 10(B) is 30's   left child
	 * 20(R) is 10's  right child
	 * 60(R) is 30's  right child
	 * 40(B) is 60's   left child
	 * 50(R) is 40's  right child
	 * 80(B) is 60's  right child
	 * 70(R) is 80's   left child
	 * 90(R) is 80's  right child
	 * 	*/
	RBTree* tree = new RBTree;
	RBTreeNode* root = NULL;
	tree->insertNode(root, 10);
	tree->insertNode(root, 40);
	tree->insertNode(root, 30);
	tree->insertNode(root, 60);
	tree->insertNode(root, 90);
	tree->insertNode(root, 70);
	tree->insertNode(root, 20);
	tree->insertNode(root, 50);
	tree->insertNode(root, 80);
	tree->printTree(root);
	cout << endl;
	tree->prePrint(root);
	cout << endl;
	tree->midPrint(root);
	cout << endl;
	tree->postPrint(root);
	cout << endl;
	tree->deleteAll(root);
	delete tree;
	system("pause");
}
