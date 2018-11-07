#include <stdio.h>

int main(void){

  int primeNumber = 16;
  int divisors = 0;

  for(int i = 2; i < primeNumber; i++){
    if(primeNumber % i == 0){
      divisors++; 
      break;
    } 
    printf("%i\n",i);
  }

  if(divisors == 0){
    printf("%i is prime\n",primeNumber);
  }else{
    printf("%i is not prime\n",primeNumber);
  }
}
