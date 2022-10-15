/**
 * @file factorial.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief factorial
 * @version 0.1
 * @date 2022-09-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cutter(int facto)
{
    while (facto % 10 == 0)
    {
        facto /= 10;
    }
    return facto % 10000;
}

int factorial(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    else
    {
        return cutter(factorial(n - 1) * n);
    }
}

int main(int argc, char **argv)
{
    int T = 0;
    int TN = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &TN);
        TN = factorial(TN);
        printf("%d\n", TN % 1000);
    }
    return EXIT_SUCCESS;
}