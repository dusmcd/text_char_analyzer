#ifndef PROGRAM3FUNCTIONS_H
#define PROGRAM3FUNCTIONS_H



// this will be in the same order as the return value from getDistinctChars in order to map characters to their frequencies
int* getCharFrequencies(char* fileContents, int fSize, char* distinctChars, int cSize);


int* getIndices(int* charFrequencies, int size);

void insertionSort(int* charFrequences, int* indices, int size);

void printStatistics(char* distinctChars, int* charFrequences, int* indices, int size);

int* copyIntPointer(int* i_pointer, int size);

void printChart(int* charFrequcencies_unsorted, char* alphabet, int size, int max);

#endif
