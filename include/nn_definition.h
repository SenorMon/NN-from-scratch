#ifndef _NN_DEF
#define _NN_DEF

#define PATH_SIZE 256
#define INPUT_LAYER_SIZE 784
#define HIDDEN_LAYERS 2
#define HIDDEN_LAYER_SIZE 128
#define OUTPUT_LAYER_SIZE 10

#include <unistd.h>

typedef struct options{
    int epochs;
    int r_flag;
    int s_flag;
    char output_path[PATH_SIZE];
    char dataset_path[PATH_SIZE];
} options;

typedef struct neural_network{
    char act_function;
    float input_layer[INPUT_LAYER_SIZE];
    float** weights;
} neural_network;

#endif