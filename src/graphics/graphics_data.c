#include "graphics_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "compile_manager.h"

Function_Block * create_function_block(int x, int y, int w, int h, Function * func)
{
    Function_Block * new_function_block = (Function_Block *) malloc(sizeof(Function_Block));

    new_function_block -> x    = x;
    new_function_block -> y    = y;
    new_function_block -> w    = w;
    new_function_block -> h    = h;
    new_function_block -> func = func;
    new_function_block -> next = NULL;

    return new_function_block;
}

void free_function_blocks(Function_Block * head)
{
    Function_Block * head_temp = NULL;

    while(head != NULL)
    {
        head_temp = head -> next;
        free(head);
        head = head_temp;
    }
}