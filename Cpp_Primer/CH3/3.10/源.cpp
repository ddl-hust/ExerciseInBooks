#include<iostream>
#include<string>
using namespace std;
/*去除标点符号输出剩下的字符串*/
int main()
{
	string s,res;
	getline(cin,s);
	
	for(char& c:s)
	{
		if (!ispunct(c)) res += c;
	}
	cout << res << endl;
	return 0;
}