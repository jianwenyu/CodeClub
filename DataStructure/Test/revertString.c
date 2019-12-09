#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* void inverted_order(char *p)
{
    char *s1, *s2, tem;
    s1 = p;
    s2 = s1 + strlen(p) - 1;
    while (s1 < s2)
    {
        tem = *s1;
        *s1 = *s2;
        *s2 = tem;
        s1++;
        s2--;
    }
} */


void inverted_order(char *p)
{
    char *s1,*s2,temp;
    s1 = p;
    s2 = s1+strlen(p)-1;
    while(s1<s2){
        temp = *s1;
        *s1=*s2;
        *s2=temp;
        s1++;
        s2--;
    }
}

int main(int argc, char **argv)
{
    if(argc<2){
        printf("usage: main string\n");
        return -1;
    }
    printf("length of string is %d\n",strlen(argv[1]));
    printf("%s\n",argv[1]);
    inverted_order(argv[1]);
    printf("%s\n",argv[1]);
    return 0;
}