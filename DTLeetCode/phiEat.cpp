#include<iostream>
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

int main(){
	DiningPhilosophers phi

}
