#include<iostream>
using std::cout;
using std::endl;
/*
*��д�Լ��汾��print(),����ɱ����
*/

//�ǿɱ�����汾print(),�൱�ڵݹ���õ�base case
template<typename T>
std::ostream& print(std::ostream&os ,const T& t)
{
	return os << t << end;
}

template<typename T,typename ... Arg>
std::ostream& print(std::ostream& os,const T& t,const Arg&... arg)
{
	os << t << " , ";
	return print(os, arg...); //�ݹ���ã�������ÿ�εݼ�
}

int main()
{
	print(std::cout, 1);
	print(std::cout,1, 2, "123");
	system("pause");
}
