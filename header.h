#ifndef HEADER_H
#define HEADER_H

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros
#define MAX_LINE 100

// Function Declarations
FILE *openFileForReading(char *fileName);

int getWordCount(char str[MAX_LINE]);

int getLineCount(FILE *file);

int getWordsPerLine(FILE *fptr, int **wordsPerLine);

#endif