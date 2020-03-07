#include<iostream>
using namespace std;

// Forward declaration of guess API.
// // @param num, your guess
// // @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int n,pick;

int guess(int num){
	if(num > pick){
		return -1;
	} else if(num < pick){
		return 1;
	} else {
		return 0;
	}
}
class Solution {
	public:
		int guessNumber(int n) {
			int num;
			int i=1,j=n,m=(i+j)/2;
			num=guess(m);
				cout<<"i="<<i<<",j="<<j<<",m="<<m<<",num="<<num<<endl;
			while(num!=0){
				cout<<"i="<<i<<",j="<<j<<",m="<<m<<",num="<<num<<endl;
				if(num==-1){
					j=m;
				} else {
					i=m+1;
				}
				m=(i+j)/2;
				num=guess(m);
			}
			return m;
		}
};


int main(int argc, char* argv[]){
	srand((unsigned)time(0));
	if(argc > 2){
		n = atoi(argv[1]);
		pick = atoi(argv[2]);
	} else if(argc > 1){
		n = atoi(argv[1]);
		pick = rand() % n;
	} else {
		n = rand() % 100;
		pick = rand() % n;
	}
	cout<<"n="<<n<<",pick="<<pick<<endl;
	Solution* s = new Solution;
	int result = s->guessNumber(n);
	cout<<"result="<<result<<endl;
	delete s;
	return EXIT_SUCCESS;
}
