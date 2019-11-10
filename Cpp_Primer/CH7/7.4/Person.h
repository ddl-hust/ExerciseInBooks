//
// Created by YTB on 2019/11/9.
//

#ifndef INC_7_4_PERSON_H
#define INC_7_4_PERSON_H
#include<string>
using std::string;
struct  Person{
    string name;
    string address;

    string GetName() const{return name;}
    string GetAddress() const {return address;}
};
#endif //INC_7_4_PERSON_H
