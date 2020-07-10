#include<stdio.h>
#include<stdbool.h>

int i[5] = {0};
int o[5] = {0};
bool eql(){
	return (i[0]+i[1]+o[1]) == (i[1]+i[2]+o[2]) &&
		(i[1]+i[2]+o[2]) == (i[2]+i[3]+o[3]) &&
		(i[2]+i[3]+o[3]) == (i[3]+i[4]+o[4]) &&
		(i[3]+i[4]+o[4]) == (i[4]+i[0]+o[0]);
}

bool chk(char* str){
	o[0] = str[0] - '0' + 1;
	o[1] = str[1] - '0' + 1;
	o[2] = str[2] - '0' + 1;
	o[3] = str[3] - '0' + 1;
	o[4] = str[4] - '0' + 1;
	i[0] = str[5] - '0' + 1;
	i[1] = str[6] - '0' + 1;
	i[2] = str[7] - '0' + 1;
	i[3] = str[8] - '0' + 1;
	i[4] = str[9] - '0' + 1;
	if(eql()){
		printf("\n%d,%d,%d;",i[0],i[1],o[1]);
		printf("%d,%d,%d;",i[1],i[2],o[2]);
		printf("%d,%d,%d;",i[2],i[3],o[3]);
		printf("%d,%d,%d;",i[3],i[4],o[4]);
		printf("%d,%d,%d\n",i[4],i[0],o[0]);
		return true;
	} else {
		return false;
	}
}

bool rep(long j){
	if(j<100000000){
		return true;
	} else {
		int b[11] = {0};
		long m = j;
		while(m > 0){
			int n = m%10;
			m /= 10;
			if(b[n] == 0){
				b[n] = 1;
			} else {
				return true;
			}
		}
		if(j < 1000000000){
			if(b[0] != 0){
				return true;
			}
		}
		return false;
	}
}

void slu(int num){
	char str[10];
	for(int j=0; j<=9999999999; j++){
		if(rep(j)){
			continue;
		} else {
			sprintf(str, "%010ld", j); 
			if(chk(str)){
				printf("\n%s\n", str);
			} else {
				printf("\r\033[k");
				printf("%s", str);
			}
		}
		/*
		   if(str[0] == str[1] ||
		   str[1] == str[2] ||
		   str[2] == str[3] || 
		   str[3] == str[4] || 
		   str[4] == str[5] ||
		   str[5] == str[6] ||
		   str[7] == str[8] ||
		   str[8] == str[9] ||
		   str[9] == str[0]){
		   printf("\r\033[k");
		   printf("%s", str);
		   }else {
		   }*/
		//printf("%s\n", str);
	}
}

int main(){
	slu(27);
	return 0;
}
