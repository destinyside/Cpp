#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isRelatePrime(int a, int b){
	int c = b;
	while(a%b!=0){
		c = a%b;
		a = b;
		b = c;
	}
	return c==1;
}

double phi(int n){
	printf("phi(%d) ", n);
	int count = n;
	int max =(int)sqrt((double)n);
	int num = n;
	for(int i=2; i<=max; i++){
		if(n%i==0){
			count=count/i*(i-1);	
		}
		while(n%i==0){
			n/=i;
		}
		//if(isRelatePrime(n,i)){
			//printf("%d ", i);
		//	count++;
		//}
	}
	//if(count == 0){
	//	printf("%d %f\n", count, 0);
	//	return 0;
	//}
	if(n>1){
		count=count/n*(n-1);
	}
	printf("%d %f\n", count, num*1.0/count*1.0);
	return num*1.0/count*1.0;
}

//euler 69 totient maximum
int main(int argc, char* argv[]){
	int num = 1000;
	if(argc >  1){
		num = atoi(argv[1]);
	}
	double max = 0;
	int maxn = 0;
	for(int i=2; i<num; i++){
		double rt = phi(i);
		if(rt > max){
			max = rt;
			maxn = i;
		}
	}
	printf("max: %d maximum: %f\n", maxn, max);
	return 0;

}
