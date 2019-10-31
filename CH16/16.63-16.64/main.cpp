#include <iostream>
#include <vector>
#include <cstring>

using  namespace std;

template <typename T>
size_t count_vec( const vector< T>& t, const T& val)
{   size_t count=0;
    for(auto c :t)
    {
        if(c==val) count++;
    }
    return  count;
}
//特例化版本 const char*
template <>
size_t count_vec(const vector< char* >& t,   char*const  & val)
{
    int res=0;
    for(auto c:t){
        if(!strcmp(c,val)) res++;
    }
    return res;
}
int main() {
    vector<int>vec{1,2,1,1,3};
    cout<<count_vec(vec,1);

    //test for char*
    vector< char*> vec_string;
    vec_string.push_back(new char[6]);
    strcpy(vec_string[0],"hello");
    char* w=new char[6];
    strcpy(w,"hello");
    cout<<count_vec(vec_string,w)<<endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}