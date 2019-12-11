#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void foo(void)
{
    unsigned int a = 6;
    int b = -20;

    (a + b > 6) ? puts(">6") : puts("<=6");
    printf("%d\n",a+b);
}

void main()
{
    char *str[] = {"abcde", "cd", "ef", "gh", "ij", "kl"};
    char *t;
    t = (str + 4)[-2];
    printf("%s\n", t);
    printf("length of the string is %d\n", strlen(str[0]));
    int *pa;
    char *pb;
    double *pc;
    printf("%d, %d, %d\n", sizeof(pa), sizeof(pb), sizeof(pc));
    foo();
}
