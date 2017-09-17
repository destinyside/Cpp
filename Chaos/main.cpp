#include<iostream>
using namespace std;
int main() {
	std::cout << "/*";
	std::cout << "*/";
	std::cout << /* "*/"/*"/*"*/;
	unsigned u = 10;
	int i = -21;
	std::cout << i + i << std::endl;
	std::cout << u + i << std::endl;
	//int i0 = 123;
	//int *i1 = &i0;
	//int **i2 = &i1;
	//int ***i3 = &i2;
	//int ****i4 = &i3;
	//std::cout << i0 << i1 << i2 << i3 << i4 << *i1 << **i2 << ***i3 << ****i4 << std::endl;

	std::cerr << "错误，自动引发的错误！" << std::endl;
	int value, sum = 0;
	while (std::cin>>value)//CTRL+Z 输入结束
	{
		sum += value;
		if (value == 0) {
			break;
		}
	}
	std::cout << "The sum of value is " << sum << endl;
	system("pause");
}