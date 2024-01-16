#include "../../../unity/unity.h"
#include "../stacks.h"

#define SIZE 100

void setUp(void) {}
void tearDown(void) {}

void test_push(void) {
  StackHead *dummyStack = createStack();
  //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

  for (int i = 0; i < SIZE; i++) {
    push(&dummyStack, i);
    TEST_ASSERT_EQUAL_INT(i + 1, dummyStack->count);
  }

  freeStack(&dummyStack);
  TEST_ASSERT_NULL(dummyStack);
}

void test_pop(void) {
  StackHead *dummyStack = createStack();
  //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

  for (int i = 0; i < SIZE; i++) {
    push(&dummyStack, i);
  }

  for (int i = SIZE - 1; i > SIZE; i--) {
    pop(&dummyStack);
    TEST_ASSERT_EQUAL_INT(i, dummyStack->count);
  }

  freeStack(&dummyStack);
  TEST_ASSERT_NULL(dummyStack);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_push);
  RUN_TEST(test_pop);
  UNITY_END();
  return 0;
}
