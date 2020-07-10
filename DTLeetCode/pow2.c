#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPowerOfTwo(int n){
	printf("n^(n-1) %d %d %d\n",n,n-1,n^(n-1));
	printf("n&(n-1) %d %d %d\n",n,n-1,n&(n-1));
	printf("n^(n+1) %d %d %d\n",n,n+1,n^(n+1));
	printf("n&(n+1) %d %d %d\n",n,n+1,n & (n+1));
	if(n<0){
		return (n^(n+1))==1;
	} else {
		return n!=0 && (n&(n-1))==0;
	}
}
bool isPowerOfTwo1(int n){
	//if(n==1){
	//	return true;
	//}
	printf("n^(n-1) %d %d %d\n",n,n-1,n^(n-1));
	printf("n&(n-1) %d %d %d\n",n,n-1,n&(n-1));
	printf("n^(n+1) %d %d %d\n",n,n+1,n^(n+1));
	printf("n&(n+1) %d %d %d\n",n,n+1,n & (n+1));
	while(n>>1){
		printf("%d %d\n",n,n>>1);
		if(n%2!=0){
			return false;
		}
		n>>=1;   
	}
	return n==1;
}

int main(int argc, char* argv[]){
	int n = 100;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	printf("pow 2 %d : %s\n",n, isPowerOfTwo(n)?"true":"false");
	return EXIT_SUCCESS;
}
