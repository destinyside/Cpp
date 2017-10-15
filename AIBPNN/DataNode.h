#pragma once
#include<vector>
#include<iostream>
using namespace std;
class DataNode {
	vector<double> attrList;
	int type;
public:
	DataNode();
	DataNode(double A, double B, double C, double D, int type);
	int getType();
	void setType(int type);
	vector<double> getAttrList();
	void addAttr(double attr);
};