#ifndef SORTING_H
#define SORTING_H

// These sorting algorithms are not used in real life. Too slow.
void selectionSort(int items[], int n);

void insertionSort(int items[], int n);

void bubbleSort(int items[], int n);

// These sorting algorithms are used in real life. Efficient.
void quickSort(int items[], int first, int last);

void merge(int data[], int n1, int n2);

void mergeSort();

#endif
