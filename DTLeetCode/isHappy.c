#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isHappy(int n){
	if(n <= 0){
		return false;
	}
	int r = 0;
	while(1){
		while(n > 0){
			int i = n%10;
			r += i*i;
			n /= 10;
		}
		printf("%d\n",r);
		if(r==1){
			return true;
		} else if(r==89){
			return false;
		} else {
			n = r;
			r = 0;
		}
	}
}

int main(int argc, char* argv[]){
	int num = 19;
	if(argc > 1){
		num = atoi(argv[1]);
	}
	printf("%d\n",num);
	printf("is happy: %s\n",isHappy(num)?"true":"false");
	return EXIT_SUCCESS;

}
