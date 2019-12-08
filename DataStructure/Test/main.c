#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char *str[] = {"abcde", "cd", "ef", "gh", "ij", "kl"};
    char *t;
    t = (str + 4)[-2];
    printf("%s\n", t);
    printf("length of the string is %d\n",strlen(str[0]));
    
}

