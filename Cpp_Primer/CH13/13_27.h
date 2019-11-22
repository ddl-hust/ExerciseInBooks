//引用计数版本 指针行为的hasptr
#include<vector>
#include<string>
using std::string;
class HasPtr{
public:
   HasPtr():p(new string()),id(0),count(new size_t(1)){}
   HasPtr(const HasPtr& rval)
   {
       p = rval.p;
       id=rval.id;
       ++*count;
   }
   HasPtr& operator= (const HasPtr& rval ){
       **rval.count;
       if(--count==0) {delete p; delete count;} 
       id=rval.id;
       p=rval.p;
       count=rval.count;
       return *this;

   }
   ~HasPtr()
   {
       if(--*count)
       {
       delete p;
       delete count;}
       }
private:
    string* p;
    int id;
    size_t* count;
};