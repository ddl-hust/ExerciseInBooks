#include<iostream>
using std::cout;
/*测试数组引用形参传递，数组维度也是数组类型的一部分*/
void print(const int (&ia)[4])
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << ia[i] << std::endl;
	}
}

int main()
{
	int arr[] = { 1,2,3,4 };
	print(arr);
	return 0;
}

