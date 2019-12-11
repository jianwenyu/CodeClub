#include <stdio.h>
#include <stdlib.h>

/* int maxPoints(int **points, int pointsSize, int *pointsColSize)
{
    int n = 0;
    int i = 0;
    int j = 0;
    int vertical = 0;
    int horizontal = 0;
    int mix = 0;
    int temp = 0;
    int max = 0;
    int *p = (int *)points;
    printf("before for loop %d\n",p[2]);
    // Case 1: vertical

    for (i = 0; i < pointsSize; i++)
    {
        vertical = 0;
        horizontal = 0;
        mix = 0;
        temp = 0;

        for (j = pointsSize-1; j > i; j--)
        {
            if (p[i][0] == p[j][0])
            {
                vertical++;
                printf("vertical:%d\n",vertical);
            }
            if (p[i][1] == p[j][1])
            {
                horizontal++;
                printf("horizontal:%d\n",horizontal);
            }
            if (p[i][0] != p[j][0] && p[i][1] != p[j][1])
            {
                if (j == pointsSize-1)
                {
                    temp = (p[i][1] - p[j][1]) / (p[i][0] - p[j][0]);
                    mix++;
                    printf("temp:%d\n",temp);
                }
                else
                {
                    if (temp == ((p[i][1] - p[j][1]) / (p[i][0] - p[j][0])))
                    {
                        mix++;
                        printf("mix:%d\n",mix);
                    }
                }
            }
        }
        if (vertical > horizontal)
        {
            if (max < vertical)
            {
                max = vertical;
            }
        }
        else
        {
            if (max < horizontal)
            {
                max = horizontal;
            }
        }
        if (mix > max)
        {
            max = mix;
        }
    }
    return max;
} */
int maxPoints(int **points, int pointsSize, int *pointsColSize)
{
    int n = 0;
    int i = 0;
    int j = 0;
    int vertical = 0;
    int horizontal = 0;
    int mix = 0;
    int temp = 0;
    int max = 0;
    int (*p)[*pointsColSize] = (int (*)[*pointsColSize])points;
    printf("before for loop %d\n",p[2][1]);
    // Case 1: vertical

    for (i = 0; i < pointsSize; i++)
    {
        vertical = 1;
        horizontal = 1;
        mix = 1;
        temp = 0;

        for (j = pointsSize-1; j > i; j--)
        {
            if (p[i][0] == p[j][0])
            {
                vertical++;
                printf("vertical:%d\n",vertical);
            }
            if (p[i][1] == p[j][1])
            {
                horizontal++;
                printf("horizontal:%d\n",horizontal);
            }
            if (p[i][0] != p[j][0] && p[i][1] != p[j][1])
            {
                if (j == pointsSize-1)
                {
                    temp = (p[i][1] - p[j][1]) / (p[i][0] - p[j][0]);
                    mix++;
                    printf("temp:%d\n",temp);
                }
                else
                {
                    if (temp == ((p[i][1] - p[j][1]) / (p[i][0] - p[j][0])))
                    {
                        mix++;
                        printf("mix:%d\n",mix);
                    }
                }
            }
        }
        if (vertical > horizontal)
        {
            if (max < vertical)
            {
                max = vertical;
            }
        }
        else
        {
            if (max < horizontal)
            {
                max = horizontal;
            }
        }
        if (mix > max)
        {
            max = mix;
        }
    }
    return max;
}

int main()
{
    int col = 2;
    int max[6][2] = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    int n = maxPoints((int**)max,6,&col);
    printf("%d \n",n);
    return 0;
}