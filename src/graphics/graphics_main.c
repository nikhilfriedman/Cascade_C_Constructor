#include "graphics_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void graphics_loop(void)
{
    initialize_SDL();
    initialize_TTF();

    SDL_Window   * window   = create_window();
    SDL_Renderer * renderer = create_renderer(window);
    TTF_Font     * dmsans   = create_font(DEFAULT_FONT_LOCATION, 40);
    SDL_Event      event;

    bool quit   = false;
    bool update = true;

    int mouse_x; // current mouse x position
    int mouse_y; // current mouse y position

    int window_w; // current window width
    int window_h; // current window height

    int mouse_icon = 0; // current mouse icon

    Function_Block * blocks     = NULL;
    Function_Block * curr_block = NULL;

    while(!quit)
    {
        // poll positions
        SDL_GetMouseState(&mouse_x, &mouse_y);
        SDL_GetWindowSize(window, &window_w, &window_h);

        // poll events
        while(SDL_PollEvent(&event)) 
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(mouse_x >= 40 && mouse_x <= 220)
                    {
                        // print button
                        if(mouse_y >= 40 && mouse_y <= 120)
                        {
                            mouse_icon = 1;
                        }

                        // if button
                        if(mouse_y >= 160 && mouse_y <= 240)
                        {
                            mouse_icon = 2;
                        }

                        // else button
                        if(mouse_y >= 280 && mouse_y <= 360)
                        {
                            mouse_icon = 3;
                        }

                        // return button
                        if(mouse_y >= 400 && mouse_y <= 480)
                        {
                            mouse_icon = 4;
                        }
                    }

                    if(mouse_x >= (window_w / 6))
                    {
                        switch(mouse_icon)
                        {
                            case 0: 
                                break;
                            case 1:
                                if(blocks == NULL)
                                {
                                    blocks = create_function_block(mouse_x - ((window_w / 6)), mouse_y, 180, 80, "printf");
                                    curr_block = blocks;
                                    break;
                                } 
                                curr_block -> next = create_function_block(mouse_x - ((window_w / 6)), mouse_y, 180, 80, "printf");
                                curr_block = curr_block -> next;
                                break;
                            case 2:
                                if(blocks == NULL)
                                {
                                    blocks = create_function_block(mouse_x - ((window_w / 6)), mouse_y, 180, 80, "if");
                                    curr_block = blocks;
                                    break;
                                } 
                                curr_block -> next = create_function_block(mouse_x - ((window_w / 6)), mouse_y, 180, 80, "if");
                                curr_block = curr_block -> next;
                                break;
                            case 3:
                                if(blocks == NULL)
                                {
                                    blocks = create_function_block(mouse_x - ((window_w / 6)), mouse_y, 180, 80, "else");
                                    curr_block = blocks;
                                    break;
                                } 
                                curr_block -> next = create_function_block(mouse_x - ((window_w / 6)), mouse_y, 180, 80, "else");
                                curr_block = curr_block -> next;
                                break;
                            case 4:
                                if(blocks == NULL)
                                {
                                    blocks = create_function_block(mouse_x - ((window_w / 6)), mouse_y, 180, 80, "return");
                                    curr_block = blocks;
                                    break;
                                } 
                                curr_block -> next = create_function_block(mouse_x - ((window_w / 6)), mouse_y, 180, 80, "return");
                                curr_block = curr_block -> next;
                                break;
                        }

                        mouse_icon = 0;
                    }

                    break;
            }
        }

        // update all (window resize, etc)

        if(update)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            render_panel(renderer, 0, 0, (window_w / 6), window_h);
            render_button(renderer, dmsans, "printf", 40, 40, 180, 80);
            render_button(renderer, dmsans, "if", 40, 160, 180, 80);
            render_button(renderer, dmsans, "else", 40, 280, 180, 80);
            render_button(renderer, dmsans, "return", 40, 400, 180, 80);

            Function_Block * render_pt = blocks;
            while(render_pt != NULL)
            {
                render_button(renderer, dmsans, render_pt -> name, render_pt -> x + (window_w / 6), render_pt -> y, render_pt -> w, render_pt -> h);

                render_pt = render_pt -> next;
            }

            switch(mouse_icon)
            {
                case 0: 
                    break;
                case 1:
                    render_button(renderer, dmsans, "printf", mouse_x, mouse_y, 180, 80);
                    break;
                case 2:
                    render_button(renderer, dmsans, "if", mouse_x, mouse_y, 180, 80);
                    break;
                case 3:
                    render_button(renderer, dmsans, "else", mouse_x, mouse_y, 180, 80);
                    break;
                case 4:
                    render_button(renderer, dmsans, "return", mouse_x, mouse_y, 180, 80);
                    break;
            }

            SDL_RenderPresent(renderer);
            // update = false;
        }
    }

    SDL_Quit();
}