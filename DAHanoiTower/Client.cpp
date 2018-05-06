#include<iostream>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
void move(int n, char A, char B, char C) {
    if (n <= 1) {
	cout << "move : " << A << " --> " << C << endl;
    }
    else {
	move(n - 1, A, C, B);
	cout << "move : " << A << " --> " << C << endl;
	move(n - 1, B, A, C);
    }
}
int main(int argc, char** argv) {
    int step = 3;
    int ch = 0;
    while((ch = getopt(argc, argv, "n:")) != -1){
	switch(ch){
	    case 'n' : {
			   step = atoi(optarg);
			   cout<< "the step is " << step <<endl;
			   break;
		       }
	    default : {
			  break;
		      }
	}
    }

    char A = 'A';
    char B = 'B';
    char C = 'C';
    move(step, A, B, C);
    system("pause");
}
