#include "build/temp/_test_Queue.c"
#include "Queue.h"
#include "unity.h"






queue* q = 

          ((void *)0)

              ;

uint16_t allocationCount = 0;



void* safeMalloc(size_t size){

    allocationCount++;

    return malloc(size);

}



void safeFree(void* ptr){

    allocationCount--;

    free(ptr);

}



void setUp(void)

{

    queue_create(&q, 256, safeMalloc);

}



void tearDown(void)

{

    safeFree(q->memory);

    safeFree(q);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((allocationCount)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

}



void test_queue(void){

    if ((((q)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(32))));};

}



void test_queueSize0(void){

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((q->size)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}



void test_allocationMemory(void){

    if ((((q->memory)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(40))));};

}



void test_queueSizeIncreasedAfterEnqueue(void){

    enqueue(q, 2);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((q->size)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

}



void test_queueSizeIncreasedAfterTwoEnqueue(void){

    enqueue(q, 2);

    enqueue(q, 3);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((q->size)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

}



void test_maxQueueAdded(void){

    for(int i = 0; i < 300; i++){

        enqueue(q, i);

    }

    UnityAssertEqualNumber((UNITY_INT)((q->maxSize)), (UNITY_INT)((q->size)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

}



void test_addToQueue(void){

    enqueue(q, 2);

    enqueue(q, 2);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((q->memory[q->maxSize - q->size])), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

}



void test_removeFromQueue(void){

    enqueue(q, 1);

    enqueue(q, 2);

    dequeue(q);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((q->memory[q->maxSize - q->size])), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

}



void test_queueSizeDecreased(void){

    enqueue(q, 1);

    enqueue(q, 2);

    dequeue(q);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((q->size)), (

   ((void *)0)

   ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT);

}



void test_doNotRemoveToMuch(void){

    for(int i = 0; i < 90; i++){

        enqueue(q, i);

    }

    for(int i = 0; i < 100; i++){

        dequeue(q);

    }

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((q->size)), (

   ((void *)0)

   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

}
