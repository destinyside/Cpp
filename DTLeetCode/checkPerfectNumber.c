#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool checkPerfectNumber(int num){
	int m = sqrt((double)num);
	int s = 1;
	for(int i=2; i<=m; i++){
		if(num%i==0){
			s+=i;
			s+=num/i;
		}
	}
	return num == s;
}

int main(int argc, char* argv[]){
	int n = 10000;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	for(int i=0; i<n; i++){
		if(checkPerfectNumber(i)){
			printf("%d\n",i);
		}
	}
	return EXIT_SUCCESS;

}
