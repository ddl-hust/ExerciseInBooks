#include "vec.h"
#include <iostream>
#include <string>
using std::cout;
int main()
{
    vec<int>vec1;
    vec<std::string>vec_str;
    vec1.push_back(1);
    cout<<vec1.size()<<std::endl;
    cout<<*vec1.begin()<<std::endl;
    std::cout<<"hello world";
    return 0;
}