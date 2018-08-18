#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/*
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		// write your code here
		int **tag = new int*[m + 1];
		int size = V.size();
		for (int i = 0; i < m + 1; i++) {
			tag[i] = new int[size];
			tag[i][0] = 0;
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < size; j++) {
				if (A.at(j) > i) {
					if (j == 0) {
						tag[i][j] = 0;
					}
					else {
						tag[i][j] = tag[i][j - 1];
					}
				}
				else {
					if (j == 0) {
						tag[i][j] = V.at(j);
					}
					else {
						int totalValue = tag[i - A.at(j)][j - 1] + V.at(j);
						tag[i][j] = tag[i][j - 1] > totalValue ? tag[i][j - 1] : totalValue;
					}
				}
			}
		}
		for (int i = 1; i <= m;i++) {
			for (int j = 0; j < size; j++) {
				cout << tag[i][j] << " ";
			}
			cout << endl;
		}
		int value = tag[m][size-1];
		for (int i = 0; i < m + 1; i++) {
			delete[] tag[i];
		}
		delete[] tag;
		return value;
	}
};
int main() {
	Solution s;
	int m = 300;
	vector<int> a = { 95, 75, 23, 73, 50, 22, 6, 57, 89, 98 };
	vector<int> v = { 89, 59, 19, 43, 100, 72, 44, 16, 7, 64 };
	cout << s.backPackII(m, a, v) << endl;
}