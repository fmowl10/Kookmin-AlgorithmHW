/**
 * @file HW-5-MergeSort-Iterative-std.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int count = 0;

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[MAX_SIZE];
    for (i = low; i <= high; i++)
        tmp[i] = a[i];
    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        count++;
        if (tmp[i] <= tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }

    while (i <= mid)
        a[k++] = tmp[i++];
    while (j <= high)
        a[k++] = tmp[j++];
}

void mergeSortIterative(int v[], int n)
{
    int size = 1;
    while (size < n)
    {
        for (int i = 0; i < n; i += 2 * size)
        {
            int low = i;
            int mid = low + size - 1;
            int high = fminl(i + 2 * size - 1, n - 1);
            if (mid >= n - 1) // merge할 subarray가 1개일 경우
                break;
            merge(v, low, mid, high);
        }
        size *= 2;
    }
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        count = 0;
        int *array = NULL;
        int n = 0;

        scanf("%d", &n);
        array = malloc(sizeof(int) * n);

        if (array == NULL)
        {
            return EXIT_FAILURE;
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%d", array + i);
        }

        mergeSortIterative(array, n);
        printf("%d\n", count);

        free(array);
    }
    return 0;
}
