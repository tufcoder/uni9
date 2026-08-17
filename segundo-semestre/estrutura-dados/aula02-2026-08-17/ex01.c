#include <stdio.h>

int main(void)
{
    int q[20] = {1,2,3,4,5,6,7,8,9,20,11,12,13,14,15,16,17,18,19,20};
    int maior = q[0];
    int indice = 0;

    for (int i = 0; i < 20; i++)
    {
        if (q[i] > maior)
        {
            maior = q[i];
            indice = i;
        }
    }

    printf("O maior valor é q[%d] = %d\n", indice, maior);

    return 0;
}
