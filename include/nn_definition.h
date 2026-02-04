#ifndef _NN_DEF
#define _NN_DEF

#define PATH_SIZE 256

#include <unistd.h>

typedef struct options{
    int epochs;
    int r_flag;
    int s_flag;
    char output_path[PATH_SIZE];
    char dataset_path[PATH_SIZE];
} options;


#endif