/**
 * @file HW-8-KMP-DFA.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-11-30
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

#define R 3
#define MAX_SIZE 1000

int DFA[R][MAX_SIZE];

int countNotZeroEdge(int n)
{
    int cnt = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j <= n; j++)
            cnt += DFA[i][j] ? 1 : 0;
    }
    return cnt;
}

void contructDFA(char *pattern)
{
    memset(DFA, 0, sizeof DFA);
    int pathLength = strlen(pattern);
    DFA[pattern[0] - 'A'][0] = 1;
    int X = 0, j = 1;

    for (; j < pathLength; j++)
    {
        for (int c = 0; c < R; c++)
            DFA[c][j] = DFA[c][X];

        DFA[pattern[j] - 'A'][j] = j + 1;
        X = DFA[pattern[j] - 'A'][X];
    }
    for (int i = 0; i < R; i++)
    {
        DFA[i][j] = DFA[i][X];
    }
}

int KMP(char *text, int patternLength)
{
    int j = 0, ans = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        j = DFA[text[i] - 'A'][j];
        if (j == patternLength)
            ans++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        char pattern[1001], text[1001];
        scanf("%s %s", pattern, text);
        contructDFA(pattern);
        int cnt = countNotZeroEdge(strlen(pattern));
        int ans = KMP(text, strlen(pattern));
        printf("%d %d\n", cnt, ans);
    }
    return 0;
}
