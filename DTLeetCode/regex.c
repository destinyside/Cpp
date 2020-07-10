#include<stdio.h>
#include<stdbool.h>


bool isMatch(char* s1, char* p1){
	int i = 0, j = 0;
	bool match = true;
	while(true){
		if(*(s+i) == '\0' && *(p+j) == '\0'){
			break;
		}
		if(*(s+i) == *(p+j) || *(p+j) == '.'){
			match = true && match;
		} else {
			if
		}
	}
	return match;
}

void match(char* s, char* p){
	bool match = isMatch(s, p);
	printf("%s %s: %s\n", s, p, match?"match":"not");

}

int main(){
	match("aa", "a*");
	match("aaa", "a*a");
	match("aa", ".*c");
	match("aae", "a*b*c*d*e*");
	return 0;
}
