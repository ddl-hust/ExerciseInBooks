#include <iostream>
/*
 * 处理足够大的sum,尾返回类型
 * int 范围
 * 一个问题：不用尾返回类型，要怎么做？
 */
//template <typename T>
//auto sum( T t1, T t2)-> decltype(t1+t2)
//{
//    return t1+t2;
//}
template<typename T>
auto sum(T lhs, T rhs) -> decltype( lhs + rhs)
{
    return lhs + rhs;
}
int main() {
    int a=2147483647;
    int b=2147483647;
//    double res=sum(a,b);
double  res=a+b;
    std::cout<<res<<std::endl;
    return 0;
}