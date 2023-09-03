#include "sort.h"

void insertionSort(int* arr, int n)
{
    int i, j, key;
    for(i = 1; i < n; ++i)
    {
        key = arr[i];
        // find index to insert key
        for(j = i-1; j >= 0 && key < arr[j]; --j)
        {
            // shift values >= key to the right
            arr[j+1] = arr[j];      
        }

        // insert key
        arr[j+1] = key;
    }
}
