#include <stdio.h>

int main(int argc, char **argv){
    int a = -3, b =2;
    printf("a:%d  b:%d \n",a,b);
    
    a=a+b;
    b=a-b;
    a=a-b;
    printf("a:%d  b:%d \n",a,b);
    a = a^b;
    b = a^b;
    a = a^b;
    printf("a:%d  b:%d \n",a,b);
    return 0;

}