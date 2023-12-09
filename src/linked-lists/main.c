#include "linked-lists.h"
#include <stdio.h>

int main(void) {
  Node *list = NULL;
  list = insert(list, 10);
  list = insert(list, 5);
  list = insert(list, 15);

  printList(list);

  Node *found = searchList(list, 10);

  if (found) {
    printf("The value was found: %d\n", found->value);
  } else {
    printf("The value was not found: %p\n", found);
  }

  if (searchList(list, 99)) {
    printf("The value was found. \n");
  } else {
    printf("The value was not found \n");
  }

  return 0;
}
