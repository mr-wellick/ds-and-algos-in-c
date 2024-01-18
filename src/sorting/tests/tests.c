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

  printf("unsorted array: \n");
  for (int i = 0; i < size; i++) {
    int randomValue = rand() % 1000;
    elements[i] = randomValue;
    printf("value is %d\n", elements[i]);
  }

  selectionSort(elements, size);

  printf("sorted array: \n\n");
  for (int i = 0; i < size; i++) {
    printf("the value is %d\n", elements[i]);
  }
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_selection_sort);
  UNITY_END();

  return 0;
}
