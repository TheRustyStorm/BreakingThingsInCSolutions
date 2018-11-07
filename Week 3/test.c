#include <stdio.h>


int input = 123127;

int isPrime(int number){
  for(int i = 2; i < number/2; i++){
    if(number % i == 0){
      return 0;
    }
  }
  return 1;
}

int counter(int number){
  int counter = 1;
  if(!isPrime(number)){
    return -1;
  }else{
    for(int i = 2; i < number; i++){
      if(isPrime(i)){
        counter++;
      } 
    }
    return counter;
  }
}


int main () {
  printf("%i\n", counter(input));

  return(0);
}
