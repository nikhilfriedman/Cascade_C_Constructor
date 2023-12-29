#ifndef __COMPILE_MANAGER_H__
#define __COMPILE_MANAGER_H__

#include <stdbool.h>

typedef struct Node {
    void        * val;  // value
    struct Node * next; // next node
} Node;

typedef struct Argument {
    int    type;    // data type
    bool   pointer; // pointer to?
    bool   address; // address of?
    char * name;    // name of argument
} Argument;

typedef struct Function_Information {
    int    function_id;   // identifier for insert/search
    char * function_name; // name of function
    int    height;        // avl tree height

    struct Node                 * arguments; // expected arguments
    struct Function_Information * left;      // left subtree
    struct Function_Information * right;     // right subtree
} Function_Information;

typedef struct Function {
    struct Function_Information * function_information; // expected arguments, etc.
    struct Node                 * arguments;            // given arguements
    struct Function             * next;                 // next function 
} Function;

// function_list.c
Node * create_node(void * val)
bool   free_list  (Node * head)

// function_information.c


#endif