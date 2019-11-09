/*
*编写可变参数版本的errormsg
*这里把之前的print(),debug_rep()都写到了一起，其实可以通过头文件调用的形式
*/
#include <iostream>
#include <string>
#include <sstream>
using std::ostream;
using std::string;
template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
	return os << t << std::endl;
}

template <typename T, typename... Arg>
ostream &print(std::ostream &os, const T &t, const Arg &... arg)
{
	os << t << " , ";
	return print(os, arg...); //递归调用，参数包每次递减
}
template <typename T>
string debug_rep(const T &t)
{
	std::ostringstream res; //字符串流对象
	res << t;
	return res.str();
}

template <typename... Arg>
void errmsg(ostream &os, const Arg &... res) //第一次包扩展，函数参数列表
{
	print(os, debug_rep(res)...); //第二次包扩展，函数调用实参列表
}

int main()
{
	errmsg(std::cout, 1, 2, "string");
	std::cout << std::endl;
	print(std::cout, 1, 2, "string");
	system("pause");
	return 0;
}
