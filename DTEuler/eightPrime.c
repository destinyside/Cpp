#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>


bool primeq(int m){
	int i,k=(int)sqrt((double)m);
	for(i=2;i<=k;i++){
		if(m%i==0){
			break;
		}
	}
	return i>k;
}

bool t(char* str){
	int num = atoi(str);
	if(primeq(num)){
		return true;
	} else {
		return false;
	}
}

void primes1(char* str){
	int slen = strlen(str);
	for(int i=0; i<slen; i++){
		char c1 = str[i];
		int cnt = 0;
		for(int x=0; x<10; x++){
			if(i == 0 && x == 0){
				continue;
			}
			str[i] = '0' + x;
			t(str)?cnt++:0;
		}
		if(cnt == 8){
			printf("\n");
			for(int x=0; x<10; x++){
				str[i] = '0' + x;
				if(primeq(atoi(str))){
					printf("%s ", str);
				}
			}
			str[i] = '*';
			printf("\n");
		}
		if(cnt > 4){
			printf("\r\033[k");
			printf("%s ", str);
			str[i] = '*';
			printf("%s ", str);
			printf(" \t\tcount: %d", cnt);
		}
		str[i] = c1;
	}
}

void primes2(char* str){
	int slen = strlen(str);
	for(int i=0; i<slen; i++){
		for(int j=i+1; j<slen; j++){
			if(i != j){
				char c1 = str[i];
				char c2 = str[j];
				int cnt = 0;
				for(int x=0; x<10; x++){
					if(i == 0 && x == 0){
						continue;
					}
					str[i] = '0' + x;
					str[j] = '0' + x;
					t(str)?cnt++:0;
				}
				if(cnt == 8){
					printf("\n");
					for(int x=0; x<10; x++){
						str[i] = '0' + x;
						str[j] = '0' + x;
						if(primeq(atoi(str))){
							printf("%s ", str);
						}
					}
					str[i] = '*';
					str[j] = '*';
					printf("\n");
				}
				if(cnt > 4){
					printf("\r\033[k");
					printf("%s ", str);
					str[i] = '*';
					str[j] = '*';
					printf("%s ", str);
					printf(" \t\tcount: %d", cnt);
				}
				str[i] = c1;
				str[j] = c2;
			}
		}
	}
}

void primes3(char* str){
	int slen = strlen(str);
	for(int i=0; i<slen; i++){
		for(int j=i+1; j<slen; j++){
			for(int k=j+1; k<slen; k++){
				if(i != j && j != k && i != k){
					char c1 = str[i];
					char c2 = str[j];
					char c3 = str[j];
					int cnt = 0;
					for(int x=0; x<10; x++){
						if(i == 0 && x == 0){
							continue;
						}
						str[i] = '0' + x;
						str[j] = '0' + x;
						str[k] = '0' + x;
						t(str)?cnt++:0;
					}
					if(cnt == 8){
						printf("\n");
						for(int x=0; x<10; x++){
							str[i] = '0' + x;
							str[j] = '0' + x;
							str[k] = '0' + x;
							if(primeq(atoi(str))){
								printf("%s ", str);
							}
						}
						str[i] = '*';
						str[j] = '*';
						str[k] = '*';
						printf("\n");
					}
					if(cnt > 4){
						printf("\r\033[k");
						printf("%s ", str);
						str[i] = '*';
						str[j] = '*';
						str[k] = '*';
						printf("%s ", str);
						printf(" \t\tcount: %d", cnt);
					}
					str[i] = c1;
					str[j] = c2;
					str[k] = c3;
				}
			}
		}
	}
}

