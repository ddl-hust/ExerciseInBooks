#include <iostream>
#include <vector>
using namespace std;
/*
 * 递归输出vector
 */
void print_vector( vector<int>&vec)
{
    if(vec.empty()) return;
    cout<<vec.back()<<endl;
    vec.pop_back();
    print_vector(vec);
}
int main() {
    vector<int>vec1={1,2,3,4};
    print_vector(vec1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}