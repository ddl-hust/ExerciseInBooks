#include<iostream>
using namespace std;

/*用户输入一个数字，返回其阶乘*/

long int fact(std::istream&os)
{
	cout << "please input a number" << endl;
	int number;
	os >> number;
	long int result = 1;
	while (number)
	{
		result *= number;
		number--;
	}
	cout << "the result of fact:" << result;
	return result;
}

int main() {
	long int res = fact(cin);
	
	return 0;
}