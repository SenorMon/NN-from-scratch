#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nn_definition.h"
#include "nn_math.h"

char* synopsis = "./train [-e epochs] [-r ReLU | -s sigmoid] [-o output path] DATASET_PATH";

/**
    This function is used when encountering an error while parsing
    arguments. It exits the programming with EXIT_FAILURE.
*/
void parse_fail_exit(char* msg){
    fprintf(stderr, "%s, Synopsis: %s\n", msg, synopsis);
    exit(EXIT_FAILURE);
}

/**
    This function initializes the CLI options. 
*/
options* initialize_options(){
    options* option_holder = malloc(sizeof(options));
    option_holder->epochs = -1;
    option_holder->r_flag = 0;
    option_holder->s_flag = 0;

    strncpy(option_holder->output_path, "output.data", PATH_SIZE - 1);
    option_holder->output_path[PATH_SIZE - 1] = '\0';

    return option_holder;
}

/**
    debug function for printing the options
*/
void print_options(options* options){
    printf("Epochs: %d\n", options->epochs);
    printf("R-Flag: %d\n", options->r_flag);
    printf("S-Flag: %d\n", options->s_flag);
    printf("Output: %s\n", options->output_path);
    printf("Dataset: %s\n", options->dataset_path);
}


/**
    The following function is used to initialize
    the neural network struct (memory allocation mainly).
*/
neural_network* initialize_nn(options* options){
    neural_network* nn = malloc(sizeof(neural_network)); 
    nn->act_function = (options->r_flag) ? 'r' : 's';

    //allocating memory for the weights pointer with 3 matrices
    nn->weights = malloc((HIDDEN_LAYERS + 1) * sizeof(float*));
    
    //allocating memory for matrix between input and first hidden layer
    nn->weights[0] = malloc(INPUT_LAYER_SIZE * HIDDEN_LAYER_SIZE * sizeof(float));

    //allocating memory between hidden layers
    for(int i = 1; i < HIDDEN_LAYERS; i++){
        nn->weights[i] = malloc(HIDDEN_LAYER_SIZE * HIDDEN_LAYER_SIZE * sizeof(float));
    }

    //allocating memory for the matrix between last hidden layer and output layer
    nn->weights[HIDDEN_LAYERS] = malloc(HIDDEN_LAYER_SIZE * OUTPUT_LAYER_SIZE * sizeof(float));

    return nn;
}

/**
    The following function initializes the nn with random
    weights between -1 and 1
*/
void weight_initialization(neural_network* nn){
    for(int i = 0; i < INPUT_LAYER_SIZE; i++){
        for(int j = 0; j < HIDDEN_LAYER_SIZE; j++){
            nn->weights[0][i * HIDDEN_LAYER_SIZE + j] = random_weight();
        }
    }

    for(int i = 1; i < HIDDEN_LAYERS; i++){
        for(int j = 0; j < HIDDEN_LAYER_SIZE; j++){
            for(int k = 0; k < HIDDEN_LAYER_SIZE; k++){
                nn->weights[i][j * HIDDEN_LAYER_SIZE + k] = random_weight();
            }
        }
    }

    for(int i = 0; i < HIDDEN_LAYER_SIZE; i++){
        for(int j = 0; j < OUTPUT_LAYER_SIZE; j++){
            nn->weights[HIDDEN_LAYERS][i * HIDDEN_LAYER_SIZE + j] = random_weight();
        }
    }
}

void free_nn(neural_network* nn){
    if(nn == NULL) return;

    for(int i = 0; i < HIDDEN_LAYERS + 1; i++){
        free(nn->weights[i]);
    }

    free(nn->weights);
    free(nn);
}


/*
    Synopsis: ./train [-e epochs] [-r ReLU | -s sigmoid] [-o output path] DATASET_PATH
*/
int main(int argc, char* argv[]){
    options* options = initialize_options();

    int opt;
    while((opt = getopt(argc, argv, "e:rso:")) != -1){
        switch(opt){
            case 'e':
                if(options->epochs == -1){
                    options->epochs = strtol(optarg, NULL, 10);
                }else{
                    parse_fail_exit("epochs already set");
                }

                break;
            case 'r':
                options->r_flag = 1;
                break;
            case 's':
                options->s_flag = 1;
                break;
            case 'o':
                strncpy(options->output_path, optarg, PATH_SIZE - 1);
                options->output_path[PATH_SIZE - 1] = '\0';
                break;
            case '?':
                parse_fail_exit("unknown character");
                break;
        }
    }

    //MAKE SURE THAT THE INPUTTED DATA IS VALID 
    if(options->epochs <= 0){
        parse_fail_exit("epochs must be > 0");
    }

    if(options->r_flag && options->s_flag){
        parse_fail_exit("can't use ReLU and Sigmoid activation function");
    }

    if(strcmp(options->output_path, "") == 0){
        parse_fail_exit("empty output_path");
    }

    if((argc - optind) <= 0){
        parse_fail_exit("no dataset path given");
    }else{
        strncpy(options->dataset_path, argv[optind], PATH_SIZE - 1);
        options->dataset_path[PATH_SIZE - 1] = '\0';
    }

    neural_network* nn = initialize_nn(options);

    free_nn(nn);
    free(options);
    return EXIT_SUCCESS;
}