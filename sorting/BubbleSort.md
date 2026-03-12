# Bubble Sort 

Bubble Sort is a sorting algorithm that repeatedly steps through a list, compares adjacent elements, and swaps them if they are in out of order. This process continues until the entire list is sorted, with the largest (or smallest, depending on the sort order) elements "bubbling" up to their correct positions.


 ## How It Works 

 The algorithm involves multiple passes through the data. In each pass, it compares every adjacent pair of items.

 1. **Comparison:** Starting from the first index, the current element is compared with the next element in the list.
 2. **Swapping:** If the elements are in the wrong order, their positions are swapped. Ex: For ascending order, if the first is greater than the second, their positions are swapped.
 3. **Iteration:** The process move to the next pair and continues until the end of the list is reached.
 4. **Repetition:** The entire process (a "pass") is repeated until no swaps occur during a pass, which indicates the list is fully sorted.

 After each pass, the next largest unsorted element is guaranteed to be in its final sorted position at the end of the unsorted section of the list.


## Manual Walk Through One Array Pass (Ascending Sort Order)

1. Start with an unsorted array [7 12, 9, 11, 3]
2. Look at the first two values. Does the lowest value come first? Yes, so we don't need to swap them.

    [**7**, **12**, 9, 11, 3]

3. Move to the next pair, values 12 and 9. Does the lowest value come first? No

    [7, **12**, **9**, 11, 3]

4. Swap 9 and 12 so that 9 comes first

    [7, **9**, **12**, 11, 3]

5. Move to the next pair, values 12 and 11. Does the lowest value come first? No.
    [7, 9, **12**, **11**, 3]

6. Swap 11 and 12 so that 11 comes first.
    [7, 9, **11**, **12**, 3]

7. Move to the next pair, values 12 and 3. Does the lowest value come first? No.
    [7, 9, 11, **12**, **3**]

8. Swap 12 and 3 so that 3 comes first.
    [7, 9, 11, **3**, **12**]
   
9. We have reached the end of the list on this first pass. Note that the largest value 12 has "bubbled up" to the end of the list. To finish sort, we need to pass through the array again, starting from the first element and ending at the next to last element.



## Pseudocode

- Set swapping to True 
- Set end to the length of the input list 
- While swapping is True:
    - Set swapping to false 
    - For i from the second element to the end:
        - If the (i-1)th element of the input list is greater than the ith element:
            - Swap the (i-1)th element and the ith element 
            - Set swapping to true 
    - Decrement end by one 
- Return the sorted list
    

    
## Characteristics 

**- Simplicity**: Easy to understand and implement. Mostly used as an educational tool for teaching sorting concepts.
**- Inefficiency**: Generally inefficient for large data sets due to its average and worst-cast time complexity of O(n^2). As the number of items (n) grows, the runtime increases significantly.

**- Time Complexity**: 
    - Let n represent the number of elements in the array.
    - Best case O(n): If the data is pre-sorted, bubble sort is very fast. The number of comparisons required is n-1 and the number of swaps required is 0. 
    - Worst case 0(n^2): The worst-case condition for bubble sort occurs when element of the array are arranged in decreasing order.  The total number of comparisons and swaps are n(n-1)/2 which is O(n^2).
        - There are n-1 iterations to sort the array.
        - At pass 1: n-1 comparisons and swaps 
        - At pass 2: n-2 comparisons and swaps
        - At pass 3: n-3 comparisons and swaps
        - ... 
        - At pass n-1: 1 comparison and swap

        - Total = (n-1) + n-2 + n-3 + ... + 2 + 1 
        - Sum of natural numbers formula: sum = n(n+1)/2
        - Total = (n-1)(n-1+1)/2 = n(n-1)/2
    - Average Case: O(n^2)

**- Space Complexity**: Requires only a constant amount of additional memory space, O(1), because it sorts the array in place.


| Complexity Type | Complexity |
| --- | --- | 
| Time  | Best:    O(n)   |
|       | Average: O(n^2) |
|       | Worst:   O(n^2) |
| Space | Worst: O(1) |
 

 ## References 

See [W3 Schools DSA Bubble Sort](https://www.w3schools.com/dsa/dsa_algo_bubblesort.php) for an excellent explanation and visualizations.

See [Geeks for Geeks, Time and Space Complexity Analysis](https://www.geeksforgeeks.org/dsa/time-and-space-complexity-analysis-of-bubble-sort/)




```python
def bubble_sort(nums):
    swapping = True 
    end = len(nums)
    while swapping == True:
        swapping = False 
        for i in range(1, end):
            if nums[i-1] > nums[i]:
                nums[i-1], nums[i] = nums[i], nums[i-1]
                swapping = True 
        end -= 1
    return nums
```