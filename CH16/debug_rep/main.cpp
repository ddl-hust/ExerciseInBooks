#include<iostream>
#include<string>
#include<sstream>
/**
 * 课本里面介绍函数模板重载的范例，熟悉模板重载调用的几点原则
*/
using namespace std;
template <typename T> string debug_rep(const T&t) {
	ostringstream ret;
	ret << t;
	return ret.str();
}
//模板重载
template<typename T> string debug_rep(T* p) {
	ostringstream ret;
	ret << "pointer：" << p;
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