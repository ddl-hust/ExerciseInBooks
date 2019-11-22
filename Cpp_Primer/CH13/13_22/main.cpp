#include <iostream>
#include<string>
using std::string;
//重写HasPtr 类值行为
class HasPtr{
public:
   HasPtr():p(new string()),id(0){}
   HasPtr(const HasPtr& rval)
   {
       p = new string(*rval.p);
       id=rval.id;
   }
   HasPtr& operator= (const HasPtr& rval ){
       auto newp = new string(*rval.p);
       delete p;
       p=newp;
       id=rval.id;
       return *this;

   }
   ~HasPtr(){delete p;}
private:
    string* p;
    int id;
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}