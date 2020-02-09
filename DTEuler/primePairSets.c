#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
int primes[100000];
bool primes1[100000] = {false};

bool primeq0(long m){
	long i,k=(long)sqrt((double)m);
	for(i=2;i<=k;i++){
		if(m%i==0){
			break;
		}
	}
	return i>k;
}

bool primeq(long m){
	if(m >= 100000){
		return primeq0(m);
	} else {
		return primes1[m];
	}
}

bool t(char* str){
	long num = atol(str);
	if(primeq(num)){
		return true;
	} else {
		return false;
	}
}

bool primeq1(int a, int b){
	char str1[15], str2[15];
	sprintf(str1, "%d%d" , a, b);
	sprintf(str2, "%d%d" , b, a);
	//printf("%s %s\n", str1, str2);
	return t(str1) && t(str2);
}

void primePairSets(int len){
	for(int i=1;i<len; i++){
		int a = primes[i];
		for(int j=1;j<len; j++){
			int b = primes[j];
			if(a==b || !primeq1(a,b)){
				continue;
			}
			for(int k=0;k<len; k++){
				int c = primes[k];
				if(a==c || b==c || !primeq1(a,c) || !primeq1(b,c)){
					continue;
				}
				for(int l=0;l<len; l++){
					int d = primes[l];
					if(a==d || b==d || c==d || !primeq1(a,d) || !primeq1(b,d) || !primeq1(c,d)){
						continue;
					}
					for(int m=0;m<len; m++){
						printf("\r\033[k");
						int e=primes[m];
						printf("%d %d %d %d %d + %d", a,b,c,d,e,a+b+c+d+e);
						if(a!=e && b!=e && c!=e && d!=e && primeq1(a,e) && primeq1(b,e) && primeq1(c,e) && primeq1(d,e)){
							printf("\n\nprimes %d %d %d %d %d + %d\n", a,b,c,d,e,a+b+c+d+e);
							//return;
						}

					}
				}
			}
		}
	}

}
// euler 60 primes 13 8389 6733 5197 5701 + 26033
int main(int argc, char* argv[]){
	//srand((unsigned) time(0));
	//int num = rand() % 100000;
	//printf("%d: %s\n", num, primeq(num)?"true":"false");
	//return 0;
	int count = 1000;
	if(argc > 1){
		count = atoi(argv[1]);
	}
	primes1[0] = false;
	primes[0] = 1;
	for(int i=2, j=1; i<100000; i++){
		if(primeq0(i)){
			primes[j++] = i;
			primes1[i] = true;
		}
	}
	primePairSets(count);
	return 0;
}
