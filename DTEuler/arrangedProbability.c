#include<stdio.h>
#include<stdlib.h>

typedef long long ll;

ll gcd1(ll x, ll y){
	if(x==y){
		return x;
	}
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

ll lcm(ll x, ll y){
	ll g = gcd1(x, y);
	return x*(y/g);
}

int main(int argc, char* argv[]){
	ll num = 100;
	ll limit = 10000;
	if(argc == 2){
		num = atol(argv[1]);
	}
	if(argc > 2){
		num = atol(argv[1]);
		limit = atol(argv[2]);
	}
	for(ll i=1; i<num; i++){
		ll n = 2 * i * (i - 1);
		printf("\r\033[k");
		printf("%lld", i);
		ll s = i/2;
		for(ll j=i/3; j<s;j++){
			ll m = (i + j) * (i + j - 1);
			if(m%2==0 && n == m){
				printf("\n%lld + %lld: %lld\n", i, j, m);
				break;
			}
			if(m > n){
				break;
			}
			if((i+j) >= limit){
				break;
			}
		}
	}
	return 0;
}
