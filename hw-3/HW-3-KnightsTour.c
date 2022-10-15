/**
 * @file HW-3-KnightsTour.c
 * @author Jinsoek Kim
 * @brief KnightTour
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0
typedef struct Point
{
    int x, y;
} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];

int knightTour(int m, int n, point pos, int counter)
{
    if (counter == m * n)
        return 1;

    point next = {0, 0};

    for (int i = 0; i < 8; i++)
    {
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;
        if (next.x > 0 && next.x <= n &&
            next.y > 0 && next.y <= m &&
            board[next.y][next.x] != MARK)
        {
            board[next.y][next.x] = MARK;
            path[next.y][next.x] = counter + 1;
            if (knightTour(m, n, next, counter + 1))
                return 1;
            board[next.y][next.x] = UNMARK;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    int T = 0;
    scanf("%d", &T);
    while (T--)
    {
        int m, n, s, t;
        point start;
        memset(board, UNMARK, sizeof(board));
        scanf("%d %d %d %d", &m, &n, &s, &t);
        start.x = s;
        start.y = t;
        board[t][s] = MARK;
        path[t][s] = 1;
        if (knightTour(m, n, start, 1))
        {
            printf("1\n");
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    printf("%d ", path[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}