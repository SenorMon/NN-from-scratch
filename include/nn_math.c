#include "nn_math.h"

#include <stdio.h>

float dot_product(float* v1, float* v2, int n){
    float result = 0.f;
    for(int i = 0; i < n; i++){
        result += (v1[i] * v2[i]);
    }

    return result;
}