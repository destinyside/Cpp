#include "DataNode.h"

DataNode::DataNode()
{
	this->attrList.clear();
}

DataNode::DataNode(double A, double B, double C, double D, int type)
{
	attrList.push_back(A);
	attrList.push_back(B);
	attrList.push_back(C);
	attrList.push_back(D);
	this->type = type;
}

int DataNode::getType()
{
	return this->type;
}

void DataNode::setType(int type)
{
	this->type = type;
}

vector<double> DataNode::getAttrList()
{
	return this->attrList;
}

void DataNode::addAttr(double attr)
{
	this->attrList.push_back(attr);
}
