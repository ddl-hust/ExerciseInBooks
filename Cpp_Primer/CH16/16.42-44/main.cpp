#include <iostream>
#include <typeinfo>
template <typename T> void g(T&&val)
{
    std::cout<<"类型 :"<< typeid(val).name()<<std::endl;
}
int main() {
    int i=0;
    const int ci=i;
    const int *  pi=&ci;
    auto x=i*ci;
    i=ci;
    g(res); //top　level
    return 0;
}