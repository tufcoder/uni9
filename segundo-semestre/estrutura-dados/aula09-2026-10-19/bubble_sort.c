int contador;

void bubble_sort(int vetor[], int tamanho)
{
    int temp;

    contador = 0;

    for (int i = 0; i < (tamanho - 1); i++)
    {
        contador++;

        for (int j = 0; j < tamanho - (i + 1); j++)
        {
            contador++;

            if (vetor[j] > vetor[j + 1])
            {
                contador += 3;

                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
