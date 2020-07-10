#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<time.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	for(int i=0; i<numsSize; i++){
		int sub = target - nums[i];
		if(sub>0){
			for(int j=0; j!=i&&j<numsSize;j++){
				if(nums[j]==sub){
					*returnSize = 2;
					int r[2];
					r[0]=nums[i];
					r[1]=nums[j];
					int* p=r;
					return p;
				}
			}
		}
	}
	returnSize = 0;
	return NULL;
}

void printArr(int* nums, int numsSize){
	for(int i=0; i<numsSize; i++){
		printf("%d ",nums[i]);
	}
	printf("\n");
}

int* randomArray(int len) {
	srand((unsigned)time(0));
	int* tmp = malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++) {
		tmp[i] = rand() % len +
			1;
	}
	return tmp;
}

int main(int argc, char* argv[]){
	int len = 10;
	if(argc > 1){
		len = atoi(argv[1]);
	}
	int* arr;
	if(argc > 2){
		len = argc-1;
		arr = malloc(sizeof(int)*len);
		for(int i=0; i<len; i++){
			arr[i]=atoi(argv[i+1]);
		}
	} else {
		arr = randomArray(len);
	}
	printArr(arr,len);
	int target = rand()%(2*len);
	printf("target: %d\n", target);
	int* s = malloc(sizeof(int)*1);
	int* r = twoSum(arr,len,target,s);
	printArr(arr,len);
	printArr(r,*s);
	free(arr);
	free(s);
	return EXIT_SUCCESS;
}
