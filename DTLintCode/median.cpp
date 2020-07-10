#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/*
	* @param nums: A list of integers
	* @return: An integer denotes the middle number of the array
	*/
	int median(vector<int> &nums) {
		// write your code here
		sort(nums.begin(), nums.end());
		int size = nums.size();
		return nums.at(size % 2 == 0 ? ((size / 2) - 1) : size / 2);
	}
};
//int main() {
//	Solution s;
//	vector<int> nums = { 7,9,4,5};
//	cout << s.median(nums)<<endl;
//}