void primes4(char* str){
	int slen = strlen(str);
	for(int i=0; i<slen; i++){
		for(int j=i+1; j<slen; j++){
			for(int k=j+1; k<slen; k++){
				for(int l=k+1; l<slen; l++){
					if(i != j && j != k && i != k && i != l && j != l && k != l){
						char c1 = str[i];
						char c2 = str[j];
						char c3 = str[j];
						char c4 = str[j];
						int cnt = 0;
						for(int x=0; x<10; x++){
							if(i == 0 && x == 0){
								continue;
							}
							str[i] = '0' + x;
							str[j] = '0' + x;
							str[k] = '0' + x;
							str[l] = '0' + x;
							t(str)?cnt++:0;
						}
						if(cnt == 8){
							printf("\n");
							for(int x=0; x<10; x++){
								str[i] = '0' + x;
								str[j] = '0' + x;
								str[k] = '0' + x;
								str[l] = '0' + x;
								if(primeq(atoi(str))){
									printf("%s ", str);
								}
							}
							str[i] = '*';
							str[j] = '*';
							str[k] = '*';
							str[l] = '*';
							printf("\n");
						}
						if(cnt > 4){
							printf("\r\033[k");
							printf("%s ", str);
							str[i] = '*';
							str[j] = '*';
							str[k] = '*';
							str[l] = '*';
							printf("%s ", str);
							printf(" \t\tcount: %d", cnt);
						}
						str[i] = c1;
						str[j] = c2;
						str[k] = c3;
						str[l] = c4;
					}
				}
			}
		}
	}
}

void primes5(char* str){
	int slen = strlen(str);
	for(int i=0; i<slen; i++){
		for(int j=i+1; j<slen; j++){
			for(int k=j+1; k<slen; k++){
				for(int l=k+1; l<slen; l++){
					for(int m=l+1; m<slen; m++){
						if(i != j && j != k && i != k && i != l && j != l && k != l && i != m && j != m && k != m && l !=m){
							char c1 = str[i];
							char c2 = str[j];
							char c3 = str[j];
							char c4 = str[j];
							char c5 = str[j];
							int cnt = 0;
							for(int x=0; x<10; x++){
								if(i == 0 && x == 0){
									continue;
								}
								str[i] = '0' + x;
								str[j] = '0' + x;
								str[k] = '0' + x;
								str[l] = '0' + x;
								str[m] = '0' + x;
								t(str)?cnt++:0;
							}
							if(cnt == 8){
								printf("\n");
								for(int x=0; x<10; x++){
									str[i] = '0' + x;
									str[j] = '0' + x;
									str[k] = '0' + x;
									str[l] = '0' + x;
									str[m] = '0' + x;
									if(primeq(atoi(str))){
										printf("%s ", str);
									}
								}
								str[i] = '*';
								str[j] = '*';
								str[k] = '*';
								str[l] = '*';
								str[m] = '*';
								printf("\n");
							}
							if(cnt > 4){
								printf("\r\033[k");
								printf("%s ", str);
								str[i] = '*';
								str[j] = '*';
								str[k] = '*';
								str[l] = '*';
								str[m] = '*';
								printf("%s ", str);
								printf(" \t\tcount: %d", cnt);
							}
							str[i] = c1;
							str[j] = c2;
							str[k] = c3;
							str[k] = c4;
							str[k] = c5;
						}
					}
				}
			}
		}
	}
}


void primed(char* str, int digit){
	if(digit == 1){
		primes1(str);
	} else if(digit == 2){
		primes2(str);
	} else if(digit == 3){
		primes3(str);
	} else if(digit == 4){
		primes4(str);
	} else if(digit == 5){
		primes5(str);
	} else {

	}
}

void primes(char* str){
	int slen = strlen(str);
	for(int i=1; i<slen; i++){
		primed(str, i);
	}
}

int main(int argc, char* argv[]){
	//srand((unsigned) time(0));
	//int num = rand() % 100000;
	//printf("%d: %s\n", num, primeq(num)?"true":"false");
	//return 0;
	int start = 10;
	int end = 100000;
	if(argc > 2){
		start = atoi(argv[1]);
		end = atoi(argv[2]);
	}
	char istr[30];
	for(int i=start; i<end; i++){
		//itoa(i, istr, 10);
		sprintf(istr, "%d", i);
		primes(istr);
	}
	printf("\n");
	return 0;
}
