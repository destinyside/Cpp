#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	int num=5;
	if(argc > 1){
		num = atoi(argv[1]);
	}
	printf("%d: \n~%d=%d\n~%d&%d=%d\n",num,num,~num,num,num,~num & num);
	return EXIT_SUCCESS;

}
