#include<string>
#include<vector>
#include<cctype>
#include<iostream>
using namespace std;

void main()
{
	string s;
	vector<string> vec_s;
	//��������
	while(cin>>s)
	{
		vec_s.push_back(s);
	}
	//�ı��Сд
	for(auto &str:vec_s)
	{
		for(auto& c:str)
		{
			c = toupper(c);
		}
	}
	//���
	for (auto v:vec_s)
	{
		cout << v << endl;
	}
	system("pause");
}