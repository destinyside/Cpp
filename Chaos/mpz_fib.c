#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gmp.h>
/*
 * cause a stack overflow exception when the nth is very large, like 666666.
 */
void fibonacci(mpz_t a, mpz_t b, int c){
	if(c<=0){
		;
	} else {
		mpz_add(b, a, b);
		mpz_sub(a, b, a);
		fibonacci(a, b, --c);
	}

}

void fibonacci1(mpz_t a, mpz_t b, int c){
	while(c>0){
		mpz_add(b, a, b);
		mpz_sub(a, b, a);
		c--;
	}
}

void fib(int i){
	mpz_t a,b;
	mpz_init(a);
	mpz_init(b);
	mpz_init_set_ui(a,0);
	mpz_init_set_ui(b,1);
	fibonacci1(a,b,i);
	gmp_printf("%i : %Zd\n",i,b);

}

int main(int argc, char* argv[]){
	int i;
	if(argc > 1){
		for(int i=1; i<argc; i++){
			i = atoi(argv[i]);
			fib(i);
		}
	} else {
		printf("input the nth: ");
		scanf("%d",i);
		fib(i);
	}
	return EXIT_SUCCESS;
}
