#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<int>v1;
    vector<string>v2;

    int number;
    string s1;
    while (cin>>number)
    {
        v1.push_back(number);
        cout<<v1.size()<<endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}