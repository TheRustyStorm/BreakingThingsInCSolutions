#include "Queue.h"

void queue_create(queue** q, int maxSize, void* (*allocation)(size_t)){
    *q = (queue*)(allocation)(sizeof(queue));
    queue* que = *q;
    que->size = 0;
    que->maxSize = 256;
    que->memory = allocation(maxSize * sizeof(int)); 
}

void enqueue(queue* q, int value){
    if(q->size < q->maxSize){
        q->memory[q->maxSize - q->size - 1] = value;
        q->size++;
    }
}

void dequeue(queue* q){
    if(q->size > 0){
        q->memory[q->maxSize - q->size - 1] = q->memory[q->maxSize - q->size - 2];
        q->size--;
    }
}
