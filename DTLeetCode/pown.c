#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPowerOfN(int num, int n){
	if(num<n || num%n!=0){
		return false;
	} else {
		while(num!=n){
			printf("%d %d\n",num,n);
			if(num<n || num%n!=0){
				return false;
			}
			num /= n;
		}
		return true;
	}
}
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
	int num = 100;
	int n=2;
	if(argc > 2){
		num = atoi(argv[1]);
		n = atoi(argv[2]);
	}
	printf("pow %d %d : %s\n",num,n, isPowerOfN(num,n)?"true":"false");
	return EXIT_SUCCESS;
}
