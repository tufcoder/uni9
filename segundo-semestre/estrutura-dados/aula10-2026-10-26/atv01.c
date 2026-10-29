#include <stdio.h>

int contador = 0;

void insertion_sort(float vetor[], int tamanho)
{
    int temp;
    int j;

    contador = 0;

    for (int i = 1; i < tamanho; i++)
    {
        temp = vetor[i];
        j = i - 1;

        contador += 3;

        while (j >= 0 && vetor[j] > temp)
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;

            contador += 3;
        }

        vetor[j + 1] = temp;
        contador++;
    }
}

void selection_sort(float vetor[], int tamanho)
{
    int indice_minimo;
    int temp;
    contador = 0;

    for (int i = 0; i < (tamanho - 1); i++)
    {
        indice_minimo = i;
        contador += 2;

        for (int j = (i + 1); j < tamanho; j++)
        {
            contador++;

            if (vetor[j] < vetor[indice_minimo])
            {
                indice_minimo = j;
                contador++;
            }
        }

        if (i != indice_minimo)
        {
            contador += 3;

            temp = vetor[i];
            vetor[i] = vetor[indice_minimo];
            vetor[indice_minimo] = temp;
        }
    }
}

void print_vetor(float vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%.2f ", vetor[i]);
    }

    printf("\n");
}

int main(void)
{
    int qtd_precos = 0;

    printf("Quantos preços deseja cadastrar? ");
    scanf("%d", &qtd_precos);

    float precos[qtd_precos];

    printf("Digite os preços:\n");

    for (int i = 0; i < qtd_precos; i++)
    {
        scanf("%f", &precos[i]);
    }

    printf("\nPreços antes da ordenação:\n");
    print_vetor(precos, qtd_precos);

    insertion_sort(precos,  qtd_precos);

    printf("\nPreços depois da ordenação (Insertion Sort):\n");
    print_vetor(precos, qtd_precos);

    printf("\nTotal de passos realizados: %d\n", contador);

    return 0;
}
