#include <iostream>
#include <fstream>
#include "Sales_data.h"
//从给定文件读取，将结果输出到给定文件
int main(int argv,char** argc) {
    Sales_data total;
    fstream fs("../input");
    fstream out("../outdada",ios::out|ios::app);
    if(read(fs,&total))
    {
        Sales_data trans;
        while(read(fs,&trans)){
            if(trans.isbn()==total.isbn()){
                total.combine(trans);
            }
            else {
                print(out,&total)<<endl;
                total=trans;
            }
        }
        print(out,&total);
    } else cerr<<"No data"<<endl;

    return 0;
}