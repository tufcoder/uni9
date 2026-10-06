#include <stdio.h>

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

void resetar_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = 0;
    }
}

void receber_notas(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Cliente %d\n", (i + 1));

        while (1 == 1)
        {
            printf("\tInsira uma nota (0 a 10): ");
            scanf("%d", &vetor[i]);

            if (vetor[i] < 0 || vetor[i] > 10)
                printf("\tValor incorreto, tente novamente...\n");
            else
                break;
        }
    }
}

void print_satisfacao(int vetor[], int tamanho)
{
    if (maior(vetor, tamanho) == 10)
        printf("\nÓtimo! Houve clientes totalmente satisfeitos.\n");
    else
        printf("\nNenhum cliente deu nota máxima.\n");
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
    int notas[15];

    resetar_vetor(notas, 15);
    receber_notas(notas, 15);
    bsort(notas, 15);
    print_satisfacao(notas, 15);

    return 0;
}
