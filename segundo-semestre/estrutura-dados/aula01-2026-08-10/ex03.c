#include <stdio.h>

int main(void)
{
    float notas[3] = {0};
    float media = 0.0f;
    float soma = 0.0f;

    for (int i = 0; i < 3; i++)
    {
        printf("Entre com a nota %d: ", i + 1);
        scanf("%f", &notas[i]);

        soma += notas[i];
    }

    media = soma / 3;

    printf("\nMédia do aluno: %.1f\n", media);

    return 0;
}
