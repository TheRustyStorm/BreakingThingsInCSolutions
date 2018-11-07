#include <stdio.h>
#include <stdint.h>

int addTwoInts(int a, int b){
    int c = a + b;
    return c;
}

float add(float a, float b){
    float c = a + b;
    return c;
}

int collatz(int num){
    if(num == 1){
        printf("\n");
        return 1;
    }
    if(num % 2 == 0){
        int newNum = num / 2;
        printf("%i ", newNum);
        return collatz(newNum);
    }else{
        int newNum = num * 3 + 1;
        printf("%i ", newNum);
        return collatz(newNum);
    }
}

int calculateSum(int num1, int num2){
    int sum = 0;
    if(num2 < num1){
        int temp = num2;
        num2 = num1;
        num1 = temp;
    }

    for(int i = num1 + 1; i < num2; i++){
        sum += i;
    }
    return sum;
}

void lowerCaseToUpperCase(char c){
    char newChar = c - (97 - 65);
    printf("%c \n", newChar);
}


int isPrime(int num){
	for(int i = 2; i <= num/2; i++){
		if(num%i == 0){
			return 1;
			break;
		}
	}
	return num;
}

void whichPrime(int number){
    int numa = 1;
    if(isPrime(number) != 1){
        printf("YES PRIME!! Its the -> ");
        for(int i = 3; i <= number; i++){
            if(isPrime(i) != 1){
                numa++;
            }
        }
        printf("%i",numa);
        printf("th one \n");
    }else{
        printf("Keine Primzahl! \n");
    }
}

uint8_t setNthBitToOne(uint8_t originalValue, uint8_t bitPosition){
    originalValue = originalValue | (1 << bitPosition);
    return originalValue;
}

uint8_t setNthBitToZero(uint8_t originalValue, uint8_t bitPosition){
    originalValue = originalValue & ~(1 << bitPosition);
    return originalValue;
}



int main(void){
    int number = 37;
    printf("Collatz: ");
    collatz(number);


    int secondNumber = 40;
    printf("Summe der Zahlen zwischen %i und %i", number, secondNumber);
    int sum = calculateSum(number, secondNumber);
    printf("%i \n", sum);


    char character = 'c';
    printf("Character klein: %c -> Character groß: ",character);
    lowerCaseToUpperCase(character);
    
    int num2 = 2;
    whichPrime(num2);


    uint8_t value = 11;
    printf("Value 1 vorher: %u \n", value);
    value = setNthBitToOne(value, 4);
    printf("Value 1 nachher: %u \n", value);


    uint8_t value2 = 241;
    printf("Value 2 vorher: %u \n", value2);
    value2 = setNthBitToZero(value2, 5);
    printf("Value 2 nachher: %u \n", value2);

}



