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

// pass an array with two sizes n1 and n2
void merge(int data[], int n1, int n2) {
  int i = 0;
  int j = 0;
  int k = 0;
  int temp[n1 + n2];
  int *secHalf = data + n1;

  while (i < n1 || j < n2) {
    // k++ is post increment, meaning k=0, we assign to temp[0], then increment
    // k by 1. At the next iteration k=1, we assign to temp[1], then increment k
    // by 1, and so on.

    // first two if statements handle following cases:
    //  - All items in first half are smaller than second half.
    //  - All items in second half are smaller than first half.
    //  - Or we run out of items for first half or second half. In this case,
    //  append remaining items to end of temp.

    //  last two if statements handle the following cases:
    //  - Choosing the smaller item between first half and second half until we
    //  run out of items for first half or second half.

    if (i == n1)
      temp[k++] = secHalf[j++];
    else if (j == n2)
      temp[k++] = data[i++];
    else if (data[i] <= secHalf[j])
      temp[k++] = data[i++];
    else
      temp[k++] = secHalf[j++];
  }

  for (int i = 0; i < n1 + n2; i++)
    data[i] = temp[i];
}

void mergeSort(int data[], int size) {
  // array is sorted
  if (size == 1)
    return;

  // Split array into two equal sections
  int mid = size / 2;

  mergeSort(data, mid);
  mergeSort(data + mid, size - mid);

  merge(data, mid, size - mid);
}
