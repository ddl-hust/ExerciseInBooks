#include <iostream>
#include <memory>
#include <string>
//用allocator重写动态内存分配，将内存的分配与对象构造分开
int main() {
    std::allocator<std::string>alloc;
    std::string s;
    auto const p=alloc.allocate(5);
    auto q=p;
    while (std::cin>>s){
        alloc.construct(q++,s);
    }
    while (q != p) {
        std::cout << *--q << " ";
        alloc.destroy(q); //销毁对象
    }
    alloc.deallocate(p, 5); //释放内存
    std::cout << "Hello, World!" << std::endl;
    return 0;
}