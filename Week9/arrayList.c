#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ArrayList{
  int index;
  int capacity;
  int *ptr;
} ArrayList;

ArrayList* create(int capacity){
  int *ptr = malloc(capacity * sizeof(int));
  ArrayList* list = malloc(sizeof(ArrayList));
  list->index = 0;
  list->capacity = capacity;
  list->ptr = ptr;
  return list;
}

void append(ArrayList *list, int element){
  if(list->index == list->capacity){
    list->ptr = realloc(list->ptr, 2*list->capacity * sizeof(int));
    list->capacity = list->capacity * 2;
  }
    list->ptr[list->index] = element;
    list->index++;
}

void removeElement(ArrayList *list, int index){
  printf("Removing %i\n", list->ptr[index]);
  for(int i = index; i < list->index; i++){
    list->ptr[i] = list->ptr[i + 1]; 
  }
  list->ptr[list->index] = 0;
  list->index--;
}

int getElement(ArrayList *list, int index){
  return list->ptr[index];
}

int size(ArrayList *list){
  return list->index;
}

void deleteList(ArrayList *list){
  free(list->ptr);
  free(list);
}

int main(void){
    ArrayList* list = create(20);
    for(int i = 0; i < 30; i++){
      append(list, i);
      printf("%i %i\n", list->ptr[i], list->capacity);
    }
    removeElement(list, 20);
    for(int i = 0; i < 30; i++){
      printf("%i\n", list->ptr[i]);
    }
    printf("%i\n", getElement(list, 10));
    deleteList(list);
}
