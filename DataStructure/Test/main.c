#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *str[] = {"ab", "cd", "ef", "gh", "ij", "kl"};
    char *t;
    t = (str + 4)[-2];
    printf("%s\n", t);
}

