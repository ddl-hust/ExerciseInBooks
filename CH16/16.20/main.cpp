#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
/*
 * accept a container reference, use begin(),end()
 * control the print element
 */
template <typename T>
void my_print(const T& t)
{
    auto begin= t.begin();
    auto end=t.end();
    while(begin!=end)
    {
        cout<<*begin<<endl;
        begin++;
    }
}
int main() {
    vector<int> test1={1,2,3};
    string test2(10,'c');
    list<int> test3={1,2,3};
    my_print(test1);
    my_print(test2);
    my_print(test3);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}