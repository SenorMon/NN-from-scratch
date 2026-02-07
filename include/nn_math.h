#ifndef _NN_MATH
#define _NN_MATH

#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
    The following functions defines the dot product of two vectors v1 and v2.
*/
float dot_product(float* v1, float* v2, int n);


//Definition of activation functions
float sigmoid(float x);
float ReLU(float x);

//random weight initialization
float random_weight();


#endif