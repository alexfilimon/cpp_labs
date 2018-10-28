##HeapSort

The heapsort algorithm involves preparing the list by first turning it into a max heap. The algorithm then repeatedly swaps the first value of the list with the last value, decreasing the range of values considered in the heap operation by one, and sifting the new first value into its position in the heap. This repeats until the range of considered values is one value in length.

The steps are:

1. Call the `buildMaxHeap()` function on the list. Also referred to as `heapify()`, this builds a heap from a list in **O(n)** operations.
2. Swap the first element of the list with the final element. Decrease the considered range of the list by one.
3. Call the `siftDown()` function on the list to sift the new first element to its appropriate index in the heap.
4. Go to step *(2)* unless the considered range of the list is one element.

The `buildMaxHeap()` operation is run once, and is **O(n)** in performance. The `siftDown()` function is **O(log n)**, and is called **n** times. Therefore, the performance of this algorithm is **O(n + n log n)** = **O(n log n)**.


## QuickSort

Quicksort is a divide and conquer algorithm. Quicksort first divides a large array into two smaller sub-arrays: the low elements and the high elements. Quicksort can then recursively sort the sub-arrays.

The steps are:

1. Pick an element, called a pivot, from the array.
2. Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
3. Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
The base case of the recursion is arrays of size zero or one, which are in order by definition, so they never need to be sorted.

The pivot selection and partitioning steps can be done in several different ways; the choice of specific implementation schemes greatly affects the algorithm's performance.

##Stack

A stack is a container of objects that are inserted and removed according to the last-in first-out (**LIFO**) principle. In the pushdown stacks only two operations are allowed: push the item into the stack, and pop the item out of the stack. A stack is a limited access data structure - elements can be added and removed from the stack only at the top. push adds an item to the top of the stack, pop removes the item from the top. A helpful analogy is to think of a stack of books; you can remove only the top book, also you can add a new book on the top.

## Task-5
Based on hash-table task. Hash table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.
It takes width and height of rectangle from `rects.txt`

#Universal
Nobody knows what it is because it's not created yet (or just full of space and void)
