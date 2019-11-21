//
// Created by YTB-002 on 2019/11/21.
//
#include"12_27.h"
#include <sstream>
using std::istringstream;
//在这里建立了从文本流每个单词到出现行号的map
TestQuery::TestQuery(std::ifstream &is):data(new vector<string>)
{
    string text;
    while (getline(is,text)){
        data->push_back(text);
        int n=data->size()-1; //行号 从0开始
        istringstream line(text);
        string word;
        while(line>>word){ //对行的每一个单词
            auto& lines=result[word]; //map 特性操作，创建空value
            if(!lines) lines.reset(new set<LineNo>);
            lines->insert(n); //lines 为引用，此处修改也会影响到result
        }

    }
}
QueryResult TestQuery::query(const string &s)
{
    static  shared_ptr<set<LineNo >>nodata(new set<LineNo>); //为了处理没查找到指定字符串，返回一个局部静态的空set
    auto loc=result.find(s);
    if(loc==result.end()) return QueryResult(s,nodata,data);
    else return QueryResult(s,loc->second,data);
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
    os<<qr.word<<"occurs: "<<qr.n->size()<<" "<<std::endl;
    //打印每一行
    for(auto num:*qr.n){
        os<<"\t(line"<<num+1<<")"<<*(qr.data->begin()+num)<<std::endl;
    }
    return os;
}