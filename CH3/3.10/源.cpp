#include<iostream>
#include<string>
using namespace std;
/*ȥ�����������ʣ�µ��ַ���*/
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