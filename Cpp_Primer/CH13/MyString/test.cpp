#include"String.h"
#include<vector>
#include<iostream>
void foo(String x)
{
    std::cout << x.c_str() << std::endl;
}

void bar(const String& x)
{
    std::cout << x.c_str() << std::endl;
}

String baz()
{
//    String ret("world");
    return "";
}

int main()
{
    char text[] = "world";

    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s1;
    String s4(text);
    s2 = s1; //拷贝赋值运算符

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s5 = baz();//返回一个局部变量 ???
    String s=std::move(s5);
    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());
    svec.push_back("good job");

    for (const auto& s : svec) {
        std::cout << s.c_str() << std::endl;
    }
    //test for 关系运算符重载
    std::cout<<(s1==s2)<<"  "<<(s1<s2);

    String s_("abcd");
    std::cout<<s_[2]<<" "<<s_[4]<<std::endl;
    return 0;
}