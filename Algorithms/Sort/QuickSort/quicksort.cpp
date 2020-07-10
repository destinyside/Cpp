#include<iostream>
#include<ctime>
using namespace std;

void quicksort(int* p, int left, int right) {
	if (left > right) {
		return;
	}
    int sign = p[left];
	int i = left;
	int j = right;
	while (i != j) {
		while (sign < p[j] && i < j) {
			j--;
		}
		if (j > i) {
			p[i] = p[j];
		}
        while (sign >= p[i] && i < j) {
			i++;
		}
		if(i < j){
			p[j]= p[i];
		}

	}
	p[i] = sign;
	quicksort(p, left, i - 1);
	quicksort(p, i + 1, right);

}

int* randomArray(int len) {
	srand((unsigned)time(0));
	int* tmp = new int[len] {0};
	for (int i = 0; i < len; i++) {
		tmp[i] = rand() % len;
	}
	return tmp;
}

void printArray(int* arr,int len){
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout<<endl;
}

int main() {
	int len = 15;
	int *arr = randomArray(len);
	printArray(arr, len);
	quicksort(arr, 0, len-1);
	printArray(arr, len);
	delete[] arr;
	//system("pause");
}
