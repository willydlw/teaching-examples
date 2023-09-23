# Insertion Sort

Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration. 

The algorithm uses an incremental method: for each array element A[i], insert it into its proper place in the subarray A[1:i], having already sorted the subarray A[1: i-1].

## Example

Assume we want to sort the following array in increasing order.

```
9   5   1   4   3
```

1. The first element 9 is assumed to be sorted. Take the second element 5 and store it separately in a variable named *key*. 

Compare key with the first elemeent. If the first element is greater than *key*, then *key*  is placed in front of the first element.

|Sorted List| Key | Unsorted List |
| ---|---|---|
| 9 | 5 | 1 4 3 |


```
if (key < sorted element to its left)
    place key to left of sorted element
else 
    place key to right of sorted element
```

key 5 is less than sorted element 9


|Sorted List| Key | Unsorted List |
| ---|---|---|
| 5 9 | 1 | 4 3 |

Now the first two elements are sorted and the next key value is 1. Compare the key value 1 with elements to its left. 1 is less than 9, so place 1 to left of 9.

|Sorted List| Key | Unsorted List |
| ---|---|---|
| 5 1 9 | 1 | 4 3 |

Next compare key 1 to first element in list, 5. 1 is less than 5, so place 1 to the left of 5.

|Sorted List| Key | Unsorted List |
| ---|---|---|
| 1 5 9 | 4 | 3 |

The value 1 has been compared to all sorted elements. The next key value is the fourth element 4. Compare it to all the sorted values on its left.

4 < 9 so place 4 to left of 9.

|Sorted List| Key | Unsorted List |
| ---|---|---|
| 1 5 4 9 | 4 | 3 |


4 < 5 so place 4 to left of 5.

|Sorted List| Key | Unsorted List |
| ---|---|---|
| 1 4 5 9 | 3 |  |

4 > 1 so we stop the comparison as we know any remaining values to the left have already been sorted and will be less than the key value 4. 

The next key value is 3, the last element in the list. We compare it to elements to its left and swap places when key is less than the sorted elements to its left.

3 < 9 place it to left of 9

|Sorted List| Key | Unsorted List |
| ---|---|---|
| 1 4 5 3 9 | 3 |  |

3 < 5 place it to left of 5

|Sorted List| Key | Unsorted List |
| ---|---|---|
| 1 4 3 5 9 | 3 |  |

3 < 4 place it to left of 4

|Sorted List| Key | Unsorted List |
| ---|---|---|
| 1 3 4 5 9 | 3 |  |

1 not less than 3, so we stop. The list is now sorted.

|Sorted List|
| ---|
| 1 3 4 5 9 |





## Algorithm

```c
insertionSort(array)
    mark first element as sorted
    for each unsorted element x
        extract the element x
        for j = lastSortedIndex down to 0
            if current element j > x
                move sorted element to the right by 1
        break loop and insert X here
end insertionSort
```
