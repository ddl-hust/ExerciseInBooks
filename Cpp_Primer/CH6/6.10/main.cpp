#include<iostream>
using  std::cout;
using  std::endl;

/*����ָ�뽻����������ֵ*/
template<typename T>
void swap(T* a,T* b)
{
	T temp = *b;
	*b = *a;
	*a = temp;

}
int main()
{
	int a = 1,b=2;
	cout << "a:" << a << "b:" << b<<endl;
	swap(&a, &b);
	cout << "after swap " << "a:" << a << "b:" << b;
	system("pause");
	return 0;
}
