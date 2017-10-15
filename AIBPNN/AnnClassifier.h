#pragma once
#include "Neuron.h"
#include "DataNode.h"
#include<vector>

class AnnClassifier {
	int inputCount;
	int hiddenCount;
	int outputCount;

	vector<Neuron*> inputNodes;
	vector<Neuron*> hiddenNodes;
	vector<Neuron*> outputNodes;

	double** inputHiddenWeight;
	double** hiddenOutputWeight;

	vector<DataNode> trainNodes;
	
public:
	AnnClassifier(int inputCount, int hiddenCount, int outputCount);
	~AnnClassifier();
	void setTrainNodes(vector<DataNode> nodes);
	void train(double eta, int n);
	int test(DataNode dn);
private:
	void updateWeights(double eta);
	void forward(vector<double> lst);
	void backward(int type);
	void reset();
	
};