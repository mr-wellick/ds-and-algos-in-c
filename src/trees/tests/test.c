#include "../../../unity/unity.h"
#include "../trees.h"
#include <stdlib.h>

// Optional: Any setup code that needs to run before each test
void setUp(void) {}

// Optional: Any teardown code that needs to run after each test
void tearDown(void) {}

void test_create_node(void) {
  Node *root = createNode(5);

  TEST_ASSERT_EQUAL_INT(5, root->value);
  TEST_ASSERT_NULL(root->left);
  TEST_ASSERT_NULL(root->right);

  free(root);

  root = NULL;
  TEST_ASSERT_NULL(root);
}

void test_tree_insertion() {
  Node *root = NULL;

  insert(&root, 3);
  insert(&root, -2);
  insert(&root, 6);
  insert(&root, 2);
  insert(&root, 25);

  // since our printTree method employs pre-order traversal, expected output
  // should be: 2, -2, 25, 6, 3
  printTree(&root);
  printf("\n");

  // since our demolish method employs post-order traversal, expected output
  // should be: 2, -2, 25, 6, 3
  demolish(&root);

  root = NULL;
  TEST_ASSERT_NULL(root);
}

void test_find_value() {
  Node *root = NULL;

  insert(&root, 3);
  insert(&root, -2);
  insert(&root, 6);
  insert(&root, 2);
  insert(&root, 25);

  // Was value found?
  // True: 1
  // False: 0
  TEST_ASSERT_EQUAL_INT(1, find(&root, 25));
  TEST_ASSERT_EQUAL_INT(0, find(&root, 100));
}

void test_find_min() {
  Node *root = NULL;

  TEST_ASSERT_EQUAL_INT(-1, min(&root));

  insert(&root, 3);
  insert(&root, -2);
  insert(&root, 6);
  insert(&root, 2);
  insert(&root, 25);

  TEST_ASSERT_EQUAL_INT(-2, min(&root));
}

void test_find_max() {
  Node *root = NULL;

  TEST_ASSERT_EQUAL_INT(-1, max(&root));

  insert(&root, 3);
  insert(&root, -2);
  insert(&root, 6);
  insert(&root, 2);
  insert(&root, 25);

  TEST_ASSERT_EQUAL_INT(25, max(&root));
}
int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_node);
  RUN_TEST(test_tree_insertion);
  RUN_TEST(test_find_value);
  RUN_TEST(test_find_min);
  RUN_TEST(test_find_max);
  UNITY_END();

  return 0;
}
