#include <iostream>
#include <string>
using namespace std;
inline  bool isshorter(const string& s1, const string& s2 )
{
    return s1.size()<s2.size();
}
int main() {
    string s1("dldl");
    string s2("coco");
    std::cout << "Hello, World!" << isshorter(s1,s2)<<endl;
    return 0;
}