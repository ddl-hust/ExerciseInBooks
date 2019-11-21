#include <iostream>
#include <map>
#include <string>
#include <set>
#include <cctype>
using  namespace std;
//忽略大小写，以及标点符号的计数器
//思路是将输入的字符串统一转化为小写，没有标点
string normalize(string & str)
{   string res;
    for(auto & c:str)
    {
        if(!ispunct(c)) res.push_back(tolower(c));
    }
    return res;

}
int main() {
    string word;
    set<string> s;
    map<string,int> word_count;
    while (cin>>word)
    {
       ++word_count[normalize(word)];
    }
    for(auto w:word_count)
        cout<<w.first<<" occurs "<<w.second<<endl;
    return 0;
}