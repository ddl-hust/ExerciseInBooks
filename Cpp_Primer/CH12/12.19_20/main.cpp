#include <iostream>
#include"ex12_19.h"
#include <fstream>
//weak_ptr 作用示例
//Write a program that reads an input file a line at a time into
//  a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.

int main() {
    std::ifstream ifs("../data");
    StrBlob blob;
    for(string s;getline(ifs,s);) blob.push_back(s);

    StrBlobPtr pbegin(blob.begin());
    StrBlobPtr pend(blob.end());
    for(;pbegin!=pend;pbegin.incr()){
        std::cout<<pbegin.deref()<<std::endl;
    }
    std::cout << "Hello, World!" << std::endl;

    //测试成员访问运算符
    StrBlob a1 = {"hi", "bye", "now"};
    StrBlobPtr p(a1);            // p points to the vector inside a1
    *p = "okay";                 // assigns to the first element in a1
    auto it =p->size();
    std::cout << p->size() << std::endl;   // prints 4, the size of the first element in a1
    std::cout << (*p).size() << std::endl; // equivalent to p->size()

    string s("all");
    std::cout<<(&s)->size();

    //test strblob_pointer
    StrBlob sb{"hello", "world"};
    StrBlobPtr iter = sb.begin();
    StrBlobPtr_pointer p1(&iter);
    std::cout << p1->deref() << std::endl; //这里做了三次-> ,前两次得到的都是重载了的->，最后一次调用内置类型的->
    return 0;
}