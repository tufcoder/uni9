int contador;

void selection_sort(int vetor[], int tamanho)
{
    int min;
    int temp;

    contador = 0;

    for (int i = 0; i < (tamanho - 1); i++)
    {
        min = i;
        contador += 2;

        for (int j = (i + 1); j < tamanho; j++)
        {
            contador++;

            if (vetor[j] > vetor[min])
            {
                min = j;
                contador++;
            }
        }

        if (i != min)
        {
            contador += 3;

            temp = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = temp;
        }
    }
}
