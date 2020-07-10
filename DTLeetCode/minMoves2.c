#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<time.h>

void printArr(int* nums, int numsSize){
	for(int i=0; i<numsSize; i++){
		printf("%d ",nums[i]);
	}
	printf("\n");
}

bool checkEqual(int* nums, int numsSize){
	int n = nums[0];
	bool eql = true;
	for(int i=1; i<numsSize; i++){
		if(nums[i]!=n){
			eql=false;
			break;
		}
	}
	return eql;
}

void addNum(int* nums, int numsSize, int max, int moves){
	int cnt = 0;
	for(int i=0; i<numsSize; i++){
		if(nums[i]==max && cnt==0){
			cnt++;
			continue;
		}
		nums[i]+=moves;
	}
}

int minMoves(int* nums, int numsSize){
	int moves = 0;
	int* p = nums;
	while(!checkEqual(p,numsSize)){
		int max = INT_MIN;
		int min = INT_MAX;
		for(int i=0; i<numsSize; i++){
			if(nums[i]<min){
				min = nums[i];
			}
			if(nums[i]>max){
				max = nums[i];
			}
		}
		for(int i=0; i<numsSize; i++){
			moves += nums[i]-min;
		}
		//return moves;
		moves+=max-min;
		addNum(p,numsSize,max,max-min);
		printf("%d ", moves);
		//printArr(p,numsSize);
		//moves++;
	}
	return moves;
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
	int moves = minMoves(arr,len);
	printArr(arr,len);
	printf("\nmoves: %d\n", moves);
	free(arr);
	return EXIT_SUCCESS;
}
