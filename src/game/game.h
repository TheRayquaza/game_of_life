/*
 * =====================================================================================
 *
 *       Filename:  game.h
 *
 *    Description: This file contains definition to create generation of the
 *    game of life using the tool already created in tools/tools.h 
 *
 *        Version:  1.0
 *        Created:  09/10/22 11:17:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
// Fill the bord of alive cells
void fill_board(int ** board, int rows, int cols);

// Seed the life in a board (add cells of alive cell)
void seed_life(int cells, int ** board, int rows, int cols);

// Apply rules on every cell and generate the next generation of the board
int ** next_generation(int ** board, int rows, int cols);

// Verify whether all cells are dead
int remaining(int ** board, int rows, int cols);
