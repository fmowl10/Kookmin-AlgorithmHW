/**
 * @file HW-5-Quicksort-Hoare-std.c
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
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swapInt(a, b) \
    swap((char *)(a), (char *)(b), sizeof(int))

void swap(char *a, char *b, size_t size)
{
    while (size--)
    {
        char temp = *a;
        *a = *b;
        *b = temp;

        a++;
        b++;
    }
}

int HoareSwapCount = 0;
int HoareCompareCount = 0;
int LomutoSwapCount = 0;
int LomutoCompareCount = 0;

void clearCounts()
{
    HoareSwapCount = 0;
    HoareCompareCount = 0;
    LomutoSwapCount = 0;
    LomutoCompareCount = 0;
}

int partition_Hoare(int *array, int low, int high)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
            HoareCompareCount++;
        } while (array[i] < pivot);
        do
        {
            j--;
            HoareCompareCount++;
        } while (array[j] > pivot);
        if (i < j)
        {
            HoareSwapCount++;
            swapInt(array + i, array + j);
        }
        else
        {
            return j;
        }
    }
}

int partition_Lomuto(int *array, int low, int high)
{
    int pivot = array[low];
    int j = low;
    for (int i = low + 1; i <= high; i++)
    {
        LomutoCompareCount++;
        if (array[i] < pivot)
        {
            j++;

            LomutoSwapCount++;
            swapInt(array + i, array + j);
        }
    }
    int pivotPos = j;
    LomutoSwapCount++;
    swapInt(array + pivotPos, array + low);
    return pivotPos;
}

void quicksort(int *array, int low, int high, bool isHoare)
{
    if (low >= high)
        return;
    int p = 0;
    if (isHoare)
        p = partition_Hoare(array, low, high);
    else
        p = partition_Lomuto(array, low, high);

    if (isHoare)
    {
        quicksort(array, low, p, isHoare);
        quicksort(array, p + 1, high, isHoare);
    }
    else
    {
        quicksort(array, low, p - 1, isHoare);
        quicksort(array, p + 1, high, isHoare);
    }
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n = 0;
        int *array1 = NULL;
        int *array2 = NULL;

        // INIT start
        scanf("%d", &n);
        array1 = (int *)malloc(sizeof(int) * n);
        array2 = (int *)malloc(sizeof(int) * n);

        for (size_t i = 0; i < n; i++)
        {
            scanf("%d", array1 + i);
            array2[i] = array1[i];
        }
        clearCounts();
        // INIT end

        // hoare partition
        quicksort(array1, 0, n - 1, true);

        // Lomuto partition
        quicksort(array2, 0, n - 1, false);

        printf("%d %d %d %d\n",
               HoareSwapCount, LomutoSwapCount,
               HoareCompareCount, LomutoCompareCount);

        free(array1);
        free(array2);
    }
    return 0;
}
