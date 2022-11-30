/**
 * @file HW-8-KMP-Fail.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-11-28
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

#define SIZE 1000

int *getFail(char *pattern)
{
    int j = 0;
    int m = strlen(pattern);
    int *fail = malloc(sizeof(int) * m);
    memset(fail, 0, sizeof(int) * m);
    for (size_t i = 1; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = fail[j - 1];

        if (pattern[i] == pattern[j])
            fail[i] = ++j;
    }
    return fail;
}

int kmp(char *text, char *pattern)
{
    int j = 0;
    int *fail = getFail(pattern);
    int n = strlen(text);
    int m = strlen(pattern);
    int ans = 0;

    for (size_t i = 0; i < m; i++)
    {
        printf("%d ", fail[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        while (j > 0 && text[i] != pattern[j])
            j = fail[j - 1];
        if (text[i] == pattern[j])
        {
            if (j == m - 1)
            {
                ans++;
                j = fail[j];
            }
            else
                j++;
        }
    }
    free(fail);
    return ans;
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        char pattern[SIZE + 1] = {
            0,
        };
        char text[SIZE + 1] = {
            0,
        };
        scanf("%s %s", pattern, text);

        int ans = 0;
        ans = kmp(text, pattern);
        printf("%d\n", ans);
    }
    return 0;
}
