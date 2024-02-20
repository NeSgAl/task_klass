#include "../inc/out.h"

void console_out(float** mas, int m, int n)
{
    printf("%d, %d\n", m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f ", mas[i][j]);
        }
        printf("\n");
    }
}

void file_out(float** mas, int m, int n);