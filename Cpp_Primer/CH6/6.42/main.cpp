#include <iostream>
#include <string>
using namespace std;
/*
 * give make_plural a default parm
 */
string make_plural(size_t ctr,const string &word,const string& ending="s")
{
    return(ctr>1?word+ending:word);
}
int main() {

    cout<<"单数："<<make_plural(1,"success","es")<<endl;
    cout<<"fushu:"<<make_plural(2,"success","es")<<endl;
    return 0;
}
