#include<iostream>
#include<typeinfo>
using namespace std;
/*
* º¯ÊıÄ£°åÖØÔØ
*/
template<typename T> void f(T)
{
	cout << "T " << typeid(T).name() << endl;
}

template<typename T> void f(const T*)
{
	cout << "const T* " << typeid(const T*).name() << endl;
}

template<typename T> void f(T *)
{
	cout << "T * " << typeid(T*).name() << endl;
}

int main() {
	int i = 42,*p= &i;
	const int ci = 0, *pi = &ci;
	f(42);
	f(p);
	f(ci);
	f(pi);
	return 0;

}
