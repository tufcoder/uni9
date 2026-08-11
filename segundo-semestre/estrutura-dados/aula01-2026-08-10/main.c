#include <stdio.h>

// Macro como constante para evitar magic numbers e code smells
#define MAX_NOTAS 3

// Macro para buscar o tamanho do array
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main(void)
{
    float notas[MAX_NOTAS] = {0};
    float soma = 0.0f;
    // o size_t é comumente usado para tamanhos em bytes
    size_t total = ARRAY_SIZE(notas);

    for (size_t i = 0; i < total; i++)
    {
        printf("Entre com a nota %zu: ", i + 1);

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
