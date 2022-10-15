/**
 * @file HW-3-fastFibo.c
 * @author  JInsoek Kim
 * @brief
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIVISOR 1000

const long fibo_1[2][2] = {{1, 1}, {1, 0}};

void fibonacci(int n, long matrix[2][2]);

// all matrix is 2x2

void multiplyMatrix(long multiplicant[2][2], const long multiplier[2][2]);

void powMatrix(long matrix[2][2]);

int main(int argc, char **argv)
{
    int t = 0;
    int t_n = 0;
    long matrix[2][2] = {
        0,
    };
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &t_n);
        if (t_n == 0)
        {
            printf("0\n");
            continue;
        }
        fibonacci(t_n, matrix);
        printf("%ld\n", (matrix[0][1]) % 1000);
        memset((void *)matrix, 0, sizeof(long) * 4);
    }
    return EXIT_SUCCESS;
}

void fibonacci(int n, long matrix[2][2])
{
    if (n == 1)
    {
        matrix[0][0] = 1;
        matrix[0][1] = 1;
        matrix[1][0] = 1;
        matrix[1][1] = 0;
        return;
    }
    else if (n % 2 == 1)
    {
        fibonacci((n - 1) / 2, matrix);
        powMatrix(matrix);
        multiplyMatrix(matrix, fibo_1);
        return;
    }
    else
    {
        fibonacci(n / 2, matrix);
        powMatrix(matrix);
    }
}

void multiplyMatrix(long multiplicant[2][2], const long multiplier[2][2])
{
    long matrix[2][2] = {
        0,
    };

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix[i][j] = (multiplicant[i][0] * multiplier[0][j] +
                            multiplicant[i][1] * multiplier[1][j]) %
                           10000;
        }
    }
    memcpy(multiplicant, matrix, sizeof(long) * 4);
}

void powMatrix(long matrix[2][2])
{
    long cpymatrix[2][2] = {
        0,
    };
    memcpy(cpymatrix, matrix, sizeof(long) * 4);
    multiplyMatrix(matrix, cpymatrix);
}