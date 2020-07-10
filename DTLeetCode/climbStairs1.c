#include<stdio.h>
#include<stdlib.h>

long long c(int n,int x)
{
	if(x ==0) return 1;
	if(x ==1) return n;
	if(x>n/2) return c(n,n-x);
	if(x > 1) return (c(n-1,x-1)+c(n-1,x));
}

int climbStairs(int n){
	int s = 1;
	for(int i=1;n>=2*i;i++){
		s+=c(n-i,i);
	}
	return s;
}

int main(int argc, char* argv[]){
	int n = 10;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	printf("%d stairs climb %d steps\n",n,climbStairs(n));
	return EXIT_SUCCESS;
}
