#include <stdio.h>

int main(void)
{
    float bonus = 50.0f;
    float comissao = 0.1f;
    float valor_comissao = 0.0f;
    float total_vendas = 0.0f;

    printf("Digite o total de vendas no mês R$ ");
    scanf("%f", &total_vendas);

    valor_comissao = total_vendas * comissao;

    printf("Valor da comissão R$ %.2f\n", valor_comissao);

    if (total_vendas > 1000)
        valor_comissao += bonus;

    printf("Valor total R$ %.2f\n", valor_comissao);

    return 0;
}
