#include "compile_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node * create_node(int val)
{
    Node * new_node = (Node *) malloc(sizeof(Node));

    new_node -> val  = val;
    new_node -> next = NULL;

    return new_node;
}

void free_list(Node * head)
{
    Node * temp = NULL;

    while(head != NULL)
    {
        temp = head -> next;
        free(head);
        head = temp;
    }
}

Function_Information * create_function_information(char * name, int id, int num_inputs, Node * input_args, int output_type)
{
    Function_Information * new_function_information = (Function_Information *) malloc(sizeof(Function_Information));

    new_function_information -> name        = name;
    new_function_information -> id          = id;
    new_function_information -> num_inputs  = num_inputs;
    new_function_information -> input_args  = input_args;
    new_function_information -> output_type = output_type;

    return new_function_information;
}

void free_function_information(Function_Information * function)
{
    free(function -> name);

    Node * temp = NULL;
    while(function -> input_args != NULL)
    {
        temp = function -> input_args -> next;
        free(function -> input_args);
        function -> input_args = temp;
    }

    free(function);
}