#include<stdio.h>
#include<stdlib.h>

int climbStairs1(int n){
	if (n < 0) return 0;
	if (n <=2) return n;

	int fn1 = 1, fn2 = 2;
	int fn3;
	for (int i = 2 ;i < n; i++){
		fn3 = fn2 + fn1;
		fn1 = fn2;
		fn2 = fn3;
	}
	return fn3;
}

int climbStairs(int n){
	if(n<0) {return 0;}
	if(n<=2) {return n;}
	int a=1,b=2;
	for(int i=2; i<n;i++){
		b = a+b;
		a = b-a;
	}
	return b;
}

int main(int argc, char* argv[]){
	int n = 10;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	printf("%d stairs climb %d steps\n",n,climbStairs1(n));
	printf("%d stairs climb %d steps\n",n,climbStairs(n));
	return EXIT_SUCCESS;
}
