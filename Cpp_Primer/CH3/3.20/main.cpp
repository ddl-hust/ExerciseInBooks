#include<string>
#include<vector>
#include<cctype>
#include<iostream>
using namespace std;

void main()
{
	int number;
	vector<int> vec_i;
	//��������
	while (cin >> number)
	{
		vec_i.push_back(number);
	}
	for (size_t i = 0; i < vec_i.size()-1; i++)
	{
		cout << vec_i[i] + vec_i[i + 1]<<"  "; //�������Ԫ��
	}
	for (size_t i = 0; i < vec_i.size()/2; i++)
	{
		cout << vec_i[i] + vec_i[vec_i.size() - 1 - i] << "  "; 
	}
	system("pause");
}