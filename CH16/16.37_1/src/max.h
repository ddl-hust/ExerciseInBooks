//
// Created by ddl on 10/27/19.
//

#ifndef INC_16_37_1_MAX_H
#define INC_16_37_1_MAX_H
#include<iostream>
/**
 * ＠brief
 * 显式指定模板函数实参，用于求不同类型的　max()
*/
template<typename T>
T max(const T& t1,const T& t2)
{
    return t1>t2?t1:t2;
}

#endif //INC_16_37_1_MAX_H
