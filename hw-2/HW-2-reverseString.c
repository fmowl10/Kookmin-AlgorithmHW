/**
 * @file reverseString.c
 * @author Jinseok Kim (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void _reverseString(char *first, char *last)
{
    if (last < first)
    {
        return;
    }
    else
    {
        swap(first, last);
        return _reverseString(first + 1, last - 1);
    }
}

void reverseString(char *str)
{
    _reverseString(str, str + strlen(str) - 1);
}

int main(int argc, char **argv)
{
    int T = 0;
    char TN[101] = {'\0'};
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%100s", TN);
        reverseString(TN);
        printf("%s\n", TN);
        memset(TN, '\0', sizeof(TN));
    }
}
