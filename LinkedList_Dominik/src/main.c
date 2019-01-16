#include "LinkedList.h"
#include <stdio.h>

int main(void) {
  linkedList *list;
  list = create_linked_list();
  add_to_end(list, 1);
  add_to_end(list, 2);
  printf("\%i \n", list->length);
  printf("\%i \n", list->first->value);
  printf("\%i \n", list->last->value);
}
