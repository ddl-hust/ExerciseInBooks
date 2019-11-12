#include<list>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main(){
    list<string>lst;
    auto iter=lst.begin();
    string word;
    cin>>word;
        iter=lst.insert(iter,word);
        cout<<*iter<<endl;
    for (auto i = lst.begin(); i!=lst.end() ; ++i) {
        cout<<*i<<endl;
    }
    return 0;
}