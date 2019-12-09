#include <stdio.h>
#include <stdlib.h>

#define SETBIT(x,n) (x|=(1L<<n))
#define CLEARBIT(x,n) (x&=~(1L<<n))

int main(void)
{
    int a = 1;
    int b = 15;
    printf("a: %d, b:%d\n",a,b);
    SETBIT(a,3);
    CLEARBIT(b,2);
    printf("a: %d, b:%d\n",a,b);
    return 0;
}
