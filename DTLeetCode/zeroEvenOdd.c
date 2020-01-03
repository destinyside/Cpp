#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void printNumber(int x){
	printf("%d",x);
}

typedef struct {
	int n;
	int i;
	int cnt;
	pthread_mutex_t mutex_zero;
	pthread_mutex_t mutex_odd;
	pthread_mutex_t mutex_even;
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
	ZeroEvenOdd* obj = (ZeroEvenOdd*) malloc(sizeof(ZeroEvenOdd));
	obj->n = n;
	obj->i = 1;
	pthread_mutex_init(&obj->mutex_zero, NULL);
	pthread_mutex_init(&obj->mutex_odd, NULL);
	pthread_mutex_init(&obj->mutex_even, NULL);
	pthread_mutex_lock(&obj->mutex_odd);
	pthread_mutex_lock(&obj->mutex_even);
	return obj;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.

void zero(ZeroEvenOdd* obj) {
	while(1){
		pthread_mutex_lock(&obj->mutex_zero);
		if(obj->i > obj->n){
			pthread_mutex_unlock(&obj->mutex_even);
			pthread_mutex_unlock(&obj->mutex_odd);
			break;
		}
		printNumber(0);
		if(obj->i % 2 != 0){
			pthread_mutex_unlock(&obj->mutex_odd);
		} else {
			pthread_mutex_unlock(&obj->mutex_even);
		}
	}
}

void even(ZeroEvenOdd* obj) {
	while(1){
		pthread_mutex_lock(&obj->mutex_even);
		if(obj->i > obj->n){
			pthread_mutex_unlock(&obj->mutex_zero);
			pthread_mutex_unlock(&obj->mutex_odd);
			pthread_mutex_unlock(&obj->mutex_even);
			break;
		}
		printNumber(obj->i);
		obj->i++;
		pthread_mutex_unlock(&obj->mutex_zero);
	}
}

void odd(ZeroEvenOdd* obj) {
	while(1){
		pthread_mutex_lock(&obj->mutex_odd);
		if(obj->i > obj->n){
			pthread_mutex_unlock(&obj->mutex_zero);
			pthread_mutex_unlock(&obj->mutex_odd);
			pthread_mutex_unlock(&obj->mutex_even);
			break;
		}
		printNumber(obj->i);
		obj->i++;
		pthread_mutex_unlock(&obj->mutex_zero);
	}
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {
	pthread_mutex_destroy(&obj->mutex_zero);
	pthread_mutex_destroy(&obj->mutex_odd);
	pthread_mutex_destroy(&obj->mutex_even);
	free(obj);
}


int main(int argc, char* argv[]){
	int num = 5;
	if(argc > 1){
		num = atoi(argv[1]);
	}
	int thread_num = 3;
	pthread_t tid[thread_num];
	ZeroEvenOdd* obj = zeroEvenOddCreate(num);
	int ret = pthread_create(&tid[0], NULL, zero, (void*)obj);
	ret = pthread_create(&tid[1], NULL, even, (void*)obj);
	ret = pthread_create(&tid[2], NULL, odd, (void*)obj);
	for(int i=0; i<thread_num; i++){
		pthread_join(tid[i], NULL);
	}
	zeroEvenOddFree(obj);
	return 0;

}

