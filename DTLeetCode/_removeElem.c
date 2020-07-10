#include<stdio.h>

int removeElement(int* nums, int numsSize, int val){
	for(int i=0,j=numsSize; i<numsSize; i++){
		if(nums[i]==val){
			int s = nums[i];

		}
	}
}

int* randomArray(int len) {

	srand((unsigned)time(0));
	int* tmp = malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++) {
		tmp[i] = rand() % len + 1;
	}
	return tmp;
}

int main(int argc,char* argv[]){
	int len=0;
	int* arr;
	if(argc > 1){
		len = argc - 1;
		arr = malloc(sizeof(int)*len);
		for(int i=0; i<len; i++){
			arr[i] = atoi(argv[i+1]);
		}
	} else {
		len = 20;
		arr = randomArray(len);
	}
	int m = rand()%10;
	int len = removeElement(arr,len,m);
	for(int i=0; i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
