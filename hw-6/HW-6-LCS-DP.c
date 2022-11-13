/**
 * @file HW-6-LCS-DP.c
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

#define MAXSIZE 101
int L[MAXSIZE][MAXSIZE] = {
    0,
};
int S[MAXSIZE][MAXSIZE] = {
    0,
};

int lengthLCS(char *str1, char *str2, int m, int n)
{
    for (int i = 0; i <= m; i++)
        L[i][0] = 0;
    for (int i = 0; i <= n; i++)
        L[0][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                S[i][j] = 0;
            }
            else
            {
                L[i][j] = fmaxl(L[i][j - 1], L[i - 1][j]);
                if (L[i][j] == L[i][j - 1])
                    S[i][j] = 1;
                else
                    S[i][j] = 2;
            }
        }
    }
    return L[m][n];
}

void printLCS(char *str1, char *str2, int m, int n)
{
    if (m == 0 || n == 0)
        return;

    if (S[m][n] == 0)
    {
        printLCS(str1, str2, m - 1, n - 1);
        printf("%c", str1[m - 1]);
    }
    else if (S[m][n] == 1)
        printLCS(str1, str2, m, n - 1);
    else if (S[m][n] == 2)
        printLCS(str1, str2, m - 1, n);
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        char str1[MAXSIZE] = {
            0,
        };
        char str2[MAXSIZE] = {
            0,
        };
        memset(L, 0, sizeof(int) * MAXSIZE);
        memset(S, 0, sizeof(int) * MAXSIZE);
        scanf("%100s %100s", str1, str2);
        int max = lengthLCS(str1, str2, strlen(str1), strlen(str2));
        printf("%d ", max);
        printLCS(str1, str2, strlen(str1), strlen(str2));
        printf("\n");
    }
    return 0;
}
