#include <iostream>
#include <fstream>
#include "program3functions.h"

using std::cout;
using std::endl;



int main(int argc, char* argv[])
{
    // read in the file
    std::ifstream input_file(argv[1]);

    // getting number of characters in text file
    input_file.seekg(0, input_file.end);
    int length = input_file.tellg();
    input_file.seekg(0, input_file.beg);

    // store file contents in char array
    char* fileContent = new char[length + 1];
    for (int i = 0; i < length; i++)
        input_file >> fileContent[i];
    
    fileContent[length] = '\0';
    
    char* alphabet = new char[27];
    alphabet[26] = '\0';
    for (int i = 0; i < 26; i++)
        alphabet[i] = 'a' + i;

    int* charFrequencies = getCharFrequencies(fileContent, length, alphabet, 26);
    int* indices = getIndices(charFrequencies, 26);
    input_file.close();

    int* charFrequencies_unsorted = copyIntPointer(charFrequencies, 26);
    insertionSort(charFrequencies, indices, 26);
    printStatistics(alphabet, charFrequencies, indices, 26);
    cout << endl;
    printChart(charFrequencies_unsorted, alphabet, 26, charFrequencies[0]);

    delete [] fileContent; fileContent = nullptr;
    delete [] alphabet; alphabet = nullptr;
    delete [] charFrequencies; charFrequencies = nullptr;
    delete [] indices; indices = nullptr;
    delete [] charFrequencies_unsorted; charFrequencies_unsorted = nullptr;
    return 0;
}