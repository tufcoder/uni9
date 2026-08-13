#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc > 2 || argc < 2)
    {
        printf("Número incorreto de parâmetros! Encerrando...\n");

        return 1;
    }

    int total = atoi(argv[1]);

    if (total <= 0)
    {
        printf("Informe um número maior que zero.\n");

        return 1;
    }

    float* notas = malloc(sizeof(float) * total);

    if (notas == NULL) return 1;

    float soma = 0.0f;

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

    free(notas);

    return 0;
}
