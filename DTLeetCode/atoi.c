#include<stdio.h>
#include<limits.h>

int myAtoi(char * str){
	long val = 0;
	int flag = 1;
	for(;*str == ' ';str++);
	if(*str == '-' || *str == '+'){
		flag = *str == '-' ?-1:1;
		str++;
	}
	for(;*str >= '0' && *str <= '9';str++){
		int bit = *str - '0';
		val = val * 10 + bit;
		if(val > INT_MAX){
			if(flag == -1){
				return INT_MIN;
			} else {
				return INT_MAX;
			}
		}
	}
	val = val * flag;
	return val;
}

void t(char* str){
	printf("%s: %d\n", str, myAtoi(str));
}

int main(){
	t("43");
	t("    -42");
	t("4872 with words");
	t("word and 4872");
	t("-11344534");
	t("-1231321344534");
	t("11344534");
	t("1231321344534");
	t("+1344534");
	t(" 000000000001344534");
	t("-+1");
	t("2000000000000000000000000000000000000000");
	t("-91283472332");
	return 0;
}
