#include <stdio.h>

int main(void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int x = 10;
    int m[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        m[i] = a[i] * x;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("m[%d] = %d\n", i, m[i]);
    }

    printf("\n");

    return 0;
}
