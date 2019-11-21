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
    return 0;
}