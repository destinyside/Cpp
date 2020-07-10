#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>


bool primeq(long m){
	long i,k=(long)sqrt((double)m);
	for(i=2;i<=k;i++){
		if(m%i==0){
			break;
		}
	}
	return i>k;
}

bool t(char* str){
	int num = atoi(str);
	if(primeq(num)){
		return true;
	} else {
		return false;
	}
}
//euler 58 Spiral primes
int main(int argc, char* argv[]){
	//srand((unsigned) time(0));
	//int num = rand() % 100000;
	//printf("%d: %s\n", num, primeq(num)?"true":"false");
	//return 0;
	int min = 1;
	int max = 100;
	int count = 1;
	if(argc > 1){
		max = atoi(argv[1]);
	}
	if(argc > 2){
		min = atoi(argv[1]);
		max = atoi(argv[2]);
	}
	if(argc > 3){
		min = atoi(argv[1]);
		max = atoi(argv[2]);
		count = atoi(argv[3]);
	}
	for(int m=min; m<=max; m++){
	long long level=1,step=2,num=1, prime=0;
	for(;level<=m;level++){
		for(int i=0; i<4; i++){
			num+=step;
			if(primeq(num)){
				//printf("%d p  ", num);
				prime++;
			}else {
				//printf("%d n  ", num);
			}
		}
		//printf("\n");
		step+=2;
	}
	level--;
	printf("level:%d side:%d step:%d num:%d prime:%d diag:%d ratio: %.2f\n", level,2*level+1,step,num,prime,4*level+1, prime*1.0/(4*level+1));
	if((prime*1.0/(4*level+1)) <0.1){
		printf("\nside:%d\n", 2*level+1);
		if((level-min)>count){
			break;
		}
	}
	}
	return 0;
}
