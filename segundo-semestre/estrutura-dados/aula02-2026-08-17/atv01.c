#include <stdio.h>

int main(void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    int b[10] = {0,9,8,7,6,5,4,3,2,1};
    int c[20] = {0};

    for (int i = 0; i < 20; i++)
    {
        if (i < 10)
            c[i] = a[i];
        else
            c[i] = b[i - 10];
    }

    printf("[");

    for (int i = 0; i < 20; i++)
    {
        if (i < (20 - 1))
            printf("%d,", c[i]);
        else
            printf("%d", c[i]);
    }

    printf("]\n");

    return 0;
}
