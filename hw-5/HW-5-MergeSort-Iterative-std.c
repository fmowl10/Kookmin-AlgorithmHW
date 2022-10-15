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

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
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
        free(array);
    }
    return 0;
}
