#include <iostream>
#include "12_27.h"
//文本查询综合练习
void runQueries(std::ifstream& infile)
{
    TestQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main()
{
    std::ifstream file("../data");
    runQueries(file);
}