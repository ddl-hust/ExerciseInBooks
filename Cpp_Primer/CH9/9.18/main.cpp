#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <list>
using namespace std;
int main() {
    string s;
    deque<string> q;
    q.push_back("dl"); //while ctrl+D 为啥退出不了
    q.push_back("asd");
    for(auto it=q.begin();it!=q.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}