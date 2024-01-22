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
