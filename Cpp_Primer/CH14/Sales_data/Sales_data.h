//
// Created by YTB-002 on 2019/11/26.
//
#include<string>
#include<iostream>
using std::string;
using std::cout;
#ifndef SALES_DATA_SALES_DATA_H
#define SALES_DATA_SALES_DATA_H

class Sales_data{
public:
    friend std::ostream&operator<< (std::ostream&,const Sales_data&);
    friend std::istream&operator>> (std::istream&, Sales_data&);

    Sales_data(const string& s,double n,size_t u):bookid(s),unit_sold(u),revenue(u*n){}
    Sales_data():Sales_data("",0,0){} //委托构造
    Sales_data(const string& s):Sales_data(s,0,0){}
    //运算符重载
    Sales_data&operator= (const Sales_data&);
    Sales_data&operator+=(Sales_data&);

    //类型转化运算符
    operator double() const {return revenue;}
    operator string() const {return bookid;}



private:
    string bookid;
    double revenue=0.0;
    size_t unit_sold=0;
};
Sales_data &Sales_data::operator=(const Sales_data& rval) {
    bookid=rval.bookid;
    unit_sold=rval.unit_sold;
    revenue=rval.revenue;
    return *this;
}

std::ostream& operator<<(std::ostream&os, const Sales_data& data)
{os<<data.bookid<<" "<<data.revenue<<" "<<data.unit_sold;
    return os;
} //<<  binary operation
std::istream& operator>>(std::istream& is,Sales_data& data){
    double price;
    is>>data.bookid>>data.unit_sold>>price;
    if(is) data.revenue=price*data.unit_sold;
    else data=Sales_data(); //流读取失败，将对象设为默认状态
}



#endif //SALES_DATA_SALES_DATA_H