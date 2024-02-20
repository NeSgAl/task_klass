#include <stdio.h>
#include <stdlib.h>

#include "../inc/functions.h"


int main()
{
    // ========EVENT==============
    printf("Выберите действие:\n");
    printf("1. a*b\n");
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

    float** mas;
    int m, n;

    // processing
    switch (enter)
    {
        case READ:
            mas = read_matrix(&m, &n);
        break;

        case ENTER:
            mas = enter_matrix(&m, &n);
        break;

        case GENERATE:
            mas = generate_matrix(&m, &n);
        break;
    
        default:
            printf("Неизвестный параметр для ввода матрицы");
            exit(ENTER_ERROR);
        break;
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
            console_out(mas, m, n);
        break;
    
        default:
        break;
    }
    printf("\n");


    // free mas
    for (int i = 0; i < m; i++)
    {
        free(mas[i]);
    }
    free(mas);
    

    exit(SUCCESS);    
}