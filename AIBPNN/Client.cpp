#include<iostream>
#include<stdlib.h>
#include<vector>
#include<fstream>
#include<sstream>
#include "AnnClassifier.h"
#include "DataNode.h"
using namespace std;
enum Iris{
	Iris_versicolor,
	Iris_setosa,
	Iris_virginica
};
vector<DataNode> initTrain();
vector<DataNode> initTest();

int main() {
	//²Î¿¼²©¿Í£ºhttp://blog.csdn.net/zhongkejingwang/article/details/44514073
	
	int typeCount = 3;
	double eta = 0.02f;
	int nIter = 1000;
	vector<DataNode> trainList = initTrain();
	vector<DataNode> testList = initTest();
	AnnClassifier* annClassifier = new AnnClassifier(
		trainList.at(0).getAttrList().size(), 
		trainList.at(0).getAttrList().size() + 8, 
		typeCount
	);
	annClassifier->setTrainNodes(trainList);
	annClassifier->train(eta, nIter);
	double rightCount = 0;
	for (int i = 0; i < testList.size(); i++)
	{
		DataNode test = testList.at(i);
		int type = annClassifier->test(test);
		vector<double> attribs = test.getAttrList();
		for (int n = 0; n < attribs.size(); n++)
		{
			cout << attribs.at(n) << ",";
		}
		if (type == testList.at(i).getType()) {
			rightCount++;
		}
		switch (type) {
		case 0: {
			cout << "Iris_versicolor" << endl;
			break;
		}

		case 1: {
			cout << "Iris_setosa" << endl;
			break;
		}
		case 2:
		{
			cout << "Iris_virginica" << endl;
			break;
		}
		default: {
			break;
		}
		}
	}
	cout << "[" << rightCount / testList.size() << "]" << endl;
	delete annClassifier;
	
	system("pause");
}

