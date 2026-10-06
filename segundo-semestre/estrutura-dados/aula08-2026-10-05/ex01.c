#include <stdio.h>

void print_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (i < tamanho - 1)
            printf("%d ", vetor[i]);
        else
            printf("%d", vetor[i]);
    }

    printf("\n");
}

int maior(int vetor[], int tamanho)
{
    int maior = vetor[0];

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] > maior)
            maior = vetor[i];
    }
    
    return maior;
}

int menor(int vetor[], int tamanho)
{
    int menor = vetor[0];

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] < menor)
            menor = vetor[i];
    }
    
    return menor;
}

void bsort(int vetor[], int tamanho)
{
    int temp = 0;

    for (int i = 0; i < (tamanho - 1); i++)
    {
        for (int j = 0; j < tamanho - (i + 1); j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int vetor[10] = {0,9,8,7,6,5,4,3,2,1};

    bsort(vetor, 10);

    print_vetor(vetor, 10);
    printf("O maior elemento: %d\n", maior(vetor, 10));
    printf("O menor elemento: %d\n", menor(vetor, 10));

    return 0;
}
