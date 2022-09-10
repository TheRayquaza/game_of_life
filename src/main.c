/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/22 10:16:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *       Errors :
 *          0 : Nothing
 *          1 : Argument error
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>


#include "reader/reader.h"
#include "tools/tools.h"
#include "game/game.h"
#include "display/display.h"

int main(int argc, char *argv[])
{
    int * const rows = calloc(1, sizeof(int));
    int * const cols = calloc(1, sizeof(int));
    int ** board = NULL;
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 250000000;

    if (argc == 1)
    {
        srand(time(NULL));

        int generation = 0;
        *rows = 10 + (rand() % 100);
        *cols = 10 + (rand() % 100);
        board = init_board(*rows, *cols, 0);
        seed_life(5 + (rand() % (*rows * *cols)), board, *rows, *cols);
        printf("INITIAL GENERATION :\n-------------------\n");
        display_generation(generation, board, *rows, *cols);
        sleep(4);
        while (remaining(board, *rows, *cols))
        {
            system("clear");
            board = next_generation(board, *rows, *cols);
            generation++;
            display_generation(generation, board, *rows, *cols);
            nanosleep(&ts, &ts);
        }

        return 0;
    }
    else if (argc == 2)
    {
        int generation = 0;
        board = read_file(argv[1], rows, cols);
        if (board ==  NULL)
            return 1;

        printf("INITIAL GENERATION :\n-------------------\n");
        display_generation(generation, board, *rows, *cols);
        while (remaining(board, *rows, *cols))
        {
            system("clear");
            board = next_generation(board, *rows, *cols);
            generation++;
            display_generation(generation, board, *rows, *cols);
            nanosleep(&ts, &ts);
        }
        return 0;
    }
    else
    {
        printf("Wrong amount of argument, should be 1");
    }
}
