#include "../../../unity/unity.h"
#include "../queue.h"
#include <stdio.h>

void setUp(void) {}
void tearDown(void) {}

void test_init_queue(void) {
  int size = 5;
  Queue *q = createQueue(size);

  insert(&q, 1);
  insert(&q, 2);
  insert(&q, 3);
  insert(&q, 4);
  insert(&q, 5);
  insert(&q, 6);

  for (int i = 0; i < 5; i++) {
    TEST_ASSERT_EQUAL_INT(i + 1, q->arr[i]);
  }

  TEST_ASSERT_EQUAL_INT(0, q->head);
  TEST_ASSERT_EQUAL_INT(size, q->tail);
  TEST_ASSERT_EQUAL_INT(size, q->count);
  TEST_ASSERT_EQUAL_INT(size, q->size);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_init_queue);
  UNITY_END();

  return 0;
}
