#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isVowel(char c){
	return c=='a' || c=='e' ||c=='i'||c=='o'||c=='u';
}

char * reverseVowels(char * s){
	int i = 0;
	int j = strlen(s)-1;
	char* tmp = malloc(sizeof(int)*(j+1));
	tmp = (char*)memcpy(tmp,s,j+1);
	while(i<j){
		printf("%d %d %c %c\n",i,j,tmp[i],tmp[j]);
		if(isVowel(s[i]) && isVowel(s[j])){
			if(isVowel(tmp[i])){
				char c = tmp[i];
				tmp[i]=tmp[j];
				tmp[j]=c;
			}
			i++;
			j--;
		}
		if(!isVowel(tmp[i])){
			i++;
		}
		if(!isVowel(tmp[j])){
			j--;
		}
	}
	return tmp;
}

int main(int argc, char* argv[]){
	char* s = "leetcode";
	if(argc > 1){
		s = argv[1];
	}
	printf("%s\n%s\n",s,reverseVowels(s));
	return EXIT_SUCCESS;
}
