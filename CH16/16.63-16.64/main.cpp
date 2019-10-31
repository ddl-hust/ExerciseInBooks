#include <iostream>
#include <vector>
using  namespace std;

template <typename T>
size_t count_vec( vector<T>const& t, const T& val)
{   size_t count=0;
    for(auto c :t)
    {
        if(c==val) count++;
    }
    return  count;
}
//特例化版本 const char*
template <>
size_t count_vec(vector<const char*>const& t,  const const char*  & val)
{

}
int main() {
    vector<int>vec{1,2,1,1,3};
    cout<<count_vec(vec,1);
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}