/*
 * =====================================================================================
 *
 *       Filename:  game.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/22 11:17:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "game.h"
#include "../tools/tools.h"

// Fill the board of alive cells
void fill_board(int ** board, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col ++)
            board[row][col] = 1;
}

// Seed the life in a board (add cells of alive cell)
void seed_life(int cells, int ** board, int rows, int cols)
{
    if (remaining(board, rows, cols) + cells >= rows*cols)
        fill_board(board, rows, cols);
    else
    {
        srand(time(NULL));
        while (cells > 0)
        {
            int rd = rand() % (cols * rows);
            int row = rd / rows;
            int col = rd % cols - 1;
            if (get_cell(row, col, board, rows, cols) == 0)
            {
                cells--;
                set_cell(row, col, 1, board, rows, cols);
            }
        }
    }
}

// Apply rules on every cell and generate the next generation of the board
int ** next_generation(int ** board, int rows, int cols)
{
    int ** new_board = calloc(rows, cols);
    
    for (int row = 0; row < rows; row++)
    {
        new_board[row] = calloc(cols, sizeof(int));
        for (int col = 0; col < cols; col++)
            new_board[row][col] = rule(board[row][col], 
                    count_neighbours(row, col, board, rows, cols));
    }
    free(board);

    return new_board;
}

// Verify whether all cells are dead
int remaining(int ** board, int rows, int cols)
{
    int remain = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            remain += board[i][j];
    return remain;
}
