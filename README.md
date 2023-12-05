# Practice tree knowlege while learning C

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

- Note, never apply the indirection operator to an uninitialized pointer variable. This causes undefined behavior

## Pointer Assignment

```c
int i, j, *p, *q;

i = 6;

p = &i; // take address of i and assign it to p
q = p; // take address stored in p and assign it to q

q = &j // override address stored in q with the address of j

// note: be careful with the following
q = p; // pointer assignment
*q = *p; // copies the value that p points to into the object that q points to
```

## Pointers as Arguments

- A variable supplied as an argument in a function call is protected against change, because C passes arguments by value.

```c
void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long)x;
    *fract_part = x - *int_part;
}

void decompose(3.14159, &i, &d);
```

## Tree

- A Tree is a special linked list-based data structure.
- Common use cases: 
    - Organize hierarchical data.
    - Make information easily searchable.
    - Simplify evaluation of math expressions.
    - To make decisions (decision tree).

## Binary Tree

- A Binary Tree is a special form of tree. In a binary tree, every node has at most two children nodes.

## Full Binary Tree

- A full binary tree is one in which every leaf node has the same depth, and every non-leaf has exactly two children.

## Binary Search Tree

- A Binary Search Tree is a type of Binary Tree with specific properties that make them very efficient to search for a value in the tree.

- For every node X in the tree:
    - All nodes in X's left subtree must be less than X.
    - All nodes in X's right subtree must be greater than X.

# Binary Search Tree Operations

- Determine if the binary search tree is empty.
- Search the binary search tree for a value.
- Insert an item in the binary search tree.
- Delete an item from the binary search tree.
- Find the height of the binary search tree.
- Find the number of nodes and leaves in the binary search tree.
- Traverse the binary search tree.
- Free the memory used by the binary search tree.

