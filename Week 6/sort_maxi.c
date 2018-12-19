#include <stdio.h>
#include <stdlib.h>

inline void swap(int* left, int* right){
    int temp = *left;
    *left = *right;
    *right = temp;
}

int partition(int* array, int left, int right){
    int pivot = *(array + right);
    int i = (left - 1);

    for(int j = left; j < right; j++){
        if(*(array + j) < pivot){
            i++;
            swap(array + i, array + j);
        }
    }
    swap(array + i + 1, array + right); 
    return (i + 1);
}

void quicksort(int *array, int left, int right){
    if(left < right){
        int index = partition(array, left, right);
        quicksort(array, left, index - 1);
        quicksort(array, index + 1, right);
    }
}


void printArray(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%i ", *(array + i));
    }
    printf("\n");
}

void bubbleSort(int* a, int size){
    int temp;
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size - 1 - i; ++j ){
            if (a[j] > a[j+1]){
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
           }
      }
    }
    //for(int i = 0; i < size; i++){
    //    printf("%i ", a[i]);
    //}
    //printf("\n");
}

int main(void){
    int array[] = {4, 7, 14, 2, 1, 5, 8, 3, 9};
    int n = sizeof(array) / sizeof(int);
    
    int bigArray[1000000];
    double sizeOfBigArray = sizeof(bigArray) / sizeof(int);
    for(int i = 0; i < 1000000; i++){
        bigArray[i] = rand();
    }
    
    quicksort(bigArray, 0, sizeOfBigArray - 1);
    //bubbleSort(bigArray, sizeOfBigArray);   
    printArray(bigArray, sizeOfBigArray);
}
