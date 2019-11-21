#include <iostream>
#include <string>
#include <cstring>
//  Write a program that reads a string from the standard input into a
//  dynamically allocated character array.
//  Describe how your program handles varying size inputs.
//  Test your program by giving it a string of data that is longer than the
//  array size you've allocated.
using  std::string;
using std::cin;

int main() {
    int n=0;
    string s;
    cin>>n>>s; //通过显式告诉用户输入字符串大小
    char* p= new char[n+1];  //'\0'
    strcpy(p,s.c_str());
    std::cout << p << std::endl;
    delete [] p;
    return 0;
}