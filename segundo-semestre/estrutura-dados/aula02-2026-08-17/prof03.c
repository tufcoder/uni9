#include <stdio.h>

int main()
{
    int a[10], m[10];
    int x, t = 5;

    for (int i = 0; i < t; i++)
    {
        printf("Digite o valor da posição a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nDigite o valor de x: ");
    scanf("%d", &x);

    for (int i = 0; i < t; i++)
    {
        m[i] = a[i] * x;
    }

    for (int i = 0; i < t; i++)
    {
        printf("\n%d x %d = %d ", a[i], x, m[i]);
    }

    printf("\n");

    return 0;
}
