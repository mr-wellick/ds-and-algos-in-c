#include "../../../unity/unity.h"
#include "../trees.h"
#include <stdlib.h>

// Optional: Any setup code that needs to run before each test
void setUp(void) {}

// Optional: Any teardown code that needs to run after each test
void tearDown(void) {}

void test_create_node(void) {
  Node *root = (Node*)malloc(sizeof(Node));
  root->value = 5;
  root->left = NULL;
  root->right = NULL;

  TEST_ASSERT_EQUAL_INT(5, root->value);
  TEST_ASSERT_NULL(root->left);
  TEST_ASSERT_NULL(root->right);

  demolish(root);
  printf("test %d\n", root->value);
  printf("test %p\n", root->left);
  printf("test %p\n", root->right);
  TEST_ASSERT_NULL(root);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_node);
  // Add more RUN_TEST statements for additional tests
  UNITY_END();

  return 0;
}
