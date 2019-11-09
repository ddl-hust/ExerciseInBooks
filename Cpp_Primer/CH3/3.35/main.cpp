#include<iostream>
#include<iterator> // π”√end()
using namespace std;
int main()
{
	int a[] = { 1,2,3 };
	for (auto c : a)cout << c << "  ";
	auto e = end(a);
	for (auto i = a; i != e; i++)
	{
		*i = 0;
		cout << *i << "  ";
	}

	return 0;

}