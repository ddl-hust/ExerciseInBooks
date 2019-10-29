//
// Created by YTB on 2019/10/27.
//

#ifndef INC_16_28_UNIQUE_PTR_UNIQUE_PTR_H
#define INC_16_28_UNIQUE_PTR_UNIQUE_PTR_H

#include "../16.21/DeletePtr.h"
template <typename ,typename >class unique_pointer;
template <typename T,typename D> void swap(unique_pointer<T,D>&lhs,unique_pointer<T,D>&rhs);

/*
 * @brief std::unique_ptr like class template
 */
template <typename T,typename D=deletptr> //默认删除器是我们之前写的
class unique_pointer{
    friend void swap<T,D>(unique_pointer<T,D>&lhs,unique_pointer<T,D>&rhs);

public:
    unique_pointer(const unique_pointer&)= delete ;//unique_ptr特性阻止拷贝，赋值
    unique_pointer& operator=(const unique_pointer&)==delete;
   
    unique_pointer()= default;
    explicit unique_pointer(T*up):ptr(up);
    //move constructor
    unique_pointer(unique_pointer&&up) noexcept :ptr(up.ptr){up.ptr=nullptr;}
    // move assignment
	unique_pointer& operator =(unique_pointer&& rhs) noexcept;
    // std::nullptr_t assignment  u=nullptr 释放u指向对象，将u置为空
    unique_pointer& operator =(std::nullptr_t n) noexcept;


    //运算符重载
    T&operator *()const{return *ptr;}
    T*operator->()const {return &this->operator*();}
    operator bool() const{return ptr?true:false;}

private:
    T* ptr;

};
#endif //INC_16_28_UNIQUE_PTR_UNIQUE_PTR_H
