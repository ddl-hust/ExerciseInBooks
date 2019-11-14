#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

//10.14lambda 
// auto add = [](int a,int b) {return a+b;}

//10.15 捕获列表
int i=0;
auto add2 = [](int num){return (i + num);} //创建不是调用

//10.21 题目意思没理解到;sb 题目
void foo()
{
    int i=10;
    auto f=[&i]()->bool {--i;return}
}

