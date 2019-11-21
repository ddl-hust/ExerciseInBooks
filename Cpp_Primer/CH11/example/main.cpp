#include <iostream>
#include <map>
#include <string>
#include <set>
using  namespace std;
int main() {
    map<string,size_t >word_count;
    set<string> exclude{"the","and","a","an"};
    string word;
    while (cin>>word){
        if(exclude.find(word)==exclude.end())
        ++word_count[word];

    }
    for(const auto c: word_count){
        cout<<c.first<<c.second;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}