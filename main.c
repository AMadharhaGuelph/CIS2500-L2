#include "header.h"

int main(int argc, char * argv[]) {
    // Decalre and Intialize Variables
    FILE *fptr = NULL;
    int lineCount = 0;
    int totalWordCount = 0;
    int *wordsPerLine = NULL;
    int size = 0;

    // Open fptr for reading
    fptr = openFileForReading(argv[1]);
    // Obtain line count
    lineCount = getLineCount(fptr);
    // Obtain the words per line and the amount of elements (size)
    size = getWordsPerLine(fptr, &wordsPerLine);
    // Calculate total words in the file
    for(int j = 0; j < size; j++) {
        totalWordCount += wordsPerLine[j];
    }

    // Output amount of words and amount of lines
    if(lineCount == 1 && totalWordCount == 1) {
        printf("%d word on %d line", totalWordCount, lineCount);
    }
    else if(lineCount == 1 && totalWordCount > 1) {
        printf("%d words on %d line", totalWordCount, lineCount);
    }
    else if(lineCount > 1 && totalWordCount == 1) {
        printf("%d word on %d lines", totalWordCount, lineCount);
    }
    else {
        printf("%d words on %d lines", totalWordCount, lineCount);
    }

    printf("\n");

    // Output amount of words per line
    for(int i = 0; i < size; i++) {
        printf("%d ", wordsPerLine[i]);
    }
    printf("\n");

    // Free memory and close file
    free(wordsPerLine);
    fclose(fptr);

    return 0;
}