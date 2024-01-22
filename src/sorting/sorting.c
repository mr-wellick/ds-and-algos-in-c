#include "./sorting.h"
#include <stdbool.h>

void selectionSort(int items[], int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (items[j] < items[minIndex])
        minIndex = j;
    }
    // swap(items[i], items[minIndex])
    int temp = items[i];
    items[i] = items[minIndex];
    items[minIndex] = temp;
  }
}

void insertionSort(int items[], int n) {
  for (int size = 2; size <= n; size++) {
    int sortMe = items[size - 1];

    int i = size - 2;
    while (i >= 0 && sortMe < items[i]) {
      items[i + 1] = items[i];
      // note: i is declared outise of while loop scope
      --i;
    }

    // note:
    //      - executed if item is already sorted, not ideal.
    //      - after while loop, we found the free spot into which we need to
    //      insert the new value.
    //      - need to increment by 1 to insert into correct location
    items[i + 1] = sortMe;
  }
}

void bubbleSort(int items[], int n) {
  bool atLeastOneSwap;

  do {
    atLeastOneSwap = false;

    for (int j = 0; j < (n - 1); j++) {
      if (items[j] > items[j + 1]) {
        int temp = items[j];
        items[j] = items[j + 1];
        items[j + 1] = temp;

        atLeastOneSwap = true;
      }
    }
  } while (atLeastOneSwap);
}

int partition(int items[], int low, int high) {
  int pi = low;
  // select first item as our pivot
  int pivot = items[low];

  do {
    // find first value > than the pivot
    while (low <= high && items[low] <= pivot)
      low++;

    // find first value < than the pivot
    while (items[high] > pivot)
      high--;

    // swap larger with the smaller
    if (low < high) {
      int temp = items[low];
      items[low] = items[high];
      items[high] = temp;
    }

  } while (low < high);

  // swap pivot to proper position in array
  int temp = items[pi];
  items[pi] = items[high];
  items[high] = temp;

  // return pivots index in the array
  pi = high;
  return pi;
};

/*
 * @items:  - array to sort
 * @first:  - starting element of the array to sort
 * @last:   - the last element of the array to sort
 */
void quickSort(int items[], int first, int last) {
  // only run for arrays of at least two items
  if (last - first >= 1) {
    int pivotIndex = partition(items, first, last);

    quickSort(items, first, pivotIndex - 1);
    quickSort(items, pivotIndex + 1, last);
  }
}

void mergeSort() {}
