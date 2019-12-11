#include <stdio.h>
void sub(char *s, int num)
{
    int i, j = num;
    char t;
    while (j-- > 1)
    {
        for (i = 0; i < j; i++)
        {
            if (s[i] < s[i + 1])
            {
                t = s[i];
                s[i] = s[i + 1];
                s[i + 1] = t;
            }
        }
    }
}

int main()
{
    char *s = "CEAeded";
    char p[] = "CEAeded";
    //sub(s, 7);
    sub(p, 7);
    printf("%s\n", s);
    printf("%s\n", p);

    return 0;
}