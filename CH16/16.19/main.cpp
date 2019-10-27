#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * accept a container reference, using size_type and size
 * control the print element
 */
template <typename T>
void my_print(const T& t)
{
    typedef typename T::size_type size_type;
    for (size_type i = 0;i < t.size(); ++i) {
        cout<<t.at(i)<<endl; //通过at获取容器元素不适合list等，后续改进
    }
}
int main() {
    vector<int> test1={1,2,3};
    string test2(10,'c');
    my_print(test1);
    my_print(test2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}