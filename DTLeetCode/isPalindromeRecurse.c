#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPalindrome(int x){
	if(x<0){
		return false;
	} else if(x<10){
		return true;
	} else {
		int r = x%10;
		int t = x;
		int n = 0;
		while(t>0){
			n=n*10+t%10;
			t/=10;
		}
		printf("%d %d %d\n", t%10, t, n);
		return n==x;

	}
}

int main(int argc, char* argv[]){
	int num = 121;
	if(argc > 1){
		for(int i=1; i<argc; i++){
			num = atoi(argv[i]);
			printf("%d is palindrome : %s\n", num, isPalindrome(num)?"true":"false");
		}
		return EXIT_SUCCESS;
	}
	printf("%d is palindrome : %s\n", num, isPalindrome(num)?"true":"false");
	return EXIT_SUCCESS;
}
