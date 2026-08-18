#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int total = 0;

    printf("Digite o valor inicial de A: ");
    scanf("%d", &a);

    printf("Digite o valor final de B: ");
    scanf("%d", &b);

    total = b - a;

    for (int i = 0; i <= total; i++)
    {
        printf("%d ", a+i);
    }

    printf("\n");

    return 0;
}
