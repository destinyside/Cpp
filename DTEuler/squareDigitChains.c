#include<stdio.h>
#include<stdlib.h>

int print = 1;
int nums[1000] = {0};

int square(int i){
	int sum = 0;
	while(i > 0){
		int r = i % 10;
		sum += r * r;
		i /= 10;
	}
	return sum;
}

int chain(int num){
	int sum = square(num);
	int res = sum;
	if(nums[sum] != 0){
		return nums[sum]; 
	}
	if(print == 1){
		printf("%d->", sum);
	}
	while(1){
		sum = square(sum);
		if(sum == 1 || sum == 89){
			break;
		}
		if(print == 1){
			printf("%d->", sum);
		}
	}
	if(print == 1){
		printf("%d\n", sum);
	}
	nums[res] = sum;
	return sum;
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
	}
	if(argc > 2){
		print = atoi(argv[2]);
	}
	int count89 = 0;
	for(int i=1; i<=num;i++){

		printf("%d->", i);
		if(print != 1){
			printf("\n");
		}
		if(chain(i)==89){
			count89++;
		}
	}
	printf("\n89 count: %d\n",count89);
	return 0;

}
