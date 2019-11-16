#include <iostream>
#include<list>
//list 里面重复元素
int main() {
    std::list<int>lst{1,2,2,1,3};
    lst.sort();
    lst.unique();
    for(auto c: lst) std::cout<<c<<" ";
    return 0;
}