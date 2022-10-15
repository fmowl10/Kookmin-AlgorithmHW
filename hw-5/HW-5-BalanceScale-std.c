/**
 * @file HW-5-BalanceScale-std.c
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

const int weights[] = {1, 2, 5, 10, 20, 50, 100};
#define NUMWEIGHTS 7

void putPebbleOnTheScale(const int *pebbles, const size_t size, int *leftPan, int *rightPan)
{
    *leftPan = pebbles[0];
    *rightPan = pebbles[1];
    for (size_t i = 2; i < size; i++)
    {
        if (*leftPan == *rightPan)
            *leftPan += pebbles[i];
        else if (*leftPan > *rightPan)
            *rightPan += pebbles[i];
        else
            *leftPan += pebbles[i];
    }

    return;
}

int balanceIt(int lightPan, int heavyPan, int count)
{
    if (lightPan == heavyPan)
        return count;
    if (lightPan > heavyPan)
        return -1;

    for (int i = NUMWEIGHTS - 1; i >= 0; i--)
    {
        if (heavyPan - lightPan < weights[i])
            continue;

        int tmp = balanceIt(lightPan + weights[i], heavyPan, count+1);
        if(tmp != -1)
            return tmp;
    }
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        size_t n = 0;
        scanf("%ld", &n);
        int *array = malloc(sizeof(int) * n);
        for (size_t i = 0; i < n; i++)
        {
            scanf("%d", array + i);
        }
        int leftPan = 0;
        int rightPan = 0;
        putPebbleOnTheScale(array, n, &leftPan, &rightPan);
        int countWeights = balanceIt(fminl(rightPan, leftPan), fmaxl(rightPan, leftPan), 0);
        printf("%d\n", countWeights);

        free(array);
    }
    return 0;
}
