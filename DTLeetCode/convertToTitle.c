#include<stdio.h>
#include<stdlib.h>

char * convertToTitle(int n){
	int len = 100;
	char* r = malloc(sizeof(char)*len);
	r[len-1]='\0';
	int i = len-2;
	while(n>0){
		r[i--]=('A'+(--n%26));
		n/=26;
	}
	r = r + i + 1;
	return r;
}

int main(int argc, char* argv[]){
	int num = 27;
	if(argc > 1){
		num = atoi(argv[1]);
	}
	printf("%d convert to %s\n", num, convertToTitle(num));
	return EXIT_SUCCESS;
}
