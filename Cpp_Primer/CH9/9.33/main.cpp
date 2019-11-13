#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<v.size()<<" "<<v.capacity()<<endl;
    auto begin = v.begin();
    begin=v.insert(begin,100);
    cout<<"begin after insert:"<<*begin<<endl;
    v.insert(begin,1000);
    cout<<"after insert:"<<v.size()<<" "<<v.capacity()<<endl;
    cout<<"begin after insert:"<<*begin<<endl;
    for (auto i : v) cout << i << " ";

    return 0;
}