//
// Created by YTB on 2019/11/9.
//

#ifndef INC_7_22_PERSON_PRIVATE_H
#define INC_7_22_PERSON_PRIVATE_H

//给person 隐藏细节
#include<string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::istream;
using std::ostream;
//前置声明
class Person;
istream& read(istream&,Person&);
ostream& print(ostream& os,const Person & person);

class  Person{
    friend istream& read(istream&,Person&);
    friend ostream& print(ostream& os,const Person & person);

private:
    string name;
    string address;
public:
    Person()= default;
    Person(const string& n,const string&addr):name(n),address(addr){}
    Person(istream&is){
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




#endif //INC_7_22_PERSON_PRIVATE_H
