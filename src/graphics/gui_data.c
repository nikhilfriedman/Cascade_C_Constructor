#include "graphics_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

Function_Block * create_function_block(int x, int y, int w, int h, char * name)
{
    Function_Block * new_function_block = (Function_Block *) malloc(sizeof(Function_Block));

    new_function_block -> x = x;
    new_function_block -> y = y;
    new_function_block -> w = w;
    new_function_block -> h = h;
    new_function_block -> name = name;
    new_function_block -> next = NULL;

    return new_function_block;
}

void free_function_blocks(Function_Block * head)
{
    while(head != NULL)
    {
        Function_Block * block_temp = head;
        head = head -> next;

        if(block_temp -> info != NULL)
        {
            free(block_temp -> info -> name);

            Node * node_temp = block_temp -> info -> input_args;
            Node * node_temp_temp;
            while(node_temp != NULL)
            {
                node_temp_temp = node_temp -> next;
                free(node_temp);

                node_temp = node_temp_temp;
            }

            node_temp = block_temp -> info -> output_args;
            while(node_temp != NULL)
            {
                node_temp_temp = node_temp -> next;
                free(node_temp);

                node_temp = node_temp_temp;
            }

            free(block_temp -> info);
        }

        free(block_temp);


    }
}