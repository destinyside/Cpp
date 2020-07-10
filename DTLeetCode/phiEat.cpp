#include<iostream>
#include<functional>
#include<pthread.h>
using namespace std;

class DiningPhilosophers {
	private:
	public:
		DiningPhilosophers() {
		}

		function<void()> pickLeftFork = []{cout<<"philosopher "<<n<<"picks left fork";};		
		function<void()> pickRightFork = []{cout<<"philosopher "<<n<<"picks right fork";};		
		function<void()> eat = []{cout<<"philosopher "<<n<<"eating";};		
		function<void()> putLeftFork = []{cout<<"philosopher "<<n<<"puts left fork";};		
		function<void()> putRightFork = []{cout<<"philosopher "<<n<<"puts right fork";};		

		void wantsToEat(int philosopher,
				function<void()> pickLeftFork,
				function<void()> pickRightFork,
				function<void()> eat,
				function<void()> putLeftFork,
				function<void()> putRightFork) {
			pickLeftFork();
			pickRightFork();
			eat();
			putLeftFork();
			putRightFork();

		}
};

int main(int argc, char* argv[]){
	int num = 5;
	if(argc > 1){
		num = atoi(argv[1]);
	}
	int thread_num = 5;
	pthread_t tid[thread_num];
	DiningPhilosophers phis[5];
	int ret = pthread_create(&tid[0], NULL, zero, (void*)obj);
	ret = pthread_create(&tid[1], NULL, even, (void*)obj);
	ret = pthread_create(&tid[2], NULL, odd, (void*)obj);
	for(int i=0; i<thread_num; i++){
		pthread_create(&tid[i], NULL, phis[i].w
	}
	for(int i=0; i<thread_num; i++){
		pthread_join(tid[i], NULL);
	}
	zeroEvenOddFree(obj);
	return 0;

}

