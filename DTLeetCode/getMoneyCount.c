#include<stdio.h>
#include<stdlib.h>

int getMoneyAmount(int n){
	int count = 0;
	int num;
	int i=1,j=n,m=i+(j-i)/2;
	count+=i;
	while(i!=j){
		printf("%d %d %d %d\n",i,j,m,count);
		//j=m;
		i=m+1;
		m=i+(j-i)/2;
		count+=i;
	}
	return count;
}

int main(int argc,char* argv[]){
	int n=10;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	int count = getMoneyAmount(n);
	printf("count: %d \n",count);
	return EXIT_SUCCESS;
}
