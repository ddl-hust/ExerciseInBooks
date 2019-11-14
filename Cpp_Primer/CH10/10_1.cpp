#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

int main()
{
    vector<double>v{1,2,3,4};
    auto s=count(v.begin(),v.end(),1);
    auto acc=accumulate(v.cbegin(),v.cend(),0);
    cout<<"there are :"<<s<<endl;
    cout<<"the sum of vector ："<<acc<<endl;

    //10.6
    fill_n(v.begin(),v.size(),0);
    for(auto c:v) cout<<c<<" ";

    //10.7(b)
    vector<int>vec2;
    vec2.resize(10); //只是分配可用内存，实际没有元素
    fill_n(vec2.begin(),10,0);
    for(auto c:vec2) cout<<c<<" ";
    return 0;
}