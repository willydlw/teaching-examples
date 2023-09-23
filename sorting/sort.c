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

void merge(int* arr, int p, int q, int r)
{
    int i, j, k;

    int nL = p - q + 1;     // length A[p:q]     
    int nR = r - q;         // length A[q+1:r]

    int left[nL];
    int right[nR];
    for(i = 0; i < nL; ++i){
        left[i] = arr[p + i];
    }

    for(j = 0; j < nR; ++j){
        right[j] = arr[q + 1 + j];
    }

    i = 0;
    j = 0;
    k = 0;
    while(i < nL && j < nR){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i += 1;
        }
        else{
            arr[k] = right[j];
            j += 1;
        }
        k += 1;
    }

    // above loop stopped when either all the elements of 
    // left or all the elements of right had been merged
    // merge the remaining elements
    while(i < nL){
        arr[k] = left[i];
        i += 1;
        k += 1;
    }

    while(j < nR){
        arr[k] = right[j];
        j += 1;
        k += 1;
    }
}


void mergeSort(int* arr, int p, int r)
{
    // base case - zero or one element
    if(p >= r){
        return;
    }

    // midpoint of A[p:r]
    int q = (p+r) / 2;

    mergeSort(arr, p, q);           // recursively sort A[p:q]
    mergeSort(arr, q+1, r);         // recursively sort A[q+1:r]

    // merge A[p:q] and A[q+1:r] into A[p:r]
    merge(arr, p, q, r);
    
}
