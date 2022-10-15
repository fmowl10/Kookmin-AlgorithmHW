/**
 * @file HW-4-MaxContiguousSum.c
 * @author Jinsoek Kim (20181600)
 * @brief max contiguous subsquence sum
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int maxContiguousSum(int *s, int n, int *start, int *end)
{
    int maxSum = 0, thisSum = 0;

    *start = *end = -1;

    int i = 0;
    int j = 0;

    for (; j < n; j++)
    {
        thisSum += s[j];

        if (thisSum > maxSum)
        {
            maxSum = thisSum;
            *start = i;
            *end = j;
        }
        else if (thisSum <= 0)
        {
            i = j + 1;
            thisSum = 0;
        }
    }
    return maxSum;
}

int main(int argc, char **argv)
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n = 0;
        scanf("%d", &n);
        int *array = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            scanf("%d", &temp);
            array[i] = temp;
        }
        int start = 0;
        int end = 0;
        int sum = maxContiguousSum(array, n, &start, &end);
        printf("%d %d %d\n",
               sum, start, end);
        free(array);
    }
    return EXIT_SUCCESS;
}