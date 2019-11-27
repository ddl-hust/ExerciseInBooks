
#include"String.h"
#include<algorithm>
#include <iostream>
std::pair<char*, char*> String::alloc_n_copy(const char*b, const char*e){
    auto data=alloc.allocate(e-b);
    return {data,std::uninitialized_copy(b,e,data)};
}

 void String::range_initializer(const char*b, const char*e)
 {
     auto newdata=alloc_n_copy(b,e);
     elements=newdata.first;
     end=newdata.second;
 }
//c-style string constructor
String::String(const char* s)
{
    char* sl = const_cast<char*>(s); //remove const for next step ++
    while (*sl) ++sl; //when meet \0 jump  put loop
    range_initializer(s, ++sl); //++ for last past end
    std::cout<<"String::String(const char* s)"<<std::endl;
}

String::String(const String& rval){
    range_initializer(rval.elements,rval.end);
    std::cout << "copy constructor" << std::endl;
 }

void String::free()
{
    if(elements){
    for (auto i = elements; i < end;)
    {
        alloc.destroy(i++);
    }}
    alloc.deallocate(elements,end-elements);
    
}
String::~String(){
    free();
}

String& String::operator=(const String& rval){
    auto newdata=alloc_n_copy(rval.elements,rval.end);
    free();
    elements=newdata.first;
    end=newdata.second;
    std::cout << "copy assign operator" << std::endl;
    return *this;
}
//算术运算符重载
bool operator==(const String& lval,const String& rval){
    return (lval.size()==rval.size()&& std::equal(lval.begin(),lval.ends(),rval.begin()));
}
bool operator!=(const String& lval,const String& rval){
    return !operator==(lval,rval);
}

bool operator<(const String &lval, const String &rval) {
    return std::lexicographical_compare(lval.begin(),lval.ends(),rval.begin(),rval.ends()); //字典序
}

char &String::operator[](size_t n) {
    if(n<end-elements) return elements[n];
    else throw std::out_of_range("error");
}

const char &String::operator[](size_t n) const {
    if(n<end-elements) return elements[n];
    else throw std::out_of_range("error");
}

