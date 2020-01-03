#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
typedef struct {
	int n;
	pthread_mutex_t mutex_fb;
	pthread_mutex_t mutex_bf;
} FooBar;

void printFoo(){printf("foo");}
void printBar(){printf("bar\n");}

FooBar* fooBarCreate(int n) {
	FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
	obj->n = n;
	pthread_mutex_init(&obj->mutex_fb, NULL);
	pthread_mutex_init(&obj->mutex_bf, NULL);
	//pthread_mutex_lock(&obj->mutex_fb);
	pthread_mutex_lock(&obj->mutex_bf);
	return obj;
}

void foo(FooBar* obj) {

	for (int i = 0; i < obj->n; i++) {

		pthread_mutex_lock(&obj->mutex_fb);
		// printFoo() outputs "foo". Do not change or remove this line.
		printFoo();
		pthread_mutex_unlock(&obj->mutex_bf);
	}
}

void bar(FooBar* obj) {

	for (int i = 0; i < obj->n; i++) {

		pthread_mutex_lock(&obj->mutex_bf);
		// printBar() outputs "bar". Do not change or remove this line.
		printBar();
		pthread_mutex_unlock(&obj->mutex_fb);
	}
}

void fooBarFree(FooBar* obj) {
	pthread_mutex_destroy(&obj->mutex_fb);
	pthread_mutex_destroy(&obj->mutex_bf);
	free(obj);
}

void t(char* msg){
	printf("%s", msg);
}

int main(int argc, char* argv[]){
	int num = 2;
	if(argc > 1){
		num = atoi(argv[1]);
	}
	int thread_num = 2;
	pthread_t tid[thread_num];
	FooBar* obj = fooBarCreate(num);
	int ret = pthread_create(&tid[0], NULL, foo, (void*)obj);
	ret = pthread_create(&tid[1], NULL, bar, (void*)obj);
	for(int i=0; i<thread_num; i++){
		        pthread_join(tid[i], NULL);
	}
	fooBarFree(obj);
	return 0;

}
