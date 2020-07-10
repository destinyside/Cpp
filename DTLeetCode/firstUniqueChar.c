#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int firstUniqChar(char * s){
	int len = strlen(s);
	for(int i=0; i<len; i++){
		int m = 0;
		for(int j=0; j<len; j++){
			printf("%d %d %c %c\n",i,j,s[i],s[j]);
			if(j!=i && s[i]==s[j]){
				m++;
				break;
			}
		}
			printf("%d %c\n",i,s[i]);
		if(m==0){
			return i;
		}
	}
	return -1;
}

int main(int argc, char* argv[]){
	char* s = "leetcode";
	if(argc > 1){
		s = argv[1];
	}
	printf("%s %d\n",s,firstUniqChar(s));
	return 0;
}
