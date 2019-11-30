#include <iostream>
//通过异或位运算来交换两个数，不引入temp
void inplace_swap(int *x, int *y) {
 *y = *x ^ *y; /* Step 1 */
 *x = *x ^ *y; /* Step 2 */
 *y = *x ^ *y; /* Step 3 */
 }
 //2_11
 void reverse_array(int a[],int len){
     for (int first = 0,last=len-1; first <last ; ++first,--last) {
         inplace_swap(&a[first],&a[last]);
     }
}
int main() {
    int a=3,b=4;
    inplace_swap(&a,&b);
    int arr[]={1,2,3,4};
    reverse_array(arr,4);
    for(auto c:arr) std::cout<<c<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}