#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int maxSubArray(int* nums, int numsSize){
    int max = INT_MIN;
	int sum = 0;
    for(int i=0; i<numsSize; i++){
        sum+=nums[i];
		if(sum>max){
			max = sum;
		}
        if(sum<0){
			sum = 0;
		}
    }
    return max;
}

void printArr(int* nums, int numsSize){
        for(int i=0; i<numsSize; i++){
                printf("%d ",nums[i]);
        }
        printf("\n");
}

int* randomArr(int len) {
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
	int* arr = randomArr(len);
	printArr(arr, len);
	printf("max sub arr : %d\n", maxSubArray(arr, len));
	return EXIT_SUCCESS;
}
