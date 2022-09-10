/*
 * =====================================================================================
 *
 *       Filename:  reader.c
 *
 *    Description: Reader helps the game of life game to load a file and play
 *    the game with the generated board (from the file) 
 *
 *        Version:  1.0
 *        Created:  09/10/22 10:30:52
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
#include <string.h>
#include <sys/types.h>

#include "reader.h"


// READER
// Read the file and return its memory representation of int
int ** read_file(char * filename, int * rows, int * cols)
{
    FILE * fp = fopen(filename, "r");

    if (fp == NULL)
        return NULL;

    char ** content = get_file_info(rows, cols, fp);

    if (content == NULL)
        return NULL;

    int ** board = calloc((*rows), (*cols));
    for (int i = 0; i < *rows; i++)
    {
        board[i] = calloc((*cols), sizeof(int));
        for (int j = 0; j < *cols; j++)
            board[i][j] = convert_chr(content[i][j]);
    }

    fclose(fp);
    return board;
}

// Convert a character to its digit representation
// Negative number returned if it's not a digit
int convert_chr(char c)
{
    if (c != '0' && c != '1')
        return -1;
    else
        return (int) (c-'0');
}


// VERIFICATION
// Verify information on a file and return if the format is valid :
// -- the number of character by line
// -- the number of line
char ** get_file_info(int * nb_line, int * nb_chr_by_line, FILE * fp)
{
    char ** content = 0;
    char * buffer;
    int i = 0;
    int j = 0;
    char current_chr = '\0';

    *nb_line = 0;
    *nb_chr_by_line = -1;

    while (current_chr != EOF)
    {
        buffer = malloc(0);
        j = 0;
        current_chr = fgetc(fp);
        while (current_chr != EOF && current_chr != '\n')
        {
            buffer = realloc(buffer, sizeof(char) * (j+1));
            buffer[j] = current_chr;
            j++;

            current_chr = fgetc(fp);
        }
        if (*nb_chr_by_line == -1)
            *nb_chr_by_line = j;
        if (j != 0 && current_chr != EOF && j != *nb_chr_by_line)
            return NULL;

        content = (char **) realloc(content, (i+1) * sizeof(*content));
        if (content == NULL)
            return NULL;

        content[i] = (char *) malloc(j * sizeof(char));
        if (content[i] == NULL)
            return NULL;

        for (int k = 0; k < j; k++)
            content[i][k] = buffer[k];

        i++;
        free(buffer);
    }
    *nb_line = i-1;
    return content;
}
