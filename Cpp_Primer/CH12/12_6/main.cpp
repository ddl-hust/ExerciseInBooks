#include <iostream>
#include<vector>
#include<memory>
using namespace std;
//返回动态内存
auto  foo(){
    return new std::vector<int>();
}
void read(std::vector<int>* ptr){
    int a;
    while(std::cin>>a){
        ptr->push_back(a);
    }
}
void write(vector<int>* ptr){
    for(auto c:*ptr) cout<<c<<endl;

}
int main() {
    auto vec=foo();
    read(vec);
    write(vec);
    delete vec;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}