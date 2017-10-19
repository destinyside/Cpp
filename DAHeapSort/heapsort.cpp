#include<iostream>
#include<ctime>
using namespace std;

//任何一非叶节点的关键字不大于或者不小于其左右孩子节点的关键字。

void HeapAdjust(int* &a, int i, int size)  {//调整堆  
	int lchild = 2 * i;       //i的左孩子节点序号 
	int rchild = 2 * i + 1;     //i的右孩子节点序号 
	int max = i;            //临时变量 
	if (i <= size / 2)          //如果i不是叶节点就不用进行调整 
	{
		if (lchild <= size&&a[lchild]>a[max])
		{
			max = lchild;
		}
		if (rchild <= size&&a[rchild]>a[max])
		{
			max = rchild;
		}
		if (max != i)
		{
			swap(a[i], a[max]);
			HeapAdjust(a, max, size);    //避免调整之后以max为父节点的子树不是堆 
		}
	}
}

void HeapSort(int* &a, int n)
{
	//先建立大顶堆
	for (int i = n / 2; i >= 0; --i)
	{
		HeapAdjust(a, i, n);
	}
	////进行排序
	for (int i = n-1; i > 0; --i)
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
	int* arr = randomArray(len); //new int[len] {7,7,0,9,1,7,2,9,9,1};
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	HeapSort(arr, len);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
	system("pause");
}