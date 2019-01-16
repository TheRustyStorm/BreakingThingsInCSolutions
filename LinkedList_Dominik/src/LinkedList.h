#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <stdbool.h>

typedef struct listNode listNode;
typedef struct linkedList linkedList;

linkedList *create_linked_list(void);
listNode *create_new_element(int value);
void add_initial_element(linkedList *list, listNode *element);
void append_element(linkedList *list, listNode *element);
bool is_empty(linkedList *list);
bool add_to_end(linkedList *list, int valueToAdd);
void add_to_begin(linkedList *list, int valueToAdd);

struct listNode {
  int value;
  listNode *next;
};

struct linkedList {
  listNode *first;
  listNode *last;
  int length;
};

#endif // _LINKEDLIST_H
