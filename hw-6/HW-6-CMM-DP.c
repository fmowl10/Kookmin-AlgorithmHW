/**
 * @file HW-6-CMM-DP.c
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

int minmult(int n, int *ds)
{
    int m[101][101];
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (int d = 1; d <= n - 1; d++)
        for (int i = 1; i <= n - d; i++)
        {
            int j = i + d;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int count = m[i][k] + m[k + 1][j] + ds[i - 1] * ds[k] * ds[j];
                if (count < m[i][j])
                {
                    table[i][j] = k;
                    m[i][j] = count;
                }
            }
        }
    return m[1][n - 1];
}

void order(int i, int j)
{
    if (i == j)
        printf("M%d", i);
    else
    {
        int k = table[i][j];
        printf("(");
        order(i, k);
        order(k + 1, j);
        printf(")");
    }
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

        int out = minmult(N, ds);
        order(1, N - 1);
        printf("\n");
        printf("%d\n", out);
    }
    return 0;
}
