#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1,s2;
    cin>>s1>>s2;
//    cout<< (s1>s2?s1:s2); //输出较大字符串

    cout << (s1.size() <= s2.size() ? s2 : s1); //输出较长字符串

    return 0;
}