/**
 * @file HW-3-euclid.c
 * @author Jinseok Kim
 * @brief
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(int argc, char **argv)
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
}