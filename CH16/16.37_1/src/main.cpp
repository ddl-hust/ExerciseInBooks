#include <iostream>
#include "max.h"
int main() {
    int left=1;
    double right=2.0;
    auto res=max<int>(right,left);
    std::cout<<"the max value :"<<res<<std::endl;
    return 0;
}