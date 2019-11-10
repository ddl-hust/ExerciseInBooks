//
// Created by YTB on 2019/11/9.
//

#ifndef INC_7_15_PERSON_H
#define INC_7_15_PERSON_H
#include<string>
#include <iostream>
/*
 * 定义在之前基础上定义构造函数
 */
using std::string;
using std::cout;
using std::cin;
using std::istream;
using std::ostream;

struct  Person;
istream& read(istream&,Person&); //前置声明

struct  Person{
    string name;
    string address;
    Person()= default; //默认构造函数
    Person(const string &n,const string &addr):name(n),address(addr){}
    Person(std::istream& is)
    {
        read(is,*this);
    }
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

#endif //INC_7_15_PERSON_H
