
#ifndef INC_7_41_SCREEN_DELEGATE_H
#define INC_7_41_SCREEN_DELEGATE_H

/*
 * 练习委托构造函数的执行顺序，先执行委托构造初始值列表，函数体
 */
#include<string>
#include<iostream>
using namespace std;
class Sales_data{
public:
    Sales_data(const string bookno,const double cnt,const double number):BookNo(bookno),unit_sold(cnt),revenue(cnt*number){
        cout<<"委托构造函数"<<endl;
    }
    Sales_data():Sales_data(" ",0,0){
        cout<<"默认构造函数"<<endl;
    }
    Sales_data(istream& is):Sales_data(" ",0,0){
        is>>BookNo>>unit_sold>>revenue;
        cout<<"cin constructor"<<endl;
    }

private:
    string BookNo;
    double unit_sold;
    double revenue;
};
#endif //INC_7_41_SCREEN_DELEGATE_H
