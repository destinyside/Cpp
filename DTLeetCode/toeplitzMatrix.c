#include<stdio.h>


bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
	for(int i=matrixSize-1,j=0,mi=i,mj=0; i>=0 || j<*matrixColSize; ){
		int one = INT_MIN;
		if(mi<=i && mj<=j){
			one = matrix[mi][mj];
		}
		for(int k=mi,l=mj; k<=i && l<=j; k++,l++){
			printf("%d %d %d \n", k, l, matrix[k][l]);
			if(one!=matrix[k][l]){
				return false;
			} else {
				one = matrix[k][l];
			}
		}
		printf("\n\n");
		if(j==*matrixColSize){
			i--;
		} else {
			j++;
		} 
		if(mi==0){
			mj++;
		} else {
			mi--;
		}
	}
	return true;
}


int main(int argc, char* argv[]){
	int col = 


	return EXIT_SUCCESS;
}
