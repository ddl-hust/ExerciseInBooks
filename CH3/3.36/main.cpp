#include<iostream>
#include<vector>
#include<iterator> //ʹ��end()
using namespace std;

//�Ƚ����������Ƿ����
//��ȡ�����С������ĸ��˳��Ƚ�
bool compare(int* const b1,int*const e1,int* const b2,int*const e2)
{
	if (e1 - b1 != e2 - b2)return false; //���Ȳ�һ��
	for (auto i = b1,j=b2; i < e1&&j<e2; ++i,++j)
	{
		if (*i != *j) return false;
	}
	return true;
}
int main()
{
	int a[] = { 1,2,3 };
	int b[] = { 1,2,3 };
	if(compare(begin(a), end(a), begin(b), end(b))) cout <<"a==b";
	else cout << "a!=b";

	return 0;

}