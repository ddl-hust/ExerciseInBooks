#include<iostream>
using std::cout;
using std::endl;
/*
*���ģ��ɱ�����������Լ������ɱ��������
*
*
**/
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest) 
{
	cout << "ģ��ɱ����������" << sizeof...(Args) << endl;
	cout << "�����ɱ��������:" << sizeof...(rest) << endl;
}
 // empty pack
int main()
{
	foo("hi");
	foo(1, 2, 3);
	system("pause");
	return 0;


}