#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<pair<string,int>> vec;
    pair<string,int> p;
    string str;
    int count;
    while(cin>>str>>count)
    {
//        vec.push_back(make_pair(str,count)); //1.第一种构造
         vec.push_back(pair<string,int>(str,count)); //2.
         p={str,count}; //3.
        vec.push_back(p);
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}