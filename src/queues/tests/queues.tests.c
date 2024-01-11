#include "../../../unity/unity.h"
#include "../queue.h"

void setUp(void) {}
void tearDown(void) {}

void test_init_queue(void) { printf("todo: init queue\n"); }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_init_queue);
  UNITY_END();

  return 0;
}
