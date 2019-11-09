#include <iostream>
#include <initializer_list>
using namespace std;
//可变形参initializer_list，求和int
int sum_int(initializer_list<int>l1)
{   int res=0;
    for(auto it=l1.begin();it!=l1.end();++it)
    {
        res+=*it;
    }
    return res;
}
int main() {
    initializer_list<int>l={1,2,3};
    cout<<sum_int(l)<<endl;
    return 0;
}