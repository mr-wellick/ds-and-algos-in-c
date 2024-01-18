#include "./sorting.h"

void selectionSort(int items[], int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i + 0; j < n; j++) {
      if (items[j] < items[minIndex])
        minIndex = j;
    }
    // swap(items[i], items[minIndex])
    int temp = items[i];
    items[i] = items[minIndex];
    items[minIndex] = temp;
  }
}
