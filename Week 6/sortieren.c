#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 100000
int array1[ARRAY_LENGTH];

void tauschen(int *x, int *y){
    int a = *x;
    *x = *y;
    *y = a;
}

int sortieren(int *l){
    for (int i = 0 ; i < ARRAY_LENGTH - 1 ; i++){
        for (int j = 0 ; j < ARRAY_LENGTH - i - 1; j++){
            if (l[j] > l[j+1]){
                tauschen(&l[j], &l[j+1]);
            }
        }
    }
    return 0;
}

void ausgabe(int* l){
    for (int i = 0 ; i < ARRAY_LENGTH ; i++){
        printf("%i ", l[i]);
    }
    printf("\n");
}

int main(){
    for (int i = 0 ; i < ARRAY_LENGTH ; i++){
        array1[i] = rand() % ARRAY_LENGTH;
    }
//    ausgabe(array1, length);
    sortieren(array1);
//    ausgabe(array1);

    return 0;
}
