#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
#include<iterator>
#include<functional>
using namespace std;
using namespace std::placeholders;
//给定string ,使用bind,check_size,在一个vector<int>查找第一个大于string.size()的值

 bool check_size(const string &s,string::size_type sz)
 {
     return s.size()<sz;
 }
int main()
{
    vector<int>v{1,2,3,4,5};
    auto new_check=bind(check_size,string("dll"),_1);
    auto it=find_if(v.begin(),v.end(),new_check);
    cout<<*it;
    return 0;
}