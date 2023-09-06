#include "test.h"
#include "sort.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>










// Fills array with random values.
void randomFill(int* arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        arr[i] = rand();
    }
}


// Fills array with values [0, n-1] in a random order
void randomOrder(int* arr, int n)
{
    int used[n];
    int i = 0;
    int val;

    zeroFill(used, n);

    while(i < n)
    {
        val = rand()%n;
        if(used[val] == 0)
        {
            arr[i] = val;
            used[val] += 1;
            i += 1;
        }
    }
}


void randomOrderTest(void (*sortFunc)(int*, int), int n)
{
    int arr[n];
    int sorted[n];
    sortedFill(sorted, n);
    randomOrder(arr, n);
    sortFunc(arr, n);
    verifySort(arr, sorted, n);
}


// runs all tests
void runTests(void (*sortFunc)(int*, int), int numTests)
{
    {   // array of size 1
        int arr[1] = {0};
        testSort(sortFunc, arr, 1);
    }

    {   // small sorted array
        int arr[2] = {1, 2};
        testSort(insertionSort, arr, 2);
    }

    {   // small unsorted array, negative values
        int arr[3] = {-1, -2, -3};
        testSort(insertionSort, arr, 3);
    }


    {   // small unsorted array
        int arr[3] = {3, 2, 1};
        testSort(insertionSort, arr, 3);
    }

    {   // random value tests
        printf("Running %d random value tests\n", numTests);
        int count = 0;
        while(count < numTests)
        {
            int n = rand() % MAX_ARRAY_LENGTH;
            int arr[n];
            randomFill(arr, n);
            testSort(insertionSort, arr, n);
            ++count;
        }
    }

    {   // random ordering tests, sorted array should be in consecutive order
        printf("Running %d random order tests\n", numTests);
        for(int i = 0; i < numTests; ++i)
        {
            int n = rand() % MAX_ARRAY_LENGTH;
            randomOrderTest(insertionSort, n);
        }
    }
}


// Fills arr[0:n-1] with values [0:n-1]
void sortedFill(int* arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
}



//  Asserts that a[i-1] <= a[i] for all array elements.
void testSort(void (*sortFunc)(int*, int), int* arr, int n)
{
    sortFunc(arr, n);
    for(int i = 1; i < n; ++i)
    {
        assert(arr[i] >= arr[i-1]);
    }
}


// Asserts that arr[i] equals solution[i] for all i = 0:n-1
void verifySort(const int* arr, const int* solution, int n)
{
    for(int i = 0; i < n; ++i)
    {
        assert(arr[i] == solution[i]);
    }
}


// Sets array elements 0:n-1 to zero value
void zeroFill(int* arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        arr[i] = 0;
    }
}
