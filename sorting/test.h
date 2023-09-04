#ifndef TEST_H
#define TEST_H

#define MAX_ARRAY_LENGTH 100

/*  Fills array with random values.

    Algorithm:
        i = 0
        while i < n
            a[i] = rand()
            i = i + 1
*/
void randomFill(int* arr, int n);


/*  Fills array with values [0, n-1] in a random order.

    Algorithm:
        set all array values to 0
        count = 0
        while count < n
            index = rand() modulus n
            if(array[index] == 0)
                array[index] = count
                count = count + 1
*/
void randomOrder(int* arr, int n);



void randomTest(int n);


// Runs all tests
void runTests(int numTests);



/*  Fills arr[0:n-1] with values [0:n-1]

    Example:
        arr[0] = 0
        arr[1] = 1
        ...
        arr[n-1] = n-1
*/ 
void sortedFill(int* arr, int n);



/*  Asserts that a[i-1] <= a[i] for all array elements.

    Algorithm:
        i = 1
        while i < n
            assert(a[i-1] <= a[i])
            i = i + 1
*/
void testSort(void (*sortFunc)(int*, int), int* arr, int n);


// Asserts that arr[i] equals solution[i] for all i = 0:n-1
void verifySort(const int* arr, const int* solution, int n);


// Sets array elements 0:n-1 to zero value
void zeroFill(int* arr, int n);

#endif 