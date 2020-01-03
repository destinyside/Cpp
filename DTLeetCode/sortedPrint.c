#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void printFirst(){ printf("first");}
void printSecond(){ printf("second");}
void printThird(){ printf("third");}

typedef struct {
	// User defined data may be declared here.
	pthread_mutex_t mutex_ab;
	pthread_mutex_t mutex_bc;
} Foo;

Foo* fooCreate() {
	Foo* obj = (Foo*) malloc(sizeof(Foo));

	// Initialize user defined data here.
	pthread_mutex_init(&obj->mutex_ab, NULL); 
	pthread_mutex_init(&obj->mutex_bc, NULL); 
	pthread_mutex_lock(&obj->mutex_ab); 
	pthread_mutex_lock(&obj->mutex_bc); 
	return obj;
}

void first(Foo* obj) {
	// printFirst() outputs "first". Do not change or remove this line.
	printFirst();
	pthread_mutex_unlock(&obj->mutex_ab); 
}

void second(Foo* obj) {
	pthread_mutex_lock(&obj->mutex_ab); 
	// printSecond() outputs "second". Do not change or remove this line.
	printSecond();
	pthread_mutex_unlock(&obj->mutex_bc); 
}

void third(Foo* obj) {
	pthread_mutex_lock(&obj->mutex_bc); 
	// printThird() outputs "third". Do not change or remove this line.
	printThird();
}

void fooFree(Foo* obj) {
	// User defined data may be cleaned up here.
	pthread_mutex_destroy(&obj->mutex_ab); 
	pthread_mutex_destroy(&obj->mutex_bc); 
	free(obj);
}

int main(){
	int thread_num = 3;
	pthread_t tid[thread_num];
	Foo* obj = fooCreate();
	int ret = pthread_create(&tid[0], NULL, first, (void*)obj);
	ret = pthread_create(&tid[1], NULL, second, (void*)obj);
	ret = pthread_create(&tid[2], NULL, third, (void*)obj);
	for(int i=0; i<thread_num; i++){
		pthread_join(tid[i], NULL);
	}
	fooFree(obj);
	return 0;
}
