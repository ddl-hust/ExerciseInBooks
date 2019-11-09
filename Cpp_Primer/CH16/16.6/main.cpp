#include <iostream>
/*
 * 定义自己版本的stl容器,begin,end
 * 思路：返回数组首元素地址，对于end,返回首地址＋数组长度
 * ｍｙ_end()返回结果正确行为应该是指向未定义的内存空间，即数组最后元素的下一个地址，这个与标准库中的end()行为一致
 */
template  <typename T,size_t M>
const T* my_begin(const T(&arr)[M])
{
    return &arr[0];
}

template  <typename T,size_t M>
const T* my_end(const T(&arr)[M])
{
    return &arr[0]+M;
}
int main(){
    int arr[2]={1,2};
    auto res = my_begin(arr);
    std::cout<<"the first element of array:"<<*res<<std::endl;
    std::cout<<"the last element of array :"<<*my_end(arr)<<std::endl;
    return 0;
}