#include <memory>
#include<iostream>
#include<algorithm>
class String;
bool operator==(const String& ,const String& );
bool operator!=(const String& ,const String& );
bool operator< (const String&,const String&);

class String {
public:
    friend bool operator==(const String& ,const String& );
    friend bool operator!=(const String& ,const String& );
    friend bool operator< (const String&,const String&);
    String() : String("") {std::cout<<"String() : String(\"\")"<<std::endl;} //委托构造函数
    String(const char*);
    String(const String&);
    String( String&& s) noexcept :elements(s.elements),end(s.end)
    {
        s.elements = s.end = nullptr;
        std::cout<<"move constructor"<<std::endl;
    }
    String&operator= ( String&& rhs){
        if (this != &rhs) {
            free();
            elements = rhs.elements;
            end = rhs.end;
            rhs.elements = rhs.end = nullptr;
        }
        std::cout<<"move assign"<<std::endl;
        return *this;
    }
    String& operator=(const String&);
    char& operator[](size_t n);
    const char&operator[] (size_t n) const;
    ~String();

    const char* c_str() const { return elements; }
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements - 1; }
    char* begin() const {return elements;}
    char* ends() const { return  end;}

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    char* elements;
    char* end;
    std::allocator<char> alloc;
};
