#include<string>
#include<vector>
#include<cctype>
#include<iostream>
using namespace std;

int main()
{
	int a[10];
	for (size_t i = 0; i < 10; i++)
	{
		a[i] = i;
	}
	int b[10];
	for (size_t j = 0; j < 10; j++)
	{
		b[j] = a[j];
		cout << "a :" << a[j] << "b : " << b[j]<<endl;
	}

	return 0;
}