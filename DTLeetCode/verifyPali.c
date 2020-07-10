#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isPalindrome(char * s){
	int len = strlen(s);
	int i = 0, j = len - 1;
	while(i < j){
		while(i <= j && !(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <='Z')){
			i++;
		}
		while(i <= j && !(s[j] >= '0' && s[j] <= '9') && !(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= 'A' && s[j] <='Z')){
			j--;
		}
		printf("%d %d %c %c - %c + %c\n",i, j, s[i], s[j], s[j] - 32, s[j] + 32);
		if(s[i] >= '0' && s[i] <= '9'){
			if(s[i] != s[j]){
				return false;
			}
		}
		if(s[i] >= 'a' && s[i] <= 'z'){
			if(s[i] != s[j] && s[i] != (s[j] + 32)){
				return false;
			}
		}
		if(s[i] >= 'A' && s[i] <= 'Z'){
			if(s[i] != s[j] && s[i] != (s[j] - 32)){
				return false;
			}
		}
		i++;
		j--;
	}
	return true;
}

void t(char* p){
	printf("test: %s \nveri: %s\n", p, isPalindrome(p)?"true":"false"); 
}
int main(){
	t("A man, a plan, a canal: Panama");
	t("race a car");
	t("");
	t(".");
	t(".,");
	t("0P");
	t("P0");
	return 0;

}
