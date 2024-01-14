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
int a[15] = {0, 0, 29, 0, 0, 0, 7, 0, 0, 0, 48};

// Instead (each number in brackets is said to be a designator).
int a[15] = { [2] = 29, [9] = 7, [14] = 48 };

// Note: the order in which the elements are listed no longer matters.
int a[15] = { [14] = 48, [2] = 29, [9] = 7 };

// If the length of the array is omitted, the compiler will deduce the length from the largest designator
int b[] = { [5] = 10, [23] = 13, [11] = 36, [15] = 29 };
```

# Sizeof Operator

- The sizeof operator can be used to determine the size of the array (in bytes).

```c
int a[10] = { 0 }

// gives us the length of the array
sizeof(a) / sizeof(a[0])

/*
    note: sizeof produces a value of size_t (an unsigned type), as such, some compilers produce a warning message for the expression: sizeof(a) / sizeof(a[0])
    - i is most likely a type int (signed type)
    - Comparing a signed integer with an unsigned integer is a dangerous practice,
*/
for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    a[i] = 0;

// We can cast
for(i = 0; i < (int) ( sizeof(a) / sizeof(a[0]) ); i++)
    a[i] = 0;

// We can write a macro to avoid writing that nice expression (more about this in chapter 14.3 parameterized macros)
#define SIZE ( (int) (sizeof (a) / sizeof(a[0])) )

for(i = 0; i < SIZE; i++)
    a[i] = 0;
```

# Multidimensional Arrays

- An array may have any number of dimensions.

- We can also use designated initializers in multidimensional arrays.

```c
// row x columns
int m[1][2] = {
            { 5, 20, 5 },
        }; // the rest of the rows will be initialized to 0
```

- C stores arrays in row-major order, with row 0 first, then row 1, and so forth. For example, here's how the marray is stored:

<img src="img/row-major-order.jpeg" />

- Note: Multidimensional arrays play a lesser role in C than in many other programming languages, primarily because C provides a more flexible way to store multidimensional data: arrays of pointers (chapter 13.7).

# Variable Length Arrays

- We can determine the length of the array when the program is executed

```c
int n;

printf("How many numbers do you want to reverse? ");
scanf("%d", &n);

// C99 only - length of array depends on n
int a[n];
```

- Can't have static storage duration (need to read about this later)

- Can't have an initializer

# Array as Arguments

- When a function parameter is a one-dimensional array, the length of the array can be (and is normally) left unspecified.

- The argument can be any one dimensional array whose elements are of the proper type.

```c
int f(int a[]);
```

- C doesn't provide an easy way for a function to determine the length of an array passed to it.

- Although we can use the sizeof operator to help determine the length of an array variable, it doesn't give the correct answer for an aray parameter (read section 12.3 on why this is).

```c
int f(int a[]) {
    /* WRONG! not the number of elements in a */
    int len = sizeof(a) / sizeof(a[0]);
}
```

- A function has no way of knowing if we passed the correct array length! Instead, we have to supply the length, if the function needs it, as an addional argument.

- Also, a function is allowed to change the elements of an array parameter, and the change is reflected in the corresponding argument.

```c
int f(int a[], int size) {
    for(int i = 0; i < size i++) {
        a[i] = 0;
    }
}
```

- If a parameter is a multidimensional array, only the length of the first dimension may be omitted when the parameter is declared.

```c
#define LEN 10;
int sum_two_dimensional_array(int a[][LEN], int n) {
    int i, j, sum = 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < LEN; j++) {
            sum += a[i][j];
        }
    }

    return sum;
}
```

- Not being able to pass multidimensional arrays with an arbitrary number of columns can be a nuisance. We can often work around this difficulty by using arrays of pointers (read 13.7).

# Variable-Length Array Parameters

- Using a variable-length array parameter, we can explicitly state that a's length in n.

```c
int sum_array(int n, int a[n]);
```

- The value of the first parameter (n) specifies the length of the second parameter (a). The order is important here.

- In general, the length of a variable-length array parameter can be any expression.

```c
int concatenate(int m, int n, int a[m], int b[n], int c[m+n]);
```

- Variable-length array parameters are most useful for multidimensional arrays.

```c
int sum_two_dimensional_array(int n, int m, int a[n][m]) {
    int i, j, sum = 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            sum += a[i][j];
        }
    }

    return sum;
}
```

# Dynamically Allocated Arrays

- It's often difficult to determine proper array size when writing programs. It's more convenient to wait unitl the program is run to decide how large the array should be.

- Can do this with by allocating space for an array during execution. Then access the array through a pointer to its first element.

- The calloc function is sometimes used instead, since it initializes the memory that it allocates.

- The realloc function allows us to make the array "grow" or "shrink." 

- Using calloc to dynamically allocate arrays:

```c
// note: returns a null pointer if the requested space isn't available
// void *calloc(size_t nmemb, size_t size);

// allocates space for an array with nmemb elements each of which is size bytes long.
// also, initializes it by setting all bits to 0.
a = calloc(n, sizeof(int));
```

- The realloc function can resize the array if it's too large or too small.

- When realloc is called, ptr must point to a memory block obtained by a previous call of malloc, calloc, or realloc.

- In practice, realloc ptr points to memory that's being used as an array, although it's not required.

- More about how realloc behaves in chapter 17.3.

```c
// realloc prototype
void *realloc(void *ptr, size_t size);
```

# Arrays of Structures

```c
#include <stdio.h>

#define STRINGS 6
#define SEMITONES 22

typedef struct Edge {
   int to 
} Edge;

int main(void) {
  Edge graph[STRINGS][SEMITONES] = {[5][8] = {10}};

  printf("We go from 8 to %d\n", graph[5][8].to);

  return 0;
}
```
