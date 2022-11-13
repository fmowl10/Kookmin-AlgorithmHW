/**
 * @file HW-6-CMM-RE.c
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

int m(int i, int j, int *ds)
{
    if (i == j)
        return 0;
    int k = 0;

    int min = INT_MAX;

    int count = 0;

    for (int k = i; k < j; k++)
    {
        count = m(i, k, ds) + m(k + 1, j, ds) + ds[i - 1] * ds[k] * ds[j];
        min = fminl(count, min);
    }
    return min;
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
        int out = m(1, N - 1, ds);
        printf("%d\n", out);
    }
    return 0;
}
