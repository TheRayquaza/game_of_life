/*
 * =====================================================================================
 *
 *       Filename:  tools.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/22 10:59:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  colOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>


// Return a board rows row cols of val values
int ** init_board(int rows, int cols, int val)
{
    int ** board = calloc(rows, sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        int * sub_board = calloc(cols, sizeof(int));
        for (int j = 0; j < cols; j++)
            sub_board[j] = val;
        board[i] = sub_board;
    }
    return board;
}

// Get a value of a cell
// If the cell is out of bound, then return it as a dead cell
int get_cell(int row, int col, int ** board, int rows, int cols)
{
    if (row >= rows || col >= cols || row < 0 || col < 0)
        return 0;
    else
        return board[row][col];
}

// Set a value of a cell
// If the cell is out of bound, nothing is done
void set_cell(int row, int col, int val, int ** board, int rows, int cols)
{
    if (row < cols && col < rows)
        board[row][col] = val;
}

// Apply axiom based on the type of cell and its number of neighbours
int rule(int val, int neighbours)
{
    if (val == 1 && neighbours != 2 && neighbours != 3)
        return 0;
    else if (val == 0 && neighbours == 3)
        return 1;
    else 
        return val;
}

// Count the number of neighbours in a board
int count_neighbours(int row, int col, int ** board, int rows, int cols)
{
    return get_cell(row-1,col-1, board, rows, cols) +
        get_cell(row-1, col, board, rows, cols) +
        get_cell(row-1, col+1, board, rows, cols) +
        get_cell(row, col-1, board, rows, cols) +
        get_cell(row, col+1, board, rows, cols) +
        get_cell(row+1, col-1, board, rows, cols) +
        get_cell(row+1, col, board, rows, cols) +
        get_cell(row+1, col+1, board, rows, cols);
}
