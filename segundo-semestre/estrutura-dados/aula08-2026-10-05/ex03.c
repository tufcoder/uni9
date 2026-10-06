#include <stdio.h>

void resetar_vetor(float vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = 0;
    }
}

void receber_notas(float vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Entre com a nota %d: ", (i + 1));
        scanf("%f", &vetor[i]);
    }
}

void print_vetor(float vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] >= 6)
            printf("Nota %.2f: APROVADO\n", vetor[i]);
        else
            printf("Nota %.2f: REPROVADO\n", vetor[i]);
    }

    printf("\n");
}

void bsort_desc(float vetor[], int tamanho)
{
    float temp = 0;

    for (int i = 0; i < (tamanho - 1); i++)
    {
        for (int j = 0; j < tamanho - (i + 1); j++)
        {
            if (vetor[j] < vetor[j + 1])
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
    float notas[10];

    resetar_vetor(notas, 10);
    receber_notas(notas, 10);
    bsort_desc(notas, 10);
    print_vetor(notas, 10);

    return 0;
}
