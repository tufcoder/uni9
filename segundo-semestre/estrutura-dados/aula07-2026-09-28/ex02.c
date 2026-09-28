#include <stdio.h>

float calcula_desconto(float valor, float desconto)
{
    return valor * desconto;
}

int main(void)
{
    printf("Desconto aplicado de: R$ %.2f\n", calcula_desconto(100.00f, 0.1f));
    return 0;
}
