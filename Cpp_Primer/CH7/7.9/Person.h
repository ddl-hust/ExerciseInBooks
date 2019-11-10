//
// Created by YTB on 2019/11/9.
//
//给person 添加非成员函数 读入输出
#ifndef INC_7_9_PERSON_H
#define INC_7_9_PERSON_H
#include<string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::istream;
using std::ostream;

struct  Person{
    string name;
    string address;

    string GetName() const{return name;}
    string GetAddress() const {return address;}
};

istream& read(istream& is,Person& person){
    is>>person.name>>person.address;
    return is;
}
ostream& print(ostream& os,const Person & person){
    os<<person.name<<" "<<person.address;
    return os;
}


#endif //INC_7_9_PERSON_H
