#include <stdio.h>

void ordem_crescente(int a, int b, int c)
{
    if (a <= b && a <= c)
    {
        if (b <= c)
        {
            printf("Ordem crescente: %d %d %d\n", a, b, c);
        }
        else
        {
            printf("Ordem crescente: %d %d %d\n", a, c, b);
        }
    }
    else if (b <= a && b <= c)
    {
        if (c <= a)
        {
            printf("Ordem crescente: %d %d %d\n", b, c, a);
        }
        else
        {
            printf("Ordem crescente: %d %d %d\n", b, a, c);
        }
    }
    else if (c <= a && c <= b)
    {
        if (a <= b)
        {
            printf("Ordem crescente: %d %d %d\n", c, a, b);
        }
        else
        {
            printf("Ordem crescente: %d %d %d\n", c, b, a);
        }
    }
    else
    {
        printf("Ordem crescente: %d %d %d\n", a, b, c);
    }
}

int main(void)
{
    int a = 30;
    int b = 10;
    int c = 20;

    ordem_crescente(a, b, c);

    return 0;
}
