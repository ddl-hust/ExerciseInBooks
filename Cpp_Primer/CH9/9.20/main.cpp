#include <iostream>
#include <list>
#include<deque>
using namespace std;
int main() {
    list<int> lst{1,2,3,4,5};
    deque<int>q1,q2;
    for (auto  it = lst.begin(); it!=lst.end() ; ++it) {
        if(*it%2!=0) q1.push_back(*it);
        else q2.push_back(*it);
    }
    cout<<"输出奇数：";
    for(auto c:q1) cout<<c<<endl;
    return 0;
}