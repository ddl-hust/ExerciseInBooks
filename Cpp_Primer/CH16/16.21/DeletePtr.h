//
// Created by YTB on 2019/10/27.
//

#ifndef INC_16_21_DELETEPTR_H
#define INC_16_21_DELETEPTR_H
#include <iostream>
using namespace std;
class deletptr
{
public:
    deletptr(ostream &s=std::cerr):os(s){} //默认构造函数，默认输出错误流参数
    template<typename T> void operator()(T*p) const
    {
        os<<"delete unique_ptr"<<endl;
        delete p;
    }
private:
    ostream &os;
};


#endif //INC_16_21_DELETEPTR_H
