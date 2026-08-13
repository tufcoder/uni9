#include <stdio.h>

int main(void)
{
    int total = 0;

    printf("Entre com o total de notas: ");

    if (scanf("%d", &total) != 1)
    {
        printf("Entrada inválida! Encerrando...\n");

        return 1;
    }

    // A partir do padrão C99
    // VLA: Variable Length Array (Array de Tamanho Variável)
    // não podem ser inicializados diretamente na declaração
    float notas[total];
    float soma = 0.0f;

    printf("\n");

    for (int i = 0; i < total; i++)
    {
        printf("Entre com a nota %d: ", i + 1);

        if (scanf("%f", &notas[i]) != 1)
        {
            printf("Entrada inválida! Encerrando...\n");

            return 1;
        }

        soma += notas[i];
    }

    float media = soma / total;

    printf("\nMédia do aluno: %.1f\n", media);

    return 0;
}
