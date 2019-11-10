//
// Created by YTB on 2019/11/10.
//

#include "Screen.h"
Screen& Screen::set(const char &val) {
    contents[cursor]=val;
    return  *this;