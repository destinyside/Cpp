#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int maxArea(int* height, int heightSize){
	int i=0,j=heightSize-1;
	int max = 0;
	while(i!=j){
		int wi = j-i;
		int h1 = height[i];
		int h2 = height[j];
		int he =  h1 < h2?h1:h2;
		if(max < wi * he){
			max = wi * he;
		}
		if(h2<h1){
			j--;
		} else {
			i++;

		}
	}
	return max;
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
	int max = maxArea(arr,len);
	for(int i=0; i<len; i++){
		printf("%d ",arr[i]);
	}
	printf("\nmax: %d\n", max);
	return 0;

}
