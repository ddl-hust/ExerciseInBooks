#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

//消除重复元素

int main(){

    vector<int>v{1,1,2,3,44,5,44,7};
    sort(v.begin(),v.end());
    auto uniqe_end=unique(v.begin(),v.end());

    v.erase(uniqe_end,v.end()); //容器操作
    for(auto c: v) cout<<c<<" ";

    return 0;
}