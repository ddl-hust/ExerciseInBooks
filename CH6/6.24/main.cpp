#include<iostream>
using std::cout;
/*�������������βδ��ݣ�����ά��Ҳ���������͵�һ����*/
void print(const int (&ia)[4])
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << ia[i] << std::endl;
	}
}

int main()
{
	int arr[] = { 1,2,3,4 };
	print(arr);
	return 0;
}

