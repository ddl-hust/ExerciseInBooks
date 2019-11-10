

#ifndef INC_7_32_SCREEN_H
#define INC_7_32_SCREEN_H

#include "Window_mgr.h"
class Screen{
public:
    typedef std::string::size_type  pos;

    friend void Window_mgr::clear(index);
    Screen()= default;
    Screen(const pos& h,const pos& w):height(h),weight(w),contents(height*weight,' '){}
    Screen(const pos& h,const pos& w,const char & c):weight(w),height(h),contents(weight*height,c){}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * weight + c]; }

    inline Screen& set(const char& val);  //显式声明为inline
    Screen& set(const pos& r,const pos& c,const char& val){
        contents[r*weight+c]=val;
        return *this;
    }

    Screen& move(const pos& r,const pos& c){
        cursor=r*weight+c;
        return *this;
    }
    Screen& display(std::ostream& os)
    {
        do_display(os);
        return *this;
    }
    const Screen& display(std::ostream& os) const
    {
        do_display(os);
        return *this;
    }

private:
    pos cursor=0;
    pos height,weight=0;
    std::string contents;
    void do_display(std::ostream& os) const {os<<contents;}
};


}
#endif //INC_7_32_SCREEN_H
