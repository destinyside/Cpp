#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rand7(){
	return rand() % 7 + 1;
}

int rand10(){
	int a = rand7(), b = rand7();
	if(a < 4 && b > 4){
		return rand10();
	} else {
		return (a + b) % 10 + 1;
	}
}

int main(int argc, char* argv[]){
	srand((unsigned) time(0));
	int num = rand() % 5 + 1;
	if(argc > 1){
		num = atoi(argv[1]);
	}
	for(int i=1; i<=num; i++){
		printf("%d ", rand10());
		if(i % 10 == 0){
			printf("\n");
		}
	}
	printf("\n");
	return 0;

}
