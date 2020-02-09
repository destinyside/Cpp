#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<gmp.h>

typedef mpz_t bi;

bi one;

typedef struct fraction {
	bi numerator;
	bi denominator;
} frac;

//greatest common divisor
/*
   bi gcd1(bi x, bi y){
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

bi gcd(bi x, bi y){
if(y == 0){
return x;
}
return gcd(y, x%y);
}

//lowest common multiple
bi lcm(bi x, bi y){
bi g = gcd(x, y);
return x*(y/g);
}*/

frac* addf(frac* f1, frac* f2){
	frac* fadd = malloc(sizeof(frac));
	mpz_init(fadd->numerator);
	mpz_init(fadd->denominator);
	bi g,l,n1,n2;
	mpz_init(g);
	mpz_init(l);
	mpz_init(n1);
	mpz_init(n2);
	gmp_printf("f1: %Zd/%Zd f2: %Zd/%Zd one: %Zd\n", f1->numerator, f1->denominator, f2->numerator, f2->denominator, one);
	mpz_gcd(g, f1->denominator, f2->denominator);
	mpz_lcm(l, f1->denominator, f2->denominator);
	mpz_tdiv_r(n1, one, f1->denominator);
	mpz_mul(n1, f1->denominator, n1);
	mpz_tdiv_r(n2, one, f2->denominator);
	mpz_mul(n2, f2->denominator, n2);
	bi g1;
	mpz_init(g1);
	bi n3;
	mpz_init(n3);
	mpz_add(n3, n1,n2);
	mpz_gcd(g1, one, n3);
	mpz_tdiv_r(fadd->denominator, one, g1);
	mpz_tdiv_r(fadd->numerator, n3, g1);
	return fadd;
}

frac* addi(long long num, frac* f2){
	gmp_printf("num: %lld f2: %Zd/%Zd one: %Zd\n", num, f2->numerator, f2->denominator, one);
	frac* fnum = malloc(sizeof(frac));;
	mpz_init(fnum->numerator);
	mpz_init(fnum->denominator);
	mpz_set(fnum->denominator,f2->denominator);
	mpz_mul_ui(fnum->numerator,f2->denominator, num);
	return addf(fnum, f2);
}

void ps(frac* t){
	printf("s1:\nn: %bid d: %bid\n\n", t->numerator, t->denominator);
}

int getsi(int i){
	if(i == 0){
		return 2;
	}
	if(i == 1){
		return 1;
	}
	if((i+1)%3==0){
		return (i+1)*2/3;
	} else {
		return 1;
	}
}

frac* ef(int n){
	frac* p = malloc(sizeof(frac));
	mpz_init(p->numerator);
	mpz_init(p->denominator);
	if(n == 0){
		mpz_init_set_ui(p->numerator, 2);
		mpz_init_set_ui(p->denominator, 1);
		//p->numerator = 2;
		//p->denominator = 1;
		return p;
	}	
	mpz_init_set_ui(p->numerator, 1);
	mpz_init_set_ui(p->denominator, getsi(n));
	//p->numerator = 1;
	//p->denominator = getsi(n);
	for(int i=n-1; i>=1; i--){
		p = addi(getsi(i), p);
		mpz_swap(p->numerator, p->denominator);
	}
	p = addi(2, p);
	return p;
}

int main(int argc, char* argv[]){
	mpz_init(one);
	mpz_init_set_ui(one, 1);
	int n = 10;
	if(argc == 2){
		n = atoi(argv[1]);	
	}
	ps(ef(n));
	return 0;
}
