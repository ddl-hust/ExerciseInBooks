#include <iostream>
#include <string>
using namespace std;

int main() {
    string s_total,s;
    while(cin>>s)
    {
//        s_total+=s;
    s_total+= s+" ";
    }
    std::cout << s_total << std::endl;
    return 0;
}
