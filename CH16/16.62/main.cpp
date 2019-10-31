#include <iostream>
#include "sale_data.h"
#include <string>
#include <unordered_set>

//大开命名空间std,以便特例化hash
namespace std
{
    template <>
    struct hash<Sales_data>
            {
                typedef size_t  return_type;
                typedef Sales_data argument_type;
                size_t  operator() (const Sales_data&s)const; //重载调用运算符，接受一个容器关键字类型的对象，返回size_t
            };
    size_t  hash<Sales_data>::operator()  (const Sales_data &s) const
            {
        return hash<string>()(s.bookNo)^hash<unsigned >()(s.units_sold)^hash<double>()(s.revenue); //异或
            }
}

int main() {
    Sales_data sales_data1("001-01", 1, 100);
    Sales_data sales_data2;
    Sales_data sales_data3("001-02");

    std::cout << std::hex << std::hash<std::string>()("001-01") << std::endl;
    std::cout << std::hex << std::hash<unsigned>()(1) << std::endl;
    std::cout << std::hex << std::hash<double>()(100) << std::endl;

    std::unordered_multiset< Sales_data> SDset;
    SDset.emplace(sales_data1);
    SDset.emplace("001-03", 1, 200);
    SDset.emplace(sales_data3);
    for( const auto &item : SDset)
        std::cout << "the hash code of " << item.isbn() <<":\n0x" << std::hex << std::hash<Sales_data>()(item) << "\n";
    return 0;
}