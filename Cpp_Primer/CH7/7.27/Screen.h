#include<string>
#include<iostream>
/*
 * 在之前screen类基础上添加新的成语函数，主要涉及inline,返回*this,const
 * move():给定行列，移动光标到指定字符 返回左值引用
 * set():1.在当前光标处设置指定字符 2.重载函数，在给定行列，设定指定字符 返回左值引用
 * display():打印内容
 */
class Screen{
public:
    typedef std::string::size_type  pos;
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

Screen& Screen::set(const char &val) {
    contents[cursor]=val;
    return  *this;
}
