//
// Created by YTB-002 on 2019/11/23.
//

#ifndef INC_15_53_13_53_H
#define INC_15_53_13_53_H
#include <string>

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string& s = std::string());
    HasPtr(const HasPtr& hp);
    HasPtr(HasPtr&& p) noexcept;
    HasPtr& operator=(HasPtr rhs);
//    HasPtr& operator=(const HasPtr &rhs);
//    HasPtr& operator=(HasPtr &&rhs) noexcept;
    ~HasPtr();

private:
    std::string* ps;
    int i;
};
#endif //INC_15_53_13_53_H
