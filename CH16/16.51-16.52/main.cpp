#include<iostream>
using std::cout;
using std::endl;
/*
*输出模板可变参数个数，以及函数可变参数个数
*
*
**/
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest) 
{
	cout << "模板可变参数个数：" << sizeof...(Args) << endl;
	cout << "函数可变参数个数:" << sizeof...(rest) << endl;
}
 // empty pack
int main()
{
	foo("hi");
	foo(1, 2, 3);
	system("pause");
	return 0;


}