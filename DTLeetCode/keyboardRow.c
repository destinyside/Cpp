#include<stdio.h>
#include<stdlib.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
char ** findWords(char ** words, int wordsSize, int* returnSize){
	*returnSize = 0;

	return NULL;
}

int main(int argc, char* argv[]){
	int wordsSize = 4;
	char* wordArr[] = {"Hello", "Alaska", "Dad", "Peace"};
	char** words = wordArr;
	if(argc > 1){
		wordsSize = argc - 1;
		words = argv+1;
	}
	int* returnSize = malloc(sizeof(int));
	char** result = findWords(words, wordsSize, returnSize);
	for(int i=0; i<*returnSize; i++){
		printf("%s ", result[i]);
	}
	return EXIT_SUCCESS;
}
