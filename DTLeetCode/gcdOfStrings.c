#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool divZero(char* str, char* d){
	int len = strlen(str);
	int l = strlen(d);
	if(len%l!=0){
		return false;
	}
	for(int i=0; i<len; i++){
		if(str[i]!=d[i%l]){
			return false;
		}
	}
	return true;
}

char * gcdOfStrings(char * str1, char * str2){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len = len1>len2?len2:len1;
	char* m = malloc(sizeof(char)*len);
	int j=0;
	for(int i=0; i<len; i++){
		if(str1[i]==str2[i]){
			m[j++]=str1[i];
		}
	}
	m[j]='\0';
	while(j>0){
		if(divZero(str1,m) && divZero(str2,m)){
			return m;
		} else {
			j--;
			m[j]='\0';
		}
	}
	return "";
}


int main(int argc, char* argv[]){
	char* a = "ABABAB";
	char* b = "ABAB";
	if(argc > 2){
		a = argv[1];
		b = argv[2];
	}
	printf("a %s b %s gcd %s\n",a,b,gcdOfStrings(a,b));
	return EXIT_SUCCESS;
}
