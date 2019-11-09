#include<string>
#include<vector>
#include<cctype>
#include<iostream>
using namespace std;

int main()
{
	string s;
	vector<string> vec;
	while (cin>>s)
	{
		vec.push_back(s);
	}


	for (auto it = vec.begin(); it != vec.end()&&!it->empty(); it++)
	{
		for(auto &c:*it)
		{
			c = toupper(c);
		}
		cout << *it << endl;
	}
	return 0;
}