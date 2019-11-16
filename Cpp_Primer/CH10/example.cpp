#include<vector>
#include<iostream>
using namespace std;

int mian(){
    //方向迭代器
    vector<int> vec{0,1,2,3};
    for(auto r_iter=vec.crbegin();r_iter!=vec.crend();++r_iter)
        cout<<*r_iter<<endl;
    return 0;
}