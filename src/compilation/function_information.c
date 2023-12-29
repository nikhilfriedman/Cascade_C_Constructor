#include "compile_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insert_function_information(int function_id, char * function_name, Node * arguments, Function_Information * root)
{
    if(root == NULL)
    {
        create_function_information_node(function_id, function_name, arguments, root);
    }
    else if(function_id < (root -> function_id))
    {
        insert_function_information(function_id, function_name, arguments, root -> left);
        update_height(root);

        if(get_balance_score(root) == 2)
        {
            balance_after_insert_in_left(function_id, root);
        }
    }
    else if(function_id > (root -> function_id))
    {
        insert_function_information(function_id, function_name, arguments, root -> right);
        update_height(root);

        if(get_balance_score(root) == -2)
        {
            balance_after_insert_in_right(function_id, root);
        }
    }
}

void free_function_information_tree(Function_Information * root)
{
    if(root != NULL)
    {
        free_function_information_tree(root -> left);
        free_function_information_tree(root -> right);
        free(root);
    }
}

static void create_function_information_node(int function_id, char * function_name, Node * arguments, Function_Information * root)
{
    root = (Function_Information *) malloc(sizeof(Function_Information));

    root -> function_id   = function_id;
    root -> function_name = function_name;
    root -> arguments     = arguments;
    root -> left          = NULL;
    root -> right         = NULL;
}

static void rotate_clockwise(Function_Information ** root)
{
    Function_Information * old_root = * root;
    Function_Information * new_root = old_root -> left;

    old_root -> left  = new_root -> right;
    new_root -> right = root;

    * root = new_root;

    update_height(old_root);
    update_height(new_root);
}

static void rotate_counterclockwise(Function_Information ** root)
{
    Function_Information * old_root = * root;
    Function_Information * new_root = old_root -> right;

    old_root -> right = new_root -> left;
    new_root -> left  = old_root;

    * root = new_root;

    update_height(old_root);
    update_height(new_root);
}

static void balance_after_insert_in_left(int function_id, Function_Information * root)
{
    if(function_id < (root -> left -> function_id))
    {
        rotate_clockwise(&root);
    }
    else
    {
        rotate_counterclockwise(&(root -> left));
        rotate_clockwise(&root);
    }
}

static void balance_after_insert_in_right(int function_id, Function_Information * root)
{
    if(function_id < (root -> right -> function_id))
    {
        rotate_counterclockwise(&root);
    }
    else
    {
        rotate_clockwise(&(root -> right));
        rotate_counterclockwise(&root);
    }
}

static int get_balance_score(Function_Information * root)
{
    int score = get_height(root -> left) - get_height(root -> right);

    return score;
}

static void update_height(Function_Information * root)
{
    int left_height = get_height(root -> left);
    int right_height = get_height(root -> right);

    if(left_height > right_height)
    {
        root -> height = 1 + left_height;
    }
    else
    {
        root -> height = 1 + right_height;
    }
}

static int get_height(Function_Information * root)
{
    if(root == NULL) return -1;
    else
    {
        return root -> height;
    }
}

