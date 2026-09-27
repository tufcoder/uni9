#include <stdio.h>

int total = 5;
char funcionarios[5][30];
int ferias[5][2];
int saldo_ferias[5];

void resetar() {
    for (int i = 0; i < 5; i++) {
        saldo_ferias[i] = -1;

        for (int j = 0; j < 2; j++) {
            ferias[i][j] = -1;
        }
        
        for (int k = 0; k < 30; k++) {
            funcionarios[i][k] = 0;
        }
    }
}

int calcular_saldo(int dias_acumulados, int dias_tirados) {
    return dias_acumulados - dias_tirados;
}

void maior_saldo_ferias() {
    printf("\n");
    int indices[5];
    int maior = 0;
    int quantidade = 0;

    for (int i = 0; i < 5; i++) {
        indices[i] = -1;
    }

    for (int i = 0; i < total; i++) {
        if (saldo_ferias[i] > 0 && saldo_ferias[i] >= maior) {
            maior = saldo_ferias[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        if (saldo_ferias[i] == maior) {
            quantidade++;
            indices[i] = i;
        }
    }

    if (quantidade == 0) {
        printf("Ninguém tem saldo maior de ferias\n");
    }
    else if (quantidade > 1) {
        char nomes[5][30];
        int indice = 0;

        for (int i = 0; i < 5; i++) {
            if (indices[i] != -1) {
                for (int j = 0; j < 30; j++) {
                    nomes[indice][j] = funcionarios[indices[i]][j];
                }

                indice++;
            }
        }

        if (quantidade == 2) {
            printf("Maior saldo de ferias %s e %s: (%d dias)\n",
                nomes[0],
                nomes[1],
                saldo_ferias[indices[0]]
            );
        }
        else if (quantidade == 3) {
            printf("Maior saldo de ferias %s e %s e %s: (%d dias)\n",
                nomes[0],
                nomes[1],
                nomes[2],
                saldo_ferias[indices[0]]
            );
        }
        else if (quantidade == 4) {
            printf("Maior saldo de ferias %s e %s e %s e %s: (%d dias)\n",
                nomes[0],
                nomes[1],
                nomes[2],
                nomes[3],
                saldo_ferias[indices[0]]
            );
        }
        else if (quantidade == 5) {
            printf("Maior saldo de ferias %s e %s e %s e %s e %s: (%d dias)\n",
                nomes[0],
                nomes[1],
                nomes[2],
                nomes[3],
                nomes[4],
                saldo_ferias[indices[0]]
            );
        }
    }
    else {
        for (int i = 0; i < 5; i++) {
            if (indices[i] != -1) {
                printf("Maior saldo de ferias %s: (%d dias)\n",
                    funcionarios[indices[i]],
                    saldo_ferias[indices[i]]
                );
                break;
            }
        }
    }
}

void menor_saldo_ferias() {
    int indices[5];
    int menor = 0;
    int quantidade = 0;

    for (int i = 0; i < 5; i++) {
        indices[i] = -1;
    }

    for (int i = 0; i < total; i++) {
        if (saldo_ferias[i] <= menor) {
            menor = saldo_ferias[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        if (saldo_ferias[i] == menor) {
            quantidade++;
            indices[i] = i;
        }
    }

    if (quantidade == 0) {
        printf("Ninguém tem saldo menor de ferias\n");
    }
    else if (quantidade > 1) {
        char nomes[5][30];
        int indice = 0;

        for (int i = 0; i < 5; i++) {
            if (indices[i] != -1) {
                for (int j = 0; j < 30; j++) {
                    nomes[indice][j] = funcionarios[indices[i]][j];
                }

                indice++;
            }
        }

        if (quantidade == 2) {
            printf("Menor saldo de ferias %s e %s: (%d dias)\n",
                nomes[0],
                nomes[1],
                saldo_ferias[indices[0]]
            );
        }
        else if (quantidade == 3) {
            printf("Menor saldo de ferias %s e %s e %s: (%d dias)\n",
                nomes[0],
                nomes[1],
                nomes[2],
                saldo_ferias[indices[0]]
            );
        }
        else if (quantidade == 4) {
            printf("Menor saldo de ferias %s e %s e %s e %s: (%d dias)\n",
                nomes[0],
                nomes[1],
                nomes[2],
                nomes[3],
                saldo_ferias[indices[0]]
            );
        }
        else if (quantidade == 5) {
            printf("Menor saldo de ferias %s e %s e %s e %s e %s: (%d dias)\n",
                nomes[0],
                nomes[1],
                nomes[2],
                nomes[3],
                nomes[4],
                saldo_ferias[indices[0]]
            );
        }
        
    }
    else {
        for (int i = 0; i < 5; i++) {
            if (indices[i] != -1) {
                printf("Menor saldo de ferias %s: (%d dias)\n",
                    funcionarios[indices[i]],
                    saldo_ferias[indices[i]]
                );
                break;
            }
        }
    }
}

void print_saldo_ferias() {
    printf("\n");
    
    for (int i = 0; i < total; i++) {
        saldo_ferias[i] = calcular_saldo(ferias[i][0], ferias[i][1]);
        
        printf("Saldo de ferias de %s: %d dias\n", funcionarios[i], saldo_ferias[i]);
    }
}

void entrada_dados() {
    resetar();

    for (int i = 0; i < total; i++) {
        printf("\nInsira o nome do funcionario: ");
        fgets(funcionarios[i], 30, stdin);
        
        for (int j = 0; j < 30; j++) {
            if (funcionarios[i][j] == '\n') {
                funcionarios[i][j] = '\0';
            }
        }

        printf("Dias de ferias acumulados: ");
        scanf("%d", &ferias[i][0]);

        printf("Dias de ferias ja tirados: ");
        scanf("%d", &ferias[i][1]);

        while (getchar() != '\n');
    }
}

int main() {
    entrada_dados();
    print_saldo_ferias();
    maior_saldo_ferias();
    menor_saldo_ferias();
}
