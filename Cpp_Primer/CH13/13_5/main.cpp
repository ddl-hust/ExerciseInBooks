#include <iostream>
#include <string>
using std::string;
//  Given the following sketch of a class, write a copy constructor that copies
//  all the members.
//  Your constructor should dynamically allocate a new string and copy the
//  object to which ps points,
//  rather than copying ps itself.
class HasPtr{
public:
    HasPtr(const string &s=string()):ps(new string(s)),i(0){}
    HasPtr(const HasPtr& lval)
    {
        ps = new string(*lval.ps); //深拷贝，类值行为拷贝
        i=lval.i;
    }
    //拷贝赋值运算符
    HasPtr&operator=(HasPtr& rhs){
        ps=new string (*rhs.ps);
        i= rhs.i;
        return *this;
    }
    ~HasPtr(){ delete ps;} //之所以要在析构函数里面delete ps 动态分配对象
                            //合成的析构函数不会delete a一个指针成员

private:
    string *ps;
    int i;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}