#include <stdio.h>
#include <stdlib.h>

#include "../inc/functions.h"


int main()
{
    // ========EVENT==============
    printf("Выберите действие:\n");
    printf("1. a+b\n");
    printf("2. a^t\n");
    // дореализовать
    printf("> ");

    int event;
    scanf("%d", &event);
    printf("\n");

    // ========ENTER==============
    printf("Выберите вид ввода матрицы:\n");
    printf("1. ручной\n");
    printf("2. из файла\n");
    printf("3. случайные числа\n");
    printf("> ");

    int enter;
    scanf("%d", &enter);

    int matrix_cnt;
    switch (event)
    {
        case MUL:
        case ADD:
            matrix_cnt = 2;
        break;

        case POW:
            matrix_cnt = 1;
        break;
    
        default:
            printf("Неверный тип ввода\n");
            exit(ENTER_ERROR);
        break;
    }

    float*** matrixes = malloc(sizeof(float**) * matrix_cnt);
    int m, n;

    // processing
    for (int i = 0; i < matrix_cnt; i++)
    {    
        switch (enter)
        {
            case READ:
                matrixes[i] = read_matrix(&m, &n);
            break;

            case ENTER:
                matrixes[i] = enter_matrix(&m, &n);
            break;

            case GENERATE:
                matrixes[i] = generate_matrix(&m, &n);
            break;
        
            default:
                printf("Неизвестный параметр для ввода матрицы");
                exit(ENTER_ERROR);
            break;
        }     
    }
    printf("\n");

    // ==========processing========
    // todo

    // ==========OUT==============
    printf("Выберите вид вывода полученной матрицы:\n");
    printf("1. на экран\n");
    printf("2. в файл\n");
    printf("> ");

    int out;
    scanf("%d", &out);

    // processing
    switch(out)
    {
        case CONSOLE:   
            console_out(matrixes[0], m, n);
        break;
    
        default:
            printf("Неверный тип вывода\n");
            exit(ENTER_ERROR);
        break;
    }
    printf("\n");


    // free matrixes
    for (int j = 0; j < matrix_cnt; j++)
    {
        // строчки
        for (int i = 0; i < m; i++)
        {
            free(matrixes[j][i]);
        }
        // матрицы
        free(matrixes[j]);
    }
    // хранилище матриц
    free(matrixes);


    exit(SUCCESS);    
}