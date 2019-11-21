//
// Created by YTB-002 on 2019/11/21.
//

#ifndef INC_12_27_12_27_H
#define INC_12_27_12_27_H

#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <memory>
using std::vector;
using std::string;
using std::set;
using std::map;
using  std::shared_ptr;
using std::cout;
using std::cin;
class QueryResult;
class TestQuery{
public:
    using LineNo=vector<string>::size_type ;
    explicit TestQuery(std::ifstream& is);
    QueryResult query(const string& s);

private:
    shared_ptr<vector<string>> data;
    map<string,shared_ptr<set<LineNo>>> result; //查询结果
};
class QueryResult{
public:
    using size = vector<string>::size_type ;
    friend std::ostream& print(std::ostream&, const QueryResult&);
    QueryResult(string  s,shared_ptr<set<size>> set,shared_ptr<vector<string>> v):
        data(std::move(v)),n(std::move(set)),word(std::move(s)){}

private:
    string word;
    shared_ptr<vector<string>> data;
    shared_ptr<set<size>> n;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif //INC_12_27_12_27_H
