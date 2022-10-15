/**
 * @file HW-3-fastPower.c
 * @author JInsoek Kim
 * @brief fast power
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

int power(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
    {
        int temp = power(x, (n - 1) / 2);
        return (x * temp * temp) % 1000;
    }
    else if (n % 2 == 0)
    {
        int temp = power(x, n / 2);
        return (temp * temp) % 1000;
    }
}

int main(int argc, char **argv)
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n = 0, x = 0;
        scanf("%d %d", &x, &n);
        printf("%d\n", power(x, n) % 1000);
    }
    return 0;
}
