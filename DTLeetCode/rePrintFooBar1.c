#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<pthread.h>

void printFoo(){printf("foo");}
void printBar(){printf("bar\n");}
typedef struct {
	int n;
	bool flag;
	pthread_mutex_t mutex;  
	pthread_cond_t  cond;  
} FooBar;

FooBar* fooBarCreate(int n) {
	FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
	obj->n = n;
	obj->flag = true;
	pthread_mutex_init(&obj->mutex, NULL);
	pthread_cond_init(&obj->cond,NULL);
	return obj;
}

void foo(FooBar* obj) {

	for (int i = 0; i < obj->n; i++) {
		pthread_mutex_lock(&obj->mutex);
		while (false == obj->flag) {
			pthread_cond_wait(&obj->cond,&obj->mutex);
		}
		// printFoo() outputs "foo". Do not change or remove this line.
		printFoo();
		obj->flag = false;
		pthread_cond_signal(&obj->cond);
		pthread_mutex_unlock(&obj->mutex);
	}
}

void bar(FooBar* obj) {

	for (int i = 0; i < obj->n; i++) {
		pthread_mutex_lock(&obj->mutex);
		while (true == obj->flag) {
			pthread_cond_wait(&obj->cond,&obj->mutex);
		}
		// printBar() outputs "bar". Do not change or remove this line.
		printBar();
		obj->flag = true;
		pthread_cond_signal(&obj->cond);
		pthread_mutex_unlock(&obj->mutex);
	}
}

void fooBarFree(FooBar* obj) {
	if (NULL != obj) {}
	pthread_mutex_destroy(&obj->mutex);
	pthread_cond_destroy(&obj->cond);
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
