#include <iostream>
#include "fun_pointer.h"
int main() {
    vector<fooP> vec;
    vec.push_back(add);
    vec.push_back(sub);
    vec.push_back(mut);
    vec.push_back(divide);
    for(auto it =vec.begin();it!=vec.end();it++)
    {
        std::cout<<(*it)(1,2)<<std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}