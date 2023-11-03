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

    int id;

    int           num_inputs;
    struct Node * input_args;

    int output_type;
} Function_Information;

typedef struct Function {
    struct Function_Information * info;
    struct Function             * next;
} Function;

// compile_data.c
Node                 * create_node                (int val);
void                   free_list                  (Node * head);
Function_Information * create_function_information(char * name, int id, int num_inputs, Node * input_args, int output_type);
void                   free_function_information  (Function_Information * function);
#endif