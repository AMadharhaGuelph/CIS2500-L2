#include "header.h"

FILE *openFileForReading(char *fileName) {
    // Declare and Intialize fptr, open it for reading
    FILE *fptr = NULL;
    fptr = fopen(fileName, "r");

    // If NULL then return NULL and print error message
    if(fptr == NULL) {
        printf("Error: fopen failed in openFileForReading. Exiting.\n");
        exit(1);
    }

    // Return fptr
    return fptr;
}

int getWordCount(char *str) {
    // Decalre and Intialize variables
    char *token;
    int wordCount = 0;

    token = strtok(str, " ");
    // Iterate through tokens
    while(token != NULL) {
        // Count amount of words
        wordCount++;
        token = strtok(NULL, " ");
    }

    // Return the word count
    return wordCount;
}

int getLineCount(FILE *fptr) {
    // Declare and initalize lineCount
    int lineCount = 0;

    // Start at beginning of file
    rewind(fptr);

    // Iterate through characters in the file 
    for (char c = getc(fptr); c != EOF; c = getc(fptr)) {
        // If current character is '\n' or '.' increment lineCount
        if(c == '\n' || c == '.') {
            lineCount++;
        }
    }

    // Return lineCount
    return lineCount;
}

int getWordsPerLine(FILE *fptr, int **wordsPerLine) {
    // Declare and Initialize variables
    char *line = malloc(sizeof(char) * MAX_LINE + 1);
    int i = 0;
    int *temp;

    // Start at the beginning of the file
    rewind(fptr);

    // Iterate through the lines of the file while storing the line
    while(fgets(line, MAX_LINE, fptr)) {
        // Remove \n character
        line[strlen(line) - 1] = '\0';
        // if wordsPerLine is NULL, allocate one integer space and store the current word count
        if(*wordsPerLine == NULL) {
            *wordsPerLine = malloc(sizeof(int));
            (*wordsPerLine)[0] = getWordCount(line);
        }
        // otherwise allocate an additional integer space and store current word count
        else {
            temp = realloc(*wordsPerLine, (i + 1) * sizeof(int));
            *wordsPerLine = temp;
            (*wordsPerLine)[i] = getWordCount(line);
        }
        // increment i
        i++; 
    }

    // Return i (the size/amount of elements of wordsPerLine)
    return i;
}