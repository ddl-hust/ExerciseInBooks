#include"Quote.h"
int main(){
    Quote q("ddl",100);
    disc_quote bq("hust",1000,10,0.1);
    Quote* ptr=&bq;
    ptr->debug();
    return 0;
}