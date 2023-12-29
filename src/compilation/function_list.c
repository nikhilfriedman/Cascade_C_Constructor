#include "compile_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node * create_node(void * val)
{
    Node * new_node = (Node *) malloc(sizeof(Node));

    new_node -> val  = val;
    new_node -> next = NULL;

    return new_node;
}

bool free_list(Node * head)
{
    Node * current = head;
    Node * next    = NULL;

    while(current != NULL)
    {
        next = current -> next;
        free(current);
        current = next;
    }
}