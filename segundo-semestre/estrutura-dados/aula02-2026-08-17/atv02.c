#include <stdio.h>

int main(void)
{
    int a[10] = {1,2,3,4,99,6,7,8,9,0};
    int maior = a[0];

    for (int i = 0; i < 10; i++)
    {
        if (a[i] > maior)
            maior = a[i];
    }

    printf("%d\n", maior);

    return 0;
}
