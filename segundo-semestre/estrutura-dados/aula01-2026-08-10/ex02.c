#include <stdio.h>

int main(void)
{
    // Variáveis
    float notas[3] = {0};
    float media = 0.0f;

    // Entrada de dados
    printf("Entre com a nota 1: ");
    scanf("%f", &notas[0]);

    printf("Entre com a nota 2: ");
    scanf("%f", &notas[1]);

    printf("Entre com a nota 3: ");
    scanf("%f", &notas[2]);

    // Processamento de dados
    media = (notas[0] + notas[1] + notas[2]) / 3;

    // Saída
    printf("\nMédia do aluno: %.1f\n", media);

    return 0;
}
