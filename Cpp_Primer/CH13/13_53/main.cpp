#include <iostream>
#include "13_53.h"
int main() {
    HasPtr h1,h2;
    h1=h2;
    h1=std::move(h2);
    return 0;
}