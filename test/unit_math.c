#include <stdio.h>
#include "nn_math.h"
#include "c_unit.h"


int main(){
    printf("UNIT TESTS FOR NN_MATH:\n");
    float v1[] = {0.1, 3, 5};
    float v2[] = {0, -5, 3};
    float v3[] = {-3, 1, 10};

    //positive tests
    assertEquals(0.f, dot_product(v1, v2, 3));
    assertEquals(52.7f, dot_product(v1, v3, 3));
    assertEquals(25.f, dot_product(v2, v3, 3));


    return EXIT_SUCCESS;
}