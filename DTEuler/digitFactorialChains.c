#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int print = 1;
int pos[1000] = {0};

int fact_sum(int n){
	int s = 1;
	while(n > 0){
		s *= n--;
	}
	return s;
}

int square(int i){
	int sum = 0;
	while(i > 0){
		int r = i % 10;
		sum += fact_sum(r);
		i /= 10;
	}
	return sum;
}

bool check(int num){
	int i=0;
	for(; pos[i]!=0; i++){
		if(pos[i]==num){
			return true;
		}
	}
	pos[i]=num;
	return false;
}

void reset(){
	for(int i=0; i<1000; i++){
		pos[i]=0;
	}
}

int chain(int num){
	reset();
	pos[0] = num;
	int sum = square(num);
	pos[1] = sum;
	int res = sum;
	if(print == 1){
		printf("%d->", sum);
	}
	while(1){
		sum = square(sum);
		if(check(sum)){
			break;
		}
		if(print == 1){
			printf("%d->", sum);
		}
	}
	if(print == 1){
		printf("%d\n", sum);
	}
	for(int i=0; i<1000; i++){
		if(pos[i]==0){
			return i;
		}
	}
	return 0;
}

int main(int argc, char* argv[]){
	int num = 100;
	if(argc <= 1){
		printf("need two parameters(integer): num(great equal 1), isprint(1 or 0).\n");
	}
	if(argc > 1){
		num = atoi(argv[1]);
		if(num <= 1){
			num = 100;
		}
		print = 1;
	}
	if(argc >= 3){
		print = atoi(argv[2]);
	}
	int mi = 0;
	int mp = 0;
	int count60 = 0;
	for(int i=1; i<=num;i++){

		printf("%d->", i);
		int m = chain(i);
		if(m > mp){
			mp = m;
			mi = i;
		}
		if(m == 60){
			count60++;
		}
		//printf(" %d\n", m);
		if(print != 1){
			printf("\n");
		}
	}
	printf("max:%d %d\n", mi, mp);
	chain(mi);
	printf("\nmax chains:%d\n",count60);
	return 0;

}
