#include <stdio.h>

int main(){
    int a = 1;
    int b = 2;
    int c = 3;
    const int *pa=&a; // Constant "int" means the value of the integer is constant
    //*pa=3; //invalid
    int *const pb = &b;
    *pb = 4;
    //pb = pa; //invalid
    printf("a is %d\n",a);
    printf("b is %d\n",*pb);
    return 0;
}