#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isUgly(int num){
	if(num<=0){
		return false;
	}
	while(num==1||num%2==0||num%3==0||num%5==0){
		if(num==1){
			return true;
		}
		if(num%2==0){
			num/=2;
		}
		if(num%3==0){
			num/=3;
		}
		if(num%5==0){
			num/=5;
		}

	}
	return false;
}

int main(int argc, char* argv[]){
	int num = 10;
	if(argc > 1){
		num = atoi(argv[1]);
	}
	printf("is ugly %d : %s\n",num,isUgly(num)?"true":"false");
	return EXIT_SUCCESS;
}
