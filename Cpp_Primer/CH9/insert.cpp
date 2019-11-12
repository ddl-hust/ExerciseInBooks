#include<list>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main(){
    list<string>lst;
    auto iter=lst.begin();
    string word;
    while(cin>>word)
    {
        iter=lst.insert(iter,word);
    }
    for(auto c:lst){
        cout<<c<<endl;
    }
    return 0;
}