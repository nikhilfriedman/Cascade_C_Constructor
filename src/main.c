#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "graphics_manager.h"

static void print_tree(Function_Information * root)
{
    if(root != NULL)
    {
        print_tree(root -> left);

        printf("\n%d %s", root -> function_id, root -> function_name);

        print_tree(root -> right);
    }
}

int main(int argc, char ** argv)
{
    Function_Information * root = NULL;

    insert_function_information(0, "x", NULL, &root);
    insert_function_information(1, "y", NULL, &root);
    insert_function_information(2, "z", NULL, &root);
    insert_function_information(3, "p", NULL, &root);
    insert_function_information(4, "d", NULL, &root);
    insert_function_information(5, "q", NULL, &root);
    insert_function_information(6, "a", NULL, &root);
    insert_function_information(7, "l", NULL, &root);

    print_tree(root);

    // graphics_loop();

    return EXIT_SUCCESS;
}