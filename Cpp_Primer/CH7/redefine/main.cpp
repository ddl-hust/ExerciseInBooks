#include <iostream>
//测试书本P255 类型重定义
typedef  double  money;
class  Account{

public:
    money  balance();
private:
    typedef double money;
};

money Account::balance() {
    return  2.0;
}

int main() {
    Account acc;
    std::cout << acc.balance()<< std::endl;
    return 0;
}