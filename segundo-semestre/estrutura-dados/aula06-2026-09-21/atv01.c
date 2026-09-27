#include <stdio.h>

#define total 5

char funcionarios[total][30];
int dias_acumulados[total];
int dias_tirados[total];
int saldos[total];
int maior_saldo = 0;
int menor_saldo = 0;

int string_length(char *string)
{
    int i = 0;

    while (*string)
    {
        i++;
        string++;
    }

    return i;
}

int calcula_saldo_maior()
{
    int saldo = maior_saldo;

    for (int i = 1; i < total; i++)
    {
        if (saldos[i] > saldo)
        {
            saldo = saldos[i];
        }
    }

    return saldo;
}

int calcula_saldo_menor()
{
    int saldo = menor_saldo;

    for (int i = 1; i < total; i++)
    {
        if (saldos[i] < saldo)
        {
            saldo = saldos[i];
        }
    }

    return saldo;
}

void print_menor_saldo()
{
    int quantidade_nomes = 0;

    menor_saldo = calcula_saldo_menor();

    printf("Menor saldo de ferias");
    
    for (int i = 0; i < total; i++)
    {
        if (saldos[i] == menor_saldo)
        {
            if (quantidade_nomes > 0)
            {
                printf(" e");
            }

            quantidade_nomes++;

            printf(" %s", funcionarios[i]);
        }
    }
    
    printf(" (%d dias)\n", menor_saldo);
}

void print_maior_saldo()
{
    int quantidade_nomes = 0;

    maior_saldo = calcula_saldo_maior();

    printf("Maior saldo de ferias");
    
    for (int i = 0; i < total; i++)
    {
        if (saldos[i] == maior_saldo)
        {
            if (quantidade_nomes > 0)
            {
                printf(" e");
            }

            quantidade_nomes++;

            printf(" %s", funcionarios[i]);
        }
    }
    
    printf(" (%d dias)\n", maior_saldo);
}

void exibe_saldos()
{
    for (int i = 0; i < total; i++)
    {
        printf("Saldo de ferias de %s: %d dias\n", funcionarios[i], saldos[i]);
    }

    printf("\n");
}

void entrada_dados()
{
    for (int i = 0; i < total; i++)
    {
        printf("Insira o nome do funcionario: ");
        fgets(funcionarios[i], sizeof(funcionarios[i]), stdin);
        funcionarios[i][string_length(funcionarios[i]) - 1] = '\0';
        
        printf("Dias de ferias acumulados: ");
        scanf("%d", &dias_acumulados[i]);

        printf("Dias de ferias ja tirados: ");
        scanf("%d", &dias_tirados[i]);
        
        while (getchar() != '\n');

        saldos[i] = dias_acumulados[i] - dias_tirados[i];

        printf("\n");
    }
}

int main(void)
{
    entrada_dados();
    exibe_saldos();
    print_maior_saldo();
    print_menor_saldo();

    return 0;
}
