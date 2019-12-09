#include <stdio.h>
#include <stdlib.h>
void count();
int main(void)
{
    int i=0;
    for (i = 0;i <= 5;i++)
    {
            count();
    }
    return 0;
}
void count()
{
    /*声明一个静态局部变量*/
    static int num = 0;
    num++;
    printf("%d\n",num);
}