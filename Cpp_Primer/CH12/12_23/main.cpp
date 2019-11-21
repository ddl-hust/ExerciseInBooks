#include <iostream>
#include <cstring>
#include <string>
//Write a program to concatenate two string literals, putting the result in a
//  dynamically allocated array of char.
//  Write a program to concatenate two library strings that have the same value
//  as the literals used in the first program.
int main() {
    const char * c1="asd";
    const char * c2= "hei";
    size_t  len=strlen(c1)+strlen(c2)+1;

    char* p = new char[len];
    strcat(p,c1);
    strcat(p,c2);

    std::cout << p << std::endl;

    //string
    std::string s1("dll");
    std::string s2("lld");
    strcpy(p,(s1+s2).c_str());
    std::cout << p << std::endl;
    delete [] p;
    return 0;
}