#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


bool isMatch(char * s, char * p){
	int slen = strlen(s);
	int plen = strlen(p);
	bool dp[slen][plen];
	for(int i=0; i<slen; i++){
		for(int j=0; j<plen; j++){
			dp[i][j] = false;
		}
	}
	
	return dp[slen-1][plen-1];
}

void t(char* s, char* p){
	printf("s:%s\np:%s\nmatch:%s\n",s,p,isMatch(s,p)?"true":"false");
}

int main(int argc, char* argv[]){
	FILE* fp = NULL;

	fp = fopen("regex_patterns.txt", "r");
	if (fp == NULL) {
		perror("open file error");
		return -1;
	}
	char ch;
	char* s = malloc(sizeof(char)*100);
	char* p = malloc(sizeof(char)*100);

	int i=0,j=0;
	int c = 0;
	int f = 0;
	while ((ch = fgetc(fp)) != EOF) {
		if(c==0){
			if(ch!='\n'){
				s[i++] = ch;
			} else {
				s[i] = '\0';
				f++;
				c=1;
			}
		} else {
			if(ch!='\n'){
				p[j++] = ch;
			} else {
				p[j] = '\0';
				f++;
			}
		}
		if(f==2){
			t(s,p);
			f=0;
			c=0;
			i=0;
			j=0;
		}
	}
	free(s);
	free(p);
	fclose(fp);
	return EXIT_SUCCESS;
}
