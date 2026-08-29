#include <stdio.h>

int main(void)
{
    int medicamentos[4][5];
    int total_itens_estoque;

    for (int x = 0; x < 4; x++)
    {
        printf("Farmácia %d:\n", (x + 1));

        total_itens_estoque = 0;

        for (int y = 0; y < 5; y++)
        {
            printf("\tQtd medicamento %d: ", (y + 1));
            scanf("%d", &medicamentos[x][y]);

            total_itens_estoque += medicamentos[x][y];

            if (medicamentos[x][y] < 10)
            {
                printf("\tO medicamento %d está com o *** ESTOQUE CRÍTICO ***\n", (y + 1));
            }
        }

        printf("\nA farmácia %d tem um estoque de %d medicamentos\n\n", (x + 1), total_itens_estoque);
    }

    return 0;
}
