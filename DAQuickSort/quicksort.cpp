#include<iostream>
#include<ctime>
using namespace std;

void quicksort(int* &p, int left, int right) {
	if (left > right) {
		return;
	}
	int sign = p[left];
	int i = left;
	int j = right;
	while (i != j) {
		while (sign <= p[j] && i < j) {
			j--;
		}

		while (sign >= p[i] && i < j) {
			//遇到不满足的数就停止循环，接着进行交换

			i++;
		}

		if (i < j) {
			int tmp = p[i];
			p[i] = p[j];
			p[j] = tmp;
		}
	}
	int tmp = p[i];
	p[i] = p[left];
	p[left] = tmp;

	quicksort(p, left, i - 1);
	quicksort(p, i + 1, right);

}

int* randomArray(int len) {
	//随机生成数组

	srand((unsigned)time(0));
	int* tmp = new int[len] {0};
	for (int i = 0; i < len; i++) {
		tmp[i] = rand() % len;
	}
	return tmp;
}

int main() {
	int len = 20;
	int *arr = randomArray(len);
	quicksort(arr, 0, len-1);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr;
	system("pause");
}