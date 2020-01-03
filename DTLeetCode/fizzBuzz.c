#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct {
	int n;
	int i;
	pthread_mutex_t mutex;
	pthread_cond_t  cond;
} FizzBuzz;

FizzBuzz* fizzBuzzCreate(int n) {
	FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
	obj->n = n;
	obj->i = 1;
	pthread_mutex_init(&obj->mutex, NULL);
	pthread_cond_init(&obj->cond, NULL);
	return obj;
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {
	while(obj->i < obj->n){
		pthread_mutex_lock(&obj->mutex);
		while (!((obj->i % 3 == 0) && (obj->i % 5 != 0))) {
			pthread_cond_wait(&obj->cond,&obj->mutex);
		}
		printf("fizz");
		obj->i++;
		pthread_cond_signal(&obj->cond);
		pthread_mutex_unlock(&obj->mutex);
	}
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {
	while(obj->i < obj->n){
		pthread_mutex_lock(&obj->mutex);
		while (!((obj->i % 5 == 0) && (obj->i % 3 != 0))) {
			pthread_cond_wait(&obj->cond,&obj->mutex);
		}
		printf("buzz");
		obj->i++;
		pthread_cond_signal(&obj->cond);
		pthread_mutex_unlock(&obj->mutex);
	}
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {
	while(obj->i < obj->n){
		pthread_mutex_lock(&obj->mutex);
		while (!((obj->i % 5 == 0) && (obj->i % 3 == 0))) {
			pthread_cond_wait(&obj->cond,&obj->mutex);
		}
		printf("fizzbuzz");
		obj->i++;
		pthread_cond_signal(&obj->cond);
		pthread_mutex_unlock(&obj->mutex);
	}
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {
	while(obj->i < obj->n){
		pthread_mutex_lock(&obj->mutex);
		while (!((obj->i % 5 != 0) && (obj->i % 3 != 0))) {
			pthread_cond_wait(&obj->cond,&obj->mutex);
		}
		printf("%d", obj->i);
		obj->i++;
		pthread_cond_signal(&obj->cond);
		pthread_mutex_unlock(&obj->mutex);
	}
}

void fizzBuzzFree(FizzBuzz* obj) {
	pthread_mutex_destroy(&obj->mutex);
	pthread_cond_destroy(&obj->cond);
	free(obj);
}


int main(int argc, char* argv[]){
	int num = 5;
	if(argc > 1){
		num = atoi(argv[1]);
	}
	int thread_num = 2;
	pthread_t tid[thread_num];
	FizzBuzz* obj = fizzBuzzCreate(num);
	int ret = 0;
	ret = pthread_create(&tid[0], NULL, fizz, (void*)obj);
	ret = pthread_create(&tid[1], NULL, buzz, (void*)obj);
	//ret = pthread_create(&tid[2], NULL, fizzbuzz, (void*)obj);
	//ret = pthread_create(&tid[3], NULL, number, (void*)obj);
	for(int i=0; i<thread_num; i++){
		pthread_join(tid[i], NULL);
	}
	fizzBuzzFree(obj);
	return 0;
}

