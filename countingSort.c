#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void populateArray(uint32_t *numbers, uint32_t size);
void printArray(uint32_t *numbers, uint32_t size);
uint32_t maximum(uint32_t *numbers, uint32_t size);
void countingSort(uint32_t *numbers, uint32_t size);

uint32_t main(void) {

  	uint32_t test1[ARRAY_SIZE];
  	uint32_t *ptr = test1;

  	populateArray(ptr, ARRAY_SIZE);
        countingSort(test1, ARRAY_SIZE);
  	//printArray(test1, ARRAY_SIZE);

  	return 0;
}

void populateArray(uint32_t *numbers, uint32_t size) {
	srand(time(NULL));

	for(uint32_t i = size - 1; i > 0; i--) {
		numbers[i] = rand() % ARRAY_SIZE;
	}
}

void printArray(uint32_t *numbers, uint32_t size) {

	for(uint32_t i = 0; i < size; i++) {
    	printf("%d, ", numbers[i]);
  	}
}

void countingSort(uint32_t *numbers, uint32_t size) {

  	uint32_t max = maximum(numbers, size);
  	uint32_t counting_array[size];
  	uint32_t *ptr_counting_array = counting_array; 
  	uint32_t i = 0;

  	for(uint32_t i = 0; i < size; i++) {
    	ptr_counting_array[numbers[i]]++;
  	}

  	uint32_t num = 0;
  	i = 0;

  	while(i <= size) {
    		while(counting_array[num] > 0) {
      			numbers[i] = num;
      			counting_array[num]--;
      			i++;
      			if(i > size){ break; }
    		}
    	num++;
  	}
}

uint32_t maximum(uint32_t *numbers, uint32_t size){

  	uint32_t i, max = 0;

  	for(i = 0; i < size; i++){
    		if(numbers[i] > max){ 
			max = numbers[i]; 
		}
  	}
  	return max;
}
