#include<string>
#include<set>
#include<memory>
#include<algorithm>
using std::string;
class StrVec {
    friend operator==(const StrVec&,const StrVec&);
    friend operator!=(const StrVec&, const StrVec&);
public:
    StrVec(): // the allocator member is default initialized
      elements(nullptr), first_free(nullptr), cap(nullptr) {
}
 

    StrVec(const StrVec&);            // copy constructor
    StrVec(const StrVec&& s) noexcept :elements(s.elements),first_free(s.first_free),cap(s.cap) //move constructor
    {
        s.elements=s.first_free=s.cap=nullptr;
    }

    StrVec &operator=(const StrVec&); // copy assignment
    StrVec& operator=(const StrVec&&); //move assignment
    ~StrVec();                        // destructor
    void push_back(const std::string&);  // copy the element
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    /****************作业****************/
    //辅助函数，实际上因该是重构的结果，考虑到拷贝构造函数，以及列表初始化都需要进行这一操作，将其模块化
    void range_initial(const string* b,const string* e)
    {
        auto p =alloc_n_copy(b,e);
        elements=p.first;
        first_free=cap=p.second;
    }
    //实际上是将reallocate里面部分提取出来，因为在reserve里面也用到
    void alloc_n_move(size_t newcap){
        auto newdata=alloc.allocate(newcap);
        auto dest=newdata;
        auto elem= elements;
        for (size_t i = 0; i !=size(); i++)
        {
            alloc.construct(dest++,std::move(*elem++));
        }
        elements=newdata;
        first_free=dest;
        cap=elements+newcap;

        //另一种实现
        auto last = std::uninitialized_copy(std::make_move_iterator(begin()),std::make_move_iterator(end()),dest);
        free();
        elements=dest;
        first_free=last;
        cap=elements+newcap;

        
    }
    StrVec(std::initializer_list<string> ls){range_initial(ls.begin(),ls.end());}

    //reserve 需要做的就是分配新的内存空间,这个时候使用移动构造效率就比较高
    void reserve(size_t n)
    {
        if(n<capacity()) return;
        alloc_n_move(n);
    }
    void resize(size_t n，string s) 
    {
        if(n<size()) {
            //销毁多余元素
            for(auto &it =first_free;size()!=n;it--) alloc.destroy(it);
        }
        else //值初始化
        {
            if(n>capacity()) reserve(n*2); 
            for(size_t i=size();i!=n;i++) alloc.construct(first_free++,s);       
        }
    }
    /****************************************************************************/

    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    // ...
private:
    std::allocator<std::string> alloc; // allocates the elements
    // used by the functions that add elements to the StrVec
    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
    // utilities used by the copy constructor, assignment operator, and destructor
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();             // destroy the elements and free the space
    void reallocate();       // get more space and copy the existing elements
    std::string *elements;   // pointer to the first element in the array
    std::string *first_free; // pointer to the first free element in the array
    std::string *cap;        // pointer to one past the end of the array
};
void StrVec::push_back(const string& s){
    chk_n_alloc();
    alloc.construct(first_free++,s);
}

std::pair<string*,string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e-b);
    return {data,std::uninitialized_copy(b,e,data)};
}

void StrVec::free(){
    if(elements){
        for(auto p=first_free;p!=elements;) alloc.destroy(p--);
        alloc.deallocate(elements,cap-elements);
    }
}
//使用之前的utility 实现拷贝控制成员
StrVec::StrVec(const StrVec& rval){
    range_initial(rval.elements,rval.first_free);
}
StrVec::~StrVec(){ free();}

StrVec& StrVec::operator=(const StrVec& rval){
    auto data=alloc_n_copy(rval.begin(),rval.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}

StrVec& StrVec::operator=(const StrVec&& rval){
    if(this!=&rval) //判断self-assign
    {
        free();
        elements=rval.elements;
        first_free=rval.first_free;
        cap=rval.cap;
        rval.elements=rval.first_free=rval.cap=nullptr;
    }
    return *this;
}

bool operator==(const StrVec&lval,const& StrVec& rval){
    return (lval.size()==rval.size() && std::equal(lval.begin(),lval.end(),rval.begin()));
}
bool operator!=(const StrVec& lval,const StrVec& rval){
    return !operator==(lval,rval);
}