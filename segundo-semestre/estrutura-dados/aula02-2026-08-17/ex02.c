#include <stdio.h>

int main(void)
{
    int q[20] = {10,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int menor = q[0];
    int indice = 0;

    for (int i = 0; i < 20; i++)
    {
        if (q[i] < menor)
        {
            menor = q[i];
            indice = i;
        }
    }

    printf("O menor valor é q[%d] = %d\n", indice, menor);

    return 0;
}
