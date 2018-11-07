#include <stdio.h>

void collatz(int in){
  printf("%i ", in);
  if(in == 1){
    printf("\n");
    return;
  }
  collatz(in % 2 == 0 ? in >> 1 : in * 3 + 1);
}

int main(void){
  collatz(17);
}


