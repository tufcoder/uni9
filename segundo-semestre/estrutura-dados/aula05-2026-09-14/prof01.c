#include <stdio.h>

int main(void) {
    char nomes[3][30] = {{0}};
    float agua[3] = {0.0f};
    float gas[3] = {0.0f};
    float luz[3] = {0.0f};
    float total = 0.0f;

    for (int i = 0; i < 3; i++) {
        printf("Entre com o nome %d: ", (i + 1));
        fgets(nomes[i], sizeof(nomes[i]), stdin);

        for (int j = 0; j < sizeof(nomes[i]); j++) {
            if (nomes[i][j] == '\n') {
                nomes[i][j] = '\0';
                break;
            }
        }

        printf("Entre com o valor de água %d: ", (i + 1));
        scanf("%f", &agua[i]);

        printf("Entre com o valor de gas %d: ", (i + 1));
        scanf("%f", &gas[i]);

        printf("Entre com o valor de luz %d: ", (i + 1));
        scanf("%f", &luz[i]);

        while (getchar() != '\n');

        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        total = 0;
        total = agua[i] + gas[i] + luz[i];

        printf("\nTOTAL DA PESSOA %s é: %.2f ", nomes[i], total);

        if (agua[i] > gas[i] && agua[i] > luz[i]) {
            printf("\nMaior consumo foi de agua, no valor de: %.2f", agua[i]);
        }
        else {
            if (gas[i] > luz[i]) {
                printf("\nMaior consumo foi de gás, no valor de: %.2f", gas[i]);
            }
            else {
                printf("\nMaior consumo foi de luz, no valor de: %.2f", luz[i]);
            }
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}
