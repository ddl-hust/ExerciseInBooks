#include<iostream>
#include<string>
#include<sstream>
/**
 * �α�������ܺ���ģ�����صķ�������Ϥģ�����ص��õļ���ԭ��
*/
using namespace std;
template <typename T> string debug_rep(const T&t) {
	ostringstream ret;
	ret << t;
	return ret.str();
}
//ģ������
template<typename T> string debug_rep(T* p) {
	ostringstream ret;
	ret << "pointer��" << p;
	if (p)ret<<" "<< debug_rep(*p);
	else ret << "null pointer";
	return ret.str();
}

int main() {
	string s("hi");
	const string *sp = &s;
	cout << debug_rep(sp) << endl;
	return  0;
}