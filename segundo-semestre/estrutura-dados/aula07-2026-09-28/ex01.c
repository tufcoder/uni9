#include <stdio.h>

void categoria_idade(int idade)
{
    if (idade >= 0 && idade <= 12)
        printf("Criança\n");
    else if (idade >= 13 && idade <= 17)
        printf("Adolescente\n");
    else if (idade >= 18 && idade <= 59)
        printf("Adulto\n");
    else if (idade >= 60)
        printf("Idoso\n");
}

int main(void)
{
    categoria_idade(12);
    categoria_idade(17);
    categoria_idade(59);
    categoria_idade(60);

    return 0;
}
