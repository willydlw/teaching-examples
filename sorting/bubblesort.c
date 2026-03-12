/*  Bubble Sort Algorithm

    1. Step through the array, one value at a time.
    2. For each value, compare the value with the next value.
    3. If the value is higher, swap the values so that the highest value comes last.
    4. Go through the array as many times as there are values in the array.

    Example - Go Through Array One Time

    Step 1. Start with an unsorted array [7 12, 9, 11, 3]
    Step 2. Look at the first two values. Does the lowest value come first? Yes, so we don't need to swap them.

    [7, 12, 9, 11, 3]


    https://www.w3schools.com/dsa/dsa_algo_bubblesort.php
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


int comp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}


void bubblesort(int* arr, int n)
{
    // Go through the array as many time as there are values in the array
    for(int i = 0; i < n - 1; i++){
        bool swapped = false;

        // Step through the array, one value at at a time, starting with the first index
        for(int j = 0; j < n - i - 1; j++){
            // For each value, compare pairs of adjacent values
            if(arr[j] > arr[j+1]){
                // If the first value is higher than the second value, swap 
                // the values so that the highest value comes last.
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        if(!swapped){
            break;
        }
    }
}

bool compareArrays(int* a, int* b, int n)
{
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            fprintf(stderr, "comparison failed, i: %d, a: %d, b: %d\n", i, a[i], b[i]);
            return false;
        }
    }

    return true;
}

void copyArray(int* destination, int* source, int n)
{
    for(int i = 0; i < n; i++){
        destination[i] = source[i];
    }
}

void printArray(int* arr, int n)
{
    for(int i = 0; i < n; i++){
        if(i % 10 == 0){
            fprintf(stderr, "\n");
        }
        fprintf(stderr, "%8d ", arr[i]);
    }

    fprintf(stderr, "\n");
}


void test(int* unsorted, int* expected, int n)
{
    int sorted[n];
    copyArray(sorted, unsorted, n);
    bubblesort(sorted, n);

    if(!compareArrays(sorted, expected, n)){
        fprintf(stderr, "[ERROR]\nUnsorted\n");
        printArray(unsorted, n);
        fprintf(stderr, "Sorted\n");
        printArray(sorted, n);
        fprintf(stderr, "Expected\n");
        printArray(sorted, n);
    }
    
}

void fillRandom(int* arr, int n)
{
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 1000;
    }
}

void run_tests(int numTests)
{
    {
        int arr[5] = {7, 3, 9, 12, 11};
        int expected[5] = {3, 7, 9, 11, 12};
        test(arr, expected, 5);
    }

    {
        for(int i = 0; i < numTests; i++){
            int n = rand() % 100;
            int arr[n];
            int expected[n];
            fillRandom(arr, n);
            copyArray(expected, arr, n);
            qsort(expected, n, sizeof(expected[0]), comp);
            test(arr, expected, n);
        }
    }
}

int main(void)
{
    srand(time(NULL));
    run_tests(50);
    return 0;
}