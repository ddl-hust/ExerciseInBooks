#include <iterator>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

int main()
{
	vector<int> vec{1, 2, 3, 4};
	for (auto it = vec.crbegin(); it != vec.crend(); it++)
		cout << *it << " ";
	//10.35
	for (auto it = vec.cend(); it != vec.cbegin();)
		cout << *--it << " "; 

	//10.36
	list<int> lst{1, 0, 1, 2, 0, 6};
	auto res = find(lst.rbegin(), lst.rend(), 0);
	cout << *res.base();

	//
	return 0;
}