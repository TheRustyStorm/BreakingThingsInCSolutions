#include <stdio.h>
#include <stdlib.h>

void tauschen(int *x, int *y){
    int a = *x;
    *x = *y;
    *y = a;
}

int sortieren(int *l, int length){
    int x = 0;
    for (int i = 0 ; i < length - 1 ; i++){
        for (int j = 0 ; i < length - i - 1; i++){
            if (l[j] > l[j+1]){
                tauschen(&l[j], &l[j+1]);
            }
        }
    }
    return 0;
}

int ausgabe(int* l, int length){
    for (int i = 0 ; i < length ; i++){
        printf("%i ", l[i]);
    }
    printf("\n");
}

int main(){
    int length = 10;
    int array1[length];
    for (int i = 0 ; i < length ; i++){
        array1[i] = rand() % 10;
    }
    ausgabe(array1, length);
    sortieren(array1, length);
    ausgabe(array1, length);

    return 0;
}
