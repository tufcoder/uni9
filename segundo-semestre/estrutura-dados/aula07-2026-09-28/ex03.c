#include <stdio.h>

int maior_de_tres(int a, int b, int c)
{
    if (a > b && a > c)
    {
        return a;
    }
    else if (b > a && b > c)
    {
        return b;
    }
    else if (c > b && c > a)
    {
        return c;
    }

    return a;
}

int main(void)
{
    int a = 10;
    int b = 20;
    int c = 30;

    printf("O maior entre %d, %d, %d é %d\n", a, b, c, maior_de_tres(a, b, c));

    return 0;
}
