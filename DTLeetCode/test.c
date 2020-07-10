#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	int p[10] = {1,2,3,4,5,5,4,3,2,1};
	int* arr = p;
	int len = 10;
	if(argc > 1){
		len = argc - 1;
		arr = malloc(sizeof(int)*len);
		for(int i=0; i<len; i++){
			arr[i] = atoi(argv[i+1]);
		}
	}
	int r = arr[0];
	for(int i=1; i<len; i++){
		r ^= arr[i];
	}
	printf("%d\n",r);
	return EXIT_SUCCESS;

}
