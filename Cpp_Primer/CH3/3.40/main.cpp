#include <iostream>
#include<cstring>
#include <string>
/*
 * strcpy(s1,s2)只需要len(s1)>len(s2),就不会报错
 */
using namespace std;

int main() {
    char s1[]="hello";
     char s2[]="world all this pro";
    char s3[6];
    strcpy(s3,s1);
    strcat(s3,s2); //? s3的容量不足以包含s1+s2 但是没有报错？？？
    std::cout << s3 << std::endl;
    return 0;
}