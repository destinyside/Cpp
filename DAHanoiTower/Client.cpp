#include<iostream>
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
int main() {
	char A = 'A';
	char B = 'B';
	char C = 'C';
	move(3, A, B, C);
	system("pause");
}