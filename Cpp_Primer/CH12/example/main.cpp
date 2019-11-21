#include <iostream>
#include<memory>
using namespace std;

#include <string>
#include "StrBlob.h"
int main() {



// allocator
allocator<string> alloc;
auto const p=alloc.allocate(10);
auto q=p;
alloc.construct(q++);
//cout<<*q<<endl;
alloc.construct(q,"hi");
    cout<<*q<<endl;

    return 0;
}