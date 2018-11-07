#include <stdio.h>
void c(int i){
  printf("%i ", i);
  if(i == 1){
    printf("\n");
    return;
  }
  c(i%2==0?i/2:i*3+1);
}
int main(void){
  c(17);
}
