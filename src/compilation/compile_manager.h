#ifndef __COMPILE_MANAGER_H__
#define __COMPILE_MANAGER_H__

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

typedef struct Function_Information_Tree {
    int id;
    int height;
    
    struct Function_Information      * func;
    struct Function_Information_Tree * left;
    struct Function_Information_Tree * right;
} Function_Information_Tree;

typedef struct Function {
    int x;
    int y;
    int w;
    int h;

    struct Function_Information * info;
    struct String_Node          * args;
    struct Function             * next;
} Function;

// compile_data.c
Node                      * create_node                     (int val);
void                        free_list                       (Node * head);
String_Node               * create_string_node              (char * val);
void                        free_string_list                (String_Node * head);
Function_Information_Tree * create_function_information_tree(Function_Information * func);
void                        function_tree_insert            (Function_Information * func, Function_Information_Tree * root);

#endif