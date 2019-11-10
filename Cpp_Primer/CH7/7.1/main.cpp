#include <iostream>
#include "Sales_data.h"
//使用自己定义的sale_data 类重写书店程序
using namespace std;
int main() {
    Sales_data total;
    if(cin>>total.BookNo>>total.unit_sold>>total.revenue){
        Sales_data trans;
        while (cin>>trans.BookNo>>trans.unit_sold>>trans.revenue){
            if(total.BookNo==trans.BookNo)
            {
                total.combine(trans);
            } else  {
                print(cout,total);
                total=trans;
            }
        }
        total.print();
    }
    else{
        cerr<<"no data"<<endl;
        return 0;
    }


}