#include <iostream>
#include <string>
//输出命令行参数字符串
int main(int argc, char** argv)
{
    std::string str;
    for (int i = 1; i != argc; ++i) {
        str += argv[i];
        str += " ";
    }

    std::cout << str << std::endl;
}
