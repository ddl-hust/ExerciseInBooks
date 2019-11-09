#include "DeletePtr.h"
int main() {
    double *p= new double;
    deletptr d;
    d(p);
    int* ip=new int ;
    deletptr()(ip); //在临时对象上调用operator()
    std::cout << "Hello, World!" << std::endl;
    return 0;
}