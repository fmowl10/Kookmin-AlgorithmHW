/**
 * @file HW-7-NQueen.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-11-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int n;
// n x n 보드판의 크기 n 
int *col;
int printed = 0;
void printQueens()
{
    if (printed)
        return;
    for (int i = 1; i <= n; i++)
        printf("%d ", col[i]);
    printf("\n");
}

int promising(int i)
{
    int k = 1;
    while (k < i)
    {
        if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k))
            return 0;
        k++;
    }
    return 1;
}

void queens(int i)
{
    int j;
    if (printed)
        return;
    if (promising(i))
    {
        if (i == n)
        {
            printQueens();
            printed = 1;
            return;
        }
        else
        {
            for (j = 1; j <= n; j++)
            {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }
}
int main()
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        col = (int *)malloc(sizeof(int) * (n + 1));
        printed = 0;
        queens(0);
    }
    return 0;
}
