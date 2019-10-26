#include <iostream>
#include <vector>
#include <string>
using  namespace std;

template<typename T, typename U>
T find(T begin, T end,const U &val) {
    while(begin!=end&&*begin!=val)
    {
        begin++;
    }
    return begin;
}


int main() {
    vector<int>test1={1,2,3};
    auto result=find(test1.begin(),test1.end(),1);
    if(result==test1.end()) cout<<"can not find result"<<endl;
    else cout<<"find at" <<result-test1.begin()<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}