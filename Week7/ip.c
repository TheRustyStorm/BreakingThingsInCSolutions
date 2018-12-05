#include <stdio.h>
#include <string.h>

int findDot(char *ip, int num){
  int count = 0;
  int index = 0;
  while(ip[index] != '\0'){
    if(ip[index] == '.'){
      if(num == count){
        return index;  
      }
      count++;
    } 
    index++;
  }
  return -1; 
}

int strtoi(char *ip, int start, int length){
  int x = 0;
  printf("Start: %i Length %i\n", start, length);
  int multiplier = 1;
  for(int i = 0; i < length; i++){
    x += multiplier * (ip[start+length - i - 1] - 48);
    multiplier *= 10;
  }
  printf("%i \n",x);
  return x;
}


int check(char *ip, int start, int end){
  int res = strtoi(ip, start, end - start);
  if(res >= 1 && res <= 255){
    return 1;
  }
  return 0;
}

int main (int argc, char **argv)
{
  char* ip = argv[1];
  printf("IP Adress to check: %s\n", ip);
  int d1 = findDot(ip, 0);
  int d2 = findDot(ip, 1);
  int d3 = findDot(ip, 2);
  int d4 = findDot(ip, 3);
  if(d4 != -1){
    printf("The IP Adress is too long\n");
    return 0;
  }
  if (d1 < 0 || d2 < 0 || d3 < 0){
    printf("The IP Adress is too short\n");
    return 0;
  }
  printf("Dots at %i %i %i \n",d1, d2, d3);
  if(check(ip,0, d1) && check(ip, d1+1, d2) && check(ip, d2+1, d3) && check(ip, d3+1, strlen(ip))){
    printf("%s is valid\n",ip);
  }else{
    printf("%s is not valid\n",ip);
  }
  return 0;
}
