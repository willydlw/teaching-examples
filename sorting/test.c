#include "test.h"
#include "sort.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


void randomFill(int* arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        arr[i] = rand();
    }
}

void testSort(void (*sortFunc)(int*, int), int* arr, int n)
{
    sortFunc(arr, n);
    for(int i = 1; i < n; ++i)
    {
        assert(arr[i] >= arr[i-1]);
    }
}

void runTests(int numTests)
{
    {
        int arr[1] = {0};
        testSort(insertionSort, arr, 1);
    }

    {
        int arr[2] = {1, 2};
        testSort(insertionSort, arr, 2);
    }

    {
        int arr[3] = {-1, -2, -3};
        testSort(insertionSort, arr, 3);
    }


    {
        int arr[3] = {3, 2, 1};
        testSort(insertionSort, arr, 3);
    }

    {
        int count = 0;
        while(count < numTests)
        {
            printf("random test %3d\n", count);
            int n = rand() % MAX_ARRAY_LENGTH;
            int arr[n];
            randomFill(arr, n);
            testSort(insertionSort, arr, n);
            ++count;
        }
    }
}