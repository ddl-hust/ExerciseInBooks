#include <iostream>
#include <vector>
//看看rsize(),reserve()等行为是否符合预期
using namespace std;

int main() {
    vector<int>v;
    cout<<v.size()<<" "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<v.size()<<" "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.size()<<" "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.size()<<" "<<v.capacity()<<endl; //新分配内存空间将当前容量翻倍

    v.resize(10);
    cout<<v.size()<<" "<<v.capacity()<<endl;

    v.reserve(50);
    cout<<v.size()<<" "<<v.capacity()<<endl;

    v.shrink_to_fit();
    cout<<v.size()<<" "<<v.capacity()<<endl;

    return 0;
}