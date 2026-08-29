#include <stdio.h>

int main()
{
    float horarios[5][6] = {{0.0f}};
    float media_por_ponto = 0.0f;
    float maior_media_por_ponto = 0.0f;
    float maior_pico_poluicao = 0.0f;
    int indices[3] = {0};
   
    for (int x = 0; x < 5; x++)
    {
        printf("Sensor de medição: %d\n", (x + 1));
       
        for (int y = 0; y < 6; y++)
        {
            printf("\tHorário %d (%02d:00): ", (y + 1), (y + 8));
            scanf("%f", &horarios[x][y]);
        }
    }
   
    printf("\n");
   
    for (int x = 0; x < 5; x++)
    {
        media_por_ponto = 0.0f;
       
        for (int y = 0; y < 6; y++)
        {
            media_por_ponto += horarios[x][y];
           
            if (horarios[x][y] > maior_pico_poluicao)
            {
                maior_pico_poluicao = horarios[x][y];
                indices[0] = x;
                indices[1] = y;
            }
        }
       
        media_por_ponto /= 6;
       
        if (media_por_ponto > maior_media_por_ponto)
        {
            maior_media_por_ponto = media_por_ponto;
            indices[2] = x;
        }
       
        printf("Média do Sensor de Medição %d: %.2f\n",
                (x + 1), media_por_ponto);
    }
   
    printf("\n\n*** RELATÓRIO ***\n\n");
    printf("Índice do sensor com maior media: [%d] = Sensor de Medição %d\n",
            indices[2], (indices[2] + 1));
    printf("Índice do horario de maior poluicao: [%d]\n", indices[1]);
    printf("Maior pico de poluição: horarios[%d][%d] (%02d:00): %.2f\n",
            indices[0], indices[1],
            (indices[1] + 8),
            horarios[indices[0]][indices[1]]
    );
   
    return 0;
}
