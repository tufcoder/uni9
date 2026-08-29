#include <stdio.h>

int main()
{
    float horarios[5][6] = {{0.0f}};
    float valor_sensores[2] = {0.0f};
    int indices[3] = {0};
   
    for (int x = 0; x < 5; x++)
    {
        printf("Sensor de Medição: %d\n", (x + 1));
       
        for (int y = 0; y < 6; y++)
        {
            printf("\tHorário %d (%02d:00): ", (y + 1), (y + 8));
            scanf("%f", &horarios[x][y]);
        }
    }
   
    printf("\n");
   
    for (int x = 0; x < 5; x++)
    {
        valor_sensores[0] = 0.0f;
       
        for (int y = 0; y < 6; y++)
        {
            valor_sensores[0] += horarios[x][y];
           
            if (horarios[x][y] > horarios[indices[0]][indices[1]])
            {
                indices[0] = x;
                indices[1] = y;
            }
        }
       
        valor_sensores[0] /= 6;
       
        if (valor_sensores[0] > valor_sensores[1])
        {
            valor_sensores[1] = valor_sensores[0];
            indices[2] = x;
        }
       
        printf("Média do Sensor de Medição %d: %.2f\n",
                (x + 1), valor_sensores[0]);
    }
   
    printf("\n\n*** RELATÓRIO ***\n\n");
    printf("Índice do sensor com maior média: [%d] = Sensor de Medição %d\n",
            indices[2], (indices[2] + 1));
    printf("Índice do horário de maior poluição: [%d] = Horário %d (%02d:00) ",
            indices[1], (indices[1] + 1), (indices[1] + 8));
    printf("do Sensor de Medição: %d\n", (indices[0] + 1));
    printf("horarios[%d][%d] = (%02d:00): %.2f\n",
            indices[0],
            indices[1],
            (indices[1] + 8),
            horarios[indices[0]][indices[1]]
    );
   
    return 0;
}
