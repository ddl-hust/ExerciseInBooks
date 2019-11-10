#include <iostream>
#include<vector>
using namespace std;
class NoDefault{
public:
//    NoDefault()= default;
    NoDefault(const int i){};
};

class C{
public:
    C():data(0){}
// C()= default;
private:
    NoDefault data;
};
int main() {
    C c;
    std::vector<NoDefault> vec(10);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}