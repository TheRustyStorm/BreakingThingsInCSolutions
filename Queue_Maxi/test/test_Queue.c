#include "unity.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdint.h>

queue* q = NULL;
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
    TEST_ASSERT_EQUAL(0, allocationCount);
}

void test_queue(void){
    TEST_ASSERT_NOT_NULL(q);
}

void test_queueSize0(void){
    TEST_ASSERT_EQUAL(0, q->size);
}

void test_allocationMemory(void){
    TEST_ASSERT_NOT_NULL(q->memory);
}

void test_queueSizeIncreasedAfterEnqueue(void){
    enqueue(q, 2);
    TEST_ASSERT_EQUAL(1,q->size);
}

void test_queueSizeIncreasedAfterTwoEnqueue(void){
    enqueue(q, 2);
    enqueue(q, 3);
    TEST_ASSERT_EQUAL(2,q->size);
}

void test_maxQueueAdded(void){
    for(int i = 0; i < 300; i++){
        enqueue(q, i);
    }
    TEST_ASSERT_EQUAL(q->maxSize, q->size);
}

void test_addToQueue(void){
    enqueue(q, 2);
    enqueue(q, 2);
    TEST_ASSERT_EQUAL(2, q->memory[q->maxSize - q->size]);
}

void test_removeFromQueue(void){
    enqueue(q, 1);
    enqueue(q, 2);
    dequeue(q);
    TEST_ASSERT_EQUAL(1, q->memory[q->maxSize - q->size]);
}

void test_queueSizeDecreased(void){
    enqueue(q, 1);
    enqueue(q, 2);
    dequeue(q);
    TEST_ASSERT_EQUAL(1, q->size);
}

void test_doNotRemoveToMuch(void){
    for(int i = 0; i < 90; i++){
        enqueue(q, i);
    }
    for(int i = 0; i < 100; i++){
        dequeue(q);
    }
    TEST_ASSERT_EQUAL(0, q->size);
}

