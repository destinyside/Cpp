#include<stdio.h>
#include<limits.h>

double myPow(double x, int n){
	if(n == 0 || x == 1){
		return 1;
	} else if(n < 0){
		if(x == INT_MIN){
			return 1.0 / (myPow(x, INT_MAX) * x);
		}
		return 1.0 / myPow(x, -n);
	} else {
		double m = 1.0;
		for(int j=n; j!=0; j/=2){
			if(j%2!=0){
				m*=x;
			}
			x*=x;
		}
		return m;
	}
}
void t(double x, int n){
	printf("%.5f %d : %.5f\n", x, n, myPow(x, n));
}

int main(){
	t(2.1000,3);
	t(2.0000,-2);
	t(2.000,10);
	t(0.0001,2147483647);
	return 0;
}
