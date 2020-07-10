#include<stdio.h>
#include<stdlib.h>

/**
 *  * Return an array of arrays of size *returnSize.
 *   * The sizes of the arrays are returned as *returnColumnSizes array.
 *    * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 *     */

int* makeSeq(int min, int max){
	if(min>max){
		return makeSeq(max,min);
	}
	int* arr = malloc(sizeof(int)*(max-min));
	for(int i=min; i<=max; i++){
		arr[i-min]=i;
	}
	return arr;
}

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
	if(target<=2){
		*returnSize = 0;
		return NULL;
	}
	int i=1,j=1;
	int count = 0;
	*returnSize = 100;
	*returnColumnSizes = malloc(sizeof(int)*100);
	int** arr = malloc(sizeof(int*)*100);
	while(j<target){
		while(i<=j){
			int s = (j-i+1)*(j+i)/2;
			printf("s %d i %d j %d\n",s,i,j);
			if(s==target){
				int plen = j-i+1;
				if(plen>1){
					arr[count] = makeSeq(i,j);
					(*returnColumnSizes)[count] = plen;
					count++;
				}
				j++;
			} else if(s>target){
				i++;
			} else {
				j++;
			}
	}
	}
	*returnSize = count;
	return arr;
}

int main(int argc, char* argv[]){
	int target = 15;
	if(argc > 1){
		target = atoi(argv[1]);
	}
	int* returnSize = malloc(sizeof(int));
	int** returnColumnSizes;
	int** arr = findContinuousSequence(target, returnSize, returnColumnSizes);
	for(int i=0; i<*returnSize; i++){
		for(int j=0; j<(*returnColumnSizes)[i]; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
