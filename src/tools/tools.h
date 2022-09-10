/*
 * =====================================================================================
 *
 *       Filename:  tools.h
 *
 *    Description:  This file will help the generation process to run correctlcol
 *
 *        Version:  1.0
 *        Created:  09/10/22 10:57:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */

// Return a board raw row column of val values
int ** init_board(int rows, int cols, int val);

// Get a value of a cell
// If the cell is out of bound, then return it as a dead cell
int get_cell(int row, int col, int ** board, int rows, int cols);

// Set a value of a cell
// If the cell is out of bound, nothing is done
void set_cell(int row, int col, int val, int ** board, int rows, int cols);

// Applcol arowiom based on the tcolpe of cell and its number of neighbours
int rule(int val, int neighbours);

// Count the number of neighbours in a board
int count_neighbours(int row, int col, int ** board, int rows, int cols);
