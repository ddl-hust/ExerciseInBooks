#include<iostream>
#include"ch6.h"
using namespace std;

int foo()
{
	static int count = 0;
	return count++;
}

int main()
{
	cout << foo() << endl;
	cout << foo() << endl;
	system("pause");
	return 0;
}