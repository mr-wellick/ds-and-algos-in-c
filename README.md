# Practice tree knowlege while learning C

## Review pointers and refs (in C++)

- IMPORTANT: C and C++ are two different languages according to Bjarne Stroustrup, creator of C++. However, the fundamentals of pointers carry over to C. To learn C, I am referencing: C Programming a Modern Approach.

- The reason for reviewing pointers in C++ is because the university course I took taught us CS fundamentals using C++. After this quick review, the tree data structures will be implemented using C.

- Every time we define a variable, the compiler finds an unused address in memory and reserves one or more bytes there to store it. Important: the address of a variable is defined to be the lowest address in memory where the variable is stored.

```c
int age = 41

cout << "age's address: " << &age; // print the address of age
```

- A pointer variable is a special kind of variable that holds another variable's address instead of a regular value.

```c
int age = 42;
int *p; // variable p is a pointer to an int variable
p = &age; // p points to the address of age
```

- Can use your pointer and the star operator to read/write to the other variables.

```c
int age = 42;
int *p;
p = &age;

cout << "age's value: " << *p; // get the address stored in p, go to that memory address, and give me the value stored there

*p = 5; // get the adress value stored in the p variable, go to that memory address, and store a value of 5 there
```

- Pointers vs References: When you pass a variable by reference to a function, what really happens? In fact, a reference is just a simpler notation for passing by a pointer!

```c
void set(int &val){ // val is a reference
    val = 5;
}

int main(){
    int x = 1;
    // looks like we're just passing the value of x to set(), but since set() accepts a reference, we are passing the address of variable x to set().
    set(x);
    cout << x;
}
```

- Common pitfalls.

```c
// did not initialize the pointer variable. we don't know where p points to. it points to some random spot in memory.
// must always set the value of a pointer variable before using the *operator on it!
int *p; 
*p = 1234;
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

