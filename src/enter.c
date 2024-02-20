#include "../inc/enter.h"

float** read_matrix(int* m, int* n)
{
    return 0;
}

float** enter_matrix(int* m, int* n)
{
    printf("Введите m: ");
    scanf("%d", m);
    printf("Введите n: ");
    scanf("%d", n);

    float** mas = malloc(sizeof(float*) * *m);

    for (int i = 0; i < *m; i++)
    {
        mas[i] = malloc(sizeof(float) * *n);
        for(int j = 0; j < *n; j++)
        {
            scanf("%f", &mas[i][j]);            
        }
    }

    return mas;
}

float** generate_matrix(int* m, int* n)
{
    return 0;
}