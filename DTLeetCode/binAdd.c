#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>



char* strrev(char* src){
	char* dst = src;
	int left = 0;
	int slen = strlen(src);
	int right = slen - 1;
	while(left <= right){
		char tmp = src[left];
		src[left] = src[right];
		src[right] = tmp;
		left++;
		right--;
	}
	return dst;
}

char* addition(char* num1, char* num2){
	//printf("\n");
	//char product[200] = "";
	char* product = malloc(sizeof(char) * 100);
	int carry = 0;
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int cnt = 0;
	int i = len1 - 1, j = len2 - 1;
	while(i >= 0 || j >=0){
		int bit1 = 0;
		if(i >= 0){
			bit1 = num1[i--] - '0';
		}
		int bit2 = 0;
		if(j >= 0){
			bit2 = num2[j--] - '0';
		}
		int bit = (bit1 + bit2) % 2 + carry;
		carry = (bit1 + bit2) / 2;
		if(bit >= 2){
			carry++;
			bit = bit % 2;
		}
		printf("%d %d %d %d\n", bit1, bit2, bit, carry);
		product[cnt++] = bit+'0';

	}
	if(carry > 0){
		product[cnt++] = carry+'0';
	}
	product[cnt] = '\0';
	char* tmp = product;
	strrev(tmp);
	return tmp;
}

int main(int argc, char* argv[]){
	char* num1 = "123";
	char* num2 = "456";
	if(argc > 2){
		num1 = argv[1];
		num2 = argv[2];
	}
	printf("add %s %s: %s\n", num1, num2, addition(num1, num2));
	return 0;
}
