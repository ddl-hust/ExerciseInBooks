

#ifndef INC_6_54_56_FUN_POINTER_H
#define INC_6_54_56_FUN_POINTER_H
#include <vector>
/*
 * 函数指针的声明与使用
 */
using std::vector;
using fooP=int(*)(int,int);

int add(int a,int b) {return a+b;}
int sub(int a,int b) { return  a-b;}
int mut(int a,int b) { return  a*b;}
int divide(int a,int b)
{
    if(b!=0) return a/b;
    else return 0;
}

#endif //INC_6_54_56_FUN_POINTER_H
