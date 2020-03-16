#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>



char* as(int c){
	char* m = malloc(sizeof(char)*c+1);
	int i=0;
	for(; i<c; i++){
		m[i]='a';
	}
	m[i]='\0';
	return m;
}

char* ruleOne(char* word, int wordSize, int idx){
	char* p = malloc(sizeof(char)*(wordSize+2+idx+1));
	sprintf(p, "%sma%s",word,as(idx));
	return p;
}

char* ruleTwo(char* word, int wordSize, int idx){
	char* p = malloc(sizeof(char)*(wordSize+2+idx+1));
	char c = *word++;
	sprintf(p, "%s%cma%s",word,c,as(idx));
	return p;
}

bool isVowel(char c){
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
		c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}

char * toGoatLatin(char * S){
	int nth = 1;
	char* p = S;
	char word[150];
	int i = 0;
	char* r = malloc(sizeof(char)*500);
	int* len = 0;
	while(*p!='\0'){
		printf("%c %d %d %d\n",*p,i,nth);
		if(*p==' '){
			word[i] = '\0';
			if(isVowel(word[0])){
				char* t = ruleOne(word,i,nth++);
				int l = strlen(t);
				for(int j=*len; j<*len+l; j++){
					r[j] = t[j];
				}
				*len = l;
				word[i]=' ';
				i=0;
			} else {
				char* t = ruleTwo(word,i,nth++);
				int l = strlen(t);
				for(int j=*len; j<*len+l; j++){
					r[j] = t[j];
				}
				*len = l;
				word[i]=' ';
				i=0;
			}
		} else {
			word[i++] = *p;
		}
		p++;
	}
	printf("%s\n",r);
	return r;
}


int main(int argc, char* argv[]){
	char* s = "The quick brown fox jumped over the lazy dog";
	if(argc > 1){
		s = argv[1];
	}
	printf("%s\n%s\n",s,toGoatLatin(s));
	return EXIT_SUCCESS;
}
