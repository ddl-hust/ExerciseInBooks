#include "vec.h"
//拷贝构造函数
template <typename T>
vec<T>::vec(const vec &v)
{
    std::pair<T *, T *> newdata = alloc_n_copy(v.begin(), v.end());
    elements = newdata.first;
    first_free = newdata.second;
}

//拷贝赋值运算符
template <typename T>
vec<T> &vec<T>::operator=(const vec &rhs)
{
    std::pair<T *, T *> newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free(); //释放拷贝之前资源内存
    elements = newdata.first;
    first_free = cap = newdata.second; //why cap ==second
    return *this;
}
template <typename T>
vec<T>::~vec<T>() { free(); }

template <typename T>
void vec<T>::push_back(const T &data)
{
    chk_n_alloc(); //检查内存是否够用
    alloc.construct(first_free++,data);

}

template <typename T>
std::pair<T*,T*> vec<T>::alloc_n_copy(T *b, T *e)
{
    auto data=alloc.allocate(e-b);
    return {data,std::uninitialized_copy(b,e,data)};
}
//释放内存空间
template <typename  T>
void vec<T>::free()
{
    if(elements){
        for (auto p = first_free; p !=elements ; ) {
            alloc.destroy(--p); //destory 运行T析构函数，从后向前释放元素内存空间
        }
        alloc.deallocate(elements,cap-elements); //释放vec对象内存空间
    }
}




