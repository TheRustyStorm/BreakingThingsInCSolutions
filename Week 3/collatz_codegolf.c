#include <stdio.h>

void col(int n){
    printf("%i ", n);
    if(n == 1){
        printf("\n");
    }else{
        col(n % 2 == 0 ? n / 2 : n * 3 + 1);
    }
}

int main(void){ 
    col(37);
}