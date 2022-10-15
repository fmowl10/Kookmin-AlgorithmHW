/**
 * @file stringPermutation.c
 * @author Jinsoek KIm (jinseok1001@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-09-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int w(const char *str, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = pow(-1, i) * (str[i] - 'a');
        sum += temp;
    }
    return sum;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permuteString(char *str, const int stringLen, int begin, int end, int *evenCount)
{
    int range = end - begin;

    if (range == 0)
    {
        if (w(str, stringLen) > 0)
            (*evenCount)++;
        return;
    }
    else
    {
        for (int i = 0; i < range; i++)
        {
            swap(str + begin, str + begin + i);
            permuteString(str, stringLen, begin + 1, end, evenCount);
            swap(str + begin, str + begin + i);
        }
    }
}

int main(int argc, char **argv)
{
    int T = 0;
    char TN[10] = {'\0'};
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int eventCount = 0;
        scanf("%10s", TN);
        permuteString(TN, strlen(TN), 0, strlen(TN), &eventCount);
        printf("%d\n", eventCount);
    }
}