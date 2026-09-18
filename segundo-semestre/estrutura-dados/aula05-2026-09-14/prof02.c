#include <stdio.h>
#include <stdlib.h>

char nomes[3][30] = {{0}};
float agua[3] = {0.0f};
float gas[3] = {0.0f};
float luz[3] = {0.0f};
float total = 0.0f;
int i = 0;

void entrada() {
    for (i = 0; i < 3; i++) {
        printf("\nEntre com nome da pessoa %d: ", (i + 1));
        fgets(nomes[i], sizeof(nomes[i]), stdin);

        for (int j = 0; j < sizeof(nomes[i]); j++) {
            if (nomes[i][j] == '\n') {
                nomes[i][j] = '\0';
                break;
            }
        }

        printf("Entre com o valor da conta de água: ");
        scanf("%f", &agua[i]);

        printf("Entre com o valor da conta de gás: ");
        scanf("%f", &gas[i]);

        printf("Entre com o valor da conta de luz: ");
        scanf("%f", &luz[i]);

        while (getchar() != '\n');
    }
}

float calcTotal() {
    total = 0;
    total = agua[i] + gas[i] + luz[i];

    return total;
}

void maiorConsumo() {
    if (agua[i] > gas[i] && agua[i] > luz[i]) {
        printf("\nMaior consumo foi de água, no valor de: %.2f", agua[i]);
    }
    else {
        if (gas[i] > luz[i]) {
            printf("\nMaior consumo foi de gás, no valor de: %.2f", gas[i]);
        }
        else {
            printf("\nMaior consumo foi de luz, no valor de: %.2f", luz[i]);
        }
    }
}

void saida() {
    for (i = 0; i < 3; i++) {
        printf("\n\nTOTAL DAS CONTAS DO %s é: %.2f ", nomes[i], calcTotal());
        maiorConsumo();
    }
}

int main(void) {
    system("clear");

    entrada();
    saida();

    printf("\n");

    return 0;
}
