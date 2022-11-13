/**
 * @file HW-6-LCS-ME.c
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

int table[100][100] = {
    0,
};

int lcs(char *str1, char *str2, int m, int n)
{
    if (m == -1 || n == -1)
    {
        return 0;
    }
    if (table[m][n] != -1)
    {
        return table[m][n];
    }
    if (str1[m] == str2[n])
    {
        table[m][n] = 1 + lcs(str1, str2, m - 1, n - 1);
        return table[m][n];
    }
    else
    {
        table[m][n] = fmaxl(lcs(str1, str2, m, n - 1), lcs(str1, str2, m - 1, n));
        return table[m][n];
    }
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        char str1[101] = {
            '\0',
        };
        char str2[101] = {
            '\0',
        };
        scanf("%100s %100s", str1, str2);
        memset(table, -1, sizeof(table));
        int max = 0;
        max = lcs(str1, str2, strlen(str1) - 1, strlen(str2) - 1);
        printf("%d\n", max);
    }
    return 0;
}
