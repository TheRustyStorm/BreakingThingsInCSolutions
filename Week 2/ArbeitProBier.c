#include <stdio.h>

int main(){
    float bierPreis = 2.50;
    float stundenLohn = 10.50;
    float bierProSekunde = 0;
    float bierProStunde = 0;
    float sekundenProBier = 0;

    bierProStunde = stundenLohn/bierPreis;
    bierProSekunde = bierProStunde/3600;
    printf("%f %f ", bierProStunde, bierProSekunde);
    sekundenProBier = 1/bierProSekunde;
    printf("Du musst %f Sekunden arbeiten füt ein Bier.", sekundenProBier);

    return 0;
}

//von Lukas
