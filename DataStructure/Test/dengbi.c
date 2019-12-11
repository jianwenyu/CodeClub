#include <stdio.h>

int cnt = 0;

int fib(int n)
{
    cnt++;
    //printf("%d: %d\n",n,cnt);
    if (n == 0)
        return 1;
    else if (n == 1)
        return 2;
    else
        return fib(n - 1) + fib(n - 2);
}

void main()
{
    int i;
    int y;
    for(i=0;i<9;i++){
        cnt=0;
        y = fib(i);
        printf("%d: %d: %d\n",i,y,cnt);
    }
    
    //printf("%d: %d\n",y,cnt);
}