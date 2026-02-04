#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "nn_definition.h"


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

    print_options(options);

    free(options);
    return EXIT_SUCCESS;
}