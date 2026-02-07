#include <stdio.h>
#include "nn_math.h"
#include "c_unit.h"


int main(){
    printf("UNIT TESTS FOR NN_MATH:\n");
    printf("DOT PRODUCT TESTS: \n");
    float v1[] = {0.1, 3, 5};
    float v2[] = {0, -5, 3};
    float v3[] = {-3, 1, 10};

    int seed = time(NULL);
    srand(seed);

    //positive tests
    assert_equals_float(0.f, dot_product(v1, v2, 3), 3);
    assert_equals_float(52.7f, dot_product(v1, v3, 3), 3);
    assert_equals_float(25.f, dot_product(v2, v3, 3), 3);

    printf("SIGMOID FUNCTION TEST: \n");
    assert_equals_float(0.01798620996209f, sigmoid(-4.), 6);
    assert_equals_float(0.5f, sigmoid(0), 6);
    assert_equals_float(0.9999546021313f, sigmoid(10), 6);

    printf("ReLU FUNCTION TEST: \n");
    assert_equals_float(0.05f, ReLU(0.05f), 3);
    assert_equals_float(0, ReLU(-0.05f), 3);
    assert_equals_float(3, ReLU(3), 3);

    printf("RANDOM WEIGHT FUNCTION TEST: \n");
    for(int i = 0; i < 100; i++){
        float random_float = random_weight();
        printf("Random float: %f\n", random_float);
        assert_true(random_float >= -1 && random_float <= 1);
    }

    return EXIT_SUCCESS;
}