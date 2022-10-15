/**
 * @file HW-4-MergeSort.c
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

#define MAX_SIZE 100
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

void mergeSort(int v[], int low, int high)
{
    int mid;
    if (low == high)
        return; /* base case */
    mid = (low + high) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        count = 0;
        int n = 0;
        scanf("%d", &n);
        int *array = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            scanf("%d", &temp);
            array[i] = temp;
        }
        mergeSort(array, 0, n - 1);
        printf("%d\n", count);
        free(array);
    }
    return 0;
}
