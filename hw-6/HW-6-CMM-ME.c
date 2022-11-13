/**
 * @file HW-6-CMM-ME.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-11-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[101][101];
int m(int i, int j, int *ds)
{
    if (i == j)
        return 0;

    if (table[i][j] != 0)
    {
        return table[i][j];
    }

    table[i][j] = INT_MAX;

    for (int k = i; k < j; k++)
    {
        table[i][j] = fmin(table[i][j],
                           m(i, k, ds) + m(k + 1, j, ds) + ds[i - 1] * ds[k] * ds[j]);
    }
    return table[i][j];
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        int N = 0;
        scanf("%d", &N);
        N++;
        int ds[N];
        for (size_t i = 0; i < N; i++)
        {
            scanf("%d", ds + i);
        }
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                table[i][j] = 0;
            }
        }

        int out = m(1, N - 1, ds);
        printf("%d\n", out);
    }
    return 0;
}
