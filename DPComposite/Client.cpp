#include<iostream>
#include "Component.h"
#include "Composite.h"
#include "Leaf.h"
using namespace std;
int main() {
	///////组合模式
	Component* root = new Composite("根");
	Component* c1 = new Composite("一层的根");
	root->Add(new Leaf("一层的叶子"));
	root->Add(c1);
	c1->Add(new Leaf("二层的叶子1"));
	c1->Add(new Leaf("二层的叶子2"));
	root->Operation();
	delete root;
	system("pause");
}