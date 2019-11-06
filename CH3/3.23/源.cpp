#include<string>
#include<vector>
#include<cctype>
#include<iostream>
using namespace std;

int main()
{
	vector<int> vec{1,2,3,4,5};

	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		*it *= 2;
		cout << *it << "  ";
	}
	return 0;
}