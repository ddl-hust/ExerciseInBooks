#include<string>
#include<list>
#include<iostream>
using namespace std;

int main(){
    list< char> c{'a','b','c'};
    string s1("dll");
    // s1=c;
    s1.assign(c.begin(),c.end());
    cout<<s1;
    return 0;
}