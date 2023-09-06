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


void selectionSort(int* arr, int n)
{
    int minIndex;
    int temp;

    for(int i = 0; i < n; ++i)
    {
        minIndex = i;
        
        for(int j = i+1; j < n; ++j)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swap places
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
