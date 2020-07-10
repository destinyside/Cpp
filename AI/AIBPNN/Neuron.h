#pragma once
#include<math.h>
#include<iostream>
using namespace std;
enum NodeType {
	Node_Input,
	Node_Hidden,
	Node_Output
};
class Neuron {
	//结点类型
	NodeType type;
	
	//结点向前输出值
	double forwardInputValue;
	double forwardOutputValue;
	//结点向后输出值
	double backwardInputValue;
	double backwardOutputValue;
public:
	Neuron();
	Neuron(NodeType type);

	void setType(NodeType type);

	//get/set
	double getForwardInputValue();
	void setForwardInputValue(double inputValue);
	double getForwardOutputValue();
	
	double getBackwardInputValue();
	void setBackwardInputValue(double backwardInputValue);
	double getBackwardOutputValue();
	
private:
	void setForwardOutputValue(double inputValue);
	void setBackwardOutputValue(double backwardInputValue);

	double tanhS(double in);
	//sigmoid 函数
	double forwardSigmoid(double in);

	double tanhSDerivative(double in);
	//误差反向传播，激活函数的导数
	double backwardPropagate(double in);


};
