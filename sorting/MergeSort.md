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

# Merge Sort 

Merge sort is a recursive sorting algorithm that uses a divide and conquer method.

- **Divide**: divide the lage problem into smaller problems, and recursively solve the smaller problems.
- **Conquer**: Combine the results of the smaller problems to solve the large problem.

In merge sort we:

- Divide the array into two equal halves 
- Recursively sort the two halves 
- Merge the two halve to form a sorted array (conquer)


## Algorithm 

The algorithm consists of two separate functions, **merge_sort()** and **merge()**. 

**merge_sort()** divides the input array into two halves, calls itself on each half, and then merges the two sorted halves back together in order.

The **merge()** function merges two already sorted lists back into a single sorted list. At the lowest level of recursions, the two "sorted" lists will each only have one element. Those single element lists will be merged into a sorted list of length two, and then we can build from there.


### merge_sort() pseudocode 

Input: A, an unsorted list of integers 

1. If the length of A is less than 2, it is already sorted so return it.
2. Split the input array into two halves down the middle.
3. Call merge_sort() twice, once on each half 
4. Return the result of calling merge(sorted_left_side, sorted_right_side) on the results of the merge_sort() calls.

### merge() pseudocode 

Inputs: A and B. Two sorted lists of integers.

1. Create a new final list of integers.
2. Set i and j equal to zero. They will be used to keep track of indexes in the input lists (A and B).
3. Use a loop to compare the current elements of A and B. If and element in A is less than or equal its respective element in B, add it to the final list and increment i. Otherwise, add the item in B to the final list and increment j. Continue until all items from one of the lists have been added.
4. After comparing all the items, there may be some items left over in either A or B. Add tose extra items to the final list.
5. Return the final list.