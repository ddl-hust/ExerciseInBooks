#include <iostream>
#include<functional>
#include<map>
#include<string>
using std::string;
using std::map;
using std::cout;
using std::endl;
//练习函数编程 lambda,可调用对象

int add(int a,int b){return a+b;}
auto mod=[](int i,int j){return i%j;}; //lambda
struct divide{
    int operator()(int a,int b){return a/b;}
};
map<string,std::function<int(int,int)>> binops={
        {"+",add},
        {"-",std::minus<int>()},
        {"divide",divide()}
};
int main() {
    cout<<binops["+"](10,10)<<endl;
    cout<<binops["-"](10,10);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}