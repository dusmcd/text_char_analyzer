#include <iostream>

using std::cout;
using std::endl;



char toLower(char ch)
{
    if ((ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a'))
        return  ch < 90 ? ch + ('a' - 'A') : ch;
    return ch;
}


int* getCharFrequencies(char* fileContents, int fSize, char* distinctChars, const int cSize)
{
    
    int* result = new int[cSize];
    for (int i = 0; i < cSize; i++)
    {
        int count = 0;
        for (int j = 0; j < fSize; j++)
        {
            if (distinctChars[i] == toLower(fileContents[j]))
                count++;
        }
        result[i] = count;
    }
    return result;
}



int* getIndices(int* charFrequencies, int size)
{
    int* indices = new int[size];
    for (int i = 0; i < size; i++)
        indices[i] = i;
    
    return indices;
}

void insertionSort(int* charFrequences, int* indices, int size)
{
    int i = 0;
    while (i + 1 < size)
    {
        int j = i + 1;
        while(charFrequences[j - 1] < charFrequences[j] && j > 0)
        {
            // swap
            int temp = charFrequences[j - 1];
            charFrequences[j - 1] = charFrequences[j];
            charFrequences[j] = temp;

            // swap indices
            temp = indices[j - 1];
            indices[j - 1] = indices[j];
            indices[j] = temp;
            j--;
        }
        i++;
    }
}


void printStatistics(char* distinctChars, int* charFrequences, int* indices, int size)
{
    int high = 1;
    int low = 1;
    
    // check how many lowest frequencies
    for (int i = 0; i < size - 1; i++)
    {
        if (charFrequences[i] == charFrequences[i + 1])
        {
            high++;
            continue;
        }
        break;
    }

    // check how many highest frequencies
    for (int i = size - 1; i >= 1; i--)
    {
        if (charFrequences[i] == charFrequences[i - 1])
        {
            low++;
            continue;
        }
        break;
    }
    char s_high;
    if (charFrequences[0] == 1)
        s_high = '\0';
    else
        s_high = 's';
    
    if (high == 1)
        cout << "Highest frequency character (appeared " << charFrequences[0] << " time" << s_high << " in the file): " << distinctChars[indices[0]] << endl;
    else // i.e., high greater than 1
    {
        cout << "Highest frequency characters (appeared " << charFrequences[0] << " time" << s_high << " in the file): ";

        for (int i = 0; i < high; i++)
        {
            if (i == high - 1)
                cout << "and " << distinctChars[indices[i]] << endl;
            else
                high == 2 ? cout << distinctChars[indices[i]] << " " :
                    cout << distinctChars[indices[i]] << ", ";
        }
    }

    if (low == 1)
    {
        cout << "Lowest frequency character (appeared " << charFrequences[size - 1];
        if (charFrequences[size - 1] == 1)
            cout << " time";
        else
            cout << " times";
        cout << " in the file): " << distinctChars[indices[size - 1]] << endl;
    }
    else
    {
        cout << "Lowest frequency characters (appeared " << charFrequences[size - 1];
        if (charFrequences[size - 1] == 1)
            cout << " time";
        else
            cout << " times";
        cout << " in the file): ";

        for (int i = size - low; i < size; i++)
        {
            if (i == size - 1)
            {
                cout << "and ";
                cout << distinctChars[indices[i]] << endl;
            }
            else
            {

                cout << distinctChars[indices[i]];
                cout << ", ";
            }
        }
    }

    cout << endl;
    for (int i = 0; i < size; i++)
        cout << distinctChars[indices[i]] << ": " << charFrequences[i] << endl;
}

int* copyIntPointer(int* i_pointer, int size)
{
    int* copy = new int[size];
    for (int i = 0; i < size; i++)
        copy[i] = i_pointer[i];
    
    return copy;
}

void printChart(int* charFrequcencies_unsorted, char* alphabet, int size, int max)
{
    int rows = max + 1;
    int cols = size + 1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j == 0 && i < rows - 1) // first column and not the last row
                max > 9 && max - i < 10 ? cout << " " << max - i << " " :
                    cout << max - i << " ";
            else if (j == 0 && i == rows - 1) // first column and last row
                max > 9 ? cout << "   " : cout << "  ";
            else if (j != 0 && i == rows - 1) // last row, but not first column
            {
                cout << alphabet[j - 1];
                j == cols - 1 ? cout << "" : cout << " ";
            }
            else if (j != 0 && charFrequcencies_unsorted[j - 1] >= max - i )
            {
                cout << "*";
                j == cols - 1 ? cout << "" : cout << " ";
            }
            else
                j == cols - 1 ? cout << " " : cout << "  ";
        }
        cout << endl;
    }
}