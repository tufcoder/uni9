#include <stdio.h>

float calcula_desconto(float valor, float desconto)
{
    return valor * desconto;
}

int main(void)
{
    float valor = 100.00f;
    float desconto = 0.1f;

    printf("Desconto aplicado de: R$ %.2f\n", calcula_desconto(valor, desconto));

    return 0;
}
