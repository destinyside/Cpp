#include<limits.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	int max = 100;
	if(argc > 1){
		max = atoi(argv[1]);
	}
	long maxx=0, d = 0, t = 0;
		for(long long j=1; j<=max; j++){
			for(long long k=2; k<=ULONG_MAX; k++){
				int r = (int) sqrt(j);
				if(j == r*r){
					break;
				}
				long long cnt = j*k*k+1;
				long long i = (long long) sqrt(cnt);
				if(cnt == i*i){
					printf("%lld^2 - %lld * %lld^2 = 1\n",i,j,k);
					if(i>maxx){
						maxx = i;
						d = j;
						t = k;
					}
					break;
				}
			}
		}
	printf("maxx: %lld, d: %lld, t: %lld\n", maxx,d,t);
	return 0;
}
