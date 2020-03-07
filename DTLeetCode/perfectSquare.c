#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPerfectSquare(int num){
	if(num<0){
		return false;
	}
	if(num==0){
		return true;
	}
	int i=1,j=num;
	int s = abs(j-i);
	int m=(i+j)/2;
	while(s!=1 && s!=0){
		s=abs(j-i);
		m=(i+j)/2;
		int m2 = m*m;
		printf("ijsm %d %d %d %d %lld\n",i,j,s,m,m2);
		if(m2==num){
			return true;
		}
		if(m2>num || m2 < 0){
			j=m;
		} else {
			i=m;
		}
	}
	if(i*i==num || j*j==num){
		return true;
	} else {
		return false;
	}
}

int main(int argc, char* argv[]){

	int n = 25;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	printf("%d %s\n", n, isPerfectSquare(n)?"true":"false");
	return EXIT_SUCCESS;
}
