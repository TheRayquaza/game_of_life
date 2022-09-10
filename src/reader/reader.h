/*
 * =====================================================================================
 *
 *       Filename:  reader.h
 *
 *    Description:  Read the 2d state of the game of life stored in a
 *    matrix-file
 *
 *        Version:  1.0
 *        Created:  09/10/22 10:19:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Mateo Lelong
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

// READER
// Read the file and return its memory representation of int
int ** read_file(char * filename, int * raw, int * column);

// Convert a character to its digit representation
// Negative number returned if it's not a digit
int convert_chr(char c);

// VERIFICATION
// Verify information on a file : 
// -- the number of character by line
// -- the number of line
char ** get_file_info(int * nb_line, int * nb_chr_by_line, FILE * fp);

