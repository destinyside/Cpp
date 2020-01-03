#include<stdio.h>
#include<limits.h>

int ipow(int x, int i){
	int m = 1;
	for(int j=0; j<i; j++){
		m = m * x;
	}
	return m;
}

int reverse(int x){
	if(x > -10 && x < 10){
		return x;
	}
	if(x >= INT_MAX || x <= INT_MIN){
		return 0;
	}
	int bits[12] = {0};
	int type = 0;
	if(x >= 0){
		type = 1;
	} else {
		type = 0;
		x = -x;
	}
	int p = x;
	int i = 0;
	while(p >= 10){
		bits[i++] = p % 10;
		p = p / 10;
	}
	bits[i] = p;
	//printf("%d %d %d\n", i, bits[0], bits[1]);
	if(i >= 9){
		if(bits[0] > 2 || (bits[0] == 2 && bits[1] > 1)){
			return 0;
		}
	}
	long r = 0;
	for(int j=i; j>=0; j--){
		r += bits[i-j] * ipow(10, j);
	}
	if(type == 0){
		r = -r;
	} else {
		r = r;
	}
	if(r > INT_MAX || r < INT_MIN){
		return 0;
	}
	return r;
}

void t(int n){
	printf("%d %d\n",n, reverse(n));
}

int main(){
	t(1);
	t(-1);
	t(10);
	t(1563847412);
	t(-10);
	t(100);
	t(-100);
	t(1000);
	t(-1000);
	t(123);
	t(-123);
	t(120);
	t(23947878);
	t(-294878999);
	t(INT_MAX);
	t(INT_MAX-10);
	t(INT_MIN);
	t(INT_MIN+10);
	return 0;
}
