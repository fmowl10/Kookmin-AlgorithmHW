/**
 * @file HW-4-BinarySearch.c
 * @author Jinseok Kim
 * @brief
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *array, int target, int start, int end)
{
    if (end < start)
    {
        return -1;
    }
    else
    {
        int mid = (end + start) / 2;
        if (array[mid] == target)
            return mid;
        else if (array[mid] > target)
        {
            return binarySearch(array, target, start, mid - 1);
        }
        else
        {
            return binarySearch(array, target, mid + 1, end);
        }
    }
}

int main(int argc, char **argv)
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n = 0;
        int target = 0;
        scanf("%d %d\n", &n, &target);
        int *array = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            scanf("%d", &temp);
            array[i] = temp;
        }
        int solve = binarySearch(array, target, 0, n - 1);
        printf("%d\n", solve);
        free(array);
    }
}