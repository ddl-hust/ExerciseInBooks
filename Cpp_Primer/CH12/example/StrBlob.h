//
// Created by YTB on 2019/11/19.
//
//一个类vector实现
#ifndef EXAMPLE_STRBLOB_H
#define EXAMPLE_STRBLOB_H
#include<string>
#include<vector>
#include<memory>
using namespace std;
class StrBlob{
public:
    typedef  string::size_type  size_type;
    StrBlob():data(make_shared<vector<string>>() ){} //默认构造函数
    StrBlob(initializer_list<string>ls):data(make_shared<vector<string>>(ls)){} //初始化列表构造

    //成员获取，front.back,pop_back,在进行这些操作之前必须验证下标有效性
    string& front(){
        check(0,"front of empty vector");
        return data->front();
    }
    string& front() const{
        check(0,"front of empty vector");
        return data->front();
    }
    string& back(){
        check(0,"end of empty vector");
        return data->back();
    }
    string& back() const {
        check(0,"end of empty vector");
        return data->back();
    }
    void push_back(string str){
        data->push_back(str);
    }
    size_type  size(){
        return data->size();
    }
    auto getdata(){return data;}
private:
    shared_ptr<vector<string>> data;
    void check  (size_t i,const string& str) const{
        if(i < data->size()) throw out_of_range(str);
    }
};




#endif //EXAMPLE_STRBLOB_H
