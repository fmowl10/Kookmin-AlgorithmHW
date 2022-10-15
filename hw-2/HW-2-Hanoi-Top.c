/**
 * @file HW-2-Hanio-Top.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief tracking number 3 stick
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[9] = {
    0,
};
int top = -1;

int hanoi(int n, int from, int via, int to)
{
    if (n > 0)
    {
        hanoi(n - 1, from, to, via);
        if (to == 3)
        {
            top++;
            stack[top] = n;
            printf("%d ", n);
        }
        else if (from == 3)
        {
            top--;
            if (top == -1)
                printf("0 ");
            else
                printf("%d ", stack[top]);
        }
        hanoi(n - 1, via, from, to);
    }
}

int main(int argc, char **argv)
{
    int T = 0;
    int TN = 0;
    char temp = 0;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &TN);
        top = -1;
        hanoi(TN, 1, 2, 3);
        printf("\n");
    }
    return EXIT_SUCCESS;
}