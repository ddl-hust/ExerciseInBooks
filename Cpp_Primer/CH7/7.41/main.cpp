#include <iostream>
#include "Sales_data_delegate.h"
int main() {
    Sales_data sal1;
    Sales_data sal2("1001",1,1);
    Sales_data sal3(cin);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}