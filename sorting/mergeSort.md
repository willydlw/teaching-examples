# Merge Sort



## Divide and Conquer Method

Many algorithms have a recursive structure. To solve the given problem, they recurse (call themselves) one or more times to solve a sub-problem. Recursive algorithms follow a divide-and-conquer approach. They break the problem down into several subproblems that are similar to the original problem but are smaller in size. The subproblems are solved recursively and the subproblem solutions are combined to create a solution to the orginal problem. 

Base case - problem is small enough to solve without recursing.

Recursive case
    1. **Divide** the problem into one or more subprobles that are smaller instances of the same problem.
    2. **Conquer** the subproblems by solving them recursively.
    3. **Combine** the subproblem solutions to form a solution to the original problem.


The **merge sort** algorithm follows the divide and conquer method. Starting with the entire array A[1:n], sort a subarray A[p:r]

**Divide** the subarray A[p:r] into two adjacent subarrays. Compute the midpoint *q* of *A[p:r]* (taking the average of p and r), and divide *A[p:r]* into subarrays *A[p:q]* and *A[q+1:r]*.

**Conquer** by sorting each of the two subarrays *A[p:q]* and *A[q+1:r]* recursively using merge sort.

**Combine** by merging the two sorted subarrays *A[p:q]* and *A[q+1:r]* back into *A[p:r]*, producing the sorted answer.

Recursion stops when reaching the base case. When the subarry *A[p:r]* has just one element, i.e. p equals r, the array is sorted.


```c
MergeSort (A, p, r)
    // base case, zero or one element in array
    if p >= r
        return

    // calculate mid point
    q = (p + r) / 2
    
    MergeSort(A, p, q)      // recursively sort A[p:q]
    MergeSort(A, q+1, r)    // recursively sort A[q+1: r]

    Merge(A, p, q, r)       // merge A[p:q] and A[q+1:r] int A[p:r]
```

## Merge 


```c
Merge(A, p, q, r)
    nL = q - p + 1       // length of A[p:q]
    nR = r - q           // length of A[q+1:r]

    let L[0:nL - 1] and R[0:nR-1] be new arrays
    // copy A[p:q] into L[0:nL-1]
    for i = 0 to nL - 1
        L[i] = A[p+i]

    // copy A[q+1:r] int R[0:nr-1]
    for j = 0 to nR - 1
        R[j] = A[q+j+1]

    i = 0       // set i index to smallest remaining element in L
    j = 0       // set j index to smallest remaining element in R
    k = p       // k indeexes the location in A to fill 

    // As long as each of the arrays L and R contain and unmerged element,
    // copy the smallest unmerged element back into A[p:r]
    while i < nL and j < nR
        if L[i] <= R[j]
            A[k] = L[i]
            i = i + 1
        else 
            A[k] = R[j]
            j = j + 1
        k = k + 1

    // Either all of L or all of R has been copied into A
    // Copy the remaining unmerged elements into A 
    while i < nL
        A[k] = L[i]
        i = i + 1
        k = k + 1 

    while j < nR
        A[i] = R[j]
        j = j + 1
        k = k + 1
```

