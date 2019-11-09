#include"src/max.cpp"
#include<iostream>
/**
 * 显式给出函数模板实参，用于max()处理不同类型比较，即能做类型转化，比如 long->int
 * 采用多源文件，链接库形式编译
*/
int main()
{
    int left=1;
    double right=2.0;
    auto res=max<int>(right,left);
    std::cout<<"the max value :"<<res<<std::endl;
    return 0;
}