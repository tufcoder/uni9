#include <stdio.h>

int main(void)
{
    int poltronas[10][4] = {0};
    int opcao = 0;
    int fileira = 0;
    int poltrona = 0;
    int total_assentos_ocupados = 0;

    while (1==1)
    {
        printf("\n--- MENU ---\n\n");
        printf("1 - Visualizar Mapa\n");
        printf("2 - Reservar Assento\n");
        printf("3 - Status do Voo\n");
        printf("4 - Sair\n\n");

        printf("Digite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                for (int i = 0; i < 10; i++)
                {
                    printf("Fileira %02d: ", (i + 1));

                    for (int y = 0; y < 4; y++)
                    {
                        if (poltronas[i][y] == 0)
                        {
                            printf("%c ", 'L');
                        }
                        else
                        {
                            printf("%c ", 'X');
                        }
                    }

                    printf("\n");
                }
                break;
            case 2:
                printf("Informe uma fileira (1-10): ");
                scanf("%d", &fileira);

                printf("Informe uma poltrona (1-4): ");
                scanf("%d", &poltrona);

                if (poltronas[fileira-1][poltrona-1] == 1)
                {
                    printf("\n\n*** Assento já reservado, tente outro ***\n\n");
                }
                else
                {
                    poltronas[fileira-1][poltrona-1] = 1;
                }
                break;
            case 3:
                total_assentos_ocupados = 0;

                for (int i = 0; i < 10; i++)
                {
                    for (int y = 0; y < 4; y++)
                    {
                        if (poltronas[i][y] == 1)
                        {
                            total_assentos_ocupados++;
                        }
                    }
                }

                printf("\nTotal de assentos ocupados: %d\n", total_assentos_ocupados);
                printf("Porcentagem de ocupação do Vôo: %.2f%%\n",
                        (float)total_assentos_ocupados / (10 * 4) * 100);
                break;
            case 4:
                return 0;
                break;
            default:
                break;
        }
    }

    return 0;
}
