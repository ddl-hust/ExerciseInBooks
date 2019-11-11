#include <iostream>
#include<vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
//从文件中读取内容到vector，然后使用istringstream一次输出一个单词
int main() {
    ifstream is("../data");
    vector<string> vec;
    string s;
    //将行存到vector
    while(getline(is,s)){
        vec.push_back(s);
    }
    //输出单个单词
    for(auto &c:vec)
    {
        istringstream iss (c);
        string word;
        while (iss>>word){
            cout<<word<<endl;
        }
    }
    return 0;
}