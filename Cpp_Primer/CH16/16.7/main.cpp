#include <iostream>

template<typename T,size_t M>
size_t ArraySize(const T(&arr)[M])
{
  return M;
}

template  <typename T,size_t  M>
void print(const T(&arr)[M])
{
    for(int i =0;i<ArraySize(arr);i++) //ArraySize(arr) 返回常量表达式
    {
        std::cout<<arr[i]<<std::endl;
    }
}

int main() {
    int arr[3]={1,2,3};
    auto res =ArraySize(arr);
    std::cout<<"the size of array:"<<res<<std::endl;
    print(arr);
    return 0;

}