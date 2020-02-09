#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	if(argc > 1){
		long num0 = atol(argv[1]);
		long num = num0;
		int ans = num % 10;
		num /= 10;
		while(num > 0){
			int bit = num % 10;
			ans = ans ^ bit;
			num /= 10;
		}
		printf("%ld：%d\n", num0, ans);
	} else {
		printf("need a parameter number.\n");
	}
	return 0;

}
