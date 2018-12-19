#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000000

void populateArray(uint32_t *numbers);
void printArray(uint32_t *numbers);
uint32_t maximum(uint32_t *numbers);
void countingSort(uint32_t *numbers);

uint32_t test1[ARRAY_SIZE];
uint32_t counting_array[ARRAY_SIZE];

int main(void) {

  	uint32_t *ptr = test1;

  	populateArray(ptr);
    countingSort(test1);
  	//printArray(test1, ARRAY_SIZE);

  	return 0;
}

void populateArray(uint32_t *numbers) {
	srand(time(NULL));

	for(uint32_t i = ARRAY_SIZE - 1; i > 0; i--) {
		numbers[i] = rand() % ARRAY_SIZE;
	}
}

void printArray(uint32_t *numbers) {

	for(uint32_t i = 0; i < ARRAY_SIZE; i++) {
    	printf("%d, ", numbers[i]);
  	}
}

void countingSort(uint32_t *numbers) {

  	uint32_t max = maximum(numbers);
  	uint32_t *ptr_counting_array = counting_array; 
  	uint32_t i = 0;

  	for(uint32_t i = 0; i < ARRAY_SIZE; i++) {
    	ptr_counting_array[numbers[i]]++;
  	}

  	uint32_t num = 0;
  	i = 0;

  	while(i <= ARRAY_SIZE) {
    		while(counting_array[num] > 0) {
      			numbers[i] = num;
      			counting_array[num]--;
      			i++;
      			if(i > ARRAY_SIZE){ break; }
    		}
    	num++;
  	}
}

uint32_t maximum(uint32_t *numbers){

  	uint32_t i, max = 0;

  	for(i = 0; i < ARRAY_SIZE; i++){
    		if(numbers[i] > max){ 
			max = numbers[i]; 
		}
  	}
  	return max;
}
