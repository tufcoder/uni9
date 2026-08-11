#include <stdio.h>

int main(void)
{
    // int:     inteiros
    // float:   números com casas decimais

    // variáveis
    float nota1, nota2, nota3, media;

    // Entrada de dados
    printf("Entre com a nota 1: ");
    scanf("%f", &nota1);

    printf("Entre com a nota 2: ");
    scanf("%f", &nota2);

    printf("Entre com a nota 3: ");
    scanf("%f", &nota3);

    // Processamento de dados
    media = (nota1 + nota2 + nota3) / 3;

    // Saída de dados
    printf("\nMédia do aluno: %.1f\n", media);

    return 0;
}
