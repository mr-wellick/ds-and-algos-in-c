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
