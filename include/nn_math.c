#include "nn_math.h"

#include <stdio.h>

float dot_product(float* v1, float* v2, int n){
    float result = 0.f;
    for(int i = 0; i < n; i++){
        result += (v1[i] * v2[i]);
    }

    return result;
}

float sigmoid(float x){
    return 1/(1 + exp(-x));
}

float ReLU(float x){
    return fmax(0, x);
}

/**
    This function calculates a random float between
    -1 and 1 used for initializing the weights of the matrices.
*/
float random_weight(){
    return (1 - (-1)) * ((((float) rand()) / (float) RAND_MAX)) + (-1);
}