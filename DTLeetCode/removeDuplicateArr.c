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

int removeDuplicates1(int* nums, int numsSize){
	int i=0;
	for(int j=1; j<numsSize; j++){
		if(nums[j]!=nums[i]){
			i++;
			nums[i]=nums[j];
		}
	}
	return i+1;
}

int removeDuplicates(int* nums, int numsSize){
	int i = numsSize - 1;
	int len = numsSize;
	while(i > 0){
		if(nums[i]==nums[i-1]){
			for(int j=i; j<len-1; j++){
				nums[j] = nums[j+1];
			}
			len--;
		}
		i--;
	}
	return len;
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

int comp(const void* a, const void* b){
	if(*(int*)a < *(int*)b){
		return -1;
	} else if(*(int*)a > *(int*)b){
		return 1;
	} else {
		return 0;
	}
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
	qsort(arr, len, sizeof(int), comp);
	printArr(arr,len);
	len = removeDuplicates1(arr,len);
	printArr(arr,len);
	free(arr);
	return EXIT_SUCCESS;
}
