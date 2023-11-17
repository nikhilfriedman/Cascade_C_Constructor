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

String_Node * create_string_node(char * val)
{
    String_Node * new_string_node = (String_Node *) malloc(sizeof(String_Node));

    new_string_node -> val  = val;
    new_string_node -> next = NULL;

    return new_string_node;
}

void free_string_list(String_Node * head)
{
    String_Node * temp = NULL;

    while(head != NULL)
    {
        temp = head -> next;
        free(head);
        head = temp;
    }
}

Function_Information_Tree * create_function_information_tree(Function_Information * func)
{
    Function_Information_Tree * new_function_information_tree = (Function_Information_Tree *) malloc(sizeof(Function_Information_Tree));

    new_function_information_tree -> id     = func -> id;
    new_function_information_tree -> height = -1;
    new_function_information_tree -> func   = func;
    new_function_information_tree -> left   = NULL;
    new_function_information_tree -> right  = NULL;

    return new_function_information_tree;
}

void function_tree_insert(Function_Information * func, Function_Information_Tree * root)
{
    if(root == NULL)
    {
        root = create_function_information_tree(func);
    } else if(func -> id < root -> id) {
        function_tree_insert(func, root -> left);
    } else if(func -> id > root -> id) {
        function_tree_insert(func, root -> right);
    } else {
        (func -> id)++;
        function_tree_insert(func, root);
    }
}