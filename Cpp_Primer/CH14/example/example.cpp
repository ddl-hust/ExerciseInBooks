#include<iostream>
#include<algorithm>
#include<string>
using std::string;
using std::cout;
//打印string 实参类，用于练习函数对象
class printstring{
public:
    printstring(std::ostream& o=std::cout,char s=','):os(o),sep(s){}
    void operator()(const string& s){
        os<<s<<sep;
    }
    //ex 14_35
    auto  operator()(int a,int b,int c){
        return a?b:c;
    }
private:
    std::ostream & os;
    char sep; //分隔符
};

int main(){
    printstring prints(std::cout,' ');
    prints("hi");
    cout<<prints(1,2,3);

    return 0;
}