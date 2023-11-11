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

typedef struct String_Node {
    char               * val;
    struct String_Node * next;
} String_Node;

typedef struct Function_Information {
    char * name;

    int id;

    int           num_inputs;
    struct Node * input_args;

    int output_type;
} Function_Information;

typedef struct Function {
    struct Function_Information * info;
    struct String_Node          * args;
    struct Function             * next;
} Function;

// compile_data.c
Node                 * create_node                (int val);
void                   free_list                  (Node * head);

#endif