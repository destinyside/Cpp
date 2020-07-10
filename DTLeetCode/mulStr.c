#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	char product[200] = "";// = malloc(sizeof(char) * 100);
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
			int bit = (bit1 + bit2) % 10 + carry;
			carry = (bit1 + bit2) / 10;
			if(bit >= 10){
				carry++;
				bit = bit % 10;
			}
			printf("%d %d %d %d\n", bit1, bit2, bit, carry);
			product[cnt++] = bit+'0';

	}
	if(carry > 0){
		product[cnt++] = carry+'0';
	}
	product[cnt] = '\0';
	char* tmp = strrev(product);
	return tmp;
}

char* multiply(char* num1, char* num2){
	if(strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0){
		return "0";
	}
	//printf("\n");
	char product[300] = "";// = malloc(sizeof(char) * 100);
	int carry = 0;
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int cnt = 0;
	for(int j=len2-1; j>=0; j--){
		char tempProduct[200] = {0};// = malloc(sizeof(char) * 100);
		strcpy(tempProduct, product);
		char byProduct[200] = {0};// = malloc(sizeof(char) * 100);
		int byCnt = cnt;
		for(int k=0; k<byCnt; k++){
			byProduct[k] = '0';
		}
		for(int i=len1-1; i>=0; i--){
			int bit1 = num1[i] - '0';
			int bit2 = num2[j] - '0';
			int bit = (bit1 * bit2) % 10 + carry;
			carry = (bit1 * bit2) / 10;
			if(bit >= 10){
				carry++;
				bit = bit % 10;
			}
			printf("%d %d %d %d\n", bit1, bit2, bit, carry);
			byProduct[byCnt++] = bit+'0';
		}
		if(carry > 0){
			byProduct[byCnt++] = carry+'0';
			carry = 0;
		}
		char* addResult = addition(tempProduct, strrev(byProduct));
		printf("%s %s %s\n", tempProduct, byProduct, addResult);
		//product = malloc(sizeof(char) * 100);
		strcpy(product, addResult);
		cnt++;
	}
	//product[cnt] = '\0';
	char* tmp = product;
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
	printf("mul %s %s: %s\n", num1, num2, multiply(num1, num2));

}
