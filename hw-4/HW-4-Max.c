/**
 * @file HW-4-Max.c
 * @author Jinseok Kim
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

int recurMax(int *a, int left, int right)
{
    int half = 0;

    if (left == right)
        return a[left];
    else
    {
        half = (left + right) / 2;
        return (int)fmax(recurMax(a, left, half),
                         recurMax(a, half + 1, right));
    }
}

int main(int argc, char **argv)
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        int len = 0;
        scanf("%d", &len);
        int *array = malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++)
        {
            int temp = 0;
            scanf("%d", &temp);
            array[i] = temp;
        }
        printf("%d\n", recurMax(array, 0, len - 1));
        free(array);
    }
    return EXIT_SUCCESS;
}
