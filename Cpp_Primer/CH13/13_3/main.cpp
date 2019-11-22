#include"../../CH12/12.19_20/ex12_19.h"
//share_ptr 与weak_ptr 拷贝构造引用计数
int main(){
// test codes in main()
StrBlob str({"hello", "world"});
std::cout << "before: " << str.count() << std::endl; // 1
StrBlob str_cp(str); //拷贝构造
std::cout << "after: " << str.count() << std::endl;  // 2

StrBlobPtr p(str);
std::cout << "before: " << p.count() << std::endl; // 2
StrBlobPtr p_cp(p);
std::cout << "after: " << p.count() << std::endl; // 2
return 0;
}