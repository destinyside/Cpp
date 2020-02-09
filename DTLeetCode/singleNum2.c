#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int txor(int a, int b, int c){

}

int singleNumber(int* nums, int numsSize){
	int temp = 0, result = 0;
	for(int i=0; i<numsSize; i++){
		result = (result ^ nums[i]) & ~temp;
		temp = (temp ^ nums[i]) & ~result;
	}
	return result;
}


int main(int argc, char* argv[]){
	int* digits;
	int nums = 10;
	if(argc > 1){
		nums = argc - 1;
	}
	digits = malloc(sizeof(int) * nums);
	if(argc > 1){
		for(int i=0; i<nums; i++){
			*(digits+i) = atoi(argv[i+1]);
		}
	} else {
		srand((unsigned)time(0));
		for(int i=0; i<nums; i+=2){
			int bit = rand() % 10;
			*(digits+i) = bit;
			*(digits+i+1) = bit;
		}
	}
	for(int i=0; i<nums; i++){
		printf("%d ", *(digits+i));
	}
	printf("\n");
	int result = singleNumber(digits, nums);
	printf("%d \n", result);
	return 0;
}
