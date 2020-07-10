#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){
	char* r=ransomNote;
	char* m=magazine;
	while(*m!='\0'){
		printf("o %c %c\n",*m,*r);
		if(*m==*r){
			while(*r!='\0'){
				printf("i %c %c\n",*m,*r);
				if(*r!=*m){
					r=ransomNote;
					m--;
					break;
				}
				r++;
				m++;
			}
			if(*r=='\0'){
				return true;
			}
		}
		m++;
	}
	if(*m==*r){
		return true;
	} else{
		return false;
	}

}

int main(int argc, char* argv[]){
	char* r;
	char* m;
	if(argc>2){
		r=argv[1];
		m=argv[2];
	}
	printf("%s %s : %s\n",r,m,canConstruct(r,m)?"true":"false");
	return EXIT_SUCCESS;

}
