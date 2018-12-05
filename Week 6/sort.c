#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define AMOUNT_NUMBERS 1000000
int numbers[AMOUNT_NUMBERS];

void printArr()
{
    for (int i = 0; i < AMOUNT_NUMBERS; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}

void validate()
{
    for (int i = 0; i < AMOUNT_NUMBERS - 1; i++)
    {
        if (numbers[i + 1] < numbers[i])
        {
            printf("FALSCH: %i > %i \n", numbers[i + 1], numbers[i]);
        }
    }
}

inline void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void quicksort2(int *numbers, int first, int last){
    int left = first;
    int right = last;
    int pivot = numbers[first];
    while(left <= right){
        while(numbers[left] < pivot){
            left++;
        }
        while(numbers[right] > pivot){
            right--;
        }
        if(left <= right){
            swap(&numbers[left], &numbers[right]);
            left++;
            right--;
        }
    }
    if(left < last){
        quicksort2(numbers, left, last);
    }
    if(right > first){
        quicksort2(numbers, first, right);
    }
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));

    for (int i = 0 ;  i < AMOUNT_NUMBERS; i++)
    {
        numbers[i] = rand();
    }
    quicksort2(numbers, 0, AMOUNT_NUMBERS - 1);
    validate();
    return 0;
}
