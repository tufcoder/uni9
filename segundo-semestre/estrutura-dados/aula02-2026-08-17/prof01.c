#include <stdio.h>

int main()
{
    int vet[20];
    int n, t = 5, mv, p;

    // Entrada de dados
    for (int i = 0; i < t; i++)
    {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &vet[i]);
    }

    // Maior numero
    mv = vet[0];
    p = 0;

    for (int i = 1; i < t; i++)
    {
        if (vet[i] > mv)
        {
            mv = vet[i];
            p = i;
        }
    }

    // Apresentar o maior valor
    printf("O maior valor é %d, ele está na posição %d\n", mv, p);

    return 0;
}
