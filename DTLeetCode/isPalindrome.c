#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPalindrome(int x){
	if(x<0){
		return false;
	} else if(x<10){
		return true;
	} else {
		int l = 0;
		int t = x;
		while(t>0){
			t/=10;
			l++;
		}
		t = x;
		int s = 0;
		bool odd = l%2!=0;
		int m = odd?(l/2+1):(l/2);
		for(int i=1; i<=l; i++){
			int b = t%10;
			if(odd){
				if(i<=m){
					s+=b;
				} else if(i==m){
					s+=0;
				} else {
					s-=b;
				}
			} else {
				if(i<=m){
					s+=b;
				} else {
					s-=b;
				}
			}
			t/=10;
		}
		return s==0;
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
