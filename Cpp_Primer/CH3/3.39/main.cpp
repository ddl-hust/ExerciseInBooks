#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//体会string对象与 c-style string 对比

int main() {
    string s1("ddl");
    string s2("zdf");
    char c_s1[]="ddl";
    char c_s2[]="ddl";
    cout<<"输出较大字符串对象："<<(s1>s1?s1:s2)<<endl;
    if(strcmp(c_s1,c_s2)<0) cout<<c_s2;
    else cout<<c_s1;
    cout<<"输出c-style 较大值："<<(strcmp(c_s1,c_s2)?c_s1:c_s2)<<endl; //在这里条件判断，即使当c_s1<c_s2返回也是c_s1,因为strcmp只有当两边相等才返回0

    return 0;
}