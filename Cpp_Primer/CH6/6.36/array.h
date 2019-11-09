
#ifndef INC_6_36_ARRAY_H
#define INC_6_36_ARRAY_H

#include <iostream>
#include <string>
/*
 * 比较几种不同的返回数组引用(或指针)函数申明
 */
//别名　
using arrT= std::string[10];
arrT & foo();

//尾返回
auto foo1()->std::string(&)[10];

//decltype
std::string arrS[10];
decltype(arrS)& foo2();

#endif //INC_6_36_ARRAY_H
