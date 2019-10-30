#include <iostream>
using std::cout;
using std::endl;
/*
*编写自己版本的print(),输出可变参数
*/

//非可变参数版本print(),相当于递归调用的base case
template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
	return os << t << end;
}

template <typename T, typename... Arg>
std::ostream &print(std::ostream &os, const T &t, const Arg &... arg)
{
	os << t << " , ";
	return print(os, arg...); //递归调用，参数包每次递减
}

int main()
{
	print(std::cout, 1);
	print(std::cout, 1, 2, "123");
	system("pause");
}