vector<DataNode> initTrain() {
	vector<DataNode> tmp;
	
	tmp.push_back(DataNode(6.1, 2.8, 4.7, 1.2, Iris_versicolor));
	tmp.push_back(DataNode(5.5, 2.4, 3.8, 1.1, Iris_versicolor));
	tmp.push_back(DataNode(5.1, 3.5, 1.4, 0.3, Iris_setosa));
	tmp.push_back(DataNode(6.7, 3.1, 5.6, 2.4, Iris_virginica));
	tmp.push_back(DataNode(5.4, 3.4, 1.7, 0.2, Iris_setosa));
	tmp.push_back(DataNode(6.9, 3.1, 5.1, 2.3, Iris_virginica));
	tmp.push_back(DataNode(6.7, 3.0, 5.2, 2.3, Iris_virginica));
	tmp.push_back(DataNode(5.7, 3.0, 4.2, 1.2, Iris_versicolor));
	tmp.push_back(DataNode(6.3, 2.5, 4.9, 1.5, Iris_versicolor));
	tmp.push_back(DataNode(6.3, 2.3, 4.4, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(5.6, 2.5, 3.9, 1.1, Iris_versicolor));
	tmp.push_back(DataNode(6.9, 3.2, 5.7, 2.3, Iris_virginica));
	tmp.push_back(DataNode(6.1, 2.8, 4.0, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(7.2, 3.6, 6.1, 2.5, Iris_virginica));
	tmp.push_back(DataNode(6.4, 2.8, 5.6, 2.1, Iris_virginica));
	tmp.push_back(DataNode(6.1, 2.9, 4.7, 1.4, Iris_versicolor));
	tmp.push_back(DataNode(6.1, 3.0, 4.9, 1.8, Iris_virginica));
	tmp.push_back(DataNode(6.7, 3.3, 5.7, 2.5, Iris_virginica));
	tmp.push_back(DataNode(5.4, 3.7, 1.5, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.7, 4.4, 1.5, 0.4, Iris_setosa));
	tmp.push_back(DataNode(6.3, 3.3, 6.0, 2.5, Iris_virginica));
	tmp.push_back(DataNode(5.0, 3.6, 1.4, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.1, 3.4, 1.5, 0.2, Iris_setosa));
	tmp.push_back(DataNode(4.6, 3.6, 1.0, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.5, 2.6, 4.4, 1.2, Iris_versicolor));
	tmp.push_back(DataNode(4.9, 3.0, 1.4, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.9, 3.0, 4.2, 1.5, Iris_versicolor));
	tmp.push_back(DataNode(6.7, 3.0, 5.0, 1.7, Iris_versicolor));
	tmp.push_back(DataNode(5.4, 3.9, 1.7, 0.4, Iris_setosa));
	tmp.push_back(DataNode(6.4, 3.2, 4.5, 1.5, Iris_versicolor));
	tmp.push_back(DataNode(7.0, 3.2, 4.7, 1.4, Iris_versicolor));
	tmp.push_back(DataNode(5.7, 2.8, 4.1, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(6.2, 2.2, 4.5, 1.5, Iris_versicolor));
	tmp.push_back(DataNode(6.2, 2.9, 4.3, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(4.8, 3.0, 1.4, 0.3, Iris_setosa));
	tmp.push_back(DataNode(5.1, 2.5, 3.0, 1.1, Iris_versicolor));
	tmp.push_back(DataNode(6.1, 2.6, 5.6, 1.4, Iris_virginica));
	tmp.push_back(DataNode(5.5, 4.2, 1.4, 0.2, Iris_setosa));
	tmp.push_back(DataNode(4.9, 2.5, 4.5, 1.7, Iris_virginica));
	tmp.push_back(DataNode(5.5, 2.3, 4.0, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(5.0, 2.3, 3.3, 1.0, Iris_versicolor));
	tmp.push_back(DataNode(7.3, 2.9, 6.3, 1.8, Iris_virginica));
	tmp.push_back(DataNode(7.2, 3.0, 5.8, 1.6, Iris_virginica));
	tmp.push_back(DataNode(5.4, 3.0, 4.5, 1.5, Iris_versicolor));
	tmp.push_back(DataNode(6.4, 3.1, 5.5, 1.8, Iris_virginica));
	tmp.push_back(DataNode(5.7, 2.5, 5.0, 2.0, Iris_virginica));
	tmp.push_back(DataNode(5.2, 3.5, 1.5, 0.2, Iris_setosa));
	tmp.push_back(DataNode(6.3, 2.9, 5.6, 1.8, Iris_virginica));
	tmp.push_back(DataNode(6.3, 3.3, 4.7, 1.6, Iris_versicolor));
	tmp.push_back(DataNode(4.4, 3.2, 1.3, 0.2, Iris_setosa));
	tmp.push_back(DataNode(6.3, 2.8, 5.1, 1.5, Iris_virginica));
	tmp.push_back(DataNode(7.2, 3.2, 6.0, 1.8, Iris_virginica));
	tmp.push_back(DataNode(6.5, 2.8, 4.6, 1.5, Iris_versicolor));
	tmp.push_back(DataNode(4.6, 3.2, 1.4, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.0, 2.0, 3.5, 1.0, Iris_versicolor));
	tmp.push_back(DataNode(7.7, 3.8, 6.7, 2.2, Iris_virginica));
	tmp.push_back(DataNode(5.7, 2.6, 3.5, 1.0, Iris_versicolor));
	tmp.push_back(DataNode(6.7, 3.1, 4.4, 1.4, Iris_versicolor));
	tmp.push_back(DataNode(5.6, 3.0, 4.1, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(7.6, 3.0, 6.6, 2.1, Iris_virginica));
	tmp.push_back(DataNode(5.1, 3.8, 1.6, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.5, 3.5, 1.3, 0.2, Iris_setosa));
	tmp.push_back(DataNode(4.4, 2.9, 1.4, 0.2, Iris_setosa));
	tmp.push_back(DataNode(6.2, 2.8, 4.8, 1.8, Iris_virginica));
	tmp.push_back(DataNode(5.9, 3.0, 5.1, 1.8, Iris_virginica));
	tmp.push_back(DataNode(6.5, 3.2, 5.1, 2.0, Iris_virginica));
	tmp.push_back(DataNode(6.3, 2.7, 4.9, 1.8, Iris_virginica));
	tmp.push_back(DataNode(4.9, 3.1, 1.5, 0.1, Iris_setosa));
	tmp.push_back(DataNode(6.0, 3.4, 4.5, 1.6, Iris_versicolor));
	tmp.push_back(DataNode(4.9, 2.4, 3.3, 1.0, Iris_versicolor));
	tmp.push_back(DataNode(5.4, 3.4, 1.5, 0.4, Iris_setosa));
	tmp.push_back(DataNode(6.5, 3.0, 5.8, 2.2, Iris_virginica));
	tmp.push_back(DataNode(5.7, 2.8, 4.5, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(7.1, 3.0, 5.9, 2.1, Iris_virginica));
	tmp.push_back(DataNode(5.8, 2.7, 5.1, 1.9, Iris_virginica));
	tmp.push_back(DataNode(5.1, 3.8, 1.5, 0.3, Iris_setosa));
	tmp.push_back(DataNode(6.5, 3.0, 5.2, 2.0, Iris_virginica));
	tmp.push_back(DataNode(5.8, 2.7, 4.1, 1.0, Iris_versicolor));
	tmp.push_back(DataNode(5.6, 2.8, 4.9, 2.0, Iris_virginica));
	tmp.push_back(DataNode(6.9, 3.1, 5.4, 2.1, Iris_virginica));
	tmp.push_back(DataNode(5.0, 3.0, 1.6, 0.2, Iris_setosa));
	tmp.push_back(DataNode(6.0, 2.9, 4.5, 1.5, Iris_versicolor));
	tmp.push_back(DataNode(5.0, 3.4, 1.5, 0.2, Iris_setosa));
	tmp.push_back(DataNode(6.7, 3.1, 4.7, 1.5, Iris_versicolor));
	tmp.push_back(DataNode(5.8, 2.8, 5.1, 2.4, Iris_virginica));
	tmp.push_back(DataNode(4.8, 3.4, 1.9, 0.2, Iris_setosa));
	tmp.push_back(DataNode(7.7, 3.0, 6.1, 2.3, Iris_virginica));
	tmp.push_back(DataNode(6.8, 3.0, 5.5, 2.1, Iris_virginica));
	tmp.push_back(DataNode(6.0, 3.0, 4.8, 1.8, Iris_virginica));
	tmp.push_back(DataNode(7.4, 2.8, 6.1, 1.9, Iris_virginica));
	tmp.push_back(DataNode(4.9, 3.1, 1.5, 0.1, Iris_setosa));
	tmp.push_back(DataNode(5.2, 3.4, 1.4, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.9, 3.2, 4.8, 1.8, Iris_versicolor));
	tmp.push_back(DataNode(6.7, 2.5, 5.8, 1.8, Iris_virginica));
	tmp.push_back(DataNode(7.9, 3.8, 6.4, 2.0, Iris_virginica));
	tmp.push_back(DataNode(4.7, 3.2, 1.3, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.8, 4.0, 1.2, 0.2, Iris_setosa));
	tmp.push_back(DataNode(6.8, 3.2, 5.9, 2.3, Iris_virginica));
	tmp.push_back(DataNode(6.0, 2.2, 5.0, 1.5, Iris_virginica));
	tmp.push_back(DataNode(5.8, 2.6, 4.0, 1.2, Iris_versicolor));
	tmp.push_back(DataNode(5.1, 3.3, 1.7, 0.5, Iris_setosa));
	tmp.push_back(DataNode(6.9, 3.1, 4.9, 1.5, Iris_versicolor));
	tmp.push_back(DataNode(5.8, 2.7, 5.1, 1.9, Iris_virginica));
	tmp.push_back(DataNode(5.6, 2.9, 3.6, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(4.9, 3.1, 1.5, 0.1, Iris_setosa));
	tmp.push_back(DataNode(6.4, 2.7, 5.3, 1.9, Iris_virginica));
	tmp.push_back(DataNode(5.2, 4.1, 1.5, 0.1, Iris_setosa));
	tmp.push_back(DataNode(5.0, 3.5, 1.6, 0.6, Iris_setosa));
	tmp.push_back(DataNode(6.3, 3.4, 5.6, 2.4, Iris_virginica));
	tmp.push_back(DataNode(6.6, 3.0, 4.4, 1.4, Iris_versicolor));
	tmp.push_back(DataNode(6.4, 2.9, 4.3, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(5.1, 3.5, 1.4, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.1, 3.8, 1.9, 0.4, Iris_setosa));
	tmp.push_back(DataNode(6.3, 2.5, 5.0, 1.9, Iris_virginica));
	tmp.push_back(DataNode(6.8, 2.8, 4.8, 1.4, Iris_versicolor));
	tmp.push_back(DataNode(6.2, 3.4, 5.4, 2.3, Iris_virginica));
	tmp.push_back(DataNode(4.7, 3.2, 1.6, 0.2, Iris_setosa));
	tmp.push_back(DataNode(6.4, 2.8, 5.6, 2.2, Iris_virginica));
	tmp.push_back(DataNode(4.6, 3.1, 1.5, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.7, 3.8, 1.7, 0.3, Iris_setosa));
	tmp.push_back(DataNode(6.5, 3.0, 5.5, 1.8, Iris_virginica));
	tmp.push_back(DataNode(5.3, 3.7, 1.5, 0.2, Iris_setosa));
	tmp.push_back(DataNode(4.6, 3.4, 1.4, 0.3, Iris_setosa));
	tmp.push_back(DataNode(4.8, 3.0, 1.4, 0.1, Iris_setosa));
	return tmp;
}

vector<DataNode> initTest()
{
	vector<DataNode> tmp;
	tmp.push_back(DataNode(6.7, 3.3, 5.7, 2.1, Iris_virginica));
	tmp.push_back(DataNode(6.4, 3.2, 5.3, 2.3, Iris_virginica));
	tmp.push_back(DataNode(4.4, 3.0, 1.3, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.0, 3.5, 1.3, 0.3, Iris_setosa));
	tmp.push_back(DataNode(5.0, 3.4, 1.6, 0.4, Iris_setosa));
	tmp.push_back(DataNode(5.4, 3.9, 1.3, 0.4, Iris_setosa));
	tmp.push_back(DataNode(4.8, 3.1, 1.6, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.8, 2.7, 3.9, 1.2, Iris_versicolor));
	tmp.push_back(DataNode(7.7, 2.8, 6.7, 2.0, Iris_virginica));
	tmp.push_back(DataNode(4.3, 3.0, 1.1, 0.1, Iris_setosa));
	tmp.push_back(DataNode(5.0, 3.3, 1.4, 0.2, Iris_setosa));
	tmp.push_back(DataNode(6.6, 2.9, 4.6, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(7.7, 2.6, 6.9, 2.3, Iris_virginica));
	tmp.push_back(DataNode(5.2, 2.7, 3.9, 1.4, Iris_versicolor));
	tmp.push_back(DataNode(4.5, 2.3, 1.3, 0.3, Iris_setosa));
	tmp.push_back(DataNode(5.7, 2.9, 4.2, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(5.5, 2.5, 4.0, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(5.1, 3.7, 1.5, 0.4, Iris_setosa));
	tmp.push_back(DataNode(6.1, 3.0, 4.6, 1.4, Iris_versicolor));
	tmp.push_back(DataNode(5.6, 3.0, 4.5, 1.5, Iris_versicolor));
	tmp.push_back(DataNode(6.0, 2.7, 5.1, 1.6, Iris_versicolor));
	tmp.push_back(DataNode(5.6, 2.7, 4.2, 1.3, Iris_versicolor));
	tmp.push_back(DataNode(5.0, 3.2, 1.2, 0.2, Iris_setosa));
	tmp.push_back(DataNode(5.5, 2.4, 3.7, 1.0, Iris_versicolor));
	tmp.push_back(DataNode(4.8, 3.4, 1.6, 0.2, Iris_setosa));
	tmp.push_back(DataNode(6.0, 2.2, 4.0, 1.0, Iris_versicolor));
	return tmp;
}
