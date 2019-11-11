//
// Created by ddl on 11/11/19.
//

#ifndef INC_8_6_SALES_DATA_H
#define INC_8_6_SALES_DATA_H
#include<iostream>
#include<string>
using namespace std;
class Sales_data{
public:
    friend istream& read(istream&is,Sales_data*item);
    friend  ostream& print(ostream& os,Sales_data* data);

    Sales_data()= default;
    Sales_data(const string s):bookno(s){}
    Sales_data(istream&is){read(is,this);}

    string isbn(){ return  bookno;}
    Sales_data& combine(const Sales_data& rhs)
    {
        this->revenue+=rhs.revenue;
        this->units_sold+=rhs.units_sold;
        return *this;
    }

private:
    string bookno;
    double revenue=0;
    double units_sold=0;
};

//普通函数
istream& read(istream&is,Sales_data*item)
{
    is>>item->bookno>>item->units_sold>>item->revenue;
    return is;
}

ostream& print(ostream& os,Sales_data* data)
{
    os<<data->bookno<<data->units_sold<<data->revenue<<endl;
    return os;
}












#endif //INC_8_6_SALES_DATA_H
