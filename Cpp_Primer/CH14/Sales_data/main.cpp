#include <iostream>
#include "Sales_data.h"
int main()
{
    Sales_data sale("ddl");
    std::cout << sale << std::endl;
    std::cout << "Hello, World!" << std::endl;
    std::cout << static_cast<string>(sale);

    return 0;
}