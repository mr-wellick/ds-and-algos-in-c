# Graphs

- Before we can implement a Graph in C, we need to uderstand how to work with arrays in C

# Arrays in C

- Simplest array has one dimension.

```c
//       _ _ _ _
// a -> |_|_|_|_|
int a[4];
```

- Since array lengths may need to change, using a macro to define the length of an array is an excellent practice.
```c
# define N 10
int a[N];
```

- In general, if an array contains elements of type T, then each element of the array is treated as if it were a variable of type T. 

```c
// For example, the elements below behave like int variables.
a[0]
a[5]
a[i]
```

- Array initialization

```c
// Length of array matches the initializer
int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

// If the initializer is shorter than the array, the remaining elements are given 0.
int a[10] = { 1, 2, 3, 4, 5 };

// Initialize all values to zero
int a[10] = { 0 };
```

- Designated initializers

```c
// We want to initialize only some elements
int a[15] = {0, 0, 29, ,0 0, ,0 0, 0, 0, 7 , 0, ,0 ,0 0, 48};

// Instead (each number in brackets is said to be a designator).
int a[15] = { [2] = 29, [9] = 7, [14] = 48 };

// Note: the order in which the elements are listed no longer matters.
int a[15] = { [14] = 48, [2] = 29, [9] = 7 };

// If the length of the array is omitted, the compiler will deduce the length from the largest designator
int b[] = { [5] = 10, [23] = 13, [11] = 36, [15] = 29 };
```
