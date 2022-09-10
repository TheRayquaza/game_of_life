/*
 * =====================================================================================
 *
 *       Filename:  display.c
 *
 *    Description: This file contains every defintion of the display function
 *    that will the help the user to see what's happening in the board 
 *
 *        Version:  1.0
 *        Created:  09/10/22 11:40:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#include "display.h"

// Display a board and the current generation
void display_generation(int generation, int ** board, int rows, int cols)
{
    printf("Current generation : %d\n\n", generation+1);
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (board[row][col] == 0)
                printf("  ");
            else if (board[row][col] == 1)
                printf("##");
            else
                printf("@@");
        }
        printf("\n");
    }
    printf("\n");
}
