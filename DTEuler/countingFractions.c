#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool primeq(long m){
	long i,k=(long)sqrt((double)m);
	for(i=2;i<=k;i++){
		if(m%i==0){
			break;
		}
	}
	return i>k;
}

long gcd(long x, long y){
	if(y == 0){
		return x;
	}
	return gcd(y, x%y);
}

long gcd1(long x, long y){
	if(x==y){
		return x;
	}
	//odd number
	bool ox = (x&1);
	bool oy = (y&1);
	if(ox && oy){
		return x>y?gcd1(x-y,y):gcd1(y-x,x);
	}
	if(!ox && !oy){
		return 2*gcd1(x>>1,y>>1);
	}
	if(!ox && oy){
		return gcd1(x>>1,y);
	}
	if(ox && !oy){
		return gcd1(x, y>>1);
	}
}

long lcm(long x, long y){
	long g = gcd1(x, y);
	return x*(y/g);
}

int main(int argc, char* argv[]){
	long num = 8;
	if(argc > 1){
		num = atol(argv[1]);

	}
	long long count = 0;
	for(long i=2; i<=num; i++){
		if(primeq(i)){
			count += i - 1;
		} else {


			for(long j=1; j<i; j++){
				//printf("%d %d %ld\n", i, j, gcd(i,j));
				if(gcd1(i, j)==1){
					printf("%d: %d/%d\n", ++count, j,i);
				}
			}
		}
	}
	return 0;
}
