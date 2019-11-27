#include <iostream>
#include<string>
#include<vector>
class Ex35{
public:
    std::istream& in;
    std::vector<std::string> vec;
    Ex35(std::istream& i=std::cin):in(i){}
    std::string operator()()
    {
        std::string s;
        while(getline(in,s)){
            vec.push_back(s);
        }
        if(in) return s;
        else return std::string();
    }
};
int main() {
    Ex35 e;
    std::cout<<e();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}