#include <iostream>
/*
 * 写一个自己版本的share_ptr
 * */
template <typename T>
class my_sp{
public:
    //默认构造函数,即不带参数
    my_sp():count(nullptr),p(nullptr){}
    //构造函数
    explicit my_sp(T* pt):p(pt),count(new size_t(1)){}
    //拷贝构造函数,构造函数都没有返回值
    my_sp(const my_sp& sp):p(sp.p),count(sp.count)
    {
        if(count) ++(*count); //引用计数加1
    }
    //拷贝赋值运算符
    my_sp& operator=(const my_sp&);
    ~my_sp();

    //运算符重载
    T&operator*(){return *p;};
    T&operator*() const{return *p;}

private:
    size_t*  count; //引用计数
    T* p; //管理对象的指针
};
template <typename T>
my_sp<T>& my_sp<T>::operator=(const my_sp<T>& rhs){
    if(rhs.count) ++*rhs.count; //将运算符右边引用数加1
    if(count&& --*count==0) //运算符左侧计数减一之后，引用数为0，释放其资源
    {
        delete count;
        delete p;
    }
    p=rhs.p;
    count=rhs.count;
    return *this;
}

template <typename T>
my_sp<T>::~my_sp()
{
    if(count&&--*count==0){
        delete count;
        delete p;
        std::cout<<"deconstruct "<<std::endl;
    }
}


int main() {
    my_sp<int> ptr(new int(1));
    my_sp<int> ptr2(new int(2));
    my_sp<int> ptr3=ptr;
    std::cout<<"ptr cuunt:"<<*ptr<<std::endl;
    ptr=ptr2;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}