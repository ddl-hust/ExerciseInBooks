#include <iostream>
#include<string>
using namespace std;
istream& foo(istream& is)
{
    int i;
    while(is>>i)
    {   //从控制台读取类型与变量i类型不一样,但是下面这句话永远不会输出，当输入流的状态为false时候，根本就不会进入到while循环
        if(is.fail()) cout<<"wrong type,please input an intagr"<<endl;
        cout<<i<<endl;
    }
    is.clear();
    return is;
}

int main() {
    foo(cin);
    return 0;
}