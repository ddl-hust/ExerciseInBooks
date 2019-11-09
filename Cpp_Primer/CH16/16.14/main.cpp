#include <iostream>
#include <string>
/*
*用模板重写Screen
*/
template <int H, int W>
class Screen
{
public:
    Screen() : contents(H * W, ''){};   //初始化列表
    Screen(char c) : contents(H * W, c) //string 初始化，H*W 范围类->c
    {
    }
    char get() const
    {
        return contents[cursor];
    } //in-plict inline
    inline chat get(int, int) const;
    Screen &clear(char = bkground);

private:
    static const char bkground = ' ';

public:
    Screen &move(int r, int c);
    Screen &set(char);
    Screen &set(int, int, char);
    Screen &display(std
                    : ostream &os)
    {
        do_display(os);
        return *this;
    }
    //const 版本重载
    const Screen &display(std
                          : ostream &os)
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream &os) const
    {
        os << contents;
    }
    int cursor = 0;
    std::string contents;
};

int main()
{
    std::string str(12, 'c');

    return 0;
}