#include<stdio.h>
#include<stdlib.h>

int times(int n, int t){
	int r = 1;
	for(int i=0; i<t; i++){
		r *= n;
	}
	return r;
}

int titleToNumber(char * s){
	int r = 0;
	int l = 0;
	char* p = s;
	while(*p++!='\0'){
		l++;
	}
	l--;
	while(*s!='\0'){
		printf("%d %d %c %d\n",l, r,*s-'@',(*s-'@')*26);
		char c = *s++-'@';
		if(*s == '\0'){
			r += c;
		} else {
			r += c * times(26, l);
			l--;
		}
	}
	return r;
}

int main(int argc, char* argv[]){
	char* s = "AZ";
	if(argc > 1){
		s = argv[1];
	}
	printf("title to number %s : %d\n", s, titleToNumber(s));
	return EXIT_SUCCESS;
}
