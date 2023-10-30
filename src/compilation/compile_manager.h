#ifndef __COMPILE_MANAGER_H__
#define __COMPILE_MANAGER_H__

typedef struct Inclusions {
    char             * inclusion;
    struct Inclusion * next;
} Inclusion;

typedef struct Node {
    int           val;
    struct Node * next;
} Node;

typedef struct Function_Information {
    char * name;

    int           num_inputs;
    struct Node * input_args;

    int           num_outputs;
    struct Node * output_args;
} Function_Information;


#endif