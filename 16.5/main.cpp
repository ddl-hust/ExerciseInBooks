#include <iostream>
/*
 * a print function ,accept an reference to array
 * besides can handle any size,any type.
 */
template <typename T, unsigned U>
void print(const T(&arr)[U])
{
    for(auto c:arr)
    {
        std::cout<<c<<std::endl;
    }
}
int main() {
    int test1[4]={1,1,2,3};
    char test2[3]={'d','d','l'};
    print(test1);
    print(test2);
    return 0;
}