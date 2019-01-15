#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdlib.h>
#include <stdint.h>

typedef struct queue{
    int size;
    int maxSize;
    int* memory;
}queue;

void queue_create(queue** q, int maxSize, void* (*allocation)(size_t));
void enqueue(queue* q, int value);
void dequeue(queue* q);

#endif // _QUEUE_H
