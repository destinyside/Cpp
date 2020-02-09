#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int* result = malloc(sizeof (int) * (digitsSize + 1));
	int over = 0;
	for (int i = digitsSize - 1; i >= 0; i--) {
		if (digits[i] == 9) {
			result[i + 1] = 0;
			if (i == 0) {
				over = 1;
				result[0] = 1;
			}
		} else {
			result[i + 1] = digits[i] + 1;
			printf("i %d\n", i);
			while (i-- > 0) {
			printf("i %d\n", i);
				result[i + 1] = digits[i];
			}
		}
	}
	*returnSize = over == 1 ? (digitsSize + 1) : digitsSize;
	return over == 1 ? result : ++result;
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
		for(int i=0; i<nums; i++){
			*(digits+i) = rand() % 10;
		}
	}
	for(int i=0; i<nums; i++){
		printf("%d ", *(digits+i));
	}
	printf("\n");
	int returnSize = 0;
	int* returns = plusOne(digits, nums, &returnSize);
	printf("%d \n", returnSize);
	for(int i=0; i<returnSize; i++){
		printf("%d ", *(returns+i));
	}
	printf("\n");
	return 0;
}
