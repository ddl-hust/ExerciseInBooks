#include <iostream>
#include <string>
using std::string;
class Employee{
public:
    Employee(){id=increment++;}
    Employee(string s):name(s){id=increment++;}
    Employee(const Employee& rval) = delete;
    Employee& operator=(Employee& rval)= delete;
private:
    string name;
    static int increment; //静态数据成员类外初始化
    int id;

};
int  Employee::increment=0;


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}