#include <iostream>
#include <vector>
#include <initializer_list>
//A good way to understand copy-control members and
// constructors is to define a simple class with these members in which each
// member prints its name:
struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&)
    {
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(const X& rx, X x) //x 作为值传递，当离开函数作用域时候会调用析构函数
{
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx); //X(const X&)
    vec.push_back(x); // X(const X&)
}

int main()
{
    X* px = new X; //X()
    f(*px, *px);  //X(const X&)
    delete px;

    return 0;
}