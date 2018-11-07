#include <stdio.h>

int main(void){
  int first = 0;
  int second = 1;
  while(second > first){
    first++;
    second++;
  }
  printf("%i\n", first);
  return 0;
}
