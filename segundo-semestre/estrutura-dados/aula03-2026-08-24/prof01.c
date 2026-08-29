#include <stdio.h>

int main(void)
{
    float notas[5][3];

    for (int x = 0; x < 5; x++)
    {
        printf("\nEntre com as informacoes do aluno %d: \n", (x + 1));

        for (int y = 0; y < 3; y++)
        {
            printf("\tEntre com a nota %d: ", (y + 1));
            scanf("%f", &notas[x][y]);
        }
    }

    printf("\n");

    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            printf("Para o aluno %d a nota %d foi: %.2f\n", (x + 1), (y + 1), notas[x][y]);
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}
