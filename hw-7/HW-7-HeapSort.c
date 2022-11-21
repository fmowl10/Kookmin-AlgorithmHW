/**
 * @file HW-7-HeapSort.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-11-21
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

int cnt = 0;

int fixHeap(int *array, int r, int k, int size)
{
    int vacant = r, largerChild;

    while (vacant <= size / 2)
    {
        if (vacant * 2 + 1 <= size)
        {
            largerChild = array[vacant * 2] > array[vacant * 2 + 1]
                              ? vacant * 2
                              : vacant * 2 + 1;
            cnt += 2;
        }
        else
        {
            largerChild = vacant * 2;
            cnt += 1;
        }
        if (array[largerChild] > k)
        {
            array[vacant] = array[largerChild];
            vacant = largerChild;
        }
        else
        {
            break;
        }
    }
    array[vacant] = k;
}

int heapSort(int *array, int n)
{
    int max;
    for (int i = n / 2; i >= 1; i--)
    {
        fixHeap(array, i, array[i], n);
    }

    for (int heapsize = n; heapsize >= 2; heapsize--)
    {
        max = array[1];
        fixHeap(array, 1, array[heapsize], heapsize - 1);
        array[heapsize] = max;
    }
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        int N = 0;
        scanf("%d", &N);
        int array[N + 1];
        memset(array, 0, sizeof(int) * (N + 1));
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", array + i);
        }
        heapSort(array, N);
        printf("%d\n", cnt);
        cnt = 0;
    }
    return 0;
}
