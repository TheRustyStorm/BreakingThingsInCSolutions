//Peter
#include <stdio.h>
#include <stdint.h>

int main(void){
  uint16_t num = 25;
  uint8_t size = 8*sizeof(num);
  for(int i = 0; i < size; i++){
    if(num / (1<<(size - 1))){
      printf("1"); 
    }else{
      printf("0"); 
    }
    num = num << 1;
  }
  printf("\n");
  
}

