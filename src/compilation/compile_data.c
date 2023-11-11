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
