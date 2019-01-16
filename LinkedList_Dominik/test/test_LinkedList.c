#include "LinkedList.h"
#include "unity.h"
#include <stdint.h>
#include <stdlib.h>

linkedList *ll = NULL;

void setUp(void) { ll = create_linked_list(); }

void tearDown(void) { free(ll); }

void test_LinkedList_allocateMemoryList(void) { TEST_ASSERT_NOT_NULL(ll); }

void test_LinkedList_startLength(void) { TEST_ASSERT_EQUAL(0, ll->length); }

void test_LinkedList_startFirstNode(void) { TEST_ASSERT_EQUAL(0, ll->first); }

void test_LinkedList_startLastNode(void) { TEST_ASSERT_EQUAL(0, ll->last); }

void test_LinkedList_allocateMemoryElement(void) {
  TEST_ASSERT_NOT_NULL(create_new_element(1));
}

void test_LinkedList_createNewElementSetsValue(void) {
  TEST_ASSERT_EQUAL(2, create_new_element(2)->value);
}

void test_LinkedList_createNewElementHasNoNextNode(void) {
  TEST_ASSERT_EQUAL(0, create_new_element(3)->next);
}

void test_LinkedList_addInititalElementFirstNode(void) {
  listNode *new_element = create_new_element(4);
  add_initial_element(ll, new_element);
  TEST_ASSERT_EQUAL(new_element, ll->first);
}

void test_LinkedList_addInititalElementLastNode(void) {
  listNode *new_element = create_new_element(5);
  add_initial_element(ll, new_element);
  TEST_ASSERT_EQUAL(new_element, ll->last);
}

void test_LinkedList_addInititalElementLength(void) {
  listNode *new_element = create_new_element(6);
  add_initial_element(ll, new_element);
  TEST_ASSERT_EQUAL(1, ll->length);
}

void test_LinkedList_appendElementLinkToPreviousNode(void) {
  listNode *first_element = create_new_element(7);
  add_initial_element(ll, first_element);
  listNode *second_element = create_new_element(8);
  append_element(ll, second_element);
  TEST_ASSERT_EQUAL(second_element, first_element->next);
}

void test_LinkedList_appendElementLastNode(void) {
  listNode *first_element = create_new_element(9);
  add_initial_element(ll, first_element);
  listNode *second_element = create_new_element(10);
  append_element(ll, second_element);
  TEST_ASSERT_EQUAL(second_element, ll->last);
}

void test_LinkedList_appendElementLength(void) {
  listNode *first_element = create_new_element(11);
  add_initial_element(ll, first_element);
  listNode *second_element = create_new_element(12);
  append_element(ll, second_element);
  TEST_ASSERT_EQUAL(2, ll->length);
}

void test_LinkedList_isEmpty(void) { TEST_ASSERT_EQUAL(true, is_empty(ll)); }

void test_LinkedList_isNotEmpty(void) {
  listNode *first_element = create_new_element(13);
  add_initial_element(ll, first_element);
  TEST_ASSERT_EQUAL(false, is_empty(ll));
}

void test_LinkedList_addToEndLastNodeValue(void) {
  listNode *element_to_append = create_new_element(15);
  add_to_end(ll, element_to_append->value);
  TEST_ASSERT_EQUAL(15, ll->last->value);
}

void test_LinkedList_addToBeginFirstNodeValue(void) {
  listNode *first_element = create_new_element(16);
  add_initial_element(ll, first_element);
  add_to_begin(ll, 17);
  TEST_ASSERT_EQUAL(17, ll->first->value);
}

void test_LinkedList_addToBeginEmptyList(void) {
  add_to_begin(ll, 18);
  TEST_ASSERT_EQUAL(18, ll->first->value);
}

void test_LinkedList_addToBeginLinkedNextNode(void) {
  listNode *first_element = create_new_element(19);
  add_initial_element(ll, first_element);
  add_to_begin(ll, 20);
  TEST_ASSERT_EQUAL(first_element, ll->first->next);
}

void test_LinkedList_addToBeginLength(void) {
  add_to_begin(ll, 20);
  TEST_ASSERT_EQUAL(1, ll->length);
}
