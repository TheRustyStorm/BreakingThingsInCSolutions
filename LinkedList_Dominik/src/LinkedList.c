#include "LinkedList.h"
#include <stdlib.h>

linkedList *create_linked_list(void) {
  linkedList *list = malloc(sizeof(linkedList));
  list->first = list->last = 0;
  list->length = 0;
  return list;
}

listNode *create_new_element(int value) {
  listNode *new_element = malloc(sizeof(listNode));
  if (new_element != 0) {
    new_element->value = value;
    new_element->next = 0;
  }
  return new_element;
}

void add_initial_element(linkedList *list, listNode *element) {
  list->first = element;
  list->last = element;
  list->length = 1;
}

void append_element(linkedList *list, listNode *element) {
  list->last->next = element;
  list->last = element;
  list->length++;
}

bool is_empty(linkedList *list) { return list->length == 0; }

bool add_to_end(linkedList *list, int valueToAdd) {
  listNode *new_element = create_new_element(valueToAdd);
  if (list == 0 || new_element == 0)
    return false;
  if (is_empty(list)) {
    add_initial_element(list, new_element);
  } else {
    append_element(list, new_element);
  }
  return true;
}

void add_to_begin(linkedList *list, int valueToAdd) {
  listNode *newElement = create_new_element(valueToAdd);
  newElement->next = list->first;
  list->first = newElement;
  list->length++;
}
