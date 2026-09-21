#include <stdio.h>

char controle = 's';
char categorias[5][30] = {
    "Alimentação",
    "Transporte",
    "Lazer",
    "Saúde",
    "Educação",
};
float gastos[5] = {0.0f};
float total_gastos = 0.0f;
int indice_categoria_maior_gasto = 0;
int indice_categoria_menor_gasto = 0;

float calcula_total_gastos()
{
    float total = 0.0f;

    for (int i = 0; i < 5; i++)
    {
        total += gastos[i];
    }

    return total;
}

int maior_gasto()
{
    int indice = 0;

    for (int i = 0; i < 5; i++)
    {
        if (gastos[i] > gastos[indice])
        {
            indice = i;
        }
    }

    return indice;
}

int menor_gasto()
{
    int indice = 0;

    for (int i = 0; i < 5; i++)
    {
        if (gastos[i] < gastos[indice])
        {
            indice = i;
        }
    }

    return indice;
}

void entrada_dados()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Insira o gasto com %s: ", categorias[i]);
        scanf("%f", &gastos[i]);

        indice_categoria_maior_gasto = maior_gasto();
        indice_categoria_menor_gasto = menor_gasto();
    }

    total_gastos = calcula_total_gastos();
}

void print_total_gastos()
{
    printf("\nTotal de gastos: %.2f\n", total_gastos);
}

void print_media_mensal()
{
    printf("Média mensal de gastos: %.2f\n", total_gastos / 5);
}

void print_maior_gasto()
{
    printf("Maior gasto: %s - %.2f\n",
            categorias[indice_categoria_maior_gasto],
            gastos[indice_categoria_maior_gasto]
    );
}

void print_menor_gasto()
{
    printf("Menor gasto: %s - %.2f\n",
            categorias[indice_categoria_menor_gasto],
            gastos[indice_categoria_menor_gasto]
    );
}

void print_novos_valores()
{
    printf("Deseja inserir novos valores? (S/N)");
    scanf(" %c", &controle);
}

int main(void)
{
    while (controle != 'N' && controle != 'n')
    {
        entrada_dados();
        print_total_gastos();
        print_media_mensal();
        print_maior_gasto();
        print_menor_gasto();
        print_novos_valores();

        printf("\n");
    }

    return 0;
}
