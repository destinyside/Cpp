#include<iostream>
#include<ctime>
using namespace std;

//任何一非叶节点的关键字不大于或者不小于其左右孩子节点的关键字。

void HeapAdjust(int* &arr, int start, int end) {
	int tmp = arr[start];
	
	for (int i = 2 * start + 1; i <= end; i *= 2) {
		//因为假设根结点的序号为0而不是1，所以i结点左孩子和右孩子分别为2i+1和2i+2
		if ((i < end) && (arr[i] <= arr[i + 1])) {//左右孩子的比较
			i++;//i为较大的记录的下标
		}
		if (tmp > arr[i]) {//左右孩子中获胜者与父亲的比较
			break;
		}
		//将孩子结点上位，则以孩子结点的位置进行下一轮的筛选
		arr[start] = arr[i];
		start = i;
	}
	arr[start] = tmp;//插入最开始不和谐的元素
}

void HeapSort(int* &a, int n)
{
	//先建立大顶堆
	for (int i = n / 2; i >= 0; --i)
	{
		HeapAdjust(a, i, n);
	}
	////进行排序
	for (int i = n - 1; i > 0; --i)
	{
		//最后一个元素和第一元素进行交换
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;

		//然后将剩下的无序元素继续调整为大顶堆
		HeapAdjust(a, 0, i - 1);
	}
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
	int len = 10;
	int* arr = randomArray(len);
	HeapSort(arr, len);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr;
	system("pause");
}