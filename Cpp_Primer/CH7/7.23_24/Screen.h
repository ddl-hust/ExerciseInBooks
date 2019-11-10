#include<string>
#include<iostream>

class Screen{
public:
    typedef std::string::size_type  pos;
    Screen()= default;
    Screen(const pos& h,const pos& w):height(h),weight(w),contents(height*weight,' '){}
    Screen(const pos& h,const pos& w,const char & c):weight(w),height(h),contents(weight*height,c){}
    
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * weight + c]; }
private:
    pos cursor=0;
    pos height,weight=0;
    std::string contents;
};