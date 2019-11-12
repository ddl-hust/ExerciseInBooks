#include<list>
#include<deque>
#include<iostream>
#include<vector>
using namespace std;
vector<int>::iterator foo(vector<int>::iterator b,vector<int>::iterator e,int val) //迭代器参数都是如何的? 
{
    while (b!=e)
    {
        if(*b==val) return b;
        b++;
    }
    return e;
    
}

int main(){
vector<int>vec{1,2,3,4,5};
auto find=foo(vec.begin(),vec.end(),4);//begin()返回的是一个临时量
std::cout<<"find or not:"<<*find;

}