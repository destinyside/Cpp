#include<stdio.h>
#include<stdlib.h>

int trailingZeroes(int n){	
	int s = 0;
	int p = 0;
	while(n > 1){
		if(n%10==0){
			s++;
		}
		if(n%2==0){
			p*=n;
			if(p%10==0){
				s++;
				p/=10;
			}
		}
		if(n%10==5){
			p*=5;
			if(p%10==0){
				s++;
				p/=10;
			}
		}
		n--;
	}
	return s;
}

int main(int argc, char* argv[]){
	int num = 10;
	if(argc > 1){
		num = atoi(argv[1]);
	}
	printf("zeroes %d : %d\n",num,trailingZeroes(num));
	return EXIT_SUCCESS;
}
