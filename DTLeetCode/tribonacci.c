#include<stdio.h>
#include<stdlib.h>

int tribonacci(int n){
	if(n<0) {return 0;}
	if(n==1||n==2) {return 1;}
	int a=0,b=1,c=1;
	for(int i=3; i<=n; i++){
		c=a+b+c;
		b=c-a-b;
		a=c-b-a;
		printf("abc %d %d %d \n",a,b,c);
	}
	return c;
}

int main(int argc, char* argv[]){

	int n = 25;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	printf("%d tribonacci is %d\n", n, tribonacci(n));
	return EXIT_SUCCESS;
}
