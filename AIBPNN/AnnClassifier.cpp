#include "AnnClassifier.h"

AnnClassifier::AnnClassifier(int inputCount, int hiddenCount, int outputCount)
{
	this->inputCount = inputCount;
	this->hiddenCount = hiddenCount;
	this->outputCount = outputCount;
	
	inputHiddenWeight = new double*[inputCount];
	for (int i = 0; i < inputCount; i++) {
		inputHiddenWeight[i] = new double[hiddenCount];
	}
	hiddenOutputWeight = new double*[hiddenCount];
	for (int i = 0; i < hiddenCount; i++) {
		hiddenOutputWeight[i] = new double[outputCount];
	}
}

AnnClassifier::~AnnClassifier()
{
	for (int i = 0; i < inputCount; i++) {
		delete[] inputHiddenWeight[i];
	}
	for (int i = 0; i < hiddenCount; i++) {
		delete[] hiddenOutputWeight[i];
	}
}

void AnnClassifier::setTrainNodes(vector<DataNode> nodes)
{
	this->trainNodes = nodes;
}

void AnnClassifier::train(double eta, int n)
{
	reset();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < trainNodes.size(); j++)
		{
			forward(trainNodes.at(j).getAttrList());
			backward(trainNodes.at(j).getType());
			updateWeights(eta);
		}
		cout << "n = " << i << endl;

	}
}

int AnnClassifier::test(DataNode dn)
{
	forward(dn.getAttrList());
	double result = 2;
	int type = 0;
	// 取最接近1的
	for (int i = 0; i < outputCount; i++)
		if ((1 - outputNodes.at(i)->getForwardOutputValue()) < result)
		{
			result = 1 - outputNodes.at(i)->getForwardOutputValue();
			type = i;
		}
	return type;
}

void AnnClassifier::updateWeights(double eta)
{
	for (int i = 0; i < inputCount; i++) {
		for (int j = 0; j < hiddenCount; j++) {
			inputHiddenWeight[i][j] -= eta
				* inputNodes.at(i)->getForwardOutputValue()
				* hiddenNodes.at(j)->getBackwardOutputValue();
		}
	}
	for (int i = 0; i < hiddenCount; i++) {
		for (int j = 0; j < outputCount; j++) {
			hiddenOutputWeight[i][j] -= eta
				* hiddenNodes.at(i)->getForwardOutputValue()
				* outputNodes.at(j)->getBackwardOutputValue();
		}
	}
}

void AnnClassifier::forward(vector<double> lst)
{
	//
	for (int i = 0; i < lst.size(); i++) {
		inputNodes.at(i)->setForwardInputValue(lst.at(i));
	}
	//
	for (int i = 0; i < hiddenCount; i++) {
		double tmp = 0;
		for (int j = 0; j < inputCount; j++) {
			tmp += inputHiddenWeight[j][i] * inputNodes.at(j)->getForwardOutputValue();
		}
		hiddenNodes.at(i)->setForwardInputValue(tmp);
	}
	//
	for (int i = 0; i < outputCount; i++) {
		double tmp = 0;
		for (int j = 0; j < hiddenCount; j++) {
			tmp += hiddenOutputWeight[j][i] * hiddenNodes.at(j)->getForwardOutputValue();
		}
		outputNodes.at(i)->setForwardInputValue(tmp);
	}
}

void AnnClassifier::backward(int type)
{
	// 输出层
	for (int j = 0; j < outputCount; j++)
	{
		// 输出层计算误差把误差反向传播，这里-1代表不属于，1代表属于
		double result = -1;
		if (j == type)
			result = 1;
		outputNodes.at(j)->setBackwardInputValue(
			outputNodes.at(j)->getForwardOutputValue() - result);
	}
	// 隐层
	for (int j = 0; j < hiddenCount; j++)
	{
		double temp = 0;
		for (int k = 0; k < outputCount; k++)
			temp += hiddenOutputWeight[j][k]
			* outputNodes.at(k)->getBackwardOutputValue();
		hiddenNodes.at(j)->setBackwardInputValue(temp);
	}

}

void AnnClassifier::reset()
{
	//list<Neuron*>::iterator iter = inputNodes.begin();

	for each (Neuron* n in inputNodes)
	{
		delete n;
	}
	for each (Neuron* n in hiddenNodes)
	{
		delete n;
	}
	for each (Neuron* n in outputNodes)
	{
		delete n;
	}

	inputNodes.clear();
	hiddenNodes.clear();
	outputNodes.clear();

	for (int i = 0; i < inputCount; i++) {
		inputNodes.push_back(new Neuron(Node_Input));
	}
	for (int i = 0; i < hiddenCount; i++) {
		hiddenNodes.push_back(new Neuron(Node_Hidden));
	}
	for (int i = 0; i < outputCount; i++) {
		outputNodes.push_back(new Neuron(Node_Output));
	}
	for (int i = 0; i < inputCount; i++) {
		for (int j = 0; j < hiddenCount; j++) {
			inputHiddenWeight[i][j] = (double)(rand() % 10)*0.1;
		}
	}
	for (int i = 0; i < hiddenCount; i++) {
		for (int j = 0; j < outputCount; j++) {
			hiddenOutputWeight[i][j] = (double)(rand() % 10)*0.1;
		}
	}
}
