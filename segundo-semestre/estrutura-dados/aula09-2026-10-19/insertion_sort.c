int contador;

void insertion_sort(int vetor[], int tamanho)
{
    int temp;
    int j;

    contador = 0;

    for (int i = 0; i < tamanho; i++)
    {
        temp = vetor[i];
        j = i - 1;

        contador += 3;

        while (j >= 0 && vetor[j] > temp)
        {
            vetor[j + 1] = vetor[j];
            j--;

            contador += 3;
        }

        vetor[j + 1] = temp;

        contador++;
    }
}
