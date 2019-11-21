#include <iostream>
#include <fstream>

#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;
//单词转换程序
unordered_map<string,string> buildmap(ifstream&map_file){
    unordered_map<string,string>trans_map;
    string key,value;
    while (map_file>>key&&getline(map_file,value)) {
        if (value.size() > 1) trans_map[key] = value.substr(1); //去掉首部空格
        else throw runtime_error("no rule for transform " + key);
    }

    return trans_map;


}

const string& transform(const string& s, const unordered_map<string,string>& m){
    auto map_it =m.find(s);
    if(map_it!=m.end()) return  map_it->second;
    else return s;
}

void word_transform(ifstream& map_file,ifstream& input){
    auto trans_map=buildmap(map_file);
    string text;
    while (getline(input,text)){
        istringstream stream(text);
        string word;
        bool firstword=true; //控制格式输出，第一个单词之后每个单词之间空“ ”
        while(stream>>word){
            if(firstword) firstword=false;
            else cout<<" ";
            cout<< transform(word,trans_map);
        }
        cout<<endl;
    }
}


int main() {
    ifstream map("../map"); //单词转换表
    ifstream txt("../text"); //待转换文本
    word_transform(map,txt);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}