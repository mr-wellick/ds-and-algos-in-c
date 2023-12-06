#include "../../../unity/unity.h"
#include "../trees.h" // Include the source file you want to test

void setUp(void) {
    // Optional: Any setup code that needs to run before each test
}

void tearDown(void) {
    // Optional: Any teardown code that needs to run after each test
}

void test_create_node(void) {
  Node *root = createNode(5);
  TEST_ASSERT_EQUAL_INT(5, root->value);
  demolish(root);
}

// You can add more test cases as needed

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_node);
  // Add more RUN_TEST statements for additional tests
  UNITY_END();

  return 0;
}
