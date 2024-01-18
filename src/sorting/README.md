# Common Sorting Algorithms

- The following sorting algorithms are inefficient and won't use them often. But it's like diagramming sentences and will serve as practice.
    - Selection Sort
    - Insertion Sort

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

<img src="./img/selection-sort.jpeg"/>

- Look at the remaining the N-1 books and select the shortest.
- Swap this book with the second book.

<img src="./img/selection-sort-2.jpeg"/>

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

- A stable sorting algorithm does take into account the inital ordering when sorting, maintaining the order of similar-valued items.

# Insertion Sort

-
