/**
 * @file HW-5-LCS-RE.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-11-13
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

int lcs(char *str1, char *str2, int m, int n)
{
    if (m == -1 || n == -1)
    {
        return 0;
    }
    if (str1[m] == str2[n])
        return lcs(str1, str2, m - 1, n - 1) + 1;
    else if (str1[m] != str2[n])
    {
        return fmaxl(lcs(str1, str2, m, n - 1), lcs(str1, str2, m - 1, n));
    }
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        char str1[11] = {
            '\0',
        };
        char str2[11] = {
            '\0',
        };

        scanf("%10s %10s", str1, str2);
        int max = 0;
        max = lcs(str1, str2, strlen(str1) - 1, strlen(str2) - 1);
        printf("%d\n", max);
    }
    return 0;
}
