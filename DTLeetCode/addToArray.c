#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* intrev(int* src, int slen){
	int* dst = src;
	int left = 0;
	int right = slen - 1;
	while(left <= right){
		int tmp = src[left];
		src[left] = src[right];
		src[right] = tmp;
		left++;
		right--;
	}
	return dst;
}

int* addToArrayForm(int* digits, int digitsSize,int num, int* returnSize){
	if(num == 0){
		int* result = malloc(sizeof(int) * (digitsSize));
		for(int i=0; i<digitsSize; i++){
			*(result+i) = *(digits+i);
		}
		return result;
	}
	int result[10005];
	//int* result = malloc(sizeof(int) * (digitsSize + 5));
	int carry = 0;
	int cnt = 0;
	int i = digitsSize - 1;
	while(i >= 0 || num > 0){
		int bit1 = 0;
		if(i >= 0){
			bit1 = digits[i--];
		}
		int bit2 = 0;
		if(num != 0){
			bit2 = num % 10;
			num /= 10;
		}
		int bit = (bit1 + bit2) % 10 + carry;
		carry = (bit1 + bit2) / 10;
		if(bit >= 10){
			carry++;
			bit = bit % 10;
		}
		printf("%d %d %d %d\n", bit1, bit2, bit, carry);
		result[cnt++] = bit;

	}
	if(carry > 0){
		result[cnt++] = carry;
	}
	*returnSize = cnt;
	int* temp = result;
	intrev(temp, cnt);
	return temp;
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
	int num = 0;//rand() % 1000;
	int* returns = addToArrayForm(digits, nums, num, &returnSize);
	printf("%d \n", returnSize);
	for(int i=0; i<returnSize; i++){
		printf("%d ", *(returns+i));
	}
	printf("\n");
	return 0;
}
