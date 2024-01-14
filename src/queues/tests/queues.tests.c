#include "../../../unity/unity.h"
#include "../queue.h"

void setUp(void) {}
void tearDown(void) {}

void test_enqueue(void) {
  int size = 5;
  Queue *q = createQueue(size);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 5);
  enqueue(&q, 6);

  for (int i = 0; i < size; i++) {
    printf("the value is %d\n", q->arr[i]);
  }

  for (int i = 0; i < size; i++) {
    TEST_ASSERT_EQUAL_INT(i + 1, q->arr[i]);
  }

  TEST_ASSERT_EQUAL_INT(0, q->head);
  TEST_ASSERT_EQUAL_INT(size, q->count);
}

void test_dequeue(void) {
  int size = 5;
  Queue *q = createQueue(size);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 5);

  for (int i = 0; i < size; i++) {
    TEST_ASSERT_EQUAL_INT(i + 1, dequeue(&q));
  }

  TEST_ASSERT_EQUAL_INT(0, q->head);
  TEST_ASSERT_EQUAL_INT(0, q->tail);
  TEST_ASSERT_EQUAL_INT(0, q->count);
}

void test_free_memory(void) {
  int size = 5;
  Queue *q = createQueue(size);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 5);

  detonate(&q);

  TEST_ASSERT_NULL(q);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_enqueue);
  RUN_TEST(test_dequeue);
  RUN_TEST(test_free_memory);
  UNITY_END();

  return 0;
}
