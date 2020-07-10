#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
bool isSelfDivNum(int num){
	if(num<10){
		return true;
	} else if(num%10==0){
		return false;
	} else {
		bool t = true;
		int n = num;
		while(n > 0){
			if(n%10==0){
				return false;
			}
			t = t && (num % (n % 10) == 0);
			n /= 10;
		}
		return t;
	}
}
int* selfDividingNumbers(int left, int right, int* returnSize){
	int arr[10000] = {0};
	int j=0;
	for(int i=left; i<=right; i++){
		if(isSelfDivNum(i)){
			arr[j++] = i;
		}
	}
	*returnSize = j;
	int* p = arr;
	return p;
}

int main(int argc, char* argv[]){
	int left = 1;
	int right = 30;
	if(argc > 2){
		left = atoi(argv[1]);
		right = atoi(argv[2]);
	}
	int* r = malloc(sizeof(int));
	int* arr = selfDividingNumbers(left, right, r);
	for(int i=0; i<*r; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	free(r);
	return EXIT_SUCCESS;
}
