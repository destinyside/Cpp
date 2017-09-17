#include<iostream>
using namespace std;
void moveZeros(int* nums, int numsSize);
int main() {
	int nums[] = { 0,0,1};
	int numsSize = sizeof(nums) / sizeof(int);
	moveZeros(nums, numsSize);
	std::cout << "Nums:" << std::endl; 
	for (int i = 0; i < numsSize; i++) {
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
}

void moveZeros(int* nums, int numsSize) {
	int i = 0;
	int j = numsSize - 1;
	while (i <= j) {
		if (nums[i] == 0) {
			for (int k = i; k < j; k++) {
				nums[k] = nums[k + 1];
			}
			nums[j] = 0;
			j--;
		}
		if (nums[i] != 0) {
			i++;
		}
	}
}