/*Write a program to assign the elements from a list of
char* pointers to C-style character strings to a vector of strings.
*/
#include<list>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main(){
    list<const char*> char_list={"ddl","dada","hust"};
    vector<string> str_vec;
    // str_vec=char_list; cannot assin direct
    str_vec.assign(char_list.begin(),char_list.end());
    for(auto c:str_vec){
        cout<<c<<endl;
    }

}