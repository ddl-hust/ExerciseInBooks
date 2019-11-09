#include<string>
#include<vector>
#include<cctype>
#include<iostream>
using namespace std;

void main()
{
	string s;
	vector<string> vec_s;
	//读入数据
	while(cin>>s)
	{
		vec_s.push_back(s);
	}
	//改变大小写
	for(auto &str:vec_s)
	{
		for(auto& c:str)
		{
			c = toupper(c);
		}
	}
	//输出
	for (auto v:vec_s)
	{
		cout << v << endl;
	}
	system("pause");
}