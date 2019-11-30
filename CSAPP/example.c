#include<stdio.h>
#include"string.h"
typedef unsigned char* byte_pointer;

//
void show_byte(byte_pointer start,int len){
    int i;
    for ( i = 0; i < len; i++)
    {
        printf("%.2x",start[i]);
    }
    printf("\n");
    
}
void show_int(int x){
    show_byte((byte_pointer) &x,sizeof(int) );
}

void show_float(float x){
    show_byte((byte_pointer) &x,sizeof(float));
}

void show_pointer(void* x){
    show_byte((byte_pointer) &x,sizeof(void *));
}

void test_show_bytes(int val) {
 int ival = val;
 float fval = (float) ival;
 int *pval = &ival;
 show_int(ival);
 show_float(fval);
 show_pointer(pval);
 }

 int main(){
    char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s));
    //  test_show_bytes(12345);
     return 0;
 }