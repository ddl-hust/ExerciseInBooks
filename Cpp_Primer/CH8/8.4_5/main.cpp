#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
//读取文件内容将其存到vector
int main() {
    fstream fs;
    fs.open("../text"); //注意读取文件路径
    if(!fs) cout<<"open file fail"<<endl;//打开文件之后，判断状态是个好习惯
    string s;
    vector<string> vec;
//    while(getline(fs,s)) //从fs读取一行到s
while(fs>>s)     //读取单个word
{
        vec.push_back(s);
    }
    for(auto & c:vec){
        cout<<c<<endl;
    }
    return 0;
}