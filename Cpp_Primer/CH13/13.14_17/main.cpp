#include <iostream>
#include<string>
using std::string;
using  std::cout;

//通过静态成员 默认构造函数 为每个对象生成唯一序号
class numbered{
public:
    numbered(){
        
        mysn=++unique;
    }
    numbered(numbered& rval):mysn(rval.mysn+1){}

    int getId(){return mysn;}
    int mysn;
    static  int unique; //生命周期整个程序执行


};
int  numbered::unique=0;  //内外初始化静态数据成员
 void foo(numbered& n){ cout<<n.mysn<<std::endl;}

int main() {
    numbered a,b=a,c=b;
    foo(a);
    foo(c);

    return 0;
}