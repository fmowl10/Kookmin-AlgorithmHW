/**
 * @file HW-7-Sudoku4x4.c
 * @author Jinseok Kim (jinseok1001@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-11-15
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

#define SIZE 4

struct cell
{
    int col, row;
};

int board[SIZE][SIZE];
struct cell emptyCells[16];
int cnt = 0;

void printBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int squarePromising(int col, int row, int n)
{
    int colStart = (col / 2) * 2;
    int rowStart = (row / 2) * 2;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (board[i + rowStart][j + colStart] == n)
                return 0;
        }
    }
    return 1;
}

int linePromising(int col, int row, int n)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][col] == n)
            return 0;
        if (board[row][i] == n)
            return 0;
    }
    return 1;
}

int isPromising(int col, int row, int n)
{
    if (linePromising(col, row, n) && squarePromising(col, row, n))
        return 1;
    else
        return 0;
}

int solver(int count)
{
    if (cnt == count)
    {
        return 1;
    }

    int col = emptyCells[count].col;
    int row = emptyCells[count].row;

    for (int i = 1; i <= SIZE; i++)
    {
        if (isPromising(col, row, i))
        {
            board[row][col] = i;
            if (solver(count + 1))
                return 1;
            else
                board[row][col] = 0;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    size_t T = 0;
    scanf("%d", &T);
    while (T--)
    {
        cnt = 0;
        for (size_t i = 0; i < SIZE; i++)
        {
            for (size_t j = 0; j < SIZE; j++)
            {
                scanf("%d", &(board[i][j]));
                if (board[i][j] == 0)
                {
                    emptyCells[cnt].col = j;
                    emptyCells[cnt].row = i;
                    cnt++;
                }
            }
        }
        solver(0);
        printBoard();
    }
    return 0;
}
