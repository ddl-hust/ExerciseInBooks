#include <iostream>
#include <memory>
using namespace std;
int main() {
    unique_ptr<int>p(new int(42));
    unique_ptr<int>q;
    q=p;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}