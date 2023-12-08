#include "linked-lists.h"
#include <stdio.h>

int main(void) {
  Node *list = NULL;
  list = insert(list, 10);
  list = insert(list, 5);
  list = insert(list, 15);

  printList(list);

  printf("Was the value found: %d\n", searchList(list, 10));

  return 0;
}
