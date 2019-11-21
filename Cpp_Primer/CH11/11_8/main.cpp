#include <iostream>
#include <map>
#include <string>
#include <set>
#include <cctype>
#include <vector>

using  namespace std;
//通过vector 实现set 每次有新的元素度需要遍历一遍容器效率低
int main() {
    int x;
    vector<int> vec;
    while(cin>>x){
        auto beg=vec.begin();
        while(beg!=vec.end())
        {
          if(*beg==x) break;
          beg++;
        }
        if(beg==vec.end()) vec.push_back(x);
    }
    for(auto c:vec) cout<<c<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}