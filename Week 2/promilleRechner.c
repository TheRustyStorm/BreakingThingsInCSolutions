#include <stdio.h>
#include <stdint.h>

const int vol_ml = 700;
const float vol_p = 88;
const int weight = 60;
const int gender = 1; // 0 for female

float alc_g = vol_ml * (vol_p / 100) * 0.8;
float promille;

int main(void){
    printf("%f\n", alc_g);
    if (gender == 0){
        promille = alc_g / (weight*0.55);
        printf("%f\n", promille);
    } else{
        promille = alc_g / (weight*0.68);
        printf("%f\n", promille);
    }
    return 0;
}
