#include "../../../unity/unity.h"
#include "../sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setUp(void) {}
void tearDown(void) {}

void test_selection_sort(void) {
  srand(time(NULL));

  int size = 10;
  int elements[size];

  for (int i = 0; i < size; i++) {
    int randomValue = rand() % 1000;
    elements[i] = randomValue;
  }

  selectionSort(elements, size);

  printf("\n");
  printf("sorted array with selection sort: \n");
  for (int i = 0; i < size; i++) {
    printf("the value is %d\n", elements[i]);
  }
}

void test_insertion_sort(void) {
  srand(time(NULL));

  int size = 10;
  int elements[size];

  for (int i = 0; i < size; i++) {
    int randomValue = rand() % 5000;
    elements[i] = randomValue;
  }

  insertionSort(elements, size);

  printf("\n");
  printf("sorted array with insertion sort: \n");
  for (int i = 0; i < size; i++) {
    printf("the value is %d\n", elements[i]);
  }
}

void test_bubble_sort(void) {
  srand(time(NULL));

  int size = 10;
  int elements[size];

  for (int i = 0; i < size; i++) {
    int randomValue = rand() % 200;
    elements[i] = randomValue;
  }

  bubbleSort(elements, size);

  printf("\n");
  printf("sorted array with bubble sort: \n");
  for (int i = 0; i < size; i++) {
    printf("the value is %d\n", elements[i]);
  }
}

void test_quicksort(void) {
  srand(time(NULL));

  int size = 15;
  int elements[size];

  for (int i = 0; i < size; i++) {
    int randomValue = rand() % 500;
    elements[i] = randomValue;
  }

  quickSort(elements, 0, size - 1);

  printf("\n");
  printf("sorted array with quicksort: \n");
  for (int i = 0; i < size; i++) {
    printf("the value is %d\n", elements[i]);
  }
}

void test_mergesort(void) {
  srand(time(NULL));

  int size = 15;
  int elements[size];

  for (int i = 0; i < size; i++) {
    int randomValue = rand() % 500;
    elements[i] = randomValue;
  }

  mergeSort();

  printf("\n");
  printf("sorted array with quicksort: \n");
  for (int i = 0; i < size; i++) {
    printf("the value is %d\n", elements[i]);
  }
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_selection_sort);
  RUN_TEST(test_insertion_sort);
  RUN_TEST(test_bubble_sort);
  RUN_TEST(test_quicksort);
  RUN_TEST(test_mergesort);
  UNITY_END();

  return 0;
}
