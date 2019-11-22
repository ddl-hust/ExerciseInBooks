#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using std::vector;
using std::string;
using std::cout;
using std::endl;
//HasPtr 类值行为 添加swap,用swap改写拷贝赋值运算符,排序
class HasPtr{
public:
    friend void swap(HasPtr& lval,HasPtr& rval);
    HasPtr(const std::string& s = std::string(),int i=0) : p(new std::string(s)), id(i){}
    HasPtr(const HasPtr& rval)
    {
        p = new string(*rval.p);
        id=rval.id;
    }
    HasPtr& operator= ( HasPtr rval ){
        using std::swap;
        swap(*this,rval);
        return *this;

    }
    ~HasPtr(){delete p;}
    void show(){std::cout<<*p<<std::endl;}
    bool operator <(const HasPtr& rval){
        return id<rval.id;
    }
private:
    string* p;
    int id;
};
void swap(HasPtr& rval,HasPtr& lval){
    using std::swap;
    swap(rval.p,lval.p);
    swap(rval.id,lval.id);
    std::cout<<"swap(HasPtr& rval,HasPtr& lval)"<<std::endl;
}
int main() {
    vector<HasPtr>vec;
   HasPtr ptr1("ddl",1);
   HasPtr ptr2("hi",2);
    HasPtr ptr3("world",3);
    vec={ptr2,ptr1,ptr3};
    cout<<"before sort"<<endl;
    for(auto c:vec) c.show();
    std::sort(vec.begin(),vec.end());
    cout<<"after sort"<<endl;
    for(auto c:vec) c.show();
    return 0;
}