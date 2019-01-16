#include "build/temp/_test_LinkedList.c"
#include "unity.h"
#include "LinkedList.h"






linkedList *ll = 

                ((void *)0)

                    ;



void setUp(void) { ll = create_linked_list(); }



void tearDown(void) { free(ll); }



void test_LinkedList_allocateMemoryList(void) { if ((((ll)) != 

                                               ((void *)0)

                                               )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(12))));}; }



void test_LinkedList_startLength(void) { UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ll->length)), (

                                        ((void *)0)

                                        ), (UNITY_UINT)(14), UNITY_DISPLAY_STYLE_INT); }



void test_LinkedList_startFirstNode(void) { UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ll->first)), (

                                           ((void *)0)

                                           ), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_INT); }



void test_LinkedList_startLastNode(void) { UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ll->last)), (

                                          ((void *)0)

                                          ), (UNITY_UINT)(18), UNITY_DISPLAY_STYLE_INT); }



void test_LinkedList_allocateMemoryElement(void) {

  if ((((create_new_element(1))) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(21))));};

}



void test_LinkedList_createNewElementSetsValue(void) {

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((create_new_element(2)->value)), (

 ((void *)0)

 ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_createNewElementHasNoNextNode(void) {

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((create_new_element(3)->next)), (

 ((void *)0)

 ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_addInititalElementFirstNode(void) {

  listNode *new_element = create_new_element(4);

  add_initial_element(ll, new_element);

  UnityAssertEqualNumber((UNITY_INT)((new_element)), (UNITY_INT)((ll->first)), (

 ((void *)0)

 ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_addInititalElementLastNode(void) {

  listNode *new_element = create_new_element(5);

  add_initial_element(ll, new_element);

  UnityAssertEqualNumber((UNITY_INT)((new_element)), (UNITY_INT)((ll->last)), (

 ((void *)0)

 ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_addInititalElementLength(void) {

  listNode *new_element = create_new_element(6);

  add_initial_element(ll, new_element);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ll->length)), (

 ((void *)0)

 ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_appendElementLinkToPreviousNode(void) {

  listNode *first_element = create_new_element(7);

  add_initial_element(ll, first_element);

  listNode *second_element = create_new_element(8);

  append_element(ll, second_element);

  UnityAssertEqualNumber((UNITY_INT)((second_element)), (UNITY_INT)((first_element->next)), (

 ((void *)0)

 ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_appendElementLastNode(void) {

  listNode *first_element = create_new_element(9);

  add_initial_element(ll, first_element);

  listNode *second_element = create_new_element(10);

  append_element(ll, second_element);

  UnityAssertEqualNumber((UNITY_INT)((second_element)), (UNITY_INT)((ll->last)), (

 ((void *)0)

 ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_appendElementLength(void) {

  listNode *first_element = create_new_element(11);

  add_initial_element(ll, first_element);

  listNode *second_element = create_new_element(12);

  append_element(ll, second_element);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((ll->length)), (

 ((void *)0)

 ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_isEmpty(void) { UnityAssertEqualNumber((UNITY_INT)((

                                    1

                                    )), (UNITY_INT)((is_empty(ll))), (

                                    ((void *)0)

                                    ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT); }



void test_LinkedList_isNotEmpty(void) {

  listNode *first_element = create_new_element(13);

  add_initial_element(ll, first_element);

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((is_empty(ll))), (

 ((void *)0)

 ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_addToEndLastNodeValue(void) {

  listNode *element_to_append = create_new_element(15);

  add_to_end(ll, element_to_append->value);

  UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((ll->last->value)), (

 ((void *)0)

 ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_addToBeginFirstNodeValue(void) {

  listNode *first_element = create_new_element(16);

  add_initial_element(ll, first_element);

  add_to_begin(ll, 17);

  UnityAssertEqualNumber((UNITY_INT)((17)), (UNITY_INT)((ll->first->value)), (

 ((void *)0)

 ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_addToBeginEmptyList(void) {

  add_to_begin(ll, 18);

  UnityAssertEqualNumber((UNITY_INT)((18)), (UNITY_INT)((ll->first->value)), (

 ((void *)0)

 ), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_addToBeginLinkedNextNode(void) {

  listNode *first_element = create_new_element(19);

  add_initial_element(ll, first_element);

  add_to_begin(ll, 20);

  UnityAssertEqualNumber((UNITY_INT)((first_element)), (UNITY_INT)((ll->first->next)), (

 ((void *)0)

 ), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);

}



void test_LinkedList_addToBeginLength(void) {

  add_to_begin(ll, 20);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ll->length)), (

 ((void *)0)

 ), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);

}
