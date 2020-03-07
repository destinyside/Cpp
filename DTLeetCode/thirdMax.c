#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int thirdMax(int* nums, int numsSize){
	long a,b,c;
	a=b=c=LONG_MIN;
	for(int i=0; i<numsSize; i++){
		if(nums[i]>a){
			c=b;
			b=a;
			a=nums[i];
		} else if(nums[i]>b && nums[i]!=a){
			c=b;
			b=nums[i];
		} else if(nums[i]>c && nums[i]!=b && nums[i]!=a){
			c=nums[i];
		} else {

		}
		printf("%d a:%d b:%d c:%d\n",nums[i],a,b,c);
	}
	if(c==LONG_MIN){
		return b;
	//} else if(b==LONG_MIN){
	//	return a;
	} else {

		return c;
	}
}


int* randomArray(int len) {

	srand((unsigned)time(0));
	int* tmp = malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++) {
		tmp[i] = rand() % len + 1;
	}
	return tmp;
}

int main(){
	int len = 10;
	int* arr = randomArray(len);
	int tmax = thirdMax(arr,len);
	for(int i=0; i<len; i++){
		printf("%d ",arr[i]);
	}
	printf("\nmax: %d\n", tmax);
	return 0;

}
