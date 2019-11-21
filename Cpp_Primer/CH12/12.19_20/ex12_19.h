//
// Created by YTB-002 on 2019/11/21.
//

#ifndef INC_12_19_EX12_19_H
#define INC_12_19_EX12_19_H

#include <vector>
#include <string>
#include <initializer_list>
#include <iostream>
#include <memory>

using std::vector;
using std::string; //之后不要直接引入整个std

class StrBlobPtr; //前置声明
class StrBlob{
public:
    friend class StrBlobPtr;
    using size_type=vector<string>::size_type ;
    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob():data(std::make_shared<vector<string>>()){}
    StrBlob(std::initializer_list<string>ls):data(std::make_shared<vector<string>>(ls)){}//注意初始化列表形式

    size_type  size() const { data->size();}
    bool empty()const {return data->empty();}
    string front()
    {   check(0,"front of vector");
        return data->front();
    }
    string back(){
        check(0,"end of vector");
        return data->back();
    }
    void push_back(string s){
        data->push_back(s);
    }

private:
    //辅助函数检查是否越界
    void check(size_type i,const string& msg) const{
        if(i>=data->size()) throw std::out_of_range(msg);
    }
    std::shared_ptr<vector<string>>data;
};

class StrBlobPtr{
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob& a,size_t sz=0):wptr(a.data),curr(sz){}

    string& deref()const {
        auto p=check(curr,"derefence past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr(){
        check(curr,"incremnet past end of strblobptr");
        ++curr;
        return *this;
    }
    bool operator !=(const StrBlobPtr& p){return this->curr!=p.curr;}
private:
    //辅助函数，检查weak_ptr指向的vector是否存在，以及下标是否越界
    std::shared_ptr<vector<string>> check(size_t i,const string& msg) const{
        auto p= wptr.lock();
        if(!p) throw std::runtime_error("unbound StrBlobPtr");
        if(i>=p->size()) throw std::out_of_range(msg);
        return p;
    }
    std::weak_ptr<vector<string>> wptr;
    size_t  curr; //下标索引
};

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this); //ptr默认形参 size=0
}
StrBlobPtr StrBlob::end() {return StrBlobPtr(*this,this->size());}
#endif //INC_12_19_EX12_19_H
