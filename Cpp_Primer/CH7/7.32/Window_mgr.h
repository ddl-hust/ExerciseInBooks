

#ifndef INC_7_32_WINDOW_MGR_H
#define INC_7_32_WINDOW_MGR_H
#include<vector>
#include "Screen.h"
#include <string>
class Window_mgr{
public:
    class Screen;
    using index=std::vector<Screen>::size_type ;
    void clear(index);
private:
    std::vector<Screen> screens{(24,80,'c')};


};
void Window_mgr::clear(index i) {
    Screen& s=screens[i];
    s.contents=std::string(s.height*s.weight,' ');
}
#endif //INC_7_32_WINDOW_MGR_H
