# Practice Data Structures & Algorithms while learning C

## Pointer Basics

- Main memory is divided into bytes each capable of storing eight bits of information:

```
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
```
- Each byte has a unique address to distinguish it from the other bytes in memory.

- A pointer is an address. A pointer variable is a variable that can store an address (p points to i).

```
        ____
p ---> | _ | i
```

## Declaring Pointer Variables

- This declaration states that p is a pointer variable capable of pointing to "objects" (need to read more on this) of type int.

```c
int *p
```

- To find the address of a variable, we use & (address) operator. 

```c
int x = 5;
&x; // address of x
```

- To gain access to the object that a pointer points to, we use the * (indirection) operator.

```c
int *p;
*p; // *p represents the object to which p currently points
```

- It's crucial to initialize pointer variables before we use them.

```c
// points nowhere in particular
int *p;


// use the address of another variable to initialize q
int x = 5;
int *q; 
q = &x;
```

## Indirection Operator

- Once a variable points to an object, we can use the * (indirection) operator to access what's stored in the object.

```c
int x = 5;
int *p = &x;

printf("%d\n", *p); // print what's stored in the object (can think of * as the inverse of &)
```

- As long as p points to x, p is an alias for x. Not only does *p have the same value as x, but changing the value of *p also changes the value of x.

- Note, never apply the indirection operator to an uninitialized pointer variable. This causes undefined behavior.

## Pointer Assignment

```c
int i, j, *p, *q;

i = 6;
j = 7;

p = &i; // take address of i and assign it to p (p points to i)
q = p; // take address stored in p and assign it to q (q points to i)

q = &j // override address stored in q with the address of j (q points to j)

// note: be careful with the following
q = p; // pointer assignment (q points to i once more)
q = &j // take the address of j and assign it to q (q points to j, again)

*q = *p; // copies the value that p points to into the object that q points to (the value of both i and j is now 6)
```

## Pointers as Arguments

- A variable supplied as an argument in a function call is protected against change, because C passes arguments by value.

- We can use pointers as arguments to circumvent this:

```c
void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long)x;
    *fract_part = x - *int_part;
}

int i = 5;
int d = 5;

// pass the address of i and d
void decompose(3.14159, &i, &d);
```

## Pointers as return types

- Never return a pointer to an automatic local variable:

```c
int *f(void) {
    int i;
    // i does not exist once f returns, so the pointer to it will be invalid!
    return &i;
}
```

## Dynamic Storage Allocation

- To allocate storage dynamically, we'll need to call one of the tree memory allocation functions declared in <stdlib.h>:

```c
#include <stdlib.h>

malloc() // allocates a block of memory but does not initialize it
calloc() // allocates a block of memory and clears it
realloc() // resizes a previously allocated block of memory
```

- Malloc is the most used. When we call a memory allocation function to request a block of memory. The function has no idea what type of data we're planning to store in the block, so it can't return a pointer to an ordinary type. Instead, the function returns a value of type void* (a generic pointer, just a memory address).

## Null Pointers

- When a memory allocation function is called, there is always the possibility that it won't be able to locate a block of memory large enough to satisfy the request. If that occurs, the function will return a NULL pointer.

- A NULL pointer is a pointer to nothing, a special value that can be distinguished from all valid pointers.

- The null pointer is represented by a macro named NULL, so we can test malloc's return value:

```c
// some previously and properly declared variable p
p = malloc(10000)
if (p == NULL) {
    // allocation failed, take proper action
}
```

- In C, pointers test true or false in the same way as numbers. All non-null pointers test true; only null pointers are false.

- Malloc and the other memory allocation functions obtain memory blocks from a storage pool known as the heap.

- A block of memory that is no longer accessible to a program is said to be garbage (memory leak). Some languages provide a garbage collector. C does not!

## Free function

- Calling free releases the block of memory that p points to:

```c
p = malloc(...)
q = malloc(...)
free(p)

p = q;
```

- The argument to free must be a pointer that was returned using malloc, calloc, realloc. Anything else causes undefined behavior.

## The dangling pointer

- Although the function allows us to reclaim memory that's no longer needed, using it leads to a new problem: dangling pointers.

- The call to free(p) deallocates the memory block that p points to but doesn't change p itself. If we forget that p no longer points to a valid memory block, chaos may ensue:

```c
char *p = malloc(4)
free(p)

// WRONG!
strcpy(p, "abc")
```

- Attempting to access or modify a deallocated memory block causes undefined behavior.

- Be careful to give sizeof() the name of the type to be allocated and not the name of a pointer to that type:

```c
typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *root = NULL;

// Correct
new_node = malloc(sizeof(Node))

// Incorrect
new_node = malloc(sizeof(root))
```
## Pointers to Pointers

- When an argument to a function is a pointer, we sometimes want the function to be able to modify the variable by making it point somewhere else.

- Doing so requires the use of a pointer to a pointer.

```c
// Pointers like all arguments are passed by VALUE!
struct node *add_to_list(struct node *list, int n);
// At the point of the call, linked_list is copied into list.
add_to_list(linked_list, 10)

// Updated to include a double pointer
void add_to_list(struct node **list, int n) {
    struct node *new_node = malloc(sizeof(struct node));

    if (!new_node) {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;

    *list = new_node;
}

```
