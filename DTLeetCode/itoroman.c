#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char* cat(char* dst,const char* src){
	int len1 = strlen(dst);
	int len2 = strlen(src);
	char* cmb = malloc(sizeof(char)*(len1+len2));
	cmb[len1+len2-1] = '\0';
	strcat(cmb, dst);
	return strcat(cmb, src);
}
int nums[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
char vals[13][2] = {"M", "CM", "D","CD","C","XC","L","XL","X", "IX", "V", "IV", "I"};

char * intToRoman(int num){
	char* p = malloc(sizeof(char)*20);
	int j = 0;
	for(int i=0,len=13; i<len; i++){
		while(num >= nums[i]){
			p[j++] = vals[i][0];
			if(vals[i][1] != '\0'){
				p[j++] = vals[i][1];
			}
			num -= nums[i];
		}
	}
	p[j]='\0';
	return p;
}

int main(int argc, char** argv){
	srand((unsigned)time(0));
	int num = rand() % 4000;
	printf("%d: %s\n", num, intToRoman(num));
	return 0;
}
