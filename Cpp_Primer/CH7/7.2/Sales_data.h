//
// Created by YTB on 2019/11/9.
//
//添加isbn,combine()，成员函数

#ifndef INC_7_1_SALES_DATA_H
#define INC_7_1_SALES_DATA_H
#include <string>
struct Sales_data{
    std::string BookNo;
    unsigned units_sold=0;
    double  revenue=0;
    std::string isbn() const{return BookNo;}
    Sales_data& combine(Sales_data&);
};

Sales_data &Sales_data::combine(Sales_data & rhs) {
    units_sold+=rhs.units_sold;
    revenue+=rhs.revenue;
    return *this;
}


#endif //INC_7_2_SALES_DATA_H
