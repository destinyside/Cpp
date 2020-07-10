#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int valueOfRoman(char c, char d){
	switch(c){
		case 'I': {
				  if(d=='V'){
					  return 4;
				  } else if(d=='X'){
					  return 9;
				  } else {
					  return 1;
				  }
			  }
		case 'V': return 5;
		case 'X': {
				  if(d=='L'){
					  return 40;
				  } else if(d=='C'){
					  return 90;
				  } else {
					  return 10;
				  }
			  }
		case 'L': return 50;
		case 'C': {
				  if(d=='D'){
					  return 400;
				  } else if(d=='M'){
					  return 900;
				  } else {
					  return 100;
				  }
			  }
		case 'D': return 500;
		case 'M': return 1000;
		default : return 0;
	}
}
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


int romanToInt(char * s){
	int r = 0;
	int len = strlen(s);
	int p = 0;
	for(int i=0; i<len; i++){
		if(i<len-1){
			int p = valueOfRoman(s[i],s[i+1]);
			r+=p;
			if(p==4||p==40||p==400||p==9||p==90||p==900){
				i++;
			}
		} else {
			r += valueOfRoman(s[i],'N');
		}
	}
	return r;
}

int main(int argc, char* argv[]){
	for(int i=1; i<5000; i++){
		char* p = intToRoman(i);
		printf("%d %s %d\n",i,p,romanToInt(p));
		free(p);
	}
	return EXIT_SUCCESS;
}

