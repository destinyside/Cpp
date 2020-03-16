#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

bool hasAlternatingBits1(int n){
	int b = n%2;
	n>>=1;
	while(n>0){
		int b1 = n%2;
		if(b1==b){
			return false;
		}
		b=b1;
		n>>=1;
	}
	return true;
}

bool hasAlternatingBits(int n){
	    return n&0x55555555==0x55555555;
}

int main(int argc, char* argv[]){
	int max = 100;
	if(argc > 1){
		max = atoi(argv[1]);
	}
	for(int i=0; i<max; i++){
		if(hasAlternatingBits1(i)){
	printf("%d %d %d %d %d\n",i,i^INT_MAX,~i,i>>1, i&0x55555555);
			printf("%d\n",i);
		}
	}
	return EXIT_SUCCESS;
}
