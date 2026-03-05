# My code dump with C-language
Different codes that I have done using C-language. 
## [Algorithms](Algorithms/)
### Bubble sort
Implementation of bubble sort algorithm. Bubble sort algorithm works by repeatedly steps through the input list element by element, 
comparing the current element with the one after it, swapping their values if needed. 
These passes through the list are repeated until no swaps have to be performed during a pass, 
meaning that the list has become fully sorted. The algorithm, which is a comparison sort, is named for the way the larger elements "bubble" up to the top of the list.

Complexity: __n^2__

Filename: __bubblesort.c__

### Insertion sort
Implementation of insertion sort algorithm. Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time by comparisons. 

Complexity: __n^2__

Filename: __insertionsort.c__

### Shell sort
Implementation of shell short algorithm. Shellsort is an in-place comparison sort. 
It can be understood as either a generalization of sorting by exchange (bubble sort) or sorting by insertion (insertion sort).
The method starts by sorting pairs of elements far apart from each other, then progressively reducing the gap between elements to be compared. 
By starting with far-apart elements, it can move some out-of-place elements into the position faster than a simple nearest-neighbor exchange. 
The running time of Shellsort is heavily dependent on the gap sequence it uses.

Complexity: __n^2__

Filename: __shellsort.c__


## [Data Structures](Data%20Structures/)
### Singly Linked List
A singly linked list is a fundamental data structure, it consists of nodes where each node contains a data field and a reference to the next node in the linked list. 
The next of the last node is null, indicating the end of the list. Linked Lists support efficient insertion and deletion operations.

Filename: __linkedlist.c__
### Queue
A queue is a linear data structure where elements are stored in the FIFO (First In First Out) principle where the first element inserted would be the first element to be accessed. 
A queue is an Abstract Data Type (ADT) similar to stack, the thing that makes queue different from stack is that a queue is open at both its ends. 
The data is inserted into the queue through one end and deleted from it using the other end.

Filename: __queue.c__

## [Others](Others/)
### Mini calculator
Calculator implemented using ternary operators. I tried to make the calculator as small and simple as possible.

Filename: __minicalc.c__

### Sizes of datatypes
Small program that prints the sizes of different data types in C.

Filename: __sizes.c__

### Swapping integers values using pointers
Self explanatory.

Filename: __swap.c__

### Printing triangle
Prints triangle using * by user given size.

Filename: __triangle.c__
