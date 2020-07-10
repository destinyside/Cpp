#include<stdio.h>

long fact(long n){
	long m = 1;
	for(long i=1;i<=n;i++){
		m*=i;
	}
	return m;
}

int c(int n,int x){
	return fact(n)/(fact(x)*fact(n-x));
	int r = 1;
	for(int i=n;i>=x;i--){

	}
}

int climbStairs(int n){
	int s = 1;
	for(int i=1;n>=2*i;i++){
		s+=c(n-i,i);
	}
	return s;
}

int main(int argc, char* argv[]){
	int n=10;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	printf("%d\n",climbStairs(n));
	return 0;
}
