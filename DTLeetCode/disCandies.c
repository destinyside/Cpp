#include<stdio.h>
#include<stdlib.h>



int nthCandies(int idx, int num, int candies){
	if(candies<=(num*(num+1)/2)){
		int s = idx*(idx+1)/2;
		if(s>candies){
			return 0;
		} else {
			return idx;
		}
	} else {

		int r = candies%num;
		int lv = (candies-r)/num;
		int bs = lv*num*(num-1)+2*num*(num+1)/2;
		int s = bs+(lv+1)*num+idx;
		printf("lv : %d, r : %d, bs : %d, s : %d\n",lv,r,bs,s);
		if(s>candies){
			return lv*num*(num-1)+2*idx*(idx+1)/2;
		} else {
			return bs+(lv+1)*num+idx;
		}
	}
}

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* distributeCandies(int candies, int num_people, int* returnSize){
	int* arr = malloc(sizeof(int)*num_people);
}



int main(int argc, char* argv[]){
	int candies = 10;
	int num = 4;
	int index = 3;
	if(argc >= 4){
		candies = atoi(argv[1]);
		num = atoi(argv[2]);
		index = atoi(argv[3]);
	}
	printf("candies : %d, num : %d, index : %d\n", candies, num, index);
	printf("nth candies: %d\n", nthCandies(index, num, candies));
	return EXIT_SUCCESS;
}
