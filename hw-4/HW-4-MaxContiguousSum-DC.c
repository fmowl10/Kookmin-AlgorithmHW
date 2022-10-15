/**
 * @file HW-4-MaxContiguousSum-DC.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int midSum(int *array, int start, int end)
{
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;
    int mid = (start + end) / 2;
    for (int i = mid; i >= start; --i)
    {
        sum += array[i];
        leftSum = fmaxl(leftSum, sum);
    }

    sum = 0;
    for (int j = mid + 1; j <= end; ++j)
    {
        sum += array[j];
        rightSum = fmaxl(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxContiguousSumDC(int *array, int start, int end)
{
    if (start == end)
        return array[start];

    int mid = (start + end) / 2;

    int maxLeft = maxContiguousSumDC(array, start, mid);
    int maxRight = maxContiguousSumDC(array, mid + 1, end);
    int cross = midSum(array, start, end);

    return (int)fmaxl(fmaxl(maxLeft, maxRight), cross);
}

int main(int argc, char const *argv[])
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
        int sum = maxContiguousSumDC(array, 0, n - 1);
        printf("%d\n",
               sum >= 0 ? sum : 0);
        free(array);
    }
    return EXIT_SUCCESS;
    return 0;
}
