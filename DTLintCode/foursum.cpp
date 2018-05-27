#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/*
	* @param numbers: Give an array
	* @param target: An integer
	* @return: Find all unique quadruplets in the array which gives the sum of zero
	*/
	vector<vector<int>> fourSum(vector<int> numbers, int target) {
		// write your code here
		vector<vector<int>> answers;
		sort(numbers.begin(), numbers.end());
		int len = numbers.size();
		for (int a = 0; a < len - 3; a++) {
			if (a && numbers.at(a) == numbers.at(a - 1)) {
				continue;
			}
			for (int b = a + 1; b < len - 2; b++) {
				if (b != a + 1 && numbers.at(b) == numbers.at(b - 1)) {
					continue;
				}
				int sum = target - numbers.at(a) - numbers.at(b);
				int c = b + 1;
				int d = len - 1;
				while (c < d) {
					if ((numbers.at(c) + numbers.at(d)) == sum) {
						vector<int> tmp = { numbers.at(a) , numbers.at(b) , numbers.at(c) , numbers.at(d) };
						
						if (find(answers.begin(), answers.end(), tmp) == answers.end()) {
							sort(tmp.begin(), tmp.end());
							answers.push_back(tmp);
						}
						c++;
						d--;
						while (c < d&&numbers.at(c) == numbers.at(c - 1)) {
							c++;
						}
						while (c < d&&numbers.at(d) == numbers.at(d + 1)) {
							d--;
						}
					}
					else {
						if ((numbers.at(c) + numbers.at(d)) > sum) {
							d--;
						}
						else {
							c++;
						}
					}
				}
			}
		}
		return answers;
	}
};

//int main() {
//	Solution s;
//	vector<int> numbers = { -2,-3,5,-1,-4,5,-11,7,1,2,3,4,-7,-1,-2,-3,-4,-5 };
//	int target;
//	cin >> target;
//	vector<vector<int>> answers = s.fourSum(numbers, target);
//	for (vector<int> solve : answers) {
//		for (int a : solve) {
//			cout << a << " ";
//		}
//		cout << endl;
//	}
//	
//}