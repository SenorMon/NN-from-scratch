#include <stdio.h>
#include <stdlib.h>

#include "c_unit.h"


float round_to_decimal_places(float number, int decimal_places){
    int rounded = (int) (number * pow(10, decimal_places) + 0.5);
    return rounded / (pow(10, decimal_places));
}

void assert_equals_float(float expected, float given, int decimal_places){
    float expected_rounded = round_to_decimal_places(expected, decimal_places);
    float given_rounded = round_to_decimal_places(given, decimal_places);

    if(expected_rounded == given_rounded){
        printf("[PASS]: Expected: %f / Given: %f\n", expected_rounded, given_rounded);
    }else{
        fprintf(stderr, "[FAIL]: Expected: %f / Given: %f\n", expected_rounded, given_rounded);
    }
}

