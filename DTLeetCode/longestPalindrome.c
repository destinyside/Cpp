#include<stdio.h>
#include<stdlib.h>

int longestPalindrome(char * s){
	int a[26] = {0};
	int A[26] = {0};
	char* p = s;
	while(*p != '\0'){
		if(*p>='a' && *p<='z'){
			a[*p-'a']+=1;
		}
		if(*p>='A' && *p<='Z'){
			A[*p-'A']+=1;
		}
		p++;
	}
	int m = 0;
	int o = 0;
	for(int i=0; i<26; i++){
		printf("%c : %d  %c : %d\n",'a'+i,a[i],'A'+i,A[i]);
		if(a[i]%2==0){
			m+=a[i];
		} else {
			o=1;
			m+=a[i]-1;
		}
		if(A[i]%2==0){
			m+=A[i];
		} else {
			o=1;
			m+=A[i]-1;
		}
	}
	return m+o;
}

int main(int argc, char* argv[]){
	char* p = "asjkdhkajshasyeasdhkjah";
	if(argc > 1){
		for(int i=1; i<argc; i++){
			p = argv[i];
			printf("%s : %d\n",p,longestPalindrome(p));
		}
	} else {
		printf("%s : %d\n",p,longestPalindrome(p));
	}

	return EXIT_SUCCESS;
}
