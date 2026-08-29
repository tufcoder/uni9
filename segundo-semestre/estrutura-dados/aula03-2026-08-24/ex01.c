#include <stdio.h>

int main(void)
{
    int medicamentos[4][5] = {{0}};
    int total_itens_estoque = 0;

    for (int x = 0; x < 4; x++)
    {
        printf("Dados da Farmácia %d:\n", (x + 1));

        for (int y = 0; y < 5; y++)
        {
            printf("\tQtd medicamento %d: ", (y + 1));
            scanf("%d", &medicamentos[x][y]);
        }
    }

    printf("\n****************************************\n");
    printf("\tTOTAL DO ESTOQUE");
    printf("\n****************************************\n");

    for (int x = 0; x < 4; x++)
    {
        printf("Total da Farmácia %d:\n", (x + 1));

        total_itens_estoque = 0;

        for (int y = 0; y < 5; y++)
        {
            total_itens_estoque += medicamentos[x][y];

            printf("\tMedicamento %d: %d em estoque\n", (y + 1), medicamentos[x][y]);

            if (medicamentos[x][y] < 10)
            {
                printf("\t*** ESTOQUE CRÍTICO ***\n");
            }
        }

        printf("\nA farmácia %d tem um estoque de %d medicamentos\n\n", (x + 1), total_itens_estoque);
    }

    return 0;
}
