# Common Sorting Algorithms

- The following sorting algorithms are inefficient and won't use them often. But it's like diagramming sentences and will serve as practice.
    - Selection Sort
    - Insertion Sort
    - Bubble Sort

- Sorting is the process of ordering items based on one or more rules subject to one or more constraints.
    - Items: what are we sorting?
    - Rules: How do we order them?
    - Constraints: Is the data in an array or a linked-list?

# Sorting Rules

- Rule #1: Don't choose a sorting algorithm until you understand the requirements of your problem.

- Rule #2: Always choose the simplest sorting algorithm possible that meets your requirements.

# Selection Sort

- Look at all N books, select the shortest book.

- Swap this with the first book.

- Look at the remaining the N-1 books and select the shortest.

- Swap this book with the second book.

- And so on...

## Big O of Selection Sort

- It takes N + N-1 + N-2 + ... + 2 + 1 = (N*(N+1)) / 2

- This is roughly equal to N^2.

- Question: Are there any kinds of input data where Selection Sort is either more or less efficient? If our array is mostly sorted, for example.

- No, Selection Sort takes just as many steps either way!

- Is selection sort stable or unstable? It's unstable.

# What is a Stable Sort?

- Imagine N people line up to buy medication at a drugstore.

- The drugstore wants to sort them and serve them based on urgency.

- The drugstore needs to pick a sort algorithm to re-order the guests. They can choose between a stable or unstable sort.

- An unstable sorting algorithm re-orders the items without taking into account their initial ordering.

<img src="./img/unstable-sort.jpeg"/>

- A stable sorting algorithm does take into account the inital ordering when sorting, maintaining the order of similar-valued items.

<img src="./img/stable-sort.jpeg"/>


# Insertion Sort

- Insertion sort is probably the most common way to sort playing cards.

<img src="./img/books.jpeg"/>

- Focus on first 2 books.
    - If the last book in this set is in the wrong order:
        - Remove it from the shelf.
        - Shift the book before it to the right.
        - Insert our book into the proper slot.

- Focus on first 3 books.
    - If the last book in this set is in the wrong order:
        - Remove it from the shelf.
        - Shift the book before it to the right as necessary.
        - Insert our book into the proper slot.

- Repeat until the shelf is sorted.

- Big O of insertion sort: 1 + 2 + ... + N-1 which is roughly N^2 steps.

- Note, if all books are in the proper order, insertion sort never needs to do any shifting.
In this case, it takes N steps to complete. Conversely, a perfectly mis-ordered set of books is the worst case, N^2.

- Can be used to sort a linked-list (doubly-linked list).

- Insertion sort is a stable sort.

# Bubble Sort

- Start at the top element of the array.

- Compare the first two elemets: A[0] and A[1]. If they're out of order, then swap them.

- Then advance one element in your array. Compare these two elements: A[1] and A[2]. If they're out of order, then swap them.

- When you hit the end, if you made at least one swap, then repeat the whole process again.

- Big O: N passes of N "bubbles" = N^2

- Can it run faster? Yes on pre-sorted arrays like insertion sort.
