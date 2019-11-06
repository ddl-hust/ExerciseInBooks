#include<iostream>
#include<vector>
#include<iterator> //使用end()
using namespace std;

//比较两个数组是否相等
//获取数组大小，按字母表顺序比较
bool compare(int* const b1,int*const e1,int* const b2,int*const e2)
{
	if (e1 - b1 != e2 - b2)return false; //长度不一致
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