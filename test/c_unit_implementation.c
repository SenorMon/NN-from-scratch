#include <stdio.h>
#include <stdlib.h>

#include "c_unit.h"

void assertEquals(float expected, float given){
    if(expected == given){
        printf("[PASS]: Expected: %f / Given: %f\n", expected, given);
    }else{
        fprintf(stderr, "[FAIL]: Expected: %f / Given: %f\n", expected, given);
    }
}